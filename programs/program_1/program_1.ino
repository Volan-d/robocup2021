
#include <Wire.h> 
#include "miniplatform.h"

#define s(x) x<=100?0:map(x, 100, 255, 0, 100)
uint32_t _timer;
float _mode;
float _start;
void setup() {
  Serial.begin(9600);
  if(Serial.available()>0){
  _start=Serial.read(); //получить по UART разрешение на старт от ESP
  delay(10);
  _mode=Serial.read();  // Положение переключателя вратарь нападающтй
  }
  if(_start==true){       
    _timer = millis();
    setupMotorShield();// инициализация пинов моторов
                       //включение датчиков
                       //градус главной оси
    Serial.write("Well"); //оправить сигнал о удачной инициализации 
  }                                    
                     
}

void loop() {
  int _chekLine;
  if(millis()-_timer>=40){          // нужно будет подобрать подходящее время
    _timer = millis();
    if(Serial.available()>0){
     _chekLine = Serial.read();
    }
   int _linetime = 40;              //тоже подобрать подходящее значение
   switch (_chekLine){
    case 1:
      turnLeft();
      delay(_linetime);              // возможно это неправильно, что я делаю все действия внутри прерывания
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
    default:
   }
  }
                                        /*
                                          * получение значения с компаса колибровка
                                          * Определить допустимый диапазон в котором робот не будет калиброватся
                                          * 
                                          * 
                                          * 
                                          * Получить массив с датчиков мачя 
                                          * опеределить его направление
                                          * 
                                          * 
                                          * если нет линии 
                                          * 
                                          * решение ехать мячу,если мячь захвачен угол до ворот и... 
                                          */

}
