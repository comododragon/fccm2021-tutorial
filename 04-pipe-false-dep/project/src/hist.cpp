extern "C" {

void hist(unsigned char *image, unsigned int *histogram, int size) {
    for(unsigned int i = 0; i < size; i++) {
#pragma HLS pipeline II=1
#pragma HLS LOOP_TRIPCOUNT max=4096
        histogram[image[i]] += 1;
	}
}

}
