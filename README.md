# Red-v blink LED

Blinks the built-in LED on the SparkFun RED-V RedBoard without libraries. 

![](example.gif)

The linker script and start.s file was borrowed from [here](https://github.com/lowleveltv/riscv-sparkfun-hello). It works well enough for this project but has to be modified if you wish to have non constant global variables etc. Right now data is stored on the stack. I am still very new to linker scripts.

I plan to possibly make a youtube video explaning the code in the future since getting this to work was nowhere near trivial, even though the c code is fairly simple. This has taken way more hours than i thought it would 😭
