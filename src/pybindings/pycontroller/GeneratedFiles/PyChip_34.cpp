#include <platform/internal/GenericConfigurationManagerImpl.h>
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

void bind_PyChip_34(std::function<pybind11::module &(std::string const & namespace_)> & M)
{
    { // chip::DeviceLayer::Internal::GenericConfigurationManagerImpl file:platform/internal/GenericConfigurationManagerImpl.h
      // line:172
        pybind11::class_<chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>,
                         std::shared_ptr<chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<
                             chip::DeviceLayer::ConfigurationManagerImpl>>>
            cl(M("chip::DeviceLayer::Internal"), "GenericConfigurationManagerImpl_chip_DeviceLayer_ConfigurationManagerImpl_t", "");
        cl.def(pybind11::init([]() {
            return new chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>();
        }));
        cl.def(
            "_Init",
            (int (chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::*)()) &
                chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::_Init,
            "C++: "
            "chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::_Init() "
            "--> int");
        cl.def("_GetVendorName",
               (int (chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::*)(
                   char *, unsigned long)) &
                   chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<
                       chip::DeviceLayer::ConfigurationManagerImpl>::_GetVendorName,
               "C++: "
               "chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::_"
               "GetVendorName(char *, unsigned long) --> int",
               pybind11::arg("buf"), pybind11::arg("bufSize"));
        cl.def("_GetVendorId",
               (int (chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::*)(
                   unsigned short &)) &
                   chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<
                       chip::DeviceLayer::ConfigurationManagerImpl>::_GetVendorId,
               "C++: "
               "chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::_"
               "GetVendorId(unsigned short &) --> int",
               pybind11::arg("vendorId"));
        cl.def("_GetProductName",
               (int (chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::*)(
                   char *, unsigned long)) &
                   chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<
                       chip::DeviceLayer::ConfigurationManagerImpl>::_GetProductName,
               "C++: "
               "chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::_"
               "GetProductName(char *, unsigned long) --> int",
               pybind11::arg("buf"), pybind11::arg("bufSize"));
        cl.def("_GetProductId",
               (int (chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::*)(
                   unsigned short &)) &
                   chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<
                       chip::DeviceLayer::ConfigurationManagerImpl>::_GetProductId,
               "C++: "
               "chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::_"
               "GetProductId(unsigned short &) --> int",
               pybind11::arg("productId"));
        cl.def("_GetProductRevisionString",
               (int (chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::*)(
                   char *, unsigned long)) &
                   chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<
                       chip::DeviceLayer::ConfigurationManagerImpl>::_GetProductRevisionString,
               "C++: "
               "chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::_"
               "GetProductRevisionString(char *, unsigned long) --> int",
               pybind11::arg("buf"), pybind11::arg("bufSize"));
        cl.def("_GetProductRevision",
               (int (chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::*)(
                   unsigned short &)) &
                   chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<
                       chip::DeviceLayer::ConfigurationManagerImpl>::_GetProductRevision,
               "C++: "
               "chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::_"
               "GetProductRevision(unsigned short &) --> int",
               pybind11::arg("productRev"));
        cl.def("_StoreProductRevision",
               (int (chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::*)(
                   unsigned short)) &
                   chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<
                       chip::DeviceLayer::ConfigurationManagerImpl>::_StoreProductRevision,
               "C++: "
               "chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::_"
               "StoreProductRevision(unsigned short) --> int",
               pybind11::arg("productRev"));
        cl.def("_GetFirmwareRevisionString",
               (int (chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::*)(
                   char *, unsigned long)) &
                   chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<
                       chip::DeviceLayer::ConfigurationManagerImpl>::_GetFirmwareRevisionString,
               "C++: "
               "chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::_"
               "GetFirmwareRevisionString(char *, unsigned long) --> int",
               pybind11::arg("buf"), pybind11::arg("bufSize"));
        cl.def("_GetFirmwareRevision",
               (int (chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::*)(
                   unsigned int &)) &
                   chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<
                       chip::DeviceLayer::ConfigurationManagerImpl>::_GetFirmwareRevision,
               "C++: "
               "chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::_"
               "GetFirmwareRevision(unsigned int &) --> int",
               pybind11::arg("firmwareRev"));
        cl.def("_GetFirmwareBuildTime",
               (int (chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::*)(
                   unsigned short &, unsigned char &, unsigned char &, unsigned char &, unsigned char &, unsigned char &)) &
                   chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<
                       chip::DeviceLayer::ConfigurationManagerImpl>::_GetFirmwareBuildTime,
               "C++: "
               "chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::_"
               "GetFirmwareBuildTime(unsigned short &, unsigned char &, unsigned char &, unsigned char &, unsigned char &, "
               "unsigned char &) --> int",
               pybind11::arg("year"), pybind11::arg("month"), pybind11::arg("dayOfMonth"), pybind11::arg("hour"),
               pybind11::arg("minute"), pybind11::arg("second"));
        cl.def("_GetSerialNumber",
               (int (chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::*)(
                   char *, unsigned long, unsigned long &)) &
                   chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<
                       chip::DeviceLayer::ConfigurationManagerImpl>::_GetSerialNumber,
               "C++: "
               "chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::_"
               "GetSerialNumber(char *, unsigned long, unsigned long &) --> int",
               pybind11::arg("buf"), pybind11::arg("bufSize"), pybind11::arg("serialNumLen"));
        cl.def("_StoreSerialNumber",
               (int (chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::*)(
                   const char *, unsigned long)) &
                   chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<
                       chip::DeviceLayer::ConfigurationManagerImpl>::_StoreSerialNumber,
               "C++: "
               "chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::_"
               "StoreSerialNumber(const char *, unsigned long) --> int",
               pybind11::arg("serialNum"), pybind11::arg("serialNumLen"));
        cl.def("_GetPrimaryWiFiMACAddress",
               (int (chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::*)(
                   unsigned char *)) &
                   chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<
                       chip::DeviceLayer::ConfigurationManagerImpl>::_GetPrimaryWiFiMACAddress,
               "C++: "
               "chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::_"
               "GetPrimaryWiFiMACAddress(unsigned char *) --> int",
               pybind11::arg("buf"));
        cl.def("_StorePrimaryWiFiMACAddress",
               (int (chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::*)(
                   const unsigned char *)) &
                   chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<
                       chip::DeviceLayer::ConfigurationManagerImpl>::_StorePrimaryWiFiMACAddress,
               "C++: "
               "chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::_"
               "StorePrimaryWiFiMACAddress(const unsigned char *) --> int",
               pybind11::arg("buf"));
        cl.def("_GetPrimary802154MACAddress",
               (int (chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::*)(
                   unsigned char *)) &
                   chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<
                       chip::DeviceLayer::ConfigurationManagerImpl>::_GetPrimary802154MACAddress,
               "C++: "
               "chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::_"
               "GetPrimary802154MACAddress(unsigned char *) --> int",
               pybind11::arg("buf"));
        cl.def("_GetPollPeriod",
               (int (chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::*)(
                   unsigned int &)) &
                   chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<
                       chip::DeviceLayer::ConfigurationManagerImpl>::_GetPollPeriod,
               "C++: "
               "chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::_"
               "GetPollPeriod(unsigned int &) --> int",
               pybind11::arg("buf"));
        cl.def("_StorePrimary802154MACAddress",
               (int (chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::*)(
                   const unsigned char *)) &
                   chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<
                       chip::DeviceLayer::ConfigurationManagerImpl>::_StorePrimary802154MACAddress,
               "C++: "
               "chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::_"
               "StorePrimary802154MACAddress(const unsigned char *) --> int",
               pybind11::arg("buf"));
        cl.def("_GetManufacturingDate",
               (int (chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::*)(
                   unsigned short &, unsigned char &, unsigned char &)) &
                   chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<
                       chip::DeviceLayer::ConfigurationManagerImpl>::_GetManufacturingDate,
               "C++: "
               "chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::_"
               "GetManufacturingDate(unsigned short &, unsigned char &, unsigned char &) --> int",
               pybind11::arg("year"), pybind11::arg("month"), pybind11::arg("dayOfMonth"));
        cl.def("_StoreManufacturingDate",
               (int (chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::*)(
                   const char *, unsigned long)) &
                   chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<
                       chip::DeviceLayer::ConfigurationManagerImpl>::_StoreManufacturingDate,
               "C++: "
               "chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::_"
               "StoreManufacturingDate(const char *, unsigned long) --> int",
               pybind11::arg("mfgDate"), pybind11::arg("mfgDateLen"));
        cl.def("_GetDeviceId",
               (int (chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::*)(
                   unsigned long long &)) &
                   chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<
                       chip::DeviceLayer::ConfigurationManagerImpl>::_GetDeviceId,
               "C++: "
               "chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::_"
               "GetDeviceId(unsigned long long &) --> int",
               pybind11::arg("deviceId"));
        cl.def("_GetDeviceCertificate",
               (int (chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::*)(
                   unsigned char *, unsigned long, unsigned long &)) &
                   chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<
                       chip::DeviceLayer::ConfigurationManagerImpl>::_GetDeviceCertificate,
               "C++: "
               "chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::_"
               "GetDeviceCertificate(unsigned char *, unsigned long, unsigned long &) --> int",
               pybind11::arg("buf"), pybind11::arg("bufSize"), pybind11::arg("certLen"));
        cl.def("_GetDeviceIntermediateCACerts",
               (int (chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::*)(
                   unsigned char *, unsigned long, unsigned long &)) &
                   chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<
                       chip::DeviceLayer::ConfigurationManagerImpl>::_GetDeviceIntermediateCACerts,
               "C++: "
               "chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::_"
               "GetDeviceIntermediateCACerts(unsigned char *, unsigned long, unsigned long &) --> int",
               pybind11::arg("buf"), pybind11::arg("bufSize"), pybind11::arg("certsLen"));
        cl.def("_GetDevicePrivateKey",
               (int (chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::*)(
                   unsigned char *, unsigned long, unsigned long &)) &
                   chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<
                       chip::DeviceLayer::ConfigurationManagerImpl>::_GetDevicePrivateKey,
               "C++: "
               "chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::_"
               "GetDevicePrivateKey(unsigned char *, unsigned long, unsigned long &) --> int",
               pybind11::arg("buf"), pybind11::arg("bufSize"), pybind11::arg("keyLen"));
        cl.def("_GetManufacturerDeviceId",
               (int (chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::*)(
                   unsigned long long &)) &
                   chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<
                       chip::DeviceLayer::ConfigurationManagerImpl>::_GetManufacturerDeviceId,
               "C++: "
               "chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::_"
               "GetManufacturerDeviceId(unsigned long long &) --> int",
               pybind11::arg("deviceId"));
        cl.def("_StoreManufacturerDeviceId",
               (int (chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::*)(
                   unsigned long long)) &
                   chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<
                       chip::DeviceLayer::ConfigurationManagerImpl>::_StoreManufacturerDeviceId,
               "C++: "
               "chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::_"
               "StoreManufacturerDeviceId(unsigned long long) --> int",
               pybind11::arg("deviceId"));
        cl.def("_GetManufacturerDeviceCertificate",
               (int (chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::*)(
                   unsigned char *, unsigned long, unsigned long &)) &
                   chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<
                       chip::DeviceLayer::ConfigurationManagerImpl>::_GetManufacturerDeviceCertificate,
               "C++: "
               "chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::_"
               "GetManufacturerDeviceCertificate(unsigned char *, unsigned long, unsigned long &) --> int",
               pybind11::arg("buf"), pybind11::arg("bufSize"), pybind11::arg("certLen"));
        cl.def("_StoreManufacturerDeviceCertificate",
               (int (chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::*)(
                   const unsigned char *, unsigned long)) &
                   chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<
                       chip::DeviceLayer::ConfigurationManagerImpl>::_StoreManufacturerDeviceCertificate,
               "C++: "
               "chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::_"
               "StoreManufacturerDeviceCertificate(const unsigned char *, unsigned long) --> int",
               pybind11::arg("cert"), pybind11::arg("certLen"));
        cl.def("_GetManufacturerDeviceIntermediateCACerts",
               (int (chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::*)(
                   unsigned char *, unsigned long, unsigned long &)) &
                   chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<
                       chip::DeviceLayer::ConfigurationManagerImpl>::_GetManufacturerDeviceIntermediateCACerts,
               "C++: "
               "chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::_"
               "GetManufacturerDeviceIntermediateCACerts(unsigned char *, unsigned long, unsigned long &) --> int",
               pybind11::arg("buf"), pybind11::arg("bufSize"), pybind11::arg("certsLen"));
        cl.def("_StoreManufacturerDeviceIntermediateCACerts",
               (int (chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::*)(
                   const unsigned char *, unsigned long)) &
                   chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<
                       chip::DeviceLayer::ConfigurationManagerImpl>::_StoreManufacturerDeviceIntermediateCACerts,
               "C++: "
               "chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::_"
               "StoreManufacturerDeviceIntermediateCACerts(const unsigned char *, unsigned long) --> int",
               pybind11::arg("certs"), pybind11::arg("certsLen"));
        cl.def("_GetManufacturerDevicePrivateKey",
               (int (chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::*)(
                   unsigned char *, unsigned long, unsigned long &)) &
                   chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<
                       chip::DeviceLayer::ConfigurationManagerImpl>::_GetManufacturerDevicePrivateKey,
               "C++: "
               "chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::_"
               "GetManufacturerDevicePrivateKey(unsigned char *, unsigned long, unsigned long &) --> int",
               pybind11::arg("buf"), pybind11::arg("bufSize"), pybind11::arg("keyLen"));
        cl.def("_StoreManufacturerDevicePrivateKey",
               (int (chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::*)(
                   const unsigned char *, unsigned long)) &
                   chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<
                       chip::DeviceLayer::ConfigurationManagerImpl>::_StoreManufacturerDevicePrivateKey,
               "C++: "
               "chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::_"
               "StoreManufacturerDevicePrivateKey(const unsigned char *, unsigned long) --> int",
               pybind11::arg("key"), pybind11::arg("keyLen"));
        cl.def("_GetSetupPinCode",
               (int (chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::*)(
                   unsigned int &)) &
                   chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<
                       chip::DeviceLayer::ConfigurationManagerImpl>::_GetSetupPinCode,
               "C++: "
               "chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::_"
               "GetSetupPinCode(unsigned int &) --> int",
               pybind11::arg("setupPinCode"));
        cl.def("_StoreSetupPinCode",
               (int (chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::*)(
                   unsigned int)) &
                   chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<
                       chip::DeviceLayer::ConfigurationManagerImpl>::_StoreSetupPinCode,
               "C++: "
               "chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::_"
               "StoreSetupPinCode(unsigned int) --> int",
               pybind11::arg("setupPinCode"));
        cl.def("_GetSetupDiscriminator",
               (int (chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::*)(
                   unsigned short &)) &
                   chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<
                       chip::DeviceLayer::ConfigurationManagerImpl>::_GetSetupDiscriminator,
               "C++: "
               "chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::_"
               "GetSetupDiscriminator(unsigned short &) --> int",
               pybind11::arg("setupDiscriminator"));
        cl.def("_StoreSetupDiscriminator",
               (int (chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::*)(
                   unsigned short)) &
                   chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<
                       chip::DeviceLayer::ConfigurationManagerImpl>::_StoreSetupDiscriminator,
               "C++: "
               "chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::_"
               "StoreSetupDiscriminator(unsigned short) --> int",
               pybind11::arg("setupDiscriminator"));
        cl.def("_GetFabricId",
               (int (chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::*)(
                   unsigned long long &)) &
                   chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<
                       chip::DeviceLayer::ConfigurationManagerImpl>::_GetFabricId,
               "C++: "
               "chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::_"
               "GetFabricId(unsigned long long &) --> int",
               pybind11::arg("fabricId"));
        cl.def("_StoreFabricId",
               (int (chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::*)(
                   unsigned long long)) &
                   chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<
                       chip::DeviceLayer::ConfigurationManagerImpl>::_StoreFabricId,
               "C++: "
               "chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::_"
               "StoreFabricId(unsigned long long) --> int",
               pybind11::arg("fabricId"));
        cl.def("_GetLifetimeCounter",
               (int (chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::*)(
                   unsigned short &)) &
                   chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<
                       chip::DeviceLayer::ConfigurationManagerImpl>::_GetLifetimeCounter,
               "C++: "
               "chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::_"
               "GetLifetimeCounter(unsigned short &) --> int",
               pybind11::arg("lifetimeCounter"));
        cl.def(
            "_IncrementLifetimeCounter",
            (int (chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::*)()) &
                chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<
                    chip::DeviceLayer::ConfigurationManagerImpl>::_IncrementLifetimeCounter,
            "C++: "
            "chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::_"
            "IncrementLifetimeCounter() --> int");
        cl.def("_GetServiceId",
               (int (chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::*)(
                   unsigned long long &)) &
                   chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<
                       chip::DeviceLayer::ConfigurationManagerImpl>::_GetServiceId,
               "C++: "
               "chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::_"
               "GetServiceId(unsigned long long &) --> int",
               pybind11::arg("serviceId"));
        cl.def("_GetServiceConfig",
               (int (chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::*)(
                   unsigned char *, unsigned long, unsigned long &)) &
                   chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<
                       chip::DeviceLayer::ConfigurationManagerImpl>::_GetServiceConfig,
               "C++: "
               "chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::_"
               "GetServiceConfig(unsigned char *, unsigned long, unsigned long &) --> int",
               pybind11::arg("buf"), pybind11::arg("bufSize"), pybind11::arg("serviceConfigLen"));
        cl.def("_StoreServiceConfig",
               (int (chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::*)(
                   const unsigned char *, unsigned long)) &
                   chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<
                       chip::DeviceLayer::ConfigurationManagerImpl>::_StoreServiceConfig,
               "C++: "
               "chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::_"
               "StoreServiceConfig(const unsigned char *, unsigned long) --> int",
               pybind11::arg("serviceConfig"), pybind11::arg("serviceConfigLen"));
        cl.def("_GetPairedAccountId",
               (int (chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::*)(
                   char *, unsigned long, unsigned long &)) &
                   chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<
                       chip::DeviceLayer::ConfigurationManagerImpl>::_GetPairedAccountId,
               "C++: "
               "chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::_"
               "GetPairedAccountId(char *, unsigned long, unsigned long &) --> int",
               pybind11::arg("buf"), pybind11::arg("bufSize"), pybind11::arg("accountIdLen"));
        cl.def("_StorePairedAccountId",
               (int (chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::*)(
                   const char *, unsigned long)) &
                   chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<
                       chip::DeviceLayer::ConfigurationManagerImpl>::_StorePairedAccountId,
               "C++: "
               "chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::_"
               "StorePairedAccountId(const char *, unsigned long) --> int",
               pybind11::arg("accountId"), pybind11::arg("accountIdLen"));
        cl.def("_StoreServiceProvisioningData",
               (int (chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::*)(
                   unsigned long long, const unsigned char *, unsigned long, const char *, unsigned long)) &
                   chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<
                       chip::DeviceLayer::ConfigurationManagerImpl>::_StoreServiceProvisioningData,
               "C++: "
               "chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::_"
               "StoreServiceProvisioningData(unsigned long long, const unsigned char *, unsigned long, const char *, unsigned "
               "long) --> int",
               pybind11::arg("serviceId"), pybind11::arg("serviceConfig"), pybind11::arg("serviceConfigLen"),
               pybind11::arg("accountId"), pybind11::arg("accountIdLen"));
        cl.def(
            "_ClearServiceProvisioningData",
            (int (chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::*)()) &
                chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<
                    chip::DeviceLayer::ConfigurationManagerImpl>::_ClearServiceProvisioningData,
            "C++: "
            "chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::_"
            "ClearServiceProvisioningData() --> int");
        cl.def("_GetFailSafeArmed",
               (int (chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::*)(
                   bool &)) &
                   chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<
                       chip::DeviceLayer::ConfigurationManagerImpl>::_GetFailSafeArmed,
               "C++: "
               "chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::_"
               "GetFailSafeArmed(bool &) --> int",
               pybind11::arg("val"));
        cl.def("_SetFailSafeArmed",
               (int (chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::*)(
                   bool)) &
                   chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<
                       chip::DeviceLayer::ConfigurationManagerImpl>::_SetFailSafeArmed,
               "C++: "
               "chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::_"
               "SetFailSafeArmed(bool) --> int",
               pybind11::arg("val"));
        cl.def("_GetQRCodeString",
               (int (chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::*)(
                   char *, unsigned long)) &
                   chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<
                       chip::DeviceLayer::ConfigurationManagerImpl>::_GetQRCodeString,
               "C++: "
               "chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::_"
               "GetQRCodeString(char *, unsigned long) --> int",
               pybind11::arg("buf"), pybind11::arg("bufSize"));
        cl.def("_GetWiFiAPSSID",
               (int (chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::*)(
                   char *, unsigned long)) &
                   chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<
                       chip::DeviceLayer::ConfigurationManagerImpl>::_GetWiFiAPSSID,
               "C++: "
               "chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::_"
               "GetWiFiAPSSID(char *, unsigned long) --> int",
               pybind11::arg("buf"), pybind11::arg("bufSize"));
        cl.def(
            "_IsCommissionableDeviceTypeEnabled",
            (bool (
                chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::*)()) &
                chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<
                    chip::DeviceLayer::ConfigurationManagerImpl>::_IsCommissionableDeviceTypeEnabled,
            "C++: "
            "chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::_"
            "IsCommissionableDeviceTypeEnabled() --> bool");
        cl.def("_GetDeviceType",
               (int (chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::*)(
                   unsigned short &)) &
                   chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<
                       chip::DeviceLayer::ConfigurationManagerImpl>::_GetDeviceType,
               "C++: "
               "chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::_"
               "GetDeviceType(unsigned short &) --> int",
               pybind11::arg("deviceType"));
        cl.def(
            "_IsCommissionableDeviceNameEnabled",
            (bool (
                chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::*)()) &
                chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<
                    chip::DeviceLayer::ConfigurationManagerImpl>::_IsCommissionableDeviceNameEnabled,
            "C++: "
            "chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::_"
            "IsCommissionableDeviceNameEnabled() --> bool");
        cl.def("_GetDeviceName",
               (int (chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::*)(
                   char *, unsigned long)) &
                   chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<
                       chip::DeviceLayer::ConfigurationManagerImpl>::_GetDeviceName,
               "C++: "
               "chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::_"
               "GetDeviceName(char *, unsigned long) --> int",
               pybind11::arg("buf"), pybind11::arg("bufSize"));
        cl.def("_GetInitialPairingHint",
               (int (chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::*)(
                   unsigned short &)) &
                   chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<
                       chip::DeviceLayer::ConfigurationManagerImpl>::_GetInitialPairingHint,
               "C++: "
               "chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::_"
               "GetInitialPairingHint(unsigned short &) --> int",
               pybind11::arg("pairingHint"));
        cl.def("_GetInitialPairingInstruction",
               (int (chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::*)(
                   char *, unsigned long)) &
                   chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<
                       chip::DeviceLayer::ConfigurationManagerImpl>::_GetInitialPairingInstruction,
               "C++: "
               "chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::_"
               "GetInitialPairingInstruction(char *, unsigned long) --> int",
               pybind11::arg("buf"), pybind11::arg("bufSize"));
        cl.def("_GetSecondaryPairingHint",
               (int (chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::*)(
                   unsigned short &)) &
                   chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<
                       chip::DeviceLayer::ConfigurationManagerImpl>::_GetSecondaryPairingHint,
               "C++: "
               "chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::_"
               "GetSecondaryPairingHint(unsigned short &) --> int",
               pybind11::arg("pairingHint"));
        cl.def("_GetSecondaryPairingInstruction",
               (int (chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::*)(
                   char *, unsigned long)) &
                   chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<
                       chip::DeviceLayer::ConfigurationManagerImpl>::_GetSecondaryPairingInstruction,
               "C++: "
               "chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::_"
               "GetSecondaryPairingInstruction(char *, unsigned long) --> int",
               pybind11::arg("buf"), pybind11::arg("bufSize"));
        cl.def("_GetRegulatoryLocation",
               (int (chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::*)(
                   unsigned int &)) &
                   chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<
                       chip::DeviceLayer::ConfigurationManagerImpl>::_GetRegulatoryLocation,
               "C++: "
               "chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::_"
               "GetRegulatoryLocation(unsigned int &) --> int",
               pybind11::arg("location"));
        cl.def("_StoreRegulatoryLocation",
               (int (chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::*)(
                   unsigned int)) &
                   chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<
                       chip::DeviceLayer::ConfigurationManagerImpl>::_StoreRegulatoryLocation,
               "C++: "
               "chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::_"
               "StoreRegulatoryLocation(unsigned int) --> int",
               pybind11::arg("location"));
        cl.def("_GetCountryCode",
               (int (chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::*)(
                   char *, unsigned long, unsigned long &)) &
                   chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<
                       chip::DeviceLayer::ConfigurationManagerImpl>::_GetCountryCode,
               "C++: "
               "chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::_"
               "GetCountryCode(char *, unsigned long, unsigned long &) --> int",
               pybind11::arg("buf"), pybind11::arg("bufSize"), pybind11::arg("codeLen"));
        cl.def("_StoreCountryCode",
               (int (chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::*)(
                   const char *, unsigned long)) &
                   chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<
                       chip::DeviceLayer::ConfigurationManagerImpl>::_StoreCountryCode,
               "C++: "
               "chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::_"
               "StoreCountryCode(const char *, unsigned long) --> int",
               pybind11::arg("code"), pybind11::arg("codeLen"));
        cl.def("_GetBreadcrumb",
               (int (chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::*)(
                   unsigned long long &)) &
                   chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<
                       chip::DeviceLayer::ConfigurationManagerImpl>::_GetBreadcrumb,
               "C++: "
               "chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::_"
               "GetBreadcrumb(unsigned long long &) --> int",
               pybind11::arg("breadcrumb"));
        cl.def("_StoreBreadcrumb",
               (int (chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::*)(
                   unsigned long long)) &
                   chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<
                       chip::DeviceLayer::ConfigurationManagerImpl>::_StoreBreadcrumb,
               "C++: "
               "chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::_"
               "StoreBreadcrumb(unsigned long long) --> int",
               pybind11::arg("breadcrumb"));
        cl.def(
            "_ConfigureChipStack",
            (int (chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::*)()) &
                chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<
                    chip::DeviceLayer::ConfigurationManagerImpl>::_ConfigureChipStack,
            "C++: "
            "chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::_"
            "ConfigureChipStack() --> int");
        cl.def(
            "_RunUnitTests",
            (int (chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::*)()) &
                chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<
                    chip::DeviceLayer::ConfigurationManagerImpl>::_RunUnitTests,
            "C++: "
            "chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::_"
            "RunUnitTests() --> int");
        cl.def(
            "_IsServiceProvisioned",
            (bool (
                chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::*)()) &
                chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<
                    chip::DeviceLayer::ConfigurationManagerImpl>::_IsServiceProvisioned,
            "C++: "
            "chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::_"
            "IsServiceProvisioned() --> bool");
        cl.def(
            "_IsMemberOfFabric",
            (bool (
                chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::*)()) &
                chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<
                    chip::DeviceLayer::ConfigurationManagerImpl>::_IsMemberOfFabric,
            "C++: "
            "chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::_"
            "IsMemberOfFabric() --> bool");
        cl.def(
            "_IsPairedToAccount",
            (bool (
                chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::*)()) &
                chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<
                    chip::DeviceLayer::ConfigurationManagerImpl>::_IsPairedToAccount,
            "C++: "
            "chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::_"
            "IsPairedToAccount() --> bool");
        cl.def(
            "_IsFullyProvisioned",
            (bool (
                chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::*)()) &
                chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<
                    chip::DeviceLayer::ConfigurationManagerImpl>::_IsFullyProvisioned,
            "C++: "
            "chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::_"
            "IsFullyProvisioned() --> bool");
        cl.def("_ComputeProvisioningHash",
               (int (chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::*)(
                   unsigned char *, unsigned long)) &
                   chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<
                       chip::DeviceLayer::ConfigurationManagerImpl>::_ComputeProvisioningHash,
               "C++: "
               "chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::_"
               "ComputeProvisioningHash(unsigned char *, unsigned long) --> int",
               pybind11::arg("hashBuf"), pybind11::arg("hashBufSize"));
        cl.def(
            "_LogDeviceConfig",
            (void (
                chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::*)()) &
                chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<
                    chip::DeviceLayer::ConfigurationManagerImpl>::_LogDeviceConfig,
            "C++: "
            "chip::DeviceLayer::Internal::GenericConfigurationManagerImpl<chip::DeviceLayer::ConfigurationManagerImpl>::_"
            "LogDeviceConfig() --> void");
    }
}
