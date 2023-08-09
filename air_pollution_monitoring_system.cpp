#include <LiquidCrystal.h>

LiquidCrystal lcd_1(12, 11, 5, 4, 3, 2);

const int gasSensorPin = A0; // Gas sensor analog input pin

const float gasSensorSensitivity = 0.1;  // Calibration data or sensitivity values

float convertToAQI(float gasConcentration) {
  return gasConcentration * 10;
}
void setup()
{
  Serial.begin(9600);
  lcd_1.begin(16, 2);
}

void loop()
{
  // Read analog input from gas sensor
  int gasSensorValue = analogRead(gasSensorPin);

  // Convert analog reading to gas concentration
  float gasConcentration = gasSensorValue * gasSensorSensitivity;

  // Calculate Air Quality Index (AQI) using the conversion equation
  float airIndex = convertToAQI(gasConcentration);
  lcd_1.clear();
  lcd_1.setCursor(0,0);
  lcd_1.print("Air Index: ");
  lcd_1.print(airIndex);
  lcd_1.setCursor(0,1);
  if(airIndex>85)
  {
    lcd_1.print("POLLUTED AIR");
  }
  else
  {
    lcd_1.print("BREATHABLE AIR");
  }
  delay(1000);
}
