# corne-layout

Hello there!
There are some things that you need to know before start playing with your new Corne Keyboard:

* You'll need to install QMK software:
  * <a href="https://beta.docs.qmk.fm/tutorial/newbs_getting_started" target="blank">Here</a> are the instructions depending on your OS to install it.
  * Then, you have to add all this folder in a path like mine: `C:\Users\luis-\qmk_firmware\keyboards\crkbd\keymaps\myCorneKeyboardLayout`
* At this point you're ready to go! So, here are some usefull links:
  * <a href="https://config.qmk.fm/#/crkbd/rev1/LAYOUT_split_3x6_3" target="blank">This link</a> can help you to know the 'name' of each key that you'll probably use.
  * These 4 tutorial videos are very long, but have a lot of information (all in spanish), have carefull with some useless steps there, I recommend to see everything before starting, although it really isn't mandatory because I'm giving you the necessary steps, some more information is always useful...
    * <a href="https://youtu.be/fvP5ws_I0HU" target="blank">Part 1</a>
    * <a href="https://youtu.be/xH1Ali0g7w8" target="blank">Part 2</a>
    * <a href="https://youtu.be/mz8WG5e--jA" target="blank">Part 3</a>
    * <a href="https://youtu.be/vA32gDmvllA" target="blank">Part 4</a>
* `qmk compile -kb crkbd -km myCorneKeyboardLayout:flash` <- this is the line I use in QMK MSYS to compile and updload my layout in my keyboard, when it finish, you have to push the reset button in the PCB or press the key between escape and enter but in the last layer.

That's all, now you can edit every layer, add or remove fuctionalities 😉

Little disclaimer:
The Dvorak layer is in beta phase, if you enter here, you'll need to unplug and plug the keyboard from the pc to return to the other layers.

## Flash keyboard

Clone repo in `keyboards/crkbd/keymaps` folder.

```sh
$ cd keyboards/crkbd/keymaps
$ git clone git@github.com:wochap/corne-layout.git wochap
```

### First time

1. Disconnect `jack TRRS cable` and the keyboard (USB-C)
1. Left keyboard
  1. Run the command
  1. Connect the left keyboard, and press the reset button twice
  1. Once it finished, disconnect the left keyboard.
1. Right keyboard
  1. Run the command
  1. Connect the right keyboard, and press the reset button twice
  1. Once it finished, disconnect the right keyboard.

### Second time and on

1. Connect `jack TRRS cable`
1. Disconnect the keyboard (USB-C) to the PC 
1. Run the command
1. Connect the keyboard (USB-C)

```sh
# command
$ qmk compile -kb crkbd/rev1 -km wochap:flash
```

## Files

```
.
├── config.h             # 
├── glcdfont.c           # oled screen related (looks like it is not being used)
├── keymap.c             # here we define our layouts
├── README.md            # this file
└── rules.mk             # environment variables?
```