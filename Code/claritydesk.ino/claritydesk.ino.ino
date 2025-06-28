int brightnessanalog =A5;
int brightnessval;
int brakeTime = 250; // For reference: 1000 = 1 second
int redled = 10;
int yellowled = 11;
int greenled = 12;

// Button Timer Variables
const int buttonPin=9;
int beforebuttonval=HIGH;
int buttonval=HIGH;
int redPin=7;
int buzzerPin=6;
int redBlink=300;
bool timeChecker=false;
unsigned long timestart=0;
unsigned long timelength=15000; //ATM its 15 secods for the sake of testing - Will change
int buttondelay=250;

//Temp Checker Variables
#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN,DHTTYPE);
unsigned long tempreadlast=0;
unsigned long tempinterval = 5000;


void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
// LDR
pinMode(brightnessanalog,INPUT);
pinMode(redled,OUTPUT);
pinMode(yellowled,OUTPUT);
pinMode(greenled,OUTPUT);
//Button
pinMode(buttonPin,INPUT_PULLUP);
pinMode(redPin,OUTPUT);
pinMode(buzzerPin,OUTPUT);
//Temp
dht.begin();

}
void LedBlinker(int ledlight){
  digitalWrite(ledlight,HIGH);
  delay(brakeTime);
  digitalWrite(ledlight,LOW);
  delay(brakeTime);
}
void loop() {
//LDR  
brightnessval = analogRead(brightnessanalog); // This allows the variable brightnessval to hold the value of the brightness measured by the A1 analog
Serial.println(brightnessval);
if(brightnessval>=300){
  LedBlinker(greenled);
}
if(brightnessval<300 && brightnessval>100){
  LedBlinker(yellowled);
}
if(brightnessval<=100){
  LedBlinker(redled);
}




// Button Timer
buttonval = digitalRead(buttonPin);
delay(buttondelay);  // small delay to debounce and slow down Serial Monitor
Serial.println(buttonval);

if (buttonval == LOW && beforebuttonval == HIGH) {
  if (timeChecker == false) {
    timeChecker = true;
    timestart = millis();
    Serial.println("The Timer Has Started!");
    delay(300); // helps with bounce and accidental double triggers
  } else {
    timeChecker = false;
    timestart = 0;
    Serial.println("The Timer Has Stopped");
    delay(300); // also debounce stop press
  }
}

if (timeChecker && (millis() - timestart >= timelength)) {
  for (int j = 0; j < 5; j++) {
    digitalWrite(redPin, HIGH);
    digitalWrite(buzzerPin, HIGH);
    delay(redBlink);
    digitalWrite(redPin, LOW);
    digitalWrite(buzzerPin, LOW);
    delay(redBlink);
  }
  Serial.println("Time is UP!");
  timeChecker = false;
  timestart = 0;
}

beforebuttonval = buttonval;
//Temp
float temp = dht.readTemperature(true);
float humidity= dht.readHumidity();
if(isnan(temp) || isnan(humidity)){
  Serial.println("ERROR!! Unable to read sesor");
} else{
  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.print(" F | Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");
}
tempreadlast = millis();
}
