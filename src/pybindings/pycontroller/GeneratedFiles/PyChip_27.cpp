#include <inet/AsyncDNSResolverSockets.h>
#include <inet/DNSResolver.h>
#include <inet/IPAddress.h>
#include <inet/InetLayer.h>
#include <sstream> // __str__
#include <system/SystemLayer.h>
#include <system/SystemStats.h>

#include <functional>
#include <pybind11/pybind11.h>
#include <string>

#ifndef BINDER_PYBIND11_TYPE_CASTER
#define BINDER_PYBIND11_TYPE_CASTER
PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>)
PYBIND11_DECLARE_HOLDER_TYPE(T, T *)
PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

void bind_PyChip_27(std::function<pybind11::module &(std::string const & namespace_)> & M)
{
    { // chip::Inet::AsyncDNSResolverSockets file:inet/AsyncDNSResolverSockets.h line:52
        pybind11::class_<chip::Inet::AsyncDNSResolverSockets, std::shared_ptr<chip::Inet::AsyncDNSResolverSockets>> cl(
            M("chip::Inet"), "AsyncDNSResolverSockets",
            "This is an internal class to InetLayer that provides helper APIs for\n    Asynchronous Domain Name System (DNS) "
            "resolution in InetLayer.\n    There is no public interface available for the application layer.\n\n ");
        cl.def(pybind11::init([]() { return new chip::Inet::AsyncDNSResolverSockets(); }));
        cl.def("EnqueueRequest",
               (int (chip::Inet::AsyncDNSResolverSockets::*)(class chip::Inet::DNSResolver &)) &
                   chip::Inet::AsyncDNSResolverSockets::EnqueueRequest,
               "C++: chip::Inet::AsyncDNSResolverSockets::EnqueueRequest(class chip::Inet::DNSResolver &) --> int",
               pybind11::arg("resolver"));
        cl.def("Init",
               (int (chip::Inet::AsyncDNSResolverSockets::*)(class chip::Inet::InetLayer *)) &
                   chip::Inet::AsyncDNSResolverSockets::Init,
               "C++: chip::Inet::AsyncDNSResolverSockets::Init(class chip::Inet::InetLayer *) --> int", pybind11::arg("inet"));
        cl.def("Cancel",
               (int (chip::Inet::AsyncDNSResolverSockets::*)(class chip::Inet::DNSResolver &)) &
                   chip::Inet::AsyncDNSResolverSockets::Cancel,
               "C++: chip::Inet::AsyncDNSResolverSockets::Cancel(class chip::Inet::DNSResolver &) --> int",
               pybind11::arg("resolver"));
        cl.def("Shutdown", (int (chip::Inet::AsyncDNSResolverSockets::*)()) & chip::Inet::AsyncDNSResolverSockets::Shutdown,
               "C++: chip::Inet::AsyncDNSResolverSockets::Shutdown() --> int");
    }
}
