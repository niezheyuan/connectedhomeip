#include <core/CHIPCallback.h>
#include <sstream> // __str__

#include <functional>
#include <pybind11/pybind11.h>
#include <string>

#ifndef BINDER_PYBIND11_TYPE_CASTER
#define BINDER_PYBIND11_TYPE_CASTER
PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>)
PYBIND11_DECLARE_HOLDER_TYPE(T, T *)
PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

void bind_PyChip_0(std::function<pybind11::module &(std::string const & namespace_)> & M)
{
    { // chip::Callback::Cancelable file:core/CHIPCallback.h line:40
        pybind11::class_<chip::Callback::Cancelable, std::shared_ptr<chip::Callback::Cancelable>> cl(
            M("chip::Callback"), "Cancelable",
            "Private members of a Callback for use by subsystems that accept\n     Callbacks for event "
            "registration/notification.\n\n ");
        cl.def(pybind11::init([]() { return new chip::Callback::Cancelable(); }));
        cl.def_readwrite("mInfoScalar", &chip::Callback::Cancelable::mInfoScalar);
        cl.def("Cancel",
               (class chip::Callback::Cancelable * (chip::Callback::Cancelable::*) ()) & chip::Callback::Cancelable::Cancel,
               "run whatever function the callee/registrar has specified in order\n  to clean up any resource allocation "
               "associated with the registration,\n  and surrender ownership of the Cancelable's fields\n\nC++: "
               "chip::Callback::Cancelable::Cancel() --> class chip::Callback::Cancelable *",
               pybind11::return_value_policy::automatic);
        cl.def("assign",
               (class chip::Callback::Cancelable & (chip::Callback::Cancelable::*) (const class chip::Callback::Cancelable &) ) &
                   chip::Callback::Cancelable::operator=,
               "C++: chip::Callback::Cancelable::operator=(const class chip::Callback::Cancelable &) --> class "
               "chip::Callback::Cancelable &",
               pybind11::return_value_policy::automatic, pybind11::arg(""));
    }
    { // chip::Callback::CallbackDeque file:core/CHIPCallback.h line:171
        pybind11::class_<chip::Callback::CallbackDeque, std::shared_ptr<chip::Callback::CallbackDeque>, chip::Callback::Cancelable>
            cl(M("chip::Callback"), "CallbackDeque", "core of a simple doubly-linked list Callback keeper-tracker-of\n\n ");
        cl.def(pybind11::init([]() { return new chip::Callback::CallbackDeque(); }));
        cl.def("Enqueue",
               (void (chip::Callback::CallbackDeque::*)(class chip::Callback::Cancelable *)) &
                   chip::Callback::CallbackDeque::Enqueue,
               "appends\n\nC++: chip::Callback::CallbackDeque::Enqueue(class chip::Callback::Cancelable *) --> void",
               pybind11::arg("ca"));
        cl.def("InsertBefore",
               (void (chip::Callback::CallbackDeque::*)(class chip::Callback::Cancelable *, class chip::Callback::Cancelable *)) &
                   chip::Callback::CallbackDeque::InsertBefore,
               "C++: chip::Callback::CallbackDeque::InsertBefore(class chip::Callback::Cancelable *, class "
               "chip::Callback::Cancelable *) --> void",
               pybind11::arg("ca"), pybind11::arg("where"));
        cl.def("First",
               (class chip::Callback::Cancelable * (chip::Callback::CallbackDeque::*) ()) & chip::Callback::CallbackDeque::First,
               "returns first item unless list is empty, otherwise returns NULL\n\nC++: chip::Callback::CallbackDeque::First() --> "
               "class chip::Callback::Cancelable *",
               pybind11::return_value_policy::automatic);
        cl.def("DequeueAll",
               (void (chip::Callback::CallbackDeque::*)(class chip::Callback::Cancelable &)) &
                   chip::Callback::CallbackDeque::DequeueAll,
               "Dequeue all, return in a stub. does not cancel the cas, as the list\n   members are still in use\n\nC++: "
               "chip::Callback::CallbackDeque::DequeueAll(class chip::Callback::Cancelable &) --> void",
               pybind11::arg("ready"));
        cl.def_static("Dequeue", (void (*)(class chip::Callback::Cancelable *)) & chip::Callback::CallbackDeque::Dequeue,
                      "dequeue but don't cancel, useful if\n     immediately putting on another list\n\nC++: "
                      "chip::Callback::CallbackDeque::Dequeue(class chip::Callback::Cancelable *) --> void",
                      pybind11::arg("ca"));
        cl.def("IsEmpty", (bool (chip::Callback::CallbackDeque::*)()) & chip::Callback::CallbackDeque::IsEmpty,
               "empty?\n\nC++: chip::Callback::CallbackDeque::IsEmpty() --> bool");
        cl.def("assign",
               (class chip::Callback::CallbackDeque &
                (chip::Callback::CallbackDeque::*) (const class chip::Callback::CallbackDeque &) ) &
                   chip::Callback::CallbackDeque::operator=,
               "C++: chip::Callback::CallbackDeque::operator=(const class chip::Callback::CallbackDeque &) --> class "
               "chip::Callback::CallbackDeque &",
               pybind11::return_value_policy::automatic, pybind11::arg(""));
    }
}
