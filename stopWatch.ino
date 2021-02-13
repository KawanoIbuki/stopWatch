#include <M5Stack.h>
#define BUTTONA 39
#define BUTTONB 38
#define BUTTONC 37
#define BUTTON_ON 0
#define BUTTON_OFF 1
int Count = 0,startCheck = 0;

void setup() {
  // put your setup code here, to run once:
  M5.begin();
  //GPIO setting
  //Button A = GPIO 39
  //Button B = GPIO 38
  //Button C = GPIO 37
  pinMode(BUTTONA, INPUT);
  pinMode(BUTTONB, INPUT);
  pinMode(BUTTONC, INPUT);
  M5.Lcd.fillScreen(BLACK);
  M5.Lcd.setTextColor(WHITE);
  M5.Lcd.setTextSize(3);
}

void loop() {
  // put your main code here, to run repeatedly:
      M5.update();
      if (M5.BtnA.wasPressed())
  {
    startCheck = 1;
  }
  if(startCheck == 1)
  {
    M5.Lcd.printf("%d",Count);
    //int %d float %f
    Count++;
    delay(1000);
    M5.Lcd.fillScreen(BLACK);
  }
}
