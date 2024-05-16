#include "Arduino.h"
#include "mux_2x1.h"

// Definir pines

// Pines de selección
#define pin_G  13 // MSB
#define pin_AB 12 //LSB

// Pines de entrada
#define pin_0A 11 
#define pin_1A 10
#define pin_2A 9
#define pin_3A 8

#define pin_0B 7
#define pin_1B 6
#define pin_2B 5
#define pin_3B 4


// Funciones

void setup_mux_2x1(){
    // Pines de selección
    pinMode(pin_G, OUTPUT);
    pinMode(pin_AB, OUTPUT);
    
    // Pines de entrada del mux / salida del aduino
    pinMode(pin_0A, OUTPUT);
    pinMode(pin_1A, OUTPUT);
    pinMode(pin_2A, OUTPUT);
    pinMode(pin_3A, OUTPUT);
    
    pinMode(pin_0B, OUTPUT);
    pinMode(pin_1B, OUTPUT);
    pinMode(pin_2B, OUTPUT);
    pinMode(pin_3B, OUTPUT);

}


void test_mux_2x1(){
    // Escribir las entradas de selección
    digitalWrite(pin_G, HIGH); // Todas las salidas en cero
    digitalWrite(pin_AB, LOW);
    delay(2000);
    
    // Habilitar las salidas A's
    digitalWrite(pin_G, LOW); 
    digitalWrite(pin_AB, LOW);
    // Escribir las entradas de A's
    digitalWrite(pin_0A, HIGH);
    digitalWrite(pin_1A, LOW);
    digitalWrite(pin_2A, HIGH);
    digitalWrite(pin_3A, LOW);
    delay(2000);

    // Habilitar las salidas B's
    digitalWrite(pin_G, LOW); 
    digitalWrite(pin_AB, HIGH);
    // Escribir las entradas de B's
    digitalWrite(pin_0B, LOW);
    digitalWrite(pin_1B, HIGH);
    digitalWrite(pin_2B, LOW);
    digitalWrite(pin_3B, HIGH);
    delay(2000);

}

void test_switch(){
    digitalWrite(pin_G, LOW);    
    delay(3000);

    digitalWrite(pin_G, HIGH);
    delay(3000);

    digitalWrite(pin_G, LOW);    
    delay(3000);

    digitalWrite(pin_G, HIGH);
    delay(3000);


    digitalWrite(pin_G, LOW);    
    delay(3000);

    digitalWrite(pin_G, HIGH);
    delay(3000);

}