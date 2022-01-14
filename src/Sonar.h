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

//Default settings

// Units 
#define UNIT_CM true    // centimeters
#define UNIT_IN false   // inches

// Sensor parameters
#define MAX_SENSOR_DISTANCE_CM 400 // in centimeters
#define MAX_SENSOR_TIME_US 38000 //  in us (for HC-SR04 default is 38 ms)
#define DELAY_BETWEEN_MEASURMENT 50000 // in us (for HC-SR04 default is 50 ms)

class Sonar {
    public:
        Sonar(uint8_t triggerPin, uint8_t echoPin = 0, long maxTime = 38000);
        long getTime();
        int getDistance(bool units = UNIT_CM);
        void setTriggerPin(uint8_t triggerPin);
        void setEchoPin(uint8_t echoPin);
        void setMaxTime(long maxTime);
        void setMaxDistance(int maxDistance = MAX_SENSOR_DISTANCE_CM, bool units = UNIT_CM);
    private:
        uint8_t _triggerPin;
        uint8_t _echoPin;
        long _maxTime;
        bool onePin = false;
};

#endif _H_7F8B8320_60C3_4750_ADDF_B3EB6F16676C