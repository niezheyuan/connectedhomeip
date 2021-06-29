#include <platform/CHIPDeviceEvent.h>

#include <pybind11/pybind11.h>
#include <functional>
#include <string>

#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>)
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*)
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

void bind_PyChip_41(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	// chip::DeviceLayer::DeviceEventType::EventTypeRanges file:platform/CHIPDeviceEvent.h line:46
	pybind11::enum_<chip::DeviceLayer::DeviceEventType::EventTypeRanges>(M("chip::DeviceLayer::DeviceEventType"), "EventTypeRanges", pybind11::arithmetic(), "Event Type Ranges\n\n Defines numeric ranges for event types based on their visibility to the application,\n an whether or not they are specific to a particular platform adaptation.")
		.value("kRange_Public", chip::DeviceLayer::DeviceEventType::kRange_Public)
		.value("kRange_PublicPlatformSpecific", chip::DeviceLayer::DeviceEventType::kRange_PublicPlatformSpecific)
		.value("kRange_Internal", chip::DeviceLayer::DeviceEventType::kRange_Internal)
		.value("kRange_InternalPlatformSpecific", chip::DeviceLayer::DeviceEventType::kRange_InternalPlatformSpecific)
		.export_values();

;

	// chip::DeviceLayer::DeviceEventType::IsPublic(unsigned short) file:platform/CHIPDeviceEvent.h line:79
	M("chip::DeviceLayer::DeviceEventType").def("IsPublic", (bool (*)(unsigned short)) &chip::DeviceLayer::DeviceEventType::IsPublic, "C++: chip::DeviceLayer::DeviceEventType::IsPublic(unsigned short) --> bool", pybind11::arg("eventType"));

	// chip::DeviceLayer::DeviceEventType::IsInternal(unsigned short) file:platform/CHIPDeviceEvent.h line:83
	M("chip::DeviceLayer::DeviceEventType").def("IsInternal", (bool (*)(unsigned short)) &chip::DeviceLayer::DeviceEventType::IsInternal, "C++: chip::DeviceLayer::DeviceEventType::IsInternal(unsigned short) --> bool", pybind11::arg("eventType"));

	// chip::DeviceLayer::DeviceEventType::IsPlatformSpecific(unsigned short) file:platform/CHIPDeviceEvent.h line:87
	M("chip::DeviceLayer::DeviceEventType").def("IsPlatformSpecific", (bool (*)(unsigned short)) &chip::DeviceLayer::DeviceEventType::IsPlatformSpecific, "C++: chip::DeviceLayer::DeviceEventType::IsPlatformSpecific(unsigned short) --> bool", pybind11::arg("eventType"));

	// chip::DeviceLayer::DeviceEventType::IsPlatformGeneric(unsigned short) file:platform/CHIPDeviceEvent.h line:91
	M("chip::DeviceLayer::DeviceEventType").def("IsPlatformGeneric", (bool (*)(unsigned short)) &chip::DeviceLayer::DeviceEventType::IsPlatformGeneric, "C++: chip::DeviceLayer::DeviceEventType::IsPlatformGeneric(unsigned short) --> bool", pybind11::arg("eventType"));

	// chip::DeviceLayer::DeviceEventType::PublicEventTypes file:platform/CHIPDeviceEvent.h line:102
	pybind11::enum_<chip::DeviceLayer::DeviceEventType::PublicEventTypes>(M("chip::DeviceLayer::DeviceEventType"), "PublicEventTypes", pybind11::arithmetic(), "Public Event Types\n\n Enumerates event types that are visible to the application and common across\n all platforms.")
		.value("kWiFiConnectivityChange", chip::DeviceLayer::DeviceEventType::kWiFiConnectivityChange)
		.value("kThreadConnectivityChange", chip::DeviceLayer::DeviceEventType::kThreadConnectivityChange)
		.value("kInternetConnectivityChange", chip::DeviceLayer::DeviceEventType::kInternetConnectivityChange)
		.value("kServiceConnectivityChange", chip::DeviceLayer::DeviceEventType::kServiceConnectivityChange)
		.value("kFabricMembershipChange", chip::DeviceLayer::DeviceEventType::kFabricMembershipChange)
		.value("kServiceProvisioningChange", chip::DeviceLayer::DeviceEventType::kServiceProvisioningChange)
		.value("kAccountPairingChange", chip::DeviceLayer::DeviceEventType::kAccountPairingChange)
		.value("kTimeSyncChange", chip::DeviceLayer::DeviceEventType::kTimeSyncChange)
		.value("kSessionEstablished", chip::DeviceLayer::DeviceEventType::kSessionEstablished)
		.value("kCHIPoBLEConnectionEstablished", chip::DeviceLayer::DeviceEventType::kCHIPoBLEConnectionEstablished)
		.value("kThreadStateChange", chip::DeviceLayer::DeviceEventType::kThreadStateChange)
		.value("kThreadInterfaceStateChange", chip::DeviceLayer::DeviceEventType::kThreadInterfaceStateChange)
		.value("kCHIPoBLEAdvertisingChange", chip::DeviceLayer::DeviceEventType::kCHIPoBLEAdvertisingChange)
		.value("kInterfaceIpAddressChanged", chip::DeviceLayer::DeviceEventType::kInterfaceIpAddressChanged)
		.value("kCommissioningComplete", chip::DeviceLayer::DeviceEventType::kCommissioningComplete)
		.value("kOperationalNetworkEnabled", chip::DeviceLayer::DeviceEventType::kOperationalNetworkEnabled)
		.export_values();

;

	// chip::DeviceLayer::DeviceEventType::InternalEventTypes file:platform/CHIPDeviceEvent.h line:218
	pybind11::enum_<chip::DeviceLayer::DeviceEventType::InternalEventTypes>(M("chip::DeviceLayer::DeviceEventType"), "InternalEventTypes", pybind11::arithmetic(), "Internal Event Types\n\n Enumerates event types that are internal to the chip Device Layer, but common across\n all platforms.")
		.value("kEventTypeNotSet", chip::DeviceLayer::DeviceEventType::kEventTypeNotSet)
		.value("kNoOp", chip::DeviceLayer::DeviceEventType::kNoOp)
		.value("kCallWorkFunct", chip::DeviceLayer::DeviceEventType::kCallWorkFunct)
		.value("kChipSystemLayerEvent", chip::DeviceLayer::DeviceEventType::kChipSystemLayerEvent)
		.value("kCHIPoBLESubscribe", chip::DeviceLayer::DeviceEventType::kCHIPoBLESubscribe)
		.value("kCHIPoBLEUnsubscribe", chip::DeviceLayer::DeviceEventType::kCHIPoBLEUnsubscribe)
		.value("kCHIPoBLEWriteReceived", chip::DeviceLayer::DeviceEventType::kCHIPoBLEWriteReceived)
		.value("kCHIPoBLEIndicateConfirm", chip::DeviceLayer::DeviceEventType::kCHIPoBLEIndicateConfirm)
		.value("kCHIPoBLEConnectionError", chip::DeviceLayer::DeviceEventType::kCHIPoBLEConnectionError)
		.export_values();

;

}
