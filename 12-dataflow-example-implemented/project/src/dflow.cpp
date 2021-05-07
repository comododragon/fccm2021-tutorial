#include <hls_stream.h>

#define DATA_SIZE 4096

void readData(int *in1, int *in2, hls::stream<int> &out1, hls::stream<int> &out2) {
#pragma HLS INLINE off
    for(unsigned int i = 0; i < DATA_SIZE; i++) {
        out1 << in1[i];
        out2 << in2[i];
    }
}

void performAdd(hls::stream<int> &in3, hls::stream<int> &in4, hls::stream<int> &out) {
#pragma HLS INLINE off
    for(unsigned int i = 0; i < DATA_SIZE; i++)
        out << in3.read() + in4.read();
}

void performSub(hls::stream<int> &in5, hls::stream<int> &out) {
#pragma HLS INLINE off
    for(unsigned int i = 0; i < DATA_SIZE; i++)
        out << in5.read() - 0xcafe;
}

void performDiv(hls::stream<int> &in6, hls::stream<int> &out) {
#pragma HLS INLINE off
    for(unsigned int i = 0; i < DATA_SIZE; i++)
        out << in6.read() / 552;
}

void writeData(hls::stream<int> &in7, int *out) {
#pragma HLS INLINE off
    for(unsigned int i = 0; i < DATA_SIZE; i++)
        in7 >> out[i];
}

extern "C" {

void dflow(int *in1, int *in2, int *out) {
#pragma HLS DATAFLOW
    hls::stream<int> tmp1("tmp1_stream");
    hls::stream<int> tmp2("tmp2_stream");
    hls::stream<int> tmp3("tmp3_stream");
    hls::stream<int> tmp4("tmp4_stream");
    hls::stream<int> tmp5("tmp5_stream");

    readData(in1, in2, tmp1, tmp2);
    performAdd(tmp1, tmp2, tmp3);
    performSub(tmp3, tmp4);
    performDiv(tmp4, tmp5);
    writeData(tmp5, out);
}

}
