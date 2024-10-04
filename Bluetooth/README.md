# Bluetooth Functionality

This section contains instructions and an exercise to learn about how to connect with your board wirelessly through Bluetooth.

---

## Downloading Stuff

I have made premade code for you to download and use on your device. The code is written in Python, so if you don't have it installed, please go to the python download site and install.

[Python 3.12.7 Download](https://www.python.org/downloads/release/python-3127/)

When installing, make sure to install pip as well. This is important as we need pip to install additional modules!.

After installing, open up your terminal and type:
`pip install pyserial`

You can then copy paste (or download from git if you know how) the starter code:

[Python Code](./bluetooth_client.py)

[Arduino Code](./bluetooth_excerise.ino)

## Using the code

You should have 2 pieces of code, one in Python and one in Arduino. 

**__Arduino__**

The Arduino code is what you will use in the Arduino IDE. Its the same process as what we have done beforehand. In the starter code, there are a few things you will need to change.

1. `SerialBT.begin("im smelly");  // Change this name to whatever you like`
    This is the line that turns on Bluetooth on your board. Change the "im smelly" name to whatever else you like. This will be the name of your board when searching for Bluetooth devices.
2. `const int ledPin = 2;  // Pin where the LED is connected`
    This is the pin where the LED will be connected. If you are just using the builtin LED, just use Pin 2.
3. The loop() function is incomplete. You will fill this out when doing the exercise. The code for reading in bluetooth has already been done and stored as `input`. You just need to use the input variable to complete the exercise.

**__Python__**

The Python code is going to be run on your computer, and will allow you to connect to the board wirelessly.
1. Upload the Arduino code first and make sure the board is running. Also make sure that you have changed the Bluetooth name as shown above.
2. Open up your computers Bluetooth settings, and connect to the board.
3. Now we need to figure out what COM port your computer has assigned the Bluetooth connection to. On Windows, open up Device Manager, and under `Ports (COM & LPT)`, you can see all the COM ports. See which one is connected to Bluetooth. For MacOS users [check this link out](https://stackoverflow.com/questions/12254378/how-to-find-the-serial-port-number-on-mac-os-x);
4. In the Python code, change the line at the top that says `bt_address = "COM5"`, and replace it with the correct COM port you found in step 3.
5. You can now run the Python Code and it should successfully connect to the board. You can type in commands into the Python window and it should send them wirelessly. 

## Exercise

Using the starter code, write code to turn on and off the LED using Bluetooth inputs.

A sample solution to this exercise can be found here:

[Solution](./bluetooth_esp.ino)

## Things to Note

Once you have uploaded your code to the board, you don't actually need to have it connected to your laptop, as long as the board is powered and connected via Bluetooth!

However, you still need to have the board plugged into the laptop to reupload code again.