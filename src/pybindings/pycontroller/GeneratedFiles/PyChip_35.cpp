#include <platform/Darwin/PosixConfig.h>
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

void bind_PyChip_35(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // chip::DeviceLayer::Internal::PosixConfig file:platform/Darwin/PosixConfig.h line:41
		pybind11::class_<chip::DeviceLayer::Internal::PosixConfig, std::shared_ptr<chip::DeviceLayer::Internal::PosixConfig>> cl(M("chip::DeviceLayer::Internal"), "PosixConfig", "Provides functions and definitions for accessing device configuration information on the Posix.\n\n This class is designed to be mixed-in to concrete implementation classes as a means to\n provide access to configuration information to generic base classes.");
		cl.def( pybind11::init( [](){ return new chip::DeviceLayer::Internal::PosixConfig(); } ) );
		cl.def_static("Init", (int (*)()) &chip::DeviceLayer::Internal::PosixConfig::Init, "C++: chip::DeviceLayer::Internal::PosixConfig::Init() --> int");
		cl.def_static("ReadConfigValue", (int (*)(struct chip::DeviceLayer::Internal::PosixConfig::Key, bool &)) &chip::DeviceLayer::Internal::PosixConfig::ReadConfigValue, "C++: chip::DeviceLayer::Internal::PosixConfig::ReadConfigValue(struct chip::DeviceLayer::Internal::PosixConfig::Key, bool &) --> int", pybind11::arg("key"), pybind11::arg("val"));
		cl.def_static("ReadConfigValue", (int (*)(struct chip::DeviceLayer::Internal::PosixConfig::Key, unsigned int &)) &chip::DeviceLayer::Internal::PosixConfig::ReadConfigValue, "C++: chip::DeviceLayer::Internal::PosixConfig::ReadConfigValue(struct chip::DeviceLayer::Internal::PosixConfig::Key, unsigned int &) --> int", pybind11::arg("key"), pybind11::arg("val"));
		cl.def_static("ReadConfigValue", (int (*)(struct chip::DeviceLayer::Internal::PosixConfig::Key, unsigned long long &)) &chip::DeviceLayer::Internal::PosixConfig::ReadConfigValue, "C++: chip::DeviceLayer::Internal::PosixConfig::ReadConfigValue(struct chip::DeviceLayer::Internal::PosixConfig::Key, unsigned long long &) --> int", pybind11::arg("key"), pybind11::arg("val"));
		cl.def_static("ReadConfigValueStr", (int (*)(struct chip::DeviceLayer::Internal::PosixConfig::Key, char *, unsigned long, unsigned long &)) &chip::DeviceLayer::Internal::PosixConfig::ReadConfigValueStr, "C++: chip::DeviceLayer::Internal::PosixConfig::ReadConfigValueStr(struct chip::DeviceLayer::Internal::PosixConfig::Key, char *, unsigned long, unsigned long &) --> int", pybind11::arg("key"), pybind11::arg("buf"), pybind11::arg("bufSize"), pybind11::arg("outLen"));
		cl.def_static("ReadConfigValueBin", (int (*)(struct chip::DeviceLayer::Internal::PosixConfig::Key, unsigned char *, unsigned long, unsigned long &)) &chip::DeviceLayer::Internal::PosixConfig::ReadConfigValueBin, "C++: chip::DeviceLayer::Internal::PosixConfig::ReadConfigValueBin(struct chip::DeviceLayer::Internal::PosixConfig::Key, unsigned char *, unsigned long, unsigned long &) --> int", pybind11::arg("key"), pybind11::arg("buf"), pybind11::arg("bufSize"), pybind11::arg("outLen"));
		cl.def_static("WriteConfigValue", (int (*)(struct chip::DeviceLayer::Internal::PosixConfig::Key, bool)) &chip::DeviceLayer::Internal::PosixConfig::WriteConfigValue, "C++: chip::DeviceLayer::Internal::PosixConfig::WriteConfigValue(struct chip::DeviceLayer::Internal::PosixConfig::Key, bool) --> int", pybind11::arg("key"), pybind11::arg("val"));
		cl.def_static("WriteConfigValue", (int (*)(struct chip::DeviceLayer::Internal::PosixConfig::Key, unsigned int)) &chip::DeviceLayer::Internal::PosixConfig::WriteConfigValue, "C++: chip::DeviceLayer::Internal::PosixConfig::WriteConfigValue(struct chip::DeviceLayer::Internal::PosixConfig::Key, unsigned int) --> int", pybind11::arg("key"), pybind11::arg("val"));
		cl.def_static("WriteConfigValue", (int (*)(struct chip::DeviceLayer::Internal::PosixConfig::Key, unsigned long long)) &chip::DeviceLayer::Internal::PosixConfig::WriteConfigValue, "C++: chip::DeviceLayer::Internal::PosixConfig::WriteConfigValue(struct chip::DeviceLayer::Internal::PosixConfig::Key, unsigned long long) --> int", pybind11::arg("key"), pybind11::arg("val"));
		cl.def_static("WriteConfigValueStr", (int (*)(struct chip::DeviceLayer::Internal::PosixConfig::Key, const char *)) &chip::DeviceLayer::Internal::PosixConfig::WriteConfigValueStr, "C++: chip::DeviceLayer::Internal::PosixConfig::WriteConfigValueStr(struct chip::DeviceLayer::Internal::PosixConfig::Key, const char *) --> int", pybind11::arg("key"), pybind11::arg("str"));
		cl.def_static("WriteConfigValueStr", (int (*)(struct chip::DeviceLayer::Internal::PosixConfig::Key, const char *, unsigned long)) &chip::DeviceLayer::Internal::PosixConfig::WriteConfigValueStr, "C++: chip::DeviceLayer::Internal::PosixConfig::WriteConfigValueStr(struct chip::DeviceLayer::Internal::PosixConfig::Key, const char *, unsigned long) --> int", pybind11::arg("key"), pybind11::arg("str"), pybind11::arg("strLen"));
		cl.def_static("WriteConfigValueBin", (int (*)(struct chip::DeviceLayer::Internal::PosixConfig::Key, const unsigned char *, unsigned long)) &chip::DeviceLayer::Internal::PosixConfig::WriteConfigValueBin, "C++: chip::DeviceLayer::Internal::PosixConfig::WriteConfigValueBin(struct chip::DeviceLayer::Internal::PosixConfig::Key, const unsigned char *, unsigned long) --> int", pybind11::arg("key"), pybind11::arg("data"), pybind11::arg("dataLen"));
		cl.def_static("ClearConfigValue", (int (*)(struct chip::DeviceLayer::Internal::PosixConfig::Key)) &chip::DeviceLayer::Internal::PosixConfig::ClearConfigValue, "C++: chip::DeviceLayer::Internal::PosixConfig::ClearConfigValue(struct chip::DeviceLayer::Internal::PosixConfig::Key) --> int", pybind11::arg("key"));
		cl.def_static("ConfigValueExists", (bool (*)(struct chip::DeviceLayer::Internal::PosixConfig::Key)) &chip::DeviceLayer::Internal::PosixConfig::ConfigValueExists, "C++: chip::DeviceLayer::Internal::PosixConfig::ConfigValueExists(struct chip::DeviceLayer::Internal::PosixConfig::Key) --> bool", pybind11::arg("key"));
		cl.def_static("FactoryResetConfig", (int (*)()) &chip::DeviceLayer::Internal::PosixConfig::FactoryResetConfig, "C++: chip::DeviceLayer::Internal::PosixConfig::FactoryResetConfig() --> int");
		cl.def_static("RunConfigUnitTest", (void (*)()) &chip::DeviceLayer::Internal::PosixConfig::RunConfigUnitTest, "C++: chip::DeviceLayer::Internal::PosixConfig::RunConfigUnitTest() --> void");

		{ // chip::DeviceLayer::Internal::PosixConfig::Key file:platform/Darwin/PosixConfig.h line:109
			auto & enclosing_class = cl;
			pybind11::class_<chip::DeviceLayer::Internal::PosixConfig::Key, std::shared_ptr<chip::DeviceLayer::Internal::PosixConfig::Key>> cl(enclosing_class, "Key", "");
			cl.def( pybind11::init( [](){ return new chip::DeviceLayer::Internal::PosixConfig::Key(); } ) );
			cl.def("__eq__", (bool (chip::DeviceLayer::Internal::PosixConfig::Key::*)(const struct chip::DeviceLayer::Internal::PosixConfig::Key &) const) &chip::DeviceLayer::Internal::PosixConfig::Key::operator==, "C++: chip::DeviceLayer::Internal::PosixConfig::Key::operator==(const struct chip::DeviceLayer::Internal::PosixConfig::Key &) const --> bool", pybind11::arg("other"));
		}

	}
}
