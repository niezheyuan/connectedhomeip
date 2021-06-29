#include <net/if.h>
#include <netinet/in.h>
#include <netinet6/in6.h>
#include <sstream> // __str__
#include <sys/_types/_iovec_t.h>
#include <sys/socket.h>

#include <functional>
#include <pybind11/pybind11.h>
#include <string>

#ifndef BINDER_PYBIND11_TYPE_CASTER
#define BINDER_PYBIND11_TYPE_CASTER
PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>)
PYBIND11_DECLARE_HOLDER_TYPE(T, T *)
PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

void bind_PyChip_23(std::function<pybind11::module &(std::string const & namespace_)> & M)
{
    { // sockaddr file:sys/socket.h line:408
        pybind11::class_<sockaddr, std::shared_ptr<sockaddr>> cl(M(""), "sockaddr", "");
        cl.def(pybind11::init([]() { return new sockaddr(); }));
        cl.def_readwrite("sa_len", &sockaddr::sa_len);
        cl.def_readwrite("sa_family", &sockaddr::sa_family);
    }
    { // in_addr file:netinet/in.h line:301
        pybind11::class_<in_addr, std::shared_ptr<in_addr>> cl(M(""), "in_addr", "");
        cl.def(pybind11::init([]() { return new in_addr(); }));
        cl.def_readwrite("s_addr", &in_addr::s_addr);
    }
    { // in6_addr file:netinet6/in6.h line:152
        pybind11::class_<in6_addr, std::shared_ptr<in6_addr>> cl(M(""), "in6_addr", "");
        cl.def(pybind11::init([]() { return new in6_addr(); }));
    }
}
