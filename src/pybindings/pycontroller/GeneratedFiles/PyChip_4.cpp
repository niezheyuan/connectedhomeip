#include <sstream> // __str__
#include <system/SystemLayer.h>
#include <system/SystemObject.h>

#include <pybind11/pybind11.h>
#include <functional>
#include <string>

#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>)
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*)
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

void bind_PyChip_4(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // chip::System::Object file:system/SystemObject.h line:72
		pybind11::class_<chip::System::Object, chip::System::Object*> cl(M("chip::System"), "Object", "This represents a reference-counted object allocated from space contained in an ObjectPool<T, N> object.\n\n  \n\n      Instance of this class may only be constructed using the related ObjectPool class template. The copy constructor and the\n      assignment operator are deleted. A reference counting system is used to track retentions of instances of this class.\n      When an object is initially retained, its reference count is one. Additional retentions may increment the reference count.\n      When the object is released, the reference count is decremented. When the reference count is zero, the object is recycled\n      back to the pool for reallocation. There is no destructor available. Subclasses must be designed to ensure that all\n      encapsulated resources are released when the final retention is released and the object is recycled.\n\n      While this class is defined as concrete, it should be regarded as abstract.");
		cl.def("IsRetained", (bool (chip::System::Object::*)(const class chip::System::Layer &) const) &chip::System::Object::IsRetained, "Test whether this object is retained by  Concurrency safe. \n\nC++: chip::System::Object::IsRetained(const class chip::System::Layer &) const --> bool", pybind11::arg("aLayer"));
		cl.def("Retain", (void (chip::System::Object::*)()) &chip::System::Object::Retain, "C++: chip::System::Object::Retain() --> void");
		cl.def("Release", (void (chip::System::Object::*)()) &chip::System::Object::Release, "C++: chip::System::Object::Release() --> void");
		cl.def("SystemLayer", (class chip::System::Layer & (chip::System::Object::*)() const) &chip::System::Object::SystemLayer, "C++: chip::System::Object::SystemLayer() const --> class chip::System::Layer &", pybind11::return_value_policy::automatic);
	}
}
