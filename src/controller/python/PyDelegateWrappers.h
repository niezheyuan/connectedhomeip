#pragma once
#include "pybind11/pybind11.h"
#include <controller/DeviceAddressUpdateDelegate.h>
#include <controller/CHIPDeviceController.h>

class PyDeviceAddressUpdateDelegate : public chip::Controller::DeviceAddressUpdateDelegate {
public:
    /* Inherit the constructors */
    using chip::Controller::DeviceAddressUpdateDelegate::DeviceAddressUpdateDelegate;

    /* Trampoline (need one for each virtual function) */
    void OnAddressUpdateComplete(chip::NodeId nodeId, CHIP_ERROR erros) override {
        PYBIND11_OVERRIDE_PURE(
            void, /* Return type */
            DeviceAddressUpdateDelegate,      /* Parent class */
            OnAddressUpdateComplete,          /* Name of function in C++ (must match Python name) */
            (chip::NodeId *) nodeId, (CHIP_ERROR) erros     /* Argument(s) */
        );
    }
};

class PyDevicePairingDelegate : public chip::Controller::DevicePairingDelegate {
public:
    /* Inherit the constructors */
    using chip::Controller::DevicePairingDelegate::DevicePairingDelegate;

    /* Trampoline (need one for each virtual function) */
    void OnPairingComplete(CHIP_ERROR error) override {
        PYBIND11_OVERRIDE(
            void, /* Return type */
            DevicePairingDelegate,      /* Parent class */
            OnPairingComplete,          /* Name of function in C++ (must match Python name) */
            (CHIP_ERROR) error     /* Argument(s) */
        );
    }
    /* Trampoline (need one for each virtual function) */
    void OnStatusUpdate(DevicePairingDelegate::Status status) override {
        PYBIND11_OVERRIDE(
            void, /* Return type */
            DevicePairingDelegate,      /* Parent class */
            OnStatusUpdate,          /* Name of function in C++ (must match Python name) */
            (DevicePairingDelegate::Status) status    /* Argument(s) */
        );
    }
    /* Trampoline (need one for each virtual function) */
    void OnPairingDeleted(CHIP_ERROR error) override {
        PYBIND11_OVERRIDE(
            void, /* Return type */
            DevicePairingDelegate,      /* Parent class */
            OnPairingDeleted,          /* Name of function in C++ (must match Python name) */
            (CHIP_ERROR) error    /* Argument(s) */
        );
    }
};
