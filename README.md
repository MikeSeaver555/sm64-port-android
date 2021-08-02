### IMPORTANT 

I did almost nothing. This is a fork of sm64-port-android made it by VDavid003 which it has as starting point the sm64 project made by n64decomp. I just made some little changes according to my preferences, I included code from other people and projects to the VDavid003's one. There are a bunch of clever folks behind all this work, I apologize if I don't mention all of them.

### Who is this aimed for?

This repository is aimed to people who own a Super Mario 64 ROM and want to play it on Android natively. An Android TV with a gamepad should be a good option, I tested it on a Nvidia Shield TV. In my opinion it runs lot of better than the emulation through Mupen64Plus FZ, at least on July 2021. It's recommended to know a little bit about basic linux commands and Android folders structure.

### Features and clarifications:

- This repository is only for Android
- The game runs natively, there is no emulation.
- You must own a Super Mario 64 ROM in .z64 format, I just tried with the US version, so the process is adapted to it.
- It runs at full screen, all characters and scenearios preserve their original aspect ratio, just the viewport will be automatically adapted to the display.
- It's expected to be used with a gamepad with at least one analog stick, this project tries to identify the right controller automatically, if the controller you were expecting to use is not the one working try disconnecting the other ones. If you are using a Nvidia Shield with gamepad, it should work.
- Touch controls are hidden because it's supossed to be playing with a gamepad.
- Game Options menu available after pressing R when you pause the game.
- Cheats menu available pressing L button three times in the Game Options menu, a sound should be played.
- Reset level by pressing L can be enable in cheats menu.
- Reset game and Exit game are in Game Options menu.
- Default keybindings for controller should let you use analog stick and d-pad for movements, if some buttons don't work you can try mapping them through Game Menu > Controls.
- BLJ (Back Long Jump) anywhere can be activated in cheats menu.
- Mode Non-Stop available in cheats menu.
- Editable Savefile with a text editor, there is also a 120 stars saved file included.
- Start button lets you leave the ending scene.
- Optional (but recommended) patch to work a 60 fps.

### Instructions:

The .apk and the necessary files will be built using Android.
You will need install Termux for this process but don't download it from Play Store, that version is outdated, take it from [f-droid](https://f-droid.org/en/packages/com.termux/). Once Termux is installed I suggest you to connect a keyboard and follow these steps:

**Install dependencies:**
```
pkg install git wget make python getconf zip apksigner clang
```

**Clone this repository:**
```
git clone https://github.com/MikeSeaver555/sm64-port-nvidia-shield
cd sm64-port-nvidia-shield/
```

**Copy baserom:**

Your Super Mario 64 ROM must be a .z64 format. This process is for the US version.
Grant permission to Termux to be able to write in your storage system and then copy the file with the indicated name.

```
termux-setup-storage
cp /sdcard/path/to/your/rom.z64 ./baserom.us.z64
```

**Get SDL includes:**
```
./getSDL.sh
```

**Apply 60 fps patch (optionally)**
```
git apply enhancements/60fps_ex.patch
```

**Build:**
```
# if you have more cores available, you can increase the --jobs parameter
# Take in consideration that you can run out of RAM during the process even with Nvidia Shield, so I recommend using 2

make --jobs 2
```

**Adapt the following commands according to your preferences:**

Copy the resulting files into a folder you can access later with a file browser.
```
mkdir -p ../storage/shared/SM64Android/com.vdavid003.sm64port/files
cp -f build/us_pc/sm64.us.f3dex2e.apk ../storage/shared/SM64Android/
cp -f build/us_pc/res/base.zip ../storage/shared/SM64Android/com.vdavid003.sm64port/files/
cp -f savefile/sm64_save_file_3.sav ../storage/shared/SM64Android/com.vdavid003.sm64port/files/
```

**Last Steps:**

Use a file manager and access to SM64Android folder you created in the last step.
Copy the folder com.vdavid003.sm64port inside your Android/data folder
Install the .apk using a file browser and enjoy it.
