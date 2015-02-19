#ifndef _konrad_h
#define _konrad_h
#include <stdlib.h>

static size_t konrad = 0;

void countMem(size_t foo) {
	konrad += foo;
}

void printMem(){
	printf("\n Lost: %d \n", konrad);
}

#endif

