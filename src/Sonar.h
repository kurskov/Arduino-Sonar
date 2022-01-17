/*
    Sonar

    The library for using ultra sound module (SR04) to Arduino.

    Author: Dmitrii Kurskov (dmitrii@kurskov.ru)
    GitHub: https://github.com/kurskov/Arduino-Sonar
    
    *** Underconstruction (for tests) ***
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
#define UNIT_CM true        // centimeters
#define UNIT_IN false       // inches
#define SOUND_SPEED 34.33   // m/s

// Sensor parameters
#define MAX_SENSOR_DISTANCE_CM 400 // in centimeters
#define MAX_SENSOR_TIME_US 38000 //  in us (for HC-SR04 default is 38 ms)
#define DELAY_BETWEEN_MEASURMENT 50000 // in us (for HC-SR04 default is 50 ms)

class Sonar {
    public:
        Sonar(uint8_t trigger_pin, uint8_t echo_pin = 0, long max_time = MAX_SENSOR_TIME_US);
        long getTime(uint8_t iterations = 1);
        float getDistance(uint8_t iterations = 1,bool units = UNIT_CM);
        void setTriggerPin(uint8_t trigger_pin);
        void setEchoPin(uint8_t echo_pin);
        void setMaxTime(long max_time);
        void setMaxDistance(int max_distance = MAX_SENSOR_DISTANCE_CM, bool units = UNIT_CM);
    private:
        uint8_t _trigger_pin;
        uint8_t _echo_pin;
        long _max_time;
        bool _one_pin = false;
};

#endif _H_7F8B8320_60C3_4750_ADDF_B3EB6F16676C