#include <core/CHIPError.h>
#include <sstream> // __str__
#include <support/ErrorStr.h>

#include <pybind11/pybind11.h>
#include <functional>
#include <string>

#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>)
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*)
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

void bind_PyChip_13(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	// chip::RegisterCHIPLayerErrorFormatter() file:core/CHIPError.h line:1800
	M("chip").def("RegisterCHIPLayerErrorFormatter", (void (*)()) &chip::RegisterCHIPLayerErrorFormatter, "C++: chip::RegisterCHIPLayerErrorFormatter() --> void");

	// chip::FormatCHIPError(char *, unsigned short, int) file:core/CHIPError.h line:1801
	M("chip").def("FormatCHIPError", (bool (*)(char *, unsigned short, int)) &chip::FormatCHIPError, "C++: chip::FormatCHIPError(char *, unsigned short, int) --> bool", pybind11::arg("buf"), pybind11::arg("bufSize"), pybind11::arg("err"));

	{ // chip::ErrorFormatter file:support/ErrorStr.h line:34
		pybind11::class_<chip::ErrorFormatter, std::shared_ptr<chip::ErrorFormatter>> cl(M("chip"), "ErrorFormatter", "");
		cl.def( pybind11::init( [](){ return new chip::ErrorFormatter(); } ) );
	}
	// chip::ErrorStr(int) file:support/ErrorStr.h line:42
	M("chip").def("ErrorStr", (const char * (*)(int)) &chip::ErrorStr, "C++: chip::ErrorStr(int) --> const char *", pybind11::return_value_policy::automatic, pybind11::arg("err"));

	// chip::RegisterErrorFormatter(struct chip::ErrorFormatter *) file:support/ErrorStr.h line:43
	M("chip").def("RegisterErrorFormatter", (void (*)(struct chip::ErrorFormatter *)) &chip::RegisterErrorFormatter, "C++: chip::RegisterErrorFormatter(struct chip::ErrorFormatter *) --> void", pybind11::arg("errFormatter"));

	// chip::DeregisterErrorFormatter(struct chip::ErrorFormatter *) file:support/ErrorStr.h line:44
	M("chip").def("DeregisterErrorFormatter", (void (*)(struct chip::ErrorFormatter *)) &chip::DeregisterErrorFormatter, "C++: chip::DeregisterErrorFormatter(struct chip::ErrorFormatter *) --> void", pybind11::arg("errFormatter"));

	// chip::FormatError(char *, unsigned short, const char *, int, const char *) file:support/ErrorStr.h line:45
	M("chip").def("FormatError", (void (*)(char *, unsigned short, const char *, int, const char *)) &chip::FormatError, "C++: chip::FormatError(char *, unsigned short, const char *, int, const char *) --> void", pybind11::arg("buf"), pybind11::arg("bufSize"), pybind11::arg("subsys"), pybind11::arg("err"), pybind11::arg("desc"));

	// chip::StatusReportStr(unsigned int, unsigned short) file:support/ErrorStr.h line:47
	M("chip").def("StatusReportStr", (const char * (*)(unsigned int, unsigned short)) &chip::StatusReportStr, "C++: chip::StatusReportStr(unsigned int, unsigned short) --> const char *", pybind11::return_value_policy::automatic, pybind11::arg("profileId"), pybind11::arg("statusCode"));

}
