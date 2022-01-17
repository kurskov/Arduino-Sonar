/*
    See Sonar.h for all information.

    Author: Dmitrii Kurskov (dmitrii@kurskov.ru)
*/

#include "Sonar.h"


// Constructor

Sonar::Sonar(uint8_t trigger_pin, uint8_t echo_pin , long max_time) {
    // set basic parameter
    setTriggerPin(trigger_pin);
    setEchoPin(echo_pin);
    setMaxTime(max_time);
}

// Get functions

long getTime(uint8_t iterations) {
    unsigned long time = 0;
    unsigned long single_time = 0;
    uint8_t errors = 0;
    
    if ( !iterations ) { return 0; }

    // main cycle
    for (int i=0; i<iterations; i++) {
        // for one signal pin
        if ( _onePin ) {
            pinMode(_triggerPin, OUTPUT);
        }

        // initialise of oscillator
        digitalWrite(_triggerPin, LOW);
        delayMicroseconds(2);
        digitalWrite(_triggerPin, HIGH);
        delayMicroseconds(10);
        digitalWrite(_triggerPin, LOW);
        
        // for one signal pin
        if ( _onePin ) {
            pinMode(_triggerPin, INPUT);
        }
        
        single_time = pulseIn(_echoPin, HIGH, _maxTime);

        if ( single_time )  {
            time =+ single_time;
        } else {
            errors++;
        }

        delayMicroseconds(DELAY_BETWEEN_MEASURMENT);
    }

    // if all measurements are errors
    if ( iterations == errors ) { return 0; }

    // value (or middle value) in microseconds
    return (long)(time / (iterations - errors)); 
}

float getDistance(uint8_t iterations,bool units) {
    float distance = getTime(iterations) * SOUND_SPEED / 2000;
    
    if ( !units ) { return distance / 2.54; }

    return distance;
}

// Set functions

void Sonar::setTriggerPin(uint8_t trigger_pin) {
    _trigger_pin = trigger_pin;
    pinMode(_trigger_pin, OUTPUT);
}

void Sonar::setEchoPin(uint8_t echo_pin) {
    if (echo_pin && (echo_pin != _trigger_pin)) {
        _echo_pin = echo_pin;
    } else {
        _echo_pin = _trigger_pin;
        _one_pin = true;
    }
    pinMode(_echo_pin, INPUT);
}

void Sonar::setMaxTime(long max_time) {
    _max_time = max_time;
}

void Sonar::setMaxDistance(int max_distance, bool units) {
    _max_time = (long)(max_distance / SOUND_SPEED) * 2000;
    if (!units) {
        _max_time = _max_time * 2.54;
    }_
}