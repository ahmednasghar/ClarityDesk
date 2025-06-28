int brightnessanalog =A5;
int brightnessval;
int brakeTime = 500; // For reference: 1000 = 1 second
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

//LCD DISPLAY
#include <LiquidCrystal.h>
LiquidCrystal lcd(8, 5, 4, 3, A0, A2);
int newbutton;
int brightnessreaderPin = A1;  


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

//LCD DISPLAY
lcd.begin(16, 2);
lcd.print("Starting System...");
delay(1500);
lcd.clear();



}



void loop() {
//LDR  
brightnessval = analogRead(brightnessanalog); // This allows the variable brightnessval to hold the value of the brightness measured by the A1 analog
Serial.println(brightnessval);
if(brightnessval >= 300){
  digitalWrite(greenled, HIGH);
  delay(brakeTime);
  digitalWrite(greenled, LOW);
  delay(brakeTime);
}
if(brightnessval< 300 && brightnessval>100){
  digitalWrite(yellowled, HIGH);
  delay(brakeTime);
  digitalWrite(yellowled, LOW);
  delay(brakeTime);
}
if(brightnessval<=100){
  digitalWrite(redled, HIGH);
  delay(brakeTime);
  digitalWrite(redled, LOW);
  delay(brakeTime);
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

//LCD DISPLAY
newbutton = analogRead(brightnessreaderPin);
// Convert timer to minutes to seconds
unsigned long timeLeft = (timeChecker) ? (timelength - (millis() - timestart)) / 1000 : 0;
int minutes = timeLeft / 60;
int seconds = timeLeft % 60;

// Refreshs the LCD every loop
lcd.setCursor(0, 0);
lcd.print("Temp:");
lcd.print(temp);
lcd.print((char)223); // Degree symbol
lcd.print("F ");

if (newbutton > 300) {
  lcd.print("HGH");
} else if (newbutton >= 100 && newbutton < 300) {
  lcd.print("MED"); 
} else {
  lcd.print("LOW");
}


lcd.print("Lvl:");
lcd.print(newbutton); 

lcd.setCursor(0, 1);
lcd.print("Timer:");
lcd.print(timeChecker ? "ON " : "OFF");
lcd.print(" ");

if (timeChecker) {
  if (minutes < 10) lcd.print("0");
  lcd.print(minutes);
  lcd.print(":");
  if (seconds < 10) lcd.print("0");
  lcd.print(seconds);
} else {
  lcd.print("       "); // clears the time thats leftover
}
}
