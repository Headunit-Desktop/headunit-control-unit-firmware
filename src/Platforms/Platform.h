#ifndef Platform_H
#define Platform_H

#include "../CanBus/CanBusDriver.h"
#include "../HUDSerial/HUDSerial.h"
#include "../config.h"
#include "../common.h"

typedef struct PlatformSettings {
    struct {
        bool enabled = false;
        uint32_t speed = 0; 
    } can0;
    struct {
        bool enabled = false;
        uint32_t speed = 0; 
    } can1;
    struct {
        bool enabled = false;
        uint32_t speed = 0; 
    } can2;
    struct {
        bool enabled = false;
        uint32_t speed = 0; 
    } lin0;
    struct {
        bool enabled = false;
        uint32_t speed = 0; 
    } lin1;

} PlatformSettings;

class PlatformAbstract
{
public:
    PlatformAbstract(HUDSerial *hudSerial) : m_hudSerial(hudSerial),  m_settings() {}
    virtual void loop();
    virtual void setup();
    virtual void receiveBusMessage(BusNumber bus, CanMessage message);
    virtual void receiveClimateControlCommand(ClimateControlCommandFrame climateControlFrame) {}
    virtual void receiveCustomCommand(CustomCommandFrame commandFrame) {}
    virtual void receiveButtonInputCommand(Keys key) {}
    PlatformSettings getSettings(){
        return m_settings;
    }
protected:
    HUDSerial *m_hudSerial;
    PlatformSettings m_settings;
};

#endif