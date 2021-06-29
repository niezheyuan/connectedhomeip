#include <core/CHIPTLVTags.h>
#include <core/CHIPTLVTypes.h>

#include <functional>
#include <pybind11/pybind11.h>
#include <string>

#ifndef BINDER_PYBIND11_TYPE_CASTER
#define BINDER_PYBIND11_TYPE_CASTER
PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>)
PYBIND11_DECLARE_HOLDER_TYPE(T, T *)
PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

void bind_PyChip_51(std::function<pybind11::module &(std::string const & namespace_)> & M)
{
    // chip::TLV::ProfileTag(unsigned int, unsigned int) file:core/CHIPTLVTags.h line:89
    M("chip::TLV")
        .def("ProfileTag", (unsigned long long (*)(unsigned int, unsigned int)) & chip::TLV::ProfileTag,
             "Generates the API representation of a profile-specific TLV tag from a profile id and tag number\n\n \n       The id "
             "of the profile within which the tag is defined.\n \n\n          The profile-specific tag number assigned to the "
             "tag.\n \n\n                      A 64-bit integer representing the tag.\n\nC++: chip::TLV::ProfileTag(unsigned int, "
             "unsigned int) --> unsigned long long",
             pybind11::arg("profileId"), pybind11::arg("tagNum"));

    // chip::TLV::ProfileTag(unsigned short, unsigned short, unsigned int) file:core/CHIPTLVTags.h line:102
    M("chip::TLV")
        .def("ProfileTag", (unsigned long long (*)(unsigned short, unsigned short, unsigned int)) & chip::TLV::ProfileTag,
             "Generates the API representation of a profile-specific TLV tag from a vendor id, profile number and tag number\n\n "
             "\n        The id of the vendor that defined the tag.\n \n\n      The vendor assigned number for the profile within "
             "which the tag is defined.\n \n\n          The profile-specific tag number assigned to the tag.\n \n\n                "
             "      A 64-bit integer representing the tag.\n\nC++: chip::TLV::ProfileTag(unsigned short, unsigned short, unsigned "
             "int) --> unsigned long long",
             pybind11::arg("vendorId"), pybind11::arg("profileNum"), pybind11::arg("tagNum"));

    // chip::TLV::ContextTag(unsigned char) file:core/CHIPTLVTags.h line:114
    M("chip::TLV")
        .def("ContextTag", (unsigned long long (*)(unsigned char)) & chip::TLV::ContextTag,
             "Generates the API representation for of context-specific TLV tag\n\n \n          The context-specific tag number "
             "assigned to the tag.\n \n\n                      A 64-bit integer representing the tag.\n\nC++: "
             "chip::TLV::ContextTag(unsigned char) --> unsigned long long",
             pybind11::arg("tagNum"));

    // chip::TLV::CommonTag(unsigned int) file:core/CHIPTLVTags.h line:125
    M("chip::TLV")
        .def("CommonTag", (unsigned long long (*)(unsigned int)) & chip::TLV::CommonTag,
             "Generates the API representation of a common profile TLV tag\n\n \n          The common profile tag number assigned "
             "to the tag.\n \n\n                      A 64-bit integer representing the tag.\n\nC++: chip::TLV::CommonTag(unsigned "
             "int) --> unsigned long long",
             pybind11::arg("tagNum"));

    // chip::TLV::ProfileIdFromTag(unsigned long long) file:core/CHIPTLVTags.h line:149
    M("chip::TLV")
        .def("ProfileIdFromTag", (unsigned int (*)(unsigned long long)) & chip::TLV::ProfileIdFromTag,
             "Returns the profile id from a TLV tag\n\n \n The behavior of this function is undefined if the supplied tag is not a "
             "profile-specific tag.\n\n \n             The API representation of a profile-specific TLV tag.\n \n\n                "
             "      The profile id.\n\nC++: chip::TLV::ProfileIdFromTag(unsigned long long) --> unsigned int",
             pybind11::arg("tag"));

    // chip::TLV::ProfileNumFromTag(unsigned long long) file:core/CHIPTLVTags.h line:162
    M("chip::TLV")
        .def(
            "ProfileNumFromTag", (unsigned short (*)(unsigned long long)) & chip::TLV::ProfileNumFromTag,
            "Returns the profile number from a TLV tag\n\n \n The behavior of this function is undefined if the supplied tag is "
            "not a profile-specific tag.\n\n \n             The API representation of a profile-specific TLV tag.\n \n\n           "
            "           The associated profile number.\n\nC++: chip::TLV::ProfileNumFromTag(unsigned long long) --> unsigned short",
            pybind11::arg("tag"));

    // chip::TLV::TagNumFromTag(unsigned long long) file:core/CHIPTLVTags.h line:178
    M("chip::TLV")
        .def("TagNumFromTag", (unsigned int (*)(unsigned long long)) & chip::TLV::TagNumFromTag,
             "Returns the tag number from a TLV tag\n\n \n The behavior of this function is undefined if the supplied tag is not a "
             "profile-specific\n or context-specific tag.\n\n \n IsProfileTag() and IsContextTag()\n\n \n             The API "
             "representation of a profile-specific or context-specific TLV tag.\n \n\n                      The associated tag "
             "number.\n\nC++: chip::TLV::TagNumFromTag(unsigned long long) --> unsigned int",
             pybind11::arg("tag"));

    // chip::TLV::VendorIdFromTag(unsigned long long) file:core/CHIPTLVTags.h line:191
    M("chip::TLV")
        .def("VendorIdFromTag", (unsigned short (*)(unsigned long long)) & chip::TLV::VendorIdFromTag,
             "Returns the vendor id from a TLV tag\n\n \n The behavior of this function is undefined if the supplied tag is not a "
             "profile-specific tag.\n\n \n             The API representation of a profile-specific TLV tag.\n \n\n                "
             "      The associated vendor id.\n\nC++: chip::TLV::VendorIdFromTag(unsigned long long) --> unsigned short",
             pybind11::arg("tag"));

    // chip::TLV::IsProfileTag(unsigned long long) file:core/CHIPTLVTags.h line:199
    M("chip::TLV")
        .def("IsProfileTag", (bool (*)(unsigned long long)) & chip::TLV::IsProfileTag,
             "Returns true of the supplied tag is a profile-specific tag.\n\nC++: chip::TLV::IsProfileTag(unsigned long long) --> "
             "bool",
             pybind11::arg("tag"));

    // chip::TLV::IsContextTag(unsigned long long) file:core/CHIPTLVTags.h line:207
    M("chip::TLV")
        .def("IsContextTag", (bool (*)(unsigned long long)) & chip::TLV::IsContextTag,
             "Returns true if the supplied tag is a context-specific tag.\n\nC++: chip::TLV::IsContextTag(unsigned long long) --> "
             "bool",
             pybind11::arg("tag"));

    // chip::TLV::IsSpecialTag(unsigned long long) file:core/CHIPTLVTags.h line:213
    M("chip::TLV")
        .def("IsSpecialTag", (bool (*)(unsigned long long)) & chip::TLV::IsSpecialTag,
             "C++: chip::TLV::IsSpecialTag(unsigned long long) --> bool", pybind11::arg("tag"));

    // chip::TLV::TLVType file:core/CHIPTLVTypes.h line:33
    pybind11::enum_<chip::TLV::TLVType>(M("chip::TLV"), "TLVType", pybind11::arithmetic(),
                                        "An enumeration identifying the type of a TLV element.")
        .value("kTLVType_NotSpecified", chip::TLV::kTLVType_NotSpecified)
        .value("kTLVType_UnknownContainer", chip::TLV::kTLVType_UnknownContainer)
        .value("kTLVType_SignedInteger", chip::TLV::kTLVType_SignedInteger)
        .value("kTLVType_UnsignedInteger", chip::TLV::kTLVType_UnsignedInteger)
        .value("kTLVType_Boolean", chip::TLV::kTLVType_Boolean)
        .value("kTLVType_FloatingPointNumber", chip::TLV::kTLVType_FloatingPointNumber)
        .value("kTLVType_UTF8String", chip::TLV::kTLVType_UTF8String)
        .value("kTLVType_ByteString", chip::TLV::kTLVType_ByteString)
        .value("kTLVType_Null", chip::TLV::kTLVType_Null)
        .value("kTLVType_Structure", chip::TLV::kTLVType_Structure)
        .value("kTLVType_Array", chip::TLV::kTLVType_Array)
        .value("kTLVType_List", chip::TLV::kTLVType_List)
        .export_values();

    ;

    // chip::TLV::TLVElementType file:core/CHIPTLVTypes.h line:53
    pybind11::enum_<chip::TLV::TLVElementType>(M("chip::TLV"), "TLVElementType", "")
        .value("NotSpecified", chip::TLV::TLVElementType::NotSpecified)
        .value("Int8", chip::TLV::TLVElementType::Int8)
        .value("Int16", chip::TLV::TLVElementType::Int16)
        .value("Int32", chip::TLV::TLVElementType::Int32)
        .value("Int64", chip::TLV::TLVElementType::Int64)
        .value("UInt8", chip::TLV::TLVElementType::UInt8)
        .value("UInt16", chip::TLV::TLVElementType::UInt16)
        .value("UInt32", chip::TLV::TLVElementType::UInt32)
        .value("UInt64", chip::TLV::TLVElementType::UInt64)
        .value("BooleanFalse", chip::TLV::TLVElementType::BooleanFalse)
        .value("BooleanTrue", chip::TLV::TLVElementType::BooleanTrue)
        .value("FloatingPointNumber32", chip::TLV::TLVElementType::FloatingPointNumber32)
        .value("FloatingPointNumber64", chip::TLV::TLVElementType::FloatingPointNumber64)
        .value("UTF8String_1ByteLength", chip::TLV::TLVElementType::UTF8String_1ByteLength)
        .value("UTF8String_2ByteLength", chip::TLV::TLVElementType::UTF8String_2ByteLength)
        .value("UTF8String_4ByteLength", chip::TLV::TLVElementType::UTF8String_4ByteLength)
        .value("UTF8String_8ByteLength", chip::TLV::TLVElementType::UTF8String_8ByteLength)
        .value("ByteString_1ByteLength", chip::TLV::TLVElementType::ByteString_1ByteLength)
        .value("ByteString_2ByteLength", chip::TLV::TLVElementType::ByteString_2ByteLength)
        .value("ByteString_4ByteLength", chip::TLV::TLVElementType::ByteString_4ByteLength)
        .value("ByteString_8ByteLength", chip::TLV::TLVElementType::ByteString_8ByteLength)
        .value("Null", chip::TLV::TLVElementType::Null)
        .value("Structure", chip::TLV::TLVElementType::Structure)
        .value("Array", chip::TLV::TLVElementType::Array)
        .value("List", chip::TLV::TLVElementType::List)
        .value("EndOfContainer", chip::TLV::TLVElementType::EndOfContainer);

    ;

    // chip::TLV::TLVFieldSize file:core/CHIPTLVTypes.h line:100
    pybind11::enum_<chip::TLV::TLVFieldSize>(M("chip::TLV"), "TLVFieldSize", pybind11::arithmetic(), "")
        .value("kTLVFieldSize_0Byte", chip::TLV::kTLVFieldSize_0Byte)
        .value("kTLVFieldSize_1Byte", chip::TLV::kTLVFieldSize_1Byte)
        .value("kTLVFieldSize_2Byte", chip::TLV::kTLVFieldSize_2Byte)
        .value("kTLVFieldSize_4Byte", chip::TLV::kTLVFieldSize_4Byte)
        .value("kTLVFieldSize_8Byte", chip::TLV::kTLVFieldSize_8Byte)
        .export_values();

    ;

    // chip::TLV::IsValidTLVType(enum chip::TLV::TLVElementType) file:core/CHIPTLVTypes.h line:121
    M("chip::TLV")
        .def("IsValidTLVType", (bool (*)(enum chip::TLV::TLVElementType)) & chip::TLV::IsValidTLVType,
             "Returns true if the specified TLV type is valid.\n\n \n  if the specified TLV type is valid; otherwise \n \n\nC++: "
             "chip::TLV::IsValidTLVType(enum chip::TLV::TLVElementType) --> bool",
             pybind11::arg("type"));

    // chip::TLV::TLVTypeHasValue(enum chip::TLV::TLVElementType) file:core/CHIPTLVTypes.h line:131
    M("chip::TLV")
        .def("TLVTypeHasValue", (bool (*)(enum chip::TLV::TLVElementType)) & chip::TLV::TLVTypeHasValue,
             "Returns true if the specified TLV type implies the presence of an associated value field.\n\n \n  if the specified "
             "TLV type implies the presence of an associated value field; otherwise \n \n\nC++: chip::TLV::TLVTypeHasValue(enum "
             "chip::TLV::TLVElementType) --> bool",
             pybind11::arg("type"));

    // chip::TLV::TLVTypeHasLength(enum chip::TLV::TLVElementType) file:core/CHIPTLVTypes.h line:142
    M("chip::TLV")
        .def("TLVTypeHasLength", (bool (*)(enum chip::TLV::TLVElementType)) & chip::TLV::TLVTypeHasLength,
             "Returns true if the specified TLV type implies the presence of an associated length field.\n\n \n  if the specified "
             "TLV type implies the presence of an associated length field; otherwise \n \n\nC++: chip::TLV::TLVTypeHasLength(enum "
             "chip::TLV::TLVElementType) --> bool",
             pybind11::arg("type"));

    // chip::TLV::TLVTypeIsContainer(enum chip::TLV::TLVElementType) file:core/CHIPTLVTypes.h line:152
    M("chip::TLV")
        .def("TLVTypeIsContainer", (bool (*)(enum chip::TLV::TLVElementType)) & chip::TLV::TLVTypeIsContainer,
             "Returns true if the specified TLV type is a container.\n\n \n  if the specified TLV type is a container; otherwise "
             "\n \n\nC++: chip::TLV::TLVTypeIsContainer(enum chip::TLV::TLVElementType) --> bool",
             pybind11::arg("type"));

    // chip::TLV::TLVTypeIsContainer(enum chip::TLV::TLVType) file:core/CHIPTLVTypes.h line:157
    M("chip::TLV")
        .def("TLVTypeIsContainer", (bool (*)(enum chip::TLV::TLVType)) & chip::TLV::TLVTypeIsContainer,
             "C++: chip::TLV::TLVTypeIsContainer(enum chip::TLV::TLVType) --> bool", pybind11::arg("type"));

    // chip::TLV::TLVTypeIsString(enum chip::TLV::TLVElementType) file:core/CHIPTLVTypes.h line:167
    M("chip::TLV")
        .def("TLVTypeIsString", (bool (*)(enum chip::TLV::TLVElementType)) & chip::TLV::TLVTypeIsString,
             "Returns true if the specified TLV type is a UTF8 or byte string.\n\n \n  if the specified TLV type is a UTF8 or byte "
             "string; otherwise \n \n\nC++: chip::TLV::TLVTypeIsString(enum chip::TLV::TLVElementType) --> bool",
             pybind11::arg("type"));

    // chip::TLV::GetTLVFieldSize(enum chip::TLV::TLVElementType) file:core/CHIPTLVTypes.h line:173
    M("chip::TLV")
        .def("GetTLVFieldSize", (enum chip::TLV::TLVFieldSize(*)(enum chip::TLV::TLVElementType)) & chip::TLV::GetTLVFieldSize,
             "C++: chip::TLV::GetTLVFieldSize(enum chip::TLV::TLVElementType) --> enum chip::TLV::TLVFieldSize",
             pybind11::arg("type"));

    // chip::TLV::TLVFieldSizeToBytes(enum chip::TLV::TLVFieldSize) file:core/CHIPTLVTypes.h line:181
    M("chip::TLV")
        .def("TLVFieldSizeToBytes", (unsigned char (*)(enum chip::TLV::TLVFieldSize)) & chip::TLV::TLVFieldSizeToBytes,
             "C++: chip::TLV::TLVFieldSizeToBytes(enum chip::TLV::TLVFieldSize) --> unsigned char", pybind11::arg("fieldSize"));
}
