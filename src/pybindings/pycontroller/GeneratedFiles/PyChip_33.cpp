#include <sstream> // __str__
#include <support/CHIPCounter.h>
#include <support/LifetimePersistedCounter.h>

#include <functional>
#include <pybind11/pybind11.h>
#include <string>

#ifndef BINDER_PYBIND11_TYPE_CASTER
#define BINDER_PYBIND11_TYPE_CASTER
PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>)
PYBIND11_DECLARE_HOLDER_TYPE(T, T *)
PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

// chip::Counter file:support/CHIPCounter.h line:40
struct PyCallBack_chip_Counter : public chip::Counter
{
    using chip::Counter::Counter;

    int Advance() override
    {
        pybind11::gil_scoped_acquire gil;
        pybind11::function overload = pybind11::get_overload(static_cast<const chip::Counter *>(this), "Advance");
        if (overload)
        {
            auto o = overload.operator()<pybind11::return_value_policy::reference>();
            if (pybind11::detail::cast_is_temporary_value_reference<int>::value)
            {
                static pybind11::detail::override_caster_t<int> caster;
                return pybind11::detail::cast_ref<int>(std::move(o), caster);
            }
            else
                return pybind11::detail::cast_safe<int>(std::move(o));
        }
        pybind11::pybind11_fail("Tried to call pure virtual function \"Counter::Advance\"");
    }
    unsigned int GetValue() override
    {
        pybind11::gil_scoped_acquire gil;
        pybind11::function overload = pybind11::get_overload(static_cast<const chip::Counter *>(this), "GetValue");
        if (overload)
        {
            auto o = overload.operator()<pybind11::return_value_policy::reference>();
            if (pybind11::detail::cast_is_temporary_value_reference<unsigned int>::value)
            {
                static pybind11::detail::override_caster_t<unsigned int> caster;
                return pybind11::detail::cast_ref<unsigned int>(std::move(o), caster);
            }
            else
                return pybind11::detail::cast_safe<unsigned int>(std::move(o));
        }
        pybind11::pybind11_fail("Tried to call pure virtual function \"Counter::GetValue\"");
    }
};

// chip::MonotonicallyIncreasingCounter file:support/CHIPCounter.h line:70
struct PyCallBack_chip_MonotonicallyIncreasingCounter : public chip::MonotonicallyIncreasingCounter
{
    using chip::MonotonicallyIncreasingCounter::MonotonicallyIncreasingCounter;

    int Advance() override
    {
        pybind11::gil_scoped_acquire gil;
        pybind11::function overload =
            pybind11::get_overload(static_cast<const chip::MonotonicallyIncreasingCounter *>(this), "Advance");
        if (overload)
        {
            auto o = overload.operator()<pybind11::return_value_policy::reference>();
            if (pybind11::detail::cast_is_temporary_value_reference<int>::value)
            {
                static pybind11::detail::override_caster_t<int> caster;
                return pybind11::detail::cast_ref<int>(std::move(o), caster);
            }
            else
                return pybind11::detail::cast_safe<int>(std::move(o));
        }
        return MonotonicallyIncreasingCounter::Advance();
    }
    unsigned int GetValue() override
    {
        pybind11::gil_scoped_acquire gil;
        pybind11::function overload =
            pybind11::get_overload(static_cast<const chip::MonotonicallyIncreasingCounter *>(this), "GetValue");
        if (overload)
        {
            auto o = overload.operator()<pybind11::return_value_policy::reference>();
            if (pybind11::detail::cast_is_temporary_value_reference<unsigned int>::value)
            {
                static pybind11::detail::override_caster_t<unsigned int> caster;
                return pybind11::detail::cast_ref<unsigned int>(std::move(o), caster);
            }
            else
                return pybind11::detail::cast_safe<unsigned int>(std::move(o));
        }
        return MonotonicallyIncreasingCounter::GetValue();
    }
};

// chip::LifetimePersistedCounter file:support/LifetimePersistedCounter.h line:52
struct PyCallBack_chip_LifetimePersistedCounter : public chip::LifetimePersistedCounter
{
    using chip::LifetimePersistedCounter::LifetimePersistedCounter;

    int Advance() override
    {
        pybind11::gil_scoped_acquire gil;
        pybind11::function overload = pybind11::get_overload(static_cast<const chip::LifetimePersistedCounter *>(this), "Advance");
        if (overload)
        {
            auto o = overload.operator()<pybind11::return_value_policy::reference>();
            if (pybind11::detail::cast_is_temporary_value_reference<int>::value)
            {
                static pybind11::detail::override_caster_t<int> caster;
                return pybind11::detail::cast_ref<int>(std::move(o), caster);
            }
            else
                return pybind11::detail::cast_safe<int>(std::move(o));
        }
        return LifetimePersistedCounter::Advance();
    }
    unsigned int GetValue() override
    {
        pybind11::gil_scoped_acquire gil;
        pybind11::function overload = pybind11::get_overload(static_cast<const chip::LifetimePersistedCounter *>(this), "GetValue");
        if (overload)
        {
            auto o = overload.operator()<pybind11::return_value_policy::reference>();
            if (pybind11::detail::cast_is_temporary_value_reference<unsigned int>::value)
            {
                static pybind11::detail::override_caster_t<unsigned int> caster;
                return pybind11::detail::cast_ref<unsigned int>(std::move(o), caster);
            }
            else
                return pybind11::detail::cast_safe<unsigned int>(std::move(o));
        }
        return MonotonicallyIncreasingCounter::GetValue();
    }
};

void bind_PyChip_33(std::function<pybind11::module &(std::string const & namespace_)> & M)
{
    { // chip::Counter file:support/CHIPCounter.h line:40
        pybind11::class_<chip::Counter, std::shared_ptr<chip::Counter>, PyCallBack_chip_Counter> cl(
            M("chip"), "Counter", "An interface for managing a counter as an integer value.");
        cl.def(pybind11::init([]() { return new PyCallBack_chip_Counter(); }));
        cl.def(pybind11::init<PyCallBack_chip_Counter const &>());
        cl.def("Advance", (int (chip::Counter::*)()) & chip::Counter::Advance,
               "Advance the value of the counter.\n\n  \n A CHIP error code if anything failed, CHIP_NO_ERROR otherwise.\n\nC++: "
               "chip::Counter::Advance() --> int");
        cl.def("GetValue", (unsigned int (chip::Counter::*)()) & chip::Counter::GetValue,
               "Get the current value of the counter.\n\n  \n The current value of the counter.\n\nC++: chip::Counter::GetValue() "
               "--> unsigned int");
        cl.def("assign", (class chip::Counter & (chip::Counter::*) (const class chip::Counter &) ) & chip::Counter::operator=,
               "C++: chip::Counter::operator=(const class chip::Counter &) --> class chip::Counter &",
               pybind11::return_value_policy::automatic, pybind11::arg(""));
    }
    { // chip::MonotonicallyIncreasingCounter file:support/CHIPCounter.h line:70
        pybind11::class_<chip::MonotonicallyIncreasingCounter, std::shared_ptr<chip::MonotonicallyIncreasingCounter>,
                         PyCallBack_chip_MonotonicallyIncreasingCounter, chip::Counter>
            cl(M("chip"), "MonotonicallyIncreasingCounter",
               "A class for managing a monotonically-increasing counter as an integer value.");
        cl.def(pybind11::init([]() { return new chip::MonotonicallyIncreasingCounter(); },
                              []() { return new PyCallBack_chip_MonotonicallyIncreasingCounter(); }));
        cl.def(pybind11::init([](PyCallBack_chip_MonotonicallyIncreasingCounter const & o) {
            return new PyCallBack_chip_MonotonicallyIncreasingCounter(o);
        }));
        cl.def(pybind11::init(
            [](chip::MonotonicallyIncreasingCounter const & o) { return new chip::MonotonicallyIncreasingCounter(o); }));
        cl.def("Init", (int (chip::MonotonicallyIncreasingCounter::*)(unsigned int)) & chip::MonotonicallyIncreasingCounter::Init,
               "Initialize a MonotonicallyIncreasingCounter object.\n\n  \n  The starting value of the counter.\n\n  \n A CHIP "
               "error code if something fails, CHIP_NO_ERROR otherwise\n\nC++: chip::MonotonicallyIncreasingCounter::Init(unsigned "
               "int) --> int",
               pybind11::arg("aStartValue"));
        cl.def("Advance", (int (chip::MonotonicallyIncreasingCounter::*)()) & chip::MonotonicallyIncreasingCounter::Advance,
               "Advance the value of the counter.\n\n  \n A CHIP error code if something fails, CHIP_NO_ERROR otherwise\n\nC++: "
               "chip::MonotonicallyIncreasingCounter::Advance() --> int");
        cl.def("GetValue",
               (unsigned int (chip::MonotonicallyIncreasingCounter::*)()) & chip::MonotonicallyIncreasingCounter::GetValue,
               "Get the current value of the counter.\n\n  \n The current value of the counter.\n\nC++: "
               "chip::MonotonicallyIncreasingCounter::GetValue() --> unsigned int");
        cl.def("assign",
               (class chip::MonotonicallyIncreasingCounter &
                (chip::MonotonicallyIncreasingCounter::*) (const class chip::MonotonicallyIncreasingCounter &) ) &
                   chip::MonotonicallyIncreasingCounter::operator=,
               "C++: chip::MonotonicallyIncreasingCounter::operator=(const class chip::MonotonicallyIncreasingCounter &) --> class "
               "chip::MonotonicallyIncreasingCounter &",
               pybind11::return_value_policy::automatic, pybind11::arg(""));
    }
    { // chip::LifetimePersistedCounter file:support/LifetimePersistedCounter.h line:52
        pybind11::class_<chip::LifetimePersistedCounter, std::shared_ptr<chip::LifetimePersistedCounter>,
                         PyCallBack_chip_LifetimePersistedCounter, chip::MonotonicallyIncreasingCounter>
            cl(M("chip"), "LifetimePersistedCounter",
               "A class for managing a counter as an integer value intended to persist\n   across reboots.\n\n Counter values are "
               "always set to start at a multiple of a bootup value\n \"epoch\".\n\n Example:\n\n - Assuming epoch is 100 via "
               "LifetimePersistedCounter::Init(_, 100) and GetValue +\n   AdvanceValue is called, we get the following "
               "outputs:\n\n   - Output: 0, 1, 2, 3, 4\n\n ");
        cl.def(pybind11::init([]() { return new chip::LifetimePersistedCounter(); },
                              []() { return new PyCallBack_chip_LifetimePersistedCounter(); }));
        cl.def(pybind11::init(
            [](PyCallBack_chip_LifetimePersistedCounter const & o) { return new PyCallBack_chip_LifetimePersistedCounter(o); }));
        cl.def(pybind11::init([](chip::LifetimePersistedCounter const & o) { return new chip::LifetimePersistedCounter(o); }));
        cl.def(
            "Init", (int (chip::LifetimePersistedCounter::*)(const char *)) & chip::LifetimePersistedCounter::Init,
            "Initialize a LifetimePersistedCounter object.\n\n  \n     The identifier of this LifetimePersistedCounter "
            "instance.\n\n  \n CHIP_ERROR_INVALID_ARGUMENT if aId is NULL\n          CHIP_ERROR_INVALID_STRING_LENGTH if aId is "
            "longer than\n          CHIP_CONFIG_PERSISTED_STORAGE_MAX_KEY_LENGTH.\n          CHIP_ERROR_INVALID_INTEGER_VALUE if "
            "aEpoch is 0.\n          CHIP_NO_ERROR otherwise\n\nC++: chip::LifetimePersistedCounter::Init(const char *) --> int",
            pybind11::arg("aId"));
        cl.def("Advance", (int (chip::LifetimePersistedCounter::*)()) & chip::LifetimePersistedCounter::Advance,
               "Increment the counter and write to persisted storage if we've completed\n  the current epoch.\n\n  \n Any error "
               "returned by a write to persisted storage.\n\nC++: chip::LifetimePersistedCounter::Advance() --> int");
        cl.def("assign",
               (class chip::LifetimePersistedCounter &
                (chip::LifetimePersistedCounter::*) (const class chip::LifetimePersistedCounter &) ) &
                   chip::LifetimePersistedCounter::operator=,
               "C++: chip::LifetimePersistedCounter::operator=(const class chip::LifetimePersistedCounter &) --> class "
               "chip::LifetimePersistedCounter &",
               pybind11::return_value_policy::automatic, pybind11::arg(""));
    }
}
