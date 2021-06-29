#include <support/logging/Constants.h>

#include <pybind11/pybind11.h>
#include <functional>
#include <string>

#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>)
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*)
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

void bind_PyChip_14(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	// chip::Logging::LogModule file:support/logging/Constants.h line:19
	pybind11::enum_<chip::Logging::LogModule>(M("chip::Logging"), "LogModule", pybind11::arithmetic(), "Identifies a logical section of code that is a source of log\n    messages.\n\n  \n If you add modules or rearrange this list you must update the\n        ModuleNames tables in ChipLogging.cpp.\n\n ")
		.value("kLogModule_NotSpecified", chip::Logging::kLogModule_NotSpecified)
		.value("kLogModule_Inet", chip::Logging::kLogModule_Inet)
		.value("kLogModule_Ble", chip::Logging::kLogModule_Ble)
		.value("kLogModule_MessageLayer", chip::Logging::kLogModule_MessageLayer)
		.value("kLogModule_SecurityManager", chip::Logging::kLogModule_SecurityManager)
		.value("kLogModule_ExchangeManager", chip::Logging::kLogModule_ExchangeManager)
		.value("kLogModule_TLV", chip::Logging::kLogModule_TLV)
		.value("kLogModule_ASN1", chip::Logging::kLogModule_ASN1)
		.value("kLogModule_Crypto", chip::Logging::kLogModule_Crypto)
		.value("kLogModule_Controller", chip::Logging::kLogModule_Controller)
		.value("kLogModule_Alarm", chip::Logging::kLogModule_Alarm)
		.value("kLogModule_SecureChannel", chip::Logging::kLogModule_SecureChannel)
		.value("kLogModule_BDX", chip::Logging::kLogModule_BDX)
		.value("kLogModule_DataManagement", chip::Logging::kLogModule_DataManagement)
		.value("kLogModule_DeviceControl", chip::Logging::kLogModule_DeviceControl)
		.value("kLogModule_DeviceDescription", chip::Logging::kLogModule_DeviceDescription)
		.value("kLogModule_Echo", chip::Logging::kLogModule_Echo)
		.value("kLogModule_FabricProvisioning", chip::Logging::kLogModule_FabricProvisioning)
		.value("kLogModule_NetworkProvisioning", chip::Logging::kLogModule_NetworkProvisioning)
		.value("kLogModule_ServiceDirectory", chip::Logging::kLogModule_ServiceDirectory)
		.value("kLogModule_ServiceProvisioning", chip::Logging::kLogModule_ServiceProvisioning)
		.value("kLogModule_SoftwareUpdate", chip::Logging::kLogModule_SoftwareUpdate)
		.value("kLogModule_TokenPairing", chip::Logging::kLogModule_TokenPairing)
		.value("kLogModule_TimeService", chip::Logging::kLogModule_TimeService)
		.value("kLogModule_Heartbeat", chip::Logging::kLogModule_Heartbeat)
		.value("kLogModule_chipSystemLayer", chip::Logging::kLogModule_chipSystemLayer)
		.value("kLogModule_EventLogging", chip::Logging::kLogModule_EventLogging)
		.value("kLogModule_Support", chip::Logging::kLogModule_Support)
		.value("kLogModule_chipTool", chip::Logging::kLogModule_chipTool)
		.value("kLogModule_Zcl", chip::Logging::kLogModule_Zcl)
		.value("kLogModule_Shell", chip::Logging::kLogModule_Shell)
		.value("kLogModule_DeviceLayer", chip::Logging::kLogModule_DeviceLayer)
		.value("kLogModule_SetupPayload", chip::Logging::kLogModule_SetupPayload)
		.value("kLogModule_AppServer", chip::Logging::kLogModule_AppServer)
		.value("kLogModule_Discovery", chip::Logging::kLogModule_Discovery)
		.value("kLogModule_Max", chip::Logging::kLogModule_Max)
		.export_values();

;

	// chip::Logging::LogCategory file:support/logging/Constants.h line:69
	pybind11::enum_<chip::Logging::LogCategory>(M("chip::Logging"), "LogCategory", pybind11::arithmetic(), "Identifies a category to which an particular error message\n    belongs.\n\n ")
		.value("kLogCategory_None", chip::Logging::kLogCategory_None)
		.value("kLogCategory_Error", chip::Logging::kLogCategory_Error)
		.value("kLogCategory_Progress", chip::Logging::kLogCategory_Progress)
		.value("kLogCategory_Detail", chip::Logging::kLogCategory_Detail)
		.value("kLogCategory_Max", chip::Logging::kLogCategory_Max)
		.export_values();

;

}
