#include <hls_stream.h>

#define DATA_SIZE 4096

void performAdd(int *in1, int *in2, int *out) {
#pragma HLS INLINE off
    for(unsigned int i = 0; i < DATA_SIZE; i++)
        out[i] = in1[i] + in2[i];
}

void performSub(int *in3, int *out) {
#pragma HLS INLINE off
    for(unsigned int i = 0; i < DATA_SIZE; i++)
        out[i] = in3[i] - 0xcafe;
}

void performDiv(int *in4, int *out) {
#pragma HLS INLINE off
    for(unsigned int i = 0; i < DATA_SIZE; i++)
        out[i] = in4[i] / 552;
}

extern "C" {

void dflow(int *in1, int *in2, int *out) {
    int tmp1[DATA_SIZE];
    int tmp2[DATA_SIZE];

    performAdd(in1, in2, tmp1);
    performSub(tmp1, tmp2);
    performDiv(tmp2, out);
}

}
