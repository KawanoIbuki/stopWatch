#include <M5Stack.h>
#define BUTTONA 39
#define BUTTONB 38
#define BUTTONC 37
#define BUTTON_ON 0
#define BUTTON_OFF 1
int secondCount = 0, minCount = 0, startCheck = 0, minRap = 0, secondRap = 0;

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
  if (M5.BtnA.wasPressed()) {
    while (1) {
      M5.Lcd.setCursor(10, 10);
      M5.Lcd.printf("%d:%d", minCount, secondCount);
      //int %d float %f
      secondCount++;
      if (secondCount == 60) {
        secondCount = 0;
        minCount++;
      }
      M5.update();
      if (M5.BtnB.wasPressed()) {

        minRap = minCount;
        secondRap = secondCount;

      }
      M5.Lcd.setCursor(30, 30);
      M5.Lcd.printf("%d:%d", minRap, secondRap);
      //delay(1000);
      M5.Lcd.fillScreen(BLACK);
    }
  }
}
