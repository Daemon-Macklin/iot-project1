#include <math.h>

int sensorPin = A0;
int sensorValue = 0;
double tempInCelcius = 0;


void setup() {
  Serial.begin(9600);
  pinMode(sensorPin, INPUT);
  pinMode(13, OUTPUT);
}

void loop() {
  sensorValue =  analogRead(sensorPin);
  fan(sensorValue);
  tempInCelcius = thermistor(sensorValue);
  sensor();
}

void sensor(){
  Serial.println(tempInCelcius);
  delay(tempInCelcius); 
}

void fan( int sensorValue){
  
    if(sensorValue > 700){
    Serial.println("Turn on Fan");
    digitalWrite(13,HIGH);
  }
  
  else if(sensorValue < 700){
    digitalWrite(13,LOW);
  }
}

double thermistor(int sensorValue){
  double temp;
  
  int B=4700;
  temp= 100000*(1023.0/(sensorValue)-1);
  
  temp = 1/(log(temp/100000)/B+1/298.15)-273.15;
  return temp;
}


