// Digital Dash - Capstone 2015
// Sean Koppenhafer, Chad Thueson, Jaime Rodriguez, Rishal Dass and Noah Erickson
//
// CAN0.h - Header file for the CAN bus with the PM100 on it.
//
// Uses due_can library from https://github.com/collin80/due_can

#include "CAN0.h"
#include "digital_dash.h"

/******************************************************************************************
** CAN0 INTERRUPT FUNCTIONS
******************************************************************************************/
void can0_interrupt_handler(CAN_FRAME* incoming_message) {
  print_data(incoming_message);
  
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

void process_gate_driver_temperature(CAN_FRAME *incoming_message) {
  const uint32_t gate_driver_temp_mask = 0xFFFF0000;  //Bytes 6 and 7
  
  int gate_driver_temp = (incoming_message->data.high & gate_driver_temp_mask) >> SHIFT16;
  gate_driver_temp /= SCALE10;  //Throw error if above 80C
  
  #ifdef DEBUG
  Serial.print("Scaled Gate Driver Temperature = ");
  Serial.println(gate_driver_temp);
  #endif
}

void process_control_board_temperature(CAN_FRAME *incoming_message) {
  const uint32_t control_board_temp_mask = 0xFFFF;  //Bytes 0 and 1
  
  int control_board_temp = incoming_message->data.low & control_board_temp_mask;
  control_board_temp /= SCALE10;  //Throw error if above 80C
  
  #ifdef DEBUG
  Serial.print("Scaled Control Board Temp = ");
  Serial.println(control_board_temp);
  #endif
}

void process_motor_temp(CAN_FRAME *incoming_message) {
  const uint16_t motor_temp_mask = 0xFFFF;  //Bytes 4 and 5 are motor temp
  
  int motor_temp = incoming_message->data.high & motor_temp_mask;
  motor_temp /= SCALE10;
  
  #ifdef DEBUG
  Serial.print("Scaled motor temp = ");
  Serial.println(motor_temp);
  #endif
}

void process_DC_current(CAN_FRAME *incoming_message) {
  const uint32_t dc_current_mask = 0xFFFF0000;  //Bytes 6 and 7 are DC current
  
  int dc_current = (incoming_message->data.high & dc_current_mask) >> SHIFT16;
  dc_current /= SCALE10;  //Just display, no warnings
  
  #ifdef DEBUG
  Serial.print("Scaled DC_current = ");
  Serial.println(dc_current);
  #endif
}

void process_DC_bus_voltage(CAN_FRAME *incoming_message) {
  const uint32_t DC_bus_voltage_mask = 0xFFFF;  //Bytes 0 and 1
  
  int DC_bus_voltage = incoming_message->data.low & DC_bus_voltage_mask;
  DC_bus_voltage /= SCALE10;  //No warnings
  
  #ifdef DEBUG
  Serial.print("Scaled DC bus voltage = ");
  Serial.println(DC_bus_voltage);
  #endif
}

// We only need the 12V bus voltage in this message 
void process_internal_voltage(CAN_FRAME *incoming_message) {
  const uint32_t low_voltage_mask = 0xFFFF0000;  //Bytes 6 and 7 are 12V rail
  
  int low_voltage = (incoming_message->data.high & low_voltage_mask) >> SHIFT16;
  low_voltage /= SCALE100;  //Warning if <11V for more than a second
  
  #ifdef DEBUG
  Serial.print("Scaled 12V bus voltage = ");
  Serial.println(low_voltage);
  #endif
}

//We only need the VMS state from this CAN message
void process_internal_states(CAN_FRAME *incoming_message) {
  const uint32_t VMS_state_mask = 0xFFFF;  //Bytes 0 and 1
  
  int VMS_state = incoming_message->data.low & VMS_state_mask;
  
  #ifdef DEBUG
  Serial.print("VMS state bytes = ");
  Serial.println(VMS_state);
  #endif
}

//TODO: Figure out if screen or Arduino checks this
void process_fault_codes(CAN_FRAME *incoming_message) {
}

