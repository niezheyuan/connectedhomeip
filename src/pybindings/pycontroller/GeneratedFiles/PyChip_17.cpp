#include <sstream> // __str__
#include <system/SystemPacketBuffer.h>

#include <functional>
#include <pybind11/pybind11.h>
#include <string>

#ifndef BINDER_PYBIND11_TYPE_CASTER
#define BINDER_PYBIND11_TYPE_CASTER
PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>)
PYBIND11_DECLARE_HOLDER_TYPE(T, T *)
PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

void bind_PyChip_17(std::function<pybind11::module &(std::string const & namespace_)> & M)
{
    { // chip::System::pbuf file:system/SystemPacketBuffer.h line:92
        pybind11::class_<chip::System::pbuf, std::shared_ptr<chip::System::pbuf>> cl(M("chip::System"), "pbuf", "");
        cl.def(pybind11::init([]() { return new chip::System::pbuf(); }));
        cl.def_readwrite("tot_len", &chip::System::pbuf::tot_len);
        cl.def_readwrite("len", &chip::System::pbuf::len);
        cl.def_readwrite("ref", &chip::System::pbuf::ref);
        cl.def_readwrite("alloc_size", &chip::System::pbuf::alloc_size);
    }
    { // chip::System::PacketBuffer file:system/SystemPacketBuffer.h line:134
        pybind11::class_<chip::System::PacketBuffer, std::shared_ptr<chip::System::PacketBuffer>> cl(
            M("chip::System"), "PacketBuffer",
            "The packet buffer class is the core structure used for manipulating packets of octet-serialized data, usually in "
            "the\n      context of a data communications network, like Bluetooth or the Internet protocol.\n\n      In LwIP-based "
            "environments, this class is built on top of the pbuf structure defined in that library. In the absence of\n      "
            "LwIP, chip provides either a malloc-based implementation, or a pool-based implementation that closely approximates "
            "the\n      memory challenges of deeply embedded devices.\n\n      The PacketBuffer class, like many similar "
            "structures used in layered network stacks, provide a mechanism to reserve space\n      for protocol headers at each "
            "layer of a configurable communication stack.  For details, see `PacketBufferHandle::New()`\n      as well as LwIP "
            "documentation.\n\n      PacketBuffer objects are reference-counted, and normally held and used through a "
            "PacketBufferHandle that owns one of the\n      counted references. When a PacketBufferHandle goes out of scope, its "
            "reference is released. To take ownership, a function\n      takes a PacketBufferHandle by value. To borrow ownership, "
            "a function takes a `const PacketBufferHandle &`.\n\n      New objects of PacketBuffer class are initialized at the "
            "beginning of an allocation of memory obtained from the underlying\n      environment, e.g. from LwIP pbuf target "
            "pools, from the standard C library heap, from an internal buffer pool. In the\n      simple pool case, the size of "
            "the data buffer is PacketBuffer::kBlockSize.\n\n      PacketBuffer objects may be chained to accomodate larger "
            "payloads.  Chaining, however, is not transparent, and users of the\n      class must explicitly decide to support "
            "chaining.  Examples of classes written with chaining support are as follows:\n\n          \n\n          \n\n ");
        cl.def(pybind11::init([]() { return new chip::System::PacketBuffer(); }));
        cl.def(
            "AllocSize", (unsigned short (chip::System::PacketBuffer::*)() const) & chip::System::PacketBuffer::AllocSize,
            "Return the size of the allocation including the reserved and payload data spaces but not including space\n allocated "
            "for the PacketBuffer structure.\n\n  \n    The allocation size is equal to or greater than the  parameter to the  "
            "method).\n\n  \n     size of the allocation\n\nC++: chip::System::PacketBuffer::AllocSize() const --> unsigned short");
        cl.def("Start", (unsigned char * (chip::System::PacketBuffer::*) () const) & chip::System::PacketBuffer::Start,
               "Get a pointer to the start of data in a buffer.\n\n  \n pointer to the start of data.\n\nC++: "
               "chip::System::PacketBuffer::Start() const --> unsigned char *",
               pybind11::return_value_policy::automatic);
        cl.def("SetStart", (void (chip::System::PacketBuffer::*)(unsigned char *)) & chip::System::PacketBuffer::SetStart,
               "Set the the start of data in a buffer, adjusting length and total length accordingly.\n\n  \n The data within the "
               "buffer is not moved, only accounting information is changed.  The function is commonly used to\n      either strip "
               "or prepend protocol headers in a zero-copy way.\n\n  \n This call should not be used on any buffer that is not the "
               "head of a buffer chain, as it only alters the current\n      buffer.\n\n  \n - A pointer to where the new payload "
               "should start.  newStart will be adjusted internally to fall within\n      the boundaries of the first buffer in "
               "the PacketBuffer chain.\n\nC++: chip::System::PacketBuffer::SetStart(unsigned char *) --> void",
               pybind11::arg("aNewStart"));
        cl.def("DataLength", (unsigned short (chip::System::PacketBuffer::*)() const) & chip::System::PacketBuffer::DataLength,
               "Get the length, in bytes, of data in a packet buffer.\n\n  \n length, in bytes (current payload length).\n\nC++: "
               "chip::System::PacketBuffer::DataLength() const --> unsigned short");
        cl.def(
            "SetDataLength",
            (void (chip::System::PacketBuffer::*)(unsigned short, const class chip::System::PacketBufferHandle &)) &
                chip::System::PacketBuffer::SetDataLength,
            "Set the length, in bytes, of data in a packet buffer, adjusting total length accordingly.\n\n  The function sets the "
            "length, in bytes, of the data in the buffer, adjusting the total length appropriately. When the buffer\n  is not the "
            "head of the buffer chain (common case: the caller adds data to the last buffer in the PacketBuffer chain prior to\n  "
            "calling higher layers), the aChainHead __must__ be passed in to properly adjust the total lengths of each buffer "
            "ahead of\n  the current buffer.\n\n  \n - new length, in bytes, of this buffer.\n\n  \n - the head of the buffer "
            "chain the current buffer belongs to.  May be  if the current\n      buffer is the head of the buffer chain.\n\nC++: "
            "chip::System::PacketBuffer::SetDataLength(unsigned short, const class chip::System::PacketBufferHandle &) --> void",
            pybind11::arg("aNewLen"), pybind11::arg("aChainHead"));
        cl.def("SetDataLength", (void (chip::System::PacketBuffer::*)(unsigned short)) & chip::System::PacketBuffer::SetDataLength,
               "C++: chip::System::PacketBuffer::SetDataLength(unsigned short) --> void", pybind11::arg("aNewLen"));
        cl.def("TotalLength", (unsigned short (chip::System::PacketBuffer::*)() const) & chip::System::PacketBuffer::TotalLength,
               "Get the total length of packet data in the buffer chain.\n\n  \n total length, in octets.\n\nC++: "
               "chip::System::PacketBuffer::TotalLength() const --> unsigned short");
        cl.def("MaxDataLength",
               (unsigned short (chip::System::PacketBuffer::*)() const) & chip::System::PacketBuffer::MaxDataLength,
               "Get the maximum amount, in bytes, of data that will fit in the buffer given the current start position and buffer "
               "size.\n\n  \n number of bytes that fits in the buffer given the current start position.\n\nC++: "
               "chip::System::PacketBuffer::MaxDataLength() const --> unsigned short");
        cl.def("AvailableDataLength",
               (unsigned short (chip::System::PacketBuffer::*)() const) & chip::System::PacketBuffer::AvailableDataLength,
               "Get the number of bytes of data that can be added to the current buffer given the current start position and data "
               "length.\n\n  \n the length, in bytes, of data that will fit in the current buffer given the current start position "
               "and data length.\n\nC++: chip::System::PacketBuffer::AvailableDataLength() const --> unsigned short");
        cl.def("ReservedSize", (unsigned short (chip::System::PacketBuffer::*)() const) & chip::System::PacketBuffer::ReservedSize,
               "Get the number of bytes within the current buffer between the start of the buffer and the current data start "
               "position.\n\n  \n the amount, in bytes, of space between the start of the buffer and the current data start "
               "position.\n\nC++: chip::System::PacketBuffer::ReservedSize() const --> unsigned short");
        cl.def("HasChainedBuffer", (bool (chip::System::PacketBuffer::*)() const) & chip::System::PacketBuffer::HasChainedBuffer,
               "Determine whether there are any additional buffers chained to the current buffer.\n\n  \n  if there is a chained "
               "buffer.\n\nC++: chip::System::PacketBuffer::HasChainedBuffer() const --> bool");
        cl.def("CompactHead", (void (chip::System::PacketBuffer::*)()) & chip::System::PacketBuffer::CompactHead,
               "Move data from subsequent buffers in the chain into the current buffer until it is full.\n\n  Only the current "
               "buffer is compacted: the data within the current buffer is moved to the front of the buffer, eliminating\n  any "
               "reserved space. The remaining available space is filled with data moved from subsequent buffers in the chain, "
               "until the\n  current buffer is full. If a subsequent buffer in the chain is moved into the current buffer in its "
               "entirety, it is removed\n  from the chain and freed. The method takes no parameters, returns no results and cannot "
               "fail.\n\nC++: chip::System::PacketBuffer::CompactHead() --> void");
        cl.def("ConsumeHead", (void (chip::System::PacketBuffer::*)(unsigned short)) & chip::System::PacketBuffer::ConsumeHead,
               "Adjust the current buffer to indicate the amount of data consumed.\n\n  Advance the data start position in the "
               "current buffer by the specified amount, in bytes, up to the length of data in the\n  buffer. Decrease the length "
               "and total length by the amount consumed.\n\n  \n - number of bytes to consume from the current buffer.\n\nC++: "
               "chip::System::PacketBuffer::ConsumeHead(unsigned short) --> void",
               pybind11::arg("aConsumeLength"));
        cl.def("EnsureReservedSize",
               (bool (chip::System::PacketBuffer::*)(unsigned short)) & chip::System::PacketBuffer::EnsureReservedSize,
               "Ensure the buffer has at least the specified amount of reserved space.\n\n  Ensure the buffer has at least the "
               "specified amount of reserved space, moving the data in the buffer forward to make room if\n  necessary.\n\n  \n - "
               "number of bytes desired for the headers.\n\n  \n  if the requested reserved size is available,  if there's not "
               "enough room in the buffer.\n\nC++: chip::System::PacketBuffer::EnsureReservedSize(unsigned short) --> bool",
               pybind11::arg("aReservedSize"));
        cl.def("AlignPayload", (bool (chip::System::PacketBuffer::*)(unsigned short)) & chip::System::PacketBuffer::AlignPayload,
               "Align the buffer payload on the specified bytes boundary.\n\n  Moving the payload in the buffer forward if "
               "necessary.\n\n  \n - specifies number of bytes alignment for the payload start pointer.\n\n  \n  if alignment is "
               "successful,  if there's not enough room in the buffer.\n\nC++: chip::System::PacketBuffer::AlignPayload(unsigned "
               "short) --> bool",
               pybind11::arg("aAlignBytes"));
        cl.def("Next", (class chip::System::PacketBufferHandle(chip::System::PacketBuffer::*)()) & chip::System::PacketBuffer::Next,
               "Return the next buffer in a buffer chain.\n\n  If there is no next buffer, the handle will have  \n\n  \n a handle "
               "to the next buffer in the buffer chain.\n\nC++: chip::System::PacketBuffer::Next() --> class "
               "chip::System::PacketBufferHandle");
        cl.def("Last", (class chip::System::PacketBufferHandle(chip::System::PacketBuffer::*)()) & chip::System::PacketBuffer::Last,
               "Return the last buffer in a buffer chain.\n\n  \n a handle to the last buffer in the buffer chain.\n\nC++: "
               "chip::System::PacketBuffer::Last() --> class chip::System::PacketBufferHandle");
        cl.def("Read",
               (int (chip::System::PacketBuffer::*)(unsigned char *, unsigned long) const) & chip::System::PacketBuffer::Read,
               "Copies data from the payloads of a chain of packet buffers until a given amount of data has been copied.\n\n \n    "
               "         Destination buffer; must be at least  bytes.\n \n\n          Destination buffer length.\n\n  "
               "#CHIP_ERROR_BUFFER_TOO_SMALL If the total length of the payloads in the chain is less than the requested \n  "
               "#CHIP_ERROR_INTERNAL         In case of an inconsistency in the buffer chain.\n  #CHIP_NO_ERROR               If "
               "the requested payload has been copied.\n\nC++: chip::System::PacketBuffer::Read(unsigned char *, unsigned long) "
               "const --> int",
               pybind11::arg("buf"), pybind11::arg("length"));
        cl.def_static(
            "Check", (void (*)(const class chip::System::PacketBuffer *)) & chip::System::PacketBuffer::Check,
            "Perform an implementation-defined check on the validity of a PacketBuffer pointer.\n\n Unless enabled by "
            "#CHIP_CONFIG_MEMORY_DEBUG_CHECKS == 1, this function does nothing.\n\n When enabled, it performs an implementation- "
            "and configuration-defined check on\n the validity of the packet buffer. It MAY log an error and/or abort the "
            "program\n if the packet buffer or the implementation-defined memory management system is in\n a faulty state. (Some "
            "configurations may not actually perform any check.)\n\n \n  A null pointer is not considered faulty.\n\n  \n - the "
            "packet buffer to check.\n\nC++: chip::System::PacketBuffer::Check(const class chip::System::PacketBuffer *) --> void",
            pybind11::arg("buffer"));
    }
    { // chip::System::PacketBufferHandle file:system/SystemPacketBuffer.h line:425
        pybind11::class_<chip::System::PacketBufferHandle, std::shared_ptr<chip::System::PacketBufferHandle>> cl(
            M("chip::System"), "PacketBufferHandle",
            "Tracks ownership of a PacketBuffer.\n\n  PacketBuffer objects are reference-counted, and normally held and used "
            "through a PacketBufferHandle that owns one of the\n  counted references. When a PacketBufferHandle goes out of scope, "
            "its reference is released. To take ownership, a function\n  takes a PacketBufferHandle by value. To borrow ownership, "
            "a function takes a `const PacketBufferHandle &`.");
        cl.def(pybind11::init([]() { return new chip::System::PacketBufferHandle(); }));
        cl.def(pybind11::init<std::nullptr_t>(), pybind11::arg(""));

        cl.def("assign",
               (class chip::System::PacketBufferHandle & (chip::System::PacketBufferHandle::*) (std::nullptr_t)) &
                   chip::System::PacketBufferHandle::operator=,
               "Free any buffer owned by this handle.\n\nC++: chip::System::PacketBufferHandle::operator=(std::std::nullptr_t) --> "
               "class chip::System::PacketBufferHandle &",
               pybind11::return_value_policy::automatic, pybind11::arg(""));
        cl.def("Retain",
               (class chip::System::PacketBufferHandle(chip::System::PacketBufferHandle::*)() const) &
                   chip::System::PacketBufferHandle::Retain,
               "Get a new handle to an existing buffer.\n\n \n a PacketBufferHandle that shares ownership with this.\n\nC++: "
               "chip::System::PacketBufferHandle::Retain() const --> class chip::System::PacketBufferHandle");
        cl.def(
            "IsNull", (bool (chip::System::PacketBufferHandle::*)() const) & chip::System::PacketBufferHandle::IsNull,
            "Test whether this PacketBufferHandle is empty, or conversely owns a PacketBuffer.\n\n \n  if this PacketBufferHandle "
            "is empty; return  if it owns a PacketBuffer.\n\nC++: chip::System::PacketBufferHandle::IsNull() const --> bool");
        cl.def("HasSoleOwnership",
               (bool (chip::System::PacketBufferHandle::*)() const) & chip::System::PacketBufferHandle::HasSoleOwnership,
               "Test whether the PacketBuffer owned by this PacketBufferHandle has unique ownership.\n\n \n  if the PacketBuffer "
               "owned by this PacketBufferHandle is solely owned; return  if\n it has more than one ownership.\n\nC++: "
               "chip::System::PacketBufferHandle::HasSoleOwnership() const --> bool");
        cl.def("PopHead",
               (class chip::System::PacketBufferHandle(chip::System::PacketBufferHandle::*)()) &
                   chip::System::PacketBufferHandle::PopHead,
               "Detach and return the head of a buffer chain while updating this handle to point to the remaining buffers.\n  The "
               "current buffer must be the head of the chain.\n\n  This PacketBufferHandle now holds the ownership formerly held "
               "by the head of the chain.\n  The returned PacketBufferHandle holds the ownership formerly held by this.\n\n  \n "
               "the detached buffer formerly at the head of the buffer chain.\n\nC++: chip::System::PacketBufferHandle::PopHead() "
               "--> class chip::System::PacketBufferHandle");
        cl.def("FreeHead", (void (chip::System::PacketBufferHandle::*)()) & chip::System::PacketBufferHandle::FreeHead,
               "Free the first buffer in a chain.\n\n  \n When the buffer chain is referenced by multiple handles, `FreeHead()` "
               "will detach the head, but will not forcibly\n  deallocate the head buffer.\n\nC++: "
               "chip::System::PacketBufferHandle::FreeHead() --> void");
        cl.def("Consume", (void (chip::System::PacketBufferHandle::*)(unsigned short)) & chip::System::PacketBufferHandle::Consume,
               "Consume data in a chain of buffers.\n\n  Consume data in a chain of buffers starting with the current buffer and "
               "proceeding through the remaining buffers in the\n  chain. Each buffer that is completely consumed is freed and the "
               "handle holds the first buffer (if any) containing the\n  remaining data. The current buffer must be the head of "
               "the buffer chain.\n\n  \n - number of bytes to consume from the current chain.\n\nC++: "
               "chip::System::PacketBufferHandle::Consume(unsigned short) --> void",
               pybind11::arg("aConsumeLength"));
        cl.def("RightSize", (void (chip::System::PacketBufferHandle::*)()) & chip::System::PacketBufferHandle::RightSize,
               "Copy the given buffer to a right-sized buffer if applicable.\n\n Only operates on single buffers (for chains, use  "
               "and RightSize the tail).\n Requires that this handle be the only reference to the underlying buffer.\n\nC++: "
               "chip::System::PacketBufferHandle::RightSize() --> void");
        cl.def_static("Adopt",
                      (class chip::System::PacketBufferHandle(*)(class chip::System::PacketBuffer *)) &
                          chip::System::PacketBufferHandle::Adopt,
                      "Get a new handle to a raw PacketBuffer pointer.\n\n \n The caller's ownership is transferred to this.\n\n "
                      "\n This should only be used in low-level code, e.g. to import buffers from LwIP or a similar stack.\n\nC++: "
                      "chip::System::PacketBufferHandle::Adopt(class chip::System::PacketBuffer *) --> class "
                      "chip::System::PacketBufferHandle",
                      pybind11::arg("buffer"));
        cl.def("Advance", (void (chip::System::PacketBufferHandle::*)()) & chip::System::PacketBufferHandle::Advance,
               "Advance this PacketBufferHandle to the next buffer in a chain.\n\n  \n This differs from `FreeHead()` in that it "
               "does not touch any content in the currently referenced packet buffer;\n      it only changes which buffer this "
               "handle owns. (Note that this could result in the previous buffer being freed,\n      if there is no other owner.) "
               "`Advance()` is designed to be used with an additional handle to traverse a buffer chain,\n      whereas "
               "`FreeHead()` modifies a chain.\n\nC++: chip::System::PacketBufferHandle::Advance() --> void");
        cl.def("UnsafeRelease",
               (class chip::System::PacketBuffer * (chip::System::PacketBufferHandle::*) ()) &
                   chip::System::PacketBufferHandle::UnsafeRelease,
               "Export a raw PacketBuffer pointer.\n\n \n The PacketBufferHandle's ownership is transferred to the caller.\n\n \n "
               "This should only be used in low-level code. The caller owns one counted reference to the \n       and is "
               "reponsible for managing it safely.\n\n \n The ref-qualifier `&&` requires the caller to use `std::move` to "
               "emphasize that ownership is\n       moved out of this handle.\n\nC++: "
               "chip::System::PacketBufferHandle::UnsafeRelease() --> class chip::System::PacketBuffer *",
               pybind11::return_value_policy::automatic);
        cl.def_static(
            "New",
            [](unsigned long const & a0) -> chip::System::PacketBufferHandle { return chip::System::PacketBufferHandle::New(a0); },
            "", pybind11::arg("aAvailableSize"));
        cl.def_static(
            "New",
            (class chip::System::PacketBufferHandle(*)(unsigned long, unsigned short)) & chip::System::PacketBufferHandle::New,
            "Allocates a packet buffer.\n\n  A packet buffer is conceptually divided into two parts:\n  \n\n  Space reserved for "
            "network protocol headers. The size of this space normally defaults to a value determined\n       by the network layer "
            "configuration, but can be given explicity by  for special cases.\n  \n\n  Space for application data. The minimum "
            "size of this space is given by  and then \n       provides a pointer to the start of this space.\n\n  Fails and "
            "returns  if no memory is available, or if the size requested is too large.\n  When the sum of  and  is no greater "
            "than \n  that is guaranteed not to be too large.\n\n  On success, it is guaranteed that  is no less than \n\n  \n  "
            "Minimum number of octets to for application data (at `Start()`).\n  \n\n   Number of octets to reserve for protocol "
            "headers (before `Start()`).\n\n  \n     On success, a PacketBufferHandle to the allocated buffer. On fail, \n     "
            "\n\nC++: chip::System::PacketBufferHandle::New(unsigned long, unsigned short) --> class "
            "chip::System::PacketBufferHandle",
            pybind11::arg("aAvailableSize"), pybind11::arg("aReservedSize"));
        cl.def_static(
            "NewWithData",
            [](const void * a0, unsigned long const & a1) -> chip::System::PacketBufferHandle {
                return chip::System::PacketBufferHandle::NewWithData(a0, a1);
            },
            "", pybind11::arg("aData"), pybind11::arg("aDataSize"));
        cl.def_static(
            "NewWithData",
            [](const void * a0, unsigned long const & a1, unsigned short const & a2) -> chip::System::PacketBufferHandle {
                return chip::System::PacketBufferHandle::NewWithData(a0, a1, a2);
            },
            "", pybind11::arg("aData"), pybind11::arg("aDataSize"), pybind11::arg("aAdditionalSize"));
        cl.def_static(
            "NewWithData",
            (class chip::System::PacketBufferHandle(*)(const void *, unsigned long, unsigned short, unsigned short)) &
                chip::System::PacketBufferHandle::NewWithData,
            "Allocates a packet buffer with initial contents.\n\n  \n           Initial buffer contents.\n  \n\n       Size of "
            "initial buffer contents.\n  \n\n Size of additional application data space after the initial contents.\n  \n\n   "
            "Number of octets to reserve for protocol headers.\n\n  \n     On success, a PacketBufferHandle to the allocated "
            "buffer. On fail, \n     \n\nC++: chip::System::PacketBufferHandle::NewWithData(const void *, unsigned long, unsigned "
            "short, unsigned short) --> class chip::System::PacketBufferHandle",
            pybind11::arg("aData"), pybind11::arg("aDataSize"), pybind11::arg("aAdditionalSize"), pybind11::arg("aReservedSize"));
        cl.def("CloneData",
               (class chip::System::PacketBufferHandle(chip::System::PacketBufferHandle::*)() const) &
                   chip::System::PacketBufferHandle::CloneData,
               "Creates a copy of a packet buffer (or chain).\n\n \n empty handle on allocation failure. Otherwise, the returned "
               "buffer has the same sizes and contents as the original.\n\nC++: chip::System::PacketBufferHandle::CloneData() "
               "const --> class chip::System::PacketBufferHandle");
        cl.def("Check", (void (chip::System::PacketBufferHandle::*)() const) & chip::System::PacketBufferHandle::Check,
               "Perform an implementation-defined check on the validity of a PacketBufferHandle.\n\n Unless enabled by "
               "#CHIP_CONFIG_MEMORY_DEBUG_CHECKS == 1, this function does nothing.\n\n When enabled, it performs an "
               "implementation- and configuration-defined check on\n the validity of the packet buffer. It MAY log an error and/or "
               "abort the program\n if the packet buffer or the implementation-defined memory management system is in\n a faulty "
               "state. (Some configurations may not actually perform any check.)\n\n \n  A null handle is not considered "
               "faulty.\n\nC++: chip::System::PacketBufferHandle::Check() const --> void");
    }
}
