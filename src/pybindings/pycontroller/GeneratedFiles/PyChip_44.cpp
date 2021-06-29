#include <platform/CHIPDeviceEvent.h>
#include <sstream> // __str__

#include <functional>
#include <pybind11/pybind11.h>
#include <string>

#ifndef BINDER_PYBIND11_TYPE_CASTER
#define BINDER_PYBIND11_TYPE_CASTER
PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>)
PYBIND11_DECLARE_HOLDER_TYPE(T, T *)
PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

void bind_PyChip_44(std::function<pybind11::module &(std::string const & namespace_)> & M)
{
    { // chip::DeviceLayer::ChipDevicePlatformEvent file: line:56
        pybind11::class_<chip::DeviceLayer::ChipDevicePlatformEvent, std::shared_ptr<chip::DeviceLayer::ChipDevicePlatformEvent>>
            cl(M("chip::DeviceLayer"), "ChipDevicePlatformEvent",
               "Represents platform-specific event information for Darwin platforms.");
        cl.def(pybind11::init([]() { return new chip::DeviceLayer::ChipDevicePlatformEvent(); }));

        { // chip::DeviceLayer::ChipDevicePlatformEvent::(anonymous) file: line:58
        }
    }
    { // chip::DeviceLayer::ChipDeviceEvent file:platform/CHIPDeviceEvent.h line:302
        pybind11::class_<chip::DeviceLayer::ChipDeviceEvent, std::shared_ptr<chip::DeviceLayer::ChipDeviceEvent>> cl(
            M("chip::DeviceLayer"), "ChipDeviceEvent", "Represents a chip Device Layer event.");
        cl.def(pybind11::init([]() { return new chip::DeviceLayer::ChipDeviceEvent(); }));
        cl.def_readwrite("Type", &chip::DeviceLayer::ChipDeviceEvent::Type);
        cl.def("Clear", (void (chip::DeviceLayer::ChipDeviceEvent::*)()) & chip::DeviceLayer::ChipDeviceEvent::Clear,
               "C++: chip::DeviceLayer::ChipDeviceEvent::Clear() --> void");
        cl.def("IsPublic", (bool (chip::DeviceLayer::ChipDeviceEvent::*)() const) & chip::DeviceLayer::ChipDeviceEvent::IsPublic,
               "C++: chip::DeviceLayer::ChipDeviceEvent::IsPublic() const --> bool");
        cl.def("IsInternal",
               (bool (chip::DeviceLayer::ChipDeviceEvent::*)() const) & chip::DeviceLayer::ChipDeviceEvent::IsInternal,
               "C++: chip::DeviceLayer::ChipDeviceEvent::IsInternal() const --> bool");
        cl.def("IsPlatformSpecific",
               (bool (chip::DeviceLayer::ChipDeviceEvent::*)() const) & chip::DeviceLayer::ChipDeviceEvent::IsPlatformSpecific,
               "C++: chip::DeviceLayer::ChipDeviceEvent::IsPlatformSpecific() const --> bool");
        cl.def("IsPlatformGeneric",
               (bool (chip::DeviceLayer::ChipDeviceEvent::*)() const) & chip::DeviceLayer::ChipDeviceEvent::IsPlatformGeneric,
               "C++: chip::DeviceLayer::ChipDeviceEvent::IsPlatformGeneric() const --> bool");

        { // chip::DeviceLayer::ChipDeviceEvent::(anonymous) file:platform/CHIPDeviceEvent.h line:306
            cl.def_readwrite("Platform", &chip::DeviceLayer::ChipDeviceEvent::Platform);
        }
    }
}
