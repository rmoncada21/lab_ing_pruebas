#include <Arduino.h>
#include "data_bus.h"

// Estado
// shift LOW (8ciclos de reloj)
int estado = 6;

// Vectores
// Implementar la instruccion según la tabla de intrucciones
int OPCODE_IR[8] = {1,0,0,0,0,0,0,1};

bool TMS_path_IR[]= {!test_logic, run_test_idle, select_DR_scan, !select_IR_scan, !capture_IR, !shift_IR, shift_IR, exit1_IR, update_IR};
int size_TMS_IR = sizeof(TMS_path_IR) / sizeof(TMS_path_IR[0]);

bool TMS_path_DR[]= {!select_DR_scan, capture_DR, exit1_DR, update_DR};
int size_TMS_DR = sizeof(TMS_path_DR) / sizeof(TMS_path_DR[0]);

void setup() {
  // put your setup code here, to run once:
  setup_data_bus();
  
}

void loop() {
  // put your main code here, to run repeatedly:
  verify_IR(TMS_path_IR, OPCODE_IR, size_TMS_IR, estado);
  // test_data_bus();
}
