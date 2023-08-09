#include <Servo.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,2,3,4,5);
Servo myservo;  
#define ServoM 7        
#define Exit 9        
#define In 8      
#define Pwr 6          
#define Gnd 10          
#define BarLow 0      
#define BarUp 180      
#define Park_capc 6      
void setup(){
  Serial.begin(9600);
  myservo.attach(ServoM);          
  lcd.begin(16,2);
  lcd.print("Space left for");
  pinMode(Gnd, OUTPUT);
  pinMode(Pwr, OUTPUT);
  pinMode(Exit, INPUT);
  pinMode(In, INPUT);                
  digitalWrite(Gnd, LOW);
  digitalWrite(Pwr, HIGH);
  myservo.write(BarLow);          
}
int  car_Space = 5;          

void loop(){
    if (car_Space >= 1){
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Space left for");
      lcd.setCursor(0,1);  
      lcd.print(car_Space);
      lcd.print(" cars");
      delay(50);
    }
    else{
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Sorry!");
      lcd.setCursor(0,1);
      lcd.print("No place left!");
      delay(50);
    }

    if(digitalRead(In)==1){
        if(car_Space != 0){
            car_Space--;
            myservo.write(BarUp);
            delay(1000);
            myservo.write(BarLow);
        }
    }

    if(digitalRead(Exit)==1){
        if(car_Space != Park_capc){
            car_Space++;
            myservo.write(BarUp);
            delay(1000);
            myservo.write(BarLow);
       }
    }
  Serial.println(car_Space);
    delay(20);
}
