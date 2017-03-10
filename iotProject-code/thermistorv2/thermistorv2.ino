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
  
  temp= log(10000.0*((1024.0/sensorValue-1)));
  
  temp = 1/(0.001129148 + (0.000234125 +(0.0000000876741 *temp* temp))*temp);
  temp =temp - 273.15;
  return temp;
}


