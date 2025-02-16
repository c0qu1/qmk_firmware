# Handwired mechanical keyboard EY191

![ey-191_1.jpg](images%2Fey-191_1.jpg)

#### Specs:

* Handwired with 16 and 18 gauge copper wire.
* Wooden sides of case, cut with a jigsaw and sanded. (First time doing this)
* Brass rods for horizontal support of the plates.
* Plates custom cut in aluminum by SendCutSend.
* Proton-C microcontroller running QMK firmware.
* Support for VIA configurator.
* ZealPC Helios silent switches L&F.
* 2 Rotary encoders EC-11 with 21 mm knobs.
* 3 RGB LEDs ws2812 connected as underglow but used as layers indicators.
* Clone (fake) not-gmk Bingsu keycaps (waiting for ePBT Less But Better keycaps set)

This is my first (and probably last) handwired mechanical keyboard. I had been impressed, mesmerized and inspired by numerous handwired keyboards that I've seen online mostly at r/MechanicalKeyboards, r/olkb and the Nibble community. Keyboards like the Saturn60, Grid650, and numerous expensive boards gave me the idea to make my own. Why leave all the fun of designing and making the keyboard to others? :-)

If you are still here, next is a description of how the EY191 was made. I'll try to be as detailed as possible in my descriptions to help anyone else that may want to make their own handwired keyboard, including the QMK firmware and VIA tool.

![keyboard-layout-editor.png](images%2Fkeyboard-layout-editor.png)
http://www.keyboard-layout-editor.com/

The keyboard matrix is at the core of any build. For a handwired build, you'll literally be making-soldering the matrix. But before you can grab the soldering gun, you must design your matrix carefully since your microcontroller decision will depend on the matrix size. The website Keyboard Layout Editor is a great resource to help you design the layout. This is specially necessary if you have a custom layout. You can choose from a list of pre-made and standard layouts, you can start from scratch or choose one and modify it.
When you finish designing your keyboard layout, select 'Download JSON' from the top right green button. You can also save to your Github account and access/modify your layout later. We will use this on the next step to generate our matrix wiring diagram.

![Matrix Diagram Flip - smaller top row.png](images%2FMatrix%20Diagram%20Flip%20-%20smaller%20top%20row.png)
https://kbfirmware.com/

This website is end-of-life but still useful for the purpose of generating a diagram of the matrix wiring. Open the json file that you previously saved, copy all the contents and paste it in the textbox under "Or import from keyboard-layout-editor.com", before pressing 'Import' make sure that you delete the root/outermost square brackets and the first object inside curly brackets.
Ex.
```
[
  {
    "name": "ANSI 65%",
    "switchMount": "cherry",
    "plate": true
  },
  ...here will be all the rows, don't delete
]  ...the last square bracket should be deleted
```
After importing you'll see a diagram of the keyboard layout with lines representing the wiring of rows and columns. You can adjust the number of rows and columns in the matrix and see the wiring change. The rows and columns are going to be the microcontroller IO pins.
The picture shows the flipped diagram (keyboard view from behind) with the rows and columns that represent the matrix (the lines connecting switches vertically and horizontally). Those lines will change depending on the amount of rows and columns in your matrix, this numbers are also directly related to the IO pins in your microcontroller. I used the Proton-C because it has many pins (a Pro Micro has less pins) this allowed me to keep the wiring simpler and be able to connect the rotary encoders and the RGB LEDS.
If you select 'flip', you can use the flipped diagram to wire your keyboard.

https://qmk.fm/proton-c/

https://docs.qmk.fm/#/hand_wire

![messy-work-inprogress.jpg](images%2Fmessy-work-inprogress.jpg)

I used http://builder.swillkb.com/ generate the design files of the plates, then sent them to https://sendcutsend.com/ to cut the plates in aluminum. Cost was about $40 including shipping. Make sure you have an idea of the case that you'll need for the plate or later on could be hard to find a case that matches your custom plate. The website that I used can also generate files to cut an acrylic sandwich case for your keyboard. I had wanted an exposed look for my keyboard, therefore I didn't make or ordered that.
The copper wire used was a combination of 16 and 18 gauge. The thicker and stiffer 16 gauge wire was used for the main rows and columns. The 18 gauge wire was used to make the connections from the rows and columns to the microcontroller. The wires must be stiff to retain the given shape, this is due to the fact that there is no insulation and any accidental touch could bent a wire and cause a short circuit. If your case will provide protection for the wiring, you can go with something like 20 gauge but it is not as stiff so I don't recommend it.
If you are going to lube switches, do it before mounting them on the plate, after you start soldering there is no way to remove a switch. Maybe you can but it will be a lot of work so make sure your switches are ready. Once ready put the switches in and also put the stabilizers and tune them before starting the soldering.

![starting-top-row.jpg](images%2Fstarting-top-row.jpg)

I started on the top row of the main plate, placing the diodes which had been previously looped to fit in one contact leg of a switch. Place and solder the diodes in a full row. Remember that diodes have direction, the black part faces the row wire.

![bending-diodes.jpg](images%2Fbending-diodes.jpg)

After soldering all the diodes in one row, and with all the opposite wire extended and in the picture, place the row wire on top of the switches in the row and bend the legs of the diodes. Put a little solder on the diodes legs and wire to hold them in place. Make sure you have good solder joints or later you could end up with a keyboard suffering from chattering and 'debouncing' it won't help and you'll be force to reflow a difficult joint.

I multimeter is a good tool to make sure your solder joints are ok and there is no shorts.

![rotary_encoders_1.jpg](images%2Frotary_encoders_1.jpg)

The rotary encoders.

![rotary_encoders_bottom.jpg](images%2Frotary_encoders_bottom.jpg)

Bottom view of the rotary encoders. The side with two legs is the push button, there is no polarity but you'll need a diode like any other switch in the matrix. Put the diode in the switch leg that will connect to the row wire. I had to do a special bending of the top plate row wire because the switches and rotary encoders didn't align perfectly as the all switches rows. See a picture of it later on.



Here we have the first columns wires on the main plate. The keyboard layout is staggered (not ortho), therefore the switches in the columns don't align. You must bend a wire that connects the top switch to the bottom switch in the column. Solder this two joints and then cut small pieces of wire to connect the remaining switches in the column to the main longer column wire. See the picture.
A helping hands tool is a must to be able to successfully do this.

https://www.amazon.com/helping-hands/s?k=helping+hands

![columns-1.png](images%2Fcolumns-1.png)

![columns-2.png](images%2Fcolumns-2.png)

Columns...

![helping-hands-1.png](images%2Fhelping-hands-1.png)

Helping hands.

![helping-hands-2.png](images%2Fhelping-hands-2.png)

Helping hands hold the wire while it is soldered, the excess wire is cut after it has been soldered.

![columns-3-all.png](images%2Fcolumns-3-all.png)

All columns done on the main plate.

![naked-behind.png](images%2Fnaked-behind.png)

Naked keyboard from behind. Notice the row wire in the top plate with the rotary encoders. The case that holds the plates is just to pieces of wood cut in an angle with 5 brass rods.

![naked-front-top.png](images%2Fnaked-front-top.png)

Front top view

![naked-bottom.png](images%2Fnaked-bottom.png)

Bottom view, not finished. Missing microcontroller.

![naked-side.png](images%2Fnaked-side.png)

Side view

![side-view-keycaps-and-mcu.png](images%2Fside-view-keycaps-and-mcu.png)

Side view with keycaps and knobs. Proton-C microcontroller.

![top-view-taped-and-rgb-leds.png](images%2Ftop-view-taped-and-rgb-leds.png)

Top view, taped to protect the wood from damage.

RGB LEDs strip and 3 little holes in the top plate.

![top-close-view.png](images%2Ftop-close-view.png)

Close view of the top plate holes for the RGB LEDs. A 1/16 drill bit was used for the LEDs holes. This will keep the light at a minimum, since the angle of the light is directly facing the user face. I ended up putting a cap on the brightness in the software too. This RGB LEDs will be use as layers indicators.

![led-strip-top.png](images%2Fled-strip-top.png)

The LEDs strip contacts were covered with tape to insulate them from the metal plate. The strip was glued to the plate using transparent epoxy.

![led-strip-bottom.png](images%2Fled-strip-bottom.png)

Insulation on the back too.

![arduino-leds-tester.png](images%2Farduino-leds-tester.png)

An Arduino UNO was used to test the RGB LEDs in place before completing the actual wiring to the microcontroller.

![arduino-leds-tester-bottom-view.png](images%2Farduino-leds-tester-bottom-view.png)

Bottom keyboard view of the Arduino UNO testing wiring.

![rgb-leds-layer-indicators-full-brigthness.png](images%2Frgb-leds-layer-indicators-full-brigthness.png)

Lights on! Brightness is set to full. After soldering the microcontroller, top view of the keyboard exposed wiring.

# QMK Firmware

The firmware was created using QMK. I followed the guides in the QMK documentation. Then went through the sections that describe the functionality that I wanted to add to the keyboard: RGB underglow, rotary encoders, audio. I also looked at other keyboards code in the repository to get ideas of how to implement functionality.

```https://github.com/c0qu1/qmk_firmware/tree/master/keyboards/handwired/ey191```

```https://docs.qmk.fm/#/newbs_building_firmware```

![via.png](images%2Fvia.png)

Adding VIA Configurator functionality was a must since I do development work and been able to program the keyboard on the fly is very important.

You'll create the VIA json file using the layout json file from:
http://www.keyboard-layout-editor.com/
But you'll have to export a new json after making modifications to the layout. Instead of having the legends in the layout, you need to add the layout coordinates of row, column.

More details in the VIA documentation:
https://caniusevia.com/docs/specification

A video from MechMerlin explaining how to do this, it helped me a lot:
https://www.youtube.com/watch?v=YXcQnVnsr0I

![bottom-with-mcu.png](images%2Fbottom-with-mcu.png)

Bottom view completed.

![top-view-completed.png](images%2Ftop-view-completed.png)

Top view completed. 

More pictures with other keycaps

![ey-191-retrocast-keycaps.png](images%2Fey-191-retrocast-keycaps.png)

![ey-191-bottom-final.png](images%2Fey-191-bottom-final.png)

Hope you enjoyed this reading, thanks for stopping by.
