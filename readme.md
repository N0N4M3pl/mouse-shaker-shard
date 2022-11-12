# mouse-shaker-shard

Shard: Mouse driver with shaker code.  
Microcontroller: Digispark ATTINY85 USB

version: 1.0.0

## How to

1. Open `/mouse-shaker-shard/mouse-shaker-shard.ino` in Arduino IDE
2. Compile and upload into `Digispark ATTINY85 USB`
3. Print case using 3d model files from `/print-case`
4. Insert `Digispark ATTINY85 USB` into case - this is shard
5. Insert shard into computer USB A port
6. Wait 30 minutes
7. Mouse will start shake with 1 minutes breaks

## Code dependencies

- [DigisparkMouse](https://github.com/digistump/DigisparkArduinoIntegration/blob/master/libraries/DigisparkMouse/DigiMouse.h)
- [RAMP](https://github.com/siteswapjuggler/RAMP)