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

void setup() {
  //Initialize CAN busses to 250kbps
  Can0.begin(BAUD_RATE);  //CAN0 receives PM100 messages
  Can1.begin(BAUD_RATE);  //CAN1 receives BMS messages
  Serial.begin(115200);
} 
 
void loop() {
  Can0.setGeneralCallback(can0_interrupt_handler);
}

void print_data(CAN_FRAME* data_frame) {
  Serial.print("CAN message received from address ");
  Serial.print(data_frame->id, HEX);
  Serial.print(" = ");
  Serial.print(data_frame->data.high, HEX);
  Serial.println(data_frame->data.low, HEX);
}

