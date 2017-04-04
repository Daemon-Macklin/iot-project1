#include <math.h>

int threshold = 23;
int sensorPin = A0;
int sensorValue = 0;
int relayPin = 7;
double tempInCelcius = 0;


void setup() {
  Serial.begin(9600);
  pinMode(sensorPin, INPUT);
  pinMode(relayPin, OUTPUT);
}

void loop() {
  sensorValue =  analogRead(sensorPin);
  fan(sensorValue);
  tempInCelcius = thermistor(sensorValue);
  sensor();
}

void sensor(){
  Serial.println(tempInCelcius);
  delay(sensorValue); 
}

void fan(int sensorValue){
  
    if(tempInCelcius > threshold){
    Serial.println("Turn on Fan");
    digitalWrite(relayPin,HIGH);
  }
  
  else if(tempInCelcius < threshold){
    digitalWrite(relayPin,LOW);
  }
}

double thermistor(int sensorValue){
  double temp;
  
  temp= log(10000.0*((1441.0/sensorValue-1)));
  
  temp = 1/(0.001129148 + (0.000234125 +(0.0000000876741 *temp* temp))*temp);
  temp =temp - 273.15;
  return temp;
}



