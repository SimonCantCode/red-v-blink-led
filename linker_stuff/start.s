.globl _start
_start:
	# Initialize stack pointer
    la sp, stack_top
    jal main

# If main returns, halt.
1: j 1b

