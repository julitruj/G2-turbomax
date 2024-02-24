#include <Arduino.h>
#include <constants.h>

#include <Arduino.h>
#include "sensor/sensor.h"
#include "constants.h"

AnalogSensor analogSensor = AnalogSensor(
  Constants::analogSensorPin, 1
);

long sample_timer = millis();
long execution_timer = millis() + 300;

void setup() {
  Serial.begin(9600);
}

void loop() {
  if (millis() - sample_timer > 1000){
    analogSensor.call();
    sample_timer = millis();
  }
  if (millis() - execution_timer > 1000){
    if(analogSensor.hasChange()){
      Serial.print("Analog Sensor: ");
      Serial.println(analogSensor.getRead());
    }
  }
}
