#include <sstream> // __str__
#include <sys/_select.h>
#include <sys/_types/_fd_def.h>
#include <sys/select.h>
#include <sys/unistd.h>
#include <unistd.h>

#include <pybind11/pybind11.h>
#include <functional>
#include <string>

#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>)
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*)
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

void bind_PyChip_2(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // fd_set file:sys/_types/_fd_def.h line:50
		pybind11::class_<fd_set, std::shared_ptr<fd_set>> cl(M(""), "fd_set", "");
		cl.def( pybind11::init( [](){ return new fd_set(); } ) );
		cl.def( pybind11::init( [](fd_set const &o){ return new fd_set(o); } ) );
		cl.def("assign", (struct fd_set & (fd_set::*)(const struct fd_set &)) &fd_set::operator=, "C++: fd_set::operator=(const struct fd_set &) --> struct fd_set &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
	{ // timeval file: line:29
		pybind11::class_<timeval, std::shared_ptr<timeval>> cl(M(""), "timeval", "");
		cl.def( pybind11::init( [](){ return new timeval(); } ) );
		cl.def( pybind11::init( [](timeval const &o){ return new timeval(o); } ) );
		cl.def_readwrite("tv_sec", &timeval::tv_sec);
		cl.def_readwrite("tv_usec", &timeval::tv_usec);
		cl.def("assign", (struct timeval & (timeval::*)(const struct timeval &)) &timeval::operator=, "C++: timeval::operator=(const struct timeval &) --> struct timeval &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
}
