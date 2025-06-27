# ClarityDesk
Smart Arduino desk assistant for environment + productivity

What It Does

- Tracks temperature, humidity, and room brightness in real-time
- Alerts you when your workspace gets too dark, too hot, or too humid
- Includes a 25-minute focus timer with a buzzer and LED alert when your session ends
- Shows live updates and alerts on a 16x2 LCD display
- Controlled with a couple of push buttons, no app needed

## Parts Used

Here's a list of everything I used to build ClarityDesk:

- **Arduino Uno** : the main microcontroller
- **Breadboard + jumper wires** : to build and connect the circuit
- **RGB LED** : shows system status (e.g., green = good, red = too hot)
- **220Ω resistors** : for limiting current to the RGB LED
- **LDR (photoresistor)** : measures how bright the room is
- **10kΩ resistor** : used with the LDR for voltage division
- **DHT11 sensor** : detects temperature and humidity
- **16x2 LCD display** (with or without I2C adapter) : shows the data and timer
- **Potentiometer** : controls contrast on the LCD if you're not using I2C
- **Push buttons** (2 or 3) : to start or reset the timer
- **Passive buzzer** : provides audio alerts

Most of these parts are included in common Arduino kits. I bought the DHT11 separately online.

## How It Works

When you power it on, ClarityDesk displays current temperature, humidity, and light level on the screen.  
You can press a button to start a 25-minute focus session. If the room is too hot, humid, or dark, the RGB LED lights up in red or yellow, and the buzzer gives a warning beep.  
When the timer ends, the system alerts you that it's time for a break.