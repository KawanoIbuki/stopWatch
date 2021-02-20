#include <M5Stack.h>
int secondCount =  minCount =  startCheck =  minRap =  secondRap = 0;

//sd setting
unsigned int auiSize = 0;
unsigned int auiCnt = 0;

void writeData(minRap, secondRap) {
  file = SD.open(fname, FILE_APPEND);

  file.println(timeStr + "," + minRap + "," + secondRap);

  file.close
}

void setup() {
  M5.begin();

  M5.Lcd.fillScreen(BLACK);
  M5.Lcd.setTextColor(WHITE);
  M5.Lcd.setTextSize(3);
}

void loop() {
  M5.update();

  if (M5.BtnA.wasPressed() && !Raptimer) {
    Raptimer = true;
    Speedmetor = false;
    M5.Lcd.fillScreen(BLACK);
  }

  if (M5.BtnC.wasPressed() && !Speedmetor) {
    Raptimer = false;
    Speedmetor = true;
    M5.Lcd.fillScreen(BLACK);
  }

  if (Speedmetor) M5.Lcd.printf("Speedmetor");

  if (Raptimer) {
    M5.Lcd.setCursor(10, 10);
    M5.Lcd.printf("%d:%d", minCount, secondCount);

    M5.update();

    if (M5.BtnA.wasPressed() && Raptimer) {
      while (1) {
        M5.Lcd.setCursor(10, 10);
        M5.Lcd.printf("%d:%d", minCount, secondCount);
        secondCount++;

        if (secondCount == 60) {
          secondCount = 0;
          minCount++;
        } //end of if

        M5.update();

        if (M5.BtnB.wasPressed()) {
          minRap = minCount;
          secondRap = secondCount;
        } //end of if

        M5.Lcd.setCursor(30, 30);
        M5.Lcd.printf("%d:%d", minRap, secondRap);
        M5.Lcd.fillScreen(BLACK);

        writeData(minRap, secondRap);

        if (M5.BtnC.wasPressed() && !Speedmetor) {
          Raptimer = false;
          Speedmetor = true;
          M5.Lcd.fillScreen(BLACK);
        } //end of if (M5.BtnA.wasPressed() && Raptimer)

      } //end of while

    } //end of if

  } //end of if

} //end of loop()
