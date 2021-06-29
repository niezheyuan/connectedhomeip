#include <platform/internal/GenericPlatformManagerImpl.h>
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

void bind_PyChip_47(std::function<pybind11::module &(std::string const & namespace_)> & M)
{
    { // chip::DeviceLayer::Internal::GenericPlatformManagerImpl file:platform/internal/GenericPlatformManagerImpl.h line:75
        pybind11::class_<
            chip::DeviceLayer::Internal::GenericPlatformManagerImpl<chip::DeviceLayer::PlatformManagerImpl>,
            std::shared_ptr<chip::DeviceLayer::Internal::GenericPlatformManagerImpl<chip::DeviceLayer::PlatformManagerImpl>>>
            cl(M("chip::DeviceLayer::Internal"), "GenericPlatformManagerImpl_chip_DeviceLayer_PlatformManagerImpl_t", "");
        cl.def(pybind11::init([]() {
            return new chip::DeviceLayer::Internal::GenericPlatformManagerImpl<chip::DeviceLayer::PlatformManagerImpl>();
        }));
        cl.def(pybind11::init(
            [](chip::DeviceLayer::Internal::GenericPlatformManagerImpl<chip::DeviceLayer::PlatformManagerImpl> const & o) {
                return new chip::DeviceLayer::Internal::GenericPlatformManagerImpl<chip::DeviceLayer::PlatformManagerImpl>(o);
            }));
        cl.def(
            "assign",
            (class chip::DeviceLayer::Internal::GenericPlatformManagerImpl<class chip::DeviceLayer::PlatformManagerImpl> &
             (chip::DeviceLayer::Internal::GenericPlatformManagerImpl<
                 chip::DeviceLayer::PlatformManagerImpl>::*) (const class chip::DeviceLayer::Internal::
                                                                  GenericPlatformManagerImpl<
                                                                      class chip::DeviceLayer::PlatformManagerImpl> &) ) &
                chip::DeviceLayer::Internal::GenericPlatformManagerImpl<chip::DeviceLayer::PlatformManagerImpl>::operator=,
            "C++: chip::DeviceLayer::Internal::GenericPlatformManagerImpl<chip::DeviceLayer::PlatformManagerImpl>::operator=(const "
            "class chip::DeviceLayer::Internal::GenericPlatformManagerImpl<class chip::DeviceLayer::PlatformManagerImpl> &) --> "
            "class chip::DeviceLayer::Internal::GenericPlatformManagerImpl<class chip::DeviceLayer::PlatformManagerImpl> &",
            pybind11::return_value_policy::automatic, pybind11::arg(""));
    }
}
