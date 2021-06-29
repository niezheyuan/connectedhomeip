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

void bind_PyChip_10(std::function<pybind11::module &(std::string const & namespace_)> & M)
{
    { // chip::Encoding::BufferWriter file:support/BufferWriter.h line:27
        pybind11::class_<chip::Encoding::BufferWriter, std::shared_ptr<chip::Encoding::BufferWriter>> cl(M("chip::Encoding"),
                                                                                                         "BufferWriter", "");
        cl.def(pybind11::init<unsigned char *, unsigned long>(), pybind11::arg("buf"), pybind11::arg("len"));

        cl.def(pybind11::init([](chip::Encoding::BufferWriter const & o) { return new chip::Encoding::BufferWriter(o); }));
        cl.def(
            "assign",
            (class chip::Encoding::BufferWriter & (chip::Encoding::BufferWriter::*) (const class chip::Encoding::BufferWriter &) ) &
                chip::Encoding::BufferWriter::operator=,
            "C++: chip::Encoding::BufferWriter::operator=(const class chip::Encoding::BufferWriter &) --> class "
            "chip::Encoding::BufferWriter &",
            pybind11::return_value_policy::automatic, pybind11::arg("other"));
        cl.def("Put",
               (class chip::Encoding::BufferWriter & (chip::Encoding::BufferWriter::*) (const char *) ) &
                   chip::Encoding::BufferWriter::Put,
               "Append a null terminated string, exclude the null terminator\n\nC++: chip::Encoding::BufferWriter::Put(const char "
               "*) --> class chip::Encoding::BufferWriter &",
               pybind11::return_value_policy::automatic, pybind11::arg("s"));
        cl.def("Put",
               (class chip::Encoding::BufferWriter & (chip::Encoding::BufferWriter::*) (const void *, unsigned long) ) &
                   chip::Encoding::BufferWriter::Put,
               "Raw append a buffer, regardless of endianess\n\nC++: chip::Encoding::BufferWriter::Put(const void *, unsigned "
               "long) --> class chip::Encoding::BufferWriter &",
               pybind11::return_value_policy::automatic, pybind11::arg("buf"), pybind11::arg("len"));
        cl.def("Put",
               (class chip::Encoding::BufferWriter & (chip::Encoding::BufferWriter::*) (unsigned char) ) &
                   chip::Encoding::BufferWriter::Put,
               "Append a single byte\n\nC++: chip::Encoding::BufferWriter::Put(unsigned char) --> class "
               "chip::Encoding::BufferWriter &",
               pybind11::return_value_policy::automatic, pybind11::arg("c"));
        cl.def("Skip",
               (class chip::Encoding::BufferWriter & (chip::Encoding::BufferWriter::*) (unsigned long) ) &
                   chip::Encoding::BufferWriter::Skip,
               "C++: chip::Encoding::BufferWriter::Skip(unsigned long) --> class chip::Encoding::BufferWriter &",
               pybind11::return_value_policy::automatic, pybind11::arg("len"));
        cl.def("Needed", (unsigned long (chip::Encoding::BufferWriter::*)() const) & chip::Encoding::BufferWriter::Needed,
               "Number of bytes required to satisfy all calls to Put() so far\n\nC++: chip::Encoding::BufferWriter::Needed() const "
               "--> unsigned long");
        cl.def("Available", (unsigned long (chip::Encoding::BufferWriter::*)() const) & chip::Encoding::BufferWriter::Available,
               "Number of bytes still available for writing\n\nC++: chip::Encoding::BufferWriter::Available() const --> unsigned "
               "long");
        cl.def("Fit", (bool (chip::Encoding::BufferWriter::*)() const) & chip::Encoding::BufferWriter::Fit,
               "Whether the input fit in the buffer\n\nC++: chip::Encoding::BufferWriter::Fit() const --> bool");
        cl.def("Fit", (bool (chip::Encoding::BufferWriter::*)(unsigned long &) const) & chip::Encoding::BufferWriter::Fit,
               "Returns whether the input fit in the buffer, outputs what was actually written\n\nC++: "
               "chip::Encoding::BufferWriter::Fit(unsigned long &) const --> bool",
               pybind11::arg("actuallyWritten"));
        cl.def("Size", (unsigned long (chip::Encoding::BufferWriter::*)() const) & chip::Encoding::BufferWriter::Size,
               "Size of the output buffer\n\nC++: chip::Encoding::BufferWriter::Size() const --> unsigned long");
        cl.def("Buffer", (unsigned char * (chip::Encoding::BufferWriter::*) ()) & chip::Encoding::BufferWriter::Buffer,
               "C++: chip::Encoding::BufferWriter::Buffer() --> unsigned char *", pybind11::return_value_policy::automatic);
    }
    { // chip::Encoding::EndianBufferWriterBase file:support/BufferWriter.h line:82
        pybind11::class_<chip::Encoding::EndianBufferWriterBase<chip::Encoding::LittleEndian::BufferWriter>,
                         std::shared_ptr<chip::Encoding::EndianBufferWriterBase<chip::Encoding::LittleEndian::BufferWriter>>,
                         chip::Encoding::BufferWriter>
            cl(M("chip::Encoding"), "EndianBufferWriterBase_chip_Encoding_LittleEndian_BufferWriter_t", "");
        cl.def("Put",
               (class chip::Encoding::LittleEndian::BufferWriter &
                (chip::Encoding::EndianBufferWriterBase<chip::Encoding::LittleEndian::BufferWriter>::*) (const char *) ) &
                   chip::Encoding::EndianBufferWriterBase<chip::Encoding::LittleEndian::BufferWriter>::Put,
               "C++: chip::Encoding::EndianBufferWriterBase<chip::Encoding::LittleEndian::BufferWriter>::Put(const char *) --> "
               "class chip::Encoding::LittleEndian::BufferWriter &",
               pybind11::return_value_policy::automatic, pybind11::arg("s"));
        cl.def("Put",
               (class chip::Encoding::LittleEndian::BufferWriter &
                (chip::Encoding::EndianBufferWriterBase<chip::Encoding::LittleEndian::BufferWriter>::*) (const void *,
                                                                                                         unsigned long) ) &
                   chip::Encoding::EndianBufferWriterBase<chip::Encoding::LittleEndian::BufferWriter>::Put,
               "C++: chip::Encoding::EndianBufferWriterBase<chip::Encoding::LittleEndian::BufferWriter>::Put(const void *, "
               "unsigned long) --> class chip::Encoding::LittleEndian::BufferWriter &",
               pybind11::return_value_policy::automatic, pybind11::arg("buf"), pybind11::arg("len"));
        cl.def("Put",
               (class chip::Encoding::LittleEndian::BufferWriter &
                (chip::Encoding::EndianBufferWriterBase<chip::Encoding::LittleEndian::BufferWriter>::*) (unsigned char) ) &
                   chip::Encoding::EndianBufferWriterBase<chip::Encoding::LittleEndian::BufferWriter>::Put,
               "C++: chip::Encoding::EndianBufferWriterBase<chip::Encoding::LittleEndian::BufferWriter>::Put(unsigned char) --> "
               "class chip::Encoding::LittleEndian::BufferWriter &",
               pybind11::return_value_policy::automatic, pybind11::arg("c"));
        cl.def("Skip",
               (class chip::Encoding::LittleEndian::BufferWriter &
                (chip::Encoding::EndianBufferWriterBase<chip::Encoding::LittleEndian::BufferWriter>::*) (unsigned long) ) &
                   chip::Encoding::EndianBufferWriterBase<chip::Encoding::LittleEndian::BufferWriter>::Skip,
               "C++: chip::Encoding::EndianBufferWriterBase<chip::Encoding::LittleEndian::BufferWriter>::Skip(unsigned long) --> "
               "class chip::Encoding::LittleEndian::BufferWriter &",
               pybind11::return_value_policy::automatic, pybind11::arg("len"));
        cl.def("Put8",
               (class chip::Encoding::LittleEndian::BufferWriter &
                (chip::Encoding::EndianBufferWriterBase<chip::Encoding::LittleEndian::BufferWriter>::*) (unsigned char) ) &
                   chip::Encoding::EndianBufferWriterBase<chip::Encoding::LittleEndian::BufferWriter>::Put8,
               "C++: chip::Encoding::EndianBufferWriterBase<chip::Encoding::LittleEndian::BufferWriter>::Put8(unsigned char) --> "
               "class chip::Encoding::LittleEndian::BufferWriter &",
               pybind11::return_value_policy::automatic, pybind11::arg("c"));
        cl.def("Put16",
               (class chip::Encoding::LittleEndian::BufferWriter &
                (chip::Encoding::EndianBufferWriterBase<chip::Encoding::LittleEndian::BufferWriter>::*) (unsigned short) ) &
                   chip::Encoding::EndianBufferWriterBase<chip::Encoding::LittleEndian::BufferWriter>::Put16,
               "C++: chip::Encoding::EndianBufferWriterBase<chip::Encoding::LittleEndian::BufferWriter>::Put16(unsigned short) --> "
               "class chip::Encoding::LittleEndian::BufferWriter &",
               pybind11::return_value_policy::automatic, pybind11::arg("x"));
        cl.def("Put32",
               (class chip::Encoding::LittleEndian::BufferWriter &
                (chip::Encoding::EndianBufferWriterBase<chip::Encoding::LittleEndian::BufferWriter>::*) (unsigned int) ) &
                   chip::Encoding::EndianBufferWriterBase<chip::Encoding::LittleEndian::BufferWriter>::Put32,
               "C++: chip::Encoding::EndianBufferWriterBase<chip::Encoding::LittleEndian::BufferWriter>::Put32(unsigned int) --> "
               "class chip::Encoding::LittleEndian::BufferWriter &",
               pybind11::return_value_policy::automatic, pybind11::arg("x"));
        cl.def("Put64",
               (class chip::Encoding::LittleEndian::BufferWriter &
                (chip::Encoding::EndianBufferWriterBase<chip::Encoding::LittleEndian::BufferWriter>::*) (unsigned long long) ) &
                   chip::Encoding::EndianBufferWriterBase<chip::Encoding::LittleEndian::BufferWriter>::Put64,
               "C++: chip::Encoding::EndianBufferWriterBase<chip::Encoding::LittleEndian::BufferWriter>::Put64(unsigned long long) "
               "--> class chip::Encoding::LittleEndian::BufferWriter &",
               pybind11::return_value_policy::automatic, pybind11::arg("x"));
        cl.def(
            "assign",
            (class chip::Encoding::BufferWriter & (chip::Encoding::BufferWriter::*) (const class chip::Encoding::BufferWriter &) ) &
                chip::Encoding::BufferWriter::operator=,
            "C++: chip::Encoding::BufferWriter::operator=(const class chip::Encoding::BufferWriter &) --> class "
            "chip::Encoding::BufferWriter &",
            pybind11::return_value_policy::automatic, pybind11::arg("other"));
        cl.def("Put",
               (class chip::Encoding::BufferWriter & (chip::Encoding::BufferWriter::*) (const char *) ) &
                   chip::Encoding::BufferWriter::Put,
               "Append a null terminated string, exclude the null terminator\n\nC++: chip::Encoding::BufferWriter::Put(const char "
               "*) --> class chip::Encoding::BufferWriter &",
               pybind11::return_value_policy::automatic, pybind11::arg("s"));
        cl.def("Put",
               (class chip::Encoding::BufferWriter & (chip::Encoding::BufferWriter::*) (const void *, unsigned long) ) &
                   chip::Encoding::BufferWriter::Put,
               "Raw append a buffer, regardless of endianess\n\nC++: chip::Encoding::BufferWriter::Put(const void *, unsigned "
               "long) --> class chip::Encoding::BufferWriter &",
               pybind11::return_value_policy::automatic, pybind11::arg("buf"), pybind11::arg("len"));
        cl.def("Put",
               (class chip::Encoding::BufferWriter & (chip::Encoding::BufferWriter::*) (unsigned char) ) &
                   chip::Encoding::BufferWriter::Put,
               "Append a single byte\n\nC++: chip::Encoding::BufferWriter::Put(unsigned char) --> class "
               "chip::Encoding::BufferWriter &",
               pybind11::return_value_policy::automatic, pybind11::arg("c"));
        cl.def("Skip",
               (class chip::Encoding::BufferWriter & (chip::Encoding::BufferWriter::*) (unsigned long) ) &
                   chip::Encoding::BufferWriter::Skip,
               "C++: chip::Encoding::BufferWriter::Skip(unsigned long) --> class chip::Encoding::BufferWriter &",
               pybind11::return_value_policy::automatic, pybind11::arg("len"));
        cl.def("Needed", (unsigned long (chip::Encoding::BufferWriter::*)() const) & chip::Encoding::BufferWriter::Needed,
               "Number of bytes required to satisfy all calls to Put() so far\n\nC++: chip::Encoding::BufferWriter::Needed() const "
               "--> unsigned long");
        cl.def("Available", (unsigned long (chip::Encoding::BufferWriter::*)() const) & chip::Encoding::BufferWriter::Available,
               "Number of bytes still available for writing\n\nC++: chip::Encoding::BufferWriter::Available() const --> unsigned "
               "long");
        cl.def("Fit", (bool (chip::Encoding::BufferWriter::*)() const) & chip::Encoding::BufferWriter::Fit,
               "Whether the input fit in the buffer\n\nC++: chip::Encoding::BufferWriter::Fit() const --> bool");
        cl.def("Fit", (bool (chip::Encoding::BufferWriter::*)(unsigned long &) const) & chip::Encoding::BufferWriter::Fit,
               "Returns whether the input fit in the buffer, outputs what was actually written\n\nC++: "
               "chip::Encoding::BufferWriter::Fit(unsigned long &) const --> bool",
               pybind11::arg("actuallyWritten"));
        cl.def("Size", (unsigned long (chip::Encoding::BufferWriter::*)() const) & chip::Encoding::BufferWriter::Size,
               "Size of the output buffer\n\nC++: chip::Encoding::BufferWriter::Size() const --> unsigned long");
        cl.def("Buffer", (unsigned char * (chip::Encoding::BufferWriter::*) ()) & chip::Encoding::BufferWriter::Buffer,
               "C++: chip::Encoding::BufferWriter::Buffer() --> unsigned char *", pybind11::return_value_policy::automatic);
    }
    { // chip::Encoding::EndianBufferWriterBase file:support/BufferWriter.h line:82
        pybind11::class_<chip::Encoding::EndianBufferWriterBase<chip::Encoding::BigEndian::BufferWriter>,
                         std::shared_ptr<chip::Encoding::EndianBufferWriterBase<chip::Encoding::BigEndian::BufferWriter>>,
                         chip::Encoding::BufferWriter>
            cl(M("chip::Encoding"), "EndianBufferWriterBase_chip_Encoding_BigEndian_BufferWriter_t", "");
        cl.def("Put",
               (class chip::Encoding::BigEndian::BufferWriter &
                (chip::Encoding::EndianBufferWriterBase<chip::Encoding::BigEndian::BufferWriter>::*) (const char *) ) &
                   chip::Encoding::EndianBufferWriterBase<chip::Encoding::BigEndian::BufferWriter>::Put,
               "C++: chip::Encoding::EndianBufferWriterBase<chip::Encoding::BigEndian::BufferWriter>::Put(const char *) --> class "
               "chip::Encoding::BigEndian::BufferWriter &",
               pybind11::return_value_policy::automatic, pybind11::arg("s"));
        cl.def(
            "Put",
            (class chip::Encoding::BigEndian::BufferWriter &
             (chip::Encoding::EndianBufferWriterBase<chip::Encoding::BigEndian::BufferWriter>::*) (const void *, unsigned long) ) &
                chip::Encoding::EndianBufferWriterBase<chip::Encoding::BigEndian::BufferWriter>::Put,
            "C++: chip::Encoding::EndianBufferWriterBase<chip::Encoding::BigEndian::BufferWriter>::Put(const void *, unsigned "
            "long) --> class chip::Encoding::BigEndian::BufferWriter &",
            pybind11::return_value_policy::automatic, pybind11::arg("buf"), pybind11::arg("len"));
        cl.def("Put",
               (class chip::Encoding::BigEndian::BufferWriter &
                (chip::Encoding::EndianBufferWriterBase<chip::Encoding::BigEndian::BufferWriter>::*) (unsigned char) ) &
                   chip::Encoding::EndianBufferWriterBase<chip::Encoding::BigEndian::BufferWriter>::Put,
               "C++: chip::Encoding::EndianBufferWriterBase<chip::Encoding::BigEndian::BufferWriter>::Put(unsigned char) --> class "
               "chip::Encoding::BigEndian::BufferWriter &",
               pybind11::return_value_policy::automatic, pybind11::arg("c"));
        cl.def("Skip",
               (class chip::Encoding::BigEndian::BufferWriter &
                (chip::Encoding::EndianBufferWriterBase<chip::Encoding::BigEndian::BufferWriter>::*) (unsigned long) ) &
                   chip::Encoding::EndianBufferWriterBase<chip::Encoding::BigEndian::BufferWriter>::Skip,
               "C++: chip::Encoding::EndianBufferWriterBase<chip::Encoding::BigEndian::BufferWriter>::Skip(unsigned long) --> "
               "class chip::Encoding::BigEndian::BufferWriter &",
               pybind11::return_value_policy::automatic, pybind11::arg("len"));
        cl.def("Put8",
               (class chip::Encoding::BigEndian::BufferWriter &
                (chip::Encoding::EndianBufferWriterBase<chip::Encoding::BigEndian::BufferWriter>::*) (unsigned char) ) &
                   chip::Encoding::EndianBufferWriterBase<chip::Encoding::BigEndian::BufferWriter>::Put8,
               "C++: chip::Encoding::EndianBufferWriterBase<chip::Encoding::BigEndian::BufferWriter>::Put8(unsigned char) --> "
               "class chip::Encoding::BigEndian::BufferWriter &",
               pybind11::return_value_policy::automatic, pybind11::arg("c"));
        cl.def("Put16",
               (class chip::Encoding::BigEndian::BufferWriter &
                (chip::Encoding::EndianBufferWriterBase<chip::Encoding::BigEndian::BufferWriter>::*) (unsigned short) ) &
                   chip::Encoding::EndianBufferWriterBase<chip::Encoding::BigEndian::BufferWriter>::Put16,
               "C++: chip::Encoding::EndianBufferWriterBase<chip::Encoding::BigEndian::BufferWriter>::Put16(unsigned short) --> "
               "class chip::Encoding::BigEndian::BufferWriter &",
               pybind11::return_value_policy::automatic, pybind11::arg("x"));
        cl.def("Put32",
               (class chip::Encoding::BigEndian::BufferWriter &
                (chip::Encoding::EndianBufferWriterBase<chip::Encoding::BigEndian::BufferWriter>::*) (unsigned int) ) &
                   chip::Encoding::EndianBufferWriterBase<chip::Encoding::BigEndian::BufferWriter>::Put32,
               "C++: chip::Encoding::EndianBufferWriterBase<chip::Encoding::BigEndian::BufferWriter>::Put32(unsigned int) --> "
               "class chip::Encoding::BigEndian::BufferWriter &",
               pybind11::return_value_policy::automatic, pybind11::arg("x"));
        cl.def("Put64",
               (class chip::Encoding::BigEndian::BufferWriter &
                (chip::Encoding::EndianBufferWriterBase<chip::Encoding::BigEndian::BufferWriter>::*) (unsigned long long) ) &
                   chip::Encoding::EndianBufferWriterBase<chip::Encoding::BigEndian::BufferWriter>::Put64,
               "C++: chip::Encoding::EndianBufferWriterBase<chip::Encoding::BigEndian::BufferWriter>::Put64(unsigned long long) "
               "--> class chip::Encoding::BigEndian::BufferWriter &",
               pybind11::return_value_policy::automatic, pybind11::arg("x"));
        cl.def(
            "assign",
            (class chip::Encoding::BufferWriter & (chip::Encoding::BufferWriter::*) (const class chip::Encoding::BufferWriter &) ) &
                chip::Encoding::BufferWriter::operator=,
            "C++: chip::Encoding::BufferWriter::operator=(const class chip::Encoding::BufferWriter &) --> class "
            "chip::Encoding::BufferWriter &",
            pybind11::return_value_policy::automatic, pybind11::arg("other"));
        cl.def("Put",
               (class chip::Encoding::BufferWriter & (chip::Encoding::BufferWriter::*) (const char *) ) &
                   chip::Encoding::BufferWriter::Put,
               "Append a null terminated string, exclude the null terminator\n\nC++: chip::Encoding::BufferWriter::Put(const char "
               "*) --> class chip::Encoding::BufferWriter &",
               pybind11::return_value_policy::automatic, pybind11::arg("s"));
        cl.def("Put",
               (class chip::Encoding::BufferWriter & (chip::Encoding::BufferWriter::*) (const void *, unsigned long) ) &
                   chip::Encoding::BufferWriter::Put,
               "Raw append a buffer, regardless of endianess\n\nC++: chip::Encoding::BufferWriter::Put(const void *, unsigned "
               "long) --> class chip::Encoding::BufferWriter &",
               pybind11::return_value_policy::automatic, pybind11::arg("buf"), pybind11::arg("len"));
        cl.def("Put",
               (class chip::Encoding::BufferWriter & (chip::Encoding::BufferWriter::*) (unsigned char) ) &
                   chip::Encoding::BufferWriter::Put,
               "Append a single byte\n\nC++: chip::Encoding::BufferWriter::Put(unsigned char) --> class "
               "chip::Encoding::BufferWriter &",
               pybind11::return_value_policy::automatic, pybind11::arg("c"));
        cl.def("Skip",
               (class chip::Encoding::BufferWriter & (chip::Encoding::BufferWriter::*) (unsigned long) ) &
                   chip::Encoding::BufferWriter::Skip,
               "C++: chip::Encoding::BufferWriter::Skip(unsigned long) --> class chip::Encoding::BufferWriter &",
               pybind11::return_value_policy::automatic, pybind11::arg("len"));
        cl.def("Needed", (unsigned long (chip::Encoding::BufferWriter::*)() const) & chip::Encoding::BufferWriter::Needed,
               "Number of bytes required to satisfy all calls to Put() so far\n\nC++: chip::Encoding::BufferWriter::Needed() const "
               "--> unsigned long");
        cl.def("Available", (unsigned long (chip::Encoding::BufferWriter::*)() const) & chip::Encoding::BufferWriter::Available,
               "Number of bytes still available for writing\n\nC++: chip::Encoding::BufferWriter::Available() const --> unsigned "
               "long");
        cl.def("Fit", (bool (chip::Encoding::BufferWriter::*)() const) & chip::Encoding::BufferWriter::Fit,
               "Whether the input fit in the buffer\n\nC++: chip::Encoding::BufferWriter::Fit() const --> bool");
        cl.def("Fit", (bool (chip::Encoding::BufferWriter::*)(unsigned long &) const) & chip::Encoding::BufferWriter::Fit,
               "Returns whether the input fit in the buffer, outputs what was actually written\n\nC++: "
               "chip::Encoding::BufferWriter::Fit(unsigned long &) const --> bool",
               pybind11::arg("actuallyWritten"));
        cl.def("Size", (unsigned long (chip::Encoding::BufferWriter::*)() const) & chip::Encoding::BufferWriter::Size,
               "Size of the output buffer\n\nC++: chip::Encoding::BufferWriter::Size() const --> unsigned long");
        cl.def("Buffer", (unsigned char * (chip::Encoding::BufferWriter::*) ()) & chip::Encoding::BufferWriter::Buffer,
               "C++: chip::Encoding::BufferWriter::Buffer() --> unsigned char *", pybind11::return_value_policy::automatic);
    }
}
