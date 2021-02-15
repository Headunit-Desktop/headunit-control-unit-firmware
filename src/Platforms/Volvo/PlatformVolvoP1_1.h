#pragma once

#include "../Platform.h"
#if PLATFORM == VOLVO_P1_1

class Platform : public PlatformAbstract {
   public:
    Platform(HUDSerial *hudSerial);
    void loop() override;
    void setup() override;
    void receiveBusMessage(BusNumber bus, CanMessage message) override;
    void receiveCustomCommand(CustomCommandFrame commandFrame) override;

   private:
    uint16_t timerCount;
    uint8_t m_settingsTimerCount;
    ClimateControlCommandFrame climateControl;
    CustomCommandFrame m_carSettings;
    CustomCommandFrame m_carSettingsReceived;
    bool m_ccLoaded;
    bool m_carSettingsLoaded;
    bool m_ccSettingsChanged;
    bool m_carSettingsChanged;
    void sendCarSettings();
};

#endif