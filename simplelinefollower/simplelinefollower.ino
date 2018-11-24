//Initialising Motors
int rmf = 9; //Right Motor Forward
int rmb = 6; //Right Motor Back
int lmf = 10; //Left Motor Forward
int lmb = 11; //Left Motor Back

//Initialising Sensors
int s1 = A0; //Right Extreme 
int s2 = A1; //Right Middle 
int s3 = A2; //Center
int s4 = A3; //Left Middle
int s5 = A4; //Left Extreme

void setup() {
  // put your setup code here, to run once:

pinMode(rmf, OUTPUT);
pinMode(rmb, OUTPUT);
pinMode(lmf, OUTPUT);
pinMode(lmb, OUTPUT);

pinMode(s1, INPUT);
pinMode(s2, INPUT);
pinMode(s3, INPUT);
pinMode(s4, INPUT);
pinMode(s5, INPUT);

}

void loop() {

/*
 *  ls1  ls2  ms   rs2  rs1
 *   1    1    1    1    1   =  forwrard
 *   1    1    1    0    0   =  90 degree left
 *   0    1    1    0    0   =  curve left   
 *   0    0    1    0    0   =  forward
 *   0    0    1    1    1   =  curve right  
 *   0    0    1    1    0   =  90 degree right  
 */



if (analogRead(s1)>=700 && analogRead(s2)>=700 && analogRead(s3)>=700 && analogRead(s4)>=700 && analogRead(s5)>=700)

{
  analogWrite(rmf, 100);
  analogWrite(lmf, 100);
  analogWrite(rmb, 0);
  analogWrite(lmb, 0);
}

else if (analogRead(s1)>=700 && analogRead(s2)>=700 && analogRead(s3)>=700 && analogRead(s4)<=100 && analogRead(s5)<=100)

{
  analogWrite(rmf, 0);
  analogWrite(lmf, 100);
  analogWrite(rmb, 100);
  analogWrite(lmb, 0);
}

else if (analogRead(s1)>=700 && analogRead(s2)>=700 && analogRead(s3)>=700 && analogRead(s4)>=700 && analogRead(s5)<=100)

{
  
  analogWrite(rmf, 0);
  analogWrite(lmf, 100);
  analogWrite(rmb, 100);
  analogWrite(lmb, 0);
}

else if (analogRead(s1)>=700 && analogRead(s2)>=700 && analogRead(s3)>=700 && analogRead(s4)<=100 && analogRead(s5)>=700)

{
  
  analogWrite(rmf, 0);
  analogWrite(lmf, 100);
  analogWrite(rmb, 100);
  analogWrite(lmb, 0);
}

else if (analogRead(s1)>=700 && analogRead(s2)>=700 && analogRead(s3)>=700 && analogRead(s4)>=700 && analogRead(s5)>=700)

{
  analogWrite(rmf, 100);
  analogWrite(lmf, 100);
  analogWrite(rmb, 0);
  analogWrite(lmb, 0);
}

else if (analogRead(s1)<=100 && analogRead(s2)<=100 && analogRead(s3)>=700 && analogRead(s4)>=700 && analogRead(s5)>=700)
{
  analogWrite(rmf, 100);
  analogWrite(lmf, 0);
  analogWrite(rmb, 0);
  analogWrite(lmb, 100);
}
else if (analogRead(s1)<=100 && analogRead(s2)>=700 && analogRead(s3)>=700 && analogRead(s4)>=700 && analogRead(s5)>=700)

{
  analogWrite(rmf, 100);
  analogWrite(lmf, 0);
  analogWrite(rmb, 0);
  analogWrite(lmb, 100);
}

else if (analogRead(s1)>=700 && analogRead(s2)<=100 && analogRead(s3)>=700 && analogRead(s4)>=700 && analogRead(s5)>=700)

{
  analogWrite(rmf, 100);
  analogWrite(lmf, 0);
  analogWrite(rmb, 0);
  analogWrite(lmb, 100);
}

else
{
  analogWrite(rmf, 100);
  analogWrite(lmf, 100);
  analogWrite(rmb, 0);
  analogWrite(lmb, 0); 
}

}
