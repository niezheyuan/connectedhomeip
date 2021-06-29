#include <inet/IANAConstants.h>

#include <functional>
#include <pybind11/pybind11.h>
#include <string>

#ifndef BINDER_PYBIND11_TYPE_CASTER
#define BINDER_PYBIND11_TYPE_CASTER
PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>)
PYBIND11_DECLARE_HOLDER_TYPE(T, T *)
PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

void bind_PyChip_22(std::function<pybind11::module &(std::string const & namespace_)> & M)
{
    // chip::Inet::IPV6MulticastGroup file:inet/IANAConstants.h line:107
    pybind11::enum_<chip::Inet::IPV6MulticastGroup>(
        M("chip::Inet"), "IPV6MulticastGroup", pybind11::arithmetic(),
        "Internet protocol multicast group identifiers\n\n \n\n  Values of the  type are used to call the\n  "
        "IPAddress::MakeIPv6Multicast() method. They indicate\n  distinguished group identifiers registered by IETF with IANA.")
        .value("kIPV6MulticastGroup_AllNodes", chip::Inet::kIPV6MulticastGroup_AllNodes)
        .value("kIPV6MulticastGroup_AllRouters", chip::Inet::kIPV6MulticastGroup_AllRouters)
        .export_values();

    ;
}
