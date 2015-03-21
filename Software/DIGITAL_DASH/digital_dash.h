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

#define CAN_FRAME_DATA_LEN 8
#define SERIAL_DELAY 100  //Delay for 100ms after serial write to screen

//Type LED_DIGITS screen IDs
#define GATE_DRIVER_SCREEN_ID 		0x00
#define CONTROL_BOARD_SCREEN_ID         0x01
#define MOTOR_TEMP_SCREEN_ID 		0x02
#define DC_CURRENT_SCREEN_ID		0x03
#define DC_BUS_VOLTAGE_SCREEN_ID	0x04
#define INTERNAL_VOLTAGE_SCREEN_ID	0x05
#define RLEC_TEMP_SCREEN_ID		0x06
#define MAX_CELL_VOLTAGE_SCREEN_ID	0x07
#define MIN_CELL_VOLTAGE_SCREEN_ID	0x08
#define MIN_CELL_TEMP_SCREEN_ID		0x09
#define MAX_CELL_TEMP_SCREEN_ID		0x0A

//Type USER_LED screen IDs
#define GATE_DRIVER_WARNING_SCREEN_ID 0x00
#define CONTROL_BOARD_WARNING_SCREEN_ID 0x01
#define WARNING_12V_VOLTAGE_SCREEN_ID 0x02
#define MAX_CELL_VOLTAGE_WARNING_SCREEN_ID 0x03
#define MIN_CELL_VOLTAGE_WARNING_SCREEN_ID 0x04
#define RLEC_WARNING_TEMP_SCREEN_ID 0x05
#define MAX_CELL_TEMP_WARNING_SCREEN_ID 0x06
#define MIN_CELL_TEMP_WARNING_SCREEN_ID 0x07

//Warning thresholds
#define GATE_DRIVER_WARNING_TEMP 80
#define CONTROL_BOARD_WARNING_TEMP 80
#define WARNING_12V_VOLTAGE 11
#define MAX_CELL_WARNING_VOLTAGE 4.2
#define MIN_CELL_WARNING_VOLTAGE 3.2
#define RLEC_WARNING_TEMP 60
#define MAX_CELL_WARNING_TEMP 40
#define MIN_CELL_WARNING_TEMP 0

//Struct that holds RMS error and warning states
//0 means no error, and 1 means error
typedef struct warning_msgs {         //Show warning when:
  bool gate_driver_temp_warning;      //Above 80C
  bool control_board_temp_warning;    //Above 80C
  bool voltage_12V_warning;           //Less than 11V for a few seconds
  bool max_cell_voltage_warning;      //Greater than 4.2V
  bool min_cell_voltage_warning;      //Less than 3.2V
  bool RLEC_temp_warning;             //Greater than 60C
  bool max_cell_temp_warning;         //Greater than 40C
  bool min_cell_temp_warning;         //Less than 0C
} warning_msgs;
  
//This struct holds the data values that are outputted to the screen
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
void init_screen_objects(void);

#endif
