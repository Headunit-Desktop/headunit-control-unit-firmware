#pragma once

#include "../CanBus.h"
#if CANBUS == TEENSY_CAN
#include <FlexCAN_T4.h>

class CanBus : public CanBusAbstract
{
public:
    CanBus(CanMessageCallback callback);
    void setBaudRate(BusNumber bus, uint32_t speed) override;
    void sendFrame(BusNumber bus, CanMessage &frame) override;
    void loop() override;
private:
    FlexCAN_T4<CAN1, RX_SIZE_256, TX_SIZE_16> can0;
    FlexCAN_T4<CAN2, RX_SIZE_256, TX_SIZE_16> can1;
    FlexCAN_T4<CAN3, RX_SIZE_256, TX_SIZE_16> can2;
    bool m_enabled = false;
};
#endif