#include <SPI.h>
#include <SD.h>

char batteryState = 100;
int ticRate = 10;

int a0 = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  batteryState = lowOnBattery();
  if (batteryState <= 14) {
    waitUntilSurfaced();
    eject();
  } else {
    if (surfaced()) {
      collectGPS();
      sendGPS();
    }
    collectSensorData();
    delay(ticRate);
    //blink(100);
  }
}


void blink(int d) {
  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(d);              // wait for a second
  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);              // wait for a second
}

