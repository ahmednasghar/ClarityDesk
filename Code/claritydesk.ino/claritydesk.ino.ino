// Setting up variables for the Brightness (LDR) Functionality
int brightnessanalog = A1;
int brightnesslvl;
int redled;
int yellowled;
int greenled;
int breaktime=500; //For reference 1000 is 1 second




void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);

// LDR
pinMode(brightnessanalog,INPUT);
pinMode(redled,OUTPUT);
pinMode(yellowled,OUTPUT);
pinMode(greenled,OUTPUT);


}
// This lets us make a function so we dont repeat ourself a million times
void LedBlinker(int ledlight){
  digitalWrite(ledlight,HIGH);
  delay(breaktime);
  digitalWrite(ledlight,LOW);
  delay(breaktime);
}
void loop() {
//LDR  
brightnesslvl = analogRead(brightnessanalog); // This allows the variable brightnesslvl to hold the value of the brightness measured by the A1 analog
Serial.println(brightnesslvl); //Allows us to see the real time brightness of the environment
delay(breaktime); 
if(brightnesslvl>=500){
  LedBlinker(greenled);
}
if(brightnesslvl>=500){
  LedBlinker(yellowled);
}
if(brightnesslvl>=500){
  LedBlinker(redled);
}