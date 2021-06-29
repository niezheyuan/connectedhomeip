#include <support/CodeUtils.h>

#include <pybind11/pybind11.h>
#include <functional>
#include <string>

#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>)
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*)
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

void bind_PyChip_16(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	// chip::min(const unsigned long &, const unsigned long &) file:support/CodeUtils.h line:125
	M("chip").def("min", (const unsigned long & (*)(const unsigned long &, const unsigned long &)) &chip::min<unsigned long>, "C++: chip::min(const unsigned long &, const unsigned long &) --> const unsigned long &", pybind11::return_value_policy::automatic, pybind11::arg("a"), pybind11::arg("b"));

}
