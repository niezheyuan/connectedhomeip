#include <system/SystemError.h>

#include <pybind11/pybind11.h>
#include <functional>
#include <string>

#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>)
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*)
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

void bind_PyChip_1(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	// chip::System::RegisterLayerErrorFormatter() file:system/SystemError.h line:176
	M("chip::System").def("RegisterLayerErrorFormatter", (void (*)()) &chip::System::RegisterLayerErrorFormatter, "C++: chip::System::RegisterLayerErrorFormatter() --> void");

	// chip::System::FormatLayerError(char *, unsigned short, int) file:system/SystemError.h line:177
	M("chip::System").def("FormatLayerError", (bool (*)(char *, unsigned short, int)) &chip::System::FormatLayerError, "C++: chip::System::FormatLayerError(char *, unsigned short, int) --> bool", pybind11::arg("buf"), pybind11::arg("bufSize"), pybind11::arg("err"));

	// chip::System::MapErrorPOSIX(int) file:system/SystemError.h line:179
	M("chip::System").def("MapErrorPOSIX", (int (*)(int)) &chip::System::MapErrorPOSIX, "C++: chip::System::MapErrorPOSIX(int) --> int", pybind11::arg("code"));

	// chip::System::DescribeErrorPOSIX(int) file:system/SystemError.h line:180
	M("chip::System").def("DescribeErrorPOSIX", (const char * (*)(int)) &chip::System::DescribeErrorPOSIX, "C++: chip::System::DescribeErrorPOSIX(int) --> const char *", pybind11::return_value_policy::automatic, pybind11::arg("code"));

	// chip::System::IsErrorPOSIX(int) file:system/SystemError.h line:181
	M("chip::System").def("IsErrorPOSIX", (bool (*)(int)) &chip::System::IsErrorPOSIX, "C++: chip::System::IsErrorPOSIX(int) --> bool", pybind11::arg("code"));

	// chip::System::RegisterPOSIXErrorFormatter() file:system/SystemError.h line:182
	M("chip::System").def("RegisterPOSIXErrorFormatter", (void (*)()) &chip::System::RegisterPOSIXErrorFormatter, "C++: chip::System::RegisterPOSIXErrorFormatter() --> void");

	// chip::System::FormatPOSIXError(char *, unsigned short, int) file:system/SystemError.h line:183
	M("chip::System").def("FormatPOSIXError", (bool (*)(char *, unsigned short, int)) &chip::System::FormatPOSIXError, "C++: chip::System::FormatPOSIXError(char *, unsigned short, int) --> bool", pybind11::arg("buf"), pybind11::arg("bufSize"), pybind11::arg("err"));

	// chip::System::MapErrorZephyr(int) file:system/SystemError.h line:184
	M("chip::System").def("MapErrorZephyr", (int (*)(int)) &chip::System::MapErrorZephyr, "C++: chip::System::MapErrorZephyr(int) --> int", pybind11::arg("code"));

}
