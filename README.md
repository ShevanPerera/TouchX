Your GitHub repository is going to look very professional with these files. Since you have everything split into individual files (Code, Images, etc.), here is a clean, structured **README.md** that ties everything together for your **ShevanTech** portfolio.

***

# 🤖 Interactive OLED Touch Robot (Obstacle Avoidance)
### A Project by **ShevanTech Robotics**

This repository contains the full source code, hardware configuration, and logic for an interactive robot that combines emotive visual feedback with autonomous navigation.

## 🚀 Project Overview
This robot is designed to be more than just a machine; it has a "personality." Using an OLED display and the `RoboEyes` library, it reacts to human touch while using ultrasonic sensors to navigate its environment without crashing.

### Key Features:
* **Interactive Moods:** Changes facial expressions based on touch sensor input.
* **Autonomous Navigation:** Real-time obstacle avoidance using ultrasonic distance measuring.
* **OLED Feedback:** Smooth eye animations and blinking.
* **Open Source:** Full code provided for customization and hardware hacking.

## 🛠️ Components List
* **Microcontroller:** Arduino Uno
* **Display:** SSD1306 128x64 OLED (I2C)
* **Sensors:** HC-SR04 Ultrasonic Sensor, Digital Touch Sensor
* **Actuators:** DC Motors + L298N/L293D Motor Driver
* **Chassis:** Custom Robot Frame
* **Power:** 7.4V - 9V Battery Source

## 📂 Repository Structure
* `OLED_Robot.ino` - The primary Arduino source code.
* `README.md` - Project documentation (this file).
* `/Images` - Highly realistic renders of the 3D-printed components and the BMW M4 test model.
* `/Docs` - Wiring diagrams and logic explanations.

## ⚙️ How to Customize
I have designed the code to be easily modified:
1.  **Change Moods:** Adjust the `roboEyes.setMood()` calls in the loop to switch between `HAPPY`, `ANGRY`, or `TIRED`.
2.  **Sensitivity:** Change the `distance < 20` variable to increase or decrease the robot's reaction range.
3.  **Animations:** Use `roboEyes.anim_confused()` to trigger a shaking animation when the robot hits a dead end.

## 💡 Technical Tip
**For the best performance:** Always ensure `roboEyes.update()` is called at the top of your loop. Avoid using long `delay()` functions, as they will "freeze" the eye animations. Instead, use a non-blocking timer logic for complex movements.

***

### 🔗 Connect with ShevanTech 
If you found this project useful, consider following the brand for more engineering and robotics content:
* **YouTube:** https://www.youtube.com/@ShevanTech
 

*To see useful videos like this, subscribe and tap the bell.* 
