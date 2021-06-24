from PyCHIPController import CHIPController
import time

import logging
logger = logging.getLogger("ChipBLEMgr")
logger.setLevel(logging.DEBUG)

setup_payload = CHIPController.SetupPayload()
qr_code_parser = CHIPController.QRCodeSetupPayloadParser("VP:vendorpayload%MT:W0GU2OTB00KA0648G00")
payload = qr_code_parser.populatePayload(setup_payload)
print("Version: {}".format(setup_payload.version))
print("Vendor ID: {}".format(setup_payload.vendorID))
print("Product ID: {}".format(setup_payload.productID))
print("Commissioning Flow: {}".format(setup_payload.commissioningFlow))
print("Rendezvous Information Flag: {}".format(setup_payload.rendezvousInformation.Raw()))
print("Discriminator: {}".format(setup_payload.discriminator))
print("Setup Pin Code: {}".format(setup_payload.setUpPINCode))
print(setup_payload.getAllOptionalVendorData())



descriptor = 0xF00
setup_code = 20202021
node_id = 1
class PyDeviceAddressUpdateDelegate(CHIPController.PyDeviceAddressUpdateDelegate):
    def OnAddressUpdateComplete(nodeId, error):
        print('Node ID: {}'.format(nodeId))
        print('Error: {}'.format(error))

class PyDevicePairingDelegate(CHIPController.PyDevicePairingDelegate):
    def OnPairingComplete(self, error):
        print("OnPairingComplete Error: {}".format(error))

    def OnStatusUpdate(self, status):
        print("OnStatusUpdate Status: {}".format(status))

    def OnPairingDeleted(self, error):
        print("OnPairingDeleted Error: {}".format(error))


# controller = CHIPController.CHIPDeviceControllerPyBind()
# device_address_delegate = PyDeviceAddressUpdateDelegate()
# device_pairing_delegate = PyDevicePairingDelegate()
# controller.SetDeviceAddressUpdateDelegate(device_address_delegate)
# controller.SetDevicePairingDelegate(device_pairing_delegate)
# controller.Init()
# controller.PairBLE(descriptor, setup_code, node_id)


# unpair_result = controller.UnpairDevice(node_id)
# print('Unpair Result: {}'.format(unpair_result))
# time.sleep(35)
# stop_pairing_result = controller.StopPairingBLE(node_id)
# print("Stop Pairing Result: {}".format(stop_pairing_result))
# close_connection_result = controller.CloseBleConnection()
# print("Shudown Result: {}".format(close_connection_result))
# sutdown_result = controller.Shutdown()
# print("Shudown Result: {}".format(sutdown_result))