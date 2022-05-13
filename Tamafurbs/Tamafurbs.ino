#include <LCD5110_Graph.h>

LCD5110 myGLCD(13, 12, 11, 9, 10); // LCD5110(SCK, MOSI, DC, RST, CS);

extern uint8_t SmallFont[];

extern uint8_t sleep1[];
extern uint8_t sleep2[];

void setup()
{
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  Serial.begin(9600);


  /* Init LCD5110_Graph library */
  myGLCD.InitLCD();
  myGLCD.setFont(SmallFont);
  randomSeed(analogRead(0));
}

void loop()
{

  myGLCD.drawBitmap(0, 0, sleep1, 84, 48);
  myGLCD.update();
  delay(500);
  myGLCD.clrScr();
  myGLCD.drawBitmap(0, 0, sleep2, 84, 48);
  myGLCD.update();
  delay(500);

  if (digitalRead(5) == LOW) {
    Serial.println("Button 5 is pressed");
  }

  if (digitalRead(6) == LOW) {
    Serial.println("Button 6 is pressed");
  }

  if (digitalRead(7) == LOW) {
    Serial.println("Button 7 is pressed");
  }
}
