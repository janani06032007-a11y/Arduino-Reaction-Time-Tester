# Arduino-Reaction-Time-Tester
An Arduino-based reaction time game that measures response speed using an LED, push button, and OLED display
🎮 Arduino Reaction Time Tester

An Arduino-based Reaction Time Tester Game that measures how quickly a user responds when an LED turns ON. The reaction time is calculated in milliseconds and displayed on an OLED screen.

🎯 Project Overview

The Arduino waits for a random amount of time and then turns ON the LED. The user must press the push button as quickly as possible. The Arduino calculates the time between the LED turning ON and the button press.

Lower reaction time = Faster response ⚡

🔧 Components Used

- Arduino UNO
- LED
- Push Button
- OLED Display (I2C)
- Resistor
- Jumper Wires

⚙️ Working

Start
  ↓
Press Button
  ↓
Random Delay
  ↓
LED ON 💡
  ↓
User Presses Button
  ↓
Calculate Reaction Time
  ↓
Display Result on OLED

The "millis()" function is used to measure the elapsed time.

reactionTime = millis() - ledOnTime;

The project also keeps track of the attempt number and the player's best reaction time.

🧠 Concepts Learned

- Arduino programming
- Digital input and output
- Push-button interfacing
- LED control
- OLED/I2C interfacing
- "millis()" for time measurement
- "random()" for random delay
- "INPUT_PULLUP"
- Basic embedded-system logic

💻 Simulation

The project was designed and tested using Wokwi Simulator.

Wokwi Project:
Add your Wokwi project link here.

🚀 Future Improvements

- Add buzzer sound feedback
- Add multiple-player mode
- Store high scores
- Add Bluetooth connectivity
- Build a physical hardware version

👩‍💻 Author

Janani
Electronics and Communication Engineering (ECE) Student
