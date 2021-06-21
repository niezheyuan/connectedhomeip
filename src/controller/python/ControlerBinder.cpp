#include "pybind11/functional.h"
#include "pybind11/pybind11.h"
#include "PyDelegateWrappers.h"

#include <controller/python/CHIPDeviceController-PyBind.h>


namespace py = pybind11;



PYBIND11_MODULE(CHIPDeviceController, m) {
  py::class_<chip::Controller::CHIPDeviceControllerPyBind>(m, "CHIPDeviceControllerPyBind")
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
  py::class_<chip::Controller::DeviceAddressUpdateDelegate, PyDeviceAddressUpdateDelegate /* <--- trampoline*/>(m, "PyDeviceAddressUpdateDelegate")
    .def(py::init<>())
    .def("OnAddressUpdateComplete", &chip::Controller::DeviceAddressUpdateDelegate::OnAddressUpdateComplete);
  py::class_<chip::Controller::DevicePairingDelegate, PyDevicePairingDelegate /* <--- trampoline*/>DevicePairingDelegate(m, "PyDevicePairingDelegate");
    DevicePairingDelegate.def(py::init<>());
    DevicePairingDelegate.def("OnPairingComplete", &chip::Controller::DevicePairingDelegate::OnPairingComplete);
    DevicePairingDelegate.def("OnStatusUpdate", &chip::Controller::DevicePairingDelegate::OnStatusUpdate);
    DevicePairingDelegate.def("OnPairingDeleted", &chip::Controller::DevicePairingDelegate::OnPairingDeleted);
  py::enum_<chip::Controller::DevicePairingDelegate::Status>(DevicePairingDelegate, "Status")
    .value("SecurePairingSuccess", chip::Controller::DevicePairingDelegate::Status::SecurePairingSuccess)
    .value("SecurePairingFailed", chip::Controller::DevicePairingDelegate::Status::SecurePairingFailed)
    .export_values();
}
