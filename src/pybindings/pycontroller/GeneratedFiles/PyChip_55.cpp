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

void bind_PyChip_55(std::function<pybind11::module &(std::string const & namespace_)> & M)
{
    { // chip::TLV::TLVUpdater file:core/CHIPTLV.h line:1913
        pybind11::class_<chip::TLV::TLVUpdater, std::shared_ptr<chip::TLV::TLVUpdater>> cl(
            M("chip::TLV"), "TLVUpdater",
            "Provides a unified Reader/Writer interface for editing/adding/deleting elements in TLV encoding.\n\n The TLVUpdater "
            "is a union of the TLVReader and TLVWriter objects and provides interface methods\n for editing/deleting data in an "
            "encoding as well as adding new elements to the TLV encoding. The\n TLVUpdater object essentially acts like two "
            "cursors, one for reading existing encoding and\n another for writing (either for copying over existing data or "
            "writing new data).\n\n Semantically, the TLVUpdater object functions like a union of the TLVReader and TLVWriter. "
            "The\n TLVUpdater methods have more or less similar meanings as similarly named counterparts in\n TLVReader/TLVWriter. "
            "Where there are differences in the semantics, the differences are clearly\n documented in the function's comment "
            "section in CHIPTLVUpdater.cpp.\n\n One particularly important note about the TLVUpdater's PutBytes() and PutString() "
            "methods is that\n it can leave the encoding in a corrupt state with only the element header written when an\n "
            "overflow occurs. Applications can call GetRemainingFreeLength() to make sure there is\n  enough free space to write "
            "the encoding. Note that GetRemainingFreeLength()\n only tells you the available free bytes and there is  way for the "
            "application to know the\n length of encoded data that gets written. In the event of an overflow, both PutBytes() "
            "and\n PutString() will return CHIP_ERROR_BUFFER_TOO_SMALL to the caller.\n\n Also, note that Next() method is "
            "overloaded to both skip the current element and also advance the\n internal reader to the next element. Because "
            "skipping already encoded elements requires changing\n the internal writer's free space state variables to account for "
            "the new freed space (made\n available by skipping), the application is expected to call Next() on the updater after a "
            "Get()\n method whose value it doesn't wish to write back (which is equivalent to skipping the current\n element).\n\n "
            "\n The application is expected to use the TLVUpdater object atomically from the time it calls\n Init() till it calls "
            "Finalize(). The same buffer should NOT be used with other TLVWriter objects.\n\n \n The TLVUpdater currently only "
            "supports single static buffers. TLVBackingStore is NOT supported.");
        cl.def(pybind11::init([]() { return new chip::TLV::TLVUpdater(); }));
        cl.def("Init", (int (chip::TLV::TLVUpdater::*)(unsigned char *, unsigned int, unsigned int)) & chip::TLV::TLVUpdater::Init,
               "Initialize a TLVUpdater object to edit a single input buffer.\n\n On calling this method, the TLV data in the "
               "buffer is moved to the end of the\n buffer and a private TLVReader object is initialized on this relocated\n "
               "buffer. A private TLVWriter object is also initialized on the free space that\n is now available at the beginning. "
               "Applications can use the TLVUpdater object\n to parse the TLV data and modify/delete existing elements or add new "
               "elements\n to the encoding.\n\n \n     A pointer to a buffer containing the TLV data to be edited.\n \n\n The "
               "length of the TLV data in the buffer.\n \n\n  The total length of the buffer.\n\n  #CHIP_NO_ERROR                  "
               "If the method succeeded.\n  #CHIP_ERROR_INVALID_ARGUMENT    If the buffer address is invalid.\n  "
               "#CHIP_ERROR_BUFFER_TOO_SMALL    If the buffer is too small.\n\n     \n\nC++: chip::TLV::TLVUpdater::Init(unsigned "
               "char *, unsigned int, unsigned int) --> int",
               pybind11::arg("buf"), pybind11::arg("dataLen"), pybind11::arg("maxLen"));
        cl.def("Init", (int (chip::TLV::TLVUpdater::*)(class chip::TLV::TLVReader &, unsigned int)) & chip::TLV::TLVUpdater::Init,
               "Initialize a TLVUpdater object using a TLVReader.\n\n On calling this method, TLV data in the buffer pointed to by "
               "the TLVReader\n is moved from the current read point to the end of the buffer. A new\n private TLVReader object is "
               "initialized to read from this new location, while\n a new private TLVWriter object is initialized to write to the "
               "freed up buffer\n space.\n\n Note that if the TLVReader is already positioned \"on\" an element, it is first\n "
               "backed-off to the start of that element. Also note that this backing off\n works well with container elements, "
               "i.e., if the TLVReader was already  used\n to call EnterContainer(), then there is nothing to back-off. But if "
               "the\n TLVReader was positioned on the container element and EnterContainer() was\n not yet called, then the "
               "TLVReader object is backed-off to the start of the\n container head.\n\n The input TLVReader object will be "
               "destroyed before returning and the\n application must not make use of the same on return.\n\n \n     Reference to "
               "a TLVReader object that will be\n                              destroyed before returning.\n \n\n     The length "
               "of free space (in bytes) available\n                              in the pre-encoded data buffer.\n\n  "
               "#CHIP_NO_ERROR                  If the method succeeded.\n  #CHIP_ERROR_INVALID_ARGUMENT    If the buffer address "
               "is invalid.\n  #CHIP_ERROR_NOT_IMPLEMENTED     If reader was initialized on a chain\n                              "
               "            of buffers.\n\nC++: chip::TLV::TLVUpdater::Init(class chip::TLV::TLVReader &, unsigned int) --> int",
               pybind11::arg("aReader"), pybind11::arg("freeLen"));
        cl.def("Finalize", (int (chip::TLV::TLVUpdater::*)()) & chip::TLV::TLVUpdater::Finalize,
               "C++: chip::TLV::TLVUpdater::Finalize() --> int");
        cl.def("SetImplicitProfileId",
               (void (chip::TLV::TLVUpdater::*)(unsigned int)) & chip::TLV::TLVUpdater::SetImplicitProfileId,
               "Set the Implicit Profile ID for the TLVUpdater object.\n\n This method sets the implicit profile ID for the "
               "TLVUpdater object. When the\n updater is asked to encode a new element, if the profile ID of the tag\n associated "
               "with the new element matches the value of the  the\n updater will encode the tag in implicit form, thereby "
               "omitting the profile ID\n in the process.\n\n \n   The profile id of tags that should be encoded in\n              "
               "            implicit form.\n\nC++: chip::TLV::TLVUpdater::SetImplicitProfileId(unsigned int) --> void",
               pybind11::arg("profileId"));
        cl.def("GetImplicitProfileId", (unsigned int (chip::TLV::TLVUpdater::*)()) & chip::TLV::TLVUpdater::GetImplicitProfileId,
               "C++: chip::TLV::TLVUpdater::GetImplicitProfileId() --> unsigned int");
        cl.def("Move", (int (chip::TLV::TLVUpdater::*)()) & chip::TLV::TLVUpdater::Move,
               "Copies the current element from input TLV to output TLV.\n\n The Move() method copies the current element on which "
               "the TLVUpdater's reader\n is positioned on, to the TLVUpdater's writer. The application should call\n Next() and "
               "position the TLVUpdater's reader on an element before calling this\n method. Just like the TLVReader::Next() "
               "method, if the reader is positioned\n on a container element at the time of the call, all the members of the\n "
               "container will be copied. If the reader is not positioned on any element,\n nothing changes on calling this "
               "method.\n\n  #CHIP_NO_ERROR              If the TLVUpdater reader was\n                                      "
               "successfully positioned on a new\n                                      element.\n  #CHIP_END_OF_TLV            If "
               "the TLVUpdater's reader is pointing\n                                      to end of container.\n  "
               "#CHIP_ERROR_INVALID_TLV_ELEMENT\n                                      If the TLVIpdater's reader is not\n         "
               "                             positioned on a valid TLV element.\n  other                        Returns other "
               "error codes returned by\n                                      TLVReader::Skip() method.\n\n     \n\nC++: "
               "chip::TLV::TLVUpdater::Move() --> int");
        cl.def("MoveUntilEnd", (void (chip::TLV::TLVUpdater::*)()) & chip::TLV::TLVUpdater::MoveUntilEnd,
               "Move everything from the TLVUpdater's current read point till end of input\n TLV buffer over to output.\n\n This "
               "method supports moving everything from the TLVUpdater's current read\n point till the end of the reader buffer "
               "over to the TLVUpdater's writer.\n\n \n This method can be called with the TLVUpdater's reader positioned\n "
               "anywhere within the input TLV. The reader can also be positioned under\n multiple levels of nested containers and "
               "this method will still work.\n\n \n This method also changes the state of the TLVUpdater object to a state\n it "
               "would be in if the application had painstakingly parsed each element from\n the current read point till the end of "
               "the input encoding and copied them to\n the output TLV.\n\nC++: chip::TLV::TLVUpdater::MoveUntilEnd() --> void");
        cl.def("EnterContainer",
               (int (chip::TLV::TLVUpdater::*)(enum chip::TLV::TLVType &)) & chip::TLV::TLVUpdater::EnterContainer,
               "Prepares a TLVUpdater object for reading elements of a container. It also\n encodes a start of container object in "
               "the output TLV.\n\n The EnterContainer() method prepares the current TLVUpdater object to begin\n reading the "
               "member elements of a TLV container (a structure, array or path).\n For every call to EnterContainer() applications "
               "must make a corresponding\n call to ExitContainer().\n\n When EnterContainer() is called the TLVUpdater's reader "
               "must be positioned on\n the container element. The method takes as an argument a reference to a\n TLVType value "
               "which will be used to save the context of the updater while it\n is reading the container.\n\n When the "
               "EnterContainer() method returns, the updater is positioned\n immediately  the first member of the container. "
               "Repeatedly calling\n Next() will advance the updater through the members of the collection until\n the end is "
               "reached, at which point the updater will return CHIP_END_OF_TLV.\n\n Once the application has finished reading a "
               "container it can continue reading\n the elements after the container by calling the ExitContainer() method.\n\n \n "
               "This method implicitly encodes a start of container element in the\n output TLV buffer.\n\n \n       A reference "
               "to a TLVType value that will\n                                      receive the context of the updater.\n\n  "
               "#CHIP_NO_ERROR              If the method succeeded.\n  #CHIP_ERROR_INCORRECT_STATE If the TLVUpdater reader is "
               "not\n                                      positioned on a container element.\n  other                        Any "
               "other CHIP or platform error code\n                                      returned by TLVWriter::StartContainer()\n "
               "                                     or TLVReader::EnterContainer().\n\n     \n\nC++: "
               "chip::TLV::TLVUpdater::EnterContainer(enum chip::TLV::TLVType &) --> int",
               pybind11::arg("outerContainerType"));
        cl.def("ExitContainer", (int (chip::TLV::TLVUpdater::*)(enum chip::TLV::TLVType)) & chip::TLV::TLVUpdater::ExitContainer,
               "Completes the reading of a TLV container element and encodes an end of TLV\n element in the output TLV.\n\n The "
               "ExitContainer() method restores the state of a TLVUpdater object after a\n call to EnterContainer(). For every "
               "call to EnterContainer() applications\n must make a corresponding call to ExitContainer(), passing the context "
               "value\n returned by the EnterContainer() method.\n\n When ExitContainer() returns, the TLVUpdater reader is "
               "positioned immediately\n before the first element that follows the container in the input TLV. From\n this point "
               "applications can call Next() to advance through any remaining\n elements.\n\n Once EnterContainer() has been "
               "called, applications can call ExitContainer()\n on the updater at any point in time, regardless of whether all "
               "elements in\n the underlying container have been read. Also, note that calling\n ExitContainer() before reading "
               "all the elements in the container, will result\n in the updated container getting truncated in the output TLV.\n\n "
               "\n Any changes made to the configuration of the updater between the calls\n to EnterContainer() and "
               "ExitContainer() are NOT undone by the call to\n ExitContainer(). For example, a change to the implicit profile "
               "id\n ( will not be reversed when a container is exited. Thus\n it is the application's responsibility to adjust "
               "the configuration\n accordingly at the appropriate times.\n\n \n        The TLVType value that was returned by\n   "
               "                                   the EnterContainer() method.\n\n  #CHIP_NO_ERROR              If the method "
               "succeeded.\n  #CHIP_ERROR_TLV_UNDERRUN    If the underlying TLV encoding ended\n                                   "
               "   prematurely.\n  #CHIP_ERROR_INVALID_TLV_ELEMENT\n                                      If the updater "
               "encountered an invalid or\n                                      unsupported TLV element type.\n  "
               "#CHIP_ERROR_INVALID_TLV_TAG If the updater encountered a TLV tag in\n                                      an "
               "invalid context.\n  other                        Any other CHIP or platform error code\n                           "
               "           returned by TLVWriter::EndContainer() or\n                                      "
               "TLVReader::ExitContainer().\n\n     \n\nC++: chip::TLV::TLVUpdater::ExitContainer(enum chip::TLV::TLVType) --> int",
               pybind11::arg("outerContainerType"));
        cl.def("GetReader", (void (chip::TLV::TLVUpdater::*)(class chip::TLV::TLVReader &)) & chip::TLV::TLVUpdater::GetReader,
               "C++: chip::TLV::TLVUpdater::GetReader(class chip::TLV::TLVReader &) --> void", pybind11::arg("containerReader"));
        cl.def("Next", (int (chip::TLV::TLVUpdater::*)()) & chip::TLV::TLVUpdater::Next,
               "Skip the current element and advance the TLVUpdater object to the next\n element in the input TLV.\n\n The Next() "
               "method skips the current element in the input TLV and advances the\n TLVUpdater's reader to the next element that "
               "resides in the same containment\n context. In particular, if the reader is positioned at the outer most level\n of "
               "a TLV encoding, calling Next() will advance it to the next, top most\n element. If the reader is positioned within "
               "a TLV container element (a\n structure, array or path), calling Next() will advance it to the next member\n "
               "element of the container.\n\n Since Next() constrains reader motion to the current containment context,\n calling "
               "Next() when the reader is positioned on a container element will\n advance  the container, skipping its member "
               "elements (and the members\n of any nested containers) until it reaches the first element after the\n "
               "container.\n\n When there are no further elements within a particular containment context\n the Next() method will "
               "return a #CHIP_END_OF_TLV error and the position of\n the reader will remain unchanged.\n\n \n The Next() method "
               "implicitly skips the current element. Hence, the\n TLVUpdater's private writer state variables will be adjusted to "
               "account for\n the new freed space (made available by skipping). This means that the\n application is expected to "
               "call Next() on the TLVUpdater object after a Get()\n whose value the application does  write back (which from "
               "the\n TLVUpdater's view is equivalent to skipping that element).\n\n \n Applications are also expected to call "
               "Next() when they are at the end\n of a container, and want to add new elements there. This is particularly\n "
               "important in situations where there is a fixed schema. Applications that have\n fixed schemas and know where the "
               "container end is cannot just add new\n elements at the end, because the TLVUpdater writer's state will not "
               "reflect\n the correct free space available for the Put() operation. Hence, applications\n must call Next() (and "
               "possibly also test for CHIP_END_OF_TLV) before adding\n elements at the end of a container.\n\n  #CHIP_NO_ERROR    "
               "          If the TLVUpdater reader was\n                                      successfully positioned on a new\n   "
               "                                   element.\n  other                        Returns the CHIP or platform error\n   "
               "                                   codes returned by the TLVReader::Skip()\n                                      "
               "and TLVReader::Next() method.\n\n     \n\nC++: chip::TLV::TLVUpdater::Next() --> int");
        cl.def("Get", (int (chip::TLV::TLVUpdater::*)(bool &)) & chip::TLV::TLVUpdater::Get,
               "C++: chip::TLV::TLVUpdater::Get(bool &) --> int", pybind11::arg("v"));
        cl.def("Get", (int (chip::TLV::TLVUpdater::*)(signed char &)) & chip::TLV::TLVUpdater::Get,
               "C++: chip::TLV::TLVUpdater::Get(signed char &) --> int", pybind11::arg("v"));
        cl.def("Get", (int (chip::TLV::TLVUpdater::*)(short &)) & chip::TLV::TLVUpdater::Get,
               "C++: chip::TLV::TLVUpdater::Get(short &) --> int", pybind11::arg("v"));
        cl.def("Get", (int (chip::TLV::TLVUpdater::*)(int &)) & chip::TLV::TLVUpdater::Get,
               "C++: chip::TLV::TLVUpdater::Get(int &) --> int", pybind11::arg("v"));
        cl.def("Get", (int (chip::TLV::TLVUpdater::*)(long long &)) & chip::TLV::TLVUpdater::Get,
               "C++: chip::TLV::TLVUpdater::Get(long long &) --> int", pybind11::arg("v"));
        cl.def("Get", (int (chip::TLV::TLVUpdater::*)(unsigned char &)) & chip::TLV::TLVUpdater::Get,
               "C++: chip::TLV::TLVUpdater::Get(unsigned char &) --> int", pybind11::arg("v"));
        cl.def("Get", (int (chip::TLV::TLVUpdater::*)(unsigned short &)) & chip::TLV::TLVUpdater::Get,
               "C++: chip::TLV::TLVUpdater::Get(unsigned short &) --> int", pybind11::arg("v"));
        cl.def("Get", (int (chip::TLV::TLVUpdater::*)(unsigned int &)) & chip::TLV::TLVUpdater::Get,
               "C++: chip::TLV::TLVUpdater::Get(unsigned int &) --> int", pybind11::arg("v"));
        cl.def("Get", (int (chip::TLV::TLVUpdater::*)(unsigned long long &)) & chip::TLV::TLVUpdater::Get,
               "C++: chip::TLV::TLVUpdater::Get(unsigned long long &) --> int", pybind11::arg("v"));
        cl.def("Get", (int (chip::TLV::TLVUpdater::*)(float &)) & chip::TLV::TLVUpdater::Get,
               "C++: chip::TLV::TLVUpdater::Get(float &) --> int", pybind11::arg("v"));
        cl.def("Get", (int (chip::TLV::TLVUpdater::*)(double &)) & chip::TLV::TLVUpdater::Get,
               "C++: chip::TLV::TLVUpdater::Get(double &) --> int", pybind11::arg("v"));
        cl.def("GetBytes", (int (chip::TLV::TLVUpdater::*)(unsigned char *, unsigned int)) & chip::TLV::TLVUpdater::GetBytes,
               "C++: chip::TLV::TLVUpdater::GetBytes(unsigned char *, unsigned int) --> int", pybind11::arg("buf"),
               pybind11::arg("bufSize"));
        cl.def("DupBytes", (int (chip::TLV::TLVUpdater::*)(unsigned char *&, unsigned int &)) & chip::TLV::TLVUpdater::DupBytes,
               "C++: chip::TLV::TLVUpdater::DupBytes(unsigned char *&, unsigned int &) --> int", pybind11::arg("buf"),
               pybind11::arg("dataLen"));
        cl.def("GetString", (int (chip::TLV::TLVUpdater::*)(char *, unsigned int)) & chip::TLV::TLVUpdater::GetString,
               "C++: chip::TLV::TLVUpdater::GetString(char *, unsigned int) --> int", pybind11::arg("buf"),
               pybind11::arg("bufSize"));
        cl.def("DupString", (int (chip::TLV::TLVUpdater::*)(char *&)) & chip::TLV::TLVUpdater::DupString,
               "C++: chip::TLV::TLVUpdater::DupString(char *&) --> int", pybind11::arg("buf"));
        cl.def("GetType", (enum chip::TLV::TLVType(chip::TLV::TLVUpdater::*)() const) & chip::TLV::TLVUpdater::GetType,
               "C++: chip::TLV::TLVUpdater::GetType() const --> enum chip::TLV::TLVType");
        cl.def("GetTag", (unsigned long long (chip::TLV::TLVUpdater::*)() const) & chip::TLV::TLVUpdater::GetTag,
               "C++: chip::TLV::TLVUpdater::GetTag() const --> unsigned long long");
        cl.def("GetLength", (unsigned int (chip::TLV::TLVUpdater::*)() const) & chip::TLV::TLVUpdater::GetLength,
               "C++: chip::TLV::TLVUpdater::GetLength() const --> unsigned int");
        cl.def("GetDataPtr", (int (chip::TLV::TLVUpdater::*)(const unsigned char *&)) & chip::TLV::TLVUpdater::GetDataPtr,
               "C++: chip::TLV::TLVUpdater::GetDataPtr(const unsigned char *&) --> int", pybind11::arg("data"));
        cl.def("VerifyEndOfContainer", (int (chip::TLV::TLVUpdater::*)()) & chip::TLV::TLVUpdater::VerifyEndOfContainer,
               "C++: chip::TLV::TLVUpdater::VerifyEndOfContainer() --> int");
        cl.def("GetContainerType",
               (enum chip::TLV::TLVType(chip::TLV::TLVUpdater::*)() const) & chip::TLV::TLVUpdater::GetContainerType,
               "C++: chip::TLV::TLVUpdater::GetContainerType() const --> enum chip::TLV::TLVType");
        cl.def("GetLengthRead", (unsigned int (chip::TLV::TLVUpdater::*)() const) & chip::TLV::TLVUpdater::GetLengthRead,
               "C++: chip::TLV::TLVUpdater::GetLengthRead() const --> unsigned int");
        cl.def("GetRemainingLength", (unsigned int (chip::TLV::TLVUpdater::*)() const) & chip::TLV::TLVUpdater::GetRemainingLength,
               "C++: chip::TLV::TLVUpdater::GetRemainingLength() const --> unsigned int");
        cl.def("Put", (int (chip::TLV::TLVUpdater::*)(unsigned long long, signed char)) & chip::TLV::TLVUpdater::Put,
               "C++: chip::TLV::TLVUpdater::Put(unsigned long long, signed char) --> int", pybind11::arg("tag"),
               pybind11::arg("v"));
        cl.def("Put", (int (chip::TLV::TLVUpdater::*)(unsigned long long, short)) & chip::TLV::TLVUpdater::Put,
               "C++: chip::TLV::TLVUpdater::Put(unsigned long long, short) --> int", pybind11::arg("tag"), pybind11::arg("v"));
        cl.def("Put", (int (chip::TLV::TLVUpdater::*)(unsigned long long, int)) & chip::TLV::TLVUpdater::Put,
               "C++: chip::TLV::TLVUpdater::Put(unsigned long long, int) --> int", pybind11::arg("tag"), pybind11::arg("v"));
        cl.def("Put", (int (chip::TLV::TLVUpdater::*)(unsigned long long, long long)) & chip::TLV::TLVUpdater::Put,
               "C++: chip::TLV::TLVUpdater::Put(unsigned long long, long long) --> int", pybind11::arg("tag"), pybind11::arg("v"));
        cl.def("Put", (int (chip::TLV::TLVUpdater::*)(unsigned long long, unsigned char)) & chip::TLV::TLVUpdater::Put,
               "C++: chip::TLV::TLVUpdater::Put(unsigned long long, unsigned char) --> int", pybind11::arg("tag"),
               pybind11::arg("v"));
        cl.def("Put", (int (chip::TLV::TLVUpdater::*)(unsigned long long, unsigned short)) & chip::TLV::TLVUpdater::Put,
               "C++: chip::TLV::TLVUpdater::Put(unsigned long long, unsigned short) --> int", pybind11::arg("tag"),
               pybind11::arg("v"));
        cl.def("Put", (int (chip::TLV::TLVUpdater::*)(unsigned long long, unsigned int)) & chip::TLV::TLVUpdater::Put,
               "C++: chip::TLV::TLVUpdater::Put(unsigned long long, unsigned int) --> int", pybind11::arg("tag"),
               pybind11::arg("v"));
        cl.def("Put", (int (chip::TLV::TLVUpdater::*)(unsigned long long, unsigned long long)) & chip::TLV::TLVUpdater::Put,
               "C++: chip::TLV::TLVUpdater::Put(unsigned long long, unsigned long long) --> int", pybind11::arg("tag"),
               pybind11::arg("v"));
        cl.def("Put", (int (chip::TLV::TLVUpdater::*)(unsigned long long, signed char, bool)) & chip::TLV::TLVUpdater::Put,
               "C++: chip::TLV::TLVUpdater::Put(unsigned long long, signed char, bool) --> int", pybind11::arg("tag"),
               pybind11::arg("v"), pybind11::arg("preserveSize"));
        cl.def("Put", (int (chip::TLV::TLVUpdater::*)(unsigned long long, short, bool)) & chip::TLV::TLVUpdater::Put,
               "C++: chip::TLV::TLVUpdater::Put(unsigned long long, short, bool) --> int", pybind11::arg("tag"), pybind11::arg("v"),
               pybind11::arg("preserveSize"));
        cl.def("Put", (int (chip::TLV::TLVUpdater::*)(unsigned long long, int, bool)) & chip::TLV::TLVUpdater::Put,
               "C++: chip::TLV::TLVUpdater::Put(unsigned long long, int, bool) --> int", pybind11::arg("tag"), pybind11::arg("v"),
               pybind11::arg("preserveSize"));
        cl.def("Put", (int (chip::TLV::TLVUpdater::*)(unsigned long long, long long, bool)) & chip::TLV::TLVUpdater::Put,
               "C++: chip::TLV::TLVUpdater::Put(unsigned long long, long long, bool) --> int", pybind11::arg("tag"),
               pybind11::arg("v"), pybind11::arg("preserveSize"));
        cl.def("Put", (int (chip::TLV::TLVUpdater::*)(unsigned long long, unsigned char, bool)) & chip::TLV::TLVUpdater::Put,
               "C++: chip::TLV::TLVUpdater::Put(unsigned long long, unsigned char, bool) --> int", pybind11::arg("tag"),
               pybind11::arg("v"), pybind11::arg("preserveSize"));
        cl.def("Put", (int (chip::TLV::TLVUpdater::*)(unsigned long long, unsigned short, bool)) & chip::TLV::TLVUpdater::Put,
               "C++: chip::TLV::TLVUpdater::Put(unsigned long long, unsigned short, bool) --> int", pybind11::arg("tag"),
               pybind11::arg("v"), pybind11::arg("preserveSize"));
        cl.def("Put", (int (chip::TLV::TLVUpdater::*)(unsigned long long, unsigned int, bool)) & chip::TLV::TLVUpdater::Put,
               "C++: chip::TLV::TLVUpdater::Put(unsigned long long, unsigned int, bool) --> int", pybind11::arg("tag"),
               pybind11::arg("v"), pybind11::arg("preserveSize"));
        cl.def("Put", (int (chip::TLV::TLVUpdater::*)(unsigned long long, unsigned long long, bool)) & chip::TLV::TLVUpdater::Put,
               "C++: chip::TLV::TLVUpdater::Put(unsigned long long, unsigned long long, bool) --> int", pybind11::arg("tag"),
               pybind11::arg("v"), pybind11::arg("preserveSize"));
        cl.def("Put", (int (chip::TLV::TLVUpdater::*)(unsigned long long, float)) & chip::TLV::TLVUpdater::Put,
               "C++: chip::TLV::TLVUpdater::Put(unsigned long long, float) --> int", pybind11::arg("tag"), pybind11::arg("v"));
        cl.def("Put", (int (chip::TLV::TLVUpdater::*)(unsigned long long, double)) & chip::TLV::TLVUpdater::Put,
               "C++: chip::TLV::TLVUpdater::Put(unsigned long long, double) --> int", pybind11::arg("tag"), pybind11::arg("v"));
        cl.def("PutBoolean", (int (chip::TLV::TLVUpdater::*)(unsigned long long, bool)) & chip::TLV::TLVUpdater::PutBoolean,
               "C++: chip::TLV::TLVUpdater::PutBoolean(unsigned long long, bool) --> int", pybind11::arg("tag"),
               pybind11::arg("v"));
        cl.def("PutNull", (int (chip::TLV::TLVUpdater::*)(unsigned long long)) & chip::TLV::TLVUpdater::PutNull,
               "C++: chip::TLV::TLVUpdater::PutNull(unsigned long long) --> int", pybind11::arg("tag"));
        cl.def("PutBytes",
               (int (chip::TLV::TLVUpdater::*)(unsigned long long, const unsigned char *, unsigned int)) &
                   chip::TLV::TLVUpdater::PutBytes,
               "C++: chip::TLV::TLVUpdater::PutBytes(unsigned long long, const unsigned char *, unsigned int) --> int",
               pybind11::arg("tag"), pybind11::arg("buf"), pybind11::arg("len"));
        cl.def("PutString", (int (chip::TLV::TLVUpdater::*)(unsigned long long, const char *)) & chip::TLV::TLVUpdater::PutString,
               "C++: chip::TLV::TLVUpdater::PutString(unsigned long long, const char *) --> int", pybind11::arg("tag"),
               pybind11::arg("buf"));
        cl.def("PutString",
               (int (chip::TLV::TLVUpdater::*)(unsigned long long, const char *, unsigned int)) & chip::TLV::TLVUpdater::PutString,
               "C++: chip::TLV::TLVUpdater::PutString(unsigned long long, const char *, unsigned int) --> int",
               pybind11::arg("tag"), pybind11::arg("buf"), pybind11::arg("len"));
        cl.def("CopyElement", (int (chip::TLV::TLVUpdater::*)(class chip::TLV::TLVReader &)) & chip::TLV::TLVUpdater::CopyElement,
               "C++: chip::TLV::TLVUpdater::CopyElement(class chip::TLV::TLVReader &) --> int", pybind11::arg("reader"));
        cl.def("CopyElement",
               (int (chip::TLV::TLVUpdater::*)(unsigned long long, class chip::TLV::TLVReader &)) &
                   chip::TLV::TLVUpdater::CopyElement,
               "C++: chip::TLV::TLVUpdater::CopyElement(unsigned long long, class chip::TLV::TLVReader &) --> int",
               pybind11::arg("tag"), pybind11::arg("reader"));
        cl.def("StartContainer",
               (int (chip::TLV::TLVUpdater::*)(unsigned long long, enum chip::TLV::TLVType, enum chip::TLV::TLVType &)) &
                   chip::TLV::TLVUpdater::StartContainer,
               "C++: chip::TLV::TLVUpdater::StartContainer(unsigned long long, enum chip::TLV::TLVType, enum chip::TLV::TLVType &) "
               "--> int",
               pybind11::arg("tag"), pybind11::arg("containerType"), pybind11::arg("outerContainerType"));
        cl.def("EndContainer", (int (chip::TLV::TLVUpdater::*)(enum chip::TLV::TLVType)) & chip::TLV::TLVUpdater::EndContainer,
               "C++: chip::TLV::TLVUpdater::EndContainer(enum chip::TLV::TLVType) --> int", pybind11::arg("outerContainerType"));
        cl.def("GetLengthWritten", (unsigned int (chip::TLV::TLVUpdater::*)()) & chip::TLV::TLVUpdater::GetLengthWritten,
               "C++: chip::TLV::TLVUpdater::GetLengthWritten() --> unsigned int");
        cl.def("GetRemainingFreeLength",
               (unsigned int (chip::TLV::TLVUpdater::*)()) & chip::TLV::TLVUpdater::GetRemainingFreeLength,
               "C++: chip::TLV::TLVUpdater::GetRemainingFreeLength() --> unsigned int");
    }
}
