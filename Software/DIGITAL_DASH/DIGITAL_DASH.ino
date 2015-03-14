// Digital Dash - Capstone 2015
// Sean Koppenhafer, Chad Thueson, Jaime Rodriguez, Rishal Dass and Noah Erickson
//
// Digital Dash main file
//
// Uses due_can library from https://github.com/collin80/due_can
#include <genieArduino.h>
#include <Arduino.h>
#include <due_can.h>
#include "digital_dash.h"
#include "CAN0.h"
#include "CAN1.h"

//Globals
CAN_FRAME message;
screen_msgs screen_messages;
Genie genie;

#define RESETLINE 4  //Change this if you are not using Arduino Adaptor Shield Version 2 (SEE CODE BELOW)
void setup() {
  //Initialize CAN buses
  Can0.begin(CAN_BPS_1000K);  //CAN0 receives PM100 messages
  Can1.begin(CAN_BPS_500K);  //CAN1 receives BMS messages
  Serial.begin(115200);
  genie.Begin(Serial);
  
  //Setup for the screen
  pinMode(RESETLINE, OUTPUT);  // Set D4 on Arduino to Output (4D Arduino Adaptor V2 - Display Reset)
  digitalWrite(RESETLINE, 1);  // Reset the Display via D4
  delay(100);
  digitalWrite(RESETLINE, 0);  // unReset the Display via D4
  delay (3500); //let the display start up after the reset (This is important)

  //Turn the Display on (Contrast)
  genie.WriteContrast(15); // 1 = Display ON, 0 = Display OFF.
} 
 
void loop() {
  setup_CAN0_watches();
  setup_CAN1_watches();
  Can0.setGeneralCallback(CAN0_interrupt_handler);
  Can1.setGeneralCallback(CAN1_interrupt_handler);
    
  #ifdef DEBUG
    CAN0_tests();
    CAN1_tests();
  #endif

  //Initalize the screen objects to 0
  genie.WriteObject(GENIE_OBJ_LED_DIGITS, 0x00, 0);
  genie.WriteObject(GENIE_OBJ_LED_DIGITS, 0x01, 0);
  genie.WriteObject(GENIE_OBJ_LED_DIGITS, 0x02, 0);
  genie.WriteObject(GENIE_OBJ_LED_DIGITS, 0x03, 0);
  genie.WriteObject(GENIE_OBJ_LED_DIGITS, 0x04, 0);
  genie.WriteObject(GENIE_OBJ_LED_DIGITS, 0x05, 0);
  genie.WriteObject(GENIE_OBJ_LED_DIGITS, 0x06, 0);
  genie.WriteObject(GENIE_OBJ_LED_DIGITS, 0x07, 0);
  genie.WriteObject(GENIE_OBJ_LED_DIGITS, 0x08, 0);
  genie.WriteObject(GENIE_OBJ_LED_DIGITS, 0x09, 0);
  genie.WriteObject(GENIE_OBJ_LED_DIGITS, 0x0A, 0);
  while (1) {
      //RMS screen objects
      genie.WriteObject(GENIE_OBJ_LED_DIGITS, 0x00, screen_messages.gate_driver_temp_value);
      delay(100);
      genie.WriteObject(GENIE_OBJ_LED_DIGITS, 0x01, screen_messages.control_board_temp_value);
      delay(100);
      genie.WriteObject(GENIE_OBJ_LED_DIGITS, 0x02, screen_messages.motor_temp_value);
      delay(100);
      genie.WriteObject(GENIE_OBJ_LED_DIGITS, 0x03, screen_messages.DC_current_value);
      delay(100);
      genie.WriteObject(GENIE_OBJ_LED_DIGITS, 0x04, screen_messages.DC_bus_voltage_value);
      delay(100);
      genie.WriteObject(GENIE_OBJ_LED_DIGITS, 0x05, screen_messages.internal_voltage_value);
      delay(100);
      
      //BMS screen objects
      genie.WriteObject(GENIE_OBJ_LED_DIGITS, 0x06, screen_messages.RLEC_temp);
      delay(100);
      genie.WriteObject(GENIE_OBJ_LED_DIGITS, 0x07, screen_messages.max_cell_voltage);
      delay(100);
      genie.WriteObject(GENIE_OBJ_LED_DIGITS, 0x08, screen_messages.min_cell_voltage);
      delay(100);
      genie.WriteObject(GENIE_OBJ_LED_DIGITS, 0x09, (int)screen_messages.min_cell_temp);
      delay(100);
      genie.WriteObject(GENIE_OBJ_LED_DIGITS, 0x0A, (int)screen_messages.max_cell_temp);
      delay(100);
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

