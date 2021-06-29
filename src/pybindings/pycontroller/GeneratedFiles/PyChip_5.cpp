#include <ble/BLEEndPoint.h>
#include <platform/internal/GenericConfigurationManagerImpl.h>
#include <sstream> // __str__
#include <support/BitFlags.h>
#include <system/SystemSockets.h>

#include <functional>
#include <pybind11/pybind11.h>
#include <string>

#ifndef BINDER_PYBIND11_TYPE_CASTER
#define BINDER_PYBIND11_TYPE_CASTER
PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>)
PYBIND11_DECLARE_HOLDER_TYPE(T, T *)
PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

void bind_PyChip_5(std::function<pybind11::module &(std::string const & namespace_)> & M)
{
    { // chip::BitFlags file:support/BitFlags.h line:43
        pybind11::class_<chip::BitFlags<chip::System::SocketEventFlags, chip::System::SocketEventFlags>,
                         std::shared_ptr<chip::BitFlags<chip::System::SocketEventFlags, chip::System::SocketEventFlags>>>
            cl(M("chip"), "BitFlags_chip_System_SocketEventFlags_chip_System_SocketEventFlags_t", "");
        cl.def(
            pybind11::init([]() { return new chip::BitFlags<chip::System::SocketEventFlags, chip::System::SocketEventFlags>(); }));
        cl.def(pybind11::init([](chip::BitFlags<chip::System::SocketEventFlags, chip::System::SocketEventFlags> const & o) {
            return new chip::BitFlags<chip::System::SocketEventFlags, chip::System::SocketEventFlags>(o);
        }));
        cl.def(pybind11::init<enum chip::System::SocketEventFlags>(), pybind11::arg("value"));

        cl.def("assign",
               (class chip::BitFlags<enum chip::System::SocketEventFlags, enum chip::System::SocketEventFlags> &
                (chip::BitFlags<
                    chip::System::SocketEventFlags,
                    chip::System::SocketEventFlags>::*) (const class chip::BitFlags<enum chip::System::SocketEventFlags,
                                                                                    enum chip::System::SocketEventFlags> &) ) &
                   chip::BitFlags<chip::System::SocketEventFlags, chip::System::SocketEventFlags>::operator=,
               "C++: chip::BitFlags<chip::System::SocketEventFlags, chip::System::SocketEventFlags>::operator=(const class "
               "chip::BitFlags<enum chip::System::SocketEventFlags, enum chip::System::SocketEventFlags> &) --> class "
               "chip::BitFlags<enum chip::System::SocketEventFlags, enum chip::System::SocketEventFlags> &",
               pybind11::return_value_policy::automatic, pybind11::arg(""));
        cl.def("Set",
               (class chip::BitFlags<enum chip::System::SocketEventFlags, enum chip::System::SocketEventFlags> &
                (chip::BitFlags<
                    chip::System::SocketEventFlags,
                    chip::System::SocketEventFlags>::*) (const class chip::BitFlags<enum chip::System::SocketEventFlags,
                                                                                    enum chip::System::SocketEventFlags> &) ) &
                   chip::BitFlags<chip::System::SocketEventFlags, chip::System::SocketEventFlags>::Set,
               "C++: chip::BitFlags<chip::System::SocketEventFlags, chip::System::SocketEventFlags>::Set(const class "
               "chip::BitFlags<enum chip::System::SocketEventFlags, enum chip::System::SocketEventFlags> &) --> class "
               "chip::BitFlags<enum chip::System::SocketEventFlags, enum chip::System::SocketEventFlags> &",
               pybind11::return_value_policy::automatic, pybind11::arg("other"));
        cl.def("Set",
               (class chip::BitFlags<enum chip::System::SocketEventFlags, enum chip::System::SocketEventFlags> &
                (chip::BitFlags<chip::System::SocketEventFlags,
                                chip::System::SocketEventFlags>::*) (enum chip::System::SocketEventFlags) const) &
                   chip::BitFlags<chip::System::SocketEventFlags, chip::System::SocketEventFlags>::Set,
               "C++: chip::BitFlags<chip::System::SocketEventFlags, chip::System::SocketEventFlags>::Set(enum "
               "chip::System::SocketEventFlags) const --> class chip::BitFlags<enum chip::System::SocketEventFlags, enum "
               "chip::System::SocketEventFlags> &",
               pybind11::return_value_policy::automatic, pybind11::arg("flag"));
        cl.def("Set",
               (class chip::BitFlags<enum chip::System::SocketEventFlags, enum chip::System::SocketEventFlags> &
                (chip::BitFlags<chip::System::SocketEventFlags,
                                chip::System::SocketEventFlags>::*) (enum chip::System::SocketEventFlags, bool) const) &
                   chip::BitFlags<chip::System::SocketEventFlags, chip::System::SocketEventFlags>::Set,
               "C++: chip::BitFlags<chip::System::SocketEventFlags, chip::System::SocketEventFlags>::Set(enum "
               "chip::System::SocketEventFlags, bool) const --> class chip::BitFlags<enum chip::System::SocketEventFlags, enum "
               "chip::System::SocketEventFlags> &",
               pybind11::return_value_policy::automatic, pybind11::arg("flag"), pybind11::arg("isSet"));
        cl.def("Clear",
               (class chip::BitFlags<enum chip::System::SocketEventFlags, enum chip::System::SocketEventFlags> &
                (chip::BitFlags<
                    chip::System::SocketEventFlags,
                    chip::System::SocketEventFlags>::*) (const class chip::BitFlags<enum chip::System::SocketEventFlags,
                                                                                    enum chip::System::SocketEventFlags> &) ) &
                   chip::BitFlags<chip::System::SocketEventFlags, chip::System::SocketEventFlags>::Clear,
               "C++: chip::BitFlags<chip::System::SocketEventFlags, chip::System::SocketEventFlags>::Clear(const class "
               "chip::BitFlags<enum chip::System::SocketEventFlags, enum chip::System::SocketEventFlags> &) --> class "
               "chip::BitFlags<enum chip::System::SocketEventFlags, enum chip::System::SocketEventFlags> &",
               pybind11::return_value_policy::automatic, pybind11::arg("other"));
        cl.def("Clear",
               (class chip::BitFlags<enum chip::System::SocketEventFlags, enum chip::System::SocketEventFlags> &
                (chip::BitFlags<chip::System::SocketEventFlags,
                                chip::System::SocketEventFlags>::*) (enum chip::System::SocketEventFlags) const) &
                   chip::BitFlags<chip::System::SocketEventFlags, chip::System::SocketEventFlags>::Clear,
               "C++: chip::BitFlags<chip::System::SocketEventFlags, chip::System::SocketEventFlags>::Clear(enum "
               "chip::System::SocketEventFlags) const --> class chip::BitFlags<enum chip::System::SocketEventFlags, enum "
               "chip::System::SocketEventFlags> &",
               pybind11::return_value_policy::automatic, pybind11::arg("flag"));
        cl.def("ClearAll",
               (class chip::BitFlags<enum chip::System::SocketEventFlags, enum chip::System::SocketEventFlags> &
                (chip::BitFlags<chip::System::SocketEventFlags, chip::System::SocketEventFlags>::*) ()) &
                   chip::BitFlags<chip::System::SocketEventFlags, chip::System::SocketEventFlags>::ClearAll,
               "C++: chip::BitFlags<chip::System::SocketEventFlags, chip::System::SocketEventFlags>::ClearAll() --> class "
               "chip::BitFlags<enum chip::System::SocketEventFlags, enum chip::System::SocketEventFlags> &",
               pybind11::return_value_policy::automatic);
        cl.def("Has",
               (bool (chip::BitFlags<chip::System::SocketEventFlags, chip::System::SocketEventFlags>::*)(
                   enum chip::System::SocketEventFlags) const) &
                   chip::BitFlags<chip::System::SocketEventFlags, chip::System::SocketEventFlags>::Has,
               "C++: chip::BitFlags<chip::System::SocketEventFlags, chip::System::SocketEventFlags>::Has(enum "
               "chip::System::SocketEventFlags) const --> bool",
               pybind11::arg("flag"));
        cl.def("HasAny",
               (bool (chip::BitFlags<chip::System::SocketEventFlags, chip::System::SocketEventFlags>::*)() const) &
                   chip::BitFlags<chip::System::SocketEventFlags, chip::System::SocketEventFlags>::HasAny,
               "C++: chip::BitFlags<chip::System::SocketEventFlags, chip::System::SocketEventFlags>::HasAny() const --> bool");
        cl.def("SetRaw",
               (class chip::BitFlags<enum chip::System::SocketEventFlags, enum chip::System::SocketEventFlags> &
                (chip::BitFlags<chip::System::SocketEventFlags,
                                chip::System::SocketEventFlags>::*) (enum chip::System::SocketEventFlags)) &
                   chip::BitFlags<chip::System::SocketEventFlags, chip::System::SocketEventFlags>::SetRaw,
               "C++: chip::BitFlags<chip::System::SocketEventFlags, chip::System::SocketEventFlags>::SetRaw(enum "
               "chip::System::SocketEventFlags) --> class chip::BitFlags<enum chip::System::SocketEventFlags, enum "
               "chip::System::SocketEventFlags> &",
               pybind11::return_value_policy::automatic, pybind11::arg("value"));
        cl.def("Raw",
               (enum chip::System::SocketEventFlags(
                   chip::BitFlags<chip::System::SocketEventFlags, chip::System::SocketEventFlags>::*)() const) &
                   chip::BitFlags<chip::System::SocketEventFlags, chip::System::SocketEventFlags>::Raw,
               "C++: chip::BitFlags<chip::System::SocketEventFlags, chip::System::SocketEventFlags>::Raw() const --> enum "
               "chip::System::SocketEventFlags");
        cl.def("RawStorage",
               (enum chip::System::SocketEventFlags *
                (chip::BitFlags<chip::System::SocketEventFlags, chip::System::SocketEventFlags>::*) ()) &
                   chip::BitFlags<chip::System::SocketEventFlags, chip::System::SocketEventFlags>::RawStorage,
               "C++: chip::BitFlags<chip::System::SocketEventFlags, chip::System::SocketEventFlags>::RawStorage() --> enum "
               "chip::System::SocketEventFlags *",
               pybind11::return_value_policy::automatic);
    }
}
