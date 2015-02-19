#ifndef _mytime_h
#define _mytime_h

#include <sys/time.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "ArrayList.h"


struct timeval timeStamp_m_1, timeStamp_m_2;
struct timeval timeStamp_f_1, timeStamp_f_2;


ArrayList * al_m = NULL;
ArrayList * al_f = NULL;



void start_m(){
	if(al_m == NULL)
		al_m = newArrayList(10);
	
	gettimeofday(&timeStamp_m_1, NULL); /*starta timer*/
}

void start_f(){
	if(al_f == NULL)
		al_f = newArrayList(10);
	
	gettimeofday(&timeStamp_f_1, NULL); /*starta timer*/
}

void end_m(){
	gettimeofday(&timeStamp_m_2, NULL); /*stop timer*/
	double result = ((double)(timeStamp_m_2.tv_usec - timeStamp_m_1.tv_usec)/1000);
	
	add_al(al_m,result);
}

void end_f(){
	gettimeofday(&timeStamp_f_2, NULL); /*stop timer*/
	double result = ((double)(timeStamp_f_2.tv_usec - timeStamp_f_1.tv_usec)/1000);
	
	add_al(al_f,result);
}

void printresults(){

	/*
	printf("Malloc: ");
	print_al(al_m);
	
	
	printf("Free: ");
	print_al(al_f);
	*/

	
		double mean_m = mean_al(al_m);
		printf("Malloc (mean (ms)): %f, \n", mean_m);
		destroy_al(al_m);
	
	
	if(al_f != NULL){
		

	
	
		double mean_f = mean_al(al_f);
		printf("Free (mean (ms)): %f, \n", mean_f);
		destroy_al(al_f);
		
	}
	
	
}

#endif
