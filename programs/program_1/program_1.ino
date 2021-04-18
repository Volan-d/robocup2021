


#include <Wire.h> 
#include "miniplatform.h"

#define s(x) x<=100?0:map(x, 100, 255, 0, 100)

float _mode;
float _start;




void setup() {

 
  Serial.begin(9600);
  if(Serial.available()>0){
  _start=Serial.read(); //получить по UART разрешение на старт от ESP
  delay(10);
  _mode=Serial.read();  // Положение переключателя вратарь нападающтй
  }       
  setupMotorShield();  // инициализация пинов моторов
                       //включение датчиков
                       //градус главной оси                                    
                     
}

void loop() {
  
  
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
                                          * 
                                          * решение ехать мячу,если мячь захвачен угол до ворот и... 
                                          */

}

SIGNAL(USART_RXC_vect) {    // прерывание по получению байта через UART
  int _chekLine;
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
    
}
