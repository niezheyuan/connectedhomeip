#include <core/CHIPTLVTags.h>

#include <functional>
#include <pybind11/pybind11.h>
#include <string>

#ifndef BINDER_PYBIND11_TYPE_CASTER
#define BINDER_PYBIND11_TYPE_CASTER
PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>)
PYBIND11_DECLARE_HOLDER_TYPE(T, T *)
PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

void bind_PyChip_50(std::function<pybind11::module &(std::string const & namespace_)> & M)
{
    // chip::TLV::TLVCommonProfiles file:core/CHIPTLVTags.h line:30
    pybind11::enum_<chip::TLV::TLVCommonProfiles>(M("chip::TLV"), "TLVCommonProfiles", pybind11::arithmetic(), "")
        .value("kProfileIdNotSpecified", chip::TLV::kProfileIdNotSpecified)
        .value("kCommonProfileId", chip::TLV::kCommonProfileId)
        .export_values();

    ;

    // chip::TLV::TLVTagFields file:core/CHIPTLVTags.h line:43
    pybind11::enum_<chip::TLV::TLVTagFields>(M("chip::TLV"), "TLVTagFields", pybind11::arithmetic(), "")
        .value("kProfileIdMask", chip::TLV::kProfileIdMask)
        .value("kProfileIdShift", chip::TLV::kProfileIdShift)
        .value("kVendorIdShift", chip::TLV::kVendorIdShift)
        .value("kProfileNumShift", chip::TLV::kProfileNumShift)
        .value("kTagNumMask", chip::TLV::kTagNumMask)
        .value("kSpecialTagMarker", chip::TLV::kSpecialTagMarker)
        .value("kContextTagMaxNum", chip::TLV::kContextTagMaxNum)
        .export_values();

    ;

    // chip::TLV::TLVTagControl file:core/CHIPTLVTags.h line:55
    pybind11::enum_<chip::TLV::TLVTagControl>(M("chip::TLV"), "TLVTagControl", "")
        .value("Anonymous", chip::TLV::TLVTagControl::Anonymous)
        .value("ContextSpecific", chip::TLV::TLVTagControl::ContextSpecific)
        .value("CommonProfile_2Bytes", chip::TLV::TLVTagControl::CommonProfile_2Bytes)
        .value("CommonProfile_4Bytes", chip::TLV::TLVTagControl::CommonProfile_4Bytes)
        .value("ImplicitProfile_2Bytes", chip::TLV::TLVTagControl::ImplicitProfile_2Bytes)
        .value("ImplicitProfile_4Bytes", chip::TLV::TLVTagControl::ImplicitProfile_4Bytes)
        .value("FullyQualified_6Bytes", chip::TLV::TLVTagControl::FullyQualified_6Bytes)
        .value("FullyQualified_8Bytes", chip::TLV::TLVTagControl::FullyQualified_8Bytes);

    ;
}
