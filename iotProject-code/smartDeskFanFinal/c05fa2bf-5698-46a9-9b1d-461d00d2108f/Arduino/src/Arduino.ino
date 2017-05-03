#include <math.h>


int threshold = 23;
int sensorPin = A0;
int sensorValue = 0;
int relayPin = 7;
double tempInCelcius = 0;
double powerConsumptionValue = 0;
bool isOn = false;
double timer = 0;
double elapsed;


void setup() {
  Serial.begin(9600);
  pinMode(sensorPin, INPUT);
  pinMode(relayPin, OUTPUT);
}

void loop() {
  sensorValue =  analogRead(sensorPin);
  if(Serial.available() > 0){
  threshold = Serial.parseInt(); 
  }
  fan(sensorValue);
  tempInCelcius = thermistor(sensorValue);
  sensor();
  if(isOn == true){
     timer ++;
   }
   if(isOn == false){
     elapsed = timer;
     timer = 0;
   }
   powerConsumptionValue = powerConsumption(elapsed);
  
}

void sensor(){
  Serial.println(tempInCelcius);
  delay(sensorValue); 
}

void fan(int sensorValue){
  if(tempInCelcius > threshold){
    Serial.println("Turn on Fan");
    digitalWrite(relayPin,HIGH);
    isOn = true;
  }
  
  else if(tempInCelcius < threshold+3){
    digitalWrite(relayPin,LOW);
    isOn = false;
  }
  
}

 double powerConsumption(double elapsed){
   if(elapsed != 0.0000000000000000){
   elapsed = elapsed/3600;
   powerConsumptionValue = (750*elapsed);
   //Serial.println(powerConsumptionValue);
   return powerConsumptionValue;
   }
 }

double thermistor(int sensorValue){
  double temp;
  
  temp= log(10000.0*((1441.0/sensorValue-1)));
  
  temp = 1/(0.001129148 + (0.000234125 +(0.0000000876741 *temp* temp))*temp);
  temp = temp - 273.15;
  return temp;
}


