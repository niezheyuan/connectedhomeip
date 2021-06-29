#include <inet/IPAddress.h>
#include <inet/InetLayer.h>
#include <netinet/in.h>
#include <netinet6/in6.h>
#include <sys/socket.h>
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

void bind_PyChip_28(std::function<pybind11::module &(std::string const & namespace_)> & M)
{
    // chip::Inet::Platform::InetLayer::WillInit(class chip::Inet::InetLayer *, void *) file:inet/InetLayer.h line:119
    M("chip::Inet::Platform::InetLayer")
        .def("WillInit", (int (*)(class chip::Inet::InetLayer *, void *)) & chip::Inet::Platform::InetLayer::WillInit,
             "C++: chip::Inet::Platform::InetLayer::WillInit(class chip::Inet::InetLayer *, void *) --> int",
             pybind11::arg("aLayer"), pybind11::arg("aContext"));

    // chip::Inet::Platform::InetLayer::DidInit(class chip::Inet::InetLayer *, void *, int) file:inet/InetLayer.h line:120
    M("chip::Inet::Platform::InetLayer")
        .def("DidInit", (void (*)(class chip::Inet::InetLayer *, void *, int)) & chip::Inet::Platform::InetLayer::DidInit,
             "C++: chip::Inet::Platform::InetLayer::DidInit(class chip::Inet::InetLayer *, void *, int) --> void",
             pybind11::arg("aLayer"), pybind11::arg("aContext"), pybind11::arg("anError"));

    // chip::Inet::Platform::InetLayer::WillShutdown(class chip::Inet::InetLayer *, void *) file:inet/InetLayer.h line:122
    M("chip::Inet::Platform::InetLayer")
        .def("WillShutdown", (int (*)(class chip::Inet::InetLayer *, void *)) & chip::Inet::Platform::InetLayer::WillShutdown,
             "C++: chip::Inet::Platform::InetLayer::WillShutdown(class chip::Inet::InetLayer *, void *) --> int",
             pybind11::arg("aLayer"), pybind11::arg("aContext"));

    // chip::Inet::Platform::InetLayer::DidShutdown(class chip::Inet::InetLayer *, void *, int) file:inet/InetLayer.h line:123
    M("chip::Inet::Platform::InetLayer")
        .def("DidShutdown", (void (*)(class chip::Inet::InetLayer *, void *, int)) & chip::Inet::Platform::InetLayer::DidShutdown,
             "C++: chip::Inet::Platform::InetLayer::DidShutdown(class chip::Inet::InetLayer *, void *, int) --> void",
             pybind11::arg("aLayer"), pybind11::arg("aContext"), pybind11::arg("anError"));
}
