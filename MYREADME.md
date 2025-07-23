# My instructions for flashing my corne

First, follow the QMK instructions (https://docs.qmk.fm/newbs_getting_started)

Press the RESET button and then run the following command to flash each half:
`avrdude -p m32u4 -c avr109 -P /dev/ttyACM0 -U flash:w:foostan_cornelius_default.hex:i`

Also possible through qmk:
`qmk flash -kb crkbd/rev1 -km sym-layer -bl avrdude`

To compile/flash for rp2040:
`qmk flash -kb crkbd/rev1 -km sym-layer -e CONVERT_TO=rp2040_ce`
This expects the bootloader mode to be active. This can be done by pressing the boot button upon power-on.
After the first flash, programming mode can be achieved by tapping the reset button twice.
