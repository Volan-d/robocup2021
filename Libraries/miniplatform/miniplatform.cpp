#include <Arduino.h>
int sdp=4;
int wdp=7;
int ndp=8;
int vdp=11;
int fsp=5;
int ssp=6;
int tsp=9;
int esp=10;
int rs=255;
void setupMotorShield()
{
  pinMode(sdp,OUTPUT);
  pinMode(wdp,OUTPUT);
  pinMode(vdp,OUTPUT);
  pinMode(ndp,OUTPUT);
  pinMode(fsp,OUTPUT);
  pinMode(ssp,OUTPUT);
  pinMode(tsp,OUTPUT);
  pinMode(esp,OUTPUT);
}
void RotatesLeft()
{
  digitalWrite(sdp,0);
  digitalWrite(wdp,1);
  digitalWrite(ndp,0);
  digitalWrite(vdp,1);
  digitalWrite(fsp,1);
  digitalWrite(ssp,0);
  digitalWrite(tsp,1);
  digitalWrite(esp,0);
}
void RotatesRigt()
{
  digitalWrite(sdp,1);
  digitalWrite(wdp,0);
  digitalWrite(ndp,1);
  digitalWrite(vdp,0);
  digitalWrite(fsp,0);
  digitalWrite(ssp,1);
  digitalWrite(tsp,0);
  digitalWrite(esp,1);
}
void stopt()
{
  digitalWrite(sdp,0);
  digitalWrite(wdp,0);
  digitalWrite(ndp,0);
  digitalWrite(vdp,0);
  digitalWrite(fsp,0);
  digitalWrite(ssp,0);
  digitalWrite(tsp,0);
  digitalWrite(esp,0);
}
void goForward()
{
  digitalWrite(sdp,1);
  digitalWrite(wdp,1);
  digitalWrite(ndp,1);
  digitalWrite(vdp,1);
  digitalWrite(fsp,0);
  digitalWrite(ssp,0);
  digitalWrite(tsp,0);
  digitalWrite(esp,0);
}
void turnLeft()
{
  digitalWrite(sdp,1);
  digitalWrite(wdp,0);
  digitalWrite(ndp,0);
  digitalWrite(vdp,1);
  digitalWrite(fsp,0);
  digitalWrite(ssp,1);
  digitalWrite(tsp,1);
  digitalWrite(esp,0);
}
void turnRight()
{
  digitalWrite(sdp,0);
  digitalWrite(wdp,1);
  digitalWrite(ndp,1);
  digitalWrite(vdp,0);
  digitalWrite(fsp,1);
  digitalWrite(ssp,0);
  digitalWrite(tsp,0);
  digitalWrite(esp,1);
}
void back()
{
  digitalWrite(sdp,0);
  digitalWrite(wdp,0);
  digitalWrite(ndp,0);
  digitalWrite(vdp,0);
  digitalWrite(fsp,1);
  digitalWrite(ssp,1);
  digitalWrite(tsp,1);
  digitalWrite(esp,1);
}