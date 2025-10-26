# Swoop

![Swoop](https://i.imgur.com/mMlmEsdh.jpg)

*The Swoopiest is an open source split keyboard. The crossbreed between a Swoop and a Kyria.*

* Keyboard Maintainer: [Diaffractus](https://github.com/miguelroldao)
* Hardware Availability: [*Swoopiest Repository*](https://github.com/miguelroldao/swoopiest)

Flash the default keymap by running the following command (after setting up your build environment):

    qmk flash -kb diaffractus/swoopiest -km default

To flash a Pro Micro board with a RP2040 use:

    qmk flash -kb diaffractus/swoopiest -km defult -e CONVERT_TO=rp2040_ce
    
Try out the developer's keymap with:

    qmk flash -kb diaffractus/swoopiest -km roldao

*Note:* To flash the keyboard, you must enter the bootloader of you keyboard (it could be automatic, depending on the ProMicro used). Some possible ways to enter the bootloader are:
* **Dedicated bootloader button**: Press the boot button if your ProMicro has one before plugging it via USB to enter the bootloader.
* **Physical reset button**: Double tap the small button on the upper side of the PCB - you may have pads you must short instead
* **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available on the programmed keymap.

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) for more information. Brand new to QMK? Start with the [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).
