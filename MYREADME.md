# My instructions for flashing my corne

First, follow the QMK instructions (https://docs.qmk.fm/newbs_getting_started)

Press the RESET button and then run the following command to flash each half:
`avrdude -p m32u4 -c avr109 -P /dev/ttyACM0 -U flash:w:foostan_cornelius_default.hex:i`
