#include "ap_int.h"

struct two_apint16_t {
    ap_int<16> in1;
    ap_int<16> in2;
}; 

extern "C" {

void vadd(two_apint16_t *in1, ap_int<16> *out, int size) {
    for(unsigned int i = 0; i < size; i++) {
#pragma HLS LOOP_TRIPCOUNT max=4096
        two_apint16_t tmp = in1[i];

        out[i] = tmp.in1 + tmp.in2;
    }
}

}
