#define DISTANCE 4

extern "C" {

void example(unsigned int *in, unsigned int *out, int size) {
    static unsigned int shiftReg[DISTANCE];

    for(unsigned int i = DISTANCE; i < size; i++) {
#pragma HLS PIPELINE II=1
#pragma HLS LOOP_TRIPCOUNT max=4092
        int _tmp = in[i] + shiftReg[0];
        out[i] = _tmp;

        // These statements below are converted to a shift register
        for(int j = 0; j < DISTANCE - 1; j++)
            shiftReg[j] = shiftReg[j+1];
        shiftReg[DISTANCE - 1] = _tmp;
    }
}

}
