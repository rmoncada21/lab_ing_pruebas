#include "Arduino.h"
#include "data_bus.h"

// Funciones 
void setup_data_bus(){
    // Inicializar lo pines
    // Entrada 
    pinMode(TDO, INPUT);
    // Salidas
    pinMode(CLK, OUTPUT);
    pinMode(TMS, OUTPUT);
    pinMode(TDI, OUTPUT);
    pinMode(OE, OUTPUT);
    pinMode(DIR, OUTPUT);
}

void test_data_bus(){
    digitalWrite(CLK, LOW);
    delay(tiempo);
    digitalWrite(TMS, LOW);
    digitalWrite(CLK, HIGH);
    delay(tiempo);
    ///////////////////////////////////////
    digitalWrite(CLK, LOW);
    delay(tiempo);
    digitalWrite(TMS, HIGH);
    digitalWrite(CLK, HIGH);
    delay(tiempo);
    ///////////////////////////////////////
    digitalWrite(CLK, LOW);
    delay(tiempo);
    digitalWrite(TMS, LOW);
    digitalWrite(CLK, HIGH);
    delay(tiempo);
    ///////////////////////////////////////
    digitalWrite(CLK, LOW);
    delay(tiempo);
    digitalWrite(TMS, LOW);
    digitalWrite(CLK, HIGH);
    delay(tiempo);
    ///////////////////////////////////////
    digitalWrite(CLK, LOW);
    delay(tiempo);
    digitalWrite(TMS, HIGH);
    digitalWrite(CLK, HIGH);
    delay(tiempo);
    ///////////////////////////////////////
    digitalWrite(CLK, LOW);
    delay(tiempo);
    digitalWrite(TMS, HIGH);
    digitalWrite(CLK, HIGH);
    delay(tiempo);

    for(int i=0 ;i<8 ;i++ ){
        digitalWrite(CLK, LOW);
        delay(tiempo);

        digitalWrite(TMS, HIGH);
        digitalWrite(TDI, LOW);

        digitalWrite(CLK, HIGH);
        delay(tiempo);
    }
    ///////////////////////////////////////
    digitalWrite(CLK, LOW);
    delay(tiempo);
    digitalWrite(TMS, LOW);
    digitalWrite(CLK, HIGH);
    delay(tiempo);
    ///////////////////////////////////////

    digitalWrite(CLK, LOW);
    delay(tiempo);
    digitalWrite(TMS, HIGH);
    digitalWrite(CLK, HIGH);
    delay(tiempo);
    ///////////////////////////////////////

    exit(0);
}

void verify_IR(bool TMS_path_IR[], int OPCODE_IR[], int size_TMS, int estado){
    for(int i=1; i<=size_TMS; i++){
        write_TMS(i, TMS_path_IR);
        write_shift_IR(i, TMS_path_IR, estado, OPCODE_IR);
        gen_clk(i);
    }
}

void write_shift_IR(int i, bool TMS_path_IR[] ,int estado, int OPCODE_IR[]){
    if(TMS_path_IR[i]==estado){
        for(int j=0; j<8; j++){
            // write_TDI(j, OPCODE_IR);
            if(OPCODE_IR[i]==1){
               digitalWrite(TDI, HIGH);
            }else if(OPCODE_IR[i]==0){
                digitalWrite(TDI, LOW);
    }
            gen_clk(j);
        }
    }
}

void write_TDI(int i, int OPCODE_IR[]){
    if(OPCODE_IR[i]==1){
        digitalWrite(TDI, HIGH);
    }else if(OPCODE_IR[i]==0){
        digitalWrite(TDI, LOW);
    }
}

void write_TMS(int i, bool TMS_path_IR[]){
    if(TMS_path_IR[i]==true){
        // digitalWrite(TMS, HIGH);
        digitalWrite(TMS, LOW);
    }else if(TMS_path_IR[i]==false){
        // digitalWrite(TMS, LOW);
        digitalWrite(TMS, HIGH);
    }
}

void gen_clk(int i){
    if (i%2!=0) {
        digitalWrite(CLK, LOW);
        delay(tiempo);
    }else{
        digitalWrite(CLK, HIGH);
        delay(tiempo);
    }
}