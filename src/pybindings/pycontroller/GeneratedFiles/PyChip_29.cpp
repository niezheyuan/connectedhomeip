#include <inet/IPAddress.h>
#include <inet/InetLayer.h>
#include <netinet/in.h>
#include <netinet6/in6.h>
#include <sstream> // __str__
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

void bind_PyChip_29(std::function<pybind11::module &(std::string const & namespace_)> & M)
{
    { // chip::Inet::InetLayer file:inet/InetLayer.h line:146
        pybind11::class_<chip::Inet::InetLayer, std::shared_ptr<chip::Inet::InetLayer>> cl(
            M("chip::Inet"), "InetLayer",
            "This provides access to Internet services, including timers,\n    Domain Name System (DNS) resolution, TCP network "
            "transport, UDP\n    network transport, and raw network transport, for a single\n    thread.\n\n    For BSD/POSIX "
            "Sockets, event readiness notification is handled\n    via file descriptors and a traditional poll / select\n    "
            "implementation on the platform adaptation.\n\n    For LwIP, event readiness notification is handle via events /\n    "
            "messages and platform- and system-specific hooks for the event /\n    message system.\n\n ");
        cl.def(pybind11::init([]() { return new chip::Inet::InetLayer(); }));
        cl.def_readwrite("State", &chip::Inet::InetLayer::State);
        cl.def("Init", (int (chip::Inet::InetLayer::*)(class chip::System::Layer &, void *)) & chip::Inet::InetLayer::Init,
               "C++: chip::Inet::InetLayer::Init(class chip::System::Layer &, void *) --> int", pybind11::arg("aSystemLayer"),
               pybind11::arg("aContext"));
        cl.def("Shutdown", (int (chip::Inet::InetLayer::*)()) & chip::Inet::InetLayer::Shutdown,
               "C++: chip::Inet::InetLayer::Shutdown() --> int");
        cl.def("SystemLayer",
               (class chip::System::Layer * (chip::Inet::InetLayer::*) () const) & chip::Inet::InetLayer::SystemLayer,
               "C++: chip::Inet::InetLayer::SystemLayer() const --> class chip::System::Layer *",
               pybind11::return_value_policy::automatic);
        cl.def("GetInterfaceFromAddr",
               (int (chip::Inet::InetLayer::*)(const class chip::Inet::IPAddress &, unsigned int &)) &
                   chip::Inet::InetLayer::GetInterfaceFromAddr,
               "C++: chip::Inet::InetLayer::GetInterfaceFromAddr(const class chip::Inet::IPAddress &, unsigned int &) --> int",
               pybind11::arg("addr"), pybind11::arg("intfId"));
        cl.def("GetLinkLocalAddr",
               (int (chip::Inet::InetLayer::*)(unsigned int, class chip::Inet::IPAddress *)) &
                   chip::Inet::InetLayer::GetLinkLocalAddr,
               "C++: chip::Inet::InetLayer::GetLinkLocalAddr(unsigned int, class chip::Inet::IPAddress *) --> int",
               pybind11::arg("link"), pybind11::arg("llAddr"));
        cl.def("MatchLocalIPv6Subnet",
               (bool (chip::Inet::InetLayer::*)(const class chip::Inet::IPAddress &)) & chip::Inet::InetLayer::MatchLocalIPv6Subnet,
               "C++: chip::Inet::InetLayer::MatchLocalIPv6Subnet(const class chip::Inet::IPAddress &) --> bool",
               pybind11::arg("addr"));
        cl.def_static("UpdateSnapshot", (void (*)(class chip::System::Stats::Snapshot &)) & chip::Inet::InetLayer::UpdateSnapshot,
                      "C++: chip::Inet::InetLayer::UpdateSnapshot(class chip::System::Stats::Snapshot &) --> void",
                      pybind11::arg("aSnapshot"));
        cl.def("GetPlatformData", (void * (chip::Inet::InetLayer::*) ()) & chip::Inet::InetLayer::GetPlatformData,
               "C++: chip::Inet::InetLayer::GetPlatformData() --> void *", pybind11::return_value_policy::automatic);
        cl.def("SetPlatformData", (void (chip::Inet::InetLayer::*)(void *)) & chip::Inet::InetLayer::SetPlatformData,
               "C++: chip::Inet::InetLayer::SetPlatformData(void *) --> void", pybind11::arg("aPlatformData"));
        cl.def_static("HandleTCPInactivityTimer",
                      (void (*)(class chip::System::Layer *, void *, int)) & chip::Inet::InetLayer::HandleTCPInactivityTimer,
                      "C++: chip::Inet::InetLayer::HandleTCPInactivityTimer(class chip::System::Layer *, void *, int) --> void",
                      pybind11::arg("aSystemLayer"), pybind11::arg("aAppState"), pybind11::arg("aError"));
    }
    { // chip::Inet::IPPacketInfo file:inet/InetLayer.h line:328
        pybind11::class_<chip::Inet::IPPacketInfo, std::shared_ptr<chip::Inet::IPPacketInfo>> cl(
            M("chip::Inet"), "IPPacketInfo",
            "Information about an incoming/outgoing message/connection.\n\n   \n\n     Do not alter the contents of this class "
            "without first reading and understanding\n     the code/comments in IPEndPointBasis::GetPacketInfo().");
        cl.def(pybind11::init([]() { return new chip::Inet::IPPacketInfo(); }));
        cl.def(pybind11::init([](chip::Inet::IPPacketInfo const & o) { return new chip::Inet::IPPacketInfo(o); }));
        cl.def_readwrite("SrcAddress", &chip::Inet::IPPacketInfo::SrcAddress);
        cl.def_readwrite("DestAddress", &chip::Inet::IPPacketInfo::DestAddress);
        cl.def_readwrite("Interface", &chip::Inet::IPPacketInfo::Interface);
        cl.def_readwrite("SrcPort", &chip::Inet::IPPacketInfo::SrcPort);
        cl.def_readwrite("DestPort", &chip::Inet::IPPacketInfo::DestPort);
        cl.def("Clear", (void (chip::Inet::IPPacketInfo::*)()) & chip::Inet::IPPacketInfo::Clear,
               "C++: chip::Inet::IPPacketInfo::Clear() --> void");
    }
    // chip::Inet::ParseHostAndPort(const char *, unsigned short, const char *&, unsigned short &, unsigned short &)
    // file:inet/InetLayer.h line:340
    M("chip::Inet")
        .def("ParseHostAndPort",
             (int (*)(const char *, unsigned short, const char *&, unsigned short &, unsigned short &)) &
                 chip::Inet::ParseHostAndPort,
             "C++: chip::Inet::ParseHostAndPort(const char *, unsigned short, const char *&, unsigned short &, unsigned short &) "
             "--> int",
             pybind11::arg("aString"), pybind11::arg("aStringLen"), pybind11::arg("aHost"), pybind11::arg("aHostLen"),
             pybind11::arg("aPort"));

    // chip::Inet::ParseHostPortAndInterface(const char *, unsigned short, const char *&, unsigned short &, unsigned short &, const
    // char *&, unsigned short &) file:inet/InetLayer.h line:343
    M("chip::Inet")
        .def("ParseHostPortAndInterface",
             (int (*)(const char *, unsigned short, const char *&, unsigned short &, unsigned short &, const char *&,
                      unsigned short &)) &
                 chip::Inet::ParseHostPortAndInterface,
             "C++: chip::Inet::ParseHostPortAndInterface(const char *, unsigned short, const char *&, unsigned short &, unsigned "
             "short &, const char *&, unsigned short &) --> int",
             pybind11::arg("aString"), pybind11::arg("aStringLen"), pybind11::arg("aHost"), pybind11::arg("aHostLen"),
             pybind11::arg("aPort"), pybind11::arg("aInterface"), pybind11::arg("aInterfaceLen"));
}
