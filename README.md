# Corne layout

Main layer
![Imgur](https://i.imgur.com/SaI0s8e.jpg)

Nums layer
![Imgur](https://i.imgur.com/yBR0Kz1.jpg)

Nav layer
![Imgur](https://i.imgur.com/cZrwUfd.jpg)

## Gettings started

[Install QMK](https://beta.docs.qmk.fm/tutorial/newbs_getting_started)

### Flashing the split keyboard

Clone repo in `~/qmk_firmware/keyboards/crkbd/keymaps` folder, rename the repository folder (`corne-layout`) to `wochap`.

```sh
$ cd ~/qmk_firmware/keyboards/crkbd/keymaps
$ git clone git@github.com:wochap/corne-layout.git wochap
```

Every time you make a change affecting the OLED screen or RGB, you must flash both sides (the `jack TRRS cable` must be connected), If you just modified the layout, then you need to flash the master (left side) only.

#### First time

1. Disconnect `jack TRRS cable` and the keyboard (USB-C)
1. Left keyboard
  1. Run the command
  1. Connect the left keyboard, and press the reset button twice
  1. Once it finished, disconnect the left keyboard.
1. Right keyboard
  1. Run the command
  1. Connect the right keyboard, and press the reset button twice
  1. Once it finished, disconnect the right keyboard.
1. Connect the `jack TRRS cable`, then the USB-C cable to the left side
1. Run the command
1. Press the reset button of the left side twice
1. Done

#### Second time and on

1. Connect `jack TRRS cable`
1. Connect the left side (USB-C) to the PC
1. Run the command
1. Press the master (left side) keyboard reset button twice
1. Done

```sh
# command ⬇️
$ qmk compile -kb crkbd/rev1 -km wochap:flash
```

## Files

```
.
├── assets               # http://www.keyboard-layout-editor.com/ json files
├── config.h             #
├── glcdfont.c           # oled screen font
├── keymap.c             # here we define our layouts
├── README.md            # this file
└── rules.mk             # environment variables?
```
