#include <Arduino.h>

const int analogInPin = A0;  // Analog input pin that the potentiometer is attached to


int sensorValue = 0;        // value read from the pot
int sensorValue_b = 0;
int sensor = 0;
unsigned long previousMillis = 0;
unsigned long previousMillis2 = 0;
void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
}

void loop() {


  unsigned long currentMillis = millis();
  // read the analog in value:

  // print the results to the serial monitor:
  if (currentMillis - previousMillis >= 10) {
    // save the last time you blinked the LED
    previousMillis2 = currentMillis;
      sensorValue = abs(analogRead(analogInPin)-500);
      if(sensorValue>sensorValue_b){
        sensor = sensorValue;
        sensorValue_b = sensorValue;
      }
  }
  if (currentMillis - previousMillis >= 1000) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;
  Serial.print("sensor = ");
  Serial.println((13.619551*log(sensor))+ 15.056);
  sensorValue_b = 0;
}
  // wait 2 milliseconds before the next loop
  // for the analog-to-digital converter to settle
  // after the last reading:

}
