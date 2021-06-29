#include <setup_payload/SetupPayload.h> // chip::SetupPayload
#include <sstream>                      // __str__

#include <controller/CHIPDeviceController.h>
#include <functional>
#include <pybind11/pybind11.h>
#include <string>

#ifndef BINDER_PYBIND11_TYPE_CASTER
#define BINDER_PYBIND11_TYPE_CASTER
PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>)
PYBIND11_DECLARE_HOLDER_TYPE(T, T *)
PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

void bind_chip_2(std::function<pybind11::module &(std::string const & namespace_)> & M)
{
    { // chip::SetupPayload file:setup_payload/SetupPayload.h line:149
        pybind11::class_<chip::SetupPayload, std::shared_ptr<chip::SetupPayload>> cl(M("chip"), "SetupPayload", "");
        cl.def(pybind11::init([]() { return new chip::SetupPayload(); }));
        cl.def_readwrite("version", &chip::SetupPayload::version);
        cl.def_readwrite("vendorID", &chip::SetupPayload::vendorID);
        cl.def_readwrite("productID", &chip::SetupPayload::productID);
        cl.def_readwrite("commissioningFlow", &chip::SetupPayload::commissioningFlow);
        cl.def_readwrite("rendezvousInformation", &chip::SetupPayload::rendezvousInformation);
        cl.def_readwrite("discriminator", &chip::SetupPayload::discriminator);
        cl.def_readwrite("setUpPINCode", &chip::SetupPayload::setUpPINCode);
        cl.def("addOptionalVendorData",
               (int (chip::SetupPayload::*)(unsigned char, int)) & chip::SetupPayload::addOptionalVendorData,
               "A function to add an optional vendor data\n \n\n 7 bit [0-127] tag number\n \n\n String representation of data to "
               "add\n \n\n Returns a CHIP_ERROR on error, CHIP_NO_ERROR otherwise\n\nC++: "
               "chip::SetupPayload::addOptionalVendorData(unsigned char, int) --> int",
               pybind11::arg("tag"), pybind11::arg("data"));
        cl.def("addOptionalVendorData",
               (int (chip::SetupPayload::*)(unsigned char, int)) & chip::SetupPayload::addOptionalVendorData,
               "A function to add an optional vendor data\n \n\n 7 bit [0-127] tag number\n \n\n Integer representation of data to "
               "add\n \n\n Returns a CHIP_ERROR on error, CHIP_NO_ERROR otherwise\n\nC++: "
               "chip::SetupPayload::addOptionalVendorData(unsigned char, int) --> int",
               pybind11::arg("tag"), pybind11::arg("data"));
        cl.def("removeOptionalVendorData",
               (int (chip::SetupPayload::*)(unsigned char)) & chip::SetupPayload::removeOptionalVendorData,
               "A function to remove an optional vendor data\n \n\n 7 bit [0-127] tag number\n \n\n Returns a "
               "CHIP_ERROR_KEY_NOT_FOUND on error, CHIP_NO_ERROR otherwise\n\nC++: "
               "chip::SetupPayload::removeOptionalVendorData(unsigned char) --> int",
               pybind11::arg("tag"));
        cl.def("getAllOptionalVendorData", (int (chip::SetupPayload::*)() const) & chip::SetupPayload::getAllOptionalVendorData,
               "A function to retrieve the vector of OptionalQRCodeInfo infos\n \n\n Returns a vector of "
               "optionalQRCodeInfos\n\nC++: chip::SetupPayload::getAllOptionalVendorData() const --> int");
        cl.def("addSerialNumber", (int (chip::SetupPayload::*)(int)) & chip::SetupPayload::addSerialNumber,
               "A function to add a string serial number\n \n\n string serial number\n \n\n Returns a CHIP_ERROR on error, "
               "CHIP_NO_ERROR otherwise\n\nC++: chip::SetupPayload::addSerialNumber(int) --> int",
               pybind11::arg("serialNumber"));
        cl.def("addSerialNumber", (int (chip::SetupPayload::*)(unsigned int)) & chip::SetupPayload::addSerialNumber,
               "A function to add a uint32_t serial number\n \n\n uint32_t serial number\n \n\n Returns a CHIP_ERROR on error, "
               "CHIP_NO_ERROR otherwise\n\nC++: chip::SetupPayload::addSerialNumber(unsigned int) --> int",
               pybind11::arg("serialNumber"));
        cl.def("getSerialNumber", (int (chip::SetupPayload::*)(int &) const) & chip::SetupPayload::getSerialNumber,
               "A function to retrieve serial number as a string\n \n\n retrieved string serial number\n \n\n Returns a CHIP_ERROR "
               "on error, CHIP_NO_ERROR otherwise\n\nC++: chip::SetupPayload::getSerialNumber(int &) const --> int",
               pybind11::arg("outSerialNumber"));
        cl.def("removeSerialNumber", (int (chip::SetupPayload::*)()) & chip::SetupPayload::removeSerialNumber,
               "A function to remove the serial number from the payload\n \n\n Returns a CHIP_ERROR_KEY_NOT_FOUND on error, "
               "CHIP_NO_ERROR otherwise\n\nC++: chip::SetupPayload::removeSerialNumber() --> int");
        cl.def("isValidQRCodePayload", (bool (chip::SetupPayload::*)()) & chip::SetupPayload::isValidQRCodePayload,
               "C++: chip::SetupPayload::isValidQRCodePayload() --> bool");
        cl.def("isValidManualCode", (bool (chip::SetupPayload::*)()) & chip::SetupPayload::isValidManualCode,
               "C++: chip::SetupPayload::isValidManualCode() --> bool");
        cl.def("__eq__", (bool (chip::SetupPayload::*)(class chip::SetupPayload &)) & chip::SetupPayload::operator==,
               "C++: chip::SetupPayload::operator==(class chip::SetupPayload &) --> bool", pybind11::arg("input"));
    }
}
