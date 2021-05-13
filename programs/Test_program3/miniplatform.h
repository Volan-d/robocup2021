void setupMotorShield()
{
  pinMode(SecondPin1,OUTPUT);
  pinMode(SecondPin2,OUTPUT);
  pinMode(SpeedPinSecondMotor,OUTPUT);
  
  pinMode(FirstPin1,OUTPUT);
  pinMode(FirstPin2,OUTPUT);
  pinMode(SpeedPinFirstMotor,OUTPUT);
  
  
  pinMode(ThirdPin1,OUTPUT);
  pinMode(ThirdPin2,OUTPUT);
  pinMode(SpeedPinTridMotor,OUTPUT);
  
  pinMode(FourPin1,OUTPUT);
  pinMode(FourPin2,OUTPUT);
  pinMode(SpeedPinFourthMotor,OUTPUT);
}
void RotatesLeft(int _speed1 = 255, int _speed2 = 255, int _speed3 = 255, int _speed4 = 255)
{
  digitalWrite(SecondPin1,0);
  digitalWrite(SecondPin2,1);
  analogWrite(SpeedPinSecondMotor,_speed2);
  
  digitalWrite(FirstPin1,1);
  digitalWrite(FirstPin2,0);
  analogWrite(SpeedPinFirstMotor,_speed1);
  
  digitalWrite(ThirdPin1,0);
  digitalWrite(ThirdPin2,1);
  analogWrite(SpeedPinTridMotor,_speed3);
  
  digitalWrite(FourPin1,1);
  digitalWrite(FourPin2,0);
  analogWrite(SpeedPinFourthMotor,_speed4);

}
void RotatesRight(int _speed1 = 255, int _speed2 = 255, int _speed3 = 255, int _speed4 = 255)
{
  digitalWrite(SecondPin1,1);
  digitalWrite(SecondPin2,0);
  analogWrite(SpeedPinSecondMotor,_speed2);

  digitalWrite(FirstPin1,0);
  digitalWrite(FirstPin2,1);
  analogWrite(SpeedPinFirstMotor,_speed1);
  
  digitalWrite(ThirdPin1,1);
  digitalWrite(ThirdPin2,0);
  analogWrite(SpeedPinTridMotor,_speed3);
  
  digitalWrite(FourPin1,0);
  digitalWrite(FourPin2,1);
  analogWrite(SpeedPinFourthMotor,_speed4);

}
void Stop()
{
  digitalWrite(SecondPin1,0);
  digitalWrite(SecondPin2,0);
  analogWrite(SpeedPinSecondMotor,0);

  digitalWrite(FirstPin1,0);
  digitalWrite(FirstPin2,0);
  analogWrite(SpeedPinFirstMotor,0);
  
  
  digitalWrite(ThirdPin1,0);
  digitalWrite(ThirdPin2,0);
  analogWrite(SpeedPinTridMotor,0);
  
  digitalWrite(FourPin1,0);
  digitalWrite(FourPin2,0);
  analogWrite(SpeedPinFourthMotor,0);
}
void goForward(int _speed1 = 255, int _speed2 = 255, int _speed3 = 255, int _speed4 = 255)
{
  digitalWrite(SecondPin1,1);
  digitalWrite(SecondPin2,0);
  analogWrite(SpeedPinSecondMotor,_speed2);

  digitalWrite(FirstPin1,1);
  digitalWrite(FirstPin2,0);
  analogWrite(SpeedPinFirstMotor,_speed1);
  
  digitalWrite(ThirdPin1,1);
  digitalWrite(ThirdPin2,0);
  analogWrite(SpeedPinTridMotor,_speed3);
  
  
  digitalWrite(FourPin1,1);
  digitalWrite(FourPin2,0);
  analogWrite(SpeedPinFourthMotor,_speed4);
}
void turnLeft(int _speed1 = 255, int _speed2 = 255, int _speed3 = 255, int _speed4 = 255)
{
  digitalWrite(SecondPin1,1);
  digitalWrite(SecondPin2,0);
  analogWrite(SpeedPinSecondMotor,_speed2);

  digitalWrite(FirstPin1,0);
  digitalWrite(FirstPin2,1);
  analogWrite(SpeedPinFirstMotor,_speed1);
  
  digitalWrite(ThirdPin1,0);
  digitalWrite(ThirdPin2,1);
  analogWrite(SpeedPinTridMotor,_speed3);
  
  digitalWrite(FourPin1,1);
  digitalWrite(FourPin1,0);
  analogWrite(SpeedPinFourthMotor,_speed4);
}
void turnRight(int _speed1 = 255, int _speed2 = 255, int _speed3 = 255, int _speed4 = 255)
{
  digitalWrite(SecondPin1,0);
  digitalWrite(SecondPin2,1);
  analogWrite(SpeedPinSecondMotor,_speed2);

  digitalWrite(FirstPin1,1);
  digitalWrite(FirstPin2,0);
  analogWrite(SpeedPinFirstMotor,_speed1);

  digitalWrite(ThirdPin1,1);
  digitalWrite(ThirdPin2,0);
  analogWrite(SpeedPinTridMotor,_speed3);
  
  digitalWrite(FourPin1,0);
  digitalWrite(FourPin2,1);
  analogWrite(SpeedPinFourthMotor,_speed4);
}
void back(int _speed1 = 255, int _speed2 = 255, int _speed3 = 255, int _speed4 = 255)
{
  digitalWrite(SecondPin1,0);
  digitalWrite(SecondPin2,1);
  analogWrite(SpeedPinSecondMotor,_speed2);

  digitalWrite(FirstPin1,0);
  digitalWrite(FirstPin2,1);
  analogWrite(SpeedPinFirstMotor,_speed1);
  
  digitalWrite(ThirdPin1,0);
  digitalWrite(ThirdPin2,1);
  analogWrite(SpeedPinTridMotor,_speed3);
  
 
  digitalWrite(FourPin1,0);
  digitalWrite(FourPin2,1);
  analogWrite(SpeedPinFourthMotor,_speed4);
}
void fun(int val){
  switch(val){
    case 1: turnLeft();
    break;
    case 2:back();
    break;
    case 3:turnRight();
    break;
    case 4:goForward();
    
  }
}
