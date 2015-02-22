// Digital Dash - Capstone 2015
// Sean Koppenhafer, Chad Thueson, Jaime Rodriguez, Rishal Dass and Noah Erickson
//
// CAN1.c - Implements functions defined in CAN1.h
//
// Uses due_can library from https://github.com/collin80/due_can

#include "CAN1.h"
#include "digital_dash.h"

/******************************************************************************************
** CAN1 INTERRUPT FUNCTIONS
******************************************************************************************/
void CAN1_interrupt_handler(CAN_FRAME* incoming_message) {
  switch(incoming_message->id) {
    case RLEC4_ID:
      process_RLEC4(incoming_message);
      break;
    case RLEC13_ID:
      process_RLEC13(incoming_message);
      break;
  }
}
 
//Max cell voltage is bytes 0 and 1
//Min cell voltage is bytes 2 and 3
//RLEC temp is byte 4 of RLEC message
static void process_RLEC4(CAN_FRAME* incoming_message) {
  const float voltage_resolution = 0.00244;
  const uint8_t shift_byte = 8;
  const uint8_t shift_3_bytes = 24;
  
  //Big endian to little endian conversion
  uint16_t max_cell_voltage = ((incoming_message->data.low & 0xFF) << shift_byte) | ((incoming_message->data.low & 0xFF00) >> shift_byte);
  uint16_t min_cell_voltage = ((incoming_message->data.low & 0xFF000000) >> shift_3_bytes) | ((incoming_message->data.low & 0xFF0000) >> shift_byte);
  
  float scaled_max_cell_voltage = (float)max_cell_voltage * voltage_resolution;  //Warning >4.2V
  float scaled_min_cell_voltage = (float)min_cell_voltage * voltage_resolution;  //Warning <3.2V, fault <2.5V
  
  short RLEC_temperature = incoming_message->data.high & 0xFF;  //Warning if >60C
    
  #ifdef DEBUG_PRINTS
  CAN1_id_buffer = incoming_message->id;
  CAN_FP_data_buffer = scaled_max_cell_voltage;
  CAN_FP_data_buffer2 = scaled_min_cell_voltage;
  CAN1_data_buffer = (int)RLEC_temperature;
  #endif
}

static void process_RLEC13(CAN_FRAME *incoming_message) {
 short max_cell_temperature = incoming_message->data.high & 0xFF;  //Warning >40C
 short min_cell_temperature = (incoming_message->data.high & 0xFF00) >> 8;  //Warning if <40C
    
  #ifdef DEBUG_PRINTS
  CAN1_id_buffer = incoming_message->id;
  CAN1_data_buffer = (int)(max_cell_temperature);
  CAN1_data_buffer2 = (int)(min_cell_temperature);
  #endif
}

/////////////////////////////////
void printDouble( double val, unsigned int precision){
// prints val with number of decimal places determine by precision
// NOTE: precision is 1 followed by the number of zeros for the desired number of decimial places
// example: printDouble( 3.1415, 100); // prints 3.14 (two decimal places)

    Serial.print (int(val));  //prints the int part
    Serial.print("."); // print the decimal point
    unsigned int frac;
    if(val >= 0)
      frac = (val - int(val)) * precision;
    else
       frac = (int(val)- val ) * precision;
    int frac1 = frac;
    while( frac1 /= 10 )
        precision /= 10;
    precision /= 10;
    while(  precision /= 10)
        Serial.print("0");

    Serial.println(frac,DEC) ;
}

