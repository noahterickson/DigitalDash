// Digital Dash - Capstone 2015
// Sean Koppenhafer, Chad Thueson, Jaime Rodriguez, Rishal Dass and Noah Erickson
//
// Demo program that runs on a second board to simulate messages coming from the car
// Should be used to demo the project when away from the car for the capstone presentation
//
// Uses due_can library from https://github.com/collin80/due_can

#include <due_can.h>
#include <inttypes.h>

//#define Serial SerialUSB

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
#define SCALE10 10
#define SCALE100 100
#define SEND_CAN0 0
#define SEND_CAN1 1

CAN_FRAME message;
uint8_t can_bus_to_send;
const uint8_t num_send_functions = 9;
void (*send_data_functions[num_send_functions]) ();  //Array of function pointers

void send_gate_driver_temp();
void send_control_board_temp();
void send_motor_temp();
void send_current();
void send_DC_bus_voltage();
void send_internal_voltage();
void send_internal_states();
void send_cell_voltage();
void send_cell_temp();
uint16_t little_to_big_endian(uint16_t);

void setup() {
  //Initialize serial for the screen
  SerialUSB.begin(115200);
  
  //Initialize the function pointers
  send_data_functions[0] = send_gate_driver_temp;
  send_data_functions[1] = send_control_board_temp;
  send_data_functions[2] = send_motor_temp;
  send_data_functions[3] = send_current;
  send_data_functions[4] = send_DC_bus_voltage;
  send_data_functions[5] = send_internal_voltage;
  send_data_functions[6] = send_internal_states;
  send_data_functions[7] = send_cell_voltage;
  send_data_functions[8] = send_cell_temp;
  
  //RMS is on CAN0, BMS on CAN1
  Can0.begin(CAN_BPS_1000K);
  Can1.begin(CAN_BPS_500K);
} 
 
void loop() {
  /*message.length = CAN_FRAME_DATA_LEN;
  message.id = TEMP1_ID;
  can_bus_to_send = SEND_CAN0;
  for(int i = 0; i < 60; i += 10) {
    message.data.high = (i * SCALE10) << 16;
    SerialUSB.println(message.data.high, HEX);
    //delay(20);
    Can0.sendFrame(message);
  }*/
  for(uint8_t func_num = 0; func_num < num_send_functions; func_num++) {
      (*send_data_functions[func_num]) ();  //Call function
      
      SerialUSB.println(message.data.low, HEX);
      SerialUSB.println(message.data.high, HEX);
      
      if(can_bus_to_send == SEND_CAN1) Can1.sendFrame(message);
      else Can0.sendFrame(message);
  }
}  //End loop

/*************************************************************************
** SENDING MESSAGE FUNCTIONS
*************************************************************************/
void send_gate_driver_temp() {
  //Value stored in bytes 6 and 7
  message.data.high = (random(40, 130) * SCALE10) << 16;
  message.id = TEMP1_ID;
  can_bus_to_send = SEND_CAN0;
}

void send_control_board_temp() {
  //Value stored in bytes 0 and 1
  message.data.low = random(40, 130) * SCALE10;
  message.id = TEMP2_ID;
  can_bus_to_send = SEND_CAN0;
}

void send_motor_temp() {
  //Value stored in bytes 4 and 5
  message.data.high = random(40, 130) * SCALE100;
  message.id = TEMP3_ID;
  can_bus_to_send = SEND_CAN0;
}

void send_current() {
  //Value stored in bytes 6 and 7
  message.data.high = (random(0, 20) * SCALE10) << 16;
  message.id = CURRENT_INFO_ID;
  can_bus_to_send = SEND_CAN0;
}

void send_DC_bus_voltage() {
  //Value stored in bytes 0 and 1
  message.data.low = random(12, 25) * SCALE10;
  message.id = VOLTAGE_INFO_ID;
  can_bus_to_send = SEND_CAN0;
}

void send_internal_voltage() {
  //Value stored in bytes 6 and 7
  message.data.high = (random(10, 15) * SCALE100) << 16;
  message.id = INTERNAL_VOLTAGE_ID;
  can_bus_to_send = SEND_CAN0;
}

void send_internal_states() {
  //Value stored in bytes 0 and 1
  message.data.high = random(10, 15);
  message.id = INTERNAL_STATES_ID;
  can_bus_to_send = SEND_CAN0;
}

void send_cell_voltage() {
  //Value stored in bytes 0 and 1
  uint16_t max_cell_voltage = random(3, 7);
  //Value stored in bytes 2 and 3
  uint16_t min_cell_voltage = random(2.5, max_cell_voltage);
  
  message.data.low = little_to_big_endian(max_cell_voltage);
  message.data.low = little_to_big_endian(min_cell_voltage) << 16;
  
  //RLEC temp value stored in byte 4
  message.data.high = random(0, 130);
  message.id = RLEC4_ID;
  can_bus_to_send = SEND_CAN1;
}

void send_cell_temp() {
  //Max cell temp value stored in byte 3
  uint8_t max_cell_temp = random(15, 50);
  //Min cell temp value stored in byte 4
  uint8_t min_cell_temp = random(10, max_cell_temp);
  
  message.data.low = max_cell_temp << 24;
  message.data.high = min_cell_temp;
  message.id = RLEC13_ID;
  can_bus_to_send = SEND_CAN1;
}

/*************************************************************************
** CONVERTS LITTLE ENDIAN TO BIG ENDIAN 
*************************************************************************/
uint16_t little_to_big_endian(uint16_t to_convert) {
  uint8_t low_byte = to_convert & 0xFF;
  uint8_t high_byte = to_convert & 0xFF00;
  uint16_t big_endian = (low_byte << 8) | high_byte;
  
  return big_endian;
}


