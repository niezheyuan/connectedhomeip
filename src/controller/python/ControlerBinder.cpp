#include "pybind11/functional.h"
#include "pybind11/pybind11.h"

#include <controller/python/CHIPDeviceController-PyBind.h>
#include <controller/DeviceAddressUpdateDelegate.h>

namespace py = pybind11;

PYBIND11_MODULE(CHIPDeviceController, m) {
  py::class_<chip::Controller::CHIPDeviceControllerPyBind>(m, "CHIPDeviceControllerPyBind")
    .def(py::init<>())
    .def("PairBLE", &chip::Controller::CHIPDeviceControllerPyBind::PairBLE)
    .def("StopPairingBLE", &chip::Controller::CHIPDeviceControllerPyBind::StopPairingBLE)
    .def("CloseBleConnection", &chip::Controller::CHIPDeviceControllerPyBind::CloseBleConnection)
    .def("Shutdown", &chip::Controller::CHIPDeviceControllerPyBind::Shutdown)
    .def("UnpairDevice", &chip::Controller::CHIPDeviceControllerPyBind::UnpairDevice)
    .def("DiscoverAllCommissioning", &chip::Controller::CHIPDeviceControllerPyBind::DiscoverAllCommissioning);
    py::class_<chip::Controller::DeviceAddressUpdateDelegate>(m, "DeviceAddressUpdateDelegate")
    .def("OnAddressUpdateComplete", &chip::Controller::DeviceAddressUpdateDelegate::OnAddressUpdateComplete);

}
