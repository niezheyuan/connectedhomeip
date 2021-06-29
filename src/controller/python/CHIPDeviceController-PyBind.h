/*
 *
 *    Copyright (c) 2021 Project CHIP Authors
 *    All rights reserved.
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */
#pragma once
#include "PyDelegateWrappers.h"
#include <controller/CHIPDevice.h>
#include <controller/CHIPDeviceController.h>
#include <core/CHIPCore.h>
#include <setup_payload/QRCodeSetupPayloadParser.h>

namespace chip {
namespace Controller {

class CHIPDeviceControllerPyBind
{
public:
    CHIPDeviceControllerPyBind();
    ~CHIPDeviceControllerPyBind() {}
    CHIP_ERROR Init();
    CHIP_ERROR PairBLE(uint16_t discriminator, uint32_t setupPINCode, NodeId nodeid);
    CHIP_ERROR StopPairingBLE(NodeId nodeid);
    CHIP_ERROR CloseBleConnection();
    CHIP_ERROR Shutdown();
    CHIP_ERROR UnpairDevice(NodeId remoteDeviceId);
    CHIP_ERROR DiscoverAllCommissioning();
    void SetDeviceAddressUpdateDelegate(chip::Controller::DeviceAddressUpdateDelegate * sdelegate);
    void SetDevicePairingDelegate(chip::Controller::DevicePairingDelegate * delegate);

private:
    chip::Controller::DeviceCommissioner * deviceCommissioner;
    NodeId localDeviceId;
    NodeId kDefaultCtlrDeviceId = kTestControllerNodeId;
    chip::Controller::DeviceAddressUpdateDelegate * sDeviceAddressUpdateDelegate;
    chip::Controller::DevicePairingDelegate * sPairingDelegate;
    chip::Controller::CommissionerInitParams initParams;
};

} // Namespace Controller
} // Namespace chip
