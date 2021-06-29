#include <platform/PlatformManager.h>
#include <support/BitFlags.h>
#include <sys/_types/_fd_def.h>
#include <system/SystemLayer.h>
#include <system/SystemObject.h>
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

void bind_PyChip_45(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	// chip::System::Platform::Layer::PostEvent(class chip::System::Layer &, void *, class chip::System::Object &, int, unsigned long) file:platform/PlatformManager.h line:34
	M("chip::System::Platform::Layer").def("PostEvent", (int (*)(class chip::System::Layer &, void *, class chip::System::Object &, int, unsigned long)) &chip::System::Platform::Layer::PostEvent, "C++: chip::System::Platform::Layer::PostEvent(class chip::System::Layer &, void *, class chip::System::Object &, int, unsigned long) --> int", pybind11::arg("aLayer"), pybind11::arg("aContext"), pybind11::arg("aTarget"), pybind11::arg("aType"), pybind11::arg("aArgument"));

	// chip::System::Platform::Layer::DispatchEvents(class chip::System::Layer &, void *) file:platform/PlatformManager.h line:36
	M("chip::System::Platform::Layer").def("DispatchEvents", (int (*)(class chip::System::Layer &, void *)) &chip::System::Platform::Layer::DispatchEvents, "C++: chip::System::Platform::Layer::DispatchEvents(class chip::System::Layer &, void *) --> int", pybind11::arg("aLayer"), pybind11::arg("aContext"));

	// chip::System::Platform::Layer::DispatchEvent(class chip::System::Layer &, void *, const struct chip::DeviceLayer::ChipDeviceEvent *) file:platform/PlatformManager.h line:37
	M("chip::System::Platform::Layer").def("DispatchEvent", (int (*)(class chip::System::Layer &, void *, const struct chip::DeviceLayer::ChipDeviceEvent *)) &chip::System::Platform::Layer::DispatchEvent, "C++: chip::System::Platform::Layer::DispatchEvent(class chip::System::Layer &, void *, const struct chip::DeviceLayer::ChipDeviceEvent *) --> int", pybind11::arg("aLayer"), pybind11::arg("aContext"), pybind11::arg("aEvent"));

	// chip::System::Platform::Layer::StartTimer(class chip::System::Layer &, void *, unsigned int) file:platform/PlatformManager.h line:38
	M("chip::System::Platform::Layer").def("StartTimer", (int (*)(class chip::System::Layer &, void *, unsigned int)) &chip::System::Platform::Layer::StartTimer, "C++: chip::System::Platform::Layer::StartTimer(class chip::System::Layer &, void *, unsigned int) --> int", pybind11::arg("aLayer"), pybind11::arg("aContext"), pybind11::arg("aMilliseconds"));

}
