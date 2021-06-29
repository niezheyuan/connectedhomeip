#include <core/CHIPTLV.h>
#include <core/CHIPTLVTypes.h>
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

// chip::TLV::TLVBackingStore file:core/CHIPTLV.h line:2236
struct PyCallBack_chip_TLV_TLVBackingStore : public chip::TLV::TLVBackingStore {
	using chip::TLV::TLVBackingStore::TLVBackingStore;

	int OnInit(class chip::TLV::TLVReader & a0, const unsigned char *& a1, unsigned int & a2) override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const chip::TLV::TLVBackingStore *>(this), "OnInit");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0, a1, a2);
			if (pybind11::detail::cast_is_temporary_value_reference<int>::value) {
				static pybind11::detail::override_caster_t<int> caster;
				return pybind11::detail::cast_ref<int>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<int>(std::move(o));
		}
		pybind11::pybind11_fail("Tried to call pure virtual function \"TLVBackingStore::OnInit\"");
	}
	int GetNextBuffer(class chip::TLV::TLVReader & a0, const unsigned char *& a1, unsigned int & a2) override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const chip::TLV::TLVBackingStore *>(this), "GetNextBuffer");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0, a1, a2);
			if (pybind11::detail::cast_is_temporary_value_reference<int>::value) {
				static pybind11::detail::override_caster_t<int> caster;
				return pybind11::detail::cast_ref<int>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<int>(std::move(o));
		}
		pybind11::pybind11_fail("Tried to call pure virtual function \"TLVBackingStore::GetNextBuffer\"");
	}
	int OnInit(class chip::TLV::TLVWriter & a0, unsigned char *& a1, unsigned int & a2) override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const chip::TLV::TLVBackingStore *>(this), "OnInit");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0, a1, a2);
			if (pybind11::detail::cast_is_temporary_value_reference<int>::value) {
				static pybind11::detail::override_caster_t<int> caster;
				return pybind11::detail::cast_ref<int>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<int>(std::move(o));
		}
		pybind11::pybind11_fail("Tried to call pure virtual function \"TLVBackingStore::OnInit\"");
	}
	int GetNewBuffer(class chip::TLV::TLVWriter & a0, unsigned char *& a1, unsigned int & a2) override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const chip::TLV::TLVBackingStore *>(this), "GetNewBuffer");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0, a1, a2);
			if (pybind11::detail::cast_is_temporary_value_reference<int>::value) {
				static pybind11::detail::override_caster_t<int> caster;
				return pybind11::detail::cast_ref<int>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<int>(std::move(o));
		}
		pybind11::pybind11_fail("Tried to call pure virtual function \"TLVBackingStore::GetNewBuffer\"");
	}
	int FinalizeBuffer(class chip::TLV::TLVWriter & a0, unsigned char * a1, unsigned int a2) override {
		pybind11::gil_scoped_acquire gil;
		pybind11::function overload = pybind11::get_overload(static_cast<const chip::TLV::TLVBackingStore *>(this), "FinalizeBuffer");
		if (overload) {
			auto o = overload.operator()<pybind11::return_value_policy::reference>(a0, a1, a2);
			if (pybind11::detail::cast_is_temporary_value_reference<int>::value) {
				static pybind11::detail::override_caster_t<int> caster;
				return pybind11::detail::cast_ref<int>(std::move(o), caster);
			}
			else return pybind11::detail::cast_safe<int>(std::move(o));
		}
		pybind11::pybind11_fail("Tried to call pure virtual function \"TLVBackingStore::FinalizeBuffer\"");
	}
};

void bind_PyChip_56(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // chip::TLV::TLVBackingStore file:core/CHIPTLV.h line:2236
		pybind11::class_<chip::TLV::TLVBackingStore, std::shared_ptr<chip::TLV::TLVBackingStore>, PyCallBack_chip_TLV_TLVBackingStore> cl(M("chip::TLV"), "TLVBackingStore", "Provides an interface for TLVReader or TLVWriter to use memory other than a simple contiguous buffer.");
		cl.def( pybind11::init( [](){ return new PyCallBack_chip_TLV_TLVBackingStore(); } ) );
		cl.def("OnInit", (int (chip::TLV::TLVBackingStore::*)(class chip::TLV::TLVReader &, const unsigned char *&, unsigned int &)) &chip::TLV::TLVBackingStore::OnInit, "A function to provide a backing store's initial start position and data length to a reader.\n\n \n          A reference to the TLVReader object that is requesting input data.\n \n\n        A reference to a data pointer. On exit, bufStart is expected to point\n                                  to the first byte of TLV data to be parsed.\n \n\n          A reference to an unsigned integer that the function must set to\n                                  the number of TLV data bytes being returned.  If the end of the\n                                  input TLV data has been reached, the function should set this value\n                                  to 0.\n\n  #CHIP_NO_ERROR           If the function successfully produced TLV data.\n  other                    Other CHIP or platform-specific error codes indicating that an error\n                                  occurred preventing the function from producing the requested data.\n\nC++: chip::TLV::TLVBackingStore::OnInit(class chip::TLV::TLVReader &, const unsigned char *&, unsigned int &) --> int", pybind11::arg("reader"), pybind11::arg("bufStart"), pybind11::arg("bufLen"));
		cl.def("GetNextBuffer", (int (chip::TLV::TLVBackingStore::*)(class chip::TLV::TLVReader &, const unsigned char *&, unsigned int &)) &chip::TLV::TLVBackingStore::GetNextBuffer, "A function that can be used to retrieve additional TLV data to be parsed.\n\n When called, the function is expected to produce additional data for the reader to parse or signal\n the reader that no more data is available.\n\n \n          A reference to the TLVReader object that is requesting input data.\n \n\n        A reference to a data pointer. On entry to the function, \n                                  points to one byte beyond the last TLV data byte consumed by the\n                                  reader.  On exit, bufStart is expected to point to the first byte\n                                  of new TLV data to be parsed.  The new pointer value can be within\n                                  the same buffer as the previously consumed data, or it can point\n                                  to an entirely new buffer.\n \n\n          A reference to an unsigned integer that the function must set to\n                                  the number of TLV data bytes being returned.  If the end of the\n                                  input TLV data has been reached, the function should set this value\n                                  to 0.\n\n  #CHIP_NO_ERROR           If the function successfully produced more TLV data, or the end of\n                                  the input data was reached ( should be set to 0 in this case).\n  other                    Other CHIP or platform-specific error codes indicating that an error\n                                  occurred preventing the function from producing the requested data.\n\nC++: chip::TLV::TLVBackingStore::GetNextBuffer(class chip::TLV::TLVReader &, const unsigned char *&, unsigned int &) --> int", pybind11::arg("reader"), pybind11::arg("bufStart"), pybind11::arg("bufLen"));
		cl.def("OnInit", (int (chip::TLV::TLVBackingStore::*)(class chip::TLV::TLVWriter &, unsigned char *&, unsigned int &)) &chip::TLV::TLVBackingStore::OnInit, "A function to provide a backing store's initial start position and data length to a writer.\n\n \n          A reference to the TLVWriter object that is requesting new buffer\n                                  space.\n \n\n        A reference to a data pointer. On exit,  is expected to\n                                  point to the beginning of the new output buffer.\n \n\n          A reference to an unsigned integer. On exit,  is expected\n                                  to contain the maximum number of bytes that can be written to the\n                                  new output buffer.\n\n  #CHIP_NO_ERROR           If the function was able to supply buffer space for the writer.\n  other                    Other CHIP or platform-specific error codes indicating that an error\n                                  occurred preventing the function from producing buffer space.\n\nC++: chip::TLV::TLVBackingStore::OnInit(class chip::TLV::TLVWriter &, unsigned char *&, unsigned int &) --> int", pybind11::arg("writer"), pybind11::arg("bufStart"), pybind11::arg("bufLen"));
		cl.def("GetNewBuffer", (int (chip::TLV::TLVBackingStore::*)(class chip::TLV::TLVWriter &, unsigned char *&, unsigned int &)) &chip::TLV::TLVBackingStore::GetNewBuffer, "A function that supplies new output buffer space to a TLVWriter.\n\n The function is expected to return a pointer to a memory location where new data should be written,\n along with an associated maximum length. The function can supply write space either by allocating\n a new buffer to hold the data or by clearing out previously written data from an existing buffer.\n\n \n          A reference to the TLVWriter object that is requesting new buffer\n                                  space.\n \n\n        A reference to a data pointer. On entry to the function, \n                                  points the beginning of the current output buffer.  On exit, \n                                  is expected to point to the beginning of the new output buffer.\n                                  The new pointer value can be the same as the previous value (e.g.\n                                  if the function copied the existing data elsewhere), or it can point\n                                  to an entirely new location.\n \n\n          A reference to an unsigned integer. On entry to the function,\n                                   contains the number of byte of  space in the\n                                  current buffer.  On exit,  is expected to contain the maximum\n                                  number of bytes that can be written to the new output buffer.\n\n  #CHIP_NO_ERROR          If the function was able to supply more buffer space for the writer.\n  other                    Other CHIP or platform-specific error codes indicating that an error\n                                  occurred preventing the function from producing additional buffer\n                                  space.\n\nC++: chip::TLV::TLVBackingStore::GetNewBuffer(class chip::TLV::TLVWriter &, unsigned char *&, unsigned int &) --> int", pybind11::arg("writer"), pybind11::arg("bufStart"), pybind11::arg("bufLen"));
		cl.def("FinalizeBuffer", (int (chip::TLV::TLVBackingStore::*)(class chip::TLV::TLVWriter &, unsigned char *, unsigned int)) &chip::TLV::TLVBackingStore::FinalizeBuffer, "A function used to perform finalization of the output from a TLVWriter object.\n\n Functions of this type are called when a TLVWriter's Finalize() method is called. The function is\n expected to perform any necessary clean-up or finalization related to consuming the output of the\n writer object. Examples of this include such things as recording the final length of the encoding,\n or closing a file descriptor.\n\n \n          A reference to the TLVWriter object that is being finalized.\n \n\n        A pointer to the beginning of the current (and final) output buffer.\n \n\n          The number of bytes contained in the buffer pointed to by \n\n  #CHIP_NO_ERROR           If finalization was successful.\n  other                    Other CHIP or platform-specific error codes indicating that an error\n                                  occurred during finalization.\n\n     \n\nC++: chip::TLV::TLVBackingStore::FinalizeBuffer(class chip::TLV::TLVWriter &, unsigned char *, unsigned int) --> int", pybind11::arg("writer"), pybind11::arg("bufStart"), pybind11::arg("bufLen"));
		cl.def("assign", (class chip::TLV::TLVBackingStore & (chip::TLV::TLVBackingStore::*)(const class chip::TLV::TLVBackingStore &)) &chip::TLV::TLVBackingStore::operator=, "C++: chip::TLV::TLVBackingStore::operator=(const class chip::TLV::TLVBackingStore &) --> class chip::TLV::TLVBackingStore &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
}
