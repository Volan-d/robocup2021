#define s(x) x<=100?0:map(x, 100, 255, 0, 100)
#include"config.h"
#include <Wire.h> 
#include "miniplatform.h"
#include <VL53L1X.h>
#include <TroykaIMU.h>
#include <SPI.h>
#define _CS_PIN1_ 10
#define _CS_PIN2_ 11

VL53L1X sensor;
VL53L1X sensor2;
Compass compass;


int _azimut = 0;
void setup() {
  pinMode(_CS_PIN1_,OUTPUT);
  digitalWrite(_CS_PIN1_,HIGH);
  pinMode(_CS_PIN2_,OUTPUT);
  digitalWrite(_CS_PIN2_,HIGH);
  
  Serial.begin(9600);
  Wire.begin();
  SPI.begin();
  SPI.setClockDivider(SPI_CLOCK_DIV2);
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
  _azimut=compass.readAzimut();//градус главной оси                                    

}

void loop() {
 int _chekLine = 0;
  if(Serial.available()>0){
     _chekLine = Serial.read();
    }
 int _linetime = 40;              //тоже подобрать подходящее значение
   switch (_chekLine){
    case 1:
      turnLeft();
      delay(_linetime);              
      break;
    case 2:
      back();
      delay(_linetime);
      break;
    case 3:
      turnRight();
      delay(_linetime);
      break;
    case 4:
      goForward();
      delay(_linetime);
      break;
    }  
  if(compass.readAzimut()<=_azimut-5 and compass.readAzimut()>=_azimut+5){
   while(compass.readAzimut()>=_azimut-5 and compass.readAzimut()<=_azimut+5){
    if(compass.readAzimut()>_azimut){
    RotatesLeft();
   }
   else{
    RotatesRight();
   }
  }
 }
 
                                         /*
                                          * 
                                          * Получить массив с датчиков мачя 
                                          * опеределить его направление
                                          *
                                          * решение ехать мячу,если мячь захвачен угол до ворот и... 
                                          */
   
}
