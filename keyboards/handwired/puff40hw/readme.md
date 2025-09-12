# puff40hw Handwired QMK keyboard

![puff40hw](docs/IMG_2979.JPG)

*A short description of the keyboard/project*

* Keyboard Maintainer: [c0qu1](https://github.com/c0qu1)
* Hardware Supported: [Sea-Picro](https://github.com/joshajohnson/sea-picro#readme)
* Hardware Availability: [Aliexpress](https://www.aliexpress.us/w/wholesale-puff40.html?spm=a2g0o.home.search.0)
* [More pictures](docs/more_pics.md)

Make example for this keyboard (after setting up your build environment):

    make puff40hw:default

Flashing example for this keyboard:

    make puff40hw:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (usually the top left key or Escape) and plug in the keyboard
* **Physical reset button**: Briefly press the button on the back of the PCB - some may have pads you must short instead
* **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available
