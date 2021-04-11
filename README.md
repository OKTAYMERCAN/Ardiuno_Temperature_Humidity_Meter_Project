# Ardiuno project
Arduino Uno/Nano temperature and Humidity Meter project with DHT22 sensor and Nokia 5110 LCD display (PCD8544)

Changelogs
+ Added basic clock (Must be set time variable, before upload code otherwise time not be correct.)
+ Added clock serial output (You can see on serial monitor.)

Note: All serial output is disabled default. You must remove this // from serial.begin() command.


Known problems
- No AM/PM for now.
- Clock is not working correct. hours section is not work.
- Not synchronize to real time. (No *RTC module, so this way is not be expect perfect.)

*RTC Module: Real time clock module
