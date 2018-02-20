

#pragma once
#include <Arduino.h>

/**
 */
class arduinoSerial
{
public:
    static void run();
    static bool hasString(char **str);
    static bool sendString(char *str);
};

