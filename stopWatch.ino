#include <M5Stack.h>
int counter = 0;
//counter[0]=>ns, [1]=>ms, [2]=>s, [3]=>,min

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
  
  //stop watch start
  while(M5.BtnA.wasPressed()){
    M5.Lcd.printf("%d",counter);
    
    counter++;
    M5.Lcd.fillScreen(BLACK);
  }
}
