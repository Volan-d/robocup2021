

#define s(B) B<=100?0:map(B, 100, 255, 0, 100)
#include <math.h>
#include"config.h"
#include <Wire.h> 
#include "miniplatform.h"
#include <VL53L1X.h>
#include <TroykaIMU.h>
#include <SPI.h>
#include <MCP3008.h>


VL53L1X _dali_X;
VL53L1X _dali_Y;
Compass compass;

MCP3008 Secker(CLOCK_PIN, MOSI_PIN, MISO_PIN, _CS_PIN1_);
MCP3008 Secker2(CLOCK_PIN, MOSI_PIN, MISO_PIN, _CS_PIN2_);
bool mode = false;
byte val = 0;
bool start = false;
bool _goal = false;
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
  _dali_X.setTimeout(500);
  _dali_X.setDistanceMode(VL53L1X::Long);
  _dali_X.setMeasurementTimingBudget(50000);
  _dali_X.startContinuous(50);
  
  _dali_Y.setTimeout(500);
  _dali_Y.setDistanceMode(VL53L1X::Long);
  _dali_Y.setMeasurementTimingBudget(50000);
  _dali_Y.startContinuous(50);                                           
  _azimut=compass.readAzimut();//градус главной оси                                    

}

void loop() {
  
 int _chekLine = 0;
  if(Serial.available()>1){
     char key = Serial.read();
     int val = Serial.parseInt();
     switch(key){
      case 'L': afun(val);
      break;
      case 'S': start = true;
      break;
      case 'F': mode = true;
      break;
      case 'G': mode = false;
      break;
     }
   }
if(start){
 if(_goal){    
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
}
 int _seckdata[16];
 for(int i=0;i<8;i++){
  int val = Secker.readADC(i); 
  _seckdata[i]=val;
 }
 for(int i=0;i<8;i++){
  int val = Secker2.readADC(i); // позже можно вынести в отдельный блок
  _seckdata[i+7]=val;
 }
 int MAX=0,NOM=0;
 for(int i=0;i<16;i++){
  if(_seckdata[i]>MAX){
    MAX=_seckdata[i];
    NOM=i;
    }
 }


 int x=0,y=0,now_azimut=0;
 if(6<=NOM<=8 and MAX>42){ 
                         // это если мячь захвачен то довернуть до ворот
                         
                         
   _goal=true;
   int x =_dali_X.read();
   int y =_dali_Y.read();
   now_azimut=compass.readAzimut();
   if(x<91){
    now_azimut=now_azimut-(x/y);           //не работает
    while(compass.readAzimut()!=now_azimut){
     turnRight();
    }
   }
   else{
    now_azimut=now_azimut+(x/y);
    while(compass.readAzimut()!=now_azimut){
     turnLeft();
    }
   }
 
 }
 else{
  if(0<=NOM<=2){
    back();
  }
  if(3<=NOM<=5){
    turnLeft();
  }
  if(6<=NOM<=8){
    goForward();
  }
  if(9<=NOM<=11){
    turnRight();
  }
  if(12<=NOM<=15){
    back();
  }
 }

 
}
}
