#define BUTTONC 37
#define BUTTON_ON 0
#define BUTTON_OFF 1
int Count = 0,startCheck = 0;
int secondCount = 0, minCount = 0, startCheck = 0, minRap = 0, secondRap = 0;

void setup() {
  // put your setup code here, to run once:
@@ -23,17 +23,28 @@ void setup() {

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
