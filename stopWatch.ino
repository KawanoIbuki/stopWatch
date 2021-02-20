#include <M5Stack.h>
#include <Ticker.h>

Ticker tickerTime;

//timer
unsigned int msCount = 0;
unsigned int secondCount = 0;
unsigned int minCount = 0;
unsigned int startCheck = 0;
unsigned int minRap = 0;
unsigned int secondRap = 0;
unsigned int msRap = 0;
unsigned int rapCount = 0;

//sd setting
unsigned int auiSize = 0;
unsigned int auiCnt = 0;

File file;
const char* fname = "/rapTime_log.csv";

void writeData(int rapCount, int minRap, int secondRap, int msRap) {
  file = SD.open(fname, FILE_APPEND);
  file.println(String(rapCount) + "," + String(minRap) + "," + String(secondRap) + "," + String(msRap));
  file.close();
}

void countUp() {
  msCount++;
}

void rapTime() {
  rapCount++;

  minRap = (msCount / 60000) % 3600;
  secondRap = (msCount / 1000) % 60;
  msRap = msCount & 1000;

  //write data to csv file
  writeData(rapCount, minRap, secondRap, msRap);
}
void Timer() {
  M5.Lcd.fillScreen(BLACK);
  tickerTime.attach_ms(1, countUp);

  //timer mode
  while (1) {
    //init
    M5.update();
    M5.Lcd.fillScreen(BLACK);

    //save rap time
    M5.Lcd.setCursor(140, 200);
    M5.Lcd.printf("RAP");
    if (M5.BtnB.wasPressed()) {
      rapTime();
    } //end of if

    //print time
    M5.Lcd.setCursor(10, 10);
    M5.Lcd.printf("Time: %2d:%2d.%3d", (msCount / 60000) % 3600, (msCount / 1000) % 60, msCount % 1000);
    M5.Lcd.setCursor(10, 50);
    M5.Lcd.printf("%10d", msCount);

    //print rap time
    M5.Lcd.setCursor(40, 100);
    M5.Lcd.printf("%d - %d:%d.%d", rapCount, minRap, secondRap, msRap);

    //Quit (return to loop())
    M5.Lcd.setCursor(220, 200);
    M5.Lcd.printf("Quit");
    if (M5.BtnC.wasPressed()) {
      M5.Power.reset();
      M5.Lcd.fillScreen(BLACK);
      return;
    }
  } //end of while (1)
}

void setup() {
  M5.begin();

  M5.Lcd.fillScreen(BLACK);
  M5.Lcd.setTextColor(WHITE);
  M5.Lcd.setTextSize(3);

  file = SD.open(fname, FILE_APPEND);
  file.println("number,min,second,msRap");
  file.close();
}

void loop() {
  M5.update();

  M5.Lcd.setCursor(10, 10);
  M5.Lcd.printf("Press A button to start rap system");

  //start timer
  M5.Lcd.setCursor(20, 200);
  M5.Lcd.printf("START");
  if (M5.BtnA.wasPressed()) Timer();

} //end of loop()
