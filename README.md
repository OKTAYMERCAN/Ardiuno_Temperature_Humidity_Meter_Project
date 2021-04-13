# Ardiuno project
Arduino Uno/Nano temperature and Humidity Meter project with DHT22 sensor and Nokia 5110 LCD display (PCD8544)

Changelogs
+ Added basic clock (Must be set time variable, before upload code otherwise time not be correct.)
+ Fixed basic clock hour section, hour section now working.
+ Fixed serial output data.
+ Serial output is default enabled. (if you don't want to serial output then add // to Serial.begin() front.)


Known problems
- No AM/PM mode option. (only 24hr mode)
- Must be set time variable, before upload code otherwise time not be correct.
- if you want to change clock time then must be edit code and reupload to arduino.
- Not synchronize to real time. (No *RTC module, so this way is not be expect perfect.)

*RTC Module: Real time clock module
