extern "C" {

#define HISTOGRAM_SIZE 256

void hist(unsigned char *image, unsigned int *histogram, int size) {
    static unsigned int lHist[HISTOGRAM_SIZE];
    unsigned char prevElem = 0;
    unsigned int histCache = 0;

    for(unsigned int i = 0; i < size; i++) {
#pragma HLS PIPELINE II=1
#pragma HLS LOOP_TRIPCOUNT max=1024
        unsigned char currElem = image[i];

        if(currElem == prevElem) {
            histCache++;
        }
        else {
            lHist[prevElem] = histCache;
            histCache = lHist[currElem] + 1;
            prevElem = currElem;
        }
    }

    lHist[prevElem] = histCache;

    for(unsigned int i = 0; i < HISTOGRAM_SIZE; i++)
        histogram[i] = lHist[i];
}

}
