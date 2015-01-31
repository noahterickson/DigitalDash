// Digital Dash - Capstone 2015
// Sean Koppenhafer, Chad Thueson, Jaime Rodriguez, Rishal Dass and Noah Erickson
//
// Digital Dash main file
//
// Uses due_can library from https://github.com/collin80/due_can

#include <due_can.h>
#include <stdint.h>

#define DEBUG
#define BAUD_RATE 250000  //250kbps
#define SHIFT16  16
#define SCALE10  10

//RMS CAN MESSAGES
#define TEMP1_ID                  0x0A0  
#define TEMP2_ID                  0x0A1  
#define TEMP3_ID                  0x0A2  
#define ANALOG_INPUT_VOLTAGE_ID   0x0A3  
#define DIGITAL_INPUT_STATUS_ID   0x0A4  
#define MOTOR_POSITION_ID         0x0A5  
#define CURRENT_INFO_ID           0x0A6  
#define VOLTAGE_INFO_ID           0x0A7  
#define FLUX_INFO_ID              0x0A8 
#define INTERNAL_VOLTAGE_ID       0x0A9  
#define INTERNAL_STATES_ID        0x0AA  
#define FAULT_CODES_ID            0x0AB  
#define TORQUE_TIMER_INFO_ID      0x0AC  
#define MOD_INDEX_FLEX_WEAK_ID    0x0AD  
#define FIRMWARE_INFO_ID          0x0AE  
#define DIAGNOSTIC_ID             0x0AF  

#define CAN_FRAME_DATA_LEN 8

//Leave defined if you use native port, comment if using programming port
//#define Serial SerialUSB

void print_data(CAN_FRAME*);

//Can interrupts
void can_interrupt_handler(CAN_FRAME*);
void process_motor_temp(CAN_FRAME*);
void process_dc_current(CAN_FRAME*);

void setup() {
  //Initialize CAN busses to 250kbps
  Can0.begin(BAUD_RATE);  //CAN0 receives RMS messages
  //Can1.begin(BAUD_RATE);
  Serial.begin(115200);
 } 
 
void loop() {
  Can0.setGeneralCallback(can_interrupt_handler);
}

void print_data(CAN_FRAME* data_frame) {
  Serial.print("CAN message received from address ");
  Serial.print(data_frame->id, HEX);
  Serial.print(" = ");
  Serial.print(data_frame->data.high, HEX);
  Serial.println(data_frame->data.low, HEX);
}

/******************************************************************************************
** CAN INTERRUPT FUNCTIONS
******************************************************************************************/

void can_interrupt_handler(CAN_FRAME* incoming_message) {
  print_data(incoming_message);
  
  switch(incoming_message->id) {
    case TEMP3_ID:
      process_motor_temp(incoming_message);
      break;
    case CURRENT_INFO_ID:
      process_dc_current(incoming_message);
      break;
  }
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

void process_dc_current(CAN_FRAME *incoming_message) {
  const uint32_t dc_current_mask = 0xFFFF0000;  //Bytes 6 and 7 are DC current
  
  int dc_current = (incoming_message->data.high & dc_current_mask) >> SHIFT16;
  dc_current /= SCALE10;
  
  #ifdef DEBUG
  Serial.print("Scaled DC_current = ");
  Serial.println(dc_current);
  #endif
}

