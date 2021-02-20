#include <M5Stack.h>
#include <Ticker.h>

//timer
Ticker ticker;

unsigned int secondCount = 0;
unsigned int minCount = 0;
unsigned int startCheck = 0;
unsigned int minRap = 0;
unsigned int secondRap = 0;
unsigned int rapCount = 0;
bool StartRapTimer = false;
//sd setting
unsigned int auiSize = 0;
unsigned int auiCnt = 0;

File file;
const char* fname = "/rapTime_log.csv";

void writeData(int rapCount, int minRap, int secondRap) {
  file = SD.open(fname, FILE_APPEND);
  file.println(String(rapCount) + "," + String(minRap) + "," + String(secondRap));
  file.close();
}

void countupTimer() {
  M5.Lcd.fillScreen(BLACK);
//timer mode
  //init
  M5.update();
  //carry
  if (secondCount == 60) {
    secondCount = 0;
    minCount++;
  } //end of if

  //save rap time
  M5.Lcd.setCursor(140, 200);
  M5.Lcd.printf("RAP");

  //print time
  M5.Lcd.setCursor(10, 10);
  M5.Lcd.printf("%d:%d", minCount, secondCount);
  // ticker.attach(1, printMillis);

  //print rap time
  M5.Lcd.setCursor(130, 130);
  M5.Lcd.printf("%d - %d:%d", rapCount, minRap, secondRap);

  //Quit (return to loop())
  M5.Lcd.setCursor(230, 200);
  M5.Lcd.printf("Quit");
  secondCount++;
}

void setup() {
  M5.begin();

  M5.Lcd.fillScreen(BLACK);
  M5.Lcd.setTextColor(WHITE);
  M5.Lcd.setTextSize(3);

  file = SD.open(fname, FILE_APPEND);
  file.println("number,min,second");
  file.close();
}

void loop() {
  M5.update();
  if(!StartRapTimer){
    M5.Lcd.setCursor(10, 10);
    M5.Lcd.printf("Press A button to start rap system");
    M5.Lcd.setCursor(20, 200);
    M5.Lcd.printf("START");
  }

  if (M5.BtnA.wasPressed()){
    StartRapTimer = true;
    ticker.attach(1,countupTimer);
  }
  
  if (M5.BtnB.wasPressed()) {
    minRap = minCount;
    secondRap = secondCount;
    rapCount++;
    writeData(rapCount, minRap, secondRap);
  } //end of if
  
  if (M5.BtnC.wasPressed()) {
    M5.Lcd.fillScreen(BLACK);
    StartRapTimer = false;
  }

} //end of loop()
