#include <inet/DNSResolver.h>    // chip::Inet::DNSOptions
#include <inet/DNSResolver.h>    // chip::Inet::DNSResolver
#include <inet/EndPointBasis.h>  // chip::Inet::EndPointBasis
#include <inet/IANAConstants.h>  // chip::Inet::(anonymous)
#include <inet/IPAddress.h>      // chip::Inet::(anonymous)
#include <inet/IPAddress.h>      // chip::Inet::IPAddress
#include <inet/IPPrefix.h>       // chip::Inet::IPPrefix
#include <inet/InetError.h>      // chip::Inet::FormatLayerError
#include <inet/InetError.h>      // chip::Inet::RegisterLayerErrorFormatter
#include <inet/InetInterface.h>  // chip::Inet::GetInterfaceName
#include <inet/InetInterface.h>  // chip::Inet::InterfaceAddressIterator
#include <inet/InetInterface.h>  // chip::Inet::InterfaceIterator
#include <inet/InetInterface.h>  // chip::Inet::InterfaceNameToId
#include <inet/InetInterface.h>  // chip::Inet::NetmaskToPrefixLength
#include <inet/InetLayer.h>      // chip::Inet::InetLayer
#include <inet/InetLayerBasis.h> // chip::Inet::InetLayerBasis
#include <inet/RawEndPoint.h>    // chip::Inet::RawEndPoint
#include <inet/TCPEndPoint.h>    // chip::Inet::TCPEndPoint
#include <inet/UDPEndPoint.h>    // chip::Inet::UDPEndPoint
#include <netinet/in.h>          // in_addr
#include <sstream>               // __str__
#include <sys/socket.h>          // sockaddr
#include <system/SystemLayer.h>  // chip::System::Layer
#include <system/SystemStats.h>  // chip::System::Stats::Snapshot

#include <controller/CHIPDeviceController.h>
#include <functional>
#include <pybind11/pybind11.h>
#include <string>

#ifndef BINDER_PYBIND11_TYPE_CASTER
#define BINDER_PYBIND11_TYPE_CASTER
PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>)
PYBIND11_DECLARE_HOLDER_TYPE(T, T *)
PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

void bind_chip_0(std::function<pybind11::module &(std::string const & namespace_)> & M)
{
    { // chip::Inet::IPAddress file:inet/IPAddress.h line:141
        pybind11::class_<chip::Inet::IPAddress, std::shared_ptr<chip::Inet::IPAddress>> cl(
            M("chip::Inet"), "IPAddress",
            "Internet protocol address\n\n \n\n  The CHIP Inet Layer uses objects of this class to represent Internet\n  protocol "
            "addresses (independent of protocol version).");
        cl.def(pybind11::init([]() { return new chip::Inet::IPAddress(); }));
        cl.def(pybind11::init([](chip::Inet::IPAddress const & o) { return new chip::Inet::IPAddress(o); }));
        cl.def("IsIPv6", (bool (chip::Inet::IPAddress::*)() const) & chip::Inet::IPAddress::IsIPv6,
               "Test whether address is IPv6 compatible.\n\n \n\n  Use this method to check if the address belongs to the IPv6 "
               "address\n  family. Note well: the unspecified address is not an IPv6 address.\n\n  true   The address is IPv6 and "
               "not the unspecified address.\n  false  The address is IPv4 or the unspecified address.\n\nC++: "
               "chip::Inet::IPAddress::IsIPv6() const --> bool");
        cl.def("IsIPv6GlobalUnicast", (bool (chip::Inet::IPAddress::*)() const) & chip::Inet::IPAddress::IsIPv6GlobalUnicast,
               "Test whether address is IPv6 global unicast address.\n\n \n\n  Use this method to check if the address belongs to "
               "the IPv6 address\n  family and has the global unicast address prefix.\n\n  true  Address is IPv6 global unicast\n  "
               "false Otherwise\n\nC++: chip::Inet::IPAddress::IsIPv6GlobalUnicast() const --> bool");
        cl.def("IsIPv6ULA", (bool (chip::Inet::IPAddress::*)() const) & chip::Inet::IPAddress::IsIPv6ULA,
               "Test whether address is IPv6 unique-local address (ULA).\n\n \n\n  Use this method to check if the address belongs "
               "to the IPv6 address\n  family and has the reserved IPv6 unique-local address prefix.\n\n  true  Address is IPv6 "
               "unique-local\n  false Otherwise\n\nC++: chip::Inet::IPAddress::IsIPv6ULA() const --> bool");
        cl.def("IsIPv6LinkLocal", (bool (chip::Inet::IPAddress::*)() const) & chip::Inet::IPAddress::IsIPv6LinkLocal,
               "Test whether address is IPv6 link-local address (LL).\n\n \n\n  Use this method to check if the address belongs to "
               "the IPv6 address\n  family and has the reserved IPv6 link-local address prefix.\n\n  true  Address is IPv6 "
               "link-local\n  false Otherwise\n\nC++: chip::Inet::IPAddress::IsIPv6LinkLocal() const --> bool");
        cl.def("IsIPv6Multicast", (bool (chip::Inet::IPAddress::*)() const) & chip::Inet::IPAddress::IsIPv6Multicast,
               "Test whether address is IPv6 multicast.\n\n \n\n  Use this method to check if the address belongs to the IPv6 "
               "address\n  family and has the reserved IPv6 multicast address prefix.\n\n  true  Address is IPv6 multicast\n  "
               "false Otherwise\n\nC++: chip::Inet::IPAddress::IsIPv6Multicast() const --> bool");
        cl.def("IsMulticast", (bool (chip::Inet::IPAddress::*)() const) & chip::Inet::IPAddress::IsMulticast,
               "Test whether address is IPv4 or IPv6 multicast.\n\n \n\n  Use this method to check if the address belongs to the "
               "IPv4 or IPv6 address\n  family and has the reserved IPv4 or IPv6 multicast address prefix.\n\n  true  Address is "
               "IPv4 or IPv6 multicast\n  false Otherwise\n\nC++: chip::Inet::IPAddress::IsMulticast() const --> bool");
        cl.def("InterfaceId", (unsigned long long (chip::Inet::IPAddress::*)() const) & chip::Inet::IPAddress::InterfaceId,
               "Extract the IID of an IPv6 ULA address.\n\n \n\n  Use this method with an IPv6 unique-local address (ULA) to "
               "extract the\n  identifier identifier (IID), which is the least significant 64 bits of\n  the address.\n\n \n "
               "64-bit interface identifier, or zero if the IP address is not\n  an IPv6 unique-local address.\n\nC++: "
               "chip::Inet::IPAddress::InterfaceId() const --> unsigned long long");
        cl.def(
            "Subnet", (unsigned short (chip::Inet::IPAddress::*)() const) & chip::Inet::IPAddress::Subnet,
            "Extract the 16-bit subnet identifier of an IPv6 ULA address.\n\n \n\n  Use this method with an IPv6 unique-local "
            "address (ULA) to extract the\n  subnet identifier, which is the least significant 16 bits of the\n  network prefix. "
            "The network prefix is the most significant 64 bits of\n  of the address. In other words, the subnet identifier is "
            "located in\n  the 7th and 8th bytes of a 16-byte address.\n\n \n 16-bit subnet identifier, or zero if the IP address "
            "is not\n  an IPv6 unique-local address.\n\nC++: chip::Inet::IPAddress::Subnet() const --> unsigned short");
        cl.def("GlobalId", (unsigned long long (chip::Inet::IPAddress::*)() const) & chip::Inet::IPAddress::GlobalId,
               "Extract the 16-bit global network identifier of an IPv6 ULA\n  address.\n\n \n\n  Use this method with an IPv6 "
               "unique-local address (ULA) to extract the\n  global network identifier, which is the 40 bits immediately "
               "following\n  the distinguished ULA network prefix, i.e. fd00::/8. In other words,\n  the global network identifier "
               "is located in the five bytes from the 2nd\n  2nd through the 6th bytes in the address.\n\n \n 40-bit global "
               "network identifier, or zero if the IP address\n  is not an IPv6 unique-local address.\n\nC++: "
               "chip::Inet::IPAddress::GlobalId() const --> unsigned long long");
        cl.def("Type", (chip::Inet::IPAddressType(chip::Inet::IPAddress::*)() const) & chip::Inet::IPAddress::Type,
               "Extract the type of the IP address.\n\n \n\n  Use this method to return an value of the enumerated type \n to "
               "indicate the type of the IP address.\n\n   kIPAddressType_IPv4 The address is IPv4.\n   kIPAddressType_IPv6 The "
               "address is IPv6.\n   kIPAddressType_Any  The address is the unspecified address.\n\nC++: "
               "chip::Inet::IPAddress::Type() const --> chip::Inet::IPAddressType");
        cl.def("__eq__",
               (bool (chip::Inet::IPAddress::*)(const class chip::Inet::IPAddress &) const) & chip::Inet::IPAddress::operator==,
               "Compare this IP address with another for equivalence.\n\n \n   The address to compare.\n\n  true  If equivalent to "
               "\n  false Otherwise\n\nC++: chip::Inet::IPAddress::operator==(const class chip::Inet::IPAddress &) const --> bool",
               pybind11::arg("other"));
        cl.def(
            "__ne__",
            (bool (chip::Inet::IPAddress::*)(const class chip::Inet::IPAddress &) const) & chip::Inet::IPAddress::operator!=,
            "Compare this IP address with another for inequivalence.\n\n \n   The address to compare.\n\n  true  If equivalent to "
            "\n  false Otherwise\n\nC++: chip::Inet::IPAddress::operator!=(const class chip::Inet::IPAddress &) const --> bool",
            pybind11::arg("other"));
        cl.def("assign",
               (class chip::Inet::IPAddress & (chip::Inet::IPAddress::*) (const class chip::Inet::IPAddress &) ) &
                   chip::Inet::IPAddress::operator=,
               "Conventional assignment operator.\n\n \n   The address to copy.\n\n \n  A reference to this object.\n\nC++: "
               "chip::Inet::IPAddress::operator=(const class chip::Inet::IPAddress &) --> class chip::Inet::IPAddress &",
               pybind11::return_value_policy::automatic, pybind11::arg("other"));
        cl.def(
            "ToString", (char * (chip::Inet::IPAddress::*) (char *, unsigned int) const) & chip::Inet::IPAddress::ToString,
            "Emit the IP address in conventional text presentation format.\n\n \n         The address of the emitted text.\n \n\n  "
            "   The size of the buffer for the emitted text.\n\n \n\n  Use ToString(char *buf, uint32_t bufSize) const to write "
            "the\n  conventional text presentation form of the IP address to the memory\n  located at  and extending as much as  "
            "bytes, including\n  its NUL termination character.\n\n  Note Well: not compliant with RFC 5952 on some platforms. "
            "Specifically,\n  zero compression may not be applied according to section 4.2.\n\n \n  The argument  if no formatting "
            "error, or zero otherwise.\n\nC++: chip::Inet::IPAddress::ToString(char *, unsigned int) const --> char *",
            pybind11::return_value_policy::automatic, pybind11::arg("buf"), pybind11::arg("bufSize"));
        cl.def_static("FromString", (bool (*)(const char *, class chip::Inet::IPAddress &)) & chip::Inet::IPAddress::FromString,
                      "Scan the IP address from its conventional presentation text.\n\n \n     The address of the emitted text.\n "
                      "\n\n  The object to set to the scanned address.\n\n \n\n  Use FromString(const char *str, IPAddress& "
                      "output) to\n  overwrite an IP address by scanning the conventional text presentation\n  located at \n\n  "
                      "true  The presentation format is valid\n  false Otherwise\n\nC++: chip::Inet::IPAddress::FromString(const "
                      "char *, class chip::Inet::IPAddress &) --> bool",
                      pybind11::arg("str"), pybind11::arg("output"));
        cl.def_static(
            "FromString",
            (bool (*)(const char *, unsigned long, class chip::Inet::IPAddress &)) & chip::Inet::IPAddress::FromString,
            "Scan the IP address from its conventional presentation text.\n\n \n     A pointer to the text to be scanned.\n \n\n  "
            "The length of the text to be scanned.\n \n\n  The object to set to the scanned address.\n\n \n\n  Use "
            "FromString(const char *str, size_t strLen, IPAddress& output) to\n  overwrite an IP address by scanning the "
            "conventional text presentation\n  located at \n\n  true  The presentation format is valid\n  false Otherwise\n\nC++: "
            "chip::Inet::IPAddress::FromString(const char *, unsigned long, class chip::Inet::IPAddress &) --> bool",
            pybind11::arg("str"), pybind11::arg("strLen"), pybind11::arg("output"));
        cl.def("WriteAddress", (void (chip::Inet::IPAddress::*)(unsigned char *&) const) & chip::Inet::IPAddress::WriteAddress,
               "Emit the IP address in standard network representation.\n\n \n   Reference to the cursor to use for writing.\n\n "
               "\n\n  Use WriteAddress(uint8_t *&p) to encode the IP address in\n  the binary format defined by RFC 4291 for IPv6 "
               "addresses.  IPv4\n  addresses are encoded according to section 2.5.5.1 \"IPv4-Compatible\n  IPv6 Address\" "
               "(V4COMPAT).\n\nC++: chip::Inet::IPAddress::WriteAddress(unsigned char *&) const --> void",
               pybind11::arg("p"));
        cl.def_static("ReadAddress",
                      (void (*)(const unsigned char *&, class chip::Inet::IPAddress &)) & chip::Inet::IPAddress::ReadAddress,
                      "Emit the IP address in standard network representation.\n\n \n       Reference to the cursor to use for "
                      "reading.\n \n\n  Object to receive decoded IP address.\n\n \n\n  Use ReadAddress(uint8_t *&p, IPAddress "
                      "&output) to decode\n  the IP address at  to the object \n     \n\nC++: "
                      "chip::Inet::IPAddress::ReadAddress(const unsigned char *&, class chip::Inet::IPAddress &) --> void",
                      pybind11::arg("p"), pybind11::arg("output"));
        cl.def("IsIPv4", (bool (chip::Inet::IPAddress::*)() const) & chip::Inet::IPAddress::IsIPv4,
               "Test whether address is IPv4 compatible.\n\n \n\n  Use this method to check if the address belongs to the IPv4 "
               "address\n  family. Note well: the unspecified address is not an IPv4 address.\n\n  true   The address is IPv4 and "
               "not the unspecified address.\n  false  The address is IPv6 or the unspecified address.\n\nC++: "
               "chip::Inet::IPAddress::IsIPv4() const --> bool");
        cl.def("IsIPv4Multicast", (bool (chip::Inet::IPAddress::*)() const) & chip::Inet::IPAddress::IsIPv4Multicast,
               "Test whether address is IPv4 multicast.\n\n \n\n  Use this method to check if the address is an IPv4 multicast\n  "
               "address.\n\n  true  Address is the IPv4 multicast\n  false Otherwise\n\nC++: "
               "chip::Inet::IPAddress::IsIPv4Multicast() const --> bool");
        cl.def("IsIPv4Broadcast", (bool (chip::Inet::IPAddress::*)() const) & chip::Inet::IPAddress::IsIPv4Broadcast,
               "Test whether address is IPv4 broadcast.\n\n \n\n  Use this method to check if the address is the special purpose "
               "IPv4\n  broadcast address.\n\n  true  Address is the IPv4 broadcast\n  false Otherwise\n\nC++: "
               "chip::Inet::IPAddress::IsIPv4Broadcast() const --> bool");
        cl.def_static("MakeULA",
                      (class chip::Inet::IPAddress(*)(unsigned long long, unsigned short, unsigned long long)) &
                          chip::Inet::IPAddress::MakeULA,
                      "Construct an IPv6 unique-local address (ULA) from its parts.\n\n \n\n  Use MakeULA(uint64_t globalId, "
                      "uint16_t subnet, uint64_t\n  interfaceId) to construct a unique-local address (ULA) with global\n  network "
                      "identifier  subnet identifier  and\n  interface identifier (IID) \n\n \n  The constructed IP "
                      "address.\n\nC++: chip::Inet::IPAddress::MakeULA(unsigned long long, unsigned short, unsigned long long) --> "
                      "class chip::Inet::IPAddress",
                      pybind11::arg("globalId"), pybind11::arg("subnet"), pybind11::arg("interfaceId"));
        cl.def_static("MakeLLA", (class chip::Inet::IPAddress(*)(unsigned long long)) & chip::Inet::IPAddress::MakeLLA,
                      "Construct an IPv6 link-local address (LL) from its IID.\n\n \n\n  Use MakeLLA(uint64_t interfaceId) to "
                      "construct an IPv6\n  link-local address (LL) with interface identifier \n\n \n  The constructed IP "
                      "address.\n\nC++: chip::Inet::IPAddress::MakeLLA(unsigned long long) --> class chip::Inet::IPAddress",
                      pybind11::arg("interfaceId"));
        cl.def_static("MakeIPv6Multicast",
                      (class chip::Inet::IPAddress(*)(unsigned char, unsigned char, unsigned int)) &
                          chip::Inet::IPAddress::MakeIPv6Multicast,
                      "Construct an IPv6 multicast address from its parts.\n\n \n\n  Use MakeIPv6Multicast(uint8_t flags, uint8_t "
                      "scope,\n  uint32_t groupId) to construct an IPv6 multicast\n  address with  for routing scope  and group\n  "
                      "identifier \n\n \n  The constructed IP address.\n\nC++: chip::Inet::IPAddress::MakeIPv6Multicast(unsigned "
                      "char, unsigned char, unsigned int) --> class chip::Inet::IPAddress",
                      pybind11::arg("aFlags"), pybind11::arg("aScope"), pybind11::arg("aGroupId"));
        cl.def_static(
            "MakeIPv6WellKnownMulticast",
            (class chip::Inet::IPAddress(*)(unsigned char, unsigned int)) & chip::Inet::IPAddress::MakeIPv6WellKnownMulticast,
            "Construct a well-known IPv6 multicast address from its parts.\n\n \n\n  Use MakeIPv6WellKnownMulticast(uint8_t scope, "
            "uint32_t\n  groupId) to construct an IPv6 multicast address for\n  routing scope  and group identifier \n\n \n  The "
            "constructed IP address.\n\nC++: chip::Inet::IPAddress::MakeIPv6WellKnownMulticast(unsigned char, unsigned int) --> "
            "class chip::Inet::IPAddress",
            pybind11::arg("aScope"), pybind11::arg("aGroupId"));
        cl.def_static(
            "MakeIPv6PrefixMulticast",
            (class chip::Inet::IPAddress(*)(unsigned char, unsigned char, const unsigned long long &, unsigned int)) &
                chip::Inet::IPAddress::MakeIPv6PrefixMulticast,
            "Construct a transient, prefix IPv6 multicast address from its parts.\n\n \n\n  Use MakeIPv6PrefixMulticast(uint8_t "
            "scope, uint8_t\n  prefixlen, const uint64_t prefix, uint32_t groupId) to\n  construct a transient, prefix IPv6 "
            "multicast address with for\n  routing scope  and group identifier octets \n  qualified by the prefix  of length  "
            "bits.\n\n \n  The constructed IP address.\n\nC++: chip::Inet::IPAddress::MakeIPv6PrefixMulticast(unsigned char, "
            "unsigned char, const unsigned long long &, unsigned int) --> class chip::Inet::IPAddress",
            pybind11::arg("aScope"), pybind11::arg("aPrefixLength"), pybind11::arg("aPrefix"), pybind11::arg("aGroupId"));
        cl.def_static("MakeIPv4Broadcast", (class chip::Inet::IPAddress(*)()) & chip::Inet::IPAddress::MakeIPv4Broadcast,
                      "Construct an IPv4 broadcast address.\n\n \n  The constructed IP address.\n\nC++: "
                      "chip::Inet::IPAddress::MakeIPv4Broadcast() --> class chip::Inet::IPAddress");
    }
}
