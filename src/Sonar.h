/*
    Sonar

    The library for using ultra sound module (SR04) to Arduino.

    Author: Dmitrii Kurskov (dmitrii@kurskov.ru)
    GitHub: https://github.com/kurskov/Arduino-Sonar
    
    *** Underconstruction ***
*/

// Include guard
#ifndef _H_7F8B8320_60C3_4750_ADDF_B3EB6F16676C
#define _H_7F8B8320_60C3_4750_ADDF_B3EB6F16676C

#if defined(ARDUINO) && ARDUINO >= 100
    #include <Arduino.h>
#else
    #include <WProgram.h>
#endif

#if defined(__AVR__)
    #include <avr/io.h>
    #include <avr/interrupt.h>
#endif

//Default settings

// Units 
#define UNIT_CM true    // centimeters
#define UNIT_IN false   // inches

class Sonar {
    public:
        Sonar(int triggerPin, int echoPin = 0, int maxTime = 5000);
        int getTime();
        int getDistance(bool units = UNIT_CM);
        void setTriggerPin(int triggerPin);
        void setEchoPin(int echoPin);
        void setMaxTime(int maxTime);
        void setMaxDistance(int maxDistance, bool units = UNIT_CM);
    private:
        int _triggerPin;
        int _echoPin;
        int _maxTime;
};

#endif _H_7F8B8320_60C3_4750_ADDF_B3EB6F16676C