#include <dispatch/block.h>
#include <dispatch/data.h>
#include <dispatch/group.h>
#include <dispatch/io.h>
#include <dispatch/object.h>
#include <dispatch/once.h>
#include <dispatch/queue.h>
#include <dispatch/semaphore.h>
#include <dispatch/source.h>
#include <dispatch/workloop.h>
#include <mach/message.h>
#include <sstream> // __str__

#include <pybind11/pybind11.h>
#include <functional>
#include <string>

#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>)
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*)
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

void bind_PyChip_7(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // dispatch_object_s file:dispatch/object.h line:80
		pybind11::class_<dispatch_object_s, dispatch_object_s*> cl(M(""), "dispatch_object_s", "");
	}
	{ // dispatch_queue_s file: line:168
		pybind11::class_<dispatch_queue_s, std::shared_ptr<dispatch_queue_s>, dispatch_object_s> cl(M(""), "dispatch_queue_s", "");
	}
}
