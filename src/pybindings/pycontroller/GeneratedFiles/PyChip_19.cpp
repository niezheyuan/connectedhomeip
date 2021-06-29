#include <ble/BleApplicationDelegate.h>
#include <ble/BleConnectionDelegate.h>
#include <ble/BleError.h>
#include <ble/BleLayer.h>
#include <ble/BlePlatformDelegate.h>
#include <ble/BleUUID.h>
#include <sstream> // __str__
#include <system/SystemLayer.h>
#include <system/SystemPacketBuffer.h>

#include <pybind11/pybind11.h>
#include <functional>
#include <string>

#ifndef BINDER_PYBIND11_TYPE_CASTER
	#define BINDER_PYBIND11_TYPE_CASTER
	PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>)
	PYBIND11_DECLARE_HOLDER_TYPE(T, T*)
	PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

// chip::Ble::BleApplicationDelegate file:ble/BleApplicationDelegate.h line:35
struct PyCallBack_chip_Ble_BleApplicationDelegate : public chip::Ble::BleApplicationDelegate {
	using chip::Ble::BleApplicationDelegate::BleApplicationDelegate;

	void NotifyChipConnectionClosed(void * a0) override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const chip::Ble::BleApplicationDelegate *>(this), "NotifyChipConnectionClosed");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0);
			if (pybind11::detail::cast_is_temporary_value_reference<void>::value) {
				static pybind11::detail::override_caster_t<void> caster;
				return pybind11::detail::cast_ref<void>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<void>(std::move(o));
		}
		pybind11::pybind11_fail("Tried to call pure virtual function \"BleApplicationDelegate::NotifyChipConnectionClosed\"");
	}
};

// chip::Ble::BleConnectionDelegate file:ble/BleConnectionDelegate.h line:41
struct PyCallBack_chip_Ble_BleConnectionDelegate : public chip::Ble::BleConnectionDelegate {
	using chip::Ble::BleConnectionDelegate::BleConnectionDelegate;

	void NewConnection(class chip::Ble::BleLayer * a0, void * a1, unsigned short a2) override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const chip::Ble::BleConnectionDelegate *>(this), "NewConnection");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0, a1, a2);
			if (pybind11::detail::cast_is_temporary_value_reference<void>::value) {
				static pybind11::detail::override_caster_t<void> caster;
				return pybind11::detail::cast_ref<void>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<void>(std::move(o));
		}
		pybind11::pybind11_fail("Tried to call pure virtual function \"BleConnectionDelegate::NewConnection\"");
	}
	int CancelConnection() override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const chip::Ble::BleConnectionDelegate *>(this), "CancelConnection");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>();
			if (pybind11::detail::cast_is_temporary_value_reference<int>::value) {
				static pybind11::detail::override_caster_t<int> caster;
				return pybind11::detail::cast_ref<int>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<int>(std::move(o));
		}
		pybind11::pybind11_fail("Tried to call pure virtual function \"BleConnectionDelegate::CancelConnection\"");
	}
};

void bind_PyChip_19(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // chip::Ble::BleApplicationDelegate file:ble/BleApplicationDelegate.h line:35
		pybind11::class_<chip::Ble::BleApplicationDelegate, std::shared_ptr<chip::Ble::BleApplicationDelegate>, PyCallBack_chip_Ble_BleApplicationDelegate> cl(M("chip::Ble"), "BleApplicationDelegate", "");
		cl.def( pybind11::init( [](){ return new PyCallBack_chip_Ble_BleApplicationDelegate(); } ) );
		cl.def("NotifyChipConnectionClosed", (void (chip::Ble::BleApplicationDelegate::*)(void *)) &chip::Ble::BleApplicationDelegate::NotifyChipConnectionClosed, "C++: chip::Ble::BleApplicationDelegate::NotifyChipConnectionClosed(void *) --> void", pybind11::arg("connObj"));
		cl.def("assign", (class chip::Ble::BleApplicationDelegate & (chip::Ble::BleApplicationDelegate::*)(const class chip::Ble::BleApplicationDelegate &)) &chip::Ble::BleApplicationDelegate::operator=, "C++: chip::Ble::BleApplicationDelegate::operator=(const class chip::Ble::BleApplicationDelegate &) --> class chip::Ble::BleApplicationDelegate &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
	// chip::Ble::RegisterLayerErrorFormatter() file:ble/BleError.h line:428
	M("chip::Ble").def("RegisterLayerErrorFormatter", (void (*)()) &chip::Ble::RegisterLayerErrorFormatter, "C++: chip::Ble::RegisterLayerErrorFormatter() --> void");

	// chip::Ble::FormatLayerError(char *, unsigned short, int) file:ble/BleError.h line:429
	M("chip::Ble").def("FormatLayerError", (bool (*)(char *, unsigned short, int)) &chip::Ble::FormatLayerError, "C++: chip::Ble::FormatLayerError(char *, unsigned short, int) --> bool", pybind11::arg("buf"), pybind11::arg("bufSize"), pybind11::arg("err"));

	{ // chip::Ble::BleConnectionDelegate file:ble/BleConnectionDelegate.h line:41
		pybind11::class_<chip::Ble::BleConnectionDelegate, std::shared_ptr<chip::Ble::BleConnectionDelegate>, PyCallBack_chip_Ble_BleConnectionDelegate> cl(M("chip::Ble"), "BleConnectionDelegate", "");
		cl.def( pybind11::init( [](){ return new PyCallBack_chip_Ble_BleConnectionDelegate(); } ) );
		cl.def("NewConnection", (void (chip::Ble::BleConnectionDelegate::*)(class chip::Ble::BleLayer *, void *, unsigned short)) &chip::Ble::BleConnectionDelegate::NewConnection, "C++: chip::Ble::BleConnectionDelegate::NewConnection(class chip::Ble::BleLayer *, void *, unsigned short) --> void", pybind11::arg("bleLayer"), pybind11::arg("appState"), pybind11::arg("connDiscriminator"));
		cl.def("CancelConnection", (int (chip::Ble::BleConnectionDelegate::*)()) &chip::Ble::BleConnectionDelegate::CancelConnection, "C++: chip::Ble::BleConnectionDelegate::CancelConnection() --> int");
		cl.def("assign", (class chip::Ble::BleConnectionDelegate & (chip::Ble::BleConnectionDelegate::*)(const class chip::Ble::BleConnectionDelegate &)) &chip::Ble::BleConnectionDelegate::operator=, "C++: chip::Ble::BleConnectionDelegate::operator=(const class chip::Ble::BleConnectionDelegate &) --> class chip::Ble::BleConnectionDelegate &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
}
