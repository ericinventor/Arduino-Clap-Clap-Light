int DO = 2; //Pin for Digital Output - DO
int DA = A3; // Pin for Analog Output - AO
int threshold = 107; //Set minimum threshold for LED lit
int sensorvalue = 0;
int clap = 0;
unsigned long starttime;
unsigned long endtime;
int count = 0;

void setup() {
  Serial.begin(9600);
}
 
void loop() {
  
  
  count = checkclap();
  Serial.println(count);
  clap = 0;
  delay(20);
 
}
  
int checkclap() 
{
 delay(20); 
  do{
      sensorvalue = analogRead(DA); 
      }while(sensorvalue < threshold);
       clap = 1;
       delay(20);
     
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
  
    starttime = millis();
    endtime = starttime;
  while ((millis()- starttime) <=500) // do this loop for up to 1000mS
  {
      sensorvalue = analogRead(DA);
      if (sensorvalue > threshold)
          {starttime = 0; clap = 3;}
  }
  return clap;
  
  /*if(clap !=3)
   {return clap;}
  delay(20);
  
    starttime = millis();
    endtime = starttime;
  while ((millis()- starttime) <=500) // do this loop for up to 1000mS
  {
      sensorvalue = analogRead(DA);
      if (sensorvalue > threshold)
          {starttime = 0; clap = 4;}
  }
 */
  
}


