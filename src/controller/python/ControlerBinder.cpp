#include "PyDelegateWrappers.h"
#include "pybind11/functional.h"
#include "pybind11/pybind11.h"
#include <pybind11/complex.h>
#include <pybind11/stl.h>

#include <controller/python/CHIPDeviceController-PyBind.h>
#include <lib/support/BitFlags.h>
#include <setup_payload/ManualSetupPayloadParser.h>
#include <setup_payload/SetupPayload.h>

namespace py = pybind11;

typedef std::function<pybind11::module &(std::string const &)> ModuleGetter;

void bind_CHIPController_ChipExceptions(std::function<pybind11::module &(std::string const & namespace_)> & M);

PYBIND11_MODULE(CHIPController, root_module)
{

    std::map<std::string, pybind11::module> modules;
    ModuleGetter M = [&](std::string const & namespace_) -> pybind11::module & {
        auto it = modules.find(namespace_);
        if (it == modules.end())
            throw std::runtime_error("Attempt to access pybind11::module for namespace " + namespace_ +
                                     " before it was created!!!");
        return it->second;
    };

    modules[""] = root_module;

    std::vector<std::pair<std::string, std::string>> sub_modules{
        { "", "ChipExceptions" },
    };
    for (auto & p : sub_modules)
        modules[p.first.size() ? p.first + "::" + p.second : p.second] =
            modules[p.first].def_submodule(p.second.c_str(), ("Bindings for " + p.first + "::" + p.second + " namespace").c_str());

    py::class_<chip::Controller::CHIPDeviceControllerPyBind>(root_module, "CHIPDeviceControllerPyBind")
        .def(py::init<>())
        .def("Init", &chip::Controller::CHIPDeviceControllerPyBind::Init)
        .def("PairBLE", &chip::Controller::CHIPDeviceControllerPyBind::PairBLE)
        .def("StopPairingBLE", &chip::Controller::CHIPDeviceControllerPyBind::StopPairingBLE)
        .def("CloseBleConnection", &chip::Controller::CHIPDeviceControllerPyBind::CloseBleConnection)
        .def("Shutdown", &chip::Controller::CHIPDeviceControllerPyBind::Shutdown)
        .def("UnpairDevice", &chip::Controller::CHIPDeviceControllerPyBind::UnpairDevice)
        .def("DiscoverAllCommissioning", &chip::Controller::CHIPDeviceControllerPyBind::DiscoverAllCommissioning)
        .def("SetDeviceAddressUpdateDelegate", &chip::Controller::CHIPDeviceControllerPyBind::SetDeviceAddressUpdateDelegate)
        .def("SetDevicePairingDelegate", &chip::Controller::CHIPDeviceControllerPyBind::SetDevicePairingDelegate);

    py::class_<chip::QRCodeSetupPayloadParser>(root_module, "QRCodeSetupPayloadParser")
        .def(py::init<const std::string &>())
        .def("populatePayload", &chip::QRCodeSetupPayloadParser::populatePayload);

    py::class_<chip::ManualSetupPayloadParser>(root_module, "ManualSetupPayloadParser")
        .def(py::init<const std::string &>())
        .def("populatePayload", &chip::ManualSetupPayloadParser::populatePayload);

    py::class_<chip::BitFlags<chip::RendezvousInformationFlag, uint8_t>>(root_module, "BitFlags")
        .def(py::init<>())
        .def("Raw", &chip::BitFlags<chip::RendezvousInformationFlag, uint8_t>::Raw)
        .def("RendezvousInformationFlag",
             &chip::BitFlags<chip::RendezvousInformationFlag, uint8_t>::operator chip::RendezvousInformationFlag);
    py::class_<chip::SetupPayload> SetupPayload(root_module, "SetupPayload");
    SetupPayload.def(py::init<>());
    SetupPayload.def_readwrite("version", &chip::SetupPayload::version);
    SetupPayload.def_readwrite("vendorID", &chip::SetupPayload::vendorID);
    SetupPayload.def_readwrite("productID", &chip::SetupPayload::productID);
    SetupPayload.def_readwrite("commissioningFlow", &chip::SetupPayload::commissioningFlow);
    SetupPayload.def_readwrite("rendezvousInformation", &chip::SetupPayload::rendezvousInformation);
    SetupPayload.def_readwrite("discriminator", &chip::SetupPayload::discriminator);
    SetupPayload.def_readwrite("setUpPINCode", &chip::SetupPayload::setUpPINCode);
    SetupPayload.def("getAllOptionalVendorData", &chip::SetupPayload::getAllOptionalVendorData);
    SetupPayload.def("addSerialNumber", py::overload_cast<std::string>(&chip::SetupPayload::addSerialNumber));
    SetupPayload.def("addSerialNumber", py::overload_cast<uint32_t>(&chip::SetupPayload::addSerialNumber));
    py::enum_<chip::RendezvousInformationFlag>(SetupPayload, "RendezvousInformationFlag")
        .value("kNone", chip::RendezvousInformationFlag::kNone)
        .value("kSoftAP", chip::RendezvousInformationFlag::kSoftAP)
        .value("kBLE", chip::RendezvousInformationFlag::kBLE)
        .value("kOnNetwork", chip::RendezvousInformationFlag::kOnNetwork)
        .export_values();
    py::enum_<chip::CommissioningFlow>(SetupPayload, "CommissioningFlow")
        .value("kStandard", chip::CommissioningFlow::kStandard)
        .value("kUserActionRequired", chip::CommissioningFlow::kUserActionRequired)
        .value("kCustom", chip::CommissioningFlow::kCustom)
        .export_values();

    py::class_<chip::Controller::DeviceAddressUpdateDelegate, PyDeviceAddressUpdateDelegate /* <--- trampoline*/>(
        root_module, "PyDeviceAddressUpdateDelegate")
        .def(py::init<>())
        .def("OnAddressUpdateComplete", &chip::Controller::DeviceAddressUpdateDelegate::OnAddressUpdateComplete);
    py::class_<chip::Controller::DevicePairingDelegate, PyDevicePairingDelegate /* <--- trampoline*/> DevicePairingDelegate(
        root_module, "PyDevicePairingDelegate");
    DevicePairingDelegate.def(py::init<>());
    DevicePairingDelegate.def("OnPairingComplete", &chip::Controller::DevicePairingDelegate::OnPairingComplete);
    DevicePairingDelegate.def("OnStatusUpdate", &chip::Controller::DevicePairingDelegate::OnStatusUpdate);
    DevicePairingDelegate.def("OnPairingDeleted", &chip::Controller::DevicePairingDelegate::OnPairingDeleted);
    py::enum_<chip::Controller::DevicePairingDelegate::Status>(DevicePairingDelegate, "Status")
        .value("SecurePairingSuccess", chip::Controller::DevicePairingDelegate::Status::SecurePairingSuccess)
        .value("SecurePairingFailed", chip::Controller::DevicePairingDelegate::Status::SecurePairingFailed)
        .export_values();

    bind_CHIPController_ChipExceptions(M);
}
