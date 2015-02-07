// Digital Dash - Capstone 2015
// Sean Koppenhafer, Chad Thueson, Jaime Rodriguez, Rishal Dass and Noah Erickson
//
// digital_dash.h - Header file for the main program
//
// Uses due_can library from https://github.com/collin80/due_can

#ifndef DIGITAL_DASH_H
#define DIGITAL_DASH_H

#include <stdint.h>

#define DEBUG

//CAN information
#define BAUD_RATE 250000  //250kbps
#define CAN_FRAME_DATA_LEN 8

//Leave defined if you use native port, comment if using programming port
//#define Serial SerialUSB

//Functions
void print_data(CAN_FRAME*);

#endif
