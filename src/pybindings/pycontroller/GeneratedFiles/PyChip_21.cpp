#include <ble/BleApplicationDelegate.h>
#include <ble/BleConnectionDelegate.h>
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

void bind_PyChip_21(std::function< pybind11::module &(std::string const &namespace_) > &M)
{
	{ // chip::Ble::BleLayer file:ble/BleLayer.h line:218
		pybind11::class_<chip::Ble::BleLayer, std::shared_ptr<chip::Ble::BleLayer>> cl(M("chip::Ble"), "BleLayer", "This class provides an interface for a single thread to drive data\n    either up the stack via the BleLayer platform interface functions,\n    or down the stack via a chipConnection object associated with a\n    BLEEndPoint.\n\n    There are two ways to associate a chipConnection (defined by the\n    chipMessageLayer) with a BLE connection:\n\n    First, the application can passively receive an incoming BLE connection\n    and hand the platform-specific BLE_CONNECTION_OBJECT that this receipt\n    generates to BleLayer via the corresponding platform interface function.\n    This causes BleLayer to wrap the BLE_CONNECTION_OBJECT in a BLEEndPoint,\n    and notify chipMessageLayer that a new BLE conneciotn has been received.\n    The message layer then wraps the new BLEEndPoint object in a\n    chipConnection, and hands this object to the application via the message\n    layer's OnConnectionReceived callback.\n\n    Second, the application can actively form an outgoing BLE connection, e.g.,\n    by connecting to a BLE peripheral. It then creates a new chipConnection\n    via the chipMessageLayer, assigns an authentication type to this\n    connection, and binds it to the BLE_CONNECTION_OBJECT for the new BLE\n    connection via chipConnection::ConnectBle. This function then\n    establishes the secure session type specified by the chipConnection's\n    authentication type member variable.\n\n ");
		cl.def( pybind11::init( [](){ return new chip::Ble::BleLayer(); } ) );
		cl.def( pybind11::init( [](chip::Ble::BleLayer const &o){ return new chip::Ble::BleLayer(o); } ) );
		cl.def_readwrite("mState", &chip::Ble::BleLayer::mState);
		cl.def("Init", (int (chip::Ble::BleLayer::*)(class chip::Ble::BlePlatformDelegate *, class chip::Ble::BleApplicationDelegate *, class chip::System::Layer *)) &chip::Ble::BleLayer::Init, "C++: chip::Ble::BleLayer::Init(class chip::Ble::BlePlatformDelegate *, class chip::Ble::BleApplicationDelegate *, class chip::System::Layer *) --> int", pybind11::arg("platformDelegate"), pybind11::arg("appDelegate"), pybind11::arg("systemLayer"));
		cl.def("Init", (int (chip::Ble::BleLayer::*)(class chip::Ble::BlePlatformDelegate *, class chip::Ble::BleConnectionDelegate *, class chip::Ble::BleApplicationDelegate *, class chip::System::Layer *)) &chip::Ble::BleLayer::Init, "C++: chip::Ble::BleLayer::Init(class chip::Ble::BlePlatformDelegate *, class chip::Ble::BleConnectionDelegate *, class chip::Ble::BleApplicationDelegate *, class chip::System::Layer *) --> int", pybind11::arg("platformDelegate"), pybind11::arg("connDelegate"), pybind11::arg("appDelegate"), pybind11::arg("systemLayer"));
		cl.def("Shutdown", (int (chip::Ble::BleLayer::*)()) &chip::Ble::BleLayer::Shutdown, "C++: chip::Ble::BleLayer::Shutdown() --> int");
		cl.def("CancelBleIncompleteConnection", (int (chip::Ble::BleLayer::*)()) &chip::Ble::BleLayer::CancelBleIncompleteConnection, "C++: chip::Ble::BleLayer::CancelBleIncompleteConnection() --> int");
		cl.def("NewBleConnectionByDiscriminator", (int (chip::Ble::BleLayer::*)(unsigned short)) &chip::Ble::BleLayer::NewBleConnectionByDiscriminator, "C++: chip::Ble::BleLayer::NewBleConnectionByDiscriminator(unsigned short) --> int", pybind11::arg("connDiscriminator"));
		cl.def("NewBleConnectionByObject", (int (chip::Ble::BleLayer::*)(void *)) &chip::Ble::BleLayer::NewBleConnectionByObject, "C++: chip::Ble::BleLayer::NewBleConnectionByObject(void *) --> int", pybind11::arg("connObj"));
		cl.def("CloseAllBleConnections", (int (chip::Ble::BleLayer::*)()) &chip::Ble::BleLayer::CloseAllBleConnections, "C++: chip::Ble::BleLayer::CloseAllBleConnections() --> int");
		cl.def("CloseBleConnection", (int (chip::Ble::BleLayer::*)(void *)) &chip::Ble::BleLayer::CloseBleConnection, "C++: chip::Ble::BleLayer::CloseBleConnection(void *) --> int", pybind11::arg("connObj"));
		cl.def("HandleSubscribeReceived", (bool (chip::Ble::BleLayer::*)(void *, const struct chip::Ble::ChipBleUUID *, const struct chip::Ble::ChipBleUUID *)) &chip::Ble::BleLayer::HandleSubscribeReceived, "C++: chip::Ble::BleLayer::HandleSubscribeReceived(void *, const struct chip::Ble::ChipBleUUID *, const struct chip::Ble::ChipBleUUID *) --> bool", pybind11::arg("connObj"), pybind11::arg("svcId"), pybind11::arg("charId"));
		cl.def("HandleSubscribeComplete", (bool (chip::Ble::BleLayer::*)(void *, const struct chip::Ble::ChipBleUUID *, const struct chip::Ble::ChipBleUUID *)) &chip::Ble::BleLayer::HandleSubscribeComplete, "Call when a GATT subscribe request succeeds.\n\nC++: chip::Ble::BleLayer::HandleSubscribeComplete(void *, const struct chip::Ble::ChipBleUUID *, const struct chip::Ble::ChipBleUUID *) --> bool", pybind11::arg("connObj"), pybind11::arg("svcId"), pybind11::arg("charId"));
		cl.def("HandleUnsubscribeReceived", (bool (chip::Ble::BleLayer::*)(void *, const struct chip::Ble::ChipBleUUID *, const struct chip::Ble::ChipBleUUID *)) &chip::Ble::BleLayer::HandleUnsubscribeReceived, "C++: chip::Ble::BleLayer::HandleUnsubscribeReceived(void *, const struct chip::Ble::ChipBleUUID *, const struct chip::Ble::ChipBleUUID *) --> bool", pybind11::arg("connObj"), pybind11::arg("svcId"), pybind11::arg("charId"));
		cl.def("HandleUnsubscribeComplete", (bool (chip::Ble::BleLayer::*)(void *, const struct chip::Ble::ChipBleUUID *, const struct chip::Ble::ChipBleUUID *)) &chip::Ble::BleLayer::HandleUnsubscribeComplete, "Call when a GATT unsubscribe request succeeds.\n\nC++: chip::Ble::BleLayer::HandleUnsubscribeComplete(void *, const struct chip::Ble::ChipBleUUID *, const struct chip::Ble::ChipBleUUID *) --> bool", pybind11::arg("connObj"), pybind11::arg("svcId"), pybind11::arg("charId"));
		cl.def("HandleWriteConfirmation", (bool (chip::Ble::BleLayer::*)(void *, const struct chip::Ble::ChipBleUUID *, const struct chip::Ble::ChipBleUUID *)) &chip::Ble::BleLayer::HandleWriteConfirmation, "Call when an outstanding GATT write request receives a positive receipt confirmation.\n\nC++: chip::Ble::BleLayer::HandleWriteConfirmation(void *, const struct chip::Ble::ChipBleUUID *, const struct chip::Ble::ChipBleUUID *) --> bool", pybind11::arg("connObj"), pybind11::arg("svcId"), pybind11::arg("charId"));
		cl.def("HandleIndicationConfirmation", (bool (chip::Ble::BleLayer::*)(void *, const struct chip::Ble::ChipBleUUID *, const struct chip::Ble::ChipBleUUID *)) &chip::Ble::BleLayer::HandleIndicationConfirmation, "Call when an oustanding GATT indication receives a positive receipt confirmation.\n\nC++: chip::Ble::BleLayer::HandleIndicationConfirmation(void *, const struct chip::Ble::ChipBleUUID *, const struct chip::Ble::ChipBleUUID *) --> bool", pybind11::arg("connObj"), pybind11::arg("svcId"), pybind11::arg("charId"));
		cl.def("HandleReadReceived", (bool (chip::Ble::BleLayer::*)(void *, void *, const struct chip::Ble::ChipBleUUID *, const struct chip::Ble::ChipBleUUID *)) &chip::Ble::BleLayer::HandleReadReceived, "Call when a GATT read request is received.\n\nC++: chip::Ble::BleLayer::HandleReadReceived(void *, void *, const struct chip::Ble::ChipBleUUID *, const struct chip::Ble::ChipBleUUID *) --> bool", pybind11::arg("connObj"), pybind11::arg("requestContext"), pybind11::arg("svcId"), pybind11::arg("charId"));
		cl.def("HandleConnectionError", (void (chip::Ble::BleLayer::*)(void *, int)) &chip::Ble::BleLayer::HandleConnectionError, "C++: chip::Ble::BleLayer::HandleConnectionError(void *, int) --> void", pybind11::arg("connObj"), pybind11::arg("err"));
		cl.def("assign", (class chip::Ble::BleLayer & (chip::Ble::BleLayer::*)(const class chip::Ble::BleLayer &)) &chip::Ble::BleLayer::operator=, "C++: chip::Ble::BleLayer::operator=(const class chip::Ble::BleLayer &) --> class chip::Ble::BleLayer &", pybind11::return_value_policy::automatic, pybind11::arg(""));
	}
}
