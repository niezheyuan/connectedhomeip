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

void bind_PyChip_6(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	// chip::System::SocketEventFlags file:system/SystemSockets.h line:41
	pybind11::enum_<chip::System::SocketEventFlags>(M("chip::System"), "SocketEventFlags", "")
		.value("kRead", chip::System::SocketEventFlags::kRead)
		.value("kWrite", chip::System::SocketEventFlags::kWrite)
		.value("kExcept", chip::System::SocketEventFlags::kExcept)
		.value("kError", chip::System::SocketEventFlags::kError);

;

	{ // chip::System::WatchableEventManager file: line:37
		pybind11::class_<chip::System::WatchableEventManager, std::shared_ptr<chip::System::WatchableEventManager>> cl(M("chip::System"), "WatchableEventManager", "");
		cl.def( pybind11::init( [](){ return new chip::System::WatchableEventManager(); } ) );
		cl.def( pybind11::init( [](chip::System::WatchableEventManager const &o){ return new chip::System::WatchableEventManager(o); } ) );
		cl.def("Init", (void (chip::System::WatchableEventManager::*)(class chip::System::Layer &)) &chip::System::WatchableEventManager::Init, "C++: chip::System::WatchableEventManager::Init(class chip::System::Layer &) --> void", pybind11::arg("systemLayer"));
		cl.def("Shutdown", (void (chip::System::WatchableEventManager::*)()) &chip::System::WatchableEventManager::Shutdown, "C++: chip::System::WatchableEventManager::Shutdown() --> void");
		cl.def("EventLoopBegins", (void (chip::System::WatchableEventManager::*)()) &chip::System::WatchableEventManager::EventLoopBegins, "C++: chip::System::WatchableEventManager::EventLoopBegins() --> void");
		cl.def("PrepareEvents", (void (chip::System::WatchableEventManager::*)()) &chip::System::WatchableEventManager::PrepareEvents, "C++: chip::System::WatchableEventManager::PrepareEvents() --> void");
		cl.def("WaitForEvents", (void (chip::System::WatchableEventManager::*)()) &chip::System::WatchableEventManager::WaitForEvents, "C++: chip::System::WatchableEventManager::WaitForEvents() --> void");
		cl.def("HandleEvents", (void (chip::System::WatchableEventManager::*)()) &chip::System::WatchableEventManager::HandleEvents, "C++: chip::System::WatchableEventManager::HandleEvents() --> void");
		cl.def("EventLoopEnds", (void (chip::System::WatchableEventManager::*)()) &chip::System::WatchableEventManager::EventLoopEnds, "C++: chip::System::WatchableEventManager::EventLoopEnds() --> void");
		cl.def("PrepareEventsWithTimeout", (void (chip::System::WatchableEventManager::*)(struct timeval &)) &chip::System::WatchableEventManager::PrepareEventsWithTimeout, "C++: chip::System::WatchableEventManager::PrepareEventsWithTimeout(struct timeval &) --> void", pybind11::arg("nextTimeout"));
		cl.def_static("SocketEventsFromFDs", (class chip::BitFlags<enum chip::System::SocketEventFlags, enum chip::System::SocketEventFlags> (*)(int, const struct fd_set &, const struct fd_set &, const struct fd_set &)) &chip::System::WatchableEventManager::SocketEventsFromFDs, "C++: chip::System::WatchableEventManager::SocketEventsFromFDs(int, const struct fd_set &, const struct fd_set &, const struct fd_set &) --> class chip::BitFlags<enum chip::System::SocketEventFlags, enum chip::System::SocketEventFlags>", pybind11::arg("socket"), pybind11::arg("readfds"), pybind11::arg("writefds"), pybind11::arg("exceptfds"));
		cl.def("assign", (class chip::System::WatchableEventManager & (chip::System::WatchableEventManager::*)(const class chip::System::WatchableEventManager &)) &chip::System::WatchableEventManager::operator=, "C++: chip::System::WatchableEventManager::operator=(const class chip::System::WatchableEventManager &) --> class chip::System::WatchableEventManager &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
	{ // chip::System::WatchableSocket file: line:85
		pybind11::class_<chip::System::WatchableSocket, std::shared_ptr<chip::System::WatchableSocket>> cl(M("chip::System"), "WatchableSocket", "");
		cl.def( pybind11::init( [](){ return new chip::System::WatchableSocket(); } ) );
		cl.def( pybind11::init( [](chip::System::WatchableSocket const &o){ return new chip::System::WatchableSocket(o); } ) );
		cl.def("OnInit", (void (chip::System::WatchableSocket::*)()) &chip::System::WatchableSocket::OnInit, "C++: chip::System::WatchableSocket::OnInit() --> void");
		cl.def("OnAttach", (void (chip::System::WatchableSocket::*)()) &chip::System::WatchableSocket::OnAttach, "C++: chip::System::WatchableSocket::OnAttach() --> void");
		cl.def("OnClose", (void (chip::System::WatchableSocket::*)()) &chip::System::WatchableSocket::OnClose, "C++: chip::System::WatchableSocket::OnClose() --> void");
		cl.def("OnRequestCallbackOnPendingRead", (void (chip::System::WatchableSocket::*)()) &chip::System::WatchableSocket::OnRequestCallbackOnPendingRead, "C++: chip::System::WatchableSocket::OnRequestCallbackOnPendingRead() --> void");
		cl.def("OnRequestCallbackOnPendingWrite", (void (chip::System::WatchableSocket::*)()) &chip::System::WatchableSocket::OnRequestCallbackOnPendingWrite, "C++: chip::System::WatchableSocket::OnRequestCallbackOnPendingWrite() --> void");
		cl.def("OnClearCallbackOnPendingRead", (void (chip::System::WatchableSocket::*)()) &chip::System::WatchableSocket::OnClearCallbackOnPendingRead, "C++: chip::System::WatchableSocket::OnClearCallbackOnPendingRead() --> void");
		cl.def("OnClearCallbackOnPendingWrite", (void (chip::System::WatchableSocket::*)()) &chip::System::WatchableSocket::OnClearCallbackOnPendingWrite, "C++: chip::System::WatchableSocket::OnClearCallbackOnPendingWrite() --> void");
		cl.def("SetPendingIO", (void (chip::System::WatchableSocket::*)(class chip::BitFlags<enum chip::System::SocketEventFlags, enum chip::System::SocketEventFlags>)) &chip::System::WatchableSocket::SetPendingIO, "C++: chip::System::WatchableSocket::SetPendingIO(class chip::BitFlags<enum chip::System::SocketEventFlags, enum chip::System::SocketEventFlags>) --> void", pybind11::arg("events"));
		cl.def("SetFDs", (void (chip::System::WatchableSocket::*)(int &, struct fd_set *, struct fd_set *, struct fd_set *)) &chip::System::WatchableSocket::SetFDs, "C++: chip::System::WatchableSocket::SetFDs(int &, struct fd_set *, struct fd_set *, struct fd_set *) --> void", pybind11::arg("nfds"), pybind11::arg("readfds"), pybind11::arg("writefds"), pybind11::arg("exceptfds"));
		cl.def("assign", (class chip::System::WatchableSocket & (chip::System::WatchableSocket::*)(const class chip::System::WatchableSocket &)) &chip::System::WatchableSocket::operator=, "C++: chip::System::WatchableSocket::operator=(const class chip::System::WatchableSocket &) --> class chip::System::WatchableSocket &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
	{ // chip::System::WakeEvent file:system/SystemSockets.h line:271
		pybind11::class_<chip::System::WakeEvent, std::shared_ptr<chip::System::WakeEvent>> cl(M("chip::System"), "WakeEvent", "");
		cl.def( pybind11::init( [](){ return new chip::System::WakeEvent(); } ) );
		cl.def("Open", (int (chip::System::WakeEvent::*)(class chip::System::WatchableEventManager &)) &chip::System::WakeEvent::Open, "C++: chip::System::WakeEvent::Open(class chip::System::WatchableEventManager &) --> int", pybind11::arg("watchState"));
		cl.def("Close", (int (chip::System::WakeEvent::*)()) &chip::System::WakeEvent::Close, "C++: chip::System::WakeEvent::Close() --> int");
		cl.def("GetNotifFD", (int (chip::System::WakeEvent::*)() const) &chip::System::WakeEvent::GetNotifFD, "C++: chip::System::WakeEvent::GetNotifFD() const --> int");
		cl.def("Notify", (int (chip::System::WakeEvent::*)()) &chip::System::WakeEvent::Notify, "C++: chip::System::WakeEvent::Notify() --> int");
		cl.def("Confirm", (void (chip::System::WakeEvent::*)()) &chip::System::WakeEvent::Confirm, "C++: chip::System::WakeEvent::Confirm() --> void");
		cl.def_static("Confirm", (void (*)(class chip::System::WatchableSocket &)) &chip::System::WakeEvent::Confirm, "C++: chip::System::WakeEvent::Confirm(class chip::System::WatchableSocket &) --> void", pybind11::arg("socket"));
	}
}
