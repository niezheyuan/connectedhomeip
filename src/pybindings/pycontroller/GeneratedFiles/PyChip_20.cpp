#include <ble/BLEEndPoint.h>
#include <ble/BleLayer.h>
#include <ble/BleLayerDelegate.h>
#include <ble/BlePlatformDelegate.h>
#include <ble/BleUUID.h>
#include <ble/BtpEngine.h>
#include <sstream> // __str__
#include <system/SystemPacketBuffer.h>

#include <functional>
#include <pybind11/pybind11.h>
#include <string>

#ifndef BINDER_PYBIND11_TYPE_CASTER
#define BINDER_PYBIND11_TYPE_CASTER
PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>)
PYBIND11_DECLARE_HOLDER_TYPE(T, T *)
PYBIND11_MAKE_OPAQUE(std::shared_ptr<void>)
#endif

// chip::Ble::BlePlatformDelegate file:ble/BlePlatformDelegate.h line:40
struct PyCallBack_chip_Ble_BlePlatformDelegate : public chip::Ble::BlePlatformDelegate
{
    using chip::Ble::BlePlatformDelegate::BlePlatformDelegate;

    bool SubscribeCharacteristic(void * a0, const struct chip::Ble::ChipBleUUID * a1,
                                 const struct chip::Ble::ChipBleUUID * a2) override
    {
        pybind11::gil_scoped_acquire gil;
        pybind11::function overload =
            pybind11::get_overload(static_cast<const chip::Ble::BlePlatformDelegate *>(this), "SubscribeCharacteristic");
        if (overload)
        {
            auto o = overload.operator()<pybind11::return_value_policy::reference>(a0, a1, a2);
            if (pybind11::detail::cast_is_temporary_value_reference<bool>::value)
            {
                static pybind11::detail::override_caster_t<bool> caster;
                return pybind11::detail::cast_ref<bool>(std::move(o), caster);
            }
            else
                return pybind11::detail::cast_safe<bool>(std::move(o));
        }
        pybind11::pybind11_fail("Tried to call pure virtual function \"BlePlatformDelegate::SubscribeCharacteristic\"");
    }
    bool UnsubscribeCharacteristic(void * a0, const struct chip::Ble::ChipBleUUID * a1,
                                   const struct chip::Ble::ChipBleUUID * a2) override
    {
        pybind11::gil_scoped_acquire gil;
        pybind11::function overload =
            pybind11::get_overload(static_cast<const chip::Ble::BlePlatformDelegate *>(this), "UnsubscribeCharacteristic");
        if (overload)
        {
            auto o = overload.operator()<pybind11::return_value_policy::reference>(a0, a1, a2);
            if (pybind11::detail::cast_is_temporary_value_reference<bool>::value)
            {
                static pybind11::detail::override_caster_t<bool> caster;
                return pybind11::detail::cast_ref<bool>(std::move(o), caster);
            }
            else
                return pybind11::detail::cast_safe<bool>(std::move(o));
        }
        pybind11::pybind11_fail("Tried to call pure virtual function \"BlePlatformDelegate::UnsubscribeCharacteristic\"");
    }
    bool CloseConnection(void * a0) override
    {
        pybind11::gil_scoped_acquire gil;
        pybind11::function overload =
            pybind11::get_overload(static_cast<const chip::Ble::BlePlatformDelegate *>(this), "CloseConnection");
        if (overload)
        {
            auto o = overload.operator()<pybind11::return_value_policy::reference>(a0);
            if (pybind11::detail::cast_is_temporary_value_reference<bool>::value)
            {
                static pybind11::detail::override_caster_t<bool> caster;
                return pybind11::detail::cast_ref<bool>(std::move(o), caster);
            }
            else
                return pybind11::detail::cast_safe<bool>(std::move(o));
        }
        pybind11::pybind11_fail("Tried to call pure virtual function \"BlePlatformDelegate::CloseConnection\"");
    }
    unsigned short GetMTU(void * a0) const override
    {
        pybind11::gil_scoped_acquire gil;
        pybind11::function overload = pybind11::get_overload(static_cast<const chip::Ble::BlePlatformDelegate *>(this), "GetMTU");
        if (overload)
        {
            auto o = overload.operator()<pybind11::return_value_policy::reference>(a0);
            if (pybind11::detail::cast_is_temporary_value_reference<unsigned short>::value)
            {
                static pybind11::detail::override_caster_t<unsigned short> caster;
                return pybind11::detail::cast_ref<unsigned short>(std::move(o), caster);
            }
            else
                return pybind11::detail::cast_safe<unsigned short>(std::move(o));
        }
        pybind11::pybind11_fail("Tried to call pure virtual function \"BlePlatformDelegate::GetMTU\"");
    }
    bool SendIndication(void * a0, const struct chip::Ble::ChipBleUUID * a1, const struct chip::Ble::ChipBleUUID * a2,
                        class chip::System::PacketBufferHandle a3) override
    {
        pybind11::gil_scoped_acquire gil;
        pybind11::function overload =
            pybind11::get_overload(static_cast<const chip::Ble::BlePlatformDelegate *>(this), "SendIndication");
        if (overload)
        {
            auto o = overload.operator()<pybind11::return_value_policy::reference>(a0, a1, a2, a3);
            if (pybind11::detail::cast_is_temporary_value_reference<bool>::value)
            {
                static pybind11::detail::override_caster_t<bool> caster;
                return pybind11::detail::cast_ref<bool>(std::move(o), caster);
            }
            else
                return pybind11::detail::cast_safe<bool>(std::move(o));
        }
        pybind11::pybind11_fail("Tried to call pure virtual function \"BlePlatformDelegate::SendIndication\"");
    }
    bool SendWriteRequest(void * a0, const struct chip::Ble::ChipBleUUID * a1, const struct chip::Ble::ChipBleUUID * a2,
                          class chip::System::PacketBufferHandle a3) override
    {
        pybind11::gil_scoped_acquire gil;
        pybind11::function overload =
            pybind11::get_overload(static_cast<const chip::Ble::BlePlatformDelegate *>(this), "SendWriteRequest");
        if (overload)
        {
            auto o = overload.operator()<pybind11::return_value_policy::reference>(a0, a1, a2, a3);
            if (pybind11::detail::cast_is_temporary_value_reference<bool>::value)
            {
                static pybind11::detail::override_caster_t<bool> caster;
                return pybind11::detail::cast_ref<bool>(std::move(o), caster);
            }
            else
                return pybind11::detail::cast_safe<bool>(std::move(o));
        }
        pybind11::pybind11_fail("Tried to call pure virtual function \"BlePlatformDelegate::SendWriteRequest\"");
    }
    bool SendReadRequest(void * a0, const struct chip::Ble::ChipBleUUID * a1, const struct chip::Ble::ChipBleUUID * a2,
                         class chip::System::PacketBufferHandle a3) override
    {
        pybind11::gil_scoped_acquire gil;
        pybind11::function overload =
            pybind11::get_overload(static_cast<const chip::Ble::BlePlatformDelegate *>(this), "SendReadRequest");
        if (overload)
        {
            auto o = overload.operator()<pybind11::return_value_policy::reference>(a0, a1, a2, a3);
            if (pybind11::detail::cast_is_temporary_value_reference<bool>::value)
            {
                static pybind11::detail::override_caster_t<bool> caster;
                return pybind11::detail::cast_ref<bool>(std::move(o), caster);
            }
            else
                return pybind11::detail::cast_safe<bool>(std::move(o));
        }
        pybind11::pybind11_fail("Tried to call pure virtual function \"BlePlatformDelegate::SendReadRequest\"");
    }
    bool SendReadResponse(void * a0, void * a1, const struct chip::Ble::ChipBleUUID * a2,
                          const struct chip::Ble::ChipBleUUID * a3) override
    {
        pybind11::gil_scoped_acquire gil;
        pybind11::function overload =
            pybind11::get_overload(static_cast<const chip::Ble::BlePlatformDelegate *>(this), "SendReadResponse");
        if (overload)
        {
            auto o = overload.operator()<pybind11::return_value_policy::reference>(a0, a1, a2, a3);
            if (pybind11::detail::cast_is_temporary_value_reference<bool>::value)
            {
                static pybind11::detail::override_caster_t<bool> caster;
                return pybind11::detail::cast_ref<bool>(std::move(o), caster);
            }
            else
                return pybind11::detail::cast_safe<bool>(std::move(o));
        }
        pybind11::pybind11_fail("Tried to call pure virtual function \"BlePlatformDelegate::SendReadResponse\"");
    }
};

void bind_PyChip_20(std::function<pybind11::module &(std::string const & namespace_)> & M)
{
    { // chip::Ble::BtpEngine file:ble/BtpEngine.h line:74
        pybind11::class_<chip::Ble::BtpEngine, std::shared_ptr<chip::Ble::BtpEngine>> cl(M("chip::Ble"), "BtpEngine", "");
        cl.def(pybind11::init([]() { return new chip::Ble::BtpEngine(); }));

        pybind11::enum_<chip::Ble::BtpEngine::HeaderFlags>(cl, "HeaderFlags", "")
            .value("kStartMessage", chip::Ble::BtpEngine::HeaderFlags::kStartMessage)
            .value("kContinueMessage", chip::Ble::BtpEngine::HeaderFlags::kContinueMessage)
            .value("kEndMessage", chip::Ble::BtpEngine::HeaderFlags::kEndMessage)
            .value("kFragmentAck", chip::Ble::BtpEngine::HeaderFlags::kFragmentAck);

        cl.def("Init", (int (chip::Ble::BtpEngine::*)(void *, bool)) & chip::Ble::BtpEngine::Init,
               "C++: chip::Ble::BtpEngine::Init(void *, bool) --> int", pybind11::arg("an_app_state"),
               pybind11::arg("expect_first_ack"));
        cl.def("SetTxFragmentSize", (void (chip::Ble::BtpEngine::*)(unsigned short)) & chip::Ble::BtpEngine::SetTxFragmentSize,
               "C++: chip::Ble::BtpEngine::SetTxFragmentSize(unsigned short) --> void", pybind11::arg("size"));
        cl.def("SetRxFragmentSize", (void (chip::Ble::BtpEngine::*)(unsigned short)) & chip::Ble::BtpEngine::SetRxFragmentSize,
               "C++: chip::Ble::BtpEngine::SetRxFragmentSize(unsigned short) --> void", pybind11::arg("size"));
        cl.def("GetRxFragmentSize", (unsigned short (chip::Ble::BtpEngine::*)()) & chip::Ble::BtpEngine::GetRxFragmentSize,
               "C++: chip::Ble::BtpEngine::GetRxFragmentSize() --> unsigned short");
        cl.def("GetTxFragmentSize", (unsigned short (chip::Ble::BtpEngine::*)()) & chip::Ble::BtpEngine::GetTxFragmentSize,
               "C++: chip::Ble::BtpEngine::GetTxFragmentSize() --> unsigned short");
        cl.def("GetAndIncrementNextTxSeqNum",
               (unsigned char (chip::Ble::BtpEngine::*)()) & chip::Ble::BtpEngine::GetAndIncrementNextTxSeqNum,
               "C++: chip::Ble::BtpEngine::GetAndIncrementNextTxSeqNum() --> unsigned char");
        cl.def("GetAndRecordRxAckSeqNum",
               (unsigned char (chip::Ble::BtpEngine::*)()) & chip::Ble::BtpEngine::GetAndRecordRxAckSeqNum,
               "C++: chip::Ble::BtpEngine::GetAndRecordRxAckSeqNum() --> unsigned char");
        cl.def("GetLastReceivedSequenceNumber",
               (unsigned char (chip::Ble::BtpEngine::*)()) & chip::Ble::BtpEngine::GetLastReceivedSequenceNumber,
               "C++: chip::Ble::BtpEngine::GetLastReceivedSequenceNumber() --> unsigned char");
        cl.def("GetNewestUnackedSentSequenceNumber",
               (unsigned char (chip::Ble::BtpEngine::*)()) & chip::Ble::BtpEngine::GetNewestUnackedSentSequenceNumber,
               "C++: chip::Ble::BtpEngine::GetNewestUnackedSentSequenceNumber() --> unsigned char");
        cl.def("ExpectingAck", (bool (chip::Ble::BtpEngine::*)() const) & chip::Ble::BtpEngine::ExpectingAck,
               "C++: chip::Ble::BtpEngine::ExpectingAck() const --> bool");
        cl.def("RxState", (chip::Ble::BtpEngine::State_t(chip::Ble::BtpEngine::*)()) & chip::Ble::BtpEngine::RxState,
               "C++: chip::Ble::BtpEngine::RxState() --> chip::Ble::BtpEngine::State_t");
        cl.def("TxState", (chip::Ble::BtpEngine::State_t(chip::Ble::BtpEngine::*)()) & chip::Ble::BtpEngine::TxState,
               "C++: chip::Ble::BtpEngine::TxState() --> chip::Ble::BtpEngine::State_t");
        cl.def("HasUnackedData", (bool (chip::Ble::BtpEngine::*)() const) & chip::Ble::BtpEngine::HasUnackedData,
               "C++: chip::Ble::BtpEngine::HasUnackedData() const --> bool");
        cl.def("HandleCharacteristicSend",
               (bool (chip::Ble::BtpEngine::*)(class chip::System::PacketBufferHandle, bool)) &
                   chip::Ble::BtpEngine::HandleCharacteristicSend,
               "C++: chip::Ble::BtpEngine::HandleCharacteristicSend(class chip::System::PacketBufferHandle, bool) --> bool",
               pybind11::arg("data"), pybind11::arg("send_ack"));
        cl.def("EncodeStandAloneAck",
               (int (chip::Ble::BtpEngine::*)(const class chip::System::PacketBufferHandle &)) &
                   chip::Ble::BtpEngine::EncodeStandAloneAck,
               "C++: chip::Ble::BtpEngine::EncodeStandAloneAck(const class chip::System::PacketBufferHandle &) --> int",
               pybind11::arg("data"));
        cl.def("TakeRxPacket",
               (class chip::System::PacketBufferHandle(chip::Ble::BtpEngine::*)()) & chip::Ble::BtpEngine::TakeRxPacket,
               "C++: chip::Ble::BtpEngine::TakeRxPacket() --> class chip::System::PacketBufferHandle");
        cl.def("BorrowRxPacket",
               (class chip::System::PacketBufferHandle(chip::Ble::BtpEngine::*)()) & chip::Ble::BtpEngine::BorrowRxPacket,
               "C++: chip::Ble::BtpEngine::BorrowRxPacket() --> class chip::System::PacketBufferHandle");
        cl.def("ClearRxPacket", (void (chip::Ble::BtpEngine::*)()) & chip::Ble::BtpEngine::ClearRxPacket,
               "C++: chip::Ble::BtpEngine::ClearRxPacket() --> void");
        cl.def("TakeTxPacket",
               (class chip::System::PacketBufferHandle(chip::Ble::BtpEngine::*)()) & chip::Ble::BtpEngine::TakeTxPacket,
               "C++: chip::Ble::BtpEngine::TakeTxPacket() --> class chip::System::PacketBufferHandle");
        cl.def("BorrowTxPacket",
               (class chip::System::PacketBufferHandle(chip::Ble::BtpEngine::*)()) & chip::Ble::BtpEngine::BorrowTxPacket,
               "C++: chip::Ble::BtpEngine::BorrowTxPacket() --> class chip::System::PacketBufferHandle");
        cl.def("ClearTxPacket", (void (chip::Ble::BtpEngine::*)()) & chip::Ble::BtpEngine::ClearTxPacket,
               "C++: chip::Ble::BtpEngine::ClearTxPacket() --> void");
        cl.def("LogState", (void (chip::Ble::BtpEngine::*)() const) & chip::Ble::BtpEngine::LogState,
               "C++: chip::Ble::BtpEngine::LogState() const --> void");
        cl.def("LogStateDebug", (void (chip::Ble::BtpEngine::*)() const) & chip::Ble::BtpEngine::LogStateDebug,
               "C++: chip::Ble::BtpEngine::LogStateDebug() const --> void");
    }
    { // chip::Ble::BLEEndPoint file:ble/BLEEndPoint.h line:59
        pybind11::class_<chip::Ble::BLEEndPoint, chip::Ble::BLEEndPoint *> cl(M("chip::Ble"), "BLEEndPoint", "");
        cl.def_readwrite("mState", &chip::Ble::BLEEndPoint::mState);
        cl.def("StartConnect", (int (chip::Ble::BLEEndPoint::*)()) & chip::Ble::BLEEndPoint::StartConnect,
               "C++: chip::Ble::BLEEndPoint::StartConnect() --> int");
        cl.def("IsUnsubscribePending", (bool (chip::Ble::BLEEndPoint::*)() const) & chip::Ble::BLEEndPoint::IsUnsubscribePending,
               "C++: chip::Ble::BLEEndPoint::IsUnsubscribePending() const --> bool");
        cl.def("ConnectionObjectIs", (bool (chip::Ble::BLEEndPoint::*)(void *)) & chip::Ble::BLEEndPoint::ConnectionObjectIs,
               "C++: chip::Ble::BLEEndPoint::ConnectionObjectIs(void *) --> bool", pybind11::arg("connObj"));
        cl.def("Close", (void (chip::Ble::BLEEndPoint::*)()) & chip::Ble::BLEEndPoint::Close,
               "C++: chip::Ble::BLEEndPoint::Close() --> void");
        cl.def("Abort", (void (chip::Ble::BLEEndPoint::*)()) & chip::Ble::BLEEndPoint::Abort,
               "C++: chip::Ble::BLEEndPoint::Abort() --> void");
    }
    { // chip::Ble::ChipBleUUID file:ble/BleUUID.h line:29
        pybind11::class_<chip::Ble::ChipBleUUID, std::shared_ptr<chip::Ble::ChipBleUUID>> cl(M("chip::Ble"), "ChipBleUUID", "");
        cl.def(pybind11::init([]() { return new chip::Ble::ChipBleUUID(); }));
    }
    // chip::Ble::UUIDsMatch(const struct chip::Ble::ChipBleUUID *, const struct chip::Ble::ChipBleUUID *) file:ble/BleUUID.h
    // line:37
    M("chip::Ble")
        .def("UUIDsMatch",
             (bool (*)(const struct chip::Ble::ChipBleUUID *, const struct chip::Ble::ChipBleUUID *)) & chip::Ble::UUIDsMatch,
             "C++: chip::Ble::UUIDsMatch(const struct chip::Ble::ChipBleUUID *, const struct chip::Ble::ChipBleUUID *) --> bool",
             pybind11::arg("idOne"), pybind11::arg("idTwo"));

    // chip::Ble::StringToUUID(const char *, struct chip::Ble::ChipBleUUID &) file:ble/BleUUID.h line:38
    M("chip::Ble")
        .def("StringToUUID", (bool (*)(const char *, struct chip::Ble::ChipBleUUID &)) & chip::Ble::StringToUUID,
             "C++: chip::Ble::StringToUUID(const char *, struct chip::Ble::ChipBleUUID &) --> bool", pybind11::arg("str"),
             pybind11::arg("uuid"));

    { // chip::Ble::BleLayerDelegate file:ble/BleLayerDelegate.h line:35
        pybind11::class_<chip::Ble::BleLayerDelegate, std::shared_ptr<chip::Ble::BleLayerDelegate>> cl(M("chip::Ble"),
                                                                                                       "BleLayerDelegate", "");
        cl.def("OnBleConnectionComplete",
               (void (chip::Ble::BleLayerDelegate::*)(class chip::Ble::BLEEndPoint *)) &
                   chip::Ble::BleLayerDelegate::OnBleConnectionComplete,
               "C++: chip::Ble::BleLayerDelegate::OnBleConnectionComplete(class chip::Ble::BLEEndPoint *) --> void",
               pybind11::arg("endpoint"));
        cl.def("OnBleConnectionError",
               (void (chip::Ble::BleLayerDelegate::*)(int)) & chip::Ble::BleLayerDelegate::OnBleConnectionError,
               "C++: chip::Ble::BleLayerDelegate::OnBleConnectionError(int) --> void", pybind11::arg("err"));
        cl.def("OnEndPointConnectComplete",
               (void (chip::Ble::BleLayerDelegate::*)(class chip::Ble::BLEEndPoint *, int)) &
                   chip::Ble::BleLayerDelegate::OnEndPointConnectComplete,
               "C++: chip::Ble::BleLayerDelegate::OnEndPointConnectComplete(class chip::Ble::BLEEndPoint *, int) --> void",
               pybind11::arg("endPoint"), pybind11::arg("err"));
        cl.def("OnEndPointConnectionClosed",
               (void (chip::Ble::BleLayerDelegate::*)(class chip::Ble::BLEEndPoint *, int)) &
                   chip::Ble::BleLayerDelegate::OnEndPointConnectionClosed,
               "C++: chip::Ble::BleLayerDelegate::OnEndPointConnectionClosed(class chip::Ble::BLEEndPoint *, int) --> void",
               pybind11::arg("endPoint"), pybind11::arg("err"));
        cl.def("SetEndPoint",
               (int (chip::Ble::BleLayerDelegate::*)(class chip::Ble::BLEEndPoint *)) & chip::Ble::BleLayerDelegate::SetEndPoint,
               "C++: chip::Ble::BleLayerDelegate::SetEndPoint(class chip::Ble::BLEEndPoint *) --> int", pybind11::arg("endPoint"));
        cl.def("assign",
               (class chip::Ble::BleLayerDelegate & (chip::Ble::BleLayerDelegate::*) (const class chip::Ble::BleLayerDelegate &) ) &
                   chip::Ble::BleLayerDelegate::operator=,
               "C++: chip::Ble::BleLayerDelegate::operator=(const class chip::Ble::BleLayerDelegate &) --> class "
               "chip::Ble::BleLayerDelegate &",
               pybind11::return_value_policy::automatic, pybind11::arg(""));
    }
    { // chip::Ble::BlePlatformDelegate file:ble/BlePlatformDelegate.h line:40
        pybind11::class_<chip::Ble::BlePlatformDelegate, std::shared_ptr<chip::Ble::BlePlatformDelegate>,
                         PyCallBack_chip_Ble_BlePlatformDelegate>
            cl(M("chip::Ble"), "BlePlatformDelegate", "");
        cl.def(pybind11::init([]() { return new PyCallBack_chip_Ble_BlePlatformDelegate(); }));
        cl.def("SubscribeCharacteristic",
               (bool (chip::Ble::BlePlatformDelegate::*)(void *, const struct chip::Ble::ChipBleUUID *,
                                                         const struct chip::Ble::ChipBleUUID *)) &
                   chip::Ble::BlePlatformDelegate::SubscribeCharacteristic,
               "C++: chip::Ble::BlePlatformDelegate::SubscribeCharacteristic(void *, const struct chip::Ble::ChipBleUUID *, const "
               "struct chip::Ble::ChipBleUUID *) --> bool",
               pybind11::arg("connObj"), pybind11::arg("svcId"), pybind11::arg("charId"));
        cl.def("UnsubscribeCharacteristic",
               (bool (chip::Ble::BlePlatformDelegate::*)(void *, const struct chip::Ble::ChipBleUUID *,
                                                         const struct chip::Ble::ChipBleUUID *)) &
                   chip::Ble::BlePlatformDelegate::UnsubscribeCharacteristic,
               "C++: chip::Ble::BlePlatformDelegate::UnsubscribeCharacteristic(void *, const struct chip::Ble::ChipBleUUID *, "
               "const struct chip::Ble::ChipBleUUID *) --> bool",
               pybind11::arg("connObj"), pybind11::arg("svcId"), pybind11::arg("charId"));
        cl.def("CloseConnection",
               (bool (chip::Ble::BlePlatformDelegate::*)(void *)) & chip::Ble::BlePlatformDelegate::CloseConnection,
               "C++: chip::Ble::BlePlatformDelegate::CloseConnection(void *) --> bool", pybind11::arg("connObj"));
        cl.def("GetMTU",
               (unsigned short (chip::Ble::BlePlatformDelegate::*)(void *) const) & chip::Ble::BlePlatformDelegate::GetMTU,
               "C++: chip::Ble::BlePlatformDelegate::GetMTU(void *) const --> unsigned short", pybind11::arg("connObj"));
        cl.def("SendIndication",
               (bool (chip::Ble::BlePlatformDelegate::*)(void *, const struct chip::Ble::ChipBleUUID *,
                                                         const struct chip::Ble::ChipBleUUID *,
                                                         class chip::System::PacketBufferHandle)) &
                   chip::Ble::BlePlatformDelegate::SendIndication,
               "C++: chip::Ble::BlePlatformDelegate::SendIndication(void *, const struct chip::Ble::ChipBleUUID *, const struct "
               "chip::Ble::ChipBleUUID *, class chip::System::PacketBufferHandle) --> bool",
               pybind11::arg("connObj"), pybind11::arg("svcId"), pybind11::arg("charId"), pybind11::arg("pBuf"));
        cl.def("SendWriteRequest",
               (bool (chip::Ble::BlePlatformDelegate::*)(void *, const struct chip::Ble::ChipBleUUID *,
                                                         const struct chip::Ble::ChipBleUUID *,
                                                         class chip::System::PacketBufferHandle)) &
                   chip::Ble::BlePlatformDelegate::SendWriteRequest,
               "C++: chip::Ble::BlePlatformDelegate::SendWriteRequest(void *, const struct chip::Ble::ChipBleUUID *, const struct "
               "chip::Ble::ChipBleUUID *, class chip::System::PacketBufferHandle) --> bool",
               pybind11::arg("connObj"), pybind11::arg("svcId"), pybind11::arg("charId"), pybind11::arg("pBuf"));
        cl.def("SendReadRequest",
               (bool (chip::Ble::BlePlatformDelegate::*)(void *, const struct chip::Ble::ChipBleUUID *,
                                                         const struct chip::Ble::ChipBleUUID *,
                                                         class chip::System::PacketBufferHandle)) &
                   chip::Ble::BlePlatformDelegate::SendReadRequest,
               "C++: chip::Ble::BlePlatformDelegate::SendReadRequest(void *, const struct chip::Ble::ChipBleUUID *, const struct "
               "chip::Ble::ChipBleUUID *, class chip::System::PacketBufferHandle) --> bool",
               pybind11::arg("connObj"), pybind11::arg("svcId"), pybind11::arg("charId"), pybind11::arg("pBuf"));
        cl.def("SendReadResponse",
               (bool (chip::Ble::BlePlatformDelegate::*)(void *, void *, const struct chip::Ble::ChipBleUUID *,
                                                         const struct chip::Ble::ChipBleUUID *)) &
                   chip::Ble::BlePlatformDelegate::SendReadResponse,
               "C++: chip::Ble::BlePlatformDelegate::SendReadResponse(void *, void *, const struct chip::Ble::ChipBleUUID *, const "
               "struct chip::Ble::ChipBleUUID *) --> bool",
               pybind11::arg("connObj"), pybind11::arg("requestContext"), pybind11::arg("svcId"), pybind11::arg("charId"));
        cl.def("assign",
               (class chip::Ble::BlePlatformDelegate &
                (chip::Ble::BlePlatformDelegate::*) (const class chip::Ble::BlePlatformDelegate &) ) &
                   chip::Ble::BlePlatformDelegate::operator=,
               "C++: chip::Ble::BlePlatformDelegate::operator=(const class chip::Ble::BlePlatformDelegate &) --> class "
               "chip::Ble::BlePlatformDelegate &",
               pybind11::return_value_policy::automatic, pybind11::arg(""));
    }
    { // chip::Ble::BleTransportCapabilitiesRequestMessage file:ble/BleLayer.h line:111
        pybind11::class_<chip::Ble::BleTransportCapabilitiesRequestMessage,
                         std::shared_ptr<chip::Ble::BleTransportCapabilitiesRequestMessage>>
            cl(M("chip::Ble"), "BleTransportCapabilitiesRequestMessage", "");
        cl.def(pybind11::init([]() { return new chip::Ble::BleTransportCapabilitiesRequestMessage(); }));
        cl.def_readwrite("mMtu", &chip::Ble::BleTransportCapabilitiesRequestMessage::mMtu);
        cl.def_readwrite("mWindowSize", &chip::Ble::BleTransportCapabilitiesRequestMessage::mWindowSize);
        cl.def(
            "SetSupportedProtocolVersion",
            (void (chip::Ble::BleTransportCapabilitiesRequestMessage::*)(unsigned char, unsigned char)) &
                chip::Ble::BleTransportCapabilitiesRequestMessage::SetSupportedProtocolVersion,
            "Set supported version value at given index in\n  SupportedProtocolVersions. uint8_t version argument is truncated to "
            "4\n  least-significant bits. Index shall be 0 through number of\n  SupportedProtocolVersions elements - 1.\n\nC++: "
            "chip::Ble::BleTransportCapabilitiesRequestMessage::SetSupportedProtocolVersion(unsigned char, unsigned char) --> void",
            pybind11::arg("index"), pybind11::arg("version"));
        cl.def("Encode",
               (int (chip::Ble::BleTransportCapabilitiesRequestMessage::*)(const class chip::System::PacketBufferHandle &) const) &
                   chip::Ble::BleTransportCapabilitiesRequestMessage::Encode,
               "Must be able to reserve 20 byte data length in msgBuf.\n\nC++: "
               "chip::Ble::BleTransportCapabilitiesRequestMessage::Encode(const class chip::System::PacketBufferHandle &) const "
               "--> int",
               pybind11::arg("msgBuf"));
        cl.def_static(
            "Decode",
            (int (*)(const class chip::System::PacketBufferHandle &, class chip::Ble::BleTransportCapabilitiesRequestMessage &)) &
                chip::Ble::BleTransportCapabilitiesRequestMessage::Decode,
            "C++: chip::Ble::BleTransportCapabilitiesRequestMessage::Decode(const class chip::System::PacketBufferHandle &, class "
            "chip::Ble::BleTransportCapabilitiesRequestMessage &) --> int",
            pybind11::arg("msgBuf"), pybind11::arg("msg"));
    }
    { // chip::Ble::BleTransportCapabilitiesResponseMessage file:ble/BleLayer.h line:154
        pybind11::class_<chip::Ble::BleTransportCapabilitiesResponseMessage,
                         std::shared_ptr<chip::Ble::BleTransportCapabilitiesResponseMessage>>
            cl(M("chip::Ble"), "BleTransportCapabilitiesResponseMessage", "");
        cl.def(pybind11::init([]() { return new chip::Ble::BleTransportCapabilitiesResponseMessage(); }));
        cl.def_readwrite("mSelectedProtocolVersion", &chip::Ble::BleTransportCapabilitiesResponseMessage::mSelectedProtocolVersion);
        cl.def_readwrite("mFragmentSize", &chip::Ble::BleTransportCapabilitiesResponseMessage::mFragmentSize);
        cl.def_readwrite("mWindowSize", &chip::Ble::BleTransportCapabilitiesResponseMessage::mWindowSize);
        cl.def("Encode",
               (int (chip::Ble::BleTransportCapabilitiesResponseMessage::*)(const class chip::System::PacketBufferHandle &) const) &
                   chip::Ble::BleTransportCapabilitiesResponseMessage::Encode,
               "Must be able to reserve 20 byte data length in msgBuf.\n\nC++: "
               "chip::Ble::BleTransportCapabilitiesResponseMessage::Encode(const class chip::System::PacketBufferHandle &) const "
               "--> int",
               pybind11::arg("msgBuf"));
        cl.def_static(
            "Decode",
            (int (*)(const class chip::System::PacketBufferHandle &, class chip::Ble::BleTransportCapabilitiesResponseMessage &)) &
                chip::Ble::BleTransportCapabilitiesResponseMessage::Decode,
            "C++: chip::Ble::BleTransportCapabilitiesResponseMessage::Decode(const class chip::System::PacketBufferHandle &, class "
            "chip::Ble::BleTransportCapabilitiesResponseMessage &) --> int",
            pybind11::arg("msgBuf"), pybind11::arg("msg"));
    }
}
