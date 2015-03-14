// Digital Dash - Capstone 2015
// Sean Koppenhafer, Chad Thueson, Jaime Rodriguez, Rishal Dass and Noah Erickson
//
// CAN0.c - Implements functions defined in CAN0.h
//
// Uses due_can library from https://github.com/collin80/due_can

#include "CAN0.h"
#include "digital_dash.h"
#include <genieArduino.h>
extern Genie genie;
extern screen_msgs screen_messages;

/******************************************************************************************
** CAN0 INTERRUPT FUNCTIONS
******************************************************************************************/
void CAN0_interrupt_handler(CAN_FRAME* incoming_message) {
  switch(incoming_message->id) {
    case TEMP1_ID:
      process_gate_driver_temperature(incoming_message);
      break;
    case TEMP2_ID:
      process_control_board_temperature(incoming_message);
      break;
    case TEMP3_ID:
      process_motor_temp(incoming_message);      
      break;
    case CURRENT_INFO_ID:
      process_DC_current(incoming_message);
      break;
    case VOLTAGE_INFO_ID:
      process_DC_bus_voltage(incoming_message);
      break;
    case INTERNAL_VOLTAGE_ID:
      process_internal_voltage(incoming_message);
      break;
    case INTERNAL_STATES_ID:
      process_internal_states(incoming_message);
      break;
    case FAULT_CODES_ID:
      process_fault_codes(incoming_message);
      break;
  }
}

static void process_gate_driver_temperature(CAN_FRAME *incoming_message) {
  const uint32_t gate_driver_temp_mask = 0xFFFF0000;  //Bytes 6 and 7
  
  screen_messages.gate_driver_temp_value = (incoming_message->data.high & gate_driver_temp_mask) >> SHIFT16;
  screen_messages.gate_driver_temp_value /= SCALE10;
}

static void process_control_board_temperature(CAN_FRAME *incoming_message) {
  const uint32_t control_board_temp_mask = 0xFFFF;  //Bytes 0 and 1
  
  screen_messages.control_board_temp_value = incoming_message->data.low & control_board_temp_mask;
  screen_messages.control_board_temp_value /= SCALE10;  //Throw error if above 80C
}

static void process_motor_temp(CAN_FRAME *incoming_message) {
  const uint16_t motor_temp_mask = 0xFFFF;  //Bytes 4 and 5 are motor temp
  
  screen_messages.motor_temp_value = incoming_message->data.high & motor_temp_mask;
  screen_messages.motor_temp_value /= SCALE100;
}

static void process_DC_current(CAN_FRAME *incoming_message) {
  const uint32_t dc_current_mask = 0xFFFF0000;  //Bytes 6 and 7 are DC current
  
  screen_messages.DC_current_value = (incoming_message->data.high & dc_current_mask) >> SHIFT16;
  screen_messages.DC_current_value /= SCALE10;  //Just display, no warnings
}

static void process_DC_bus_voltage(CAN_FRAME *incoming_message) {
  const uint32_t DC_bus_voltage_mask = 0xFFFF;  //Bytes 0 and 1
  
  screen_messages.DC_bus_voltage_value = incoming_message->data.low & DC_bus_voltage_mask;
  screen_messages.DC_bus_voltage_value /= SCALE10;  //No warnings
}

// We only need the 12V bus voltage in this message 
static void process_internal_voltage(CAN_FRAME *incoming_message) {
  const uint32_t low_voltage_mask = 0xFFFF0000;  //Bytes 6 and 7 are 12V rail
  
  screen_messages.internal_voltage_value = (incoming_message->data.high & low_voltage_mask) >> SHIFT16;
  screen_messages.internal_voltage_value /= SCALE100;  //Warning if <11V for more than a second
}

//We only need the VMS state from this CAN message
static void process_internal_states(CAN_FRAME *incoming_message) {
  const uint32_t VMS_state_mask = 0xFFFF;  //Bytes 0 and 1
  
  int VMS_state = incoming_message->data.low & VMS_state_mask;
}

//TODO: Figure out if screen or Arduino checks this
void process_fault_codes(CAN_FRAME *incoming_message) {
}


