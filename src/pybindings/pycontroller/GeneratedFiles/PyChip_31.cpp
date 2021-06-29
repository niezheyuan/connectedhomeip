#include <platform/ConfigurationManager.h>
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

void bind_PyChip_31(std::function<pybind11::module &(std::string const & namespace_)> & M)
{
    { // chip::DeviceLayer::ConfigurationManager file:platform/ConfigurationManager.h line:52
        pybind11::class_<chip::DeviceLayer::ConfigurationManager, chip::DeviceLayer::ConfigurationManager *> cl(
            M("chip::DeviceLayer"), "ConfigurationManager",
            "Provides access to runtime and build-time configuration information for a chip device.");
        cl.def("GetVendorName",
               (int (chip::DeviceLayer::ConfigurationManager::*)(char *, unsigned long)) &
                   chip::DeviceLayer::ConfigurationManager::GetVendorName,
               "C++: chip::DeviceLayer::ConfigurationManager::GetVendorName(char *, unsigned long) --> int", pybind11::arg("buf"),
               pybind11::arg("bufSize"));
        cl.def("GetVendorId",
               (int (chip::DeviceLayer::ConfigurationManager::*)(unsigned short &)) &
                   chip::DeviceLayer::ConfigurationManager::GetVendorId,
               "C++: chip::DeviceLayer::ConfigurationManager::GetVendorId(unsigned short &) --> int", pybind11::arg("vendorId"));
        cl.def("GetProductName",
               (int (chip::DeviceLayer::ConfigurationManager::*)(char *, unsigned long)) &
                   chip::DeviceLayer::ConfigurationManager::GetProductName,
               "C++: chip::DeviceLayer::ConfigurationManager::GetProductName(char *, unsigned long) --> int", pybind11::arg("buf"),
               pybind11::arg("bufSize"));
        cl.def("GetProductId",
               (int (chip::DeviceLayer::ConfigurationManager::*)(unsigned short &)) &
                   chip::DeviceLayer::ConfigurationManager::GetProductId,
               "C++: chip::DeviceLayer::ConfigurationManager::GetProductId(unsigned short &) --> int", pybind11::arg("productId"));
        cl.def("GetProductRevisionString",
               (int (chip::DeviceLayer::ConfigurationManager::*)(char *, unsigned long)) &
                   chip::DeviceLayer::ConfigurationManager::GetProductRevisionString,
               "C++: chip::DeviceLayer::ConfigurationManager::GetProductRevisionString(char *, unsigned long) --> int",
               pybind11::arg("buf"), pybind11::arg("bufSize"));
        cl.def("GetProductRevision",
               (int (chip::DeviceLayer::ConfigurationManager::*)(unsigned short &)) &
                   chip::DeviceLayer::ConfigurationManager::GetProductRevision,
               "C++: chip::DeviceLayer::ConfigurationManager::GetProductRevision(unsigned short &) --> int",
               pybind11::arg("productRev"));
        cl.def("GetSerialNumber",
               (int (chip::DeviceLayer::ConfigurationManager::*)(char *, unsigned long, unsigned long &)) &
                   chip::DeviceLayer::ConfigurationManager::GetSerialNumber,
               "C++: chip::DeviceLayer::ConfigurationManager::GetSerialNumber(char *, unsigned long, unsigned long &) --> int",
               pybind11::arg("buf"), pybind11::arg("bufSize"), pybind11::arg("serialNumLen"));
        cl.def("GetPrimaryWiFiMACAddress",
               (int (chip::DeviceLayer::ConfigurationManager::*)(unsigned char *)) &
                   chip::DeviceLayer::ConfigurationManager::GetPrimaryWiFiMACAddress,
               "C++: chip::DeviceLayer::ConfigurationManager::GetPrimaryWiFiMACAddress(unsigned char *) --> int",
               pybind11::arg("buf"));
        cl.def("GetPrimary802154MACAddress",
               (int (chip::DeviceLayer::ConfigurationManager::*)(unsigned char *)) &
                   chip::DeviceLayer::ConfigurationManager::GetPrimary802154MACAddress,
               "C++: chip::DeviceLayer::ConfigurationManager::GetPrimary802154MACAddress(unsigned char *) --> int",
               pybind11::arg("buf"));
        cl.def("GetManufacturingDate",
               (int (chip::DeviceLayer::ConfigurationManager::*)(unsigned short &, unsigned char &, unsigned char &)) &
                   chip::DeviceLayer::ConfigurationManager::GetManufacturingDate,
               "C++: chip::DeviceLayer::ConfigurationManager::GetManufacturingDate(unsigned short &, unsigned char &, unsigned "
               "char &) --> int",
               pybind11::arg("year"), pybind11::arg("month"), pybind11::arg("dayOfMonth"));
        cl.def("GetFirmwareRevisionString",
               (int (chip::DeviceLayer::ConfigurationManager::*)(char *, unsigned long)) &
                   chip::DeviceLayer::ConfigurationManager::GetFirmwareRevisionString,
               "C++: chip::DeviceLayer::ConfigurationManager::GetFirmwareRevisionString(char *, unsigned long) --> int",
               pybind11::arg("buf"), pybind11::arg("bufSize"));
        cl.def("GetFirmwareRevision",
               (int (chip::DeviceLayer::ConfigurationManager::*)(unsigned int &)) &
                   chip::DeviceLayer::ConfigurationManager::GetFirmwareRevision,
               "C++: chip::DeviceLayer::ConfigurationManager::GetFirmwareRevision(unsigned int &) --> int",
               pybind11::arg("firmwareRev"));
        cl.def("GetFirmwareBuildTime",
               (int (chip::DeviceLayer::ConfigurationManager::*)(unsigned short &, unsigned char &, unsigned char &,
                                                                 unsigned char &, unsigned char &, unsigned char &)) &
                   chip::DeviceLayer::ConfigurationManager::GetFirmwareBuildTime,
               "C++: chip::DeviceLayer::ConfigurationManager::GetFirmwareBuildTime(unsigned short &, unsigned char &, unsigned "
               "char &, unsigned char &, unsigned char &, unsigned char &) --> int",
               pybind11::arg("year"), pybind11::arg("month"), pybind11::arg("dayOfMonth"), pybind11::arg("hour"),
               pybind11::arg("minute"), pybind11::arg("second"));
        cl.def("GetDeviceId",
               (int (chip::DeviceLayer::ConfigurationManager::*)(unsigned long long &)) &
                   chip::DeviceLayer::ConfigurationManager::GetDeviceId,
               "C++: chip::DeviceLayer::ConfigurationManager::GetDeviceId(unsigned long long &) --> int",
               pybind11::arg("deviceId"));
        cl.def("GetDeviceCertificate",
               (int (chip::DeviceLayer::ConfigurationManager::*)(unsigned char *, unsigned long, unsigned long &)) &
                   chip::DeviceLayer::ConfigurationManager::GetDeviceCertificate,
               "C++: chip::DeviceLayer::ConfigurationManager::GetDeviceCertificate(unsigned char *, unsigned long, unsigned long "
               "&) --> int",
               pybind11::arg("buf"), pybind11::arg("bufSize"), pybind11::arg("certLen"));
        cl.def("GetDeviceIntermediateCACerts",
               (int (chip::DeviceLayer::ConfigurationManager::*)(unsigned char *, unsigned long, unsigned long &)) &
                   chip::DeviceLayer::ConfigurationManager::GetDeviceIntermediateCACerts,
               "C++: chip::DeviceLayer::ConfigurationManager::GetDeviceIntermediateCACerts(unsigned char *, unsigned long, "
               "unsigned long &) --> int",
               pybind11::arg("buf"), pybind11::arg("bufSize"), pybind11::arg("certsLen"));
        cl.def("GetDevicePrivateKey",
               (int (chip::DeviceLayer::ConfigurationManager::*)(unsigned char *, unsigned long, unsigned long &)) &
                   chip::DeviceLayer::ConfigurationManager::GetDevicePrivateKey,
               "C++: chip::DeviceLayer::ConfigurationManager::GetDevicePrivateKey(unsigned char *, unsigned long, unsigned long &) "
               "--> int",
               pybind11::arg("buf"), pybind11::arg("bufSize"), pybind11::arg("keyLen"));
        cl.def("GetManufacturerDeviceId",
               (int (chip::DeviceLayer::ConfigurationManager::*)(unsigned long long &)) &
                   chip::DeviceLayer::ConfigurationManager::GetManufacturerDeviceId,
               "C++: chip::DeviceLayer::ConfigurationManager::GetManufacturerDeviceId(unsigned long long &) --> int",
               pybind11::arg("deviceId"));
        cl.def("GetManufacturerDeviceCertificate",
               (int (chip::DeviceLayer::ConfigurationManager::*)(unsigned char *, unsigned long, unsigned long &)) &
                   chip::DeviceLayer::ConfigurationManager::GetManufacturerDeviceCertificate,
               "C++: chip::DeviceLayer::ConfigurationManager::GetManufacturerDeviceCertificate(unsigned char *, unsigned long, "
               "unsigned long &) --> int",
               pybind11::arg("buf"), pybind11::arg("bufSize"), pybind11::arg("certLen"));
        cl.def("GetManufacturerDeviceIntermediateCACerts",
               (int (chip::DeviceLayer::ConfigurationManager::*)(unsigned char *, unsigned long, unsigned long &)) &
                   chip::DeviceLayer::ConfigurationManager::GetManufacturerDeviceIntermediateCACerts,
               "C++: chip::DeviceLayer::ConfigurationManager::GetManufacturerDeviceIntermediateCACerts(unsigned char *, unsigned "
               "long, unsigned long &) --> int",
               pybind11::arg("buf"), pybind11::arg("bufSize"), pybind11::arg("certsLen"));
        cl.def("GetManufacturerDevicePrivateKey",
               (int (chip::DeviceLayer::ConfigurationManager::*)(unsigned char *, unsigned long, unsigned long &)) &
                   chip::DeviceLayer::ConfigurationManager::GetManufacturerDevicePrivateKey,
               "C++: chip::DeviceLayer::ConfigurationManager::GetManufacturerDevicePrivateKey(unsigned char *, unsigned long, "
               "unsigned long &) --> int",
               pybind11::arg("buf"), pybind11::arg("bufSize"), pybind11::arg("keyLen"));
        cl.def("GetSetupPinCode",
               (int (chip::DeviceLayer::ConfigurationManager::*)(unsigned int &)) &
                   chip::DeviceLayer::ConfigurationManager::GetSetupPinCode,
               "C++: chip::DeviceLayer::ConfigurationManager::GetSetupPinCode(unsigned int &) --> int",
               pybind11::arg("setupPinCode"));
        cl.def("GetSetupDiscriminator",
               (int (chip::DeviceLayer::ConfigurationManager::*)(unsigned short &)) &
                   chip::DeviceLayer::ConfigurationManager::GetSetupDiscriminator,
               "C++: chip::DeviceLayer::ConfigurationManager::GetSetupDiscriminator(unsigned short &) --> int",
               pybind11::arg("setupDiscriminator"));
        cl.def("GetServiceId",
               (int (chip::DeviceLayer::ConfigurationManager::*)(unsigned long long &)) &
                   chip::DeviceLayer::ConfigurationManager::GetServiceId,
               "C++: chip::DeviceLayer::ConfigurationManager::GetServiceId(unsigned long long &) --> int",
               pybind11::arg("serviceId"));
        cl.def("GetFabricId",
               (int (chip::DeviceLayer::ConfigurationManager::*)(unsigned long long &)) &
                   chip::DeviceLayer::ConfigurationManager::GetFabricId,
               "C++: chip::DeviceLayer::ConfigurationManager::GetFabricId(unsigned long long &) --> int",
               pybind11::arg("fabricId"));
        cl.def("GetServiceConfig",
               (int (chip::DeviceLayer::ConfigurationManager::*)(unsigned char *, unsigned long, unsigned long &)) &
                   chip::DeviceLayer::ConfigurationManager::GetServiceConfig,
               "C++: chip::DeviceLayer::ConfigurationManager::GetServiceConfig(unsigned char *, unsigned long, unsigned long &) "
               "--> int",
               pybind11::arg("buf"), pybind11::arg("bufSize"), pybind11::arg("serviceConfigLen"));
        cl.def("GetPairedAccountId",
               (int (chip::DeviceLayer::ConfigurationManager::*)(char *, unsigned long, unsigned long &)) &
                   chip::DeviceLayer::ConfigurationManager::GetPairedAccountId,
               "C++: chip::DeviceLayer::ConfigurationManager::GetPairedAccountId(char *, unsigned long, unsigned long &) --> int",
               pybind11::arg("buf"), pybind11::arg("bufSize"), pybind11::arg("accountIdLen"));
        cl.def("GetLifetimeCounter",
               (int (chip::DeviceLayer::ConfigurationManager::*)(unsigned short &)) &
                   chip::DeviceLayer::ConfigurationManager::GetLifetimeCounter,
               "C++: chip::DeviceLayer::ConfigurationManager::GetLifetimeCounter(unsigned short &) --> int",
               pybind11::arg("lifetimeCounter"));
        cl.def("GetRegulatoryLocation",
               (int (chip::DeviceLayer::ConfigurationManager::*)(unsigned int &)) &
                   chip::DeviceLayer::ConfigurationManager::GetRegulatoryLocation,
               "C++: chip::DeviceLayer::ConfigurationManager::GetRegulatoryLocation(unsigned int &) --> int",
               pybind11::arg("location"));
        cl.def("GetCountryCode",
               (int (chip::DeviceLayer::ConfigurationManager::*)(char *, unsigned long, unsigned long &)) &
                   chip::DeviceLayer::ConfigurationManager::GetCountryCode,
               "C++: chip::DeviceLayer::ConfigurationManager::GetCountryCode(char *, unsigned long, unsigned long &) --> int",
               pybind11::arg("buf"), pybind11::arg("bufSize"), pybind11::arg("codeLen"));
        cl.def("GetBreadcrumb",
               (int (chip::DeviceLayer::ConfigurationManager::*)(unsigned long long &)) &
                   chip::DeviceLayer::ConfigurationManager::GetBreadcrumb,
               "C++: chip::DeviceLayer::ConfigurationManager::GetBreadcrumb(unsigned long long &) --> int",
               pybind11::arg("breadcrumb"));
        cl.def("StoreSerialNumber",
               (int (chip::DeviceLayer::ConfigurationManager::*)(const char *, unsigned long)) &
                   chip::DeviceLayer::ConfigurationManager::StoreSerialNumber,
               "C++: chip::DeviceLayer::ConfigurationManager::StoreSerialNumber(const char *, unsigned long) --> int",
               pybind11::arg("serialNum"), pybind11::arg("serialNumLen"));
        cl.def("StorePrimaryWiFiMACAddress",
               (int (chip::DeviceLayer::ConfigurationManager::*)(const unsigned char *)) &
                   chip::DeviceLayer::ConfigurationManager::StorePrimaryWiFiMACAddress,
               "C++: chip::DeviceLayer::ConfigurationManager::StorePrimaryWiFiMACAddress(const unsigned char *) --> int",
               pybind11::arg("buf"));
        cl.def("StorePrimary802154MACAddress",
               (int (chip::DeviceLayer::ConfigurationManager::*)(const unsigned char *)) &
                   chip::DeviceLayer::ConfigurationManager::StorePrimary802154MACAddress,
               "C++: chip::DeviceLayer::ConfigurationManager::StorePrimary802154MACAddress(const unsigned char *) --> int",
               pybind11::arg("buf"));
        cl.def("StoreManufacturingDate",
               (int (chip::DeviceLayer::ConfigurationManager::*)(const char *, unsigned long)) &
                   chip::DeviceLayer::ConfigurationManager::StoreManufacturingDate,
               "C++: chip::DeviceLayer::ConfigurationManager::StoreManufacturingDate(const char *, unsigned long) --> int",
               pybind11::arg("mfgDate"), pybind11::arg("mfgDateLen"));
        cl.def("StoreProductRevision",
               (int (chip::DeviceLayer::ConfigurationManager::*)(unsigned short)) &
                   chip::DeviceLayer::ConfigurationManager::StoreProductRevision,
               "C++: chip::DeviceLayer::ConfigurationManager::StoreProductRevision(unsigned short) --> int",
               pybind11::arg("productRev"));
        cl.def("StoreFabricId",
               (int (chip::DeviceLayer::ConfigurationManager::*)(unsigned long long)) &
                   chip::DeviceLayer::ConfigurationManager::StoreFabricId,
               "C++: chip::DeviceLayer::ConfigurationManager::StoreFabricId(unsigned long long) --> int",
               pybind11::arg("fabricId"));
        cl.def("StoreManufacturerDeviceId",
               (int (chip::DeviceLayer::ConfigurationManager::*)(unsigned long long)) &
                   chip::DeviceLayer::ConfigurationManager::StoreManufacturerDeviceId,
               "C++: chip::DeviceLayer::ConfigurationManager::StoreManufacturerDeviceId(unsigned long long) --> int",
               pybind11::arg("deviceId"));
        cl.def("StoreManufacturerDeviceCertificate",
               (int (chip::DeviceLayer::ConfigurationManager::*)(const unsigned char *, unsigned long)) &
                   chip::DeviceLayer::ConfigurationManager::StoreManufacturerDeviceCertificate,
               "C++: chip::DeviceLayer::ConfigurationManager::StoreManufacturerDeviceCertificate(const unsigned char *, unsigned "
               "long) --> int",
               pybind11::arg("cert"), pybind11::arg("certLen"));
        cl.def("StoreManufacturerDeviceIntermediateCACerts",
               (int (chip::DeviceLayer::ConfigurationManager::*)(const unsigned char *, unsigned long)) &
                   chip::DeviceLayer::ConfigurationManager::StoreManufacturerDeviceIntermediateCACerts,
               "C++: chip::DeviceLayer::ConfigurationManager::StoreManufacturerDeviceIntermediateCACerts(const unsigned char *, "
               "unsigned long) --> int",
               pybind11::arg("certs"), pybind11::arg("certsLen"));
        cl.def("StoreManufacturerDevicePrivateKey",
               (int (chip::DeviceLayer::ConfigurationManager::*)(const unsigned char *, unsigned long)) &
                   chip::DeviceLayer::ConfigurationManager::StoreManufacturerDevicePrivateKey,
               "C++: chip::DeviceLayer::ConfigurationManager::StoreManufacturerDevicePrivateKey(const unsigned char *, unsigned "
               "long) --> int",
               pybind11::arg("key"), pybind11::arg("keyLen"));
        cl.def("StoreSetupPinCode",
               (int (chip::DeviceLayer::ConfigurationManager::*)(unsigned int)) &
                   chip::DeviceLayer::ConfigurationManager::StoreSetupPinCode,
               "C++: chip::DeviceLayer::ConfigurationManager::StoreSetupPinCode(unsigned int) --> int",
               pybind11::arg("setupPinCode"));
        cl.def("StoreSetupDiscriminator",
               (int (chip::DeviceLayer::ConfigurationManager::*)(unsigned short)) &
                   chip::DeviceLayer::ConfigurationManager::StoreSetupDiscriminator,
               "C++: chip::DeviceLayer::ConfigurationManager::StoreSetupDiscriminator(unsigned short) --> int",
               pybind11::arg("setupDiscriminator"));
        cl.def("StoreServiceProvisioningData",
               (int (chip::DeviceLayer::ConfigurationManager::*)(unsigned long long, const unsigned char *, unsigned long,
                                                                 const char *, unsigned long)) &
                   chip::DeviceLayer::ConfigurationManager::StoreServiceProvisioningData,
               "C++: chip::DeviceLayer::ConfigurationManager::StoreServiceProvisioningData(unsigned long long, const unsigned char "
               "*, unsigned long, const char *, unsigned long) --> int",
               pybind11::arg("serviceId"), pybind11::arg("serviceConfig"), pybind11::arg("serviceConfigLen"),
               pybind11::arg("accountId"), pybind11::arg("accountIdLen"));
        cl.def("ClearServiceProvisioningData",
               (int (chip::DeviceLayer::ConfigurationManager::*)()) &
                   chip::DeviceLayer::ConfigurationManager::ClearServiceProvisioningData,
               "C++: chip::DeviceLayer::ConfigurationManager::ClearServiceProvisioningData() --> int");
        cl.def("StoreServiceConfig",
               (int (chip::DeviceLayer::ConfigurationManager::*)(const unsigned char *, unsigned long)) &
                   chip::DeviceLayer::ConfigurationManager::StoreServiceConfig,
               "C++: chip::DeviceLayer::ConfigurationManager::StoreServiceConfig(const unsigned char *, unsigned long) --> int",
               pybind11::arg("serviceConfig"), pybind11::arg("serviceConfigLen"));
        cl.def("StorePairedAccountId",
               (int (chip::DeviceLayer::ConfigurationManager::*)(const char *, unsigned long)) &
                   chip::DeviceLayer::ConfigurationManager::StorePairedAccountId,
               "C++: chip::DeviceLayer::ConfigurationManager::StorePairedAccountId(const char *, unsigned long) --> int",
               pybind11::arg("accountId"), pybind11::arg("accountIdLen"));
        cl.def("StoreRegulatoryLocation",
               (int (chip::DeviceLayer::ConfigurationManager::*)(unsigned int)) &
                   chip::DeviceLayer::ConfigurationManager::StoreRegulatoryLocation,
               "C++: chip::DeviceLayer::ConfigurationManager::StoreRegulatoryLocation(unsigned int) --> int",
               pybind11::arg("location"));
        cl.def("StoreCountryCode",
               (int (chip::DeviceLayer::ConfigurationManager::*)(const char *, unsigned long)) &
                   chip::DeviceLayer::ConfigurationManager::StoreCountryCode,
               "C++: chip::DeviceLayer::ConfigurationManager::StoreCountryCode(const char *, unsigned long) --> int",
               pybind11::arg("code"), pybind11::arg("codeLen"));
        cl.def("StoreBreadcrumb",
               (int (chip::DeviceLayer::ConfigurationManager::*)(unsigned long long)) &
                   chip::DeviceLayer::ConfigurationManager::StoreBreadcrumb,
               "C++: chip::DeviceLayer::ConfigurationManager::StoreBreadcrumb(unsigned long long) --> int",
               pybind11::arg("breadcrumb"));
        cl.def("GetQRCodeString",
               (int (chip::DeviceLayer::ConfigurationManager::*)(char *, unsigned long)) &
                   chip::DeviceLayer::ConfigurationManager::GetQRCodeString,
               "C++: chip::DeviceLayer::ConfigurationManager::GetQRCodeString(char *, unsigned long) --> int", pybind11::arg("buf"),
               pybind11::arg("bufSize"));
        cl.def("GetWiFiAPSSID",
               (int (chip::DeviceLayer::ConfigurationManager::*)(char *, unsigned long)) &
                   chip::DeviceLayer::ConfigurationManager::GetWiFiAPSSID,
               "C++: chip::DeviceLayer::ConfigurationManager::GetWiFiAPSSID(char *, unsigned long) --> int", pybind11::arg("buf"),
               pybind11::arg("bufSize"));
        cl.def("RunUnitTests",
               (int (chip::DeviceLayer::ConfigurationManager::*)()) & chip::DeviceLayer::ConfigurationManager::RunUnitTests,
               "C++: chip::DeviceLayer::ConfigurationManager::RunUnitTests() --> int");
        cl.def("IsServiceProvisioned",
               (bool (chip::DeviceLayer::ConfigurationManager::*)()) &
                   chip::DeviceLayer::ConfigurationManager::IsServiceProvisioned,
               "C++: chip::DeviceLayer::ConfigurationManager::IsServiceProvisioned() --> bool");
        cl.def("IsPairedToAccount",
               (bool (chip::DeviceLayer::ConfigurationManager::*)()) & chip::DeviceLayer::ConfigurationManager::IsPairedToAccount,
               "C++: chip::DeviceLayer::ConfigurationManager::IsPairedToAccount() --> bool");
        cl.def("IsMemberOfFabric",
               (bool (chip::DeviceLayer::ConfigurationManager::*)()) & chip::DeviceLayer::ConfigurationManager::IsMemberOfFabric,
               "C++: chip::DeviceLayer::ConfigurationManager::IsMemberOfFabric() --> bool");
        cl.def("IsFullyProvisioned",
               (bool (chip::DeviceLayer::ConfigurationManager::*)()) & chip::DeviceLayer::ConfigurationManager::IsFullyProvisioned,
               "C++: chip::DeviceLayer::ConfigurationManager::IsFullyProvisioned() --> bool");
        cl.def("InitiateFactoryReset",
               (void (chip::DeviceLayer::ConfigurationManager::*)()) &
                   chip::DeviceLayer::ConfigurationManager::InitiateFactoryReset,
               "C++: chip::DeviceLayer::ConfigurationManager::InitiateFactoryReset() --> void");
        cl.def("ComputeProvisioningHash",
               (int (chip::DeviceLayer::ConfigurationManager::*)(unsigned char *, unsigned long)) &
                   chip::DeviceLayer::ConfigurationManager::ComputeProvisioningHash,
               "C++: chip::DeviceLayer::ConfigurationManager::ComputeProvisioningHash(unsigned char *, unsigned long) --> int",
               pybind11::arg("hashBuf"), pybind11::arg("hashBufSize"));
        cl.def("LogDeviceConfig",
               (void (chip::DeviceLayer::ConfigurationManager::*)()) & chip::DeviceLayer::ConfigurationManager::LogDeviceConfig,
               "C++: chip::DeviceLayer::ConfigurationManager::LogDeviceConfig() --> void");
        cl.def("IsCommissionableDeviceTypeEnabled",
               (bool (chip::DeviceLayer::ConfigurationManager::*)()) &
                   chip::DeviceLayer::ConfigurationManager::IsCommissionableDeviceTypeEnabled,
               "C++: chip::DeviceLayer::ConfigurationManager::IsCommissionableDeviceTypeEnabled() --> bool");
        cl.def("GetDeviceType",
               (int (chip::DeviceLayer::ConfigurationManager::*)(unsigned short &)) &
                   chip::DeviceLayer::ConfigurationManager::GetDeviceType,
               "C++: chip::DeviceLayer::ConfigurationManager::GetDeviceType(unsigned short &) --> int",
               pybind11::arg("deviceType"));
        cl.def("IsCommissionableDeviceNameEnabled",
               (bool (chip::DeviceLayer::ConfigurationManager::*)()) &
                   chip::DeviceLayer::ConfigurationManager::IsCommissionableDeviceNameEnabled,
               "C++: chip::DeviceLayer::ConfigurationManager::IsCommissionableDeviceNameEnabled() --> bool");
        cl.def("GetDeviceName",
               (int (chip::DeviceLayer::ConfigurationManager::*)(char *, unsigned long)) &
                   chip::DeviceLayer::ConfigurationManager::GetDeviceName,
               "C++: chip::DeviceLayer::ConfigurationManager::GetDeviceName(char *, unsigned long) --> int", pybind11::arg("buf"),
               pybind11::arg("bufSize"));
        cl.def("GetInitialPairingHint",
               (int (chip::DeviceLayer::ConfigurationManager::*)(unsigned short &)) &
                   chip::DeviceLayer::ConfigurationManager::GetInitialPairingHint,
               "C++: chip::DeviceLayer::ConfigurationManager::GetInitialPairingHint(unsigned short &) --> int",
               pybind11::arg("pairingHint"));
        cl.def("GetInitialPairingInstruction",
               (int (chip::DeviceLayer::ConfigurationManager::*)(char *, unsigned long)) &
                   chip::DeviceLayer::ConfigurationManager::GetInitialPairingInstruction,
               "C++: chip::DeviceLayer::ConfigurationManager::GetInitialPairingInstruction(char *, unsigned long) --> int",
               pybind11::arg("buf"), pybind11::arg("bufSize"));
        cl.def("GetSecondaryPairingHint",
               (int (chip::DeviceLayer::ConfigurationManager::*)(unsigned short &)) &
                   chip::DeviceLayer::ConfigurationManager::GetSecondaryPairingHint,
               "C++: chip::DeviceLayer::ConfigurationManager::GetSecondaryPairingHint(unsigned short &) --> int",
               pybind11::arg("pairingHint"));
        cl.def("GetSecondaryPairingInstruction",
               (int (chip::DeviceLayer::ConfigurationManager::*)(char *, unsigned long)) &
                   chip::DeviceLayer::ConfigurationManager::GetSecondaryPairingInstruction,
               "C++: chip::DeviceLayer::ConfigurationManager::GetSecondaryPairingInstruction(char *, unsigned long) --> int",
               pybind11::arg("buf"), pybind11::arg("bufSize"));
    }
}
