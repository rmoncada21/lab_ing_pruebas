#include <Arduino.h>
#include "one_led.h"
#include "mux_2x1.h"
#include "paralell_serial_reg.h"

#define G 13
int opcion = 4;

void setup() {
  // put your setup code here, to run once:
  // Habilitar le monitor
  Serial.begin(9600);

  
  switch(opcion){
    case 0:
      setup_LED();
      break;

    case 1:
      setup_mux_2x1();
      break;

    case 2:
      setup_reg_ps();
      break;

    case 3:
      setup_mux_2x1();
      break;
    
    case 4:
      pinMode(G, OUTPUT);
      break;
    default:
      break;

  }
  
  
}

void loop() {
  // put your main code here, to run repeatedly:
  
  switch(opcion){
    case 0:
      test_LED();
      break;

    case 1:
      for(int i=0; i<3; i++){
        test_mux_2x1();
      }
      exit(0);
      break;

    case 2:
      test_reg_ps();
      exit(0);
      break;
    
    case 3:
      //exit(0);
      for(int i=0; i<5; i++){
        test_switch();
      }
      exit(0);
      
      break;

    case 4:
      //exit(0);
      analogWrite(G, LOW); // Todas las salidas en cero
      delay(300);
      analogWrite(G, HIGH); // Todas las salidas en cero
      delay(300);
      analogWrite(G, LOW); // Todas las salidas en cero
      delay(300);
      analogWrite(G, HIGH); // Todas las salidas en cero
      delay(300);
      analogWrite(G, LOW); // Todas las salidas en cero
      delay(300);
      analogWrite(G, HIGH); // Todas las salidas en cero
      delay(300);
      analogWrite(G, LOW); // Todas las salidas en cero
      delay(300);
      analogWrite(G, HIGH); // Todas las salidas en cero
      delay(300);
      analogWrite(G, LOW); // Todas las salidas en cero
      delay(300);
      analogWrite(G, HIGH); // Todas las salidas en cero
      delay(300);
      exit(0);
      break;

    default:
      break;

  }
  
}