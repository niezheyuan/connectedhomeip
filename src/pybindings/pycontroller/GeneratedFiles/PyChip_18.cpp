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

void bind_PyChip_18(std::function<pybind11::module &(std::string const & namespace_)> & M)
{
    { // chip::Encoding::PacketBufferWriterUtil file:system/SystemPacketBuffer.h line:739
        pybind11::class_<chip::Encoding::PacketBufferWriterUtil, std::shared_ptr<chip::Encoding::PacketBufferWriterUtil>> cl(
            M("chip::Encoding"), "PacketBufferWriterUtil", "");
        cl.def(pybind11::init([]() { return new chip::Encoding::PacketBufferWriterUtil(); }));
    }
}
