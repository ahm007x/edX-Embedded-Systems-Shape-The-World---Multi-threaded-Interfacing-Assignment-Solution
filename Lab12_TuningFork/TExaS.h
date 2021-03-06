// TExaS.h
// Runs on LM4F120/TM4C123
// Periodic timer Timer4A, ADC1, PD3, and UART0 used to create the scope
// Periodic timer Timer5A which will interact with debugger and grade the lab
// It initializes on reset and runs whenever interrupts are enabled
// Daniel Valvano, Jonathan Valvano
// January 15, 2016

/* This example accompanies the book
   "Embedded Systems: Introduction to ARM Cortex M Microcontrollers",
   ISBN: 978-1469998749, Jonathan Valvano, copyright (c) 2015

 Copyright 2016 by Jonathan W. Valvano, valvano@mail.utexas.edu
    You may use, edit, run or distribute this file
    as long as the above copyright notice remains
 THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 VALVANO SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL,
 OR CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 For more information about my classes, my research, and my books, see
 http://users.ece.utexas.edu/~valvano/
 */

// IMPORTANT: These enumerated types are specific to Lab 12.
enum InputPorts{
  SW_PIN_PA3 = 0,
  SW_PIN_PB3 = 1,
  SW_PIN_PE3 = 4
};

enum OutputPorts{
  HEADPHONE_PIN_PA2 = 0,
  HEADPHONE_PIN_PB2 = 1,
  HEADPHONE_PIN_PE2 = 4
};

enum ScopeModes{
  ScopeOff = 0,   // no scope needed
  ScopeOn = 1     // turn on UART0 and stream analog data from PD3 to TExaSdisplay
};

// ************TExaS_Init*****************
// Initialize grader, triggered by timer 5A
// This needs to be called once
// Inputs: iport input(s) connected to this port
//         oport output(s) connected to this port
//         scope true if oscilloscope to be implemented (uses UART0 and TExaSdisplay)
// Outputs: none
void TExaS_Init(enum InputPorts iport, enum OutputPorts oport, enum ScopeModes scope);

// ************TExaS_Stop*****************
// Stop the transfer
// Inputs:  none
// Outputs: none
void TExaS_Stop(void);
