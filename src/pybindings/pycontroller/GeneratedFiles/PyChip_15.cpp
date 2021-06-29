#include <support/logging/CHIPLogging.h>

#include <functional>
#include <pybind11/pybind11.h>
#include <string>

#ifndef BINDER_PYBIND11_TYPE_CASTER
#define BINDER_PYBIND11_TYPE_CASTER
PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>)
PYBIND11_DECLARE_HOLDER_TYPE(T, T *)
PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

void bind_PyChip_15(std::function<pybind11::module &(std::string const & namespace_)> & M)
{
    // chip::Logging::Log(unsigned char, unsigned char, const char *) file:support/logging/CHIPLogging.h line:89
    M("chip::Logging")
        .def(
            "Log",
            [](unsigned char const & a0, unsigned char const & a1, const char * a2) -> void {
                return chip::Logging::Log(a0, a1, a2);
            },
            "", pybind11::arg("module"), pybind11::arg("category"), pybind11::arg("msg"));

    // chip::Logging::GetLogFilter() file:support/logging/CHIPLogging.h line:91
    M("chip::Logging")
        .def("GetLogFilter", (unsigned char (*)()) & chip::Logging::GetLogFilter,
             "C++: chip::Logging::GetLogFilter() --> unsigned char");

    // chip::Logging::SetLogFilter(unsigned char) file:support/logging/CHIPLogging.h line:92
    M("chip::Logging")
        .def("SetLogFilter", (void (*)(unsigned char)) & chip::Logging::SetLogFilter,
             "C++: chip::Logging::SetLogFilter(unsigned char) --> void", pybind11::arg("category"));

    // chip::Logging::GetMessageWithPrefix(char *, unsigned char, unsigned char, const char *) file:support/logging/CHIPLogging.h
    // line:179
    M("chip::Logging")
        .def("GetMessageWithPrefix",
             (void (*)(char *, unsigned char, unsigned char, const char *)) & chip::Logging::GetMessageWithPrefix,
             "C++: chip::Logging::GetMessageWithPrefix(char *, unsigned char, unsigned char, const char *) --> void",
             pybind11::arg("buf"), pybind11::arg("bufSize"), pybind11::arg("module"), pybind11::arg("msg"));

    // chip::Logging::GetModuleName(char *, unsigned char, unsigned char) file:support/logging/CHIPLogging.h line:180
    M("chip::Logging")
        .def("GetModuleName", (void (*)(char *, unsigned char, unsigned char)) & chip::Logging::GetModuleName,
             "C++: chip::Logging::GetModuleName(char *, unsigned char, unsigned char) --> void", pybind11::arg("buf"),
             pybind11::arg("bufSize"), pybind11::arg("module"));

    // chip::Logging::IsCategoryEnabled(unsigned char) file:support/logging/CHIPLogging.h line:196
    M("chip::Logging")
        .def("IsCategoryEnabled", (bool (*)(unsigned char)) & chip::Logging::IsCategoryEnabled,
             "C++: chip::Logging::IsCategoryEnabled(unsigned char) --> bool", pybind11::arg("category"));
}
