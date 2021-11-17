

#include <Servo.h> 
 
Servo myservo;  // create servo object to control a servo 
 
int DO = 2; //Pin for Digital Output - DO
int DA = A3; // Pin for Analog Output - AO
int threshold = 108; //Set minimum threshold for LED lit
int sensorvalue = 0;
boolean light = true;
int clap = 0;
int count = 0;
int x;
unsigned long starttime;
unsigned long endtime;


 
 
void setup() 
{
  Serial.begin(9600);
  myservo.attach(9);
  myservo.write (10);
  delay (800);
}
 
void loop() {
  
  count = checkclap();
  Serial.println(count);
        
     if (count == 2)
      { if (light == true)
          lightoff(); 
        else
          {lighton(); }
      }  
}


int checkclap() 
{
  clap= 0;
 delay(40); 
  do{
      sensorvalue = analogRead(DA); 
      }while(sensorvalue < threshold);
       clap = 1;
       delay(100);
     
    starttime = millis();
    endtime = starttime;
  while ((millis()- starttime) <=500) // do this loop for up to 1000mS
  {
      sensorvalue = analogRead(DA);
      if (sensorvalue > threshold)
          {starttime = 0; clap = 2;}
  }
  
  if(clap !=2)
   {return clap;}
   delay(20);
  return clap; 
}

void lighton()
{
  myservo.write (85);
  delay (800);
  light = true;
}

void lightoff()
{
  myservo.write (10);
  delay (800);
  light = false;
}


