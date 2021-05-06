extern "C" {

void vadd(unsigned int *in1, unsigned int *in2, unsigned int *out, int size) {
    for(unsigned int i = 0; i < size; i++) {
#pragma HLS LOOP_TRIPCOUNT max=4096
#pragma HLS PIPELINE off
        out[i] = in1[i] + in2[i];
    }
}

}
