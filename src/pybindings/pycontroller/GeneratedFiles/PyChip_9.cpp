#include <sstream> // __str__
#include <support/BitFlags.h>
#include <sys/_types/_fd_def.h>
#include <system/SystemLayer.h>
#include <system/SystemSockets.h>

#include <pybind11/pybind11.h>
#include <functional>
#include <string>

#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>)
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*)
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

void bind_PyChip_9(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	// chip::System::LayerState file:system/SystemLayer.h line:92
	pybind11::enum_<chip::System::LayerState>(M("chip::System"), "LayerState", pybind11::arithmetic(), "The state of a Layer object.")
		.value("kLayerState_NotInitialized", chip::System::kLayerState_NotInitialized)
		.value("kLayerState_Initialized", chip::System::kLayerState_Initialized)
		.export_values();

;

	{ // chip::System::Layer file:system/SystemLayer.h line:127
		pybind11::class_<chip::System::Layer, std::shared_ptr<chip::System::Layer>> cl(M("chip::System"), "Layer", "This provides access to timers according to the configured event handling model.\n\n      For  event readiness notification is handled via WatchableEventManager.\n\n      For  event readiness notification is handle via events / messages and platform- and\n      system-specific hooks for the event/message system.");
		cl.def( pybind11::init( [](){ return new chip::System::Layer(); } ) );
		cl.def("Init", (int (chip::System::Layer::*)(void *)) &chip::System::Layer::Init, "C++: chip::System::Layer::Init(void *) --> int", pybind11::arg("aContext"));
		cl.def("Shutdown", (int (chip::System::Layer::*)()) &chip::System::Layer::Shutdown, "C++: chip::System::Layer::Shutdown() --> int");
		cl.def("GetPlatformData", (void * (chip::System::Layer::*)() const) &chip::System::Layer::GetPlatformData, "C++: chip::System::Layer::GetPlatformData() const --> void *", pybind11::return_value_policy::automatic);
		cl.def("SetPlatformData", (void (chip::System::Layer::*)(void *)) &chip::System::Layer::SetPlatformData, "C++: chip::System::Layer::SetPlatformData(void *) --> void", pybind11::arg("aPlatformData"));
		cl.def("State", (enum chip::System::LayerState (chip::System::Layer::*)() const) &chip::System::Layer::State, "C++: chip::System::Layer::State() const --> enum chip::System::LayerState");
		cl.def("DispatchTimerCallbacks", (void (chip::System::Layer::*)(unsigned long long)) &chip::System::Layer::DispatchTimerCallbacks, "C++: chip::System::Layer::DispatchTimerCallbacks(unsigned long long) --> void", pybind11::arg("kCurrentEpoch"));
		cl.def("WatchableEvents", (class chip::System::WatchableEventManager & (chip::System::Layer::*)()) &chip::System::Layer::WatchableEvents, "C++: chip::System::Layer::WatchableEvents() --> class chip::System::WatchableEventManager &", pybind11::return_value_policy::automatic);
		cl.def("GetTimeout", (bool (chip::System::Layer::*)(struct timeval &)) &chip::System::Layer::GetTimeout, "C++: chip::System::Layer::GetTimeout(struct timeval &) --> bool", pybind11::arg("aSleepTime"));
		cl.def("HandleTimeout", (void (chip::System::Layer::*)()) &chip::System::Layer::HandleTimeout, "C++: chip::System::Layer::HandleTimeout() --> void");
		cl.def("WakeIOThread", (void (chip::System::Layer::*)()) &chip::System::Layer::WakeIOThread, "C++: chip::System::Layer::WakeIOThread() --> void");
		cl.def("SetDispatchQueue", (void (chip::System::Layer::*)(struct dispatch_queue_s *)) &chip::System::Layer::SetDispatchQueue, "C++: chip::System::Layer::SetDispatchQueue(struct dispatch_queue_s *) --> void", pybind11::arg("dispatchQueue"));
		cl.def("GetDispatchQueue", (struct dispatch_queue_s * (chip::System::Layer::*)()) &chip::System::Layer::GetDispatchQueue, "C++: chip::System::Layer::GetDispatchQueue() --> struct dispatch_queue_s *", pybind11::return_value_policy::automatic);
		cl.def_static("GetClock_Monotonic", (unsigned long long (*)()) &chip::System::Layer::GetClock_Monotonic, "C++: chip::System::Layer::GetClock_Monotonic() --> unsigned long long");
		cl.def_static("GetClock_MonotonicMS", (unsigned long long (*)()) &chip::System::Layer::GetClock_MonotonicMS, "C++: chip::System::Layer::GetClock_MonotonicMS() --> unsigned long long");
		cl.def_static("GetClock_MonotonicHiRes", (unsigned long long (*)()) &chip::System::Layer::GetClock_MonotonicHiRes, "C++: chip::System::Layer::GetClock_MonotonicHiRes() --> unsigned long long");
		cl.def_static("GetClock_RealTime", (int (*)(unsigned long long &)) &chip::System::Layer::GetClock_RealTime, "C++: chip::System::Layer::GetClock_RealTime(unsigned long long &) --> int", pybind11::arg("curTime"));
		cl.def_static("GetClock_RealTimeMS", (int (*)(unsigned long long &)) &chip::System::Layer::GetClock_RealTimeMS, "C++: chip::System::Layer::GetClock_RealTimeMS(unsigned long long &) --> int", pybind11::arg("curTimeMS"));
		cl.def_static("SetClock_RealTime", (int (*)(unsigned long long)) &chip::System::Layer::SetClock_RealTime, "C++: chip::System::Layer::SetClock_RealTime(unsigned long long) --> int", pybind11::arg("newCurTime"));
	}
}
