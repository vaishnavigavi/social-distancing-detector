const int trigPin = 9;
const int echoPin = 10;
const int ledPin = 13; //led pin on arduino
long duration;
int distanceCm, distanceInch;
void setup()
{
Serial.begin(9600); 
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
pinMode(11,OUTPUT);
pinMode(12,OUTPUT);
}
void loop() {
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distanceCm= duration*0.034/2;
distanceInch = duration*0.0133/2;
Serial.println("Distance: ");
Serial.println(distanceCm);

if(distanceCm < 100)
{
  digitalWrite(11,HIGH);
  digitalWrite(ledPin, HIGH); //light led
  digitalWrite(12,HIGH);
}
else 
{
  digitalWrite(11,LOW);
  digitalWrite(ledPin, LOW); //don't light led
  digitalWrite(12,LOW);
}
}
