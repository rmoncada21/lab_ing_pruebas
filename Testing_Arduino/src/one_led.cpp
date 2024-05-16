#include <Arduino.h>
#include "one_led.h"
#define LED 13

int a = 0;

void setup_LED() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
  
}

void test_LED() {
  // put your main code here, to run repeatedly:
  // exit(0);
  Serial.println(a++);  
  digitalWrite(LED, HIGH);
  // 1000ms -> 1s
  delay(1000);
  digitalWrite(LED, LOW);
  delay(1000);
  // exit(0);
}