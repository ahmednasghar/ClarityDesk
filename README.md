# ClarityDesk

ClarityDesk is a personal passion project I built during Summer 2025. As a student, I often found myself wanting a simple desk tool that could help me stay focused and manage my time better. That led to the idea of creating something small, useful, and entirely my own.

This project is where I combined my growing interest in electronics with my passion for CAD and 3D printing. Although it’s not a very large or complex project, it’s meaningful to me because it brings together both the electrical and mechanical sides of engineering in one build.

ClarityDesk tracks room brightness, temperature, and includes a timer for focused work sessions. It runs off a portable charger, so it doesn’t need to be connected to a computer.

## Features
- Brightness detection using an LDR (photoresistor)  
  - Green LED for bright conditions  
  - Yellow for medium  
  - Red for dark  

- Pushbutton-activated timer (set to 25 minutes, currently testing with 15 seconds)  
  - Buzzer + red LED alerts when time is up  

- Temperature and humidity tracking using a DHT11 sensor  
  - All info is displayed on a 16x2 LCD in real time  

## What I Used
- Arduino Uno-compatible board  
- Breadboard and jumper wires  
- LDR (light sensor)  
- DHT11 temperature + humidity sensor  
- Passive buzzer  
- Pushbutton  
- 16x2 LCD display  
- Red, yellow, green LEDs  
- Portable power bank

## What I Learned
This was one of my first full projects that brought together multiple components and disciplines. I learned how to work with analog and digital inputs, use `millis()` for timing without delays, and format information on an LCD screen. It also gave me experience organizing code and thinking about how electrical components would fit into a future 3D design. I made a lot of mistakes and fixed them as I went, which helped me understand how to approach real-world debugging and iteration.

## Next Steps
I’m currently sketching a custom 3D-printed enclosure to hold everything together neatly. Once that’s done, I’d like to clean up the code and possibly add features like a real-time clock or data logging.
