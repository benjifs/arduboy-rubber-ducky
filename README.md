# [Arduboy Rubber Ducky](http://benji.dog/projects/arduboy-rubber-ducky)

by [Benji Encalada](http://benji.dog) | [@benjifs](http://twitter.com/benjifs)

## Overview
This is a simple application to manage and run [DuckyScript payloads](https://github.com/hak5darren/USB-Rubber-Ducky/wiki/Payloads) for HID Attacks from your Arduboy. This project was inspired by the [USB Rubber Ducky](https://hakshop.com/products/usb-rubber-ducky-deluxe) with help from [Dckuino.js](https://github.com/Thecakeisgit/Dckuino.js) for translating DuckyScript payloads to Arduino.

## Usage
After you've uploaded the Arduboy Rubber Ducky code to your Arduboy you should see a rubber ducky icon on the screen. At this point you should enter the [Konami Code](https://en.wikipedia.org/wiki/Konami_Code) to get access to the main menu which shows the available payloads. You can then choose one of the available payloads from the menu and watch it run on your computer.

In order to add your own payloads you will need to convert them from DuckyScript to Arduino. You can do this by using [Dckuino.js](https://github.com/Thecakeisgit/Dckuino.js) (You can also go [here](http://benji.dog/ducky)). After you have converted your payload, you should copy everything that is under the `setup` function into your own function in the `ducky.h` file like in the examples. After that just scroll to the bottom of that file and make sure that you've added the function name and a label to properly show this on the menu.

You can remove the Konami Code functionality by changing `bool konami` in the `ArduboyRubberDucky.ino` file to false. I only added this for fun.

## TODO
- Improve speed at which payloads run.
- Compare performance to the [USB Rubber Ducky](https://hakshop.com/products/usb-rubber-ducky-deluxe).

## Questions
Feel free to contact me with any questions you may have.

