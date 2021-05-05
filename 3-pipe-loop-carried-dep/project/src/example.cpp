#define DISTANCE 4

extern "C" {

void example(unsigned int *in, unsigned int *out, int size) {
	for(unsigned int i = DISTANCE; i < size; i++) {
#pragma HLS pipeline II=1
#pragma HLS LOOP_TRIPCOUNT max=4091
		out[i] = in[i] + out[i - DISTANCE];
	}
}

}
