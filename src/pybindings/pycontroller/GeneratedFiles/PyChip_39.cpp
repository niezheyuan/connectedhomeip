#include <platform/ConnectivityManager.h>
#include <platform/internal/GenericConnectivityManagerImpl_NoThread.h>
#include <platform/internal/GenericConnectivityManagerImpl_NoWiFi.h>
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

void bind_PyChip_39(std::function<pybind11::module &(std::string const & namespace_)> & M)
{
    { // chip::DeviceLayer::Internal::GenericConnectivityManagerImpl_NoThread
      // file:platform/internal/GenericConnectivityManagerImpl_NoThread.h line:40
        pybind11::class_<
            chip::DeviceLayer::Internal::GenericConnectivityManagerImpl_NoThread<chip::DeviceLayer::ConnectivityManagerImpl>,
            std::shared_ptr<
                chip::DeviceLayer::Internal::GenericConnectivityManagerImpl_NoThread<chip::DeviceLayer::ConnectivityManagerImpl>>>
            cl(M("chip::DeviceLayer::Internal"),
               "GenericConnectivityManagerImpl_NoThread_chip_DeviceLayer_ConnectivityManagerImpl_t", "");
        cl.def(pybind11::init([]() {
            return new chip::DeviceLayer::Internal::GenericConnectivityManagerImpl_NoThread<
                chip::DeviceLayer::ConnectivityManagerImpl>();
        }));
        cl.def(pybind11::init([](chip::DeviceLayer::Internal::GenericConnectivityManagerImpl_NoThread<
                                  chip::DeviceLayer::ConnectivityManagerImpl> const & o) {
            return new chip::DeviceLayer::Internal::GenericConnectivityManagerImpl_NoThread<
                chip::DeviceLayer::ConnectivityManagerImpl>(o);
        }));
        cl.def(
            "assign",
            (class chip::DeviceLayer::Internal::GenericConnectivityManagerImpl_NoThread<
                 class chip::DeviceLayer::ConnectivityManagerImpl> &
             (chip::DeviceLayer::Internal::GenericConnectivityManagerImpl_NoThread<
                 chip::DeviceLayer::ConnectivityManagerImpl>::*) (const class chip::DeviceLayer::Internal::
                                                                      GenericConnectivityManagerImpl_NoThread<
                                                                          class chip::DeviceLayer::ConnectivityManagerImpl> &) ) &
                chip::DeviceLayer::Internal::GenericConnectivityManagerImpl_NoThread<
                    chip::DeviceLayer::ConnectivityManagerImpl>::operator=,
            "C++: "
            "chip::DeviceLayer::Internal::GenericConnectivityManagerImpl_NoThread<chip::DeviceLayer::ConnectivityManagerImpl>::"
            "operator=(const class chip::DeviceLayer::Internal::GenericConnectivityManagerImpl_NoThread<class "
            "chip::DeviceLayer::ConnectivityManagerImpl> &) --> class "
            "chip::DeviceLayer::Internal::GenericConnectivityManagerImpl_NoThread<class "
            "chip::DeviceLayer::ConnectivityManagerImpl> &",
            pybind11::return_value_policy::automatic, pybind11::arg(""));
    }
    { // chip::DeviceLayer::Internal::GenericConnectivityManagerImpl_NoWiFi
      // file:platform/internal/GenericConnectivityManagerImpl_NoWiFi.h line:50
        pybind11::class_<
            chip::DeviceLayer::Internal::GenericConnectivityManagerImpl_NoWiFi<chip::DeviceLayer::ConnectivityManagerImpl>,
            std::shared_ptr<
                chip::DeviceLayer::Internal::GenericConnectivityManagerImpl_NoWiFi<chip::DeviceLayer::ConnectivityManagerImpl>>>
            cl(M("chip::DeviceLayer::Internal"), "GenericConnectivityManagerImpl_NoWiFi_chip_DeviceLayer_ConnectivityManagerImpl_t",
               "");
        cl.def(pybind11::init([]() {
            return new chip::DeviceLayer::Internal::GenericConnectivityManagerImpl_NoWiFi<
                chip::DeviceLayer::ConnectivityManagerImpl>();
        }));
        cl.def(pybind11::init([](chip::DeviceLayer::Internal::GenericConnectivityManagerImpl_NoWiFi<
                                  chip::DeviceLayer::ConnectivityManagerImpl> const & o) {
            return new chip::DeviceLayer::Internal::GenericConnectivityManagerImpl_NoWiFi<
                chip::DeviceLayer::ConnectivityManagerImpl>(o);
        }));
        cl.def("_GetWiFiStationMode",
               (enum chip::DeviceLayer::ConnectivityManager::WiFiStationMode(
                   chip::DeviceLayer::Internal::GenericConnectivityManagerImpl_NoWiFi<
                       chip::DeviceLayer::ConnectivityManagerImpl>::*)()) &
                   chip::DeviceLayer::Internal::GenericConnectivityManagerImpl_NoWiFi<
                       chip::DeviceLayer::ConnectivityManagerImpl>::_GetWiFiStationMode,
               "C++: "
               "chip::DeviceLayer::Internal::GenericConnectivityManagerImpl_NoWiFi<chip::DeviceLayer::ConnectivityManagerImpl>::_"
               "GetWiFiStationMode() --> enum chip::DeviceLayer::ConnectivityManager::WiFiStationMode");
        cl.def(
            "_SetWiFiStationMode",
            (int (
                chip::DeviceLayer::Internal::GenericConnectivityManagerImpl_NoWiFi<chip::DeviceLayer::ConnectivityManagerImpl>::*)(
                enum chip::DeviceLayer::ConnectivityManager::WiFiStationMode)) &
                chip::DeviceLayer::Internal::GenericConnectivityManagerImpl_NoWiFi<
                    chip::DeviceLayer::ConnectivityManagerImpl>::_SetWiFiStationMode,
            "C++: "
            "chip::DeviceLayer::Internal::GenericConnectivityManagerImpl_NoWiFi<chip::DeviceLayer::ConnectivityManagerImpl>::_"
            "SetWiFiStationMode(enum chip::DeviceLayer::ConnectivityManager::WiFiStationMode) --> int",
            pybind11::arg("val"));
        cl.def("_IsWiFiStationEnabled",
               (bool (chip::DeviceLayer::Internal::GenericConnectivityManagerImpl_NoWiFi<
                      chip::DeviceLayer::ConnectivityManagerImpl>::*)()) &
                   chip::DeviceLayer::Internal::GenericConnectivityManagerImpl_NoWiFi<
                       chip::DeviceLayer::ConnectivityManagerImpl>::_IsWiFiStationEnabled,
               "C++: "
               "chip::DeviceLayer::Internal::GenericConnectivityManagerImpl_NoWiFi<chip::DeviceLayer::ConnectivityManagerImpl>::_"
               "IsWiFiStationEnabled() --> bool");
        cl.def("_IsWiFiStationApplicationControlled",
               (bool (chip::DeviceLayer::Internal::GenericConnectivityManagerImpl_NoWiFi<
                      chip::DeviceLayer::ConnectivityManagerImpl>::*)()) &
                   chip::DeviceLayer::Internal::GenericConnectivityManagerImpl_NoWiFi<
                       chip::DeviceLayer::ConnectivityManagerImpl>::_IsWiFiStationApplicationControlled,
               "C++: "
               "chip::DeviceLayer::Internal::GenericConnectivityManagerImpl_NoWiFi<chip::DeviceLayer::ConnectivityManagerImpl>::_"
               "IsWiFiStationApplicationControlled() --> bool");
        cl.def("_IsWiFiStationConnected",
               (bool (chip::DeviceLayer::Internal::GenericConnectivityManagerImpl_NoWiFi<
                      chip::DeviceLayer::ConnectivityManagerImpl>::*)()) &
                   chip::DeviceLayer::Internal::GenericConnectivityManagerImpl_NoWiFi<
                       chip::DeviceLayer::ConnectivityManagerImpl>::_IsWiFiStationConnected,
               "C++: "
               "chip::DeviceLayer::Internal::GenericConnectivityManagerImpl_NoWiFi<chip::DeviceLayer::ConnectivityManagerImpl>::_"
               "IsWiFiStationConnected() --> bool");
        cl.def("_HaveIPv4InternetConnectivity",
               (bool (chip::DeviceLayer::Internal::GenericConnectivityManagerImpl_NoWiFi<
                      chip::DeviceLayer::ConnectivityManagerImpl>::*)()) &
                   chip::DeviceLayer::Internal::GenericConnectivityManagerImpl_NoWiFi<
                       chip::DeviceLayer::ConnectivityManagerImpl>::_HaveIPv4InternetConnectivity,
               "C++: "
               "chip::DeviceLayer::Internal::GenericConnectivityManagerImpl_NoWiFi<chip::DeviceLayer::ConnectivityManagerImpl>::_"
               "HaveIPv4InternetConnectivity() --> bool");
        cl.def("_HaveIPv6InternetConnectivity",
               (bool (chip::DeviceLayer::Internal::GenericConnectivityManagerImpl_NoWiFi<
                      chip::DeviceLayer::ConnectivityManagerImpl>::*)()) &
                   chip::DeviceLayer::Internal::GenericConnectivityManagerImpl_NoWiFi<
                       chip::DeviceLayer::ConnectivityManagerImpl>::_HaveIPv6InternetConnectivity,
               "C++: "
               "chip::DeviceLayer::Internal::GenericConnectivityManagerImpl_NoWiFi<chip::DeviceLayer::ConnectivityManagerImpl>::_"
               "HaveIPv6InternetConnectivity() --> bool");
        cl.def("_GetWiFiStationReconnectIntervalMS",
               (unsigned int (chip::DeviceLayer::Internal::GenericConnectivityManagerImpl_NoWiFi<
                              chip::DeviceLayer::ConnectivityManagerImpl>::*)()) &
                   chip::DeviceLayer::Internal::GenericConnectivityManagerImpl_NoWiFi<
                       chip::DeviceLayer::ConnectivityManagerImpl>::_GetWiFiStationReconnectIntervalMS,
               "C++: "
               "chip::DeviceLayer::Internal::GenericConnectivityManagerImpl_NoWiFi<chip::DeviceLayer::ConnectivityManagerImpl>::_"
               "GetWiFiStationReconnectIntervalMS() --> unsigned int");
        cl.def(
            "_SetWiFiStationReconnectIntervalMS",
            (int (
                chip::DeviceLayer::Internal::GenericConnectivityManagerImpl_NoWiFi<chip::DeviceLayer::ConnectivityManagerImpl>::*)(
                unsigned int)) &
                chip::DeviceLayer::Internal::GenericConnectivityManagerImpl_NoWiFi<
                    chip::DeviceLayer::ConnectivityManagerImpl>::_SetWiFiStationReconnectIntervalMS,
            "C++: "
            "chip::DeviceLayer::Internal::GenericConnectivityManagerImpl_NoWiFi<chip::DeviceLayer::ConnectivityManagerImpl>::_"
            "SetWiFiStationReconnectIntervalMS(unsigned int) --> int",
            pybind11::arg("val"));
        cl.def("_IsWiFiStationProvisioned",
               (bool (chip::DeviceLayer::Internal::GenericConnectivityManagerImpl_NoWiFi<
                      chip::DeviceLayer::ConnectivityManagerImpl>::*)()) &
                   chip::DeviceLayer::Internal::GenericConnectivityManagerImpl_NoWiFi<
                       chip::DeviceLayer::ConnectivityManagerImpl>::_IsWiFiStationProvisioned,
               "C++: "
               "chip::DeviceLayer::Internal::GenericConnectivityManagerImpl_NoWiFi<chip::DeviceLayer::ConnectivityManagerImpl>::_"
               "IsWiFiStationProvisioned() --> bool");
        cl.def("_ClearWiFiStationProvision",
               (void (chip::DeviceLayer::Internal::GenericConnectivityManagerImpl_NoWiFi<
                      chip::DeviceLayer::ConnectivityManagerImpl>::*)()) &
                   chip::DeviceLayer::Internal::GenericConnectivityManagerImpl_NoWiFi<
                       chip::DeviceLayer::ConnectivityManagerImpl>::_ClearWiFiStationProvision,
               "C++: "
               "chip::DeviceLayer::Internal::GenericConnectivityManagerImpl_NoWiFi<chip::DeviceLayer::ConnectivityManagerImpl>::_"
               "ClearWiFiStationProvision() --> void");
        cl.def("_GetWiFiAPMode",
               (enum chip::DeviceLayer::ConnectivityManager::WiFiAPMode(
                   chip::DeviceLayer::Internal::GenericConnectivityManagerImpl_NoWiFi<
                       chip::DeviceLayer::ConnectivityManagerImpl>::*)()) &
                   chip::DeviceLayer::Internal::GenericConnectivityManagerImpl_NoWiFi<
                       chip::DeviceLayer::ConnectivityManagerImpl>::_GetWiFiAPMode,
               "C++: "
               "chip::DeviceLayer::Internal::GenericConnectivityManagerImpl_NoWiFi<chip::DeviceLayer::ConnectivityManagerImpl>::_"
               "GetWiFiAPMode() --> enum chip::DeviceLayer::ConnectivityManager::WiFiAPMode");
        cl.def(
            "_SetWiFiAPMode",
            (int (
                chip::DeviceLayer::Internal::GenericConnectivityManagerImpl_NoWiFi<chip::DeviceLayer::ConnectivityManagerImpl>::*)(
                enum chip::DeviceLayer::ConnectivityManager::WiFiAPMode)) &
                chip::DeviceLayer::Internal::GenericConnectivityManagerImpl_NoWiFi<
                    chip::DeviceLayer::ConnectivityManagerImpl>::_SetWiFiAPMode,
            "C++: "
            "chip::DeviceLayer::Internal::GenericConnectivityManagerImpl_NoWiFi<chip::DeviceLayer::ConnectivityManagerImpl>::_"
            "SetWiFiAPMode(enum chip::DeviceLayer::ConnectivityManager::WiFiAPMode) --> int",
            pybind11::arg("val"));
        cl.def("_IsWiFiAPActive",
               (bool (chip::DeviceLayer::Internal::GenericConnectivityManagerImpl_NoWiFi<
                      chip::DeviceLayer::ConnectivityManagerImpl>::*)()) &
                   chip::DeviceLayer::Internal::GenericConnectivityManagerImpl_NoWiFi<
                       chip::DeviceLayer::ConnectivityManagerImpl>::_IsWiFiAPActive,
               "C++: "
               "chip::DeviceLayer::Internal::GenericConnectivityManagerImpl_NoWiFi<chip::DeviceLayer::ConnectivityManagerImpl>::_"
               "IsWiFiAPActive() --> bool");
        cl.def("_IsWiFiAPApplicationControlled",
               (bool (chip::DeviceLayer::Internal::GenericConnectivityManagerImpl_NoWiFi<
                      chip::DeviceLayer::ConnectivityManagerImpl>::*)()) &
                   chip::DeviceLayer::Internal::GenericConnectivityManagerImpl_NoWiFi<
                       chip::DeviceLayer::ConnectivityManagerImpl>::_IsWiFiAPApplicationControlled,
               "C++: "
               "chip::DeviceLayer::Internal::GenericConnectivityManagerImpl_NoWiFi<chip::DeviceLayer::ConnectivityManagerImpl>::_"
               "IsWiFiAPApplicationControlled() --> bool");
        cl.def("_DemandStartWiFiAP",
               (void (chip::DeviceLayer::Internal::GenericConnectivityManagerImpl_NoWiFi<
                      chip::DeviceLayer::ConnectivityManagerImpl>::*)()) &
                   chip::DeviceLayer::Internal::GenericConnectivityManagerImpl_NoWiFi<
                       chip::DeviceLayer::ConnectivityManagerImpl>::_DemandStartWiFiAP,
               "C++: "
               "chip::DeviceLayer::Internal::GenericConnectivityManagerImpl_NoWiFi<chip::DeviceLayer::ConnectivityManagerImpl>::_"
               "DemandStartWiFiAP() --> void");
        cl.def("_StopOnDemandWiFiAP",
               (void (chip::DeviceLayer::Internal::GenericConnectivityManagerImpl_NoWiFi<
                      chip::DeviceLayer::ConnectivityManagerImpl>::*)()) &
                   chip::DeviceLayer::Internal::GenericConnectivityManagerImpl_NoWiFi<
                       chip::DeviceLayer::ConnectivityManagerImpl>::_StopOnDemandWiFiAP,
               "C++: "
               "chip::DeviceLayer::Internal::GenericConnectivityManagerImpl_NoWiFi<chip::DeviceLayer::ConnectivityManagerImpl>::_"
               "StopOnDemandWiFiAP() --> void");
        cl.def("_MaintainOnDemandWiFiAP",
               (void (chip::DeviceLayer::Internal::GenericConnectivityManagerImpl_NoWiFi<
                      chip::DeviceLayer::ConnectivityManagerImpl>::*)()) &
                   chip::DeviceLayer::Internal::GenericConnectivityManagerImpl_NoWiFi<
                       chip::DeviceLayer::ConnectivityManagerImpl>::_MaintainOnDemandWiFiAP,
               "C++: "
               "chip::DeviceLayer::Internal::GenericConnectivityManagerImpl_NoWiFi<chip::DeviceLayer::ConnectivityManagerImpl>::_"
               "MaintainOnDemandWiFiAP() --> void");
        cl.def("_GetWiFiAPIdleTimeoutMS",
               (unsigned int (chip::DeviceLayer::Internal::GenericConnectivityManagerImpl_NoWiFi<
                              chip::DeviceLayer::ConnectivityManagerImpl>::*)()) &
                   chip::DeviceLayer::Internal::GenericConnectivityManagerImpl_NoWiFi<
                       chip::DeviceLayer::ConnectivityManagerImpl>::_GetWiFiAPIdleTimeoutMS,
               "C++: "
               "chip::DeviceLayer::Internal::GenericConnectivityManagerImpl_NoWiFi<chip::DeviceLayer::ConnectivityManagerImpl>::_"
               "GetWiFiAPIdleTimeoutMS() --> unsigned int");
        cl.def(
            "_SetWiFiAPIdleTimeoutMS",
            (void (
                chip::DeviceLayer::Internal::GenericConnectivityManagerImpl_NoWiFi<chip::DeviceLayer::ConnectivityManagerImpl>::*)(
                unsigned int)) &
                chip::DeviceLayer::Internal::GenericConnectivityManagerImpl_NoWiFi<
                    chip::DeviceLayer::ConnectivityManagerImpl>::_SetWiFiAPIdleTimeoutMS,
            "C++: "
            "chip::DeviceLayer::Internal::GenericConnectivityManagerImpl_NoWiFi<chip::DeviceLayer::ConnectivityManagerImpl>::_"
            "SetWiFiAPIdleTimeoutMS(unsigned int) --> void",
            pybind11::arg("val"));
        cl.def("_GetAndLogWifiStatsCounters",
               (int (chip::DeviceLayer::Internal::GenericConnectivityManagerImpl_NoWiFi<
                     chip::DeviceLayer::ConnectivityManagerImpl>::*)()) &
                   chip::DeviceLayer::Internal::GenericConnectivityManagerImpl_NoWiFi<
                       chip::DeviceLayer::ConnectivityManagerImpl>::_GetAndLogWifiStatsCounters,
               "C++: "
               "chip::DeviceLayer::Internal::GenericConnectivityManagerImpl_NoWiFi<chip::DeviceLayer::ConnectivityManagerImpl>::_"
               "GetAndLogWifiStatsCounters() --> int");
        cl.def("_CanStartWiFiScan",
               (bool (chip::DeviceLayer::Internal::GenericConnectivityManagerImpl_NoWiFi<
                      chip::DeviceLayer::ConnectivityManagerImpl>::*)()) &
                   chip::DeviceLayer::Internal::GenericConnectivityManagerImpl_NoWiFi<
                       chip::DeviceLayer::ConnectivityManagerImpl>::_CanStartWiFiScan,
               "C++: "
               "chip::DeviceLayer::Internal::GenericConnectivityManagerImpl_NoWiFi<chip::DeviceLayer::ConnectivityManagerImpl>::_"
               "CanStartWiFiScan() --> bool");
        cl.def("_OnWiFiScanDone",
               (void (chip::DeviceLayer::Internal::GenericConnectivityManagerImpl_NoWiFi<
                      chip::DeviceLayer::ConnectivityManagerImpl>::*)()) &
                   chip::DeviceLayer::Internal::GenericConnectivityManagerImpl_NoWiFi<
                       chip::DeviceLayer::ConnectivityManagerImpl>::_OnWiFiScanDone,
               "C++: "
               "chip::DeviceLayer::Internal::GenericConnectivityManagerImpl_NoWiFi<chip::DeviceLayer::ConnectivityManagerImpl>::_"
               "OnWiFiScanDone() --> void");
        cl.def("_OnWiFiStationProvisionChange",
               (void (chip::DeviceLayer::Internal::GenericConnectivityManagerImpl_NoWiFi<
                      chip::DeviceLayer::ConnectivityManagerImpl>::*)()) &
                   chip::DeviceLayer::Internal::GenericConnectivityManagerImpl_NoWiFi<
                       chip::DeviceLayer::ConnectivityManagerImpl>::_OnWiFiStationProvisionChange,
               "C++: "
               "chip::DeviceLayer::Internal::GenericConnectivityManagerImpl_NoWiFi<chip::DeviceLayer::ConnectivityManagerImpl>::_"
               "OnWiFiStationProvisionChange() --> void");
        cl.def_static(
            "_WiFiStationModeToStr",
            (const char * (*) (enum chip::DeviceLayer::ConnectivityManager::WiFiStationMode)) &
                chip::DeviceLayer::Internal::GenericConnectivityManagerImpl_NoWiFi<
                    chip::DeviceLayer::ConnectivityManagerImpl>::_WiFiStationModeToStr,
            "C++: "
            "chip::DeviceLayer::Internal::GenericConnectivityManagerImpl_NoWiFi<chip::DeviceLayer::ConnectivityManagerImpl>::_"
            "WiFiStationModeToStr(enum chip::DeviceLayer::ConnectivityManager::WiFiStationMode) --> const char *",
            pybind11::return_value_policy::automatic, pybind11::arg("mode"));
        cl.def_static(
            "_WiFiAPModeToStr",
            (const char * (*) (enum chip::DeviceLayer::ConnectivityManager::WiFiAPMode)) &
                chip::DeviceLayer::Internal::GenericConnectivityManagerImpl_NoWiFi<
                    chip::DeviceLayer::ConnectivityManagerImpl>::_WiFiAPModeToStr,
            "C++: "
            "chip::DeviceLayer::Internal::GenericConnectivityManagerImpl_NoWiFi<chip::DeviceLayer::ConnectivityManagerImpl>::_"
            "WiFiAPModeToStr(enum chip::DeviceLayer::ConnectivityManager::WiFiAPMode) --> const char *",
            pybind11::return_value_policy::automatic, pybind11::arg("mode"));
        cl.def_static(
            "_WiFiStationStateToStr",
            (const char * (*) (enum chip::DeviceLayer::ConnectivityManager::WiFiStationState)) &
                chip::DeviceLayer::Internal::GenericConnectivityManagerImpl_NoWiFi<
                    chip::DeviceLayer::ConnectivityManagerImpl>::_WiFiStationStateToStr,
            "C++: "
            "chip::DeviceLayer::Internal::GenericConnectivityManagerImpl_NoWiFi<chip::DeviceLayer::ConnectivityManagerImpl>::_"
            "WiFiStationStateToStr(enum chip::DeviceLayer::ConnectivityManager::WiFiStationState) --> const char *",
            pybind11::return_value_policy::automatic, pybind11::arg("state"));
        cl.def_static(
            "_WiFiAPStateToStr",
            (const char * (*) (enum chip::DeviceLayer::ConnectivityManager::WiFiAPState)) &
                chip::DeviceLayer::Internal::GenericConnectivityManagerImpl_NoWiFi<
                    chip::DeviceLayer::ConnectivityManagerImpl>::_WiFiAPStateToStr,
            "C++: "
            "chip::DeviceLayer::Internal::GenericConnectivityManagerImpl_NoWiFi<chip::DeviceLayer::ConnectivityManagerImpl>::_"
            "WiFiAPStateToStr(enum chip::DeviceLayer::ConnectivityManager::WiFiAPState) --> const char *",
            pybind11::return_value_policy::automatic, pybind11::arg("state"));
        cl.def(
            "assign",
            (class chip::DeviceLayer::Internal::GenericConnectivityManagerImpl_NoWiFi<
                 class chip::DeviceLayer::ConnectivityManagerImpl> &
             (chip::DeviceLayer::Internal::GenericConnectivityManagerImpl_NoWiFi<
                 chip::DeviceLayer::ConnectivityManagerImpl>::*) (const class chip::DeviceLayer::Internal::
                                                                      GenericConnectivityManagerImpl_NoWiFi<
                                                                          class chip::DeviceLayer::ConnectivityManagerImpl> &) ) &
                chip::DeviceLayer::Internal::GenericConnectivityManagerImpl_NoWiFi<
                    chip::DeviceLayer::ConnectivityManagerImpl>::operator=,
            "C++: "
            "chip::DeviceLayer::Internal::GenericConnectivityManagerImpl_NoWiFi<chip::DeviceLayer::ConnectivityManagerImpl>::"
            "operator=(const class chip::DeviceLayer::Internal::GenericConnectivityManagerImpl_NoWiFi<class "
            "chip::DeviceLayer::ConnectivityManagerImpl> &) --> class "
            "chip::DeviceLayer::Internal::GenericConnectivityManagerImpl_NoWiFi<class chip::DeviceLayer::ConnectivityManagerImpl> "
            "&",
            pybind11::return_value_policy::automatic, pybind11::arg(""));
    }
}
