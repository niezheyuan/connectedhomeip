#include <inet/DNSResolver.h>
#include <inet/EndPointBasis.h>
#include <inet/IANAConstants.h>
#include <inet/IPAddress.h>
#include <inet/IPPrefix.h>
#include <inet/InetError.h>
#include <inet/InetInterface.h>
#include <inet/InetLayer.h>
#include <inet/InetLayerBasis.h>
#include <inet/RawEndPoint.h>
#include <inet/TCPEndPoint.h>
#include <netinet/in.h>
#include <netinet6/in6.h>
#include <sstream> // __str__
#include <sys/socket.h>
#include <system/SystemLayer.h>
#include <system/SystemStats.h>

#include <pybind11/pybind11.h>
#include <functional>
#include <string>

#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>)
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*)
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

void bind_PyChip_25(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	// chip::Inet::RegisterLayerErrorFormatter() file:inet/InetError.h line:374
	M("chip::Inet").def("RegisterLayerErrorFormatter", (void (*)()) &chip::Inet::RegisterLayerErrorFormatter, "C++: chip::Inet::RegisterLayerErrorFormatter() --> void");

	// chip::Inet::FormatLayerError(char *, unsigned short, int) file:inet/InetError.h line:375
	M("chip::Inet").def("FormatLayerError", (bool (*)(char *, unsigned short, int)) &chip::Inet::FormatLayerError, "C++: chip::Inet::FormatLayerError(char *, unsigned short, int) --> bool", pybind11::arg("buf"), pybind11::arg("bufSize"), pybind11::arg("err"));

	// chip::Inet::GetInterfaceName(unsigned int, char *, unsigned long) file:inet/InetInterface.h line:117
	M("chip::Inet").def("GetInterfaceName", (int (*)(unsigned int, char *, unsigned long)) &chip::Inet::GetInterfaceName, "C++: chip::Inet::GetInterfaceName(unsigned int, char *, unsigned long) --> int", pybind11::arg("intfId"), pybind11::arg("nameBuf"), pybind11::arg("nameBufSize"));

	// chip::Inet::InterfaceNameToId(const char *, unsigned int &) file:inet/InetInterface.h line:118
	M("chip::Inet").def("InterfaceNameToId", (int (*)(const char *, unsigned int &)) &chip::Inet::InterfaceNameToId, "C++: chip::Inet::InterfaceNameToId(const char *, unsigned int &) --> int", pybind11::arg("intfName"), pybind11::arg("intfId"));

	// chip::Inet::NetmaskToPrefixLength(const unsigned char *, unsigned short) file:inet/InetInterface.h line:119
	M("chip::Inet").def("NetmaskToPrefixLength", (unsigned char (*)(const unsigned char *, unsigned short)) &chip::Inet::NetmaskToPrefixLength, "C++: chip::Inet::NetmaskToPrefixLength(const unsigned char *, unsigned short) --> unsigned char", pybind11::arg("netmask"), pybind11::arg("netmaskLen"));

	{ // chip::Inet::InterfaceIterator file:inet/InetInterface.h line:142
		pybind11::class_<chip::Inet::InterfaceIterator, std::shared_ptr<chip::Inet::InterfaceIterator>> cl(M("chip::Inet"), "InterfaceIterator", "Iterator for the list of system network interfaces.\n\n \n\n  Use objects of this class to iterate the list of system network interfaces.\n\n  Methods on an individual instance of this class are *not* thread-safe;\n  however separate instances may be used simultaneously by multiple threads.\n\n  On multi-threaded LwIP systems, instances are thread-safe relative to other\n  threads accessing the global LwIP state provided that the other threads hold\n  the LwIP core lock while mutating the list of netifs, and that netif object\n  themselves are never destroyed.\n\n  On sockets-based systems, iteration is always stable in the face of changes\n  to the underlying system's interfaces.\n\n  On LwIP systems, iteration is stable except in the case where the currently\n  selected interface is removed from the list, in which case iteration ends\n  immediately.");
		cl.def( pybind11::init( [](){ return new chip::Inet::InterfaceIterator(); } ) );
		cl.def("HasCurrent", (bool (chip::Inet::InterfaceIterator::*)()) &chip::Inet::InterfaceIterator::HasCurrent, "C++: chip::Inet::InterfaceIterator::HasCurrent() --> bool");
		cl.def("Next", (bool (chip::Inet::InterfaceIterator::*)()) &chip::Inet::InterfaceIterator::Next, "C++: chip::Inet::InterfaceIterator::Next() --> bool");
		cl.def("GetInterface", (unsigned int (chip::Inet::InterfaceIterator::*)()) &chip::Inet::InterfaceIterator::GetInterface, "C++: chip::Inet::InterfaceIterator::GetInterface() --> unsigned int");
		cl.def("GetInterfaceId", (unsigned int (chip::Inet::InterfaceIterator::*)()) &chip::Inet::InterfaceIterator::GetInterfaceId, "C++: chip::Inet::InterfaceIterator::GetInterfaceId() --> unsigned int");
		cl.def("GetInterfaceName", (int (chip::Inet::InterfaceIterator::*)(char *, unsigned long)) &chip::Inet::InterfaceIterator::GetInterfaceName, "C++: chip::Inet::InterfaceIterator::GetInterfaceName(char *, unsigned long) --> int", pybind11::arg("nameBuf"), pybind11::arg("nameBufSize"));
		cl.def("IsUp", (bool (chip::Inet::InterfaceIterator::*)()) &chip::Inet::InterfaceIterator::IsUp, "C++: chip::Inet::InterfaceIterator::IsUp() --> bool");
		cl.def("SupportsMulticast", (bool (chip::Inet::InterfaceIterator::*)()) &chip::Inet::InterfaceIterator::SupportsMulticast, "C++: chip::Inet::InterfaceIterator::SupportsMulticast() --> bool");
		cl.def("HasBroadcastAddress", (bool (chip::Inet::InterfaceIterator::*)()) &chip::Inet::InterfaceIterator::HasBroadcastAddress, "C++: chip::Inet::InterfaceIterator::HasBroadcastAddress() --> bool");
	}
	{ // chip::Inet::InterfaceAddressIterator file:inet/InetInterface.h line:212
		pybind11::class_<chip::Inet::InterfaceAddressIterator, std::shared_ptr<chip::Inet::InterfaceAddressIterator>> cl(M("chip::Inet"), "InterfaceAddressIterator", "Iterator for the list of system network interface IP addresses.\n\n \n\n  Use objects of this class to iterate the list of system network interface\n  interface IP addresses.\n\n  Methods on an individual instance of this class are *not* thread-safe;\n  however separate instances may be used simultaneously by multiple threads.\n\n  On multi-threaded LwIP systems, instances are thread-safe relative to other\n  threads accessing the global LwIP state provided that: 1) other threads hold\n  the LwIP core lock while mutating the list of netifs; and 2) netif object\n  themselves are never destroyed.\n\n  On sockets-based systems, iteration is always stable in the face of changes\n  to the underlying system's interfaces and/or addresses.\n\n  On LwIP systems, iteration is stable except in the case where the interface\n  associated with the current address is removed, in which case iteration may\n  end prematurely.");
		cl.def( pybind11::init( [](){ return new chip::Inet::InterfaceAddressIterator(); } ) );
		cl.def("HasCurrent", (bool (chip::Inet::InterfaceAddressIterator::*)()) &chip::Inet::InterfaceAddressIterator::HasCurrent, "C++: chip::Inet::InterfaceAddressIterator::HasCurrent() --> bool");
		cl.def("Next", (bool (chip::Inet::InterfaceAddressIterator::*)()) &chip::Inet::InterfaceAddressIterator::Next, "C++: chip::Inet::InterfaceAddressIterator::Next() --> bool");
		cl.def("GetAddress", (class chip::Inet::IPAddress (chip::Inet::InterfaceAddressIterator::*)()) &chip::Inet::InterfaceAddressIterator::GetAddress, "C++: chip::Inet::InterfaceAddressIterator::GetAddress() --> class chip::Inet::IPAddress");
		cl.def("GetPrefixLength", (unsigned char (chip::Inet::InterfaceAddressIterator::*)()) &chip::Inet::InterfaceAddressIterator::GetPrefixLength, "C++: chip::Inet::InterfaceAddressIterator::GetPrefixLength() --> unsigned char");
		cl.def("GetIPv6PrefixLength", (unsigned char (chip::Inet::InterfaceAddressIterator::*)()) &chip::Inet::InterfaceAddressIterator::GetIPv6PrefixLength, "C++: chip::Inet::InterfaceAddressIterator::GetIPv6PrefixLength() --> unsigned char");
		cl.def("GetAddressWithPrefix", (void (chip::Inet::InterfaceAddressIterator::*)(class chip::Inet::IPPrefix &)) &chip::Inet::InterfaceAddressIterator::GetAddressWithPrefix, "C++: chip::Inet::InterfaceAddressIterator::GetAddressWithPrefix(class chip::Inet::IPPrefix &) --> void", pybind11::arg("addrWithPrefix"));
		cl.def("GetInterface", (unsigned int (chip::Inet::InterfaceAddressIterator::*)()) &chip::Inet::InterfaceAddressIterator::GetInterface, "C++: chip::Inet::InterfaceAddressIterator::GetInterface() --> unsigned int");
		cl.def("GetInterfaceId", (unsigned int (chip::Inet::InterfaceAddressIterator::*)()) &chip::Inet::InterfaceAddressIterator::GetInterfaceId, "C++: chip::Inet::InterfaceAddressIterator::GetInterfaceId() --> unsigned int");
		cl.def("GetInterfaceName", (int (chip::Inet::InterfaceAddressIterator::*)(char *, unsigned long)) &chip::Inet::InterfaceAddressIterator::GetInterfaceName, "C++: chip::Inet::InterfaceAddressIterator::GetInterfaceName(char *, unsigned long) --> int", pybind11::arg("nameBuf"), pybind11::arg("nameBufSize"));
		cl.def("IsUp", (bool (chip::Inet::InterfaceAddressIterator::*)()) &chip::Inet::InterfaceAddressIterator::IsUp, "C++: chip::Inet::InterfaceAddressIterator::IsUp() --> bool");
		cl.def("SupportsMulticast", (bool (chip::Inet::InterfaceAddressIterator::*)()) &chip::Inet::InterfaceAddressIterator::SupportsMulticast, "C++: chip::Inet::InterfaceAddressIterator::SupportsMulticast() --> bool");
		cl.def("HasBroadcastAddress", (bool (chip::Inet::InterfaceAddressIterator::*)()) &chip::Inet::InterfaceAddressIterator::HasBroadcastAddress, "C++: chip::Inet::InterfaceAddressIterator::HasBroadcastAddress() --> bool");
	}
	{ // chip::Inet::InetLayerBasis file:inet/InetLayerBasis.h line:54
		pybind11::class_<chip::Inet::InetLayerBasis, std::shared_ptr<chip::Inet::InetLayerBasis>, chip::System::Object> cl(M("chip::Inet"), "InetLayerBasis", "This is the basis class of reference-counted objects managed by an\n    InetLayer object.\n\n ");
		cl.def("Layer", (class chip::Inet::InetLayer & (chip::Inet::InetLayerBasis::*)() const) &chip::Inet::InetLayerBasis::Layer, "C++: chip::Inet::InetLayerBasis::Layer() const --> class chip::Inet::InetLayer &", pybind11::return_value_policy::automatic);
		cl.def("IsCreatedByInetLayer", (bool (chip::Inet::InetLayerBasis::*)(const class chip::Inet::InetLayer &) const) &chip::Inet::InetLayerBasis::IsCreatedByInetLayer, "C++: chip::Inet::InetLayerBasis::IsCreatedByInetLayer(const class chip::Inet::InetLayer &) const --> bool", pybind11::arg("aInetLayer"));
	}
	// chip::Inet::DNSOptions file:inet/DNSResolver.h line:44
	pybind11::enum_<chip::Inet::DNSOptions>(M("chip::Inet"), "DNSOptions", pybind11::arithmetic(), "Options controlling how IP address resolution is performed.")
		.value("kDNSOption_AddrFamily_Mask", chip::Inet::kDNSOption_AddrFamily_Mask)
		.value("kDNSOption_Flags_Mask", chip::Inet::kDNSOption_Flags_Mask)
		.value("kDNSOption_AddrFamily_Any", chip::Inet::kDNSOption_AddrFamily_Any)
		.value("kDNSOption_AddrFamily_IPv4Only", chip::Inet::kDNSOption_AddrFamily_IPv4Only)
		.value("kDNSOption_AddrFamily_IPv4Preferred", chip::Inet::kDNSOption_AddrFamily_IPv4Preferred)
		.value("kDNSOption_AddrFamily_IPv6Only", chip::Inet::kDNSOption_AddrFamily_IPv6Only)
		.value("kDNSOption_AddrFamily_IPv6Preferred", chip::Inet::kDNSOption_AddrFamily_IPv6Preferred)
		.value("kDNSOption_ValidFlags", chip::Inet::kDNSOption_ValidFlags)
		.value("kDNSOption_Default", chip::Inet::kDNSOption_Default)
		.export_values();

;

	{ // chip::Inet::DNSResolver file:inet/DNSResolver.h line:73
		pybind11::class_<chip::Inet::DNSResolver, std::shared_ptr<chip::Inet::DNSResolver>, chip::Inet::InetLayerBasis> cl(M("chip::Inet"), "DNSResolver", "This is an internal class to InetLayer that provides the abstraction of\n    Domain Name System (DNS) resolution in InetLayer. There is no public\n    interface available for the application layer.\n\n ");
	}
	{ // chip::Inet::EndPointBasis file:inet/EndPointBasis.h line:66
		pybind11::class_<chip::Inet::EndPointBasis, std::shared_ptr<chip::Inet::EndPointBasis>, chip::Inet::InetLayerBasis> cl(M("chip::Inet"), "EndPointBasis", "Basis of internet transport endpoint classes");
		cl.def( pybind11::init( [](chip::Inet::EndPointBasis const &o){ return new chip::Inet::EndPointBasis(o); } ) );
		cl.def("IsSocketsEndPoint", (bool (chip::Inet::EndPointBasis::*)() const) &chip::Inet::EndPointBasis::IsSocketsEndPoint, "Test whether endpoint is a POSIX socket \n\nC++: chip::Inet::EndPointBasis::IsSocketsEndPoint() const --> bool");
		cl.def("IsOpenEndPoint", (bool (chip::Inet::EndPointBasis::*)() const) &chip::Inet::EndPointBasis::IsOpenEndPoint, "Test whether endpoint has a valid descriptor. \n\nC++: chip::Inet::EndPointBasis::IsOpenEndPoint() const --> bool");
	}
	{ // chip::Inet::IPEndPointBasis file: line:51
		pybind11::class_<chip::Inet::IPEndPointBasis, chip::Inet::IPEndPointBasis*, chip::Inet::EndPointBasis> cl(M("chip::Inet"), "IPEndPointBasis", "Objects of this class represent non-instantiable IP protocol\n        endpoints.\n\n ");
		cl.def_readwrite("mState", &chip::Inet::IPEndPointBasis::mState);
		cl.def("SetMulticastLoopback", (int (chip::Inet::IPEndPointBasis::*)(chip::Inet::IPVersion, bool)) &chip::Inet::IPEndPointBasis::SetMulticastLoopback, "C++: chip::Inet::IPEndPointBasis::SetMulticastLoopback(chip::Inet::IPVersion, bool) --> int", pybind11::arg("aIPVersion"), pybind11::arg("aLoopback"));
		cl.def("JoinMulticastGroup", (int (chip::Inet::IPEndPointBasis::*)(unsigned int, const class chip::Inet::IPAddress &)) &chip::Inet::IPEndPointBasis::JoinMulticastGroup, "C++: chip::Inet::IPEndPointBasis::JoinMulticastGroup(unsigned int, const class chip::Inet::IPAddress &) --> int", pybind11::arg("aInterfaceId"), pybind11::arg("aAddress"));
		cl.def("LeaveMulticastGroup", (int (chip::Inet::IPEndPointBasis::*)(unsigned int, const class chip::Inet::IPAddress &)) &chip::Inet::IPEndPointBasis::LeaveMulticastGroup, "C++: chip::Inet::IPEndPointBasis::LeaveMulticastGroup(unsigned int, const class chip::Inet::IPAddress &) --> int", pybind11::arg("aInterfaceId"), pybind11::arg("aAddress"));
	}
	{ // chip::Inet::RawEndPoint file:inet/RawEndPoint.h line:54
		pybind11::class_<chip::Inet::RawEndPoint, chip::Inet::RawEndPoint*, chip::Inet::IPEndPointBasis> cl(M("chip::Inet"), "RawEndPoint", "Objects of this class represent raw IP network endpoints.\n\n \n\n  CHIP Inet Layer encapsulates methods for interacting with IP network\n  endpoints (SOCK_RAW sockets on Linux and BSD-derived systems) or LwIP\n  raw protocol control blocks, as the system is configured accordingly.");
		cl.def_readwrite("IPVer", &chip::Inet::RawEndPoint::IPVer);
		cl.def_readwrite("IPProto", &chip::Inet::RawEndPoint::IPProto);
		cl.def("Bind", [](chip::Inet::RawEndPoint &o, chip::Inet::IPAddressType const & a0, const class chip::Inet::IPAddress & a1) -> int { return o.Bind(a0, a1); }, "", pybind11::arg("addrType"), pybind11::arg("addr"));
		cl.def("Bind", (int (chip::Inet::RawEndPoint::*)(chip::Inet::IPAddressType, const class chip::Inet::IPAddress &, unsigned int)) &chip::Inet::RawEndPoint::Bind, "C++: chip::Inet::RawEndPoint::Bind(chip::Inet::IPAddressType, const class chip::Inet::IPAddress &, unsigned int) --> int", pybind11::arg("addrType"), pybind11::arg("addr"), pybind11::arg("intfId"));
		cl.def("BindIPv6LinkLocal", (int (chip::Inet::RawEndPoint::*)(unsigned int, const class chip::Inet::IPAddress &)) &chip::Inet::RawEndPoint::BindIPv6LinkLocal, "C++: chip::Inet::RawEndPoint::BindIPv6LinkLocal(unsigned int, const class chip::Inet::IPAddress &) --> int", pybind11::arg("intfId"), pybind11::arg("addr"));
		cl.def("BindInterface", (int (chip::Inet::RawEndPoint::*)(chip::Inet::IPAddressType, unsigned int)) &chip::Inet::RawEndPoint::BindInterface, "C++: chip::Inet::RawEndPoint::BindInterface(chip::Inet::IPAddressType, unsigned int) --> int", pybind11::arg("addrType"), pybind11::arg("intfId"));
		cl.def("GetBoundInterface", (unsigned int (chip::Inet::RawEndPoint::*)()) &chip::Inet::RawEndPoint::GetBoundInterface, "C++: chip::Inet::RawEndPoint::GetBoundInterface() --> unsigned int");
		cl.def("SetICMPFilter", (int (chip::Inet::RawEndPoint::*)(unsigned char, const unsigned char *)) &chip::Inet::RawEndPoint::SetICMPFilter, "C++: chip::Inet::RawEndPoint::SetICMPFilter(unsigned char, const unsigned char *) --> int", pybind11::arg("numICMPTypes"), pybind11::arg("aICMPTypes"));
		cl.def("Close", (void (chip::Inet::RawEndPoint::*)()) &chip::Inet::RawEndPoint::Close, "C++: chip::Inet::RawEndPoint::Close() --> void");
		cl.def("Free", (void (chip::Inet::RawEndPoint::*)()) &chip::Inet::RawEndPoint::Free, "C++: chip::Inet::RawEndPoint::Free() --> void");
	}
	{ // chip::Inet::TCPEndPoint file:inet/TCPEndPoint.h line:59
		pybind11::class_<chip::Inet::TCPEndPoint, chip::Inet::TCPEndPoint*, chip::Inet::EndPointBasis> cl(M("chip::Inet"), "TCPEndPoint", "Objects of this class represent TCP transport endpoints.\n\n \n\n  CHIP Inet Layer encapsulates methods for interacting with TCP transport\n  endpoints (SOCK_STREAM sockets on Linux and BSD-derived systems) or LwIP\n  TCP protocol control blocks, as the system is configured accordingly.");
		cl.def_readwrite("ReceiveEnabled", &chip::Inet::TCPEndPoint::ReceiveEnabled);
		cl.def_readwrite("State", &chip::Inet::TCPEndPoint::State);
		cl.def("Bind", [](chip::Inet::TCPEndPoint &o, chip::Inet::IPAddressType const & a0, const class chip::Inet::IPAddress & a1, unsigned short const & a2) -> int { return o.Bind(a0, a1, a2); }, "", pybind11::arg("addrType"), pybind11::arg("addr"), pybind11::arg("port"));
		cl.def("Bind", (int (chip::Inet::TCPEndPoint::*)(chip::Inet::IPAddressType, const class chip::Inet::IPAddress &, unsigned short, bool)) &chip::Inet::TCPEndPoint::Bind, "Bind the endpoint to an interface IP address.\n\n \n    the protocol version of the IP address\n \n\n        the IP address (must be an interface address)\n \n\n        the TCP port\n \n\n   option to share binding with other endpoints\n\n   INET_NO_ERROR               success: endpoint bound to address\n   INET_ERROR_INCORRECT_STATE  endpoint has been bound previously\n   INET_NO_MEMORY              insufficient memory for endpoint\n\n   INET_ERROR_WRONG_PROTOCOL_TYPE\n       does not match \n\n   INET_ERROR_WRONG_ADDRESS_TYPE\n       is  or the type of  is not\n      equal to \n\n   other                   another system or platform error\n\n \n\n  Binds the endpoint to the specified network interface IP address.\n\n  On LwIP, this method must not be called with the LwIP stack lock\n  already acquired.\n\nC++: chip::Inet::TCPEndPoint::Bind(chip::Inet::IPAddressType, const class chip::Inet::IPAddress &, unsigned short, bool) --> int", pybind11::arg("addrType"), pybind11::arg("addr"), pybind11::arg("port"), pybind11::arg("reuseAddr"));
		cl.def("Listen", (int (chip::Inet::TCPEndPoint::*)(unsigned short)) &chip::Inet::TCPEndPoint::Listen, "Prepare the endpoint to receive TCP messages.\n\n \n     maximum depth of connection acceptance queue\n\n   INET_NO_ERROR   success: endpoint ready to receive messages.\n   INET_ERROR_INCORRECT_STATE  endpoint is already listening.\n\n \n\n  If  is already  then no operation is\n  performed, otherwise the  is set to  and\n  the endpoint is prepared to received TCP messages, according to the\n  semantics of the platform.\n\n  On some platforms, the  argument is not used (the depth of\n  the queue is fixed; only one connection may be accepted at a time).\n\n  On LwIP systems, this method must not be called with the LwIP stack\n  lock already acquired\n\nC++: chip::Inet::TCPEndPoint::Listen(unsigned short) --> int", pybind11::arg("backlog"));
		cl.def("Connect", [](chip::Inet::TCPEndPoint &o, const class chip::Inet::IPAddress & a0, unsigned short const & a1) -> int { return o.Connect(a0, a1); }, "", pybind11::arg("addr"), pybind11::arg("port"));
		cl.def("Connect", (int (chip::Inet::TCPEndPoint::*)(const class chip::Inet::IPAddress &, unsigned short, unsigned int)) &chip::Inet::TCPEndPoint::Connect, "Initiate a TCP connection.\n\n \n        the destination IP address\n \n\n        the destination TCP port\n \n\n      an optional network interface indicator\n\n   INET_NO_ERROR       success:  is queued for transmit.\n   INET_ERROR_NOT_IMPLEMENTED  system implementation not complete.\n\n   INET_ERROR_WRONG_ADDRESS_TYPE\n      the destination address and the bound interface address do not\n      have matching protocol versions or address type, or the destination\n      address is an IPv6 link-local address and  is not specified.\n\n   other                   another system or platform error\n\n \n\n      If possible, then this method initiates a TCP connection to the\n      destination  (with  used as the scope\n      identifier for IPv6 link-local destinations) and \n     \n\nC++: chip::Inet::TCPEndPoint::Connect(const class chip::Inet::IPAddress &, unsigned short, unsigned int) --> int", pybind11::arg("addr"), pybind11::arg("port"), pybind11::arg("intfId"));
		cl.def("GetPeerInfo", (int (chip::Inet::TCPEndPoint::*)(class chip::Inet::IPAddress *, unsigned short *) const) &chip::Inet::TCPEndPoint::GetPeerInfo, "Extract IP address and TCP port of remote endpoint.\n\n \n     IP address of remote endpoint.\n \n\n     TCP port of remote endpoint.\n\n   INET_NO_ERROR           success: address and port extracted.\n   INET_ERROR_INCORRECT_STATE  TCP connection not established.\n   INET_ERROR_CONNECTION_ABORTED   TCP connection no longer open.\n\n \n\n  Do not use  pointer values for either argument.\n\nC++: chip::Inet::TCPEndPoint::GetPeerInfo(class chip::Inet::IPAddress *, unsigned short *) const --> int", pybind11::arg("retAddr"), pybind11::arg("retPort"));
		cl.def("GetLocalInfo", (int (chip::Inet::TCPEndPoint::*)(class chip::Inet::IPAddress *, unsigned short *)) &chip::Inet::TCPEndPoint::GetLocalInfo, "Extract IP address and TCP port of local endpoint.\n\n \n     IP address of local endpoint.\n \n\n     TCP port of local endpoint.\n\n   INET_NO_ERROR           success: address and port extracted.\n   INET_ERROR_INCORRECT_STATE  TCP connection not established.\n   INET_ERROR_CONNECTION_ABORTED   TCP connection no longer open.\n\n \n\n  Do not use  pointer values for either argument.\n\nC++: chip::Inet::TCPEndPoint::GetLocalInfo(class chip::Inet::IPAddress *, unsigned short *) --> int", pybind11::arg("retAddr"), pybind11::arg("retPort"));
		cl.def("GetInterfaceId", (int (chip::Inet::TCPEndPoint::*)(unsigned int *)) &chip::Inet::TCPEndPoint::GetInterfaceId, "Extract the interface id of the TCP endpoint.\n\n \n  The interface id.\n\n   INET_NO_ERROR           success: address and port extracted.\n   INET_ERROR_INCORRECT_STATE  TCP connection not established.\n   INET_ERROR_CONNECTION_ABORTED   TCP connection no longer open.\n\nC++: chip::Inet::TCPEndPoint::GetInterfaceId(unsigned int *) --> int", pybind11::arg("retInterface"));
		cl.def("DisableReceive", (void (chip::Inet::TCPEndPoint::*)()) &chip::Inet::TCPEndPoint::DisableReceive, "Disable reception.\n\n \n\n  Disable all event handlers. Data sent to an endpoint that disables\n  reception will be acknowledged until the receive window is exhausted.\n\nC++: chip::Inet::TCPEndPoint::DisableReceive() --> void");
		cl.def("EnableReceive", (void (chip::Inet::TCPEndPoint::*)()) &chip::Inet::TCPEndPoint::EnableReceive, "Enable reception.\n\n \n\n  Enable all event handlers. Data sent to an endpoint that disables\n  reception will be acknowledged until the receive window is exhausted.\n\nC++: chip::Inet::TCPEndPoint::EnableReceive() --> void");
		cl.def("EnableNoDelay", (int (chip::Inet::TCPEndPoint::*)()) &chip::Inet::TCPEndPoint::EnableNoDelay, "EnableNoDelay\n\nC++: chip::Inet::TCPEndPoint::EnableNoDelay() --> int");
		cl.def("EnableKeepAlive", (int (chip::Inet::TCPEndPoint::*)(unsigned short, unsigned short)) &chip::Inet::TCPEndPoint::EnableKeepAlive, "Enable TCP keepalive probes on the associated TCP connection.\n\n  \n\n    The interval (in seconds) between keepalive probes.  This value also controls\n    the time between last data packet sent and the transmission of the first keepalive\n    probe.\n\n  \n\n    The maximum number of unacknowledged probes before the connection will be deemed\n    to have failed.\n\n   INET_NO_ERROR           success: address and port extracted.\n   INET_ERROR_INCORRECT_STATE  TCP connection not established.\n   INET_ERROR_CONNECTION_ABORTED   TCP connection no longer open.\n   INET_ERROR_NOT_IMPLEMENTED  system implementation not complete.\n\n   other                   another system or platform error\n\n  \n\n    This method can only be called when the endpoint is in one of the connected states.\n\n    This method can be called multiple times to adjust the keepalive interval or timeout\n    count.\n\n \n\n  Start automatically  transmitting TCP \"keep-alive\" probe segments every\n   seconds. The connection will abort automatically after\n  receiving a negative response, or after sending \n  probe segments without receiving a positive response.\n\n  See RFC 1122, section 4.2.3.6 for specification details.\n\nC++: chip::Inet::TCPEndPoint::EnableKeepAlive(unsigned short, unsigned short) --> int", pybind11::arg("interval"), pybind11::arg("timeoutCount"));
		cl.def("DisableKeepAlive", (int (chip::Inet::TCPEndPoint::*)()) &chip::Inet::TCPEndPoint::DisableKeepAlive, "Disable the TCP \"keep-alive\" option.\n\n   INET_NO_ERROR           success: address and port extracted.\n   INET_ERROR_INCORRECT_STATE  TCP connection not established.\n   INET_ERROR_CONNECTION_ABORTED   TCP connection no longer open.\n   INET_ERROR_NOT_IMPLEMENTED  system implementation not complete.\n\n   other                   another system or platform error\n\nC++: chip::Inet::TCPEndPoint::DisableKeepAlive() --> int");
		cl.def("SetUserTimeout", (int (chip::Inet::TCPEndPoint::*)(unsigned int)) &chip::Inet::TCPEndPoint::SetUserTimeout, "Set the TCP TCP_USER_TIMEOUT socket option.\n\n \n    Tcp user timeout value in milliseconds.\n\n   INET_NO_ERROR           success: address and port extracted.\n   INET_ERROR_NOT_IMPLEMENTED  system implementation not complete.\n\n   other                   another system or platform error\n\n \n\n  When the value is greater than 0, it specifies the maximum amount of\n  time in milliseconds that transmitted data may remain\n  unacknowledged before TCP will forcibly close the\n  corresponding connection. If the option value is specified as 0,\n  TCP will to use the system default.\n  See RFC 5482, for further details.\n\nC++: chip::Inet::TCPEndPoint::SetUserTimeout(unsigned int) --> int", pybind11::arg("userTimeoutMillis"));
		cl.def("AckReceive", (int (chip::Inet::TCPEndPoint::*)(unsigned short)) &chip::Inet::TCPEndPoint::AckReceive, "Acknowledge receipt of message text.\n\n \n     number of bytes to acknowledge.\n\n   INET_NO_ERROR           success: reception acknowledged.\n   INET_ERROR_INCORRECT_STATE  TCP connection not established.\n   INET_ERROR_CONNECTION_ABORTED   TCP connection no longer open.\n\n \n\n  Use this method to acknowledge reception of all or part of the data\n  received. The operational semantics are undefined if  is larger\n  than the total outstanding unacknowledged received data.\n\nC++: chip::Inet::TCPEndPoint::AckReceive(unsigned short) --> int", pybind11::arg("len"));
		cl.def("PendingSendLength", (unsigned int (chip::Inet::TCPEndPoint::*)()) &chip::Inet::TCPEndPoint::PendingSendLength, "Extract the length of the data awaiting first transmit.\n\n \n  Number of untransmitted bytes in the transmit queue.\n\nC++: chip::Inet::TCPEndPoint::PendingSendLength() --> unsigned int");
		cl.def("PendingReceiveLength", (unsigned int (chip::Inet::TCPEndPoint::*)()) &chip::Inet::TCPEndPoint::PendingReceiveLength, "Extract the length of the unacknowledged receive data.\n\n \n  Number of bytes in the receive queue that have not yet been\n      acknowledged with AckReceive(uint16_t len).\n\nC++: chip::Inet::TCPEndPoint::PendingReceiveLength() --> unsigned int");
		cl.def("Shutdown", (int (chip::Inet::TCPEndPoint::*)()) &chip::Inet::TCPEndPoint::Shutdown, "Initiate TCP half close, in other words, finished with sending.\n\n   INET_NO_ERROR           success: address and port extracted.\n   INET_ERROR_INCORRECT_STATE  TCP connection not established.\n\n   other                   another system or platform error\n\nC++: chip::Inet::TCPEndPoint::Shutdown() --> int");
		cl.def("Close", (int (chip::Inet::TCPEndPoint::*)()) &chip::Inet::TCPEndPoint::Close, "Initiate TCP full close, in other words, finished with both send and\n  receive.\n\n   INET_NO_ERROR           success: address and port extracted.\n   INET_ERROR_INCORRECT_STATE  TCP connection not established.\n\n   other                   another system or platform error\n\nC++: chip::Inet::TCPEndPoint::Close() --> int");
		cl.def("Abort", (void (chip::Inet::TCPEndPoint::*)()) &chip::Inet::TCPEndPoint::Abort, "Abortively close the endpoint, in other words, send RST packets.\n\nC++: chip::Inet::TCPEndPoint::Abort() --> void");
		cl.def("Free", (void (chip::Inet::TCPEndPoint::*)()) &chip::Inet::TCPEndPoint::Free, "Initiate (or continue) TCP full close, ignoring errors.\n\n \n\n  The object is returned to the free pool, and all remaining user\n  references are subsequently invalid.\n\nC++: chip::Inet::TCPEndPoint::Free() --> void");
		cl.def("IsConnected", (bool (chip::Inet::TCPEndPoint::*)() const) &chip::Inet::TCPEndPoint::IsConnected, "Extract whether TCP connection is established.\n\nC++: chip::Inet::TCPEndPoint::IsConnected() const --> bool");
		cl.def("SetConnectTimeout", (void (chip::Inet::TCPEndPoint::*)(unsigned int)) &chip::Inet::TCPEndPoint::SetConnectTimeout, "C++: chip::Inet::TCPEndPoint::SetConnectTimeout(unsigned int) --> void", pybind11::arg("connTimeoutMsecs"));
		cl.def("SetIdleTimeout", (void (chip::Inet::TCPEndPoint::*)(unsigned int)) &chip::Inet::TCPEndPoint::SetIdleTimeout, "Set timer event for idle activity.\n\n \n The timeout in milliseconds\n\n \n\n  Set the idle timer interval to  milliseconds. A zero\n  time interval implies the idle timer is disabled.\n\nC++: chip::Inet::TCPEndPoint::SetIdleTimeout(unsigned int) --> void", pybind11::arg("timeoutMS"));
		cl.def("MarkActive", (void (chip::Inet::TCPEndPoint::*)()) &chip::Inet::TCPEndPoint::MarkActive, "Note activity, in other words, reset the idle timer.\n\n \n\n  Reset the idle timer to zero.\n\nC++: chip::Inet::TCPEndPoint::MarkActive() --> void");
		cl.def("LogId", (unsigned short (chip::Inet::TCPEndPoint::*)()) &chip::Inet::TCPEndPoint::LogId, "Obtain an identifier for the endpoint.\n\n \n  Returns an opaque unique identifier for use logs.\n\nC++: chip::Inet::TCPEndPoint::LogId() --> unsigned short");
	}
}
