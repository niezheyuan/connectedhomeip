#include <sstream> // __str__
#include <system/SystemStats.h>

#include <functional>
#include <pybind11/pybind11.h>
#include <string>

#ifndef BINDER_PYBIND11_TYPE_CASTER
#define BINDER_PYBIND11_TYPE_CASTER
PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>)
PYBIND11_DECLARE_HOLDER_TYPE(T, T *)
PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

void bind_PyChip_3(std::function<pybind11::module &(std::string const & namespace_)> & M)
{
    { // chip::System::Stats::Snapshot file:system/SystemStats.h line:87
        pybind11::class_<chip::System::Stats::Snapshot, std::shared_ptr<chip::System::Stats::Snapshot>> cl(M("chip::System::Stats"),
                                                                                                           "Snapshot", "");
        cl.def(pybind11::init([]() { return new chip::System::Stats::Snapshot(); }));
    }
    // chip::System::Stats::Difference(class chip::System::Stats::Snapshot &, class chip::System::Stats::Snapshot &, class
    // chip::System::Stats::Snapshot &) file:system/SystemStats.h line:94
    M("chip::System::Stats")
        .def("Difference",
             (bool (*)(class chip::System::Stats::Snapshot &, class chip::System::Stats::Snapshot &,
                       class chip::System::Stats::Snapshot &)) &
                 chip::System::Stats::Difference,
             "C++: chip::System::Stats::Difference(class chip::System::Stats::Snapshot &, class chip::System::Stats::Snapshot &, "
             "class chip::System::Stats::Snapshot &) --> bool",
             pybind11::arg("result"), pybind11::arg("after"), pybind11::arg("before"));

    // chip::System::Stats::UpdateSnapshot(class chip::System::Stats::Snapshot &) file:system/SystemStats.h line:95
    M("chip::System::Stats")
        .def("UpdateSnapshot", (void (*)(class chip::System::Stats::Snapshot &)) & chip::System::Stats::UpdateSnapshot,
             "C++: chip::System::Stats::UpdateSnapshot(class chip::System::Stats::Snapshot &) --> void",
             pybind11::arg("aSnapshot"));

    // chip::System::Stats::GetResourcesInUse() file:system/SystemStats.h line:96
    M("chip::System::Stats")
        .def("GetResourcesInUse", (signed char * (*) ()) & chip::System::Stats::GetResourcesInUse,
             "C++: chip::System::Stats::GetResourcesInUse() --> signed char *", pybind11::return_value_policy::automatic);

    // chip::System::Stats::GetHighWatermarks() file:system/SystemStats.h line:97
    M("chip::System::Stats")
        .def("GetHighWatermarks", (signed char * (*) ()) & chip::System::Stats::GetHighWatermarks,
             "C++: chip::System::Stats::GetHighWatermarks() --> signed char *", pybind11::return_value_policy::automatic);
}
