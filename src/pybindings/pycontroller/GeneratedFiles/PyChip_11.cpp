#include <sstream> // __str__
#include <support/BufferWriter.h>

#include <pybind11/pybind11.h>
#include <functional>
#include <string>

#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>)
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*)
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

void bind_PyChip_11(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // chip::Encoding::LittleEndian::BufferWriter file:support/BufferWriter.h line:107
		pybind11::class_<chip::Encoding::LittleEndian::BufferWriter, std::shared_ptr<chip::Encoding::LittleEndian::BufferWriter>, chip::Encoding::EndianBufferWriterBase<chip::Encoding::LittleEndian::BufferWriter>> cl(M("chip::Encoding::LittleEndian"), "BufferWriter", "");
		cl.def( pybind11::init<unsigned char *, unsigned long>(), pybind11::arg("buf"), pybind11::arg("len") );

		cl.def( pybind11::init( [](chip::Encoding::LittleEndian::BufferWriter const &o){ return new chip::Encoding::LittleEndian::BufferWriter(o); } ) );
		cl.def("assign", (class chip::Encoding::LittleEndian::BufferWriter & (chip::Encoding::LittleEndian::BufferWriter::*)(const class chip::Encoding::LittleEndian::BufferWriter &)) &chip::Encoding::LittleEndian::BufferWriter::operator=, "C++: chip::Encoding::LittleEndian::BufferWriter::operator=(const class chip::Encoding::LittleEndian::BufferWriter &) --> class chip::Encoding::LittleEndian::BufferWriter &", pybind11::return_value_policy::automatic, pybind11::arg("other"));
		cl.def("EndianPut", (class chip::Encoding::LittleEndian::BufferWriter & (chip::Encoding::LittleEndian::BufferWriter::*)(unsigned long long, unsigned long)) &chip::Encoding::LittleEndian::BufferWriter::EndianPut, "C++: chip::Encoding::LittleEndian::BufferWriter::EndianPut(unsigned long long, unsigned long) --> class chip::Encoding::LittleEndian::BufferWriter &", pybind11::return_value_policy::automatic, pybind11::arg("x"), pybind11::arg("size"));
	}
}
