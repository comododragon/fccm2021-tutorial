extern "C" {

void hist(unsigned char *image, unsigned int *histogram, int size) {
    for(unsigned int i = 0; i < size; i++) {
#pragma HLS PIPELINE II=1
#pragma HLS LOOP_TRIPCOUNT max=1024
        histogram[image[i]] += 1;
    }
}

}
