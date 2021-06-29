#include <platform/ConfigurationManager.h>

#include <pybind11/pybind11.h>
#include <functional>
#include <string>

#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>)
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*)
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

void bind_PyChip_32(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	// chip::DeviceLayer::ConfigurationMgr() file:platform/ConfigurationManager.h line:202
	M("chip::DeviceLayer").def("ConfigurationMgr", (class chip::DeviceLayer::ConfigurationManager & (*)()) &chip::DeviceLayer::ConfigurationMgr, "Returns a reference to the public interface of the ConfigurationManager singleton object.\n\n chip application should use this to access features of the ConfigurationManager object\n that are common to all platforms.\n\nC++: chip::DeviceLayer::ConfigurationMgr() --> class chip::DeviceLayer::ConfigurationManager &", pybind11::return_value_policy::automatic);

	// chip::DeviceLayer::ConfigurationMgrImpl() file:platform/ConfigurationManager.h line:210
	M("chip::DeviceLayer").def("ConfigurationMgrImpl", (class chip::DeviceLayer::ConfigurationManagerImpl & (*)()) &chip::DeviceLayer::ConfigurationMgrImpl, "Returns the platform-specific implementation of the ConfigurationManager singleton object.\n\n chip applications can use this to gain access to features of the ConfigurationManager\n that are specific to the selected platform.\n\nC++: chip::DeviceLayer::ConfigurationMgrImpl() --> class chip::DeviceLayer::ConfigurationManagerImpl &", pybind11::return_value_policy::automatic);

}
