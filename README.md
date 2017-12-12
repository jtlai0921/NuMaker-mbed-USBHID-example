# Example for USB HID raw data transfer

Clone of [USBHID](https://os.mbed.com/cookbook/USBHID-bindings-),
this example demonstrates USB HID raw data transfer on Nuvoton Mbed-enabled boards.

## Supported platforms
- [NuMaker-PFM-NUC472](https://developer.mbed.org/platforms/Nuvoton-NUC472/)
- [NuMaker-PFM-M453](https://developer.mbed.org/platforms/Nuvoton-M453/)
- [NuMaker-PFM-M487](https://developer.mbed.org/platforms/NUMAKER-PFM-M487/)

## Software requirement
- [python 2.7](https://www.python.org/downloads/)
- [Mbed CLI](https://github.com/ARMmbed/mbed-cli)
- [pywinusb](https://github.com/rene-aguirre/pywinusb)
- [Serial port monitor](https://os.mbed.com/handbook/SerialPC#host-interface-and-terminal-applications)

## Execution
To verify this USB example, we need programs running on device/host ends to communicate with each other.
For device end, we take the **NuMaker-PFM-NUC472** board.
For host end, we just provide Python script on Windows.

### Build Mbed program with Mbed CLI
Mbed USB device library is not released yet, so we cannot compile it with [Mbed Online Compiler](https://os.mbed.com/compiler/).
Instead, we use Mbed CLI.
To compile with USB device support, we need to specify USB library explicitly:

```mbed compile --source .  --source mbed-os/features/unsupported/USBDevice -m NUMAKER_PFM_NUC472 -t ARM```

After compiling is finished, you'll get **BUILD/NUMAKER_PFM_NUC472/ARM NuMaker-mbed-USBHID-example.bin**.

### Flash Mbed program
Connect the **NuMaker-PFM-NUC472** board (USB socket on the right side) to Windows with one USB cable.
You would see MBED drive appear on Windows File Browser.
Drag-n-drop the program onto this drive for flashing it.

### Run Mbed program on device
Run the program by pressing **RESET** button on the **NuMaker-PFM-NUC472** board.
Connect the board (USB socket on the up side) to Windows with another USB cable.
You would see a new USB HID device appear on Windows Device Manager.

### Run Python script on Windows
The repository includes a python script ```tools/win_usbhid.py``` to test with the example.
On Windows CLI console, change CWD to this repository and run:

```python tools\winusbhid.py```

### Execution result
If everythong goes well, you would see received data on your Windows CLI console:
```
Mbed detected
recv:  [0, 38, 142, 7, 4, 216, 81, 117, 163]
recv:  [0, 254, 47, 255, 231, 68, 56, 161, 215]
recv:  [0, 244, 244, 144, 252, 67, 224, 40, 125]
recv:  [0, 138, 50, 184, 185, 93, 105, 168, 102]
recv:  [0, 46, 107, 96, 52, 37, 186, 180, 132]
recv:  [0, 59, 199, 39, 218, 25, 73, 215, 106]
recv:  [0, 70, 126, 192, 228, 173, 178, 87, 140]
recv:  [0, 188, 114, 100, 12, 118, 47, 87, 130]
recv:  [0, 106, 198, 14, 30, 81, 234, 174, 94]
recv:  [0, 58, 14, 188, 39, 141, 218, 212, 22]
recv:  [0, 238, 42, 29, 105, 223, 215, 189, 176]
recv:  [0, 213, 38, 66, 67, 11, 158, 50, 153]
recv:  [0, 1, 53, 150, 64, 214, 177, 62, 92]
recv:  [0, 108, 234, 1, 22, 145, 46, 73, 108]
recv:  [0, 71, 138, 78, 185, 58, 245, 180, 3]
recv:  [0, 199, 67, 180, 145, 192, 95, 156, 150]
```
And if your have terminal program open and configure it to 9600/8-N-1, you would see:
```
recv: 92 200 56 136 113 184 59 211 
recv: 224 241 187 203 125 69 53 229 
recv: 241 39 33 70 5 61 84 247 
recv: 247 176 26 4 88 176 51 172 
recv: 122 115 30 251 181 59 113 194 
recv: 30 0 34 138 76 112 157 203 
recv: 127 34 98 137 67 168 178 224 
recv: 26 121 54 229 94 203 15 65 
recv: 61 7 224 162 192 194 186 105 
recv: 162 224 11 117 124 2 217 211 
recv: 122 133 216 148 126 162 183 237 
recv: 138 178 2 91 70 240 82 105 
```
