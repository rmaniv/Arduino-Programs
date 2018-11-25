int trigPin = 2;
int echoPin = 1;
int leftMotorf = A0;
int leftMotorb = A1;
int rightMotorf = A2;
int rightMotorb = A3;

void setup() {
 
pinMode(trigPin,OUTPUT);
pinMode(echoPin,INPUT);
  
}
 
void loop () {
 
int duration;
int distance;

digitalWrite(trigPin,HIGH);
delay(1);
digitalWrite(trigPin,LOW);

duration = pulseIn(echoPin,HIGH);
distance = (duration/2) / 29.2;

if (distance = 20) //If an obstacle is detected at a distacle of 20 cm.
{
  //Avoid the obstacle 
  
  //Turn right 
  analogWrite(leftMotorf, 140);
  analogWrite(leftMotorb, 140);
  analogWrite(rightMotorf, 0);
  analogWrite(rightMotorb, 0);
  delay(2500);
  
  //Move Foreward
  analogWrite(leftMotorf, 140);
  analogWrite(leftMotorb, 0);
  analogWrite(rightMotorf, 140);
  analogWrite(rightMotorb, 0);
  delay(2500);
  
  //Turn Left
  analogWrite(leftMotorf, 0);
  analogWrite(leftMotorb, 0);
  analogWrite(rightMotorf, 140);
  analogWrite(rightMotorb, 140);
  delay(2500); 
}  

}
