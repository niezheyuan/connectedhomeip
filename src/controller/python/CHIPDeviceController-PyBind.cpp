#include <controller/python/CHIPDeviceController-PyBind.h>
#include <errno.h>
#include <fcntl.h>
#include <memory>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

#include <system/SystemError.h>
#include <system/SystemLayer.h>

#include <inttypes.h>
#include <net/if.h>

#include "ChipDeviceController-StorageDelegate.h"


#include <controller/python/Delegate.h>

#include <app/CommandSender.h>
#include <app/InteractionModelEngine.h>
#include <controller/ExampleOperationalCredentialsIssuer.h>
#include <inet/IPAddress.h>
#include <mdns/Resolver.h>
#include <support/BytesToHex.h>
#include <support/CHIPMem.h>
#include <support/CodeUtils.h>
#include <support/DLLUtil.h>
#include <support/logging/CHIPLogging.h>


using namespace chip;
using namespace chip::Ble;
using namespace chip::Controller;

namespace {
chip::Controller::PythonPersistentStorageDelegate sStorageDelegate;
chip::Controller::ExampleOperationalCredentialsIssuer sOperationalCredentialsIssuer;
} // namespace

namespace chip {
namespace Controller {

CHIPDeviceControllerPyBind::CHIPDeviceControllerPyBind()
{
    CHIP_ERROR err = CHIP_NO_ERROR;
    err = chip::Platform::MemoryInit();
    SuccessOrExit(err);

    deviceCommissioner = new chip::Controller::DeviceCommissioner();
    VerifyOrExit(deviceCommissioner != NULL, err = CHIP_ERROR_NO_MEMORY);

    if (localDeviceId == chip::kUndefinedNodeId)
    {
        localDeviceId = kDefaultCtlrDeviceId;
    }

exit:
    return;
}

CHIP_ERROR CHIPDeviceControllerPyBind::Init(){
    CHIP_ERROR err = CHIP_NO_ERROR;
    SuccessOrExit(err = sOperationalCredentialsIssuer.Initialize(sStorageDelegate));
    initParams.storageDelegate                = &sStorageDelegate;
    initParams.mDeviceAddressUpdateDelegate   = sDeviceAddressUpdateDelegate;
    initParams.pairingDelegate                = sPairingDelegate;
    initParams.operationalCredentialsDelegate = &sOperationalCredentialsIssuer;
    initParams.imDelegate                     = &PythonInteractionModelDelegate::Instance();

    SuccessOrExit(err = (deviceCommissioner)->Init(localDeviceId, initParams));
    SuccessOrExit(err = (deviceCommissioner)->ServiceEvents());
exit:
    return err;
}
// pychip_DeviceController_ConnectBLE
CHIP_ERROR CHIPDeviceControllerPyBind::PairBLE(uint16_t discriminator,
                                              uint32_t setupPINCode, NodeId nodeid){
    return deviceCommissioner->PairDevice(nodeid,
                               chip::RendezvousParameters()
                                   .SetPeerAddress(Transport::PeerAddress(Transport::Type::kBle))
                                   .SetSetupPINCode(setupPINCode)
                                   .SetDiscriminator(discriminator));
}

CHIP_ERROR CHIPDeviceControllerPyBind::StopPairingBLE(NodeId nodeid){
    return deviceCommissioner->StopPairing(nodeid);
}

CHIP_ERROR CHIPDeviceControllerPyBind::UnpairDevice(NodeId remoteDeviceId){
    return deviceCommissioner->UnpairDevice(remoteDeviceId);
}

CHIP_ERROR CHIPDeviceControllerPyBind::CloseBleConnection(){
    return deviceCommissioner->CloseBleConnection();
}

CHIP_ERROR CHIPDeviceControllerPyBind::Shutdown(){
    return deviceCommissioner->Shutdown();
}
CHIP_ERROR CHIPDeviceControllerPyBind::DiscoverAllCommissioning(){
    return deviceCommissioner->DiscoverAllCommissioning();
}

void CHIPDeviceControllerPyBind::SetDeviceAddressUpdateDelegate(chip::Controller::DeviceAddressUpdateDelegate *delegate){
    sDeviceAddressUpdateDelegate = delegate;
}

void CHIPDeviceControllerPyBind::SetDevicePairingDelegate(chip::Controller::DevicePairingDelegate *delegate){
    sPairingDelegate = delegate;
}

}//Controller
}//chip
