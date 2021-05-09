#define DATA_SIZE 1024
#define STENCIL_SIZE 16

extern "C" {

void stencil(int *in1, int *out) {
    int buffer[STENCIL_SIZE];
#pragma HLS ARRAY_PARTITION variable=buffer complete

    for(unsigned int i = 0; i < (STENCIL_SIZE - 1); i++)
        buffer[i + 1] = in1[i];

    for(unsigned int i = 0; i < DATA_SIZE; i++) {
        for(unsigned int j = 0; j < (STENCIL_SIZE - 1); j++)
            buffer[j] = buffer[j + 1];
        buffer[STENCIL_SIZE - 1] = in1[i + STENCIL_SIZE - 1];

        int acc = 0;
        for(unsigned int j = 0; j < STENCIL_SIZE; j++)
            acc += buffer[j];
        out[i] = acc;
    }
}

}
