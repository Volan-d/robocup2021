
#include"config.h"
#include <Wire.h> 
#include "miniplatform.h"
#include <VL53L1X.h>
#include <TroykaIMU.h>

VL53L1X sensor;
VL53L1X sensor2;
Compass compass;
#define s(x) x<=100?0:map(x, 100, 255, 0, 100)

void setup() {
  OCR0A = 0xC8;
  TIMSK0 |= _BV(OCIE0A);
  Serial.begin(9600);
  Wire.begin();
  compass.begin();
  Wire.setClock(400000);
       
  setupMotorShield();// инициализация пинов моторов
  Stop();

  //включение датчиков
  sensor.setTimeout(500);
  sensor.setDistanceMode(VL53L1X::Long);
  sensor.setMeasurementTimingBudget(50000);
  sensor.startContinuous(50);
  sensor2.setTimeout(500);
  sensor2.setDistanceMode(VL53L1X::Long);
  sensor2.setMeasurementTimingBudget(50000);
  sensor2.startContinuous(50);                                           
  //градус главной оси                                    
                     
}

void loop() {
  Serial.print(compass.readAzimut());
  Serial.println(" Degrees");
  Serial.print(sensor.read());
  Serial.print("mm");
  Serial.print(sensor2.read());
  Serial.print("mm");
  delay(100);
  
                                         /*
                                          * получение значения с компаса колибровка
                                          * Определить допустимый диапазон в котором робот не будет калиброватся 
                                          * 
                                          * Получить массив с датчиков мачя 
                                          * опеределить его направление
                                          *
                                          * решение ехать мячу,если мячь захвачен угол до ворот и... 
                                          */

}
