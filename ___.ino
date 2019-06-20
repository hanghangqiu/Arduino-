#include <Wire.h>

int redPin= 7;
int greenPin = 6;
int bluePin = 5;
int Intensity =0;//定义Intensity变量

#define AD5 A5//定义模拟口A5

void setup() {
    
Serial.begin(9600);
 
 while (!Serial) {
    
; // wait for serial port to connect. Needed for Leonardo only
  

  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

}
  
}

void loop() {
  
  //光线越暗，值越大；反之则越小。
  Intensity = analogRead(AD5);  //读取模拟口AD5的值，存入Intensity变量
  Serial.print("Intensity = ");  //串口输出"Intensity = "
  Serial.println(Intensity);     //串口输出Intensity变量的值，并换行
  delay(500);     //延时500ms
if(Intensity>600){
  setColor(0, 0, 255); // Blue Color
  delay(5);
//大于600时，即达到了一定暗的程度，亮灯
  }
  else {
    setColor(0, 0, 0); // Black Color
  delay(1000);
//否则，灭灯
    }

}

void setColor(int redValue, int greenValue, int blueValue) {
  analogWrite(redPin, redValue);
  analogWrite(greenPin, greenValue);
  analogWrite(bluePin, blueValue);
}
