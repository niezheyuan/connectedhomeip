
#include <functional>
#include <pybind11/pybind11.h>
#include <string>

#ifndef BINDER_PYBIND11_TYPE_CASTER
#define BINDER_PYBIND11_TYPE_CASTER
PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>)
PYBIND11_DECLARE_HOLDER_TYPE(T, T *)
PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

void bind_PyChip_43(std::function<pybind11::module &(std::string const & namespace_)> & M)
{
    // chip::DeviceLayer::DeviceEventType::PublicPlatformSpecificEventTypes file: line:36
    pybind11::enum_<chip::DeviceLayer::DeviceEventType::PublicPlatformSpecificEventTypes>(
        M("chip::DeviceLayer::DeviceEventType"), "PublicPlatformSpecificEventTypes", pybind11::arithmetic(),
        "Enumerates platform-specific event types that are visible to the application.")
        .export_values();

    ;

    // chip::DeviceLayer::DeviceEventType::InternalPlatformSpecificEventTypes file: line:44
    pybind11::enum_<chip::DeviceLayer::DeviceEventType::InternalPlatformSpecificEventTypes>(
        M("chip::DeviceLayer::DeviceEventType"), "InternalPlatformSpecificEventTypes", pybind11::arithmetic(),
        "Enumerates platform-specific event types that are internal to the chip Device Layer.")
        .value("kPlatformDarwinEvent", chip::DeviceLayer::DeviceEventType::kPlatformDarwinEvent)
        .value("kPlatformDarwinBleC1WriteEvent", chip::DeviceLayer::DeviceEventType::kPlatformDarwinBleC1WriteEvent)
        .value("kPlatformDarwinBleOutOfBuffersEvent", chip::DeviceLayer::DeviceEventType::kPlatformDarwinBleOutOfBuffersEvent)
        .export_values();

    ;
}
