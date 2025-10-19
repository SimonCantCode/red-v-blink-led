/*
 * Blink led on the sparkfun redboard-v in c, no libraries.
 * Thanks to ChatGPT for help to learn this stuff.
 * There is almost no official documentation, i dont understand
 * how they've mannaged to stay in buisness.
 * */

#define GPIO_BASE_ADDR			0x10012000UL // Refference manual page 22. UL = unsigned long, best practice to specify.
#define GPIO_INPUT_EN_OFFSET	0x04 // page 76
#define GPIO_OUTPUT_EN_OFFSET	0x08 // page 76
#define GPIO_OUTPUT_VAL_OFFSET	0x0C // page 76
#define GPIO_IOF_EN_OFFSET		0x38 // Not in the refference manual for some dumb reason.
#define PIN						5 // Built in LED. Couln't fint any damn schematic for it though.

// Has to be volatile to prevent "optimisation"
typedef unsigned int uint32_t; // To avoid needing stdint.h
volatile uint32_t* const GPIO_INPUT_EN		= (volatile uint32_t*)(GPIO_BASE_ADDR + GPIO_INPUT_EN_OFFSET);
volatile uint32_t* const GPIO_OUTPUT_EN		= (volatile uint32_t*)(GPIO_BASE_ADDR + GPIO_OUTPUT_EN_OFFSET);
volatile uint32_t* const GPIO_OUTPUT_VAL	= (volatile uint32_t*)(GPIO_BASE_ADDR + GPIO_OUTPUT_VAL_OFFSET);
volatile uint32_t* const GPIO_IOF_EN		= (volatile uint32_t*)(GPIO_BASE_ADDR + GPIO_IOF_EN_OFFSET);
// const to force it in flash instead of ram, we dont have .data in linker file.

// Low effort delay function
void delay(unsigned int cycles) {
	while(cycles--) {
		asm volatile ("nop"); // Waits a clock cycle 
	}
	return;
}

int main() {
	// Diasble IOF to use pin as regular GPIO, dw, idk what that means either.
	*GPIO_IOF_EN &= ~(1 << PIN);

	// Disable input for pin
	*GPIO_INPUT_EN &= ~(1 << PIN);

	// Enable output for pin
	*GPIO_OUTPUT_EN |= (1 << PIN); 

	while(1) {
		// Turn on led
		*GPIO_OUTPUT_VAL |= (1 << PIN);
		delay(1000000);

		// Turn off led
		*GPIO_OUTPUT_VAL &= ~(1 << PIN);
		delay(1000000);
	}
	return 0; // Idk why i included this tbh, it will never run probably lol.
}
