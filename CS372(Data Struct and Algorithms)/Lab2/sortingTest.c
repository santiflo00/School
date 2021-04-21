/*#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sorting.h"

void printArray(int A[], int size, double time) {
	if(time != 0)
		printf("\nTime to sort array: %fs\n", time);
	printf("First 5 elements of Array: ");
	for(int i = 0; i < 5; i++)
		printf("A[%d]=%d | ",i, A[i]);

	printf("\nLast 5 elements of Array: ");
	for(int j = size-5; j < size; j++)
		printf("A[%d]=%d | ",j, A[j]);

	printf("\n");
}

void test() {
	int A1[] = {87,76,981,765,542,112,991,6};
	int A2[] = {87,76,981,765,542,112,991,6};
	int A3[] = {87,76,981,765,542,112,991,6};
	int size = sizeof(A1)/sizeof(A1[0]);
	clock_t start, end;
	double time = 0;

	printf("Starting test array: ");
	for(int i = 0; i < size; i++)
		printf("%d | ", A1[i]);
	printf("\n");
	
	//Test for merge Sort
	printf("\nTest for merge Sort");
	start = clock();
	mergeSort(A1,0,size-1);
	end = clock();
	time = (double)(end-start)/CLOCKS_PER_SEC;
	printArray(A1,size,time);
	
	//Test for quick Sort
	printf("\nTest for quick Sort");
	start = clock();
	quickSort(A2, 0, size-1);
	end = clock();
	time = (double)(end-start)/CLOCKS_PER_SEC;
	printArray(A2,size,time);
	
	//Test for bubble sort
	printf("\nTest for bubble sort");
	start = clock();
	bubbleSort(A3,8);
	end = clock();
	time = (double)(end-start)/CLOCKS_PER_SEC;
	printArray(A3,size,time);

}

int main() {
//	test();
	
	int a1[512],a2[512],a3[512]; 
	int b1[1024],b2[1024],b3[1024];
	int c1[2048],c2[2048],c3[2048];
	int d1[4096],d2[4096],d3[4096];
	int x, rnum=0;
	double time = 0;
	clock_t s,e;

//-------Test for array size 512(a[512])--------
	for(x = 0; x < 512; x++) {
		rnum = rand() % 1001;
		a1[x] = rnum;
		a2[x] = rnum;
		a3[x] = rnum;
	}
	printf("\nTest for array size 512\n");
	printArray(a1,512,0);
	s = clock();
	mergeSort(a1,0,511);
	e = clock();
	time = (double)(e-s)/CLOCKS_PER_SEC;
	printArray(a1,512,time);
	
	s = clock();
	quickSort(a2,0,511);
	e = clock();
	time = (double)(e-s)/CLOCKS_PER_SEC;
	printArray(a2,512,time);

	s = clock();
	bubbleSort(a3,512);
	e = clock();
	time = (double)(e-s)/CLOCKS_PER_SEC;
	printArray(a3,512,time);

//  -----Test for array size 1024(b[1024])-------
	for(x = 0; x < 1024; x++) {
		rnum = rand() % 1001;
		b1[x] = rnum;
		b2[x] = rnum;
		b3[x] = rnum;
	}
	printf("\nTest for array size 1024\n");
	printArray(b1,1024,0);
	s = clock();
	mergeSort(b1,0,1023);
	e = clock();
	time = (double)(e-s)/CLOCKS_PER_SEC;
	printArray(b1,1024,time);
	
	s = clock();
	quickSort(b2,0,1023);
	e = clock();
	time = (double)(e-s)/CLOCKS_PER_SEC;
	printArray(b2,1024,time);

	s = clock();
	bubbleSort(b3,1024);
	e = clock();
	time = (double)(e-s)/CLOCKS_PER_SEC;
	printArray(b3,1024,time);

//--------Test for array size 2048(c[2048])------------
	for(x = 0; x < 2048; x++) {
		rnum = rand() % 1001;
		c1[x] = rnum; 
		c2[x] = rnum; 
		c3[x] = rnum; 
	}
	printf("\nTest for array size 2048\n");
	printArray(c1,2048,0);
	s = clock();
	mergeSort(c1,0,2047);
	e = clock();
	time = (double)(e-s)/CLOCKS_PER_SEC;
	printArray(c1,2048,time);
	
	s = clock();
	quickSort(c2,0,2047);
	e = clock();
	time = (double)(e-s)/CLOCKS_PER_SEC;
	printArray(c2,2048,time);

	s = clock();
	bubbleSort(c2,2048);
	e = clock();
	time = (double)(e-s)/CLOCKS_PER_SEC;
	printArray(c2,2048,time);

//--------Test for array size 4096(d[4096])----------
	for(x = 0; x < 4096; x++) {
		rnum = rand() % 1001;
		d1[x] = rnum;
		d2[x] = rnum;
		d3[x] = rnum;
	}
	printf("\nTest for array size 4096\n");
	printArray(d1,4096,0);
	s = clock();
	mergeSort(d1,0,4095);
	e = clock();
	time = (double)(e-s)/CLOCKS_PER_SEC;
	printArray(d1,4096,time);
	
	s = clock();
	quickSort(d2,0,4095);
	e = clock();
	time = (double)(e-s)/CLOCKS_PER_SEC;
	printArray(d2,4096,time);

	s = clock();
	bubbleSort(d3,4096);
	e = clock();
	time = (double)(e-s)/CLOCKS_PER_SEC;
	printArray(d3,4096,time);

	return 0;
}*/
