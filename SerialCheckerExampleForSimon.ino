#include "SerialChecker.h"
// Put the SerialChecker.h and SerialChecker.cpp in the same folder as this sketch.

SerialChecker sc;

const uint8_t ID = 1;

void setup(){
    sc.init(); //defaults to 250000 baud.
}

void loop(){
    checkSerial();
}

void checkSerial(){
    if(sc.check()){ // returns an uint8_t giving the number of chars in the received message
        if(sc.contains(ID)){
            if(sc.contains("S", 1)){ // looks for S at index 1.
                int16_t speed = sc.toInt16(2); // looks for an integer starting at index 2
            }
            else if(sc.contains("E", 1)){
                // Emergency stop or something.
            }
            else if(sc.contains("maxS", 1)){
                float maxSpeed = sc.toFloat(5);
            }
        }
    }
}