#include <system/SystemClock.h>

#include <functional>
#include <pybind11/pybind11.h>
#include <string>

#ifndef BINDER_PYBIND11_TYPE_CASTER
#define BINDER_PYBIND11_TYPE_CASTER
PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>)
PYBIND11_DECLARE_HOLDER_TYPE(T, T *)
PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

void bind_PyChip_49(std::function<pybind11::module &(std::string const & namespace_)> & M)
{
    // chip::System::Platform::Layer::GetClock_Monotonic() file:system/SystemClock.h line:71
    M("chip::System::Platform::Layer")
        .def("GetClock_Monotonic", (unsigned long long (*)()) & chip::System::Platform::Layer::GetClock_Monotonic,
             "Platform-specific function for getting monotonic system time in microseconds.\n\n This function is expected to "
             "return elapsed time in microseconds since an arbitrary, platform-defined\n epoch.  Platform implementations are "
             "obligated to return a value that is ever-increasing (i.e. never\n wraps) between reboots of the system.  "
             "Additionally, the underlying time source is required to tick\n continuously during any system sleep modes that do "
             "not entail a restart upon wake.\n\n The epoch for time returned by this function is *not* required to be the same "
             "that for any of the\n other GetClock... functions, including GetClock_MonotonicMS().\n\n This function is expected "
             "to be thread-safe on any platform that employs threading.\n\n \n\n   This function is reserved for internal use by "
             "the CHIP System Layer.  Users of the CHIP System\n   Layer should call System::Layer::GetClock_Monotonic().\n\n \n   "
             "          Elapsed time in microseconds since an arbitrary, platform-defined epoch.\n\nC++: "
             "chip::System::Platform::Layer::GetClock_Monotonic() --> unsigned long long");

    // chip::System::Platform::Layer::GetClock_MonotonicMS() file:system/SystemClock.h line:93
    M("chip::System::Platform::Layer")
        .def("GetClock_MonotonicMS", (unsigned long long (*)()) & chip::System::Platform::Layer::GetClock_MonotonicMS,
             "Platform-specific function for getting monotonic system time in milliseconds.\n\n This function is expected to "
             "return elapsed time in milliseconds since an arbitrary, platform-defined\n epoch.  Platform implementations are "
             "obligated to return a value that is ever-increasing (i.e. never\n wraps) between reboots of the system.  "
             "Additionally, the underlying time source is required to tick\n continuously during any system sleep modes that do "
             "not entail a restart upon wake.\n\n The epoch for time returned by this function is *not* required to be the same as "
             "that for any of the\n other GetClock... functions, including GetClock_Monotonic().\n\n This function is expected to "
             "be thread-safe on any platform that employs threading.\n\n \n\n   This function is reserved for internal use by the "
             "CHIP System Layer.  Users of the CHIP System\n   Layer should call System::Layer::GetClock_MonotonicMS().\n\n \n     "
             "        Elapsed time in milliseconds since an arbitrary, platform-defined epoch.\n\nC++: "
             "chip::System::Platform::Layer::GetClock_MonotonicMS() --> unsigned long long");

    // chip::System::Platform::Layer::GetClock_MonotonicHiRes() file:system/SystemClock.h line:119
    M("chip::System::Platform::Layer")
        .def("GetClock_MonotonicHiRes", (unsigned long long (*)()) & chip::System::Platform::Layer::GetClock_MonotonicHiRes,
             "Platform-specific function for getting high-resolution monotonic system time in microseconds.\n\n This function is "
             "expected to return elapsed time in microseconds since an arbitrary, platform-defined\n epoch.  Values returned by "
             "GetClock_MonotonicHiRes() are required to be ever-increasing (i.e. never\n wrap).  However, the underlying timer is "
             "*not* required to tick continuously during system\n deep-sleep states.\n\n Platform are encouraged to implement "
             "GetClock_MonotonicHiRes() using a high-resolution timer\n that is not subject to gradual clock adjustments "
             "(slewing).  On platforms without such a timer,\n GetClock_MonotonicHiRes() can return the same value as "
             "GetClock_Monotonic().\n\n The epoch for time returned by this function is not required to be the same that for any "
             "of the\n other GetClock... functions.\n\n This function is expected to be thread-safe on any platform that employs "
             "threading.\n\n \n\n   This function is reserved for internal use by the CHIP System Layer.  Users of the CHIP "
             "System\n   Layer should call System::Layer::GetClock_MonotonicHiRes().\n\n \n             Elapsed time in "
             "microseconds since an arbitrary, platform-defined epoch.\n\nC++: "
             "chip::System::Platform::Layer::GetClock_MonotonicHiRes() --> unsigned long long");

    // chip::System::Platform::Layer::GetClock_RealTime(unsigned long long &) file:system/SystemClock.h line:153
    M("chip::System::Platform::Layer")
        .def("GetClock_RealTime", (int (*)(unsigned long long &)) & chip::System::Platform::Layer::GetClock_RealTime,
             "Platform-specific function for getting the current real (civil) time in microsecond Unix time\n   format.\n\n This "
             "function is expected to return the local platform's notion of current real time, expressed\n as a Unix time value "
             "scaled to microseconds.  The underlying clock is required to tick at a\n rate of least at whole seconds (values of "
             "1,000,000), but may tick faster.\n\n On those platforms that are capable of tracking real time, GetClock_RealTime() "
             "must return the\n error CHIP_SYSTEM_ERROR_REAL_TIME_NOT_SYNCED whenever the system is unsynchronized with real "
             "time.\n\n Platforms that are incapable of tracking real time should not implement the GetClock_RealTime()\n "
             "function, thereby forcing link-time failures of features that depend on access to real time.\n Alternatively, such "
             "platforms may supply an implementation of GetClock_RealTime() that returns\n the error "
             "CHIP_SYSTEM_ERROR_NOT_SUPPORTED.\n\n This function is expected to be thread-safe on any platform that employs "
             "threading.\n\n \n\n   This function is reserved for internal use by the CHIP System Layer.  Users of the CHIP "
             "System\n   Layer should call System::Layer::GetClock_RealTime().\n\n \n                  The current time, expressed "
             "as Unix time scaled to microseconds.\n\n  #CHIP_SYSTEM_NO_ERROR       If the method succeeded.\n  "
             "#CHIP_SYSTEM_ERROR_REAL_TIME_NOT_SYNCED\n                                      If the platform is capable of "
             "tracking real time, but is\n                                      is currently unsynchronized.\n  "
             "#CHIP_SYSTEM_ERROR_NOT_SUPPORTED\n                                      If the platform is incapable of tracking "
             "real time.\n\nC++: chip::System::Platform::Layer::GetClock_RealTime(unsigned long long &) --> int",
             pybind11::arg("curTime"));

    // chip::System::Platform::Layer::GetClock_RealTimeMS(unsigned long long &) file:system/SystemClock.h line:178
    M("chip::System::Platform::Layer")
        .def("GetClock_RealTimeMS", (int (*)(unsigned long long &)) & chip::System::Platform::Layer::GetClock_RealTimeMS,
             "Platform-specific function for getting the current real (civil) time in millisecond Unix time\n   format.\n\n This "
             "function is expected to return the local platform's notion of current real time, expressed\n as a Unix time value "
             "scaled to milliseconds.\n\n See the documentation for GetClock_RealTime() for details on the expected behavior.\n\n "
             "\n\n   This function is reserved for internal use by the CHIP System Layer.  Users of the CHIP System\n   Layer "
             "should call System::Layer::GetClock_RealTimeMS().\n\n \n               The current time, expressed as Unix time "
             "scaled to milliseconds.\n\n  #CHIP_SYSTEM_NO_ERROR       If the method succeeded.\n  "
             "#CHIP_SYSTEM_ERROR_REAL_TIME_NOT_SYNCED\n                                      If the platform is capable of "
             "tracking real time, but is\n                                      is currently unsynchronized.\n  "
             "#CHIP_SYSTEM_ERROR_NOT_SUPPORTED\n                                      If the platform is incapable of tracking "
             "real time.\n\nC++: chip::System::Platform::Layer::GetClock_RealTimeMS(unsigned long long &) --> int",
             pybind11::arg("curTimeMS"));

    // chip::System::Platform::Layer::SetClock_RealTime(unsigned long long) file:system/SystemClock.h line:214
    M("chip::System::Platform::Layer")
        .def("SetClock_RealTime", (int (*)(unsigned long long)) & chip::System::Platform::Layer::SetClock_RealTime,
             "Platform-specific function for setting the current real (civil) time.\n\n CHIP calls this function to set the local "
             "platform's notion of current real time.  The new current\n time is expressed as a Unix time value scaled to "
             "microseconds.\n\n Once set, underlying platform clock is expected to track real time with a granularity of at least "
             "whole\n seconds.\n\n On platforms that support tracking real time, the SetClock_RealTime() function must return the "
             "error\n CHIP_SYSTEM_ERROR_ACCESS_DENIED if the calling application does not have the privilege to set the\n current "
             "time.\n\n Platforms that are incapable of tracking real time, or do not offer the ability to set real time,\n should "
             "not implement the SetClock_RealTime() function, thereby forcing link-time failures of features\n that depend on "
             "setting real time.  Alternatively, such platforms may supply an implementation of\n SetClock_RealTime() that returns "
             "the error CHIP_SYSTEM_ERROR_NOT_SUPPORTED.\n\n This function is expected to be thread-safe on any platform that "
             "employs threading.\n\n \n\n   This function is reserved for internal use by the CHIP System Layer.  Users of the "
             "CHIP System\n   Layer should call System::Layer::GetClock_RealTimeMS().\n\n \n                The new current time, "
             "expressed as Unix time scaled to microseconds.\n\n  #CHIP_SYSTEM_NO_ERROR       If the method succeeded.\n  "
             "#CHIP_SYSTEM_ERROR_NOT_SUPPORTED\n                                      If the platform is incapable of tracking "
             "real time.\n  #CHIP_SYSTEM_ERROR_ACCESS_DENIED\n                                      If the calling application "
             "does not have the privilege to set the\n                                      current time.\n\nC++: "
             "chip::System::Platform::Layer::SetClock_RealTime(unsigned long long) --> int",
             pybind11::arg("newCurTime"));
}
