#include "data_bus_defines.h"

#ifndef DATA_BUS
#define DATA_BUS


void setup_data_bus();
void test_data_bus();
void verify_IR(bool [], int [], int, int);
void write_TMS(int, bool []);
void write_TDI(int, int []);
void write_shift_IR(int, bool [], int, int []);
void gen_clk(int);


#endif
