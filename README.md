# Luis Raul's layout for Corne

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