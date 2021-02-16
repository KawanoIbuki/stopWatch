#include <M5Stack.h>
int counter = 35900;
//counter[0]=>ns, [1]=>ms, [2]=>s, [3]=>,min
void stopWatch() {
  M5.Lcd.fillScreen(BLACK);
  while (1) {
    M5.Lcd.setCursor(10, 10);
    M5.Lcd.printf("%8d", counter);
    M5.Lcd.setCursor(10, 70);
    M5.Lcd.printf("%2d:%2d.%1d", (counter / 600) % 3600, (counter / 10) % 60, counter % 10);
    counter++;

    M5.Lcd.setCursor(90, 140);
    M5.Lcd.printf("STOP");
    M5.Lcd.fillScreen(BLACK);
    //delay(65);
    M5.update();
    if (M5.BtnB.wasPressed()) {
      counter = 0;
      break;
    }
  }
}
void setup() {
  // put your setup code here, to run once:
  M5.begin();

  M5.Lcd.fillScreen(BLACK);
  M5.Lcd.setTextColor(WHITE);
  M5.Lcd.setTextSize(5);
  M5.Lcd.setCursor(10, 10);
}

void loop() {
  // put your main code here, to run repeatedly:
  M5.update();
  M5.Lcd.setCursor(10, 10);
  M5.Lcd.printf("Please press BtnA");
  //stop watch start
  if (M5.BtnA.isPressed()) {
    stopWatch();
  }
}
