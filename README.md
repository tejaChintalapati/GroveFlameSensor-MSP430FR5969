# FlameSensor-MSP430FR5969

Interfaces Grove Flame Sensor with MSP430FR5969
Sensor can be bought from www.seeedstudio.com/depot/Grove-Flame-Sensor-p-1450.html
Sensor WiKi: www.seeedstudio.com/wiki/Grove_-_Flame_Sensor

# Working:

 * Grove Flame Sensor outputs 0 if flame is detected and 1 if flame is not detected.
 * MSP will sleep in LPM4 untill flame is detected. High to low interrupt on pin will wake the MCU from sleep mode. MCU sets
LED and Buzzer on(If buzzer is present and is configured in code) and goes to LPM4 untill button press is detected.
 * Once button is pressed, MCU switches off Buzzer and LED and starts monitoring for fire again.
 
## P.S: 
Don't like to play with fire? Flash your phone's flashlight at the sensor and it will mistake flashlight as fire
