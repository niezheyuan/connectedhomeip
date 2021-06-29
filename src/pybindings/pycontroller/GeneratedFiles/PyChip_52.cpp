#include <sstream> // __str__
#include <support/Span.h>

#include <pybind11/pybind11.h>
#include <functional>
#include <string>

#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>)
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*)
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

void bind_PyChip_52(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // chip::Span file:support/Span.h line:34
		pybind11::class_<chip::Span<const unsigned char>, std::shared_ptr<chip::Span<const unsigned char>>> cl(M("chip"), "Span_const_unsigned_char_t", "");
		cl.def( pybind11::init( [](){ return new chip::Span<const unsigned char>(); } ) );
		cl.def( pybind11::init<const unsigned char *, unsigned long>(), pybind11::arg("databuf"), pybind11::arg("datalen") );

		cl.def( pybind11::init( [](chip::Span<const unsigned char> const &o){ return new chip::Span<const unsigned char>(o); } ) );
		cl.def("data", (const unsigned char * (chip::Span<const unsigned char>::*)() const) &chip::Span<const unsigned char>::data, "C++: chip::Span<const unsigned char>::data() const --> const unsigned char *", pybind11::return_value_policy::automatic);
		cl.def("size", (unsigned long (chip::Span<const unsigned char>::*)() const) &chip::Span<const unsigned char>::size, "C++: chip::Span<const unsigned char>::size() const --> unsigned long");
		cl.def("empty", (bool (chip::Span<const unsigned char>::*)() const) &chip::Span<const unsigned char>::empty, "C++: chip::Span<const unsigned char>::empty() const --> bool");
		cl.def("SubSpan", (class chip::Span<const unsigned char> (chip::Span<const unsigned char>::*)(unsigned long, unsigned long) const) &chip::Span<const unsigned char>::SubSpan, "C++: chip::Span<const unsigned char>::SubSpan(unsigned long, unsigned long) const --> class chip::Span<const unsigned char>", pybind11::arg("offset"), pybind11::arg("length"));
		cl.def("reduce_size", (void (chip::Span<const unsigned char>::*)(unsigned long)) &chip::Span<const unsigned char>::reduce_size, "C++: chip::Span<const unsigned char>::reduce_size(unsigned long) --> void", pybind11::arg("new_size"));
	}
}
