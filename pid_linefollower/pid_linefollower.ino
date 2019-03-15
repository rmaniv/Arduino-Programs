/*  
 *   PID Line Follower
 *   
 *   NOTE: This code hasn't been tested on a robot, so values for Kp, Ki, Kd, set point etc are dummy values.
 *   
 *   Developed by Vinamr L. Sachdeva 
*/

long sensor[] = {0, 0, 0, 0, 0}; //leftmost - 0, rightmost - 4
int rmf=9;
int rmb=6;
int lmf=10; 
int lmb=11;

//speeds
int right;
int left;
const int max_speed = 255;

int pos;
long sensor_average;
int sensor_sum;

float p;
float i;
float d;
float lp;
int error;
int correction;
const float sp = 3.5;

float Kp = 0.1;
float Ki = 0;
float Kd = 10;

void pid_calc();
void calc_turn();
void motor_drive();

void setup()
{
  //sensors
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);

  //motors
  pinMode(rmf, OUTPUT);
  pinMode(rmb, OUTPUT);
  pinMode(lmf, OUTPUT);
  pinMode(lmb, OUTPUT);
}

void loop()
{
  
}

void pid_calc()
{
  sensor_average = 0;
  sensor_sum = 0;
  i = 0;

  for(int i = -2; i <= 2; i++)
  {
    sensor[i]=analogRead(i);
    sensor_average = sensor[i]*i*1000; //weighted mean
    sensor_sum += sensor[i];
  }

  pos = int(sensor_average / sensor_sum);

  error = pos-sp;

  p = error;
  i += p;
  d = p - lp;

  lp = p;

   correction = int(Kp*p + Ki*i + Kd*d);
}

void calc_turn()
{
  //adjusting minimum and maximum value
  if (correction > 255)
    correction = 255;

  else if (correction < -255)
    correction = -255;

   //motor speeds
   if (correction < 0)
   {
     right = max_speed + correction;
     left = max_speed;
   }

   else if (correction > 0)
   {
      right = max_speed;
      left = max_speed - correction;
   }

   motor_drive (right, left);
}

void motor_drive (int right_speed, int left_speed)
{
    analogWrite(rmf, abs(right_speed));
    analogWrite(lmf, abs(left_speed));

    delay(50);
}

