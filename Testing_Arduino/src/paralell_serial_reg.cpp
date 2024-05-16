#include "Arduino.h"
#include "paralell_serial_reg.h"

// definir puertos/pines del arduino
#define pin_SHLD  13 // MSB
#define pin_CLK 12 //LSB
#define pin_CLK_INH 11 
#define pin_SER 10

#define pin_A 9
#define pin_B 8
#define pin_C 7
#define pin_D 6
#define pin_E 5
#define pin_F 4
#define pin_G 3
#define pin_H 2



void setup_reg_ps(){
    pinMode(pin_SHLD, OUTPUT);
    pinMode(pin_CLK, OUTPUT);
    pinMode(pin_CLK_INH, OUTPUT);
    pinMode(pin_SER, OUTPUT);

    pinMode(pin_A, OUTPUT);
    pinMode(pin_B, OUTPUT);
    pinMode(pin_C, OUTPUT);
    pinMode(pin_D, OUTPUT);
    pinMode(pin_E, OUTPUT);
    pinMode(pin_F, OUTPUT);
    pinMode(pin_G, OUTPUT);
    pinMode(pin_H, OUTPUT);
    
}


void test_reg_ps(){
    // pin_CLK_INH debe estar en alto para cargar los datos paralelo
    digitalWrite(pin_CLK_INH, HIGH);
    digitalWrite(pin_SER, LOW);
    digitalWrite(pin_SHLD, HIGH);

    // Entrada paralela
    digitalWrite(pin_A, HIGH);
    digitalWrite(pin_B, LOW);
    digitalWrite(pin_C, HIGH);
    digitalWrite(pin_D, LOW);
    digitalWrite(pin_E, HIGH);
    digitalWrite(pin_F, LOW);
    digitalWrite(pin_G, HIGH);
    digitalWrite(pin_H, HIGH);

    
    // Un ciclo de reloj
    digitalWrite(pin_CLK, LOW);
    delay(500);
    digitalWrite(pin_CLK, HIGH);
    delay(500);
    digitalWrite(pin_CLK, LOW);
    delay(500);
    digitalWrite(pin_CLK, HIGH);
    delay(500);

    // Cargar los datos 
    // SHLD carga en flanco descendete
    digitalWrite(pin_SHLD, LOW);
    
    // Un ciclo de reloj
    digitalWrite(pin_CLK, LOW);
    delay(500);
    
    digitalWrite(pin_SHLD, HIGH);

    digitalWrite(pin_CLK, HIGH);
    delay(500);
    digitalWrite(pin_CLK, LOW);
    delay(500);
    digitalWrite(pin_CLK, HIGH);
    delay(500);

    // Desahibilitar CLK_INH
    digitalWrite(pin_CLK_INH, LOW);

    for(int i=0; i<12; i++){
        digitalWrite(pin_CLK, LOW);
        delay(2000);
        digitalWrite(pin_CLK, HIGH);
        delay(2000);
    }

}