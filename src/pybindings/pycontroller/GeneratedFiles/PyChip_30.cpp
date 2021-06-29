#include <platform/PersistedStorage.h>

#include <functional>
#include <pybind11/pybind11.h>
#include <string>

#ifndef BINDER_PYBIND11_TYPE_CASTER
#define BINDER_PYBIND11_TYPE_CASTER
PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>)
PYBIND11_DECLARE_HOLDER_TYPE(T, T *)
PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

void bind_PyChip_30(std::function<pybind11::module &(std::string const & namespace_)> & M)
{
    // chip::Platform::PersistedStorage::Read(const char *, unsigned int &) file:platform/PersistedStorage.h line:76
    M("chip::Platform::PersistedStorage")
        .def("Read", (int (*)(const char *, unsigned int &)) & chip::Platform::PersistedStorage::Read,
             "Read integer value of a key from persistent storage.\n    Platform is responsible for validating aKey.\n\n  \n      "
             "A key to a persistently-stored value.\n  \n\n    A reference to an integer value.\n\n  \n "
             "CHIP_ERROR_INVALID_ARGUMENT if aKey is NULL\n          CHIP_ERROR_INVALID_STRING_LENGTH if aKey exceeds\n            "
             "      CHIP_CONFIG_PERSISTED_STORAGE_MAX_KEY_LENGTH\n          CHIP_ERROR_PERSISTED_STORAGE_VALUE_NOT_FOUND if aKey "
             "does not exist\n          CHIP_NO_ERROR otherwise\n\nC++: chip::Platform::PersistedStorage::Read(const char *, "
             "unsigned int &) --> int",
             pybind11::arg("aKey"), pybind11::arg("aValue"));

    // chip::Platform::PersistedStorage::Write(const char *, unsigned int) file:platform/PersistedStorage.h line:93
    M("chip::Platform::PersistedStorage")
        .def("Write", (int (*)(const char *, unsigned int)) & chip::Platform::PersistedStorage::Write,
             "Write the integer value of a key to persistent storage.\n    Platform is responsible for validating aKey.\n    If "
             "aKey does not exist, it will be created and assigned aValue.\n    Otherwise any existing value of aKey will be "
             "replaced with aValue.\n\n  \n      A key to a persistently-stored value.\n  \n\n    The value.\n\n  \n "
             "CHIP_ERROR_INVALID_ARGUMENT if aKey is NULL\n          CHIP_ERROR_INVALID_STRING_LENGTH if aKey exceeds\n            "
             "      CHIP_CONFIG_PERSISTED_STORAGE_MAX_KEY_LENGTH\n          CHIP_NO_ERROR otherwise\n\nC++: "
             "chip::Platform::PersistedStorage::Write(const char *, unsigned int) --> int",
             pybind11::arg("aKey"), pybind11::arg("aValue"));
}
