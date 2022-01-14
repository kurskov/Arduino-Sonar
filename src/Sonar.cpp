/*
    See Sonar.h for all information.

    Author: Dmitrii Kurskov (dmitrii@kurskov.ru)
*/

#include "Sonar.h"


// Constructor

Sonar::Sonar(uint8_t triggerPin, uint8_t echoPin , long maxTime) {
    // set basic parameter
    setTriggerPin(triggerPin);
    setEchoPin(echoPin);
    setMaxTime(maxTime);

    pinMode(_triggerPin, OUTPUT);
    if (!_onePin) {
        pinMode(_echoPin, INPUT);
    }
}


// Set functions

void Sonar::setTriggerPin(uint8_t triggerPin) {
    _triggerPin = triggerPin;
}

void Sonar::setEchoPin(uint8_t echoPin) {
    if (echoPin) {
        _echoPin = echoPin;
    } else {
        _echoPin = _triggerPin;
        _onePin = true;
    }
}

void Sonar::setMaxTime(long maxTime) {
    _maxTime = maxTime;
}

void Sonar::setMaxDistance(int maxDistance, bool units) {
    _maxTime = maxDistance * 29.1 * 2;
    if (!units) {
        _maxTime = _maxTime * 2.54;
    }_
}