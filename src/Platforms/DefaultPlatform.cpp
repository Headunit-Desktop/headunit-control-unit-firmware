#include "DefaultPlatform.h"

#if PLATFORM == DEFAULT_PLATFORM

Platform::Platform(HUDSerial *hudSerial) : PlatformAbstract(hudSerial),
    m_climateControlFrame(),
    m_customCommandControlFrame() {
}
void Platform::loop(){
    
}

void Platform::setup(){
    
}

void Platform::receiveBusMessage(BusNumber bus, CanMessage message){
    
}


void Platform::receiveCustomCommand(CustomCommandFrame commandFrame){
    memcpy(&m_customCommandControlFrame, &commandFrame, sizeof(CustomCommandFrame));

    m_hudSerial->sendCustomCommand(m_customCommandControlFrame);    
}
void Platform::receiveClimateControlCommand(ClimateControlCommandFrame climateControlFrame){
    
    memcpy(&m_climateControlFrame, &climateControlFrame, sizeof(ClimateControlCommandFrame));
    
    m_hudSerial->sendClimateControlCommand(m_climateControlFrame);
}
#endif
