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
warning_msgs warning_messages;
Genie genie;
static uint8_t current_screen = MAIN_SCREEN;

#define RESETLINE 4  //Change this if you are not using Arduino Adaptor Shield Version 2 (SEE CODE BELOW)

void setup() {
  //Initialize CAN buses
  Can0.begin(CAN_BPS_1000K);  //CAN0 receives RMS messages
  Can1.begin(CAN_BPS_500K);  //CAN1 receives BMS messages

  //Initialize serial for the screen
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
  
  //Attach screen change handler function
  //genie.AttachEventHandler(screen_change_handler);
} 
 
void loop() {
  setup_CAN0_watches();
  setup_CAN1_watches();
  Can0.setGeneralCallback(CAN0_interrupt_handler);
  Can1.setGeneralCallback(CAN1_interrupt_handler);
  
  init_screen_objects();
  while (1) {
      //Inits library for handler function
      //genie.DoEvents();
  
      //Main screen objects
      //if(current_screen == MAIN_SCREEN) {
        genie.WriteObject(GENIE_OBJ_ANGULAR_METER, CURRENT_METER_SCREEN_ID, screen_messages.DC_current_value);
        delay(SERIAL_DELAY);
        genie.WriteObject(GENIE_OBJ_ANGULAR_METER, MOTOR_TEMP_METER_SCREEN_ID, screen_messages.motor_temp_value);
        delay(SERIAL_DELAY);
        genie.WriteObject(GENIE_OBJ_TANK, BATTERY_METER_SCREEN_ID, 80);
        delay(SERIAL_DELAY);
      //}
    
      //RMS debug screen objects
      //if(current_screen == DEBUG_SCREEN) {
        genie.WriteObject(GENIE_OBJ_LED_DIGITS, GATE_DRIVER_SCREEN_ID, screen_messages.gate_driver_temp_value);
        delay(SERIAL_DELAY);
        genie.WriteObject(GENIE_OBJ_LED_DIGITS, CONTROL_BOARD_SCREEN_ID, screen_messages.control_board_temp_value);
        delay(SERIAL_DELAY);
        genie.WriteObject(GENIE_OBJ_LED_DIGITS, MOTOR_TEMP_SCREEN_ID, screen_messages.motor_temp_value);
        delay(SERIAL_DELAY);
        genie.WriteObject(GENIE_OBJ_LED_DIGITS, DC_CURRENT_SCREEN_ID, screen_messages.DC_current_value);
        delay(SERIAL_DELAY);
        genie.WriteObject(GENIE_OBJ_LED_DIGITS, DC_BUS_VOLTAGE_SCREEN_ID, screen_messages.DC_bus_voltage_value);
        delay(SERIAL_DELAY);
        genie.WriteObject(GENIE_OBJ_LED_DIGITS, INTERNAL_VOLTAGE_SCREEN_ID, screen_messages.internal_voltage_value);
        delay(SERIAL_DELAY);
      //}
      
      //BMS screen objects
      /*genie.WriteObject(GENIE_OBJ_LED_DIGITS, RLEC_TEMP_SCREEN_ID, screen_messages.RLEC_temp);
//delay(SERIAL_DELAY);
      genie.WriteObject(GENIE_OBJ_LED_DIGITS, MAX_CELL_VOLTAGE_SCREEN_ID, screen_messages.max_cell_voltage);
//delay(SERIAL_DELAY);
      genie.WriteObject(GENIE_OBJ_LED_DIGITS, MIN_CELL_VOLTAGE_SCREEN_ID, screen_messages.min_cell_voltage);
//delay(SERIAL_DELAY);
      genie.WriteObject(GENIE_OBJ_LED_DIGITS, MIN_CELL_TEMP_SCREEN_ID, (int)screen_messages.min_cell_temp);
//delay(SERIAL_DELAY);
      genie.WriteObject(GENIE_OBJ_LED_DIGITS, MAX_CELL_TEMP_SCREEN_ID, (int)screen_messages.max_cell_temp);
//delay(SERIAL_DELAY);*/

      //Warning LEDs - RMS
      //if(current_screen == RMS_WARNING_SCREEN) {
        if(warning_messages.gate_driver_temp_warning || warning_messages.control_board_temp_warning || 
           warning_messages.voltage_12V_warning) {
             genie.WriteObject(GENIE_OBJ_USERIMAGES, RMS_WARNING_IMAGE_SCREEN_ID, WARNING);
        }
        else {
          genie.WriteObject(GENIE_OBJ_USERIMAGES, RMS_WARNING_IMAGE_SCREEN_ID, NO_WARNING);
        }
        genie.WriteObject(GENIE_OBJ_USER_LED, GATE_DRIVER_WARNING_SCREEN_ID, warning_messages.gate_driver_temp_warning);
        delay(SERIAL_DELAY);
        genie.WriteObject(GENIE_OBJ_USER_LED, CONTROL_BOARD_WARNING_SCREEN_ID, warning_messages.control_board_temp_warning);
        delay(SERIAL_DELAY);
        genie.WriteObject(GENIE_OBJ_USER_LED, WARNING_12V_VOLTAGE_SCREEN_ID, warning_messages.voltage_12V_warning);
        delay(SERIAL_DELAY);
      //}
      
      //Warning LEDs - BMS
      //if(current_screen == BMS_WARNING_SCREEN) {
        genie.WriteObject(GENIE_OBJ_USER_LED, MAX_CELL_VOLTAGE_WARNING_SCREEN_ID, warning_messages.max_cell_voltage_warning);
        delay(SERIAL_DELAY);
        genie.WriteObject(GENIE_OBJ_USER_LED, MIN_CELL_VOLTAGE_WARNING_SCREEN_ID, warning_messages.min_cell_voltage_warning);
        delay(SERIAL_DELAY);
        genie.WriteObject(GENIE_OBJ_USER_LED, RLEC_WARNING_TEMP_SCREEN_ID, warning_messages.RLEC_temp_warning);
        delay(SERIAL_DELAY);
        genie.WriteObject(GENIE_OBJ_USER_LED, MAX_CELL_TEMP_WARNING_SCREEN_ID, warning_messages.max_cell_temp_warning);
        delay(SERIAL_DELAY);
        genie.WriteObject(GENIE_OBJ_USER_LED, MIN_CELL_TEMP_WARNING_SCREEN_ID, warning_messages.min_cell_temp_warning);
        delay(SERIAL_DELAY);
      //}
  }
}

/******************************************************************************
** CAN0 WATCHES FOR THE CAN MESSAGES NEEDED FROM THE RMS
******************************************************************************/
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

/******************************************************************************
** CAN1 WATCHES FOR THE CAN MESSAGES NEEDED FROM THE BMS
******************************************************************************/
void setup_CAN1_watches(void) {
  Can1.watchFor(RLEC4_ID);
  Can1.watchFor(RLEC13_ID);
}

/******************************************************************************
** INITS SCREEN OBJECTS
******************************************************************************/
void init_screen_objects(void) {
  //Main screen objects
  genie.WriteObject(GENIE_OBJ_ANGULAR_METER, CURRENT_METER_SCREEN_ID, 0);
  genie.WriteObject(GENIE_OBJ_ANGULAR_METER, MOTOR_TEMP_METER_SCREEN_ID, 0);
  genie.WriteObject(GENIE_OBJ_TANK, BATTERY_METER_SCREEN_ID, 0);
  
  //Debug screen objects
  genie.WriteObject(GENIE_OBJ_LED_DIGITS, GATE_DRIVER_SCREEN_ID, 0);
  genie.WriteObject(GENIE_OBJ_LED_DIGITS, CONTROL_BOARD_SCREEN_ID, 0);
  genie.WriteObject(GENIE_OBJ_LED_DIGITS, MOTOR_TEMP_SCREEN_ID, 0);
  genie.WriteObject(GENIE_OBJ_LED_DIGITS, DC_CURRENT_SCREEN_ID, 0);
  genie.WriteObject(GENIE_OBJ_LED_DIGITS, DC_BUS_VOLTAGE_SCREEN_ID, 0);
  genie.WriteObject(GENIE_OBJ_LED_DIGITS, INTERNAL_VOLTAGE_SCREEN_ID, 0);
  genie.WriteObject(GENIE_OBJ_LED_DIGITS, RLEC_TEMP_SCREEN_ID, 0);
  genie.WriteObject(GENIE_OBJ_LED_DIGITS, MAX_CELL_VOLTAGE_SCREEN_ID, 0);
  genie.WriteObject(GENIE_OBJ_LED_DIGITS, MIN_CELL_VOLTAGE_SCREEN_ID, 0);
  genie.WriteObject(GENIE_OBJ_LED_DIGITS, MIN_CELL_TEMP_SCREEN_ID, 0);
  genie.WriteObject(GENIE_OBJ_LED_DIGITS, MAX_CELL_TEMP_SCREEN_ID, 0);
  
  //Warning screen objects
  genie.WriteObject(GENIE_OBJ_USER_LED, GATE_DRIVER_WARNING_SCREEN_ID, 0);
  genie.WriteObject(GENIE_OBJ_USER_LED, CONTROL_BOARD_WARNING_SCREEN_ID, 0);
  genie.WriteObject(GENIE_OBJ_USER_LED, WARNING_12V_VOLTAGE_SCREEN_ID, 0);
  genie.WriteObject(GENIE_OBJ_USER_LED, MAX_CELL_VOLTAGE_WARNING_SCREEN_ID, 0);
  genie.WriteObject(GENIE_OBJ_USER_LED, MIN_CELL_VOLTAGE_WARNING_SCREEN_ID, 0);
  genie.WriteObject(GENIE_OBJ_USER_LED, RLEC_WARNING_TEMP_SCREEN_ID, 0);
  genie.WriteObject(GENIE_OBJ_USER_LED, MAX_CELL_TEMP_WARNING_SCREEN_ID, 0);
  genie.WriteObject(GENIE_OBJ_USER_LED, MIN_CELL_TEMP_WARNING_SCREEN_ID, 0);
}

/******************************************************************************
** SCREEN EVENT HANDLER THAT KEEPS TRACK OF WHICH SCREEN IS CURRENTLY SELECTED
******************************************************************************/
void screen_change_handler(void) {
  genieFrame event;
  genie.DequeueEvent(&event);
  
  if(event.reportObject.cmd == GENIE_REPORT_EVENT) {
    if(event.reportObject.object == GENIE_OBJ_USERBUTTON) {
      //The BMS has two small buttons (top and bottom) with IDs of 0x00 and 0x01
      if(event.reportObject.index == MAIN_TO_RMS_BUTTON_SCREEN_ID) {
        current_screen = RMS_WARNING_SCREEN;
      }
      else {  //BMS
        current_screen = BMS_WARNING_SCREEN;
      }
    }
    else if(event.reportObject.object == GENIE_OBJ_WINBUTTON) {
      if(event.reportObject.index == RMS_TO_MAIN_BUTTON_SCREEN_ID ||
         event.reportObject.index == BMS_TO_MAIN_BUTTON_SCREEN_ID ||
         event.reportObject.index == DEBUG_TO_MAIN_BUTTON_SCREEN_ID) {
        current_screen = MAIN_SCREEN;
      }
      else {  //Main to debug screen
        current_screen = DEBUG_SCREEN;
      }
    }     
  }  //END GENIE_REPORT
}
