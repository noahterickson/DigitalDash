// Digital Dash - Capstone 2015
// Sean Koppenhafer, Chad Thueson, Jaime Rodriguez, Rishal Dass and Noah Erickson
//
// CAN1.h - Header file for CAN1 bus which has BMS on it
//
// Uses due_can library from https://github.com/collin80/due_can

#ifndef CAN1_H
#define CAN1_H

#include <due_can.h>
 
//BMS message IDS
#define RLEC4_ID 0x004
#define RLEC13_ID 0x00D

void CAN1_interrupt_handler(CAN_FRAME*);
static void process_RLEC4(CAN_FRAME*);
static void process_RLEC13(CAN_FRAME*);

static void printDouble( double val, unsigned int precision);

#endif

