#include <inet/IPAddress.h>
#include <inet/UDPEndPoint.h>
#include <netinet/in.h>
#include <netinet6/in6.h>
#include <sstream> // __str__
#include <sys/socket.h>

#include <pybind11/pybind11.h>
#include <functional>
#include <string>

#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>)
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*)
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

void bind_PyChip_26(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // chip::Inet::UDPEndPoint file:inet/UDPEndPoint.h line:54
		pybind11::class_<chip::Inet::UDPEndPoint, chip::Inet::UDPEndPoint*, chip::Inet::IPEndPointBasis> cl(M("chip::Inet"), "UDPEndPoint", "Objects of this class represent UDP transport endpoints.\n\n \n\n  CHIP Inet Layer encapsulates methods for interacting with UDP transport\n  endpoints (SOCK_DGRAM sockets on Linux and BSD-derived systems) or LwIP\n  UDP protocol control blocks, as the system is configured accordingly.");
		cl.def("Bind", [](chip::Inet::UDPEndPoint &o, chip::Inet::IPAddressType const & a0, const class chip::Inet::IPAddress & a1, unsigned short const & a2) -> int { return o.Bind(a0, a1, a2); }, "", pybind11::arg("addrType"), pybind11::arg("addr"), pybind11::arg("port"));
		cl.def("Bind", (int (chip::Inet::UDPEndPoint::*)(chip::Inet::IPAddressType, const class chip::Inet::IPAddress &, unsigned short, unsigned int)) &chip::Inet::UDPEndPoint::Bind, "C++: chip::Inet::UDPEndPoint::Bind(chip::Inet::IPAddressType, const class chip::Inet::IPAddress &, unsigned short, unsigned int) --> int", pybind11::arg("addrType"), pybind11::arg("addr"), pybind11::arg("port"), pybind11::arg("intfId"));
		cl.def("BindInterface", (int (chip::Inet::UDPEndPoint::*)(chip::Inet::IPAddressType, unsigned int)) &chip::Inet::UDPEndPoint::BindInterface, "C++: chip::Inet::UDPEndPoint::BindInterface(chip::Inet::IPAddressType, unsigned int) --> int", pybind11::arg("addrType"), pybind11::arg("intfId"));
		cl.def("GetBoundInterface", (unsigned int (chip::Inet::UDPEndPoint::*)()) &chip::Inet::UDPEndPoint::GetBoundInterface, "C++: chip::Inet::UDPEndPoint::GetBoundInterface() --> unsigned int");
		cl.def("GetBoundPort", (unsigned short (chip::Inet::UDPEndPoint::*)()) &chip::Inet::UDPEndPoint::GetBoundPort, "C++: chip::Inet::UDPEndPoint::GetBoundPort() --> unsigned short");
		cl.def("Close", (void (chip::Inet::UDPEndPoint::*)()) &chip::Inet::UDPEndPoint::Close, "C++: chip::Inet::UDPEndPoint::Close() --> void");
		cl.def("Free", (void (chip::Inet::UDPEndPoint::*)()) &chip::Inet::UDPEndPoint::Free, "C++: chip::Inet::UDPEndPoint::Free() --> void");
	}
}
