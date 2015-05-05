// Digital Dash - Capstone 2015
// Sean Koppenhafer, Chad Thueson, Jaime Rodriguez, Rishal Dass and Noah Erickson
//
// CAN0.cpp - Implements functions defined in CAN0.h
// CAN0 is on the RMS CAN bus
//
// Uses due_can library from https://github.com/collin80/due_can

#include "CAN0.h"
#include "digital_dash.h"

extern screen_msgs screen_messages;
extern warning_msgs warning_messages;

/******************************************************************************************
** CAN0 INTERRUPT HANDLER FUNCTION
** DIRECTS EACH RMS CAN MESSAGES TO THE RIGHT HANDLER FUNCTION
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
    case MOTOR_TORQUE_ID:
      process_motor_torque(incoming_message);
      break;
  }
}

/******************************************************************************
** INTERRUPT HANDLER FUNCTION FOR THE RMS GATE DRIVER TEMPERATURE
******************************************************************************/
static void process_gate_driver_temperature(CAN_FRAME *incoming_message) {
  const uint32_t gate_driver_temp_mask = 0xFFFF0000;  //Bytes 6 and 7
  
  screen_messages.gate_driver_temp_value = (incoming_message->data.high & gate_driver_temp_mask) >> SHIFT16;
  screen_messages.gate_driver_temp_value /= SCALE10;
  
  //Warning above 80C
  if(screen_messages.gate_driver_temp_value > GATE_DRIVER_WARNING_TEMP)
    warning_messages.gate_driver_temp_warning = 1;
  else
    warning_messages.gate_driver_temp_warning = 0;
}

/******************************************************************************
** INTERRUPT HANDLER FUNCTION FOR THE RMS CONTROL BOARD TEMPERATURE
******************************************************************************/
static void process_control_board_temperature(CAN_FRAME *incoming_message) {
  const uint32_t control_board_temp_mask = 0xFFFF;  //Bytes 0 and 1
  
  screen_messages.control_board_temp_value = incoming_message->data.low & control_board_temp_mask;
  screen_messages.control_board_temp_value /= SCALE10;
  
  //Warning above 80C
  if(screen_messages.control_board_temp_value > CONTROL_BOARD_WARNING_TEMP)
    warning_messages.control_board_temp_warning = 1;
  else
    warning_messages.control_board_temp_warning = 0;
}

/******************************************************************************
** INTERRUPT HANDLER FUNCTION FOR THE RMS MOTOR TEMPERATURE
******************************************************************************/
static void process_motor_temp(CAN_FRAME *incoming_message) {
  const uint16_t motor_temp_mask = 0xFFFF;  //Bytes 4 and 5 are motor temp
  
  screen_messages.motor_temp_value = incoming_message->data.high & motor_temp_mask;
  screen_messages.motor_temp_value /= SCALE100;
}

/******************************************************************************
** INTERRUPT HANDLER FUNCTION FOR THE RMS DC CURRENT
******************************************************************************/
static void process_DC_current(CAN_FRAME *incoming_message) {
  const uint32_t dc_current_mask = 0xFFFF0000;  //Bytes 6 and 7 are DC current
  
  screen_messages.DC_current_value = (incoming_message->data.high & dc_current_mask) >> SHIFT16;
  screen_messages.DC_current_value /= SCALE10;  //Just display, no warnings
}

/******************************************************************************
** INTERRUPT HANDLER FUNCTION FOR THE RMS DC BUS VOLTAGE
******************************************************************************/
static void process_DC_bus_voltage(CAN_FRAME *incoming_message) {
  const uint32_t DC_bus_voltage_mask = 0xFFFF;  //Bytes 0 and 1
  
  screen_messages.DC_bus_voltage_value = incoming_message->data.low & DC_bus_voltage_mask;
  screen_messages.DC_bus_voltage_value /= SCALE10;  //No warnings
}

/******************************************************************************
** INTERRUPT HANDLER FUNCTION FOR THE RMS LOW VOLTAGE BUS
** ONLY THE 12V BUS VOLTAGE IS NEEDED FROM THIS MESSAGE
******************************************************************************/
static void process_internal_voltage(CAN_FRAME *incoming_message) {
  const uint32_t low_voltage_mask = 0xFFFF0000;  //Bytes 6 and 7 are 12V rail
  
  screen_messages.internal_voltage_value = (incoming_message->data.high & low_voltage_mask) >> SHIFT16;
  screen_messages.internal_voltage_value /= SCALE100;  
  
  //Warning if <11V for more than a second
  //TODO: SETUP TIMER 
  if(screen_messages.internal_voltage_value < WARNING_12V_VOLTAGE)
    warning_messages.voltage_12V_warning = 1;
  else
    warning_messages.voltage_12V_warning = 0;
}

/******************************************************************************
** INTERRUPT HANDLER FUNCTION FOR THE RMS INTERNAL STATE
** ONLY THE VMS STATE IS NEEDED FROM THIS MESSAGE
******************************************************************************/
static void process_internal_states(CAN_FRAME *incoming_message) {
  const uint32_t RMS_state_mask = 0xFFFF;  //Bytes 0 and 1
  
  uint16_t RMS_state = incoming_message->data.low & RMS_state_mask;
  
  switch(RMS_state) {
    case 0:
      screen_messages.RMS_state = START_STATE;
      break;
    case 1:
      screen_messages.RMS_state = INIT_STATE;
      break;
    case 2:
      screen_messages.RMS_state = ACTIVE_STATE;
      break;
    case 3:
      screen_messages.RMS_state = COMPLETE_STATE;
      break;
    case 4:
      screen_messages.RMS_state = WAIT_STATE;
      break;
    case 5:
      screen_messages.RMS_state = READY_STATE;
      break;
    case 6:
      screen_messages.RMS_state = RUNNING_STATE;
      break;
    case 7:
      screen_messages.RMS_state = BLINK_STATE;
      break;Can0.watchFor(FAULT_CODES_ID);
    case 14:
      screen_messages.RMS_state = SHUTDOWN_STATE;
      break;
    case 15:
      screen_messages.RMS_state = POWER_STATE;
      break;
  }
}

//TODO: Figure out if screen or Arduino c//#define DEBUG_MOTORhecks this
void process_fault_codes(CAN_FRAME *incoming_message) {
}

/******************************************************************************
** OUTPUTS THE TORQUE FEEDBACK VALUE FROM THE MOTOR
** TORQUE INFO IS STORED IN BYTES 2 and 3
******************************************************************************/
static void process_motor_torque(CAN_FRAME* incoming_message) {
  /*screen_messages.motor_torque = incoming_message->data.low & 0xFFFF0000;
  screen_messages.motor_torque >>= 16;
  screen_messages.motor_torque /= SCALE10;*/
  screen_messages.motor_torque = 50;
}

