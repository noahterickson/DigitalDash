// Digital Dash - Capstone 2015
// Sean Koppenhafer, Chad Thueson, Jaime Rodriguez, Rishal Dass and Noah Erickson
//
// digital_dash.h - Header file for the main program
//
// Uses due_can library from https://github.com/collin80/due_can

#ifndef DIGITAL_DASH_H
#define DIGITAL_DASH_H

#include <stdint.h>
#include <string.h>

//#define DEBUG
//#define DEBUG_PRINTS

extern uint32_t CAN0_id_buffer;
extern uint32_t CAN1_id_buffer;
extern int CAN0_data_buffer;
extern int CAN1_data_buffer;
extern int CAN1_data_buffer2;
extern float CAN_FP_data_buffer;
extern float CAN_FP_data_buffer2;

//CAN information
#define CAN_FRAME_DATA_LEN 8


//Leave defined if you use native port, comment if using programming port
//#define Serial SerialUSB

//Functions
void setup_CAN0_watches(void);
void setup_CAN1_watches(void);
void CAN0_tests(void);
void CAN1_tests(void);

#endif
