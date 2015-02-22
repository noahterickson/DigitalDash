// Digital Dash - Capstone 2015
// Sean Koppenhafer, Chad Thueson, Jaime Rodriguez, Rishal Dass and Noah Erickson
//
// Digital Dash main file
//
// Uses due_can library from https://github.com/collin80/due_can

#include <Arduino.h>
#include <due_can.h>
#include "digital_dash.h"
#include "CAN0.h"
#include "CAN1.h"

CAN_FRAME message;

//Declarations for debug
uint32_t CAN0_id_buffer;
uint32_t CAN1_id_buffer;
int CAN0_data_buffer;
int CAN1_data_buffer;
int CAN1_data_buffer2;
float CAN_FP_data_buffer;
float CAN_FP_data_buffer2;

void setup() {
  //Initialize CAN busses to 250kbps
  Can0.begin(CAN_BPS_1000K);  //CAN0 receives PM100 messages
  Can1.begin(CAN_BPS_1000K);  //CAN1 receives BMS messages
  Serial.begin(115200);
} 
 
void loop() {
  setup_CAN0_watches();
  setup_CAN1_watches();
  Can0.setGeneralCallback(CAN0_interrupt_handler);
  Can1.setGeneralCallback(CAN1_interrupt_handler);
  
    
  #ifdef DEBUG
    CAN0_tests();messages
    CAN1_tests();
  #endif

  while (1) {
      Serial.print(CAN0_id_buffer, HEX);
      Serial.print(", ");
      Serial.println(CAN0_data_buffer, HEX);
  }
}

void setup_CAN0_watches(void) {
  Can0.watchFor(TEMP1_ID);
  Can0.watchFor(TEMP2_ID);
  Can0.watchFor(TEMP3_ID);
  Can0.watchFor(CURRENT_INFO_ID);
  Can0.watchFor(VOLTAGE_INFO_ID);
  Can0.watchFor(INTERNAL_VOLTAGE_ID);
  Can0.watchFor(INTERNAL_STATES_ID);
  Can0.watchFor(FAULT_CODES_ID);
}

void setup_CAN1_watches(void) {
  Can1.watchFor(RLEC4_ID);
  Can1.watchFor(RLEC13_ID);
}

void CAN0_tests(void) {
  //Result should be 80
  message.id = TEMP1_ID;
  message.length = CAN_FRAME_DATA_LEN;
  message.data.low = 0;
  message.data.high = 0x03200000;  //800
  Can1.sendFrame(message);
  delay(100);
  
  //Result should be 81
  message.id = TEMP2_ID;
  message.data.low = 0x32A;  //810
  message.data.high = 0x0;
  Can1.sendFrame(message);
  delay(100);
  
  //Result should be 82
  message.id = TEMP3_ID;
  message.data.low = 0;
  message.data.high = 0x334; //820
  Can1.sendFrame(message);
  delay(100);
  
  //Result should be 83
  message.id = CURRENT_INFO_ID;
  message.data.low = 0;
  message.data.high = 0x033E0000; //830
  Can1.sendFrame(message);
  delay(100);
  
  //Result should be 84
  message.id = VOLTAGE_INFO_ID;
  message.data.low = 0x348; //840
  message.data.high = 0x0;
  Can1.sendFrame(message);
  delay(100);
  
  //Result should be 12
  message.id = INTERNAL_VOLTAGE_ID;
  message.data.low = 0;
  message.data.high = 0x04B00000; //1200
  Can1.sendFrame(message);
  delay(100);
  
  //Result should be 0x35C
  message.id = INTERNAL_STATES_ID;
  message.data.low = 0x35C;
  message.data.high = 0;
  Can1.sendFrame(message);
  delay(100);
  
  //message.id = FAULT_CODES_ID;
  //message.data.low = 0;
  //message.data.high = 0x03480000; //840
  //Can1.sendFrame(message);
  //delay(100);
}

void CAN1_tests(void) {
  //Max cell voltage should be 3.55V
  //Min cell voltage should be 3.1V
  //RLEC temp should be 65
  message.id = RLEC4_ID;
  message.length = CAN_FRAME_DATA_LEN;
  message.data.low = 0xF604AF05;
  message.data.high = 0x41;
  Can0.sendFrame(message);
  delay(100);
  
  //Max cell temp should be 35
  //Min cell temp should be 30
  message.id = RLEC13_ID;
  message.data.low = 0;
  message.data.high = 0x1E23;
  Can0.sendFrame(message);
  delay(100);
}

