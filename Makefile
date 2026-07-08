default:
	riscv64-elf-gcc \
	-march=rv32imac -mabi=ilp32 \
	-nostartfiles -nostdlib \
	-T linker_stuff/red-v.ld \
	linker_stuff/start.s blink.c -o firmware.elf

	# The "-j .text -j .rodata" ommits the RAM stuff, we only want to flash whats supposed to be flashed.
	riscv64-elf-objcopy -O ihex -j .text -j .rodata firmware.elf firmware.hex

