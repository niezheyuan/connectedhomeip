#include <core/CHIPTLV.h>
#include <core/CHIPTLVTypes.h>
#include <sstream> // __str__
#include <support/Span.h>

#include <functional>
#include <pybind11/pybind11.h>
#include <string>

#ifndef BINDER_PYBIND11_TYPE_CASTER
#define BINDER_PYBIND11_TYPE_CASTER
PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>)
PYBIND11_DECLARE_HOLDER_TYPE(T, T *)
PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

void bind_PyChip_54(std::function<pybind11::module &(std::string const & namespace_)> & M)
{
    { // chip::TLV::TLVWriter file:core/CHIPTLV.h line:823
        pybind11::class_<chip::TLV::TLVWriter, std::shared_ptr<chip::TLV::TLVWriter>> cl(
            M("chip::TLV"), "TLVWriter",
            "Provides a memory efficient encoder for writing data in CHIP TLV format.\n\n TLVWriter implements a forward-only, "
            "stream-style encoder for CHIP TLV data.  Applications\n write data to an encoding by calling one of the writer's "
            "Put() methods, passing associated\n tag and value information as necessary.  Similarly applications can encode TLV "
            "container types\n (structures, arrays or paths) by calling the writer's OpenContainer() or EnterContainer()\n "
            "methods.\n\n A TLVWriter object can write data directly to a fixed output buffer, or to memory provided by\n a "
            "TLVBackingStore.");
        cl.def(pybind11::init([]() { return new chip::TLV::TLVWriter(); }));
        cl.def_readwrite("ImplicitProfileId", &chip::TLV::TLVWriter::ImplicitProfileId);
        cl.def("Init", (void (chip::TLV::TLVWriter::*)(unsigned char *, unsigned int)) & chip::TLV::TLVWriter::Init,
               "Initializes a TLVWriter object to write into a single output buffer.\n\n \n Applications must call Finalize() on "
               "the writer before using the contents of the output\n buffer.\n\n \n     A pointer to the buffer into which TLV "
               "should be written.\n \n\n  The maximum number of bytes that should be written to the output buffer.\n\n     "
               "\n\nC++: chip::TLV::TLVWriter::Init(unsigned char *, unsigned int) --> void",
               pybind11::arg("buf"), pybind11::arg("maxLen"));
        cl.def(
            "Init", [](chip::TLV::TLVWriter & o, class chip::TLV::TLVBackingStore & a0) -> int { return o.Init(a0); }, "",
            pybind11::arg("backingStore"));
        cl.def("Init",
               (int (chip::TLV::TLVWriter::*)(class chip::TLV::TLVBackingStore &, unsigned int)) & chip::TLV::TLVWriter::Init,
               "Initializes a TLVWriter object to write into memory provided by a TLVBackingStore.\n\n \n Applications must call "
               "Finalize() on the writer before using the contents of the buffer.\n\n \n    A TLVBackingStore providing memory, "
               "which must outlive the TVLWriter.\n \n\n          The maximum number of bytes that should be written to the output "
               "buffer.\n\n  #CHIP_NO_ERROR  If the method succeeded.\n  other           Other error codes returned by "
               "TLVBackingStore::OnInit().\n\nC++: chip::TLV::TLVWriter::Init(class chip::TLV::TLVBackingStore &, unsigned int) "
               "--> int",
               pybind11::arg("backingStore"), pybind11::arg("maxLen"));
        cl.def("Finalize", (int (chip::TLV::TLVWriter::*)()) & chip::TLV::TLVWriter::Finalize,
               "Finish the writing of a TLV encoding.\n\n The Finalize() method completes the process of writing a TLV encoding to "
               "the underlying output\n buffer.  The method must be called by the application before it uses the contents of the "
               "buffer.\n Finalize() can only be called when there are no container writers open for the current writer.\n (See "
               "\n\n  #CHIP_NO_ERROR      If the encoding was finalized successfully.\n  #CHIP_ERROR_TLV_CONTAINER_OPEN\n          "
               "                    If a container writer has been opened on the current writer and not\n                          "
               "    yet closed.\n  other                Other CHIP or platform-specific errors returned by the configured\n        "
               "                      FinalizeBuffer() function.\n\nC++: chip::TLV::TLVWriter::Finalize() --> int");
        cl.def("Put", (int (chip::TLV::TLVWriter::*)(unsigned long long, signed char)) & chip::TLV::TLVWriter::Put,
               "Encodes a TLV signed integer value.\n\n \n             The TLV tag to be encoded with the value, or  if the\n      "
               "                        value should be encoded without a tag.  Tag values should be\n                             "
               " constructed with one of the tag definition functions ProfileTag(),\n                              ContextTag() or "
               "CommonTag().\n \n\n               The value to be encoded.\n\n  #CHIP_NO_ERROR      If the method succeeded.\n  "
               "#CHIP_ERROR_TLV_CONTAINER_OPEN\n                              If a container writer has been opened on the current "
               "writer and not\n                              yet closed.\n  #CHIP_ERROR_INVALID_TLV_TAG\n                         "
               "     If the specified tag value is invalid or inappropriate in the context\n                              in which "
               "the value is being written.\n  #CHIP_ERROR_BUFFER_TOO_SMALL\n                              If writing the value "
               "would exceed the limit on the maximum number of\n                              bytes specified when the writer was "
               "initialized.\n  #CHIP_ERROR_NO_MEMORY\n                              If an attempt to allocate an output buffer "
               "failed due to lack of\n                              memory.\n  other                Other CHIP or "
               "platform-specific errors returned by the configured\n                              TLVBackingStore.\n\n     "
               "\n\nC++: chip::TLV::TLVWriter::Put(unsigned long long, signed char) --> int",
               pybind11::arg("tag"), pybind11::arg("v"));
        cl.def("Put", (int (chip::TLV::TLVWriter::*)(unsigned long long, signed char, bool)) & chip::TLV::TLVWriter::Put,
               "Encodes a TLV signed integer value.\n\n \n             The TLV tag to be encoded with the value, or  if the\n      "
               "                        value should be encoded without a tag.  Tag values should be\n                             "
               " constructed with one of the tag definition functions ProfileTag(),\n                              ContextTag() or "
               "CommonTag().\n \n\n               The value to be encoded.\n \n\n    True if the value should be encoded in the "
               "same number of bytes as\n                              at the input type.  False if value should be encoded in the "
               "minimum\n                              number of bytes necessary to represent the value.  Note: Applications\n     "
               "                         are strongly encouraged to set this parameter to false.\n\n  #CHIP_NO_ERROR      If the "
               "method succeeded.\n  #CHIP_ERROR_TLV_CONTAINER_OPEN\n                              If a container writer has been "
               "opened on the current writer and not\n                              yet closed.\n  #CHIP_ERROR_INVALID_TLV_TAG\n   "
               "                           If the specified tag value is invalid or inappropriate in the context\n                 "
               "             in which the value is being written.\n  #CHIP_ERROR_BUFFER_TOO_SMALL\n                              "
               "If writing the value would exceed the limit on the maximum number of\n                              bytes "
               "specified when the writer was initialized.\n  #CHIP_ERROR_NO_MEMORY\n                              If an attempt "
               "to allocate an output buffer failed due to lack of\n                              memory.\n  other                "
               "Other CHIP or platform-specific errors returned by the configured\n                              "
               "TLVBackingStore.\n\n     \n\nC++: chip::TLV::TLVWriter::Put(unsigned long long, signed char, bool) --> int",
               pybind11::arg("tag"), pybind11::arg("v"), pybind11::arg("preserveSize"));
        cl.def("Put", (int (chip::TLV::TLVWriter::*)(unsigned long long, short)) & chip::TLV::TLVWriter::Put,
               "C++: chip::TLV::TLVWriter::Put(unsigned long long, short) --> int", pybind11::arg("tag"), pybind11::arg("v"));
        cl.def("Put", (int (chip::TLV::TLVWriter::*)(unsigned long long, short, bool)) & chip::TLV::TLVWriter::Put,
               "C++: chip::TLV::TLVWriter::Put(unsigned long long, short, bool) --> int", pybind11::arg("tag"), pybind11::arg("v"),
               pybind11::arg("preserveSize"));
        cl.def("Put", (int (chip::TLV::TLVWriter::*)(unsigned long long, int)) & chip::TLV::TLVWriter::Put,
               "C++: chip::TLV::TLVWriter::Put(unsigned long long, int) --> int", pybind11::arg("tag"), pybind11::arg("v"));
        cl.def("Put", (int (chip::TLV::TLVWriter::*)(unsigned long long, int, bool)) & chip::TLV::TLVWriter::Put,
               "C++: chip::TLV::TLVWriter::Put(unsigned long long, int, bool) --> int", pybind11::arg("tag"), pybind11::arg("v"),
               pybind11::arg("preserveSize"));
        cl.def("Put", (int (chip::TLV::TLVWriter::*)(unsigned long long, long long)) & chip::TLV::TLVWriter::Put,
               "C++: chip::TLV::TLVWriter::Put(unsigned long long, long long) --> int", pybind11::arg("tag"), pybind11::arg("v"));
        cl.def("Put", (int (chip::TLV::TLVWriter::*)(unsigned long long, long long, bool)) & chip::TLV::TLVWriter::Put,
               "C++: chip::TLV::TLVWriter::Put(unsigned long long, long long, bool) --> int", pybind11::arg("tag"),
               pybind11::arg("v"), pybind11::arg("preserveSize"));
        cl.def("Put", (int (chip::TLV::TLVWriter::*)(unsigned long long, unsigned char)) & chip::TLV::TLVWriter::Put,
               "Encodes a TLV unsigned integer value.\n\n \n             The TLV tag to be encoded with the value, or  if the\n    "
               "                          value should be encoded without a tag. Tag values should be\n                            "
               "  constructed with one of the tag definition functions ProfileTag(),\n                              ContextTag() "
               "or CommonTag().\n \n\n               The value to be encoded.\n\n  #CHIP_NO_ERROR      If the method succeeded.\n  "
               "#CHIP_ERROR_TLV_CONTAINER_OPEN\n                              If a container writer has been opened on the current "
               "writer and not\n                              yet closed.\n  #CHIP_ERROR_INVALID_TLV_TAG\n                         "
               "     If the specified tag value is invalid or inappropriate in the context\n                              in which "
               "the value is being written.\n  #CHIP_ERROR_BUFFER_TOO_SMALL\n                              If writing the value "
               "would exceed the limit on the maximum number of\n                              bytes specified when the writer was "
               "initialized.\n  #CHIP_ERROR_NO_MEMORY\n                              If an attempt to allocate an output buffer "
               "failed due to lack of\n                              memory.\n  other                Other CHIP or "
               "platform-specific errors returned by the configured\n                              TLVBackingStore.\n\n     "
               "\n\nC++: chip::TLV::TLVWriter::Put(unsigned long long, unsigned char) --> int",
               pybind11::arg("tag"), pybind11::arg("v"));
        cl.def("Put", (int (chip::TLV::TLVWriter::*)(unsigned long long, unsigned char, bool)) & chip::TLV::TLVWriter::Put,
               "Encodes a TLV unsigned integer value.\n\n \n             The TLV tag to be encoded with the value, or  if the\n    "
               "                          value should be encoded without a tag.  Tag values should be\n                           "
               "   constructed with one of the tag definition functions ProfileTag(),\n                              ContextTag() "
               "or CommonTag().\n \n\n               The value to be encoded.\n \n\n    True if the value should be encoded in the "
               "same number of bytes as\n                              at the input type.  False if value should be encoded in the "
               "minimum\n                              number of bytes necessary to represent the value.  Note: Applications\n     "
               "                         are strongly encouraged to set this parameter to false.\n\n  #CHIP_NO_ERROR      If the "
               "method succeeded.\n  #CHIP_ERROR_TLV_CONTAINER_OPEN\n                              If a container writer has been "
               "opened on the current writer and not\n                              yet closed.\n  #CHIP_ERROR_INVALID_TLV_TAG\n   "
               "                           If the specified tag value is invalid or inappropriate in the context\n                 "
               "             in which the value is being written.\n  #CHIP_ERROR_BUFFER_TOO_SMALL\n                              "
               "If writing the value would exceed the limit on the maximum number of\n                              bytes "
               "specified when the writer was initialized.\n  #CHIP_ERROR_NO_MEMORY\n                              If an attempt "
               "to allocate an output buffer failed due to lack of\n                              memory.\n  other                "
               "Other CHIP or platform-specific errors returned by the configured\n                              "
               "TLVBackingStore.\n\n     \n\nC++: chip::TLV::TLVWriter::Put(unsigned long long, unsigned char, bool) --> int",
               pybind11::arg("tag"), pybind11::arg("v"), pybind11::arg("preserveSize"));
        cl.def("Put", (int (chip::TLV::TLVWriter::*)(unsigned long long, unsigned short)) & chip::TLV::TLVWriter::Put,
               "C++: chip::TLV::TLVWriter::Put(unsigned long long, unsigned short) --> int", pybind11::arg("tag"),
               pybind11::arg("v"));
        cl.def("Put", (int (chip::TLV::TLVWriter::*)(unsigned long long, unsigned short, bool)) & chip::TLV::TLVWriter::Put,
               "C++: chip::TLV::TLVWriter::Put(unsigned long long, unsigned short, bool) --> int", pybind11::arg("tag"),
               pybind11::arg("v"), pybind11::arg("preserveSize"));
        cl.def("Put", (int (chip::TLV::TLVWriter::*)(unsigned long long, unsigned int)) & chip::TLV::TLVWriter::Put,
               "C++: chip::TLV::TLVWriter::Put(unsigned long long, unsigned int) --> int", pybind11::arg("tag"),
               pybind11::arg("v"));
        cl.def("Put", (int (chip::TLV::TLVWriter::*)(unsigned long long, unsigned int, bool)) & chip::TLV::TLVWriter::Put,
               "C++: chip::TLV::TLVWriter::Put(unsigned long long, unsigned int, bool) --> int", pybind11::arg("tag"),
               pybind11::arg("v"), pybind11::arg("preserveSize"));
        cl.def("Put", (int (chip::TLV::TLVWriter::*)(unsigned long long, unsigned long long)) & chip::TLV::TLVWriter::Put,
               "C++: chip::TLV::TLVWriter::Put(unsigned long long, unsigned long long) --> int", pybind11::arg("tag"),
               pybind11::arg("v"));
        cl.def("Put", (int (chip::TLV::TLVWriter::*)(unsigned long long, unsigned long long, bool)) & chip::TLV::TLVWriter::Put,
               "C++: chip::TLV::TLVWriter::Put(unsigned long long, unsigned long long, bool) --> int", pybind11::arg("tag"),
               pybind11::arg("v"), pybind11::arg("preserveSize"));
        cl.def("Put", (int (chip::TLV::TLVWriter::*)(unsigned long long, double)) & chip::TLV::TLVWriter::Put,
               "Encodes a TLV floating point value.\n\n \n             The TLV tag to be encoded with the value, or  if the\n      "
               "                        value should be encoded without a tag.  Tag values should be\n                             "
               " constructed with one of the tag definition functions ProfileTag(),\n                              ContextTag() or "
               "CommonTag().\n \n\n               The value to be encoded.\n\n  #CHIP_NO_ERROR      If the method succeeded.\n  "
               "#CHIP_ERROR_TLV_CONTAINER_OPEN\n                              If a container writer has been opened on the current "
               "writer and not\n                              yet closed.\n  #CHIP_ERROR_INVALID_TLV_TAG\n                         "
               "     If the specified tag value is invalid or inappropriate in the context\n                              in which "
               "the value is being written.\n  #CHIP_ERROR_BUFFER_TOO_SMALL\n                              If writing the value "
               "would exceed the limit on the maximum number of\n                              bytes specified when the writer was "
               "initialized.\n  #CHIP_ERROR_NO_MEMORY\n                              If an attempt to allocate an output buffer "
               "failed due to lack of\n                              memory.\n  other                Other CHIP or "
               "platform-specific errors returned by the configured\n                              TLVBackingStore.\n\n     "
               "\n\nC++: chip::TLV::TLVWriter::Put(unsigned long long, double) --> int",
               pybind11::arg("tag"), pybind11::arg("v"));
        cl.def("Put", (int (chip::TLV::TLVWriter::*)(unsigned long long, float)) & chip::TLV::TLVWriter::Put,
               "C++: chip::TLV::TLVWriter::Put(unsigned long long, float) --> int", pybind11::arg("tag"), pybind11::arg("v"));
        cl.def("Put",
               (int (chip::TLV::TLVWriter::*)(unsigned long long, class chip::Span<const unsigned char>)) &
                   chip::TLV::TLVWriter::Put,
               "Encodes a TLV byte string value using ByteSpan class.\n\n \n             The TLV tag to be encoded with the value, "
               "or  if the\n                              value should be encoded without a tag.  Tag values should be\n           "
               "                   constructed with one of the tag definition functions ProfileTag(),\n                            "
               "  ContextTag() or CommonTag().\n \n\n            A ByteSpan object containing the bytes string to be encoded.\n\n  "
               "#CHIP_NO_ERROR      If the method succeeded.\n  #CHIP_ERROR_TLV_CONTAINER_OPEN\n                              If a "
               "container writer has been opened on the current writer and not\n                              yet closed.\n  "
               "#CHIP_ERROR_INVALID_TLV_TAG\n                              If the specified tag value is invalid or inappropriate "
               "in the context\n                              in which the value is being written.\n  "
               "#CHIP_ERROR_BUFFER_TOO_SMALL\n                              If writing the value would exceed the limit on the "
               "maximum number of\n                              bytes specified when the writer was initialized.\n  "
               "#CHIP_ERROR_NO_MEMORY\n                              If an attempt to allocate an output buffer failed due to lack "
               "of\n                              memory.\n  other                Other CHIP or platform-specific errors returned "
               "by the configured\n                              TLVBackingStore.\n\n     \n\nC++: "
               "chip::TLV::TLVWriter::Put(unsigned long long, class chip::Span<const unsigned char>) --> int",
               pybind11::arg("tag"), pybind11::arg("data"));
        cl.def("PutBoolean", (int (chip::TLV::TLVWriter::*)(unsigned long long, bool)) & chip::TLV::TLVWriter::PutBoolean,
               "Encodes a TLV boolean value.\n\n \n             The TLV tag to be encoded with the value, or  if the\n             "
               "                 value should be encoded without a tag.  Tag values should be\n                              "
               "constructed with one of the tag definition functions ProfileTag(),\n                              ContextTag() or "
               "CommonTag().\n \n\n               The value to be encoded.\n\n  #CHIP_NO_ERROR      If the method succeeded.\n  "
               "#CHIP_ERROR_TLV_CONTAINER_OPEN\n                              If a container writer has been opened on the current "
               "writer and not\n                              yet closed.\n  #CHIP_ERROR_INVALID_TLV_TAG\n                         "
               "     If the specified tag value is invalid or inappropriate in the context\n                              in which "
               "the value is being written.\n  #CHIP_ERROR_BUFFER_TOO_SMALL\n                              If writing the value "
               "would exceed the limit on the maximum number of\n                              bytes specified when the writer was "
               "initialized.\n  #CHIP_ERROR_NO_MEMORY\n                              If an attempt to allocate an output buffer "
               "failed due to lack of\n                              memory.\n  other                Other CHIP or "
               "platform-specific errors returned by the configured\n                              TLVBackingStore.\n\n     "
               "\n\nC++: chip::TLV::TLVWriter::PutBoolean(unsigned long long, bool) --> int",
               pybind11::arg("tag"), pybind11::arg("v"));
        cl.def("PutBytes",
               (int (chip::TLV::TLVWriter::*)(unsigned long long, const unsigned char *, unsigned int)) &
                   chip::TLV::TLVWriter::PutBytes,
               "Encodes a TLV byte string value.\n\n \n             The TLV tag to be encoded with the value, or  if the\n         "
               "                     value should be encoded without a tag.  Tag values should be\n                              "
               "constructed with one of the tag definition functions ProfileTag(),\n                              ContextTag() or "
               "CommonTag().\n \n\n             A pointer to a buffer containing the bytes string to be encoded.\n \n\n            "
               " The number of bytes to be encoded.\n\n  #CHIP_NO_ERROR      If the method succeeded.\n  "
               "#CHIP_ERROR_TLV_CONTAINER_OPEN\n                              If a container writer has been opened on the current "
               "writer and not\n                              yet closed.\n  #CHIP_ERROR_INVALID_TLV_TAG\n                         "
               "     If the specified tag value is invalid or inappropriate in the context\n                              in which "
               "the value is being written.\n  #CHIP_ERROR_BUFFER_TOO_SMALL\n                              If writing the value "
               "would exceed the limit on the maximum number of\n                              bytes specified when the writer was "
               "initialized.\n  #CHIP_ERROR_NO_MEMORY\n                              If an attempt to allocate an output buffer "
               "failed due to lack of\n                              memory.\n  other                Other CHIP or "
               "platform-specific errors returned by the configured\n                              TLVBackingStore.\n\n     "
               "\n\nC++: chip::TLV::TLVWriter::PutBytes(unsigned long long, const unsigned char *, unsigned int) --> int",
               pybind11::arg("tag"), pybind11::arg("buf"), pybind11::arg("len"));
        cl.def(
            "PutString", (int (chip::TLV::TLVWriter::*)(unsigned long long, const char *)) & chip::TLV::TLVWriter::PutString,
            "Encodes a TLV UTF8 string value.\n\n \n             The TLV tag to be encoded with the value, or  if the\n            "
            "                  value should be encoded without a tag.  Tag values should be\n                              "
            "constructed with one of the tag definition functions ProfileTag(),\n                              ContextTag() or "
            "CommonTag().\n \n\n             A pointer to the null-terminated UTF-8 string to be encoded.\n\n  #CHIP_NO_ERROR      "
            "If the method succeeded.\n  #CHIP_ERROR_TLV_CONTAINER_OPEN\n                              If a container writer has "
            "been opened on the current writer and not\n                              yet closed.\n  #CHIP_ERROR_INVALID_TLV_TAG\n "
            "                             If the specified tag value is invalid or inappropriate in the context\n                  "
            "            in which the value is being written.\n  #CHIP_ERROR_BUFFER_TOO_SMALL\n                              If "
            "writing the value would exceed the limit on the maximum number of\n                              bytes specified when "
            "the writer was initialized.\n  #CHIP_ERROR_NO_MEMORY\n                              If an attempt to allocate an "
            "output buffer failed due to lack of\n                              memory.\n  other                Other CHIP or "
            "platform-specific errors returned by the configured\n                              TLVBackingStore.\n\n     \n\nC++: "
            "chip::TLV::TLVWriter::PutString(unsigned long long, const char *) --> int",
            pybind11::arg("tag"), pybind11::arg("buf"));
        cl.def("PutString",
               (int (chip::TLV::TLVWriter::*)(unsigned long long, const char *, unsigned int)) & chip::TLV::TLVWriter::PutString,
               "Encodes a TLV UTF8 string value.\n\n \n             The TLV tag to be encoded with the value, or  if the\n         "
               "                     value should be encoded without a tag.  Tag values should be\n                              "
               "constructed with one of the tag definition functions ProfileTag(),\n                              ContextTag() or "
               "CommonTag().\n \n\n             A pointer to the UTF-8 string to be encoded.\n \n\n             The length (in "
               "bytes) of the string to be encoded.\n\n  #CHIP_NO_ERROR      If the method succeeded.\n  "
               "#CHIP_ERROR_TLV_CONTAINER_OPEN\n                              If a container writer has been opened on the current "
               "writer and not\n                              yet closed.\n  #CHIP_ERROR_INVALID_TLV_TAG\n                         "
               "     If the specified tag value is invalid or inappropriate in the context\n                              in which "
               "the value is being written.\n  #CHIP_ERROR_BUFFER_TOO_SMALL\n                              If writing the value "
               "would exceed the limit on the maximum number of\n                              bytes specified when the writer was "
               "initialized.\n  #CHIP_ERROR_NO_MEMORY\n                              If an attempt to allocate an output buffer "
               "failed due to lack of\n                              memory.\n  other                Other CHIP or "
               "platform-specific errors returned by the configured\n                              TLVBackingStore.\n\n     "
               "\n\nC++: chip::TLV::TLVWriter::PutString(unsigned long long, const char *, unsigned int) --> int",
               pybind11::arg("tag"), pybind11::arg("buf"), pybind11::arg("len"));
        cl.def(
            "PutStringF",
            [](chip::TLV::TLVWriter & o, unsigned long long const & a0, const char * a1) -> int { return o.PutStringF(a0, a1); },
            "", pybind11::arg("tag"), pybind11::arg("fmt"));
        cl.def("PutNull", (int (chip::TLV::TLVWriter::*)(unsigned long long)) & chip::TLV::TLVWriter::PutNull,
               "Encodes a TLV null value.\n\n \n             The TLV tag to be encoded with the value, or  if the\n                "
               "              value should be encoded without a tag.  Tag values should be\n                              "
               "constructed with one of the tag definition functions ProfileTag(),\n                              ContextTag() or "
               "CommonTag().\n\n  #CHIP_NO_ERROR      If the method succeeded.\n  #CHIP_ERROR_TLV_CONTAINER_OPEN\n                 "
               "             If a container writer has been opened on the current writer and not\n                              "
               "yet closed.\n  #CHIP_ERROR_INVALID_TLV_TAG\n                              If the specified tag value is invalid or "
               "inappropriate in the context\n                              in which the value is being written.\n  "
               "#CHIP_ERROR_BUFFER_TOO_SMALL\n                              If writing the value would exceed the limit on the "
               "maximum number of\n                              bytes specified when the writer was initialized.\n  "
               "#CHIP_ERROR_NO_MEMORY\n                              If an attempt to allocate an output buffer failed due to lack "
               "of\n                              memory.\n  other                Other CHIP or platform-specific errors returned "
               "by the configured\n                              TLVBackingStore.\n\n     \n\nC++: "
               "chip::TLV::TLVWriter::PutNull(unsigned long long) --> int",
               pybind11::arg("tag"));
        cl.def(
            "CopyElement", (int (chip::TLV::TLVWriter::*)(class chip::TLV::TLVReader &)) & chip::TLV::TLVWriter::CopyElement,
            "Copies a TLV element from a reader object into the writer.\n\n The CopyElement() method encodes a new TLV element "
            "whose type, tag and value are taken from a TLVReader\n object. When the method is called, the supplied reader object "
            "is expected to be positioned on the\n source TLV element. The newly encoded element will have the same type, tag and "
            "contents as the input\n container.  If the supplied element is a TLV container (structure, array or path), the entire "
            "contents\n of the container will be copied.\n\n \n This method requires the supplied TVLReader object to be reading "
            "from a single, contiguous\n input buffer that contains the entirety of the underlying TLV encoding. Supplying a "
            "reader in any\n other mode has undefined behavior.\n\n \n          A reference to a TLVReader object identifying a "
            "pre-encoded TLV\n                              element that should be copied.\n\n  #CHIP_NO_ERROR      If the method "
            "succeeded.\n  #CHIP_ERROR_INCORRECT_STATE\n                              If the supplied reader is not positioned on "
            "an element.\n  #CHIP_ERROR_TLV_CONTAINER_OPEN\n                              If a container writer has been opened on "
            "the current writer and not\n                              yet closed.\n  #CHIP_ERROR_TLV_UNDERRUN\n                   "
            "           If the underlying TLV encoding associated with the supplied reader ended\n                              "
            "prematurely.\n  #CHIP_ERROR_INVALID_TLV_ELEMENT\n                              If the supplied reader encountered an "
            "invalid or unsupported TLV element\n                              type.\n  #CHIP_ERROR_INVALID_TLV_TAG\n              "
            "                If the supplied reader encountered a TLV tag in an invalid context,\n                              or "
            "if the supplied tag is invalid or inappropriate in the context in\n                              which the new "
            "container is being written.\n  #CHIP_ERROR_BUFFER_TOO_SMALL\n                              If writing the value would "
            "exceed the limit on the maximum number of\n                              bytes specified when the writer was "
            "initialized.\n  #CHIP_ERROR_NO_MEMORY\n                              If an attempt to allocate an output buffer "
            "failed due to lack of\n                              memory.\n  other                Other CHIP or platform-specific "
            "errors returned by the configured\n                              GetNewBuffer() or FinalizeBuffer() functions, or by "
            "the GetNextBuffer()\n                              function associated with the reader object.\n\n     \n\nC++: "
            "chip::TLV::TLVWriter::CopyElement(class chip::TLV::TLVReader &) --> int",
            pybind11::arg("reader"));
        cl.def(
            "CopyElement",
            (int (chip::TLV::TLVWriter::*)(unsigned long long, class chip::TLV::TLVReader &)) & chip::TLV::TLVWriter::CopyElement,
            "Copies a TLV element from a reader object into the writer.\n\n The CopyElement() method encodes a new TLV element "
            "whose type and value are taken from a TLVReader\n object. When the method is called, the supplied reader object is "
            "expected to be positioned on the\n source TLV element. The newly encoded element will have the same type and contents "
            "as the input\n container, however the tag will be set to the specified argument.  If the supplied element is a\n TLV "
            "container (structure, array or path), the entire contents of the container will be copied.\n\n \n This method "
            "requires the supplied TVLReader object to be reading from a single, contiguous\n input buffer that contains the "
            "entirety of the underlying TLV encoding. Supplying a reader in any\n other mode has undefined behavior.\n\n \n        "
            "     The TLV tag to be encoded with the container, or  if\n                              the container should be "
            "encoded without a tag.  Tag values should be\n                              constructed with one of the tag "
            "definition functions ProfileTag(),\n                              ContextTag() or CommonTag().\n \n\n          A "
            "reference to a TLVReader object identifying a pre-encoded TLV\n                              element whose type and "
            "value should be copied.\n\n  #CHIP_NO_ERROR      If the method succeeded.\n  #CHIP_ERROR_INCORRECT_STATE\n            "
            "                  If the supplied reader is not positioned on an element.\n  #CHIP_ERROR_TLV_CONTAINER_OPEN\n         "
            "                     If a container writer has been opened on the current writer and not\n                            "
            "  yet closed.\n  #CHIP_ERROR_TLV_UNDERRUN\n                              If the underlying TLV encoding associated "
            "with the supplied reader ended\n                              prematurely.\n  #CHIP_ERROR_INVALID_TLV_ELEMENT\n       "
            "                       If the supplied reader encountered an invalid or unsupported TLV element\n                     "
            "         type.\n  #CHIP_ERROR_INVALID_TLV_TAG\n                              If the supplied reader encountered a TLV "
            "tag in an invalid context,\n                              or if the supplied tag is invalid or inappropriate in the "
            "context in\n                              which the new container is being written.\n  #CHIP_ERROR_BUFFER_TOO_SMALL\n "
            "                             If writing the value would exceed the limit on the maximum number of\n                   "
            "           bytes specified when the writer was initialized.\n  #CHIP_ERROR_NO_MEMORY\n                              "
            "If an attempt to allocate an output buffer failed due to lack of\n                              memory.\n  other      "
            "          Other CHIP or platform-specific errors returned by the configured\n                              "
            "GetNewBuffer() or FinalizeBuffer() functions, or by the GetNextBuffer()\n                              function "
            "associated with the reader object.\n\n     \n\nC++: chip::TLV::TLVWriter::CopyElement(unsigned long long, class "
            "chip::TLV::TLVReader &) --> int",
            pybind11::arg("tag"), pybind11::arg("reader"));
        cl.def(
            "StartContainer",
            (int (chip::TLV::TLVWriter::*)(unsigned long long, enum chip::TLV::TLVType, enum chip::TLV::TLVType &)) &
                chip::TLV::TLVWriter::StartContainer,
            "Begins encoding a new TLV container element.\n\n The StartContainer() method is used to write TLV container elements "
            "(structure, arrays or paths)\n to an encoding.  The method takes the type and tag (if any) of the new container, and "
            "a reference\n to a TLVType value which will be used to save the current context of the writer while it is being\n "
            "used to write the container.\n\n Once the StartContainer() method returns, the application should use the current "
            "TLVWriter object to\n write the elements of the container.  When finish, the application must call the "
            "EndContainer()\n method to finish the encoding of the container.\n\n \n             The TLV tag to be encoded with "
            "the container, or  if\n                              the container should be encoded without a tag.  Tag values "
            "should be\n                              constructed with one of the tag definition functions ProfileTag(),\n         "
            "                     ContextTag() or CommonTag().\n \n\n   The type of container to encode.  Must be one of \n        "
            "                       or \n \n\n\n                              A reference to a TLVType value that will receive the "
            "context of the\n                              writer.\n\n  #CHIP_NO_ERROR      If the method succeeded.\n  "
            "#CHIP_ERROR_WRONG_TLV_TYPE\n                              If the value specified for containerType is incorrect.\n  "
            "#CHIP_ERROR_TLV_CONTAINER_OPEN\n                              If a container writer has been opened on the current "
            "writer and not\n                              yet closed.\n  #CHIP_ERROR_INVALID_TLV_TAG\n                            "
            "  If the specified tag value is invalid or inappropriate in the context\n                              in which the "
            "value is being written.\n  #CHIP_ERROR_BUFFER_TOO_SMALL\n                              If writing the value would "
            "exceed the limit on the maximum number of\n                              bytes specified when the writer was "
            "initialized.\n  #CHIP_ERROR_NO_MEMORY\n                              If an attempt to allocate an output buffer "
            "failed due to lack of\n                              memory.\n  other                Other CHIP or platform-specific "
            "errors returned by the configured\n                              TLVBackingStore.\n\n     \n\nC++: "
            "chip::TLV::TLVWriter::StartContainer(unsigned long long, enum chip::TLV::TLVType, enum chip::TLV::TLVType &) --> int",
            pybind11::arg("tag"), pybind11::arg("containerType"), pybind11::arg("outerContainerType"));
        cl.def(
            "EndContainer", (int (chip::TLV::TLVWriter::*)(enum chip::TLV::TLVType)) & chip::TLV::TLVWriter::EndContainer,
            "Completes the encoding of a TLV container element.\n\n The EndContainer() method completes the encoding of a TLV "
            "container element and restores the state\n of a TLVWrite object after an earlier call to StartContainer().  For every "
            "call to StartContainer()\n applications must make a corresponding call to EndContainer(), passing the TLVType value "
            "returned\n by the StartContainer() call.  When EndContainer() returns, the writer object can be used to write\n "
            "additional TLV elements that follow the container element.\n\n \n Any changes made to the configuration of the writer "
            "between the calls to StartContainer()\n and EndContainer() are NOT undone by the call to EndContainer().  For "
            "example, a change to the\n implicit profile id ( will not be reversed when a container is ended.  Thus\n it is the "
            "application's responsibility to adjust the configuration accordingly at the appropriate\n times.\n\n \n\n             "
            "                 The TLVType value that was returned by the StartContainer() method.\n\n  #CHIP_NO_ERROR      If the "
            "method succeeded.\n  #CHIP_ERROR_INCORRECT_STATE\n                              If a corresponding StartContainer() "
            "call was not made.\n  #CHIP_ERROR_TLV_CONTAINER_OPEN\n                              If a container writer has been "
            "opened on the current writer and not\n                              yet closed.\n  #CHIP_ERROR_BUFFER_TOO_SMALL\n     "
            "                         If writing the value would exceed the limit on the maximum number of\n                       "
            "       bytes specified when the writer was initialized.\n  #CHIP_ERROR_NO_MEMORY\n                              If an "
            "attempt to allocate an output buffer failed due to lack of\n                              memory.\n  other            "
            "    Other CHIP or platform-specific errors returned by the configured\n                              "
            "TLVBackingStore.\n\n     \n\nC++: chip::TLV::TLVWriter::EndContainer(enum chip::TLV::TLVType) --> int",
            pybind11::arg("outerContainerType"));
        cl.def(
            "OpenContainer",
            (int (chip::TLV::TLVWriter::*)(unsigned long long, enum chip::TLV::TLVType, class chip::TLV::TLVWriter &)) &
                chip::TLV::TLVWriter::OpenContainer,
            "Initializes a new TLVWriter object for writing the members of a TLV container element.\n\n The OpenContainer() method "
            "is used to write TLV container elements (structure, arrays or paths)\n to an encoding.  The method takes the type and "
            "tag (if any) of the new container, and a reference\n to a new writer object (the container writer) that will be "
            "initialized for the purpose\n of writing the container's elements.  Applications write the members of the new "
            "container using\n the container writer and then call CloseContainer() to complete the container encoding.\n\n While "
            "the container writer is open, applications must not make calls on or otherwise alter the state\n of the parent "
            "writer.\n\n The container writer inherits various configuration properties from the parent writer.  These are:\n\n \n "
            "The implicit profile id (ImplicitProfileId)\n \n\n The application data pointer (AppData)\n \n\n The GetNewBuffer and "
            "FinalizeBuffer function pointers\n\n \n The StartContainer() method can be used as an alternative to OpenContainer() "
            "to write a\n container element without initializing a new writer object.\n\n \n             The TLV tag to be encoded "
            "with the container, or  if\n                              the container should be encoded without a tag.  Tag values "
            "should be\n                              constructed with one of the tag definition functions ProfileTag(),\n         "
            "                     ContextTag() or CommonTag().\n \n\n   The type of container to encode.  Must be one of \n        "
            "                       or \n \n\n A reference to a TLVWriter object that will be initialized for\n                    "
            "          writing the members of the new container element. Any data\n                              associated with "
            "the supplied object is overwritten.\n\n  #CHIP_NO_ERROR      If the method succeeded.\n  #CHIP_ERROR_WRONG_TLV_TYPE\n "
            "                             If the value specified for containerType is incorrect.\n  "
            "#CHIP_ERROR_TLV_CONTAINER_OPEN\n                              If a container writer has been opened on the current "
            "writer and not\n                              yet closed.\n  #CHIP_ERROR_INVALID_TLV_TAG\n                            "
            "  If the specified tag value is invalid or inappropriate in the context\n                              in which the "
            "value is being written.\n  #CHIP_ERROR_BUFFER_TOO_SMALL\n                              If writing the value would "
            "exceed the limit on the maximum number of\n                              bytes specified when the writer was "
            "initialized.\n  #CHIP_ERROR_NO_MEMORY\n                              If an attempt to allocate an output buffer "
            "failed due to lack of\n                              memory.\n  other                Other CHIP or platform-specific "
            "errors returned by the configured\n                              TLVBackingStore.\n\n     \n\nC++: "
            "chip::TLV::TLVWriter::OpenContainer(unsigned long long, enum chip::TLV::TLVType, class chip::TLV::TLVWriter &) --> "
            "int",
            pybind11::arg("tag"), pybind11::arg("containerType"), pybind11::arg("containerWriter"));
        cl.def(
            "CloseContainer", (int (chip::TLV::TLVWriter::*)(class chip::TLV::TLVWriter &)) & chip::TLV::TLVWriter::CloseContainer,
            "Completes the writing of a TLV container after a call to OpenContainer().\n\n The CloseContainer() method restores "
            "the state of a parent TLVWriter object after a call to\n OpenContainer().  For every call to OpenContainer() "
            "applications must make a corresponding\n call to CloseContainer(), passing a reference to the same container writer "
            "to both methods.\n\n When CloseContainer() returns, applications may continue to use the parent writer to write\n "
            "additional TLV elements that appear after the container element.  At this point the supplied\n container writer "
            "should be considered 'de-initialized' and must not be used without\n re-initialization.\n\n \n   A reference to the "
            "TLVWriter object that was supplied to the\n                              OpenContainer() method.\n\n  #CHIP_NO_ERROR  "
            "    If the method succeeded.\n  #CHIP_ERROR_INCORRECT_STATE\n                              If the supplied container "
            "writer is not in the correct state.\n  #CHIP_ERROR_TLV_CONTAINER_OPEN\n                              If another "
            "container writer has been opened on the supplied\n                              container writer and not yet "
            "closed.\n  #CHIP_ERROR_BUFFER_TOO_SMALL\n                              If completing the encoding of the container "
            "would exceed the\n                              limit on the maximum number of bytes specified when the writer\n      "
            "                        was initialized.\n  #CHIP_ERROR_NO_MEMORY\n                              If an attempt to "
            "allocate an output buffer failed due to lack\n                              of memory.\n  other                Other "
            "CHIP or platform-specific errors returned by the\n                              configured TLVBackingStore.\n\n     "
            "\n\nC++: chip::TLV::TLVWriter::CloseContainer(class chip::TLV::TLVWriter &) --> int",
            pybind11::arg("containerWriter"));
        cl.def(
            "PutPreEncodedContainer",
            (int (chip::TLV::TLVWriter::*)(unsigned long long, enum chip::TLV::TLVType, const unsigned char *, unsigned int)) &
                chip::TLV::TLVWriter::PutPreEncodedContainer,
            "Encodes a TLV container element from a pre-encoded set of member elements\n\n The PutPreEncodedContainer() method "
            "encodes a new TLV container element (a structure, array or path)\n containing a set of member elements taken from a "
            "pre-encoded buffer.  The input buffer is expected to\n contain zero or more full-encoded TLV elements, with tags that "
            "conform to the rules associated with\n the specified container type (e.g. structure members must have tags, while "
            "array members must not).\n\n The method encodes the entirety of the container element in one call.  When "
            "PutPreEncodedContainer()\n returns, the writer object can be used to write additional TLV elements following the "
            "container element.\n\n \n             The TLV tag to be encoded with the container, or  if\n                          "
            "    the container should be encoded without a tag.  Tag values should be\n                              constructed "
            "with one of the tag definition functions ProfileTag(),\n                              ContextTag() or CommonTag().\n "
            "\n\n   The type of container to encode.  Must be one of \n                               or \n \n\n            A "
            "pointer to a buffer containing zero of more encoded TLV elements that\n                              will become the "
            "members of the new container.\n \n\n         The number of bytes in the  buffer.\n\n  #CHIP_NO_ERROR      If the "
            "method succeeded.\n  #CHIP_ERROR_WRONG_TLV_TYPE\n                              If the value specified for "
            "containerType is incorrect.\n  #CHIP_ERROR_TLV_CONTAINER_OPEN\n                              If a container writer "
            "has been opened on the current writer and not\n                              yet closed.\n  "
            "#CHIP_ERROR_INVALID_TLV_TAG\n                              If the specified tag value is invalid or inappropriate in "
            "the context\n                              in which the value is being written.\n  #CHIP_ERROR_BUFFER_TOO_SMALL\n     "
            "                         If writing the value would exceed the limit on the maximum number of\n                       "
            "       bytes specified when the writer was initialized.\n  #CHIP_ERROR_NO_MEMORY\n                              If an "
            "attempt to allocate an output buffer failed due to lack of\n                              memory.\n  other            "
            "    Other CHIP or platform-specific errors returned by the configured\n                              "
            "TLVBackingStore.\n\n     \n\nC++: chip::TLV::TLVWriter::PutPreEncodedContainer(unsigned long long, enum "
            "chip::TLV::TLVType, const unsigned char *, unsigned int) --> int",
            pybind11::arg("tag"), pybind11::arg("containerType"), pybind11::arg("data"), pybind11::arg("dataLen"));
        cl.def(
            "CopyContainer", (int (chip::TLV::TLVWriter::*)(class chip::TLV::TLVReader &)) & chip::TLV::TLVWriter::CopyContainer,
            "Copies a TLV container element from TLVReader object\n\n The CopyContainer() encodes a new TLV container element by "
            "copying a pre-encoded container element\n located at the current position of a TLVReader object. The method writes "
            "the entirety of the new\n container element in one call, copying the container's type, tag and elements from the "
            "source\n encoding. When the method returns, the writer object can be used to write additional TLV elements\n "
            "following the container element.\n\n \n This method requires the supplied TVLReader object to be reading from a "
            "single, contiguous\n input buffer that contains the entirety of the underlying TLV encoding.\n\n \n       A reference "
            "to a TLVReader object identifying the pre-encoded TLV\n                              container to be copied.\n\n  "
            "#CHIP_NO_ERROR      If the method succeeded.\n  #CHIP_ERROR_INVALID_ARGUMENT\n                              If the "
            "supplied reader uses a TLVBackingStore rather than a simple buffer.\n  #CHIP_ERROR_INCORRECT_STATE\n                  "
            "            If the supplied reader is not positioned on a container element.\n  #CHIP_ERROR_TLV_CONTAINER_OPEN\n      "
            "                        If a container writer has been opened on the current writer and not\n                         "
            "     yet closed.\n  #CHIP_ERROR_TLV_UNDERRUN\n                              If the underlying TLV encoding associated "
            "with the supplied reader ended\n                              prematurely.\n  #CHIP_ERROR_INVALID_TLV_ELEMENT\n       "
            "                       If the supplied reader encountered an invalid or unsupported TLV element\n                     "
            "         type.\n  #CHIP_ERROR_INVALID_TLV_TAG\n                              If the supplied reader encountered a TLV "
            "tag in an invalid context,\n                              or if the tag associated with the source container is "
            "invalid or\n                              inappropriate in the context in which the new container is being written.\n "
            " #CHIP_ERROR_BUFFER_TOO_SMALL\n                              If writing the value would exceed the limit on the "
            "maximum number of\n                              bytes specified when the writer was initialized.\n  "
            "#CHIP_ERROR_NO_MEMORY\n                              If an attempt to allocate an output buffer failed due to lack "
            "of\n                              memory.\n  other                Other CHIP or platform-specific errors returned by "
            "the configured\n                              TLVBackingStore.\n\n     \n\nC++: "
            "chip::TLV::TLVWriter::CopyContainer(class chip::TLV::TLVReader &) --> int",
            pybind11::arg("container"));
        cl.def(
            "CopyContainer",
            (int (chip::TLV::TLVWriter::*)(unsigned long long, class chip::TLV::TLVReader &)) & chip::TLV::TLVWriter::CopyContainer,
            "Encodes a TLV container element from a pre-encoded set of member elements\n\n The CopyContainer() method encodes a "
            "new TLV container element (a structure, array or path)\n containing a set of member elements taken from a TLVReader "
            "object. When the method is called, the\n supplied reader object is expected to be positioned on a TLV container "
            "element. The newly encoded\n container will have the same type and members as the input container.  The tag for the "
            "new\n container is specified as an input parameter.\n\n When the method returns, the writer object can be used to "
            "write additional TLV elements following\n the container element.\n\n \n This method requires the supplied TVLReader "
            "object to be reading from a single, contiguous\n input buffer that contains the entirety of the underlying TLV "
            "encoding.\n\n \n             The TLV tag to be encoded with the container, or  if\n                              the "
            "container should be encoded without a tag.  Tag values should be\n                              constructed with one "
            "of the tag definition functions ProfileTag(),\n                              ContextTag() or CommonTag().\n \n\n      "
            " A reference to a TLVReader object identifying a pre-encoded TLV\n                              container whose type "
            "and members should be copied.\n\n  #CHIP_NO_ERROR      If the method succeeded.\n  #CHIP_ERROR_INVALID_ARGUMENT\n     "
            "                         If the supplied reader uses a TLVBackingStore rather than a simple buffer.\n  "
            "#CHIP_ERROR_INCORRECT_STATE\n                              If the supplied reader is not positioned on a container "
            "element.\n  #CHIP_ERROR_TLV_CONTAINER_OPEN\n                              If a container writer has been opened on "
            "the current writer and not\n                              yet closed.\n  #CHIP_ERROR_TLV_UNDERRUN\n                   "
            "           If the underlying TLV encoding associated with the supplied reader ended\n                              "
            "prematurely.\n  #CHIP_ERROR_INVALID_TLV_ELEMENT\n                              If the supplied reader encountered an "
            "invalid or unsupported TLV element\n                              type.\n  #CHIP_ERROR_INVALID_TLV_TAG\n              "
            "                If the supplied reader encountered a TLV tag in an invalid context,\n                              or "
            "if the supplied tag is invalid or inappropriate in the context in\n                              which the new "
            "container is being written.\n  #CHIP_ERROR_BUFFER_TOO_SMALL\n                              If writing the value would "
            "exceed the limit on the maximum number of\n                              bytes specified when the writer was "
            "initialized.\n  #CHIP_ERROR_NO_MEMORY\n                              If an attempt to allocate an output buffer "
            "failed due to lack of\n                              memory.\n  other                Other CHIP or platform-specific "
            "errors returned by the configured\n                              TLVBackingStore.\n\n     \n\nC++: "
            "chip::TLV::TLVWriter::CopyContainer(unsigned long long, class chip::TLV::TLVReader &) --> int",
            pybind11::arg("tag"), pybind11::arg("container"));
        cl.def(
            "CopyContainer",
            (int (chip::TLV::TLVWriter::*)(unsigned long long, const unsigned char *, unsigned short)) &
                chip::TLV::TLVWriter::CopyContainer,
            "Encodes a TLV container element that contains member elements from a pre-encoded container\n\n The CopyContainer() "
            "method encodes a new TLV container element (a structure, array or path)\n containing a set of member elements taken "
            "from the contents of a supplied pre-encoded container.\n When the method is called, data in the supplied input buffer "
            "is parsed as a TLV container element\n an a new container is written that has the same type and members as the input "
            "container.  The tag\n for the new container is specified as an input parameter.\n\n When the method returns, the "
            "writer object can be used to write additional TLV elements following\n the container element.\n\n \n                  "
            " The TLV tag to be encoded with the container, or  if\n                                  the container should be "
            "encoded without a tag.  Tag values should be\n                                  constructed with one of the tag "
            "definition functions ProfileTag(),\n                                  ContextTag() or CommonTag().\n \n\n      A "
            "buffer containing a pre-encoded TLV container whose type and members\n                                  should be "
            "copied.\n \n\n   The length in bytes of the pre-encoded container.\n\n  #CHIP_NO_ERROR          If the method "
            "succeeded.\n  #CHIP_ERROR_TLV_CONTAINER_OPEN\n                                  If a container writer has been opened "
            "on the current writer and not\n                                  yet closed.\n  #CHIP_ERROR_TLV_UNDERRUN\n            "
            "                      If the encoded container ended prematurely.\n  #CHIP_ERROR_INVALID_TLV_ELEMENT\n                "
            "                  If the encoded container contained an invalid or unsupported TLV element type.\n  "
            "#CHIP_ERROR_INVALID_TLV_TAG\n                                  If the encoded container contained a TLV tag in an "
            "invalid context,\n                                  or if the supplied tag is invalid or inappropriate in the context "
            "in\n                                  which the new container is being written.\n  #CHIP_ERROR_BUFFER_TOO_SMALL\n     "
            "                             If writing the value would exceed the limit on the maximum number of\n                   "
            "               bytes specified when the writer was initialized.\n  #CHIP_ERROR_NO_MEMORY\n                            "
            "      If an attempt to allocate an output buffer failed due to lack of\n                                  memory.\n  "
            "other                    Other CHIP or platform-specific errors returned by the configured\n                          "
            "        TLVBackingStore.\n\n     \n\nC++: chip::TLV::TLVWriter::CopyContainer(unsigned long long, const unsigned char "
            "*, unsigned short) --> int",
            pybind11::arg("tag"), pybind11::arg("encodedContainer"), pybind11::arg("encodedContainerLen"));
        cl.def("GetContainerType",
               (enum chip::TLV::TLVType(chip::TLV::TLVWriter::*)() const) & chip::TLV::TLVWriter::GetContainerType,
               "Returns the type of container within which the TLVWriter is currently writing.\n\n The GetContainerType() method "
               "returns the type of the TLV container within which the TLVWriter\n is currently writing.  If the TLVWriter is not "
               "writing elements within a container (i.e. if writing\n at the outer-most level of an encoding) the method returns "
               "kTLVType_NotSpecified.\n\n \n  The TLVType of the current container, or kTLVType_NotSpecified if the TLVWriter is "
               "not\n          writing elements within a container.\n\nC++: chip::TLV::TLVWriter::GetContainerType() const --> "
               "enum chip::TLV::TLVType");
        cl.def("GetLengthWritten", (unsigned int (chip::TLV::TLVWriter::*)() const) & chip::TLV::TLVWriter::GetLengthWritten,
               "Returns the total number of bytes written since the writer was initialized.\n\n \n Total number of bytes written "
               "since the writer was initialized.\n\nC++: chip::TLV::TLVWriter::GetLengthWritten() const --> unsigned int");
        cl.def("GetRemainingFreeLength",
               (unsigned int (chip::TLV::TLVWriter::*)() const) & chip::TLV::TLVWriter::GetRemainingFreeLength,
               "Returns the total remaining number of bytes for current tlv writer\n\n \n the total remaining number of "
               "bytes.\n\nC++: chip::TLV::TLVWriter::GetRemainingFreeLength() const --> unsigned int");
    }
}
