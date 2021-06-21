#include "pybind11/functional.h"
#include "pybind11/pybind11.h"

#include <controller/python/CHIPDeviceController-PyBind.h>
#include <controller/DeviceAddressUpdateDelegate.h>

namespace py = pybind11;

class PyAnimal : public chip::Controller::DeviceAddressUpdateDelegate {
public:
    /* Inherit the constructors */
    using chip::Controller::DeviceAddressUpdateDelegate::DeviceAddressUpdateDelegate;

    /* Trampoline (need one for each virtual function) */
    void OnAddressUpdateComplete(chip::NodeId nodeId, CHIP_ERROR erros) override {
        PYBIND11_OVERRIDE_PURE(
            void, /* Return type */
            DeviceAddressUpdateDelegate,      /* Parent class */
            OnAddressUpdateComplete,          /* Name of function in C++ (must match Python name) */
            (chip::NodeId *) nodeId, (CHIP_ERROR) erros     /* Argument(s) */
        );
    }
};

PYBIND11_MODULE(CHIPDeviceController, m) {
  py::class_<chip::Controller::CHIPDeviceControllerPyBind>(m, "CHIPDeviceControllerPyBind")
    .def(py::init<>())
    .def("PairBLE", &chip::Controller::CHIPDeviceControllerPyBind::PairBLE)
    .def("StopPairingBLE", &chip::Controller::CHIPDeviceControllerPyBind::StopPairingBLE)
    .def("CloseBleConnection", &chip::Controller::CHIPDeviceControllerPyBind::CloseBleConnection)
    .def("Shutdown", &chip::Controller::CHIPDeviceControllerPyBind::Shutdown)
    .def("UnpairDevice", &chip::Controller::CHIPDeviceControllerPyBind::UnpairDevice)
    .def("DiscoverAllCommissioning", &chip::Controller::CHIPDeviceControllerPyBind::DiscoverAllCommissioning)
    .def("SetDeviceAddressUpdateDelegate", &chip::Controller::CHIPDeviceControllerPyBind::SetDeviceAddressUpdateDelegate);
  py::class_<chip::Controller::DeviceAddressUpdateDelegate, PyAnimal /* <--- trampoline*/>(m, "PyDeviceAddressUpdateDelegate")
    .def(py::init<>())
    .def("OnAddressUpdateComplete", &chip::Controller::DeviceAddressUpdateDelegate::OnAddressUpdateComplete);
}
