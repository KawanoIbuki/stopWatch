#include <M5Stack.h>
#include <Ticker.h>

#define ZERO 0
#define WIDTH 320
#define HEIGHT 235
#define DISPLAY_HEIGHT 190
#define MANU_HEIGHT 45

#define BUTTON_Y 180

Ticker tickerTime;

//timer
unsigned int msCount = 0;
unsigned int secondCount = 0;
unsigned int minCount = 0;

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

  minRap = (msCount / 6000) % 3600;
  secondRap = (msCount / 100) % 60;
  msRap = msCount & 100;

  //write data to csv file
  writeData(rapCount, minRap, secondRap, msRap);

  //print rap time
  M5.Lcd.fillRect(40, 100, 250, 25, 0x000F);
  M5.Lcd.setCursor(40, 100);
  M5.Lcd.setTextSize(3);
  M5.Lcd.printf("%2d - %2d:%2d.%2d", rapCount, minRap, secondRap, msRap);

}
void Timer() {
  //button icon
  M5.Lcd.fillRoundRect(0, 0, WIDTH, DISPLAY_HEIGHT, 10, 0x000F);  //x, y, width, height
  M5.Lcd.fillTriangle(50, DISPLAY_HEIGHT + 10, 50, DISPLAY_HEIGHT + 40, 80, DISPLAY_HEIGHT + 25, 0x000F);

  //10ms exec
  tickerTime.attach_ms(10, countUp);

  //timer mode
  while (1) {
    //init
    M5.update();

    //save rap time
    M5.Lcd.setCursor(140, 200);
    M5.Lcd.setTextSize(3);
    M5.Lcd.printf("RAP");
    if (M5.BtnB.wasPressed()) {
      rapTime();
    } //end of if

    //main print time
    M5.Lcd.fillRect(10, 10, 290, 50, 0x000F);
    M5.Lcd.setTextSize(6);
    M5.Lcd.setCursor(10, 10);
    M5.Lcd.printf("%2d:%2d.%2d", (msCount / 6000) % 3600, (msCount / 100) % 60, msCount % 100);
    //debag
    // M5.Lcd.setCursor(10, 50);
    // M5.Lcd.printf("%10d", msCount);

    //Quit (return to loop())
    M5.Lcd.setCursor(220, 200);
    M5.Lcd.setTextSize(3);
    M5.Lcd.printf("Quit");
    if (M5.BtnC.wasPressed()) {
      M5.Power.reset();
      return;
    } //end of if (M5.BtnC.wasPressed())

  } //end of while (1)

}

void setup() {
  M5.begin();

  //data explain
  file = SD.open(fname, FILE_APPEND);
  file.println("number,min,second,msRap");
  file.close();

  M5.Lcd.fillScreen(BLACK);   //background color
  M5.Lcd.setTextColor(GREEN);   //text color (RGBの中で一番明るく見えるため)

  /*
    M5.Lcd.drawFastVLine(2, 2, 230, 0xFD20); //left
    M5.Lcd.drawFastHLine(2, 2, 319, 0xFD20); //top
    M5.Lcd.drawFastVLine(319, 2, 230, 0xFD20); //right
    M5.Lcd.drawFastHLine(2, 230, 319, 0xFD20); //bottom
  */
  //M5.Lcd.drawRect(0, 0, WIDTH, HEIGHT, BLUE);  //x, y, width, height

  M5.Lcd.fillRoundRect(0, 0, WIDTH, DISPLAY_HEIGHT, 10, 0x000F);  //x, y, width, height
}

void loop() {
  M5.update();

  M5.Lcd.setTextSize(6);
  M5.Lcd.setCursor(20, 20);
  M5.Lcd.printf("RapTimer");

  M5.Lcd.setTextSize(2);
  M5.Lcd.setCursor(75, 100);
  M5.Lcd.printf("Press button to");
  M5.Lcd.setCursor(70, 130);
  M5.Lcd.printf("start stop watch");

  //start timer
  M5.Lcd.fillTriangle(50, DISPLAY_HEIGHT + 10, 50, DISPLAY_HEIGHT + 40, 80, DISPLAY_HEIGHT + 25, BLUE); //(x1, y1), (x2,y2), (x3, y3)
  if (M5.BtnA.wasPressed()) Timer();

} //end of loop()
