// Lab13.c
// Runs on LM4F120 or TM4C123
// Use SysTick interrupts to implement a 4-key digital piano
// edX Lab 13 
// Talal Javed Qadri
// August 5, 2014
// Port B bits 3-0 have the 4-bit DAC
// Port E bits 3-0 have 4 piano keys


// 1.Pre-processorr Directives Section
#include "tm4c123gh6pm.h"
#include "Sound.h"
#include "Piano.h"
#include "TExaS.h"

//define period for the four needed tones
//Points per 1 wave length = 32
//Bus clock frequency = 800 MHz
//Bus clock frequency = 1/800 MHz = 12.5ns
//Fruequency of wave = 1/Period of wave = 1/(12.5ns*period(values defined below)*32)
#define C_0 4778 // 523.3 Hz
#define D  4257 // 587.3 Hz
#define E  3792 // 659.3 Hz
#define G  3189 // 784 Hz

// 2.Global Declarations Section
//Function prototypes
void delay(unsigned long msec);
// basic functions defined at end of startup.s
void DisableInterrupts(void); // Disable interrupts
void EnableInterrupts(void);  // Enable interrupts


// 3. Subroutines Section
int main(void){ 
	unsigned long input,previous;	
  TExaS_Init(SW_PIN_PE3210, DAC_PIN_PB3210,ScopeOn); // activate grader and set system clock to 80 MHz
 // PortE used for piano keys, PortB used for DAC        
  Sound_Init(); // initialize SysTick timer and DAC
  Piano_Init();
	EnableInterrupts();
	Sound_Off();
	previous = Piano_In()&0x0F;
  while(1){ 
    input = Piano_In()&0x0F; // bit 4 means SW1 pressed
    if(input&&(previous!=input)){ // just pressed     
			 switch(input){
				case 0x01:
					 Sound_Tone(C_0);     
					 break; 
				case 0x02:   
					 Sound_Tone(D);      // Play note D wave
					 break; 
			
				case 0x04:  
					Sound_Tone(E);      // Play note E wave
					break;
				case 0x08:
					Sound_Tone(G);      // Play note G wave
					break;
				default:
					break;
			} 
    }
    if((input==0) && previous){ // just released    
			Sound_Off();;    // stop sound
    }
    previous = input; 
    delay(1);  // remove switch bounce    
  } 
}

// Inputs: Number of msec to delay
// Outputs: None
void delay(unsigned long msec){ 
  unsigned long count;
  while(msec > 0 ) {  // repeat while there are still delay
    count = 16000;    // about 1ms
    while (count > 0) { 
      count--;
    } // This while loop takes approximately 3 cycles
    msec--;
  }
}


