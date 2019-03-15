/*
 * This program measures the PM2.5 values using an Optical Dusty Sensor.
 * Developer: Vinamr L. Sachdeva
 */

int measurePin = A0;
int ledPower = 12;
 
int samplingTime = 280;
int deltaTime = 40;
int sleepTime = 9680;
 
float voMeasured = 0;
float calcVoltage = 0;
float dustDensity = 0;

void setup() {
  Serial.begin(9600);
  
  pinMode(ledPower,OUTPUT);

}

void loop() {

  digitalWrite(ledPower,LOW);
  delayMicroseconds(samplingTime);
 
  voMeasured = analogRead(measurePin);
 
  delayMicroseconds(deltaTime);
  digitalWrite(ledPower,HIGH);
  delayMicroseconds(sleepTime);
 
  // 0 - 3.3V mapped to 0 - 1023 integer values
  // recover voltage
  calcVoltage = voMeasured * (3.3 / 1024);
  
  dustDensity = (0.17 * calcVoltage - 0.1)*843;

  Serial.println(dustDensity);
 
  delay(1000);

}
