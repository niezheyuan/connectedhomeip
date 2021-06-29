#include <support/BitFlags.h>
#include <sys/_types/_fd_def.h>
#include <system/SystemLayer.h>
#include <system/SystemSockets.h>

#include <functional>
#include <pybind11/pybind11.h>
#include <string>

#ifndef BINDER_PYBIND11_TYPE_CASTER
#define BINDER_PYBIND11_TYPE_CASTER
PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>)
PYBIND11_DECLARE_HOLDER_TYPE(T, T *)
PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

void bind_PyChip_8(std::function<pybind11::module &(std::string const & namespace_)> & M)
{
    // chip::System::Platform::Layer::WillInit(class chip::System::Layer &, void *) file:system/SystemLayer.h line:71
    M("chip::System::Platform::Layer")
        .def("WillInit", (int (*)(class chip::System::Layer &, void *)) & chip::System::Platform::Layer::WillInit,
             "C++: chip::System::Platform::Layer::WillInit(class chip::System::Layer &, void *) --> int", pybind11::arg("aLayer"),
             pybind11::arg("aContext"));

    // chip::System::Platform::Layer::WillShutdown(class chip::System::Layer &, void *) file:system/SystemLayer.h line:72
    M("chip::System::Platform::Layer")
        .def("WillShutdown", (int (*)(class chip::System::Layer &, void *)) & chip::System::Platform::Layer::WillShutdown,
             "C++: chip::System::Platform::Layer::WillShutdown(class chip::System::Layer &, void *) --> int",
             pybind11::arg("aLayer"), pybind11::arg("aContext"));

    // chip::System::Platform::Layer::DidInit(class chip::System::Layer &, void *, int) file:system/SystemLayer.h line:74
    M("chip::System::Platform::Layer")
        .def("DidInit", (void (*)(class chip::System::Layer &, void *, int)) & chip::System::Platform::Layer::DidInit,
             "C++: chip::System::Platform::Layer::DidInit(class chip::System::Layer &, void *, int) --> void",
             pybind11::arg("aLayer"), pybind11::arg("aContext"), pybind11::arg("aStatus"));

    // chip::System::Platform::Layer::DidShutdown(class chip::System::Layer &, void *, int) file:system/SystemLayer.h line:75
    M("chip::System::Platform::Layer")
        .def("DidShutdown", (void (*)(class chip::System::Layer &, void *, int)) & chip::System::Platform::Layer::DidShutdown,
             "C++: chip::System::Platform::Layer::DidShutdown(class chip::System::Layer &, void *, int) --> void",
             pybind11::arg("aLayer"), pybind11::arg("aContext"), pybind11::arg("aStatus"));
}
