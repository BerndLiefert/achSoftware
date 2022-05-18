#include "Arduino.h"
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"

SoftwareSerial mySoftwareSerial(10, 11); // RX, TX
DFRobotDFPlayerMini myDFPlayer;

#define BUSY 8

#define STBY 3
#define IN1 4
#define IN2 5

void setup()
{
  mySoftwareSerial.begin(9600);

  pinMode(BUSY, INPUT);
  pinMode(STBY, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  if (!myDFPlayer.begin(mySoftwareSerial)) {  //Use softwareSerial to communicate with mp3.
    while (true) {
      delay(0); // Code to compatible with ESP8266 watch dog.
    }
  }

  myDFPlayer.volume(30);
}

void loop()
{
  if (digitalRead(BUSY) == HIGH) {
    //Shut up, Furbs! At least for 3 seconds.
    digitalWrite(STBY, LOW);
    delay(3000);
    myDFPlayer.next();
  }
  digitalWrite(STBY, HIGH);
  delay(1000);
}