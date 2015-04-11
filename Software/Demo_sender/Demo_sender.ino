// Digital Dash - Capstone 2015
// Sean Koppenhafer, Chad Thueson, Jaime Rodriguez, Rishal Dass and Noah Erickson
//
// Simple polled CAN test
//
// Uses due_can library from https://github.com/collin80/due_can

#include <due_can.h>
#include <inttypes.h>

//RMS CAN MESSAGES
#define TEMP1_ID                  0x0A0  
#define TEMP2_ID                  0x0A1  
#define TEMP3_ID                  0x0A2  
#define CURRENT_INFO_ID           0x0A6  
#define VOLTAGE_INFO_ID           0x0A7  
#define INTERNAL_VOLTAGE_ID       0x0A9  
#define INTERNAL_STATES_ID        0x0AA  
#define FAULT_CODES_ID            0x0AB

//BMS message IDS
#define RLEC4_ID 0x1C4
#define RLEC13_ID 0x1CD

#define CAN_FRAME_DATA_LEN 8

CAN_FRAME message;

//Leave defined if you use native port, comment if using programming port
//#define Serial SerialUSB

void setup() {
  //Initialize CAN busses to 250kbps
  Can0.begin(CAN_BPS_1000K);
  Can1.begin(CAN_BPS_500K);
  Serial.begin(9600);
} 
 
void loop() {
  //Can0.sendFrame(message);
  
  //Wait for the second port to receive the message
  while(Can0.available() == 0) {
  }
  
  message.length = CAN_FRAME_DATA_LEN;
}

/*************************************************************************
** SENDING MESSAGE FUNCTIONS
*************************************************************************/
void send_gate_driver_temp() {
  //Value stored in bytes 6 and 7
  message.data.high = random(40, 130) << 16;
  message.id = TEMP1_ID;
}

void send_control_board_temp() {
  //Value stored in bytes 0 and 1
  message.data.low = random(40, 130);
  message.id = TEMP2_ID;
}

void send_motor_temp() {
  //Value stored in bytes 4 and 5
  message.data.high = random(40, 130);
  message.id = TEMP3_ID;
}

void send_current() {
  //Value stored in bytes 6 and 7
  message.data.high = random(0, 20) << 16;
  message.id = CURRENT_INFO_ID;
}

void send_DC_bus_voltage() {
  //Value stored in bytes 0 and 1
  message.data.low = random(12, 25);
  message.id = VOLTAGE_INFO_ID;
}

void send_internal_voltage() {
  //Value stored in bytes 6 and 7
  message.data.high = random(10, 15) << 16;
  message.id = INTERNAL_VOLTAGE_ID;
}

void send_internal_states() {
  //Value stored in bytes 0 and 1
  message.data.high = random(10, 15);
  message.id = INTERNAL_STATES_ID;
}

void send_cell_voltage() {
  //Value stored in bytes 0 and 1
  message.data.low = random(3, 7);
  message.id = INTERNAL_STATES_ID;
}
