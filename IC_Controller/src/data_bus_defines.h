#include <Arduino.h>

// Pines
// Pines de entrada
#define TDO 8

// Pines de salida del arduino
#define CLK 13
#define TMS 12
#define TDI 11
#define OE  10 //Output enable
#define DIR 9  // Dirección 

// Cargar de entrada paralela
// #define data1
// #define data2
// #define data3
// #define data4
// #define data5
// #define data6
// #define data7
// #define data8

// Estados Lógicos de la Máquina de estados
#define tiempo 500
#define test_logic true
#define run_test_idle true

// Registros de datos
#define select_DR_scan true
#define capture_DR true
#define shift_DR true
#define exit1_DR true
#define pause_DR true
#define exit2_DR true
#define update_DR true

// Registros de instrucciones
#define select_IR_scan true
#define capture_IR true
#define shift_IR true
#define exit1_IR true
#define pause_IR true
#define exit2_IR true
#define update_IR true



// para la funcion setup_data_bus
// pinMode(data1, OUTPUT);
    // pinMode(data2, OUTPUT);
    // pinMode(data3, OUTPUT);
    // pinMode(data4, OUTPUT);
    // pinMode(data5, OUTPUT);
    // pinMode(data6, OUTPUT);
    // pinMode(data7, OUTPUT);
    // pinMode(data8, OUTPUT);