
#define sdp 1    //здесь я назову по человечески и сгруппирую
#define wdp 2   //думаю называть моторы по часовой стрелки начиная с верхнего левого по типу FirstPin1,FirstPin2....SecondPin1...
#define ndp 3
#define vdp 4
#define fsp 5
#define ssp 6
#define tsp 7
#define esp 8
#define SpeedPinFirstMotor 9
#define SpeedPinSecondMotor 10
#define SpeedPinTridMotor 11
#define SpeedPinFourthMotor 12

int Speed1 = 0; 
int Speed2 =0;
int Speed3 =0;
int Speed4 =0;
#include "miniplatform.h"
void setup() {
  // put your setup code here, to run once:
  
  setupMotorShield();
}

void loop() {
  // put your main code here, to run repeatedly:
  goForward();

}
