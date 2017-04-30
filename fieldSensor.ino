
#include <OneWire.h>
#include <DallasTemperature.h>
#include <Wire.h>

#include "LowPower.h"


#define ONE_WIRE_BUS_1 2
#define ONE_WIRE_BUS_2 3


OneWire oneWire_1(ONE_WIRE_BUS_1);
OneWire onewire_2(ONE_WIRE_BUS_2);

DallasTemperature temp_sensor_1(&oneWire_1);
DallasTemperature temp_sensor_2(&onewire_2);

float temp_1 = 0;
float temp_2 = 0;
float moisture0 =0;
float moisture1 = 0;
float voltage =0;
void read_temp_1() {
    temp_sensor_1.requestTemperatures();
    temp_1 = temp_sensor_1.getTempCByIndex(0);

    if(temp_1 == -127) {
      temp_1 = 0;
    }

    Serial.print("col1=");
    Serial.print(temp_1);
    Serial.print("&");
}

void read_temp_2() {
    temp_sensor_2.requestTemperatures();
    temp_2 = temp_sensor_2.getTempCByIndex(0);

    if(temp_2 == -127) {
      temp_2 = 0;
    }

    Serial.print("col2=");
    Serial.print(temp_2);
    Serial.print("&");
}

int readMositureA0() {
    moisture0 = analogRead(A0);
    Serial.print("col3=");
    Serial.print(moisture0);
    Serial.print("&");
    return 0;
}

int readMositureA1() {
    moisture1 = analogRead(A1);
    Serial.print("col4=");
    Serial.print(moisture1);
    Serial.print("&");
    return 0;
}

int readBatteryVoltage() {
    Serial.print("col5=");
    voltage = analogRead(A7);
    Serial.println(voltage);
   
    return 0;
  }

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED_BUILTIN,OUTPUT);
  temp_sensor_1.begin();
  temp_sensor_2.begin();

}

void loop() {  // put your main code here, to run repeatedly:
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);
  digitalWrite(LED_BUILTIN, LOW);
  LowPower.powerDown(SLEEP_8S, ADC_OFF, BOD_OFF);
 
  delay(1000);
  
  read_temp_1();
  read_temp_2();
  readMositureA0();
  readMositureA1();
  readBatteryVoltage();
 // Serial.print(
//  Serial.print("==");
//   Serial.print(temp_1);
//   Serial.print(",");
//   Serial.print(temp_2);
//   Serial.print("==");
}