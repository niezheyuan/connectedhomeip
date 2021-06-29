#include <sstream> // __str__
#include <support/BufferWriter.h>

#include <functional>
#include <pybind11/pybind11.h>
#include <string>

#ifndef BINDER_PYBIND11_TYPE_CASTER
#define BINDER_PYBIND11_TYPE_CASTER
PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>)
PYBIND11_DECLARE_HOLDER_TYPE(T, T *)
PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

void bind_PyChip_12(std::function<pybind11::module &(std::string const & namespace_)> & M)
{
    { // chip::Encoding::BigEndian::BufferWriter file:support/BufferWriter.h line:120
        pybind11::class_<chip::Encoding::BigEndian::BufferWriter, std::shared_ptr<chip::Encoding::BigEndian::BufferWriter>,
                         chip::Encoding::EndianBufferWriterBase<chip::Encoding::BigEndian::BufferWriter>>
            cl(M("chip::Encoding::BigEndian"), "BufferWriter", "");
        cl.def(pybind11::init<unsigned char *, unsigned long>(), pybind11::arg("buf"), pybind11::arg("len"));

        cl.def(pybind11::init(
            [](chip::Encoding::BigEndian::BufferWriter const & o) { return new chip::Encoding::BigEndian::BufferWriter(o); }));
        cl.def("assign",
               (class chip::Encoding::BigEndian::BufferWriter &
                (chip::Encoding::BigEndian::BufferWriter::*) (const class chip::Encoding::BigEndian::BufferWriter &) ) &
                   chip::Encoding::BigEndian::BufferWriter::operator=,
               "C++: chip::Encoding::BigEndian::BufferWriter::operator=(const class chip::Encoding::BigEndian::BufferWriter &) --> "
               "class chip::Encoding::BigEndian::BufferWriter &",
               pybind11::return_value_policy::automatic, pybind11::arg("other"));
        cl.def("EndianPut",
               (class chip::Encoding::BigEndian::BufferWriter &
                (chip::Encoding::BigEndian::BufferWriter::*) (unsigned long long, unsigned long) ) &
                   chip::Encoding::BigEndian::BufferWriter::EndianPut,
               "C++: chip::Encoding::BigEndian::BufferWriter::EndianPut(unsigned long long, unsigned long) --> class "
               "chip::Encoding::BigEndian::BufferWriter &",
               pybind11::return_value_policy::automatic, pybind11::arg("x"), pybind11::arg("size"));
    }
}
