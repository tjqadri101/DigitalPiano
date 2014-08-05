DigitalPiano
============

An embedded system, for a simple digital piano with 4 keys, was built in this project. This project was a laboratory exercise for the MOOC "UTAustinX: UT.6.01x Embedded Systems - Shape the World" (this MOOC was taught on edx.org). This project had the following major objectives: to learn about Digital-to-analog converter (DAC) conversion, to understand how digital data stored in a computer could be used to represent sounds and music, and to study how the DAC and interrupts can be used together to create sounds.

The C code for the project can be found in the Lab13_DAC folder. The main sub-routine is present in Lab13.c file. The system was divided into three main modules: a low-level device driver for the DAC, a low-level device driver for the piano keys, and a device driver for sound generation. The code for these 3 modules is present in DAC.c, Piano.c, and Sound.c respectively. The program was run on the Tiva TM4C123G Launchpad microcontroller. The datasheet and manual of the Launchpad have been added to the project page as a reference guide. The Keil µVision Integrated Development Environment (IDE) was used for this project. 

A 32 element array in Sound.c contains the data points for the sine wave used for the notes. Further information on the method for determing these 32 data points can be found in the "dac.pdf" file in the Lab13_DAC folder. SysTick interrupts are used to produce the sound waves. Waves corresponding to particular notes are produced by varying the period of the wave using the Sound_Tone(period) method present in Sound.c.

A 4-bit binary-weighted DAC uses resistors in a 1/2/4/8 resistance ratio. The link below shows the DAC circuit used for this system.
[DAC circuit] (https://cloud.githubusercontent.com/assets/6359679/3817984/434a2b80-1cdd-11e4-8877-0935b9b2d990.png)

Only one key should be pressed at a time since the system cannot handle chords (multiple notes at the same time). When no key is pressed there is no sound output. The video below shows a successful trial run of the system.

[Demo Run] (https://www.youtube.com/watch?v=Gj3jyPJBa2w&feature=youtu.be)
