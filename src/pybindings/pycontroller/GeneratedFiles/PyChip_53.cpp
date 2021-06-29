#include <core/CHIPTLV.h>
#include <core/CHIPTLVTypes.h>
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

void bind_PyChip_53(std::function<pybind11::module &(std::string const & namespace_)> & M)
{
    { // chip::TLV::TLVReader file:core/CHIPTLV.h line:93
        pybind11::class_<chip::TLV::TLVReader, std::shared_ptr<chip::TLV::TLVReader>> cl(
            M("chip::TLV"), "TLVReader",
            "Provides a memory efficient parser for data encoded in CHIP TLV format.\n\n TLVReader implements a forward-only, "
            "“pull-style” parser for CHIP TLV data.  The TLVReader\n object operates as a cursor that can be used to iterate over "
            "a sequence of TLV elements\n and interpret their contents.  When positioned on an element, applications can make "
            "calls\n to the reader's Get() methods to query the current element’s type and tag, and to extract\n any associated "
            "value.  The reader’s Next() method is used to advance from element to element.\n\n A TLVReader object is always "
            "positioned either before, on or after a TLV element.  When first\n initialized, a TLVReader is positioned immediately "
            "before the first element of the encoding.\n To begin reading, an application must make an initial call to the Next() "
            "method to position\n the reader on the first element.  When a container element is encountered--either a structure,\n "
            "an array or a path--the OpenContainer() or EnterContainer() methods can be used to iterate\n through the contents of "
            "the container.\n\n When the reader reaches the end of a TLV encoding, or the last element within a container,\n it "
            "signals the application by returning a CHIP_END_OF_TLV error from the Next() method.\n The reader will continue to "
            "return CHIP_END_OF_TLV until it is reinitialized, or the current\n container is exited (via CloseContainer() / "
            "ExitContainer()).\n\n A TLVReader object can parse data directly from a fixed input buffer, or from memory provided\n "
            "by a TLVBackingStore.");
        cl.def(pybind11::init([]() { return new chip::TLV::TLVReader(); }));
        cl.def_readwrite("ImplicitProfileId", &chip::TLV::TLVReader::ImplicitProfileId);
        cl.def("Init", (void (chip::TLV::TLVReader::*)(const class chip::TLV::TLVReader &)) & chip::TLV::TLVReader::Init,
               "Initializes a TLVReader object from another TLVReader object.\n\n \n  A read-only reference to the TLVReader to "
               "initialize\n                       this from.\n\n     \n\nC++: chip::TLV::TLVReader::Init(const class "
               "chip::TLV::TLVReader &) --> void",
               pybind11::arg("aReader"));
        cl.def("Init", (void (chip::TLV::TLVReader::*)(const unsigned char *, unsigned int)) & chip::TLV::TLVReader::Init,
               "Initializes a TLVReader object to read from a single input buffer.\n\n \n    A pointer to a buffer containing the "
               "TLV data to be parsed.\n \n\n The length of the TLV data to be parsed.\n\n     \n\nC++: "
               "chip::TLV::TLVReader::Init(const unsigned char *, unsigned int) --> void",
               pybind11::arg("data"), pybind11::arg("dataLen"));
        cl.def(
            "Init", [](chip::TLV::TLVReader & o, class chip::TLV::TLVBackingStore & a0) -> int { return o.Init(a0); }, "",
            pybind11::arg("backingStore"));
        cl.def("Init",
               (int (chip::TLV::TLVReader::*)(class chip::TLV::TLVBackingStore &, unsigned int)) & chip::TLV::TLVReader::Init,
               "Initializes a TLVReader object to read from a TLVBackingStore.\n\n Parsing begins at the backing store's start "
               "position and continues until the\n end of the data in the buffer, or maxLen bytes have been parsed.\n\n \n    A "
               "reference to a TLVBackingStore providing the TLV data to be parsed.\n \n\n          The maximum number of bytes to "
               "parse. Defaults to the amount of data\n                              in the input buffer.\n\n  #CHIP_NO_ERROR  If "
               "the method succeeded.\n  other           Other error codes returned by TLVBackingStore::OnInit().\n\nC++: "
               "chip::TLV::TLVReader::Init(class chip::TLV::TLVBackingStore &, unsigned int) --> int",
               pybind11::arg("backingStore"), pybind11::arg("maxLen"));
        cl.def("Next", (int (chip::TLV::TLVReader::*)()) & chip::TLV::TLVReader::Next,
               "Advances the TLVReader object to the next TLV element to be read.\n\n The Next() method positions the reader "
               "object on the next element in a TLV encoding that resides\n in the same containment context.  In particular, if "
               "the reader is positioned at the outer-most\n level of a TLV encoding, calling Next() will advance the reader to "
               "the next, top-most element.\n If the reader is positioned within a TLV container element (a structure, array or "
               "path), calling\n Next() will advance the reader to the next member element of the container.\n\n Since Next() "
               "constrains reader motion to the current containment context, calling Next() when\n the reader is positioned on a "
               "container element will advance  the container, skipping\n its member elements (and the members of any nested "
               "containers) until it reaches the first element\n after the container.\n\n When there are no further elements "
               "within a particular containment context the Next() method will\n return a #CHIP_END_OF_TLV error and the position "
               "of the reader will remain unchanged.\n\n  #CHIP_NO_ERROR              If the reader was successfully positioned on "
               "a new element.\n  #CHIP_END_OF_TLV            If no further elements are available.\n  #CHIP_ERROR_TLV_UNDERRUN    "
               "If the underlying TLV encoding ended prematurely.\n  #CHIP_ERROR_INVALID_TLV_ELEMENT\n                             "
               "         If the reader encountered an invalid or unsupported TLV element\n                                      "
               "type.\n  #CHIP_ERROR_INVALID_TLV_TAG If the reader encountered a TLV tag in an invalid context.\n  "
               "#CHIP_ERROR_UNKNOWN_IMPLICIT_TLV_TAG\n                                      If the reader encountered a "
               "implicitly-encoded TLV tag for which\n                                      the corresponding profile id is "
               "unknown.\n  other                        Other CHIP or platform error codes returned by the configured\n           "
               "                           TLVBackingStore.\n\n     \n\nC++: chip::TLV::TLVReader::Next() --> int");
        cl.def(
            "Next", (int (chip::TLV::TLVReader::*)(enum chip::TLV::TLVType, unsigned long long)) & chip::TLV::TLVReader::Next,
            "Advances the TLVReader object to the next TLV element to be read, asserting the type and tag of\n the new "
            "element.\n\n The Next(TLVType expectedType, uint64_t expectedTag) method is a convenience method that has the\n same "
            "behavior as Next(), but also verifies that the type and tag of the new TLV element match\n the supplied "
            "arguments.\n\n \n              The expected data type for the next element.\n \n\n               The expected tag for "
            "the next element.\n\n  #CHIP_NO_ERROR              If the reader was successfully positioned on a new element.\n  "
            "#CHIP_END_OF_TLV            If no further elements are available.\n  #CHIP_ERROR_WRONG_TLV_TYPE  If the type of the "
            "new element does not match the value\n                                      of the  argument.\n  "
            "#CHIP_ERROR_UNEXPECTED_TLV_ELEMENT\n                                      If the tag associated with the new element "
            "does not match the\n                                      value of the  argument.\n  #CHIP_ERROR_TLV_UNDERRUN    If "
            "the underlying TLV encoding ended prematurely.\n  #CHIP_ERROR_INVALID_TLV_ELEMENT\n                                   "
            "   If the reader encountered an invalid or unsupported TLV\n                                      element type.\n  "
            "#CHIP_ERROR_INVALID_TLV_TAG If the reader encountered a TLV tag in an invalid context.\n  other                       "
            " Other CHIP or platform error codes returned by the configured\n                                      "
            "TLVBackingStore.\n\n     \n\nC++: chip::TLV::TLVReader::Next(enum chip::TLV::TLVType, unsigned long long) --> int",
            pybind11::arg("expectedType"), pybind11::arg("expectedTag"));
        cl.def("GetType", (enum chip::TLV::TLVType(chip::TLV::TLVReader::*)() const) & chip::TLV::TLVReader::GetType,
               "Returns the type of the current TLV element.\n\n \n      A TLVType value describing the data type of the current "
               "TLV element.  If the reader\n              is not positioned on a TLV element, the return value will be "
               "kTLVType_NotSpecified.\n\nC++: chip::TLV::TLVReader::GetType() const --> enum chip::TLV::TLVType");
        cl.def(
            "GetTag", (unsigned long long (chip::TLV::TLVReader::*)() const) & chip::TLV::TLVReader::GetTag,
            "Returns the tag associated with current TLV element.\n\n The value returned by GetTag() can be used with the tag "
            "utility functions (IsProfileTag(),\n IsContextTag(), ProfileIdFromTag(), etc.) to determine the type of tag and to "
            "extract various tag\n field values.\n\n \n If the reader is not positioned on a TLV element when GetTag() is called, "
            "the return value\n is undefined. Therefore whenever the position of the reader is uncertain applications should "
            "call\n GetType() to determine if the reader is position on an element (GetType() != kTLVType_NotSpecified)\n before "
            "calling GetTag().\n\n \n      An unsigned integer containing information about the tag associated with the current\n  "
            "            TLV element.\n\nC++: chip::TLV::TLVReader::GetTag() const --> unsigned long long");
        cl.def("GetLength", (unsigned int (chip::TLV::TLVReader::*)() const) & chip::TLV::TLVReader::GetLength,
               "Returns the length of data associated with current TLV element.\n\n Data length only applies to elements of type "
               "UTF8 string or byte string.  For UTF8 strings, the\n value returned is the number of bytes in the string, not the "
               "number of characters.\n\n \n      The length (in bytes) of data associated with the current TLV element, or 0 if "
               "the\n              current element is not a UTF8 string or byte string, or if the reader is not\n              "
               "positioned on an element.\n\nC++: chip::TLV::TLVReader::GetLength() const --> unsigned int");
        cl.def("GetControlByte", (unsigned short (chip::TLV::TLVReader::*)() const) & chip::TLV::TLVReader::GetControlByte,
               "Returns the control byte associated with current TLV element.\n\n Ideally, nobody ever needs to know about the "
               "control byte and only the\n internal implementation of TLV should have access to it. But, nevertheless,\n having "
               "access to the control byte is helpful for debugging purposes by the\n TLV Debug Utilities (that try to decode the "
               "tag control byte when pretty\n printing the TLV buffer contents).\n\n \n Unless you really know what you are "
               "doing, please refrain from using\n this method and the associated control byte information.\n\n \n      An "
               "unsigned integer containing the control byte associated with\n              the current TLV element. "
               "kTLVControlByte_NotSpecified is\n              returned if the reader is not positioned  an element.\n\nC++: "
               "chip::TLV::TLVReader::GetControlByte() const --> unsigned short");
        cl.def("Get", (int (chip::TLV::TLVReader::*)(bool &)) & chip::TLV::TLVReader::Get,
               "Get the value of the current element as a bool type.\n\n \n                       Receives the value associated "
               "with current TLV element.\n\n  #CHIP_NO_ERROR              If the method succeeded.\n  #CHIP_ERROR_WRONG_TLV_TYPE  "
               "If the current element is not a TLV boolean type, or the\n                                      reader is not "
               "positioned on an element.\n\nC++: chip::TLV::TLVReader::Get(bool &) --> int",
               pybind11::arg("v"));
        cl.def(
            "Get", (int (chip::TLV::TLVReader::*)(signed char &)) & chip::TLV::TLVReader::Get,
            "Get the value of the current element as an 8-bit signed integer.\n\n If the encoded integer value is larger than the "
            "output data type the resultant value will be\n truncated.\n\n \n                       Receives the value associated "
            "with current TLV element.\n\n  #CHIP_NO_ERROR              If the method succeeded.\n  #CHIP_ERROR_WRONG_TLV_TYPE  If "
            "the current element is not a TLV integer type (signed or\n                                      unsigned), or the "
            "reader is not positioned on an element.\n\n     \n\nC++: chip::TLV::TLVReader::Get(signed char &) --> int",
            pybind11::arg("v"));
        cl.def(
            "Get", (int (chip::TLV::TLVReader::*)(short &)) & chip::TLV::TLVReader::Get,
            "Get the value of the current element as a 16-bit signed integer.\n\n If the encoded integer value is larger than the "
            "output data type the resultant value will be\n truncated.\n\n \n                       Receives the value associated "
            "with current TLV element.\n\n  #CHIP_NO_ERROR              If the method succeeded.\n  #CHIP_ERROR_WRONG_TLV_TYPE  If "
            "the current element is not a TLV integer type (signed or\n                                      unsigned), or the "
            "reader is not positioned on an element.\n\n     \n\nC++: chip::TLV::TLVReader::Get(short &) --> int",
            pybind11::arg("v"));
        cl.def(
            "Get", (int (chip::TLV::TLVReader::*)(int &)) & chip::TLV::TLVReader::Get,
            "Get the value of the current element as a 32-bit signed integer.\n\n If the encoded integer value is larger than the "
            "output data type the resultant value will be\n truncated.\n\n \n                       Receives the value associated "
            "with current TLV element.\n\n  #CHIP_NO_ERROR              If the method succeeded.\n  #CHIP_ERROR_WRONG_TLV_TYPE  If "
            "the current element is not a TLV integer type (signed or\n                                      unsigned), or the "
            "reader is not positioned on an element.\n\n     \n\nC++: chip::TLV::TLVReader::Get(int &) --> int",
            pybind11::arg("v"));
        cl.def(
            "Get", (int (chip::TLV::TLVReader::*)(long long &)) & chip::TLV::TLVReader::Get,
            "Get the value of the current element as a 64-bit signed integer.\n\n If the encoded integer value is larger than the "
            "output data type the resultant value will be\n truncated.\n\n \n                       Receives the value associated "
            "with current TLV element.\n\n  #CHIP_NO_ERROR              If the method succeeded.\n  #CHIP_ERROR_WRONG_TLV_TYPE  If "
            "the current element is not a TLV integer type (signed or\n                                      unsigned), or the "
            "reader is not positioned on an element.\n\n     \n\nC++: chip::TLV::TLVReader::Get(long long &) --> int",
            pybind11::arg("v"));
        cl.def("Get", (int (chip::TLV::TLVReader::*)(unsigned char &)) & chip::TLV::TLVReader::Get,
               "Get the value of the current element as an 8-bit unsigned integer.\n\n If the encoded integer value is larger than "
               "the output data type the resultant value will be\n truncated.  Similarly, if the encoded integer value is "
               "negative, the value will be converted\n to unsigned.\n\n \n                       Receives the value associated "
               "with current TLV element.\n\n  #CHIP_NO_ERROR              If the method succeeded.\n  #CHIP_ERROR_WRONG_TLV_TYPE  "
               "If the current element is not a TLV integer type (signed or\n                                      unsigned), or "
               "the reader is not positioned on an element.\n\n     \n\nC++: chip::TLV::TLVReader::Get(unsigned char &) --> int",
               pybind11::arg("v"));
        cl.def("Get", (int (chip::TLV::TLVReader::*)(unsigned short &)) & chip::TLV::TLVReader::Get,
               "Get the value of the current element as a 16-bit unsigned integer.\n\n If the encoded integer value is larger than "
               "the output data type the resultant value will be\n truncated.  Similarly, if the encoded integer value is "
               "negative, the value will be converted\n to unsigned.\n\n \n                       Receives the value associated "
               "with current TLV element.\n\n  #CHIP_NO_ERROR              If the method succeeded.\n  #CHIP_ERROR_WRONG_TLV_TYPE  "
               "If the current element is not a TLV integer type (signed or\n                                      unsigned), or "
               "the reader is not positioned on an element.\n\n     \n\nC++: chip::TLV::TLVReader::Get(unsigned short &) --> int",
               pybind11::arg("v"));
        cl.def("Get", (int (chip::TLV::TLVReader::*)(unsigned int &)) & chip::TLV::TLVReader::Get,
               "Get the value of the current element as a 32-bit unsigned integer.\n\n If the encoded integer value is larger than "
               "the output data type the resultant value will be\n truncated.  Similarly, if the encoded integer value is "
               "negative, the value will be converted\n to unsigned.\n\n \n                       Receives the value associated "
               "with current TLV element.\n\n  #CHIP_NO_ERROR              If the method succeeded.\n  #CHIP_ERROR_WRONG_TLV_TYPE  "
               "If the current element is not a TLV integer type (signed or\n     unsigned), or the reader is not positioned on an "
               "element.\n\n     \n\nC++: chip::TLV::TLVReader::Get(unsigned int &) --> int",
               pybind11::arg("v"));
        cl.def("Get", (int (chip::TLV::TLVReader::*)(unsigned long long &)) & chip::TLV::TLVReader::Get,
               "Get the value of the current element as a 64-bit unsigned integer.\n\n If the encoded integer value is negative, "
               "the value will be converted to unsigned.\n\n \n                       Receives the value associated with current "
               "TLV element.\n\n  #CHIP_NO_ERROR              If the method succeeded.\n  #CHIP_ERROR_WRONG_TLV_TYPE  If the "
               "current element is not a TLV integer type (signed or\n                                      unsigned), or the "
               "reader is not positioned on an element.\n\n     \n\nC++: chip::TLV::TLVReader::Get(unsigned long long &) --> int",
               pybind11::arg("v"));
        cl.def(
            "Get", (int (chip::TLV::TLVReader::*)(double &)) & chip::TLV::TLVReader::Get,
            "Get the value of the current element as a double-precision floating point number.\n\n \n                       "
            "Receives the value associated with current TLV element.\n\n  #CHIP_NO_ERROR              If the method succeeded.\n  "
            "#CHIP_ERROR_WRONG_TLV_TYPE  If the current element is not a TLV floating point type, or\n                             "
            "         the reader is not positioned on an element.\n\n     \n\nC++: chip::TLV::TLVReader::Get(double &) --> int",
            pybind11::arg("v"));
        cl.def(
            "Get", (int (chip::TLV::TLVReader::*)(float &)) & chip::TLV::TLVReader::Get,
            "Get the value of the current element as a single-precision floating point number.\n\n \n                       "
            "Receives the value associated with current TLV element.\n\n  #CHIP_NO_ERROR              If the method succeeded.\n  "
            "#CHIP_ERROR_WRONG_TLV_TYPE  If the current element is not a TLV floating point type, or\n                             "
            "         the reader is not positioned on an element.\n\n     \n\nC++: chip::TLV::TLVReader::Get(float &) --> int",
            pybind11::arg("v"));
        cl.def(
            "GetBytes", (int (chip::TLV::TLVReader::*)(unsigned char *, unsigned int)) & chip::TLV::TLVReader::GetBytes,
            "Get the value of the current byte or UTF8 string element.\n\n To determine the required input buffer size, call the "
            "GetLength() method before calling GetBytes().\n\n \n The data output by this method is NOT null-terminated.\n\n \n    "
            "                  A pointer to a buffer to receive the string data.\n \n\n                  The size in bytes of the "
            "buffer pointed to by \n\n  #CHIP_NO_ERROR              If the method succeeded.\n  #CHIP_ERROR_WRONG_TLV_TYPE  If the "
            "current element is not a TLV byte or UTF8 string, or\n                                      the reader is not "
            "positioned on an element.\n  #CHIP_ERROR_BUFFER_TOO_SMALL\n                                      If the supplied "
            "buffer is too small to hold the data associated\n                                      with the current element.\n  "
            "#CHIP_ERROR_TLV_UNDERRUN    If the underlying TLV encoding ended prematurely.\n  other                        Other "
            "CHIP or platform error codes returned by the configured\n                                      TLVBackingStore.\n\n   "
            "  \n\nC++: chip::TLV::TLVReader::GetBytes(unsigned char *, unsigned int) --> int",
            pybind11::arg("buf"), pybind11::arg("bufSize"));
        cl.def(
            "DupBytes", (int (chip::TLV::TLVReader::*)(unsigned char *&, unsigned int &)) & chip::TLV::TLVReader::DupBytes,
            "Allocates and returns a buffer containing the value of the current byte or UTF8 string.\n\n This method creates a "
            "buffer for and returns a copy of the data associated with the byte\n or UTF-8 string element at the current position. "
            "Memory for the buffer is obtained with\n Platform::MemoryAlloc() and should be freed with Platform::MemoryFree() by "
            "the caller when\n it is no longer needed.\n\n \n The data returned by this method is NOT null-terminated.\n\n \n      "
            "                A reference to a pointer to which a heap-allocated buffer of\n                                       "
            "bytes will be assigned on success.\n \n\n                  A reference to storage for the size, in bytes, of  on\n    "
            "                                  success.\n\n  #CHIP_NO_ERROR              If the method succeeded.\n  "
            "#CHIP_ERROR_WRONG_TLV_TYPE  If the current element is not a TLV byte or UTF8 string, or\n                             "
            "         the reader is not positioned on an element.\n  #CHIP_ERROR_NO_MEMORY       If memory could not be allocated "
            "for the output buffer.\n  #CHIP_ERROR_TLV_UNDERRUN    If the underlying TLV encoding ended prematurely.\n  other      "
            "                  Other CHIP or platform error codes returned by the configured\n                                     "
            " TLVBackingStore.\n\n     \n\nC++: chip::TLV::TLVReader::DupBytes(unsigned char *&, unsigned int &) --> int",
            pybind11::arg("buf"), pybind11::arg("dataLen"));
        cl.def("GetString", (int (chip::TLV::TLVReader::*)(char *, unsigned int)) & chip::TLV::TLVReader::GetString,
               "Get the value of the current byte or UTF8 string element as a null terminated string.\n\n To determine the "
               "required input buffer size, call the GetLength() method before calling GetBytes().\n The input buffer should be at "
               "least one byte bigger than the string length to accommodate the null\n character.\n\n \n                      A "
               "pointer to a buffer to receive the byte string data.\n \n\n                  The size in bytes of the buffer "
               "pointed to by \n\n  #CHIP_NO_ERROR              If the method succeeded.\n  #CHIP_ERROR_WRONG_TLV_TYPE  If the "
               "current element is not a TLV byte or UTF8 string, or\n                                      the reader is not "
               "positioned on an element.\n  #CHIP_ERROR_BUFFER_TOO_SMALL\n                                      If the supplied "
               "buffer is too small to hold the data associated\n                                      with the current element.\n "
               " #CHIP_ERROR_TLV_UNDERRUN    If the underlying TLV encoding ended prematurely.\n  other                        "
               "Other CHIP or platform error codes returned by the configured\n                                      "
               "TLVBackingStore.\n\n     \n\nC++: chip::TLV::TLVReader::GetString(char *, unsigned int) --> int",
               pybind11::arg("buf"), pybind11::arg("bufSize"));
        cl.def("DupString", (int (chip::TLV::TLVReader::*)(char *&)) & chip::TLV::TLVReader::DupString,
               "Allocates and returns a buffer containing the null-terminated value of the current byte or UTF8\n string.\n\n This "
               "method creates a buffer for and returns a null-terminated copy of the data associated with\n the byte or UTF-8 "
               "string element at the current position. Memory for the buffer is obtained with\n Platform::MemoryAlloc() and "
               "should be freed with chip::Platform::MemoryFree() by the caller when\n it is no longer needed.\n\n \n              "
               "        A reference to a pointer to which a heap-allocated buffer of\n                                      will "
               "be assigned on success.\n\n  #CHIP_NO_ERROR              If the method succeeded.\n  #CHIP_ERROR_WRONG_TLV_TYPE  "
               "If the current element is not a TLV byte or UTF8 string, or\n                                      the reader is "
               "not positioned on an element.\n  #CHIP_ERROR_NO_MEMORY       If memory could not be allocated for the output "
               "buffer.\n  #CHIP_ERROR_TLV_UNDERRUN    If the underlying TLV encoding ended prematurely.\n  other                  "
               "     Other CHIP or platform error codes returned by the configured\n                                      "
               "TLVBackingStore.\n\n     \n\nC++: chip::TLV::TLVReader::DupString(char *&) --> int",
               pybind11::arg("buf"));
        cl.def("GetDataPtr", (int (chip::TLV::TLVReader::*)(const unsigned char *&)) & chip::TLV::TLVReader::GetDataPtr,
               "Get a pointer to the initial encoded byte of a TLV byte or UTF8 string element.\n\n This method returns a direct "
               "pointer the encoded string value within the underlying input buffer.\n To succeed, the method requires that the "
               "entirety of the string value be present in a single buffer.\n Otherwise the method returns "
               "#CHIP_ERROR_TLV_UNDERRUN.  This makes the method of limited use when\n reading data from multiple discontiguous "
               "buffers.\n\n \n                     A reference to a const pointer that will receive a pointer to\n                "
               "                      the underlying string data.\n\n  #CHIP_NO_ERROR              If the method succeeded.\n  "
               "#CHIP_ERROR_WRONG_TLV_TYPE  If the current element is not a TLV byte or UTF8 string, or the\n                      "
               "                reader is not positioned on an element.\n  #CHIP_ERROR_TLV_UNDERRUN    If the underlying TLV "
               "encoding ended prematurely or the value\n                                      of the current string element is "
               "not contained within a single\n                                      contiguous buffer.\n  other                   "
               "     Other CHIP or platform error codes returned by the configured\n                                      "
               "TLVBackingStore.\n\n     \n\nC++: chip::TLV::TLVReader::GetDataPtr(const unsigned char *&) --> int",
               pybind11::arg("data"));
        cl.def("EnterContainer", (int (chip::TLV::TLVReader::*)(enum chip::TLV::TLVType &)) & chip::TLV::TLVReader::EnterContainer,
               "Prepares a TLVReader object for reading the members of TLV container element.\n\n The EnterContainer() method "
               "prepares the current TLVReader object to begin reading the member\n elements of a TLV container (a structure, "
               "array or path). For every call to EnterContainer()\n applications must make a corresponding call to "
               "ExitContainer().\n\n When EnterContainer() is called the TLVReader object must be positioned on the container "
               "element\n to be read.  The method takes as an argument a reference to a TLVType value which will be used\n to save "
               "the context of the reader while it is reading the container.\n\n When the EnterContainer() method returns, the "
               "reader is positioned immediately  the\n first member of the container. Repeatedly calling Next() will advance the "
               "reader through the members\n of the collection until the end is reached, at which point the reader will return "
               "CHIP_END_OF_TLV.\n\n Once the application has finished reading a container it can continue reading the elements "
               "after\n the container by calling the ExitContainer() method.\n\n \n       A reference to a TLVType value that will "
               "receive the context\n                                      of the reader.\n\n  #CHIP_NO_ERROR              If the "
               "method succeeded.\n  #CHIP_ERROR_INCORRECT_STATE If the current element is not positioned on a container "
               "element.\n\n     \n\nC++: chip::TLV::TLVReader::EnterContainer(enum chip::TLV::TLVType &) --> int",
               pybind11::arg("outerContainerType"));
        cl.def(
            "ExitContainer", (int (chip::TLV::TLVReader::*)(enum chip::TLV::TLVType)) & chip::TLV::TLVReader::ExitContainer,
            "Completes the reading of a TLV container and prepares a TLVReader object to read elements\n after the container.\n\n "
            "The ExitContainer() method restores the state of a TLVReader object after a call to\n EnterContainer().  For every "
            "call to EnterContainer() applications must make a corresponding\n call to ExitContainer(), passing the context value "
            "returned by the EnterContainer() method.\n\n When ExitContainer() returns, the reader is positioned immediately "
            "before the first element that\n follows the container.  From this point an application can use the Next() method to "
            "advance\n through any remaining elements.\n\n Once EnterContainer() has been called, applications can call "
            "ExitContainer() on a reader at any\n point in time, regardless of whether all elements in the underlying container "
            "have been read.\n\n \n Any changes made to the configuration of the reader between the calls to EnterContainer()\n "
            "and ExitContainer() are NOT undone by the call to ExitContainer().  For example, a change to the\n implicit profile "
            "id ( will not be reversed when a container is exited.  Thus\n it is the application's responsibility to adjust the "
            "configuration accordingly at the appropriate\n times.\n\n \n        The TLVType value that was returned by the "
            "EnterContainer() method.\n\n  #CHIP_NO_ERROR              If the method succeeded.\n  #CHIP_ERROR_INCORRECT_STATE If "
            "OpenContainer() has not been called on the reader, or if\n                                      the container reader "
            "does not match the one passed to the\n                                      OpenContainer() method.\n  "
            "#CHIP_ERROR_TLV_UNDERRUN    If the underlying TLV encoding ended prematurely.\n  #CHIP_ERROR_INVALID_TLV_ELEMENT\n    "
            "                                  If the reader encountered an invalid or unsupported TLV element type.\n  "
            "#CHIP_ERROR_INVALID_TLV_TAG If the reader encountered a TLV tag in an invalid context.\n  other                       "
            " Other CHIP or platform error codes returned by the configured\n                                      "
            "TLVBackingStore.\n\n     \n\nC++: chip::TLV::TLVReader::ExitContainer(enum chip::TLV::TLVType) --> int",
            pybind11::arg("outerContainerType"));
        cl.def(
            "OpenContainer", (int (chip::TLV::TLVReader::*)(class chip::TLV::TLVReader &)) & chip::TLV::TLVReader::OpenContainer,
            "Initializes a new TLVReader object for reading the members of a TLV container element.\n\n The OpenContainer() method "
            "initializes a new TLVReader object for reading the member elements of a\n TLV container (a structure, array or path). "
            " When OpenContainer() is called, the current TLVReader\n object must be positioned on the container element to be "
            "read.  The method takes as its sole argument\n a reference to a new reader that will be initialized to read the "
            "container.  This reader is known as\n the container reader while the reader on which OpenContainer() is called is "
            "known as the parent\n reader.\n\n When the OpenContainer() method returns, the container reader is positioned "
            "immediately before the\n first member of the container. Calling Next() on the container reader will advance through "
            "the members\n of the collection until the end is reached, at which point the reader will return CHIP_END_OF_TLV.\n\n "
            "While the container reader is open, applications must not make calls on or otherwise alter the state\n of the parent "
            "reader.  Once an application has finished using the container reader it must close it\n by calling CloseContainer() "
            "on the parent reader, passing the container reader as an argument.\n Applications may close the container reader at "
            "any point, with or without reading all elements\n contained in the underlying container. After the container reader "
            "is closed, applications may\n continue their use of the parent reader.\n\n The container reader inherits various "
            "configuration properties from the parent reader.  These are:\n\n \n The implicit profile id (ImplicitProfileId)\n "
            "\n\n The application data pointer (AppData)\n \n\n The GetNextBuffer function pointer\n\n \n The EnterContainer() "
            "method can be used as an alternative to OpenContainer() to read a\n container element without initializing a new "
            "reader object.\n\n \n          A reference to a TLVReader object that will be initialized for\n                       "
            "               reading the members of the current container element. Any data\n                                      "
            "associated with the supplied object is overwritten.\n\n  #CHIP_NO_ERROR              If the method succeeded.\n  "
            "#CHIP_ERROR_INCORRECT_STATE If the current element is not positioned on a container element.\n\n     \n\nC++: "
            "chip::TLV::TLVReader::OpenContainer(class chip::TLV::TLVReader &) --> int",
            pybind11::arg("containerReader"));
        cl.def("CloseContainer",
               (int (chip::TLV::TLVReader::*)(class chip::TLV::TLVReader &)) & chip::TLV::TLVReader::CloseContainer,
               "Completes the reading of a TLV container after a call to OpenContainer().\n\n The CloseContainer() method restores "
               "the state of a parent TLVReader object after a call to\n OpenContainer().  For every call to OpenContainer() "
               "applications must make a corresponding\n call to CloseContainer(), passing a reference to the same container "
               "reader to both methods.\n\n When CloseContainer() returns, the parent reader is positioned immediately before the "
               "first\n element that follows the container.  From this point an application can use the Next() method\n to advance "
               "through any remaining elements.\n\n Applications can call close CloseContainer() on a parent reader at any point "
               "in time, regardless\n of whether all elements in the underlying container have been read. After CloseContainer() "
               "has\n been called, the application should consider the container reader 'de-initialized' and must not\n use it "
               "further without re-initializing it.\n\n \n           A reference to the TLVReader object that was supplied to "
               "the\n                                      OpenContainer() method.\n\n  #CHIP_NO_ERROR              If the method "
               "succeeded.\n  #CHIP_ERROR_INCORRECT_STATE If OpenContainer() has not been called on the reader, or if\n            "
               "                          the container reader does not match the one passed to the\n                              "
               "        OpenContainer() method.\n  #CHIP_ERROR_TLV_UNDERRUN    If the underlying TLV encoding ended prematurely.\n "
               " #CHIP_ERROR_INVALID_TLV_ELEMENT\n                                      If the reader encountered an invalid or "
               "unsupported TLV\n                                      element type.\n  #CHIP_ERROR_INVALID_TLV_TAG If the reader "
               "encountered a TLV tag in an invalid context.\n  other                        Other CHIP or platform error codes "
               "returned by the configured\n                                      TLVBackingStore.\n\n     \n\nC++: "
               "chip::TLV::TLVReader::CloseContainer(class chip::TLV::TLVReader &) --> int",
               pybind11::arg("containerReader"));
        cl.def("GetContainerType",
               (enum chip::TLV::TLVType(chip::TLV::TLVReader::*)() const) & chip::TLV::TLVReader::GetContainerType,
               "Returns the type of the container within which the TLVReader is currently reading.\n\n The GetContainerType() "
               "method returns the type of the TLV container within which the TLVReader\n is reading.  If the TLVReader is "
               "positioned at the outer-most level of a TLV encoding (i.e. before,\n on or after the outer-most TLV element), the "
               "method will return kTLVType_NotSpecified.\n\n \n  The TLVType of the current container, or kTLVType_NotSpecified "
               "if the TLVReader is not\n          positioned within a container.\n\nC++: chip::TLV::TLVReader::GetContainerType() "
               "const --> enum chip::TLV::TLVType");
        cl.def(
            "VerifyEndOfContainer", (int (chip::TLV::TLVReader::*)()) & chip::TLV::TLVReader::VerifyEndOfContainer,
            "Verifies that the TLVReader object is at the end of a TLV container.\n\n The VerifyEndOfContainer() method verifies "
            "that there are no further TLV elements to be read\n within the current TLV container.  This is a convenience method "
            "that is equivalent to calling\n Next() and checking for a return value of CHIP_END_OF_TLV.\n\n \n When there are more "
            "TLV elements in the collection, this method will change the position\n of the reader.\n\n  #CHIP_NO_ERROR             "
            " If there are no further TLV elements to be read.\n  #CHIP_ERROR_UNEXPECTED_TLV_ELEMENT\n                             "
            "         If another TLV element was found in the collection.\n  #CHIP_ERROR_TLV_UNDERRUN    If the underlying TLV "
            "encoding ended prematurely.\n  #CHIP_ERROR_INVALID_TLV_ELEMENT\n                                      If the reader "
            "encountered an invalid or unsupported TLV element\n                                      type.\n  "
            "#CHIP_ERROR_INVALID_TLV_TAG If the reader encountered a TLV tag in an invalid context.\n  other                       "
            " Other CHIP or platform error codes returned by the configured\n                                      "
            "TLVBackingStore.\n\n     \n\nC++: chip::TLV::TLVReader::VerifyEndOfContainer() --> int");
        cl.def("GetLengthRead", (unsigned int (chip::TLV::TLVReader::*)() const) & chip::TLV::TLVReader::GetLengthRead,
               "Returns the total number of bytes read since the reader was initialized.\n\n \n Total number of bytes read since "
               "the reader was initialized.\n\nC++: chip::TLV::TLVReader::GetLengthRead() const --> unsigned int");
        cl.def("GetRemainingLength", (unsigned int (chip::TLV::TLVReader::*)() const) & chip::TLV::TLVReader::GetRemainingLength,
               "Returns the total number of bytes that can be read until the max read length is reached.\n\n \n Total number of "
               "bytes that can be read until the max read length is reached.\n\nC++: chip::TLV::TLVReader::GetRemainingLength() "
               "const --> unsigned int");
        cl.def("GetReadPoint", (const unsigned char * (chip::TLV::TLVReader::*) () const) & chip::TLV::TLVReader::GetReadPoint,
               "Gets the point in the underlying input buffer that corresponds to the reader's current position.\n\n \n Depending "
               "on the type of the current element, GetReadPoint() will return a pointer that\n is some number of bytes *after* "
               "the first byte of the element.  For string types (UTF8 and byte\n strings), the pointer will point to the first "
               "byte of the string's value.  For container types\n (structures, arrays and paths), the pointer will point to the "
               "first member element within the\n container. For all other types, the pointer will point to the byte immediately "
               "after the element's\n encoding.\n\n \n A pointer into underlying input buffer that corresponds to the reader's "
               "current position.\n\nC++: chip::TLV::TLVReader::GetReadPoint() const --> const unsigned char *",
               pybind11::return_value_policy::automatic);
        cl.def("Skip", (int (chip::TLV::TLVReader::*)()) & chip::TLV::TLVReader::Skip,
               "Advances the TLVReader object to immediately after the current TLV element.\n\n The Skip() method positions the "
               "reader object immediately  the current TLV element, such\n that a subsequent call to Next() will advance the "
               "reader to the following element.  Like Next(),\n if the reader is positioned on a container element at the time of "
               "the call, the members of the\n container will be skipped.  If the reader is not positioned on any element, its "
               "position remains\n unchanged.\n\n  #CHIP_NO_ERROR              If the reader was successfully positioned on a new "
               "element.\n  #CHIP_END_OF_TLV            If no further elements are available.\n  #CHIP_ERROR_TLV_UNDERRUN    If "
               "the underlying TLV encoding ended prematurely.\n  #CHIP_ERROR_INVALID_TLV_ELEMENT\n                                "
               "      If the reader encountered an invalid or unsupported TLV\n                                      element "
               "type.\n  #CHIP_ERROR_INVALID_TLV_TAG If the reader encountered a TLV tag in an invalid context.\n  other           "
               "             Other CHIP or platform error codes returned by the configured\n                                      "
               "TLVBackingStore.\n\n     \n\nC++: chip::TLV::TLVReader::Skip() --> int");
        cl.def("FindElementWithTag",
               (int (chip::TLV::TLVReader::*)(const unsigned long long, class chip::TLV::TLVReader &) const) &
                   chip::TLV::TLVReader::FindElementWithTag,
               "Position the destination reader on the next element with the given tag within this reader's current container "
               "context\n\n \n             The destination context tag value\n \n\n               The destination TLV reader value "
               "that was located by given tag\n\n  #CHIP_NO_ERROR              If the reader was successfully positioned at the "
               "given tag\n  #CHIP_END_OF_TLV            If the given tag cannot be found\n  other                       Other "
               "CHIP or platform error codes\n\nC++: chip::TLV::TLVReader::FindElementWithTag(const unsigned long long, class "
               "chip::TLV::TLVReader &) const --> int",
               pybind11::arg("tagInApiForm"), pybind11::arg("destReader"));
        cl.def("assign",
               (class chip::TLV::TLVReader & (chip::TLV::TLVReader::*) (const class chip::TLV::TLVReader &) ) &
                   chip::TLV::TLVReader::operator=,
               "C++: chip::TLV::TLVReader::operator=(const class chip::TLV::TLVReader &) --> class chip::TLV::TLVReader &",
               pybind11::return_value_policy::automatic, pybind11::arg(""));
    }
}
