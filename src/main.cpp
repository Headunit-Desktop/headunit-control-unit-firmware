#include "CanBus/CanBusDriver.h"
#include "HAL/hal.h"
#include "HUDSerial/HUDSerial.h"
#include "Platforms/Platforms.h"
#include "common.h"
#include "config.h"

void canBusReceiveBusMessage(BusNumber bus, CanMessage message) { platform.receiveBusMessage(bus, message); }

class Callbacks : public PlatformCallbacks {
    void ClimateControlCallback(ClimateControlCommandFrame controlFrame) override {
        platform.receiveClimateControlCommand(controlFrame);
    }

    void CustomCommandCallback(CustomCommandFrame commandFrame) override {
        platform.receiveCustomCommand(commandFrame);
    }
    void ButtonInputCommandCallback(Keys key) { platform.receiveButtonInputCommand(key); }

    void SendMessageCallback(uint8_t sendByte) {
        SERIAL_PRIMARY.print((char)sendByte);
    }
    void PrintString(char *message) {

    }
};

HUDSerial hudSerial;
CanBus canBus(canBusReceiveBusMessage);
Platform platform(&hudSerial);
Callbacks callbacks;

void setup() {
    SERIAL_PRIMARY.begin(1000000);
#ifdef SERIAL_DEBUG
    SERIAL_DEBUG.begin(1000000);
#endif
    HAL::init();
    hudSerial.setCallbacks(&callbacks);
}

void loop() {
    if (SERIAL_PRIMARY.available() > 0) {
        char received = SERIAL_PRIMARY.read();
        hudSerial.receiveByte(received);
    }
    canBus.loop();
    HAL::loop();
    if (HAL::TimerExpired) {
        platform.loop();
        hudSerial.loop();
        HAL::TimerExpired = false;
    }
}