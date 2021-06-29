#include <platform/TimeSyncManager.h>
#include <sstream> // __str__

#include <pybind11/pybind11.h>
#include <functional>
#include <string>

#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>)
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*)
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

void bind_PyChip_59(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // chip::DeviceLayer::SoftwareUpdateManagerImpl file: line:32
		pybind11::class_<chip::DeviceLayer::SoftwareUpdateManagerImpl, std::shared_ptr<chip::DeviceLayer::SoftwareUpdateManagerImpl>, chip::DeviceLayer::SoftwareUpdateManager, chip::DeviceLayer::Internal::GenericSoftwareUpdateManagerImpl<chip::DeviceLayer::SoftwareUpdateManagerImpl>> cl(M("chip::DeviceLayer"), "SoftwareUpdateManagerImpl", "Concrete implementation of the SoftwareUpdateManager singleton object for the\n nRF52 platforms.");
		cl.def( pybind11::init( [](){ return new chip::DeviceLayer::SoftwareUpdateManagerImpl(); } ) );
	}
	{ // chip::DeviceLayer::TimeSyncManager file:platform/TimeSyncManager.h line:49
		pybind11::class_<chip::DeviceLayer::TimeSyncManager, chip::DeviceLayer::TimeSyncManager*> cl(M("chip::DeviceLayer"), "TimeSyncManager", "Manages time synchronization for chip Devices.");

		pybind11::enum_<chip::DeviceLayer::TimeSyncManager::TimeSyncMode>(cl, "TimeSyncMode", pybind11::arithmetic(), "")
			.value("kTimeSyncMode_NotSupported", chip::DeviceLayer::TimeSyncManager::kTimeSyncMode_NotSupported)
			.value("kTimeSyncMode_Disabled", chip::DeviceLayer::TimeSyncManager::kTimeSyncMode_Disabled)
			.value("kTimeSyncMode_Service", chip::DeviceLayer::TimeSyncManager::kTimeSyncMode_Service)
			.value("kTimeSyncMode_Max", chip::DeviceLayer::TimeSyncManager::kTimeSyncMode_Max)
			.export_values();

		cl.def("GetMode", (enum chip::DeviceLayer::TimeSyncManager::TimeSyncMode (chip::DeviceLayer::TimeSyncManager::*)()) &chip::DeviceLayer::TimeSyncManager::GetMode, "C++: chip::DeviceLayer::TimeSyncManager::GetMode() --> enum chip::DeviceLayer::TimeSyncManager::TimeSyncMode");
		cl.def("SetMode", (int (chip::DeviceLayer::TimeSyncManager::*)(enum chip::DeviceLayer::TimeSyncManager::TimeSyncMode)) &chip::DeviceLayer::TimeSyncManager::SetMode, "C++: chip::DeviceLayer::TimeSyncManager::SetMode(enum chip::DeviceLayer::TimeSyncManager::TimeSyncMode) --> int", pybind11::arg("newMode"));
		cl.def("GetSyncInterval", (unsigned int (chip::DeviceLayer::TimeSyncManager::*)()) &chip::DeviceLayer::TimeSyncManager::GetSyncInterval, "C++: chip::DeviceLayer::TimeSyncManager::GetSyncInterval() --> unsigned int");
		cl.def("SetSyncInterval", (void (chip::DeviceLayer::TimeSyncManager::*)(unsigned int)) &chip::DeviceLayer::TimeSyncManager::SetSyncInterval, "C++: chip::DeviceLayer::TimeSyncManager::SetSyncInterval(unsigned int) --> void", pybind11::arg("intervalSec"));
		cl.def("IsTimeSynchronized", (bool (chip::DeviceLayer::TimeSyncManager::*)()) &chip::DeviceLayer::TimeSyncManager::IsTimeSynchronized, "C++: chip::DeviceLayer::TimeSyncManager::IsTimeSynchronized() --> bool");
	}
	// chip::DeviceLayer::TimeSyncMgr() file:platform/TimeSyncManager.h line:79
	M("chip::DeviceLayer").def("TimeSyncMgr", (class chip::DeviceLayer::TimeSyncManager & (*)()) &chip::DeviceLayer::TimeSyncMgr, "C++: chip::DeviceLayer::TimeSyncMgr() --> class chip::DeviceLayer::TimeSyncManager &", pybind11::return_value_policy::automatic);

}
