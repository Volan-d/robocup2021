    
#define FirstPin1 2
#define FirstPin2 6
#define SpeedPinFirstMotor 9

#define SecondPin1 1
#define SecondPin2 5
#define SpeedPinSecondMotor 10

#define ThirdPin1 44
#define ThirdPin2 72
#define SpeedPinTridMotor 11

#define FourPin1 4
#define FourPin2 8
#define SpeedPinFourthMotor 12

int Speed1 =0; 
int Speed2 =0;
int Speed3 =0;
int Speed4 =0;
#include "miniplatform.h"

#define s(x) x<=100?0:map(x, 100, 255, 0, 100)

void setup() {
  // put your setup code here, to run once:

  setupMotorShield();
}

void loop() {
  // put your main code here, to run repeatedly:
  goForward(s(100), s(50), s(100), s(50));

}
