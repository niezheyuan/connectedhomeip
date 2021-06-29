#include <ble/BleApplicationDelegate.h>
#include <ble/BleConnectionDelegate.h>
#include <ble/BleLayer.h>
#include <ble/BlePlatformDelegate.h>
#include <ble/BleUUID.h>
#include <platform/ConnectivityManager.h>
#include <sstream> // __str__
#include <system/SystemLayer.h>

#include <pybind11/pybind11.h>
#include <functional>
#include <string>

#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>)
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*)
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

void bind_PyChip_36(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // chip::DeviceLayer::ConfigurationManagerImpl file: line:36
		pybind11::class_<chip::DeviceLayer::ConfigurationManagerImpl, std::shared_ptr<chip::DeviceLayer::ConfigurationManagerImpl>, chip::DeviceLayer::ConfigurationManager, chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>> cl(M("chip::DeviceLayer"), "ConfigurationManagerImpl", "Concrete implementation of the ConfigurationManager singleton object for the Darwin platform.");
		cl.def( pybind11::init( [](){ return new chip::DeviceLayer::ConfigurationManagerImpl(); } ) );
	}
	{ // chip::DeviceLayer::ConnectivityManager file:platform/ConnectivityManager.h line:51
		pybind11::class_<chip::DeviceLayer::ConnectivityManager, chip::DeviceLayer::ConnectivityManager*> cl(M("chip::DeviceLayer"), "ConnectivityManager", "Provides control of network connectivity for a chip device.");

		pybind11::enum_<chip::DeviceLayer::ConnectivityManager::WiFiStationMode>(cl, "WiFiStationMode", pybind11::arithmetic(), "")
			.value("kWiFiStationMode_NotSupported", chip::DeviceLayer::ConnectivityManager::kWiFiStationMode_NotSupported)
			.value("kWiFiStationMode_ApplicationControlled", chip::DeviceLayer::ConnectivityManager::kWiFiStationMode_ApplicationControlled)
			.value("kWiFiStationMode_Disabled", chip::DeviceLayer::ConnectivityManager::kWiFiStationMode_Disabled)
			.value("kWiFiStationMode_Enabled", chip::DeviceLayer::ConnectivityManager::kWiFiStationMode_Enabled)
			.export_values();


		pybind11::enum_<chip::DeviceLayer::ConnectivityManager::WiFiAPMode>(cl, "WiFiAPMode", pybind11::arithmetic(), "")
			.value("kWiFiAPMode_NotSupported", chip::DeviceLayer::ConnectivityManager::kWiFiAPMode_NotSupported)
			.value("kWiFiAPMode_ApplicationControlled", chip::DeviceLayer::ConnectivityManager::kWiFiAPMode_ApplicationControlled)
			.value("kWiFiAPMode_Disabled", chip::DeviceLayer::ConnectivityManager::kWiFiAPMode_Disabled)
			.value("kWiFiAPMode_Enabled", chip::DeviceLayer::ConnectivityManager::kWiFiAPMode_Enabled)
			.value("kWiFiAPMode_OnDemand", chip::DeviceLayer::ConnectivityManager::kWiFiAPMode_OnDemand)
			.value("kWiFiAPMode_OnDemand_NoStationProvision", chip::DeviceLayer::ConnectivityManager::kWiFiAPMode_OnDemand_NoStationProvision)
			.export_values();


		pybind11::enum_<chip::DeviceLayer::ConnectivityManager::ThreadMode>(cl, "ThreadMode", pybind11::arithmetic(), "")
			.value("kThreadMode_NotSupported", chip::DeviceLayer::ConnectivityManager::kThreadMode_NotSupported)
			.value("kThreadMode_ApplicationControlled", chip::DeviceLayer::ConnectivityManager::kThreadMode_ApplicationControlled)
			.value("kThreadMode_Disabled", chip::DeviceLayer::ConnectivityManager::kThreadMode_Disabled)
			.value("kThreadMode_Enabled", chip::DeviceLayer::ConnectivityManager::kThreadMode_Enabled)
			.export_values();


		pybind11::enum_<chip::DeviceLayer::ConnectivityManager::WiFiStationState>(cl, "WiFiStationState", pybind11::arithmetic(), "")
			.value("kWiFiStationState_NotConnected", chip::DeviceLayer::ConnectivityManager::kWiFiStationState_NotConnected)
			.value("kWiFiStationState_Connecting", chip::DeviceLayer::ConnectivityManager::kWiFiStationState_Connecting)
			.value("kWiFiStationState_Connecting_Succeeded", chip::DeviceLayer::ConnectivityManager::kWiFiStationState_Connecting_Succeeded)
			.value("kWiFiStationState_Connecting_Failed", chip::DeviceLayer::ConnectivityManager::kWiFiStationState_Connecting_Failed)
			.value("kWiFiStationState_Connected", chip::DeviceLayer::ConnectivityManager::kWiFiStationState_Connected)
			.value("kWiFiStationState_Disconnecting", chip::DeviceLayer::ConnectivityManager::kWiFiStationState_Disconnecting)
			.export_values();


		pybind11::enum_<chip::DeviceLayer::ConnectivityManager::WiFiAPState>(cl, "WiFiAPState", pybind11::arithmetic(), "")
			.value("kWiFiAPState_NotActive", chip::DeviceLayer::ConnectivityManager::kWiFiAPState_NotActive)
			.value("kWiFiAPState_Activating", chip::DeviceLayer::ConnectivityManager::kWiFiAPState_Activating)
			.value("kWiFiAPState_Active", chip::DeviceLayer::ConnectivityManager::kWiFiAPState_Active)
			.value("kWiFiAPState_Deactivating", chip::DeviceLayer::ConnectivityManager::kWiFiAPState_Deactivating)
			.export_values();


		pybind11::enum_<chip::DeviceLayer::ConnectivityManager::CHIPoBLEServiceMode>(cl, "CHIPoBLEServiceMode", pybind11::arithmetic(), "")
			.value("kCHIPoBLEServiceMode_NotSupported", chip::DeviceLayer::ConnectivityManager::kCHIPoBLEServiceMode_NotSupported)
			.value("kCHIPoBLEServiceMode_Enabled", chip::DeviceLayer::ConnectivityManager::kCHIPoBLEServiceMode_Enabled)
			.value("kCHIPoBLEServiceMode_Disabled", chip::DeviceLayer::ConnectivityManager::kCHIPoBLEServiceMode_Disabled)
			.export_values();


		pybind11::enum_<chip::DeviceLayer::ConnectivityManager::ThreadDeviceType>(cl, "ThreadDeviceType", pybind11::arithmetic(), "")
			.value("kThreadDeviceType_NotSupported", chip::DeviceLayer::ConnectivityManager::kThreadDeviceType_NotSupported)
			.value("kThreadDeviceType_Router", chip::DeviceLayer::ConnectivityManager::kThreadDeviceType_Router)
			.value("kThreadDeviceType_FullEndDevice", chip::DeviceLayer::ConnectivityManager::kThreadDeviceType_FullEndDevice)
			.value("kThreadDeviceType_MinimalEndDevice", chip::DeviceLayer::ConnectivityManager::kThreadDeviceType_MinimalEndDevice)
			.value("kThreadDeviceType_SleepyEndDevice", chip::DeviceLayer::ConnectivityManager::kThreadDeviceType_SleepyEndDevice)
			.export_values();


		pybind11::enum_<chip::DeviceLayer::ConnectivityManager::BLEAdvertisingMode>(cl, "BLEAdvertisingMode", pybind11::arithmetic(), "")
			.value("kFastAdvertising", chip::DeviceLayer::ConnectivityManager::kFastAdvertising)
			.value("kSlowAdvertising", chip::DeviceLayer::ConnectivityManager::kSlowAdvertising)
			.export_values();

		cl.def("GetWiFiStationMode", (enum chip::DeviceLayer::ConnectivityManager::WiFiStationMode (chip::DeviceLayer::ConnectivityManager::*)()) &chip::DeviceLayer::ConnectivityManager::GetWiFiStationMode, "C++: chip::DeviceLayer::ConnectivityManager::GetWiFiStationMode() --> enum chip::DeviceLayer::ConnectivityManager::WiFiStationMode");
		cl.def("SetWiFiStationMode", (int (chip::DeviceLayer::ConnectivityManager::*)(enum chip::DeviceLayer::ConnectivityManager::WiFiStationMode)) &chip::DeviceLayer::ConnectivityManager::SetWiFiStationMode, "C++: chip::DeviceLayer::ConnectivityManager::SetWiFiStationMode(enum chip::DeviceLayer::ConnectivityManager::WiFiStationMode) --> int", pybind11::arg("val"));
		cl.def("IsWiFiStationEnabled", (bool (chip::DeviceLayer::ConnectivityManager::*)()) &chip::DeviceLayer::ConnectivityManager::IsWiFiStationEnabled, "C++: chip::DeviceLayer::ConnectivityManager::IsWiFiStationEnabled() --> bool");
		cl.def("IsWiFiStationApplicationControlled", (bool (chip::DeviceLayer::ConnectivityManager::*)()) &chip::DeviceLayer::ConnectivityManager::IsWiFiStationApplicationControlled, "C++: chip::DeviceLayer::ConnectivityManager::IsWiFiStationApplicationControlled() --> bool");
		cl.def("IsWiFiStationConnected", (bool (chip::DeviceLayer::ConnectivityManager::*)()) &chip::DeviceLayer::ConnectivityManager::IsWiFiStationConnected, "C++: chip::DeviceLayer::ConnectivityManager::IsWiFiStationConnected() --> bool");
		cl.def("GetWiFiStationReconnectIntervalMS", (unsigned int (chip::DeviceLayer::ConnectivityManager::*)()) &chip::DeviceLayer::ConnectivityManager::GetWiFiStationReconnectIntervalMS, "C++: chip::DeviceLayer::ConnectivityManager::GetWiFiStationReconnectIntervalMS() --> unsigned int");
		cl.def("SetWiFiStationReconnectIntervalMS", (int (chip::DeviceLayer::ConnectivityManager::*)(unsigned int)) &chip::DeviceLayer::ConnectivityManager::SetWiFiStationReconnectIntervalMS, "C++: chip::DeviceLayer::ConnectivityManager::SetWiFiStationReconnectIntervalMS(unsigned int) --> int", pybind11::arg("val"));
		cl.def("IsWiFiStationProvisioned", (bool (chip::DeviceLayer::ConnectivityManager::*)()) &chip::DeviceLayer::ConnectivityManager::IsWiFiStationProvisioned, "C++: chip::DeviceLayer::ConnectivityManager::IsWiFiStationProvisioned() --> bool");
		cl.def("ClearWiFiStationProvision", (void (chip::DeviceLayer::ConnectivityManager::*)()) &chip::DeviceLayer::ConnectivityManager::ClearWiFiStationProvision, "C++: chip::DeviceLayer::ConnectivityManager::ClearWiFiStationProvision() --> void");
		cl.def("GetAndLogWifiStatsCounters", (int (chip::DeviceLayer::ConnectivityManager::*)()) &chip::DeviceLayer::ConnectivityManager::GetAndLogWifiStatsCounters, "C++: chip::DeviceLayer::ConnectivityManager::GetAndLogWifiStatsCounters() --> int");
		cl.def("GetWiFiAPMode", (enum chip::DeviceLayer::ConnectivityManager::WiFiAPMode (chip::DeviceLayer::ConnectivityManager::*)()) &chip::DeviceLayer::ConnectivityManager::GetWiFiAPMode, "C++: chip::DeviceLayer::ConnectivityManager::GetWiFiAPMode() --> enum chip::DeviceLayer::ConnectivityManager::WiFiAPMode");
		cl.def("SetWiFiAPMode", (int (chip::DeviceLayer::ConnectivityManager::*)(enum chip::DeviceLayer::ConnectivityManager::WiFiAPMode)) &chip::DeviceLayer::ConnectivityManager::SetWiFiAPMode, "C++: chip::DeviceLayer::ConnectivityManager::SetWiFiAPMode(enum chip::DeviceLayer::ConnectivityManager::WiFiAPMode) --> int", pybind11::arg("val"));
		cl.def("IsWiFiAPActive", (bool (chip::DeviceLayer::ConnectivityManager::*)()) &chip::DeviceLayer::ConnectivityManager::IsWiFiAPActive, "C++: chip::DeviceLayer::ConnectivityManager::IsWiFiAPActive() --> bool");
		cl.def("IsWiFiAPApplicationControlled", (bool (chip::DeviceLayer::ConnectivityManager::*)()) &chip::DeviceLayer::ConnectivityManager::IsWiFiAPApplicationControlled, "C++: chip::DeviceLayer::ConnectivityManager::IsWiFiAPApplicationControlled() --> bool");
		cl.def("DemandStartWiFiAP", (void (chip::DeviceLayer::ConnectivityManager::*)()) &chip::DeviceLayer::ConnectivityManager::DemandStartWiFiAP, "C++: chip::DeviceLayer::ConnectivityManager::DemandStartWiFiAP() --> void");
		cl.def("StopOnDemandWiFiAP", (void (chip::DeviceLayer::ConnectivityManager::*)()) &chip::DeviceLayer::ConnectivityManager::StopOnDemandWiFiAP, "C++: chip::DeviceLayer::ConnectivityManager::StopOnDemandWiFiAP() --> void");
		cl.def("MaintainOnDemandWiFiAP", (void (chip::DeviceLayer::ConnectivityManager::*)()) &chip::DeviceLayer::ConnectivityManager::MaintainOnDemandWiFiAP, "C++: chip::DeviceLayer::ConnectivityManager::MaintainOnDemandWiFiAP() --> void");
		cl.def("GetWiFiAPIdleTimeoutMS", (unsigned int (chip::DeviceLayer::ConnectivityManager::*)()) &chip::DeviceLayer::ConnectivityManager::GetWiFiAPIdleTimeoutMS, "C++: chip::DeviceLayer::ConnectivityManager::GetWiFiAPIdleTimeoutMS() --> unsigned int");
		cl.def("SetWiFiAPIdleTimeoutMS", (void (chip::DeviceLayer::ConnectivityManager::*)(unsigned int)) &chip::DeviceLayer::ConnectivityManager::SetWiFiAPIdleTimeoutMS, "C++: chip::DeviceLayer::ConnectivityManager::SetWiFiAPIdleTimeoutMS(unsigned int) --> void", pybind11::arg("val"));
		cl.def("GetThreadMode", (enum chip::DeviceLayer::ConnectivityManager::ThreadMode (chip::DeviceLayer::ConnectivityManager::*)()) &chip::DeviceLayer::ConnectivityManager::GetThreadMode, "C++: chip::DeviceLayer::ConnectivityManager::GetThreadMode() --> enum chip::DeviceLayer::ConnectivityManager::ThreadMode");
		cl.def("SetThreadMode", (int (chip::DeviceLayer::ConnectivityManager::*)(enum chip::DeviceLayer::ConnectivityManager::ThreadMode)) &chip::DeviceLayer::ConnectivityManager::SetThreadMode, "C++: chip::DeviceLayer::ConnectivityManager::SetThreadMode(enum chip::DeviceLayer::ConnectivityManager::ThreadMode) --> int", pybind11::arg("val"));
		cl.def("IsThreadEnabled", (bool (chip::DeviceLayer::ConnectivityManager::*)()) &chip::DeviceLayer::ConnectivityManager::IsThreadEnabled, "C++: chip::DeviceLayer::ConnectivityManager::IsThreadEnabled() --> bool");
		cl.def("IsThreadApplicationControlled", (bool (chip::DeviceLayer::ConnectivityManager::*)()) &chip::DeviceLayer::ConnectivityManager::IsThreadApplicationControlled, "C++: chip::DeviceLayer::ConnectivityManager::IsThreadApplicationControlled() --> bool");
		cl.def("GetThreadDeviceType", (enum chip::DeviceLayer::ConnectivityManager::ThreadDeviceType (chip::DeviceLayer::ConnectivityManager::*)()) &chip::DeviceLayer::ConnectivityManager::GetThreadDeviceType, "C++: chip::DeviceLayer::ConnectivityManager::GetThreadDeviceType() --> enum chip::DeviceLayer::ConnectivityManager::ThreadDeviceType");
		cl.def("SetThreadDeviceType", (int (chip::DeviceLayer::ConnectivityManager::*)(enum chip::DeviceLayer::ConnectivityManager::ThreadDeviceType)) &chip::DeviceLayer::ConnectivityManager::SetThreadDeviceType, "C++: chip::DeviceLayer::ConnectivityManager::SetThreadDeviceType(enum chip::DeviceLayer::ConnectivityManager::ThreadDeviceType) --> int", pybind11::arg("deviceType"));
		cl.def("GetThreadPollingConfig", (void (chip::DeviceLayer::ConnectivityManager::*)(struct chip::DeviceLayer::ConnectivityManager::ThreadPollingConfig &)) &chip::DeviceLayer::ConnectivityManager::GetThreadPollingConfig, "C++: chip::DeviceLayer::ConnectivityManager::GetThreadPollingConfig(struct chip::DeviceLayer::ConnectivityManager::ThreadPollingConfig &) --> void", pybind11::arg("pollingConfig"));
		cl.def("SetThreadPollingConfig", (int (chip::DeviceLayer::ConnectivityManager::*)(const struct chip::DeviceLayer::ConnectivityManager::ThreadPollingConfig &)) &chip::DeviceLayer::ConnectivityManager::SetThreadPollingConfig, "C++: chip::DeviceLayer::ConnectivityManager::SetThreadPollingConfig(const struct chip::DeviceLayer::ConnectivityManager::ThreadPollingConfig &) --> int", pybind11::arg("pollingConfig"));
		cl.def("IsThreadAttached", (bool (chip::DeviceLayer::ConnectivityManager::*)()) &chip::DeviceLayer::ConnectivityManager::IsThreadAttached, "C++: chip::DeviceLayer::ConnectivityManager::IsThreadAttached() --> bool");
		cl.def("IsThreadProvisioned", (bool (chip::DeviceLayer::ConnectivityManager::*)()) &chip::DeviceLayer::ConnectivityManager::IsThreadProvisioned, "C++: chip::DeviceLayer::ConnectivityManager::IsThreadProvisioned() --> bool");
		cl.def("ErasePersistentInfo", (void (chip::DeviceLayer::ConnectivityManager::*)()) &chip::DeviceLayer::ConnectivityManager::ErasePersistentInfo, "C++: chip::DeviceLayer::ConnectivityManager::ErasePersistentInfo() --> void");
		cl.def("HaveServiceConnectivityViaThread", (bool (chip::DeviceLayer::ConnectivityManager::*)()) &chip::DeviceLayer::ConnectivityManager::HaveServiceConnectivityViaThread, "C++: chip::DeviceLayer::ConnectivityManager::HaveServiceConnectivityViaThread() --> bool");
		cl.def("HaveIPv4InternetConnectivity", (bool (chip::DeviceLayer::ConnectivityManager::*)()) &chip::DeviceLayer::ConnectivityManager::HaveIPv4InternetConnectivity, "C++: chip::DeviceLayer::ConnectivityManager::HaveIPv4InternetConnectivity() --> bool");
		cl.def("HaveIPv6InternetConnectivity", (bool (chip::DeviceLayer::ConnectivityManager::*)()) &chip::DeviceLayer::ConnectivityManager::HaveIPv6InternetConnectivity, "C++: chip::DeviceLayer::ConnectivityManager::HaveIPv6InternetConnectivity() --> bool");
		cl.def("HaveServiceConnectivity", (bool (chip::DeviceLayer::ConnectivityManager::*)()) &chip::DeviceLayer::ConnectivityManager::HaveServiceConnectivity, "C++: chip::DeviceLayer::ConnectivityManager::HaveServiceConnectivity() --> bool");
		cl.def("GetBleLayer", (class chip::Ble::BleLayer * (chip::DeviceLayer::ConnectivityManager::*)()) &chip::DeviceLayer::ConnectivityManager::GetBleLayer, "C++: chip::DeviceLayer::ConnectivityManager::GetBleLayer() --> class chip::Ble::BleLayer *", pybind11::return_value_policy::automatic);
		cl.def("GetCHIPoBLEServiceMode", (enum chip::DeviceLayer::ConnectivityManager::CHIPoBLEServiceMode (chip::DeviceLayer::ConnectivityManager::*)()) &chip::DeviceLayer::ConnectivityManager::GetCHIPoBLEServiceMode, "C++: chip::DeviceLayer::ConnectivityManager::GetCHIPoBLEServiceMode() --> enum chip::DeviceLayer::ConnectivityManager::CHIPoBLEServiceMode");
		cl.def("SetCHIPoBLEServiceMode", (int (chip::DeviceLayer::ConnectivityManager::*)(enum chip::DeviceLayer::ConnectivityManager::CHIPoBLEServiceMode)) &chip::DeviceLayer::ConnectivityManager::SetCHIPoBLEServiceMode, "C++: chip::DeviceLayer::ConnectivityManager::SetCHIPoBLEServiceMode(enum chip::DeviceLayer::ConnectivityManager::CHIPoBLEServiceMode) --> int", pybind11::arg("val"));
		cl.def("IsBLEAdvertisingEnabled", (bool (chip::DeviceLayer::ConnectivityManager::*)()) &chip::DeviceLayer::ConnectivityManager::IsBLEAdvertisingEnabled, "C++: chip::DeviceLayer::ConnectivityManager::IsBLEAdvertisingEnabled() --> bool");
		cl.def("SetBLEAdvertisingEnabled", (int (chip::DeviceLayer::ConnectivityManager::*)(bool)) &chip::DeviceLayer::ConnectivityManager::SetBLEAdvertisingEnabled, "C++: chip::DeviceLayer::ConnectivityManager::SetBLEAdvertisingEnabled(bool) --> int", pybind11::arg("val"));
		cl.def("IsBLEAdvertising", (bool (chip::DeviceLayer::ConnectivityManager::*)()) &chip::DeviceLayer::ConnectivityManager::IsBLEAdvertising, "C++: chip::DeviceLayer::ConnectivityManager::IsBLEAdvertising() --> bool");
		cl.def("SetBLEAdvertisingMode", (int (chip::DeviceLayer::ConnectivityManager::*)(enum chip::DeviceLayer::ConnectivityManager::BLEAdvertisingMode)) &chip::DeviceLayer::ConnectivityManager::SetBLEAdvertisingMode, "C++: chip::DeviceLayer::ConnectivityManager::SetBLEAdvertisingMode(enum chip::DeviceLayer::ConnectivityManager::BLEAdvertisingMode) --> int", pybind11::arg("mode"));
		cl.def("GetBLEDeviceName", (int (chip::DeviceLayer::ConnectivityManager::*)(char *, unsigned long)) &chip::DeviceLayer::ConnectivityManager::GetBLEDeviceName, "C++: chip::DeviceLayer::ConnectivityManager::GetBLEDeviceName(char *, unsigned long) --> int", pybind11::arg("buf"), pybind11::arg("bufSize"));
		cl.def("SetBLEDeviceName", (int (chip::DeviceLayer::ConnectivityManager::*)(const char *)) &chip::DeviceLayer::ConnectivityManager::SetBLEDeviceName, "C++: chip::DeviceLayer::ConnectivityManager::SetBLEDeviceName(const char *) --> int", pybind11::arg("deviceName"));
		cl.def("NumBLEConnections", (unsigned short (chip::DeviceLayer::ConnectivityManager::*)()) &chip::DeviceLayer::ConnectivityManager::NumBLEConnections, "C++: chip::DeviceLayer::ConnectivityManager::NumBLEConnections() --> unsigned short");
		cl.def("IsUserSelectedModeActive", (bool (chip::DeviceLayer::ConnectivityManager::*)()) &chip::DeviceLayer::ConnectivityManager::IsUserSelectedModeActive, "C++: chip::DeviceLayer::ConnectivityManager::IsUserSelectedModeActive() --> bool");
		cl.def("SetUserSelectedMode", (void (chip::DeviceLayer::ConnectivityManager::*)(bool)) &chip::DeviceLayer::ConnectivityManager::SetUserSelectedMode, "C++: chip::DeviceLayer::ConnectivityManager::SetUserSelectedMode(bool) --> void", pybind11::arg("val"));
		cl.def("GetUserSelectedModeTimeout", (unsigned short (chip::DeviceLayer::ConnectivityManager::*)()) &chip::DeviceLayer::ConnectivityManager::GetUserSelectedModeTimeout, "C++: chip::DeviceLayer::ConnectivityManager::GetUserSelectedModeTimeout() --> unsigned short");
		cl.def("SetUserSelectedModeTimeout", (void (chip::DeviceLayer::ConnectivityManager::*)(unsigned short)) &chip::DeviceLayer::ConnectivityManager::SetUserSelectedModeTimeout, "C++: chip::DeviceLayer::ConnectivityManager::SetUserSelectedModeTimeout(unsigned short) --> void", pybind11::arg("val"));
		cl.def_static("WiFiStationModeToStr", (const char * (*)(enum chip::DeviceLayer::ConnectivityManager::WiFiStationMode)) &chip::DeviceLayer::ConnectivityManager::WiFiStationModeToStr, "C++: chip::DeviceLayer::ConnectivityManager::WiFiStationModeToStr(enum chip::DeviceLayer::ConnectivityManager::WiFiStationMode) --> const char *", pybind11::return_value_policy::automatic, pybind11::arg("mode"));
		cl.def_static("WiFiAPModeToStr", (const char * (*)(enum chip::DeviceLayer::ConnectivityManager::WiFiAPMode)) &chip::DeviceLayer::ConnectivityManager::WiFiAPModeToStr, "C++: chip::DeviceLayer::ConnectivityManager::WiFiAPModeToStr(enum chip::DeviceLayer::ConnectivityManager::WiFiAPMode) --> const char *", pybind11::return_value_policy::automatic, pybind11::arg("mode"));
		cl.def_static("WiFiStationStateToStr", (const char * (*)(enum chip::DeviceLayer::ConnectivityManager::WiFiStationState)) &chip::DeviceLayer::ConnectivityManager::WiFiStationStateToStr, "C++: chip::DeviceLayer::ConnectivityManager::WiFiStationStateToStr(enum chip::DeviceLayer::ConnectivityManager::WiFiStationState) --> const char *", pybind11::return_value_policy::automatic, pybind11::arg("state"));
		cl.def_static("WiFiAPStateToStr", (const char * (*)(enum chip::DeviceLayer::ConnectivityManager::WiFiAPState)) &chip::DeviceLayer::ConnectivityManager::WiFiAPStateToStr, "C++: chip::DeviceLayer::ConnectivityManager::WiFiAPStateToStr(enum chip::DeviceLayer::ConnectivityManager::WiFiAPState) --> const char *", pybind11::return_value_policy::automatic, pybind11::arg("state"));
		cl.def_static("CHIPoBLEServiceModeToStr", (const char * (*)(enum chip::DeviceLayer::ConnectivityManager::CHIPoBLEServiceMode)) &chip::DeviceLayer::ConnectivityManager::CHIPoBLEServiceModeToStr, "C++: chip::DeviceLayer::ConnectivityManager::CHIPoBLEServiceModeToStr(enum chip::DeviceLayer::ConnectivityManager::CHIPoBLEServiceMode) --> const char *", pybind11::return_value_policy::automatic, pybind11::arg("mode"));

		{ // chip::DeviceLayer::ConnectivityManager::ThreadPollingConfig file:platform/ConnectivityManager.h line:226
			auto & enclosing_class = cl;
			pybind11::class_<chip::DeviceLayer::ConnectivityManager::ThreadPollingConfig, std::shared_ptr<chip::DeviceLayer::ConnectivityManager::ThreadPollingConfig>> cl(enclosing_class, "ThreadPollingConfig", "Information describing the desired Thread polling behavior of a device.");
			cl.def( pybind11::init( [](){ return new chip::DeviceLayer::ConnectivityManager::ThreadPollingConfig(); } ) );
			cl.def_readwrite("ActivePollingIntervalMS", &chip::DeviceLayer::ConnectivityManager::ThreadPollingConfig::ActivePollingIntervalMS);
			cl.def_readwrite("InactivePollingIntervalMS", &chip::DeviceLayer::ConnectivityManager::ThreadPollingConfig::InactivePollingIntervalMS);
			cl.def("Clear", (void (chip::DeviceLayer::ConnectivityManager::ThreadPollingConfig::*)()) &chip::DeviceLayer::ConnectivityManager::ThreadPollingConfig::Clear, "C++: chip::DeviceLayer::ConnectivityManager::ThreadPollingConfig::Clear() --> void");
		}

	}
}
