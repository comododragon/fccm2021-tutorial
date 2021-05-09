#define DATA_SIZE 1024
#define STENCIL_SIZE 16

extern "C" {

void stencil(int *in1, int *out) {
    for(unsigned int i = 0; i < DATA_SIZE; i++) {
        int acc = 0;

        for(unsigned int j = 0; j < STENCIL_SIZE; j++)
            acc += in1[i + j];

        out[i] = acc;
    }
}

}
