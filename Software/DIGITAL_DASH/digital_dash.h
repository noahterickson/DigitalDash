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

//CAN information
#define CAN_FRAME_DATA_LEN 8

//Holds data values to output to the screen
typedef struct screen_msgs {
  int gate_driver_temp_value;
  int control_board_temp_value;
  int motor_temp_value;
  int DC_current_value;
  int DC_bus_voltage_value;
  int internal_voltage_value;
  int internal_states_value;
  int fault_codes_value;
  int RLEC_temp;
  float max_cell_voltage;
  float min_cell_voltage;
  int min_cell_temp;
  int max_cell_temp; 
} screen_msgs;

//Leave defined if you use native port, comment if using programming port
//#define Serial SerialUSB

//Functions
void setup_CAN0_watches(void);
void setup_CAN1_watches(void);
void CAN0_tests(void);
void CAN1_tests(void);

#endif
