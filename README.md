# WarHook

## Some DLC for certain Thunder War game

### A brief description of what to do if there are problems:

**- The game crashes right after the injection**

> Most likely one or more of the signatures is out of date. You need to check each signature via Cheat Engine. If it is out of date, find and generate a new one in `IDA-style`. Also an offset for the signature is the `mov` command : 3 bytes (0x3)

**- Game crashes when `ESP` is turned on or when entering battle/training range**

> Broken class structures. Use ReClass.NET x64 and rebuild classes based on current ones from `classes.h` file

Also, for convenience, I added a table Cheat Engine. The names have signatures and addresses for ReClass (change offsets to the actual ones, please)

![ct](https://user-images.githubusercontent.com/84017229/213824826-dba6ead2-ae9d-4499-bb8f-5ccc4f230e25.jpg)
