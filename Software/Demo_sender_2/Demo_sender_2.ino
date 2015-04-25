// Digital Dash - Capstone 2015
// Sean Koppenhafer, Chad Thueson, Jaime Rodriguez, Rishal Dass and Noah Erickson
//
// Demo program that runs on a second board to simulate messages coming from the car
// Should be used to demo the project when away from the car for the capstone presentation
//
// Uses due_can library from https://github.com/collin80/due_can

#include <due_can.h>
#include <inttypes.h>

//#define DEBUG
#define DEBUG_FUNCTIONS

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

//Analog pin information
#define BATTERY_PIN 3     //Actually AIN0 (pin 20) on EVCU
#define MOTOR_TEMP_PIN 2  //Actually AIN1 (pin 21) on EVCU

#define CAN_FRAME_DATA_LEN 8
#define SCALE10 10
#define SCALE100 100
#define SEND_CAN0 0
#define SEND_CAN1 1

CAN_FRAME message;

void send_motor_temp(uint16_t);
void send_cell_voltage(uint16_t);
void send_cell_temp(uint16_t);
uint16_t little_to_big_endian(uint16_t);

void setup() {
  //Initialize serial for the screen
  SerialUSB.begin(115200);
  
  //RMS is on CAN0, BMS on CAN1
  Can0.begin(CAN_BPS_1000K);
  Can1.begin(CAN_BPS_500K);
  message.length = CAN_FRAME_DATA_LEN;
} 
 
void loop() {
  uint16_t battery_level, motor_temp;
  
  battery_level = analogRead(BATTERY_PIN);
  send_cell_voltage(battery_level);
  motor_temp = analogRead(MOTOR_TEMP_PIN);
  send_motor_temp(motor_temp);
  
  #ifdef DEBUG
  SerialUSB.print("BATTERY_OUTPUT = ");
  SerialUSB.println(battery_level);
  SerialUSB.print("MOTOR_OUTPUT = ");
  SerialUSB.println(motor_temp);
  #endif
}  //End loop

/*************************************************************************
** SENDING MESSAGE FUNCTIONS
*************************************************************************/
// Input value: motor temp can be ~15 to ~800
// Has a resolution of 50
void send_motor_temp(uint16_t motor_temp) {
  //Value stored in bytes 4 and 5
  uint16_t mod_value = motor_temp % 100;
  uint16_t hundreds = motor_temp - mod_value;
  
  if(mod_value >= 50) mod_value = 50;
  else mod_value = 0;
  
  message.data.high = (hundreds + mod_value) * 12;  //Scale up for the division of 100 on screen side
  message.data.low = 0;
  
  #ifdef DEBUG_FUNCTIONS
  SerialUSB.print("MOTOR_TEMP = ");
  SerialUSB.println(message.data.high);
  #endif
  
  message.id = TEMP3_ID;
  Can0.sendFrame(message);
}

void send_cell_voltage(uint16_t min_cell_scale) {
  const uint8_t max_voltage_offset = 123;  //Always be 0.3V above min cell voltage
  //Value stored in bytes 0 and 1
  uint16_t min_cell_voltage = min_cell_scale * 2;
  //Value stored in bytes 2 and 3
  uint16_t max_cell_voltage = min_cell_voltage + max_voltage_offset;
  
  message.data.low = little_to_big_endian(max_cell_voltage);
  message.data.low |= little_to_big_endian(min_cell_voltage) << 16;
  
  //RLEC temp value stored in byte 4
  message.data.high = 0;
  message.id = RLEC4_ID;
  Can1.sendFrame(message);
}

void send_cell_temp() {
  //Max cell temp value stored in byte 3
  uint8_t max_cell_temp = random(15, 50);
  //Min cell temp value stored in byte 4
  uint8_t min_cell_temp = random(10, max_cell_temp);
  
  message.data.low = max_cell_temp << 24;
  message.data.high = min_cell_temp;
  message.id = RLEC13_ID;
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


