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

void bind_PyChip_42(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	// chip::DeviceLayer::ConnectivityChange file:platform/CHIPDeviceEvent.h line:240
	pybind11::enum_<chip::DeviceLayer::ConnectivityChange>(M("chip::DeviceLayer"), "ConnectivityChange", pybind11::arithmetic(), "Connectivity Change\n\n Describes a change in some aspect of connectivity associated with a chip device.")
		.value("kConnectivity_NoChange", chip::DeviceLayer::kConnectivity_NoChange)
		.value("kConnectivity_Established", chip::DeviceLayer::kConnectivity_Established)
		.value("kConnectivity_Lost", chip::DeviceLayer::kConnectivity_Lost)
		.export_values();

;

	// chip::DeviceLayer::InterfaceIpChangeType file:platform/CHIPDeviceEvent.h line:247
	pybind11::enum_<chip::DeviceLayer::InterfaceIpChangeType>(M("chip::DeviceLayer"), "InterfaceIpChangeType", "")
		.value("kIpV4_Assigned", chip::DeviceLayer::InterfaceIpChangeType::kIpV4_Assigned)
		.value("kIpV4_Lost", chip::DeviceLayer::InterfaceIpChangeType::kIpV4_Lost)
		.value("kIpV6_Assigned", chip::DeviceLayer::InterfaceIpChangeType::kIpV6_Assigned)
		.value("kIpV6_Lost", chip::DeviceLayer::InterfaceIpChangeType::kIpV6_Lost);

;

	// chip::DeviceLayer::ActivityChange file:platform/CHIPDeviceEvent.h line:260
	pybind11::enum_<chip::DeviceLayer::ActivityChange>(M("chip::DeviceLayer"), "ActivityChange", pybind11::arithmetic(), "Activity Change\n\n Describes a change in some activity associated with a chip device.")
		.value("kActivity_NoChange", chip::DeviceLayer::kActivity_NoChange)
		.value("kActivity_Started", chip::DeviceLayer::kActivity_Started)
		.value("kActivity_Stopped", chip::DeviceLayer::kActivity_Stopped)
		.export_values();

;

	// chip::DeviceLayer::GetConnectivityChange(bool, bool) file:platform/CHIPDeviceEvent.h line:267
	M("chip::DeviceLayer").def("GetConnectivityChange", (enum chip::DeviceLayer::ConnectivityChange (*)(bool, bool)) &chip::DeviceLayer::GetConnectivityChange, "C++: chip::DeviceLayer::GetConnectivityChange(bool, bool) --> enum chip::DeviceLayer::ConnectivityChange", pybind11::arg("prevState"), pybind11::arg("newState"));

}
