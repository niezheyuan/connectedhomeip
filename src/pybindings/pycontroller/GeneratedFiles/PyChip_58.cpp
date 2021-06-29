#include <platform/internal/GenericSoftwareUpdateManagerImpl.h>
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

void bind_PyChip_58(std::function<pybind11::module &(std::string const & namespace_)> & M)
{
    { // chip::DeviceLayer::Internal::GenericSoftwareUpdateManagerImpl file:platform/internal/GenericSoftwareUpdateManagerImpl.h
      // line:131
        pybind11::class_<
            chip::DeviceLayer::Internal::GenericSoftwareUpdateManagerImpl<chip::DeviceLayer::SoftwareUpdateManagerImpl>,
            std::shared_ptr<
                chip::DeviceLayer::Internal::GenericSoftwareUpdateManagerImpl<chip::DeviceLayer::SoftwareUpdateManagerImpl>>>
            cl(M("chip::DeviceLayer::Internal"), "GenericSoftwareUpdateManagerImpl_chip_DeviceLayer_SoftwareUpdateManagerImpl_t",
               "");
        cl.def(pybind11::init([]() {
            return new chip::DeviceLayer::Internal::GenericSoftwareUpdateManagerImpl<
                chip::DeviceLayer::SoftwareUpdateManagerImpl>();
        }));
        cl.def(pybind11::init([](chip::DeviceLayer::Internal::GenericSoftwareUpdateManagerImpl<
                                  chip::DeviceLayer::SoftwareUpdateManagerImpl> const & o) {
            return new chip::DeviceLayer::Internal::GenericSoftwareUpdateManagerImpl<chip::DeviceLayer::SoftwareUpdateManagerImpl>(
                o);
        }));
        cl.def(
            "assign",
            (class chip::DeviceLayer::Internal::GenericSoftwareUpdateManagerImpl<
                 class chip::DeviceLayer::SoftwareUpdateManagerImpl> &
             (chip::DeviceLayer::Internal::GenericSoftwareUpdateManagerImpl<
                 chip::DeviceLayer::SoftwareUpdateManagerImpl>::*) (const class chip::DeviceLayer::Internal::
                                                                        GenericSoftwareUpdateManagerImpl<
                                                                            class chip::DeviceLayer::
                                                                                SoftwareUpdateManagerImpl> &) ) &
                chip::DeviceLayer::Internal::GenericSoftwareUpdateManagerImpl<
                    chip::DeviceLayer::SoftwareUpdateManagerImpl>::operator=,
            "C++: "
            "chip::DeviceLayer::Internal::GenericSoftwareUpdateManagerImpl<chip::DeviceLayer::SoftwareUpdateManagerImpl>::operator="
            "(const class chip::DeviceLayer::Internal::GenericSoftwareUpdateManagerImpl<class "
            "chip::DeviceLayer::SoftwareUpdateManagerImpl> &) --> class "
            "chip::DeviceLayer::Internal::GenericSoftwareUpdateManagerImpl<class chip::DeviceLayer::SoftwareUpdateManagerImpl> &",
            pybind11::return_value_policy::automatic, pybind11::arg(""));
    }
}
