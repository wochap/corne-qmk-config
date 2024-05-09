## Corne QMK config

### Layers

ColemakDH
![Imgur](https://i.imgur.com/1igKPoQ.jpg)

Querty
![Imgur](https://i.imgur.com/OMmmfWw.png)

Num
![Imgur](https://i.imgur.com/70txcxD.png)

Nav
![Imgur](https://i.imgur.com/YICzLky.png)

> Images generated with http://www.keyboard-layout-editor.com/, use the files in `assets` folder

### Flashing

Every time you make a change affecting the OLED screen or RGB, you must flash both sides (the `jack TRRS cable` must be **connected**). If you just modified the layout, then you need to flash the master (left side) only.

```sh
$ cd ~/qmk_firmware

# command is
$ sh util/docker_build.sh crkbd/rev1:wochap:flash
# or if you setup your dev environment
$ qmk compile -kb crkbd/rev1 -km wochap
$ qmk flash -kb crkbd/rev1 -km wochap
```

#### Flashing both sides

1. Disconnect `jack TRRS cable` and both sides from the computer
1. Left side
   1. Run the `command`
   1. Connect the left side to the computer, and press the reset button twice
   1. Once it finished, disconnect the left side.
1. Right side
   1. Run the `command`
   1. Connect the right side to the computer, and press the reset button twice
   1. Once it finished, disconnect the right side.
1. Connect the `jack TRRS cable`, then only connect the left side to the computer
1. Run the `command`
1. Press the reset button of the left side twice

#### Flashing only master (left side)

1. Connect the `jack TRRS cable`, then only connect the left side to the computer
1. Run the `command`
1. Press reset button of the master (left side) twice

### Development

1. Setup your [dev environment](https://docs.qmk.fm/#/newbs_getting_started)

   ```sh
   $ python3 -m pip install qmk

   # run one the following commands
   $ qmk setup
   # or
   $ git clone --recurse-submodules --depth 1 https://github.com/qmk/qmk_firmware.git ~/qmk_firmware
   # both do the same, but the second should be faster
   ```

1. Clone `corne-qmk-config` git repository
1. Symlink the folder `config` in `corne-qmk-config` to `~/qmk_firmware/keyboards/crkbd/keymaps/wochap`
   ```sh
   $ ln -s $(pwd)/config ~/qmk_firmware/keyboards/crkbd/keymaps/wochap
   ```
