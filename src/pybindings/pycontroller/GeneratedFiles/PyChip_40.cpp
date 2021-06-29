#include <inet/IPAddress.h>
#include <inet/IPPrefix.h>
#include <netinet/in.h>
#include <netinet6/in6.h>
#include <platform/GeneralUtils.h>
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

void bind_PyChip_40(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // chip::DeviceLayer::ConnectivityManagerImpl file: line:47
		pybind11::class_<chip::DeviceLayer::ConnectivityManagerImpl, std::shared_ptr<chip::DeviceLayer::ConnectivityManagerImpl>, chip::DeviceLayer::ConnectivityManager, chip::DeviceLayer::Internal::GenericConnectivityManagerImpl_BLE<chip::DeviceLayer::ConnectivityManagerImpl>, chip::DeviceLayer::Internal::GenericConnectivityManagerImpl_NoThread<chip::DeviceLayer::ConnectivityManagerImpl>, chip::DeviceLayer::Internal::GenericConnectivityManagerImpl_NoWiFi<chip::DeviceLayer::ConnectivityManagerImpl>, chip::DeviceLayer::Internal::GenericConnectivityManagerImpl<chip::DeviceLayer::ConnectivityManagerImpl>> cl(M("chip::DeviceLayer"), "ConnectivityManagerImpl", "Concrete implementation of the ConnectivityManager singleton object for Darwin platforms.");
		cl.def( pybind11::init( [](){ return new chip::DeviceLayer::ConnectivityManagerImpl(); } ) );
	}
	// chip::DeviceLayer::ParseCompilerDateStr(const char *, unsigned short &, unsigned char &, unsigned char &) file:platform/GeneralUtils.h line:29
	M("chip::DeviceLayer").def("ParseCompilerDateStr", (int (*)(const char *, unsigned short &, unsigned char &, unsigned char &)) &chip::DeviceLayer::ParseCompilerDateStr, "C++: chip::DeviceLayer::ParseCompilerDateStr(const char *, unsigned short &, unsigned char &, unsigned char &) --> int", pybind11::arg("dateStr"), pybind11::arg("year"), pybind11::arg("month"), pybind11::arg("dayOfMonth"));

	// chip::DeviceLayer::Parse24HourTimeStr(const char *, unsigned char &, unsigned char &, unsigned char &) file:platform/GeneralUtils.h line:30
	M("chip::DeviceLayer").def("Parse24HourTimeStr", (int (*)(const char *, unsigned char &, unsigned char &, unsigned char &)) &chip::DeviceLayer::Parse24HourTimeStr, "C++: chip::DeviceLayer::Parse24HourTimeStr(const char *, unsigned char &, unsigned char &, unsigned char &) --> int", pybind11::arg("timeStr"), pybind11::arg("hour"), pybind11::arg("minute"), pybind11::arg("second"));

	// chip::DeviceLayer::CharacterizeIPv6Address(const class chip::Inet::IPAddress &) file:platform/GeneralUtils.h line:31
	M("chip::DeviceLayer").def("CharacterizeIPv6Address", (const char * (*)(const class chip::Inet::IPAddress &)) &chip::DeviceLayer::CharacterizeIPv6Address, "C++: chip::DeviceLayer::CharacterizeIPv6Address(const class chip::Inet::IPAddress &) --> const char *", pybind11::return_value_policy::automatic, pybind11::arg("ipAddr"));

	// chip::DeviceLayer::CharacterizeIPv6Prefix(const class chip::Inet::IPPrefix &) file:platform/GeneralUtils.h line:32
	M("chip::DeviceLayer").def("CharacterizeIPv6Prefix", (const char * (*)(const class chip::Inet::IPPrefix &)) &chip::DeviceLayer::CharacterizeIPv6Prefix, "C++: chip::DeviceLayer::CharacterizeIPv6Prefix(const class chip::Inet::IPPrefix &) --> const char *", pybind11::return_value_policy::automatic, pybind11::arg("inPrefix"));

	// chip::DeviceLayer::RegisterDeviceLayerErrorFormatter() file:platform/GeneralUtils.h line:33
	M("chip::DeviceLayer").def("RegisterDeviceLayerErrorFormatter", (void (*)()) &chip::DeviceLayer::RegisterDeviceLayerErrorFormatter, "C++: chip::DeviceLayer::RegisterDeviceLayerErrorFormatter() --> void");

	// chip::DeviceLayer::FormatDeviceLayerError(char *, unsigned short, int) file:platform/GeneralUtils.h line:34
	M("chip::DeviceLayer").def("FormatDeviceLayerError", (bool (*)(char *, unsigned short, int)) &chip::DeviceLayer::FormatDeviceLayerError, "C++: chip::DeviceLayer::FormatDeviceLayerError(char *, unsigned short, int) --> bool", pybind11::arg("buf"), pybind11::arg("bufSize"), pybind11::arg("err"));

}
