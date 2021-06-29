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

void bind_PyChip_48(std::function<pybind11::module &(std::string const & namespace_)> & M)
{
    { // chip::DeviceLayer::PlatformManagerImpl file: line:37
        pybind11::class_<chip::DeviceLayer::PlatformManagerImpl, std::shared_ptr<chip::DeviceLayer::PlatformManagerImpl>,
                         chip::DeviceLayer::PlatformManager,
                         chip::DeviceLayer::Internal::GenericPlatformManagerImpl<chip::DeviceLayer::PlatformManagerImpl>>
            cl(M("chip::DeviceLayer"), "PlatformManagerImpl",
               "Concrete implementation of the PlatformManager singleton object for Darwin platforms.");
        cl.def(pybind11::init([]() { return new chip::DeviceLayer::PlatformManagerImpl(); }));
        cl.def("GetWorkQueue",
               (struct dispatch_queue_s * (chip::DeviceLayer::PlatformManagerImpl::*) ()) &
                   chip::DeviceLayer::PlatformManagerImpl::GetWorkQueue,
               "C++: chip::DeviceLayer::PlatformManagerImpl::GetWorkQueue() --> struct dispatch_queue_s *",
               pybind11::return_value_policy::automatic);
    }
}
