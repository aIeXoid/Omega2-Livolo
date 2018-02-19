### Simple console command line util for using Livolo switches with Onion Omega2 
![omega2 with RF transmitter](https://raw.githubusercontent.com/aIeXoid/Omega2-Livolo/master/images/Omega2-Livolo.jpg)
Ported from [LamPI-3.x](https://github.com/platenspeler/LamPI-3.x/tree/master/transmitters/livolo)

## Prerequisites
- Omega2(+)
- Compiled binary requires firmware **0.1.10 b160** (you may be able to compile from source for older firmware as well)
(See [Updating the Omega2](https://docs.onion.io/omega2-docs/using-the-omega-updating.html) to check or update firmware)

## Install
```bash
$ wget https://github.com/aIeXoid/Omega2-Livolo/raw/master/bin/livolo
$ chmod +x livolo
$ mv livolo /bin/livolo
```

## How to use
```bash
usage: livolo -p 11 -g 6400 -n 0 -b 460 -l 230 -s 50

Settings:
                ; This setting will affect other timing settings as well
-b              ; Start pulse time in uSec
-g              ; ID of Remote
-h              ; Show this help
-l              ; Long pulse time in uSec
-n              ; Key code of Remote
-p              ; Transmitter pin (3 by default)
-r              ; Repeats per train pulse time
-s              ; Short pulse time in uSec
-t              ; Loops
-v              ; Verbose, will output more information about the received codes

Key codes #1: 0, #2: 96, #3: 120, #4: 24, #5: 80, #6: 48, #7: 108, #8: 12, #9: 72; #10: 40, #OFF: 106
Real remote IDs: 6400; 19303; 23783
Tested "virtual" remote IDs: 10550; 8500; 7400
```
## Example:
```bash
$ livolo -p 11 -g 6400 -n 0 -b 460 -l 230 -s 50
```
## Known Issues
sched_setscheduler returns an error.  Because of this delay introduced into the parameters do not coincide with the real

## Cross compile env used:
```bash
$ git clone https://github.com/aIeXoid/Omega2-Livolo.git livolo
$ docker run -it --name omega2-sdk-app -v livolo:/remote jlcs/omega2-sdk bash
$ cd /remote
$ make
```
