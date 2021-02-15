#pragma once

#define DEFAULT 0

//Boards
#define TEENSY_DEFAULT 2
#define UNO_DEFAULT 3

// #define BOARD UNO_DEFAULT

//Platforms
#define DEFAULT_PLATFORM 2
#define VOLVO_P1_1 3

#define PLATFORM DEFAULT_PLATFORM

//Can Bus drivers
#define TEENSY_CAN 2
#define MCP2515_CAN 3

#ifndef PLATFORM
    #define PLATFORM DEFAULT_PLATFORM
#endif
#ifndef BOARD
    #define BOARD DEFAULT
#endif

#if BOARD == TEENSY_DEFAULT
#define CANBUS TEENSY_CAN
#elif BOARD == UNO_DEFAULT
#define CANBUS MCP2515_CAN
#define CAN0_PIN 8
#define CAN1_PIN 9
#define CAN2_PIN 10
#endif
