import CHIPDeviceController
import time

import logging
logger = logging.getLogger("ChipBLEMgr")
logger.setLevel(logging.DEBUG)

descriptor = 0xF01
setup_code = 20202020
node_id = 1

controller = CHIPDeviceController.CHIPDeviceControllerPyBind()
controller.PairBLE(descriptor, setup_code, node_id)
# unpair_result = controller.UnpairDevice(node_id)
# print('Unpair Result: {}'.format(unpair_result))
# time.sleep(35)
# stop_pairing_result = controller.StopPairingBLE(node_id)
# print("Stop Pairing Result: {}".format(stop_pairing_result))
# close_connection_result = controller.CloseBleConnection()
# print("Shudown Result: {}".format(close_connection_result))
# sutdown_result = controller.Shutdown()
# print("Shudown Result: {}".format(sutdown_result))