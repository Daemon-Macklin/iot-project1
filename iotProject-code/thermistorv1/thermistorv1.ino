int sensorPin = A0;
int sensorValue = 0;

void setup() {
  Serial.begin(9600);
  pinMode(sensorPin, INPUT);
  pinMode(13, OUTPUT);
}

void loop() {
  sensorValue = analogRead(sensorPin);
  Serial.println(sensorValue);
  delay(sensorValue);
  fan();

}

void fan(){
    if(sensorValue > 700){
    Serial.println("Turn on Fan");
    digitalWrite(13,HIGH);
  }
  else if(sensorValue < 700){
    digitalWrite(13,LOW);
  }
}
