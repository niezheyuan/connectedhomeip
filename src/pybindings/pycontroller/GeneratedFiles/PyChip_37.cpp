#include <ble/BleApplicationDelegate.h>
#include <ble/BleConnectionDelegate.h>
#include <ble/BleLayer.h>
#include <ble/BlePlatformDelegate.h>
#include <ble/BleUUID.h>
#include <platform/ConnectivityManager.h>
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

void bind_PyChip_37(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	// chip::DeviceLayer::ConnectivityMgr() file:platform/ConnectivityManager.h line:245
	M("chip::DeviceLayer").def("ConnectivityMgr", (class chip::DeviceLayer::ConnectivityManager & (*)()) &chip::DeviceLayer::ConnectivityMgr, "Returns a reference to the public interface of the ConnectivityManager singleton object.\n\n chip applications should use this to access features of the ConnectivityManager object\n that are common to all platforms.\n\nC++: chip::DeviceLayer::ConnectivityMgr() --> class chip::DeviceLayer::ConnectivityManager &", pybind11::return_value_policy::automatic);

	// chip::DeviceLayer::ConnectivityMgrImpl() file:platform/ConnectivityManager.h line:253
	M("chip::DeviceLayer").def("ConnectivityMgrImpl", (class chip::DeviceLayer::ConnectivityManagerImpl & (*)()) &chip::DeviceLayer::ConnectivityMgrImpl, "Returns the platform-specific implementation of the ConnectivityManager singleton object.\n\n chip applications can use this to gain access to features of the ConnectivityManager\n that are specific to the selected platform.\n\nC++: chip::DeviceLayer::ConnectivityMgrImpl() --> class chip::DeviceLayer::ConnectivityManagerImpl &", pybind11::return_value_policy::automatic);

}
