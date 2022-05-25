# ey191

![ey191](https://i.imgur.com/iUtnWIp.jpeg)
![ey191](https://i.imgur.com/DuFs3nP.jpeg)

*A short description of the keyboard/project*

* Keyboard Maintainer: [Juan Rivera](https://github.com/c0qu1)
* Hardware Supported: *No PCB since it is handwired, it uses the Proton-C microcontroller*
* Hardware Availability: *https://olkb.com/products/qmk-proton-c-rev-2*

Make example for this keyboard (after setting up your build environment):

    make ey191:via

Flashing example for this keyboard:

    make ey191:via:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (usually the top left key or Escape) and plug in the keyboard
* **Physical reset button**: Briefly press the button on the back of the PCB - some may have pads you must short instead
* **Keycode in layout**: Press the key mapped to `RESET` if it is available
