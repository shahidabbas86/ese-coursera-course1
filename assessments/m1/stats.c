/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file <stats.c> 
 * @brief <Add Brief Description Here >
 *
 * <Add Extended Description Here>
 *
 * @author <Shahid Abbas>
 * @date <01.10.2017>
 *
 */


#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
	int min, max, mean, median;

  /* Statistics and Printing Functions Go Here */
	print_array(test, SIZE);
	min = find_minimum(test, SIZE);
//	printf("minimum: %u \n", min);
	max = find_maximum(test, SIZE);
//	printf("maxium: %u \n", max);
	mean = find_mean(test, SIZE);
//	printf("mean: %u \n", mean);
	median = find_median(test, SIZE);
//	printf("median: %u \n", median);
	print_statistics(min, max, mean, median);
	sort_array(test, SIZE);
	print_array(test, SIZE);

}

/* Add other Implementation File Code Here */
void print_array(unsigned char *ptr, int size)
{	
	int i;
	for ( i = 0; i< size; i++)
		printf("Array element [%d] : %u \n", i, *(ptr+i));
	printf("********************************************\n");
}

void sort_array(unsigned char *ptr, int size)
{
	int i, j; 
        unsigned char temp;
   
	for (i = 0; i < size; ++i)
	{
		for (j = i + 1; j < size; ++j)
		{
		    if (*(ptr+i) < *(ptr+j))
		    {
		        temp = *(ptr+i);
		        *(ptr+i) = *(ptr+j);
		        *(ptr+j)= temp;
		   }
		}
	 }

}

unsigned char find_minimum(unsigned char *ptr, int size)
{
	int i, j; 
        unsigned char minimum;
   
	for (i = 0; i < size; ++i)
	{
		for (j = i + 1; j < size; ++j)
		{
		    if (*(ptr+i) < *(ptr+j))
		    {
		        minimum = *(ptr+i);
			*(ptr+i) = *(ptr+j);
		        *(ptr+j)= minimum;
		   }
		}
	 }
	return minimum;
}

unsigned char find_maximum(unsigned char *ptr, int size)
{
	int i, j; 
        unsigned char maximum;
   
	for (i = 0; i < size; ++i)
	{
		for (j = i + 1; j < size; ++j)
		{
		    if (*(ptr+i) > *(ptr+j))
		    {
		        maximum = *(ptr+i);
			*(ptr+i) = *(ptr+j);
		        *(ptr+j)= maximum;
		   }
		}
	 }
	return maximum;
}

int find_mean(unsigned char *ptr, int size)
{
	int i; 
        float mean = 0;
	for (i = 0; i < size; ++i)
	{
		mean = mean + *(ptr+i);
	}
	mean = mean/size;
	return mean;
}

int find_median(unsigned char *ptr, int size)
{
	int i, j; 
        unsigned char temp;
   
	for (i = 0; i < size; ++i)
	{
		for (j = i + 1; j < size; ++j)
		{
		    if (*(ptr+i) < *(ptr+j))
		    {
		        temp = *(ptr+i);
		        *(ptr+i) = *(ptr+j);
		        *(ptr+j)= temp;
		   }
		}
	 }
	if(size%2==0) 
        	return((*(ptr+size/2) + *(ptr+size/2 - 1)) / 2);
	else
       		return *(ptr+size/2);
}

void print_statistics(int min, int max, int mean, int median)
{
	printf("Array Statistics\n");
	printf("Minimum: %u \n", min);
	
	printf("Maxium: %u \n", max);
	
	printf("Mean: %u \n", mean);
	
	printf("Median: %u \n", median);
	printf("********************************************\n");
}
