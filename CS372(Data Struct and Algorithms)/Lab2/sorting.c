/* Lab2: Sorting
 * File: sorting.c
 * Sorts an array using 3 different sorting algorithm and finds their run time
 * Uses merge sort, quick sort, bubble sort
 * main function creates arrays of size 512, 1024, 2048, 4096 and fills them 
 * with random numbers from 0-1000 and sorts them using each algorithm and displays the run time
 * Santiago Flores
 * 9/16/2020
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//merge sort
void merge(int A[], int l, int m, int r) {
	int i, j, k;
	int l1 = m - l +1;
	int r1 = r - m;

	//create left and right of original array to merge
	int L[l1], R[r1];
	for(i = 0; i < l1; i++)
		L[i] = A[l+i];
	for(j = 0; j < r1; j++)
		R[j] = A[m+1 + j];

	i = 0;
	j = 0;
	k = l;
	//merge left and right into A 
	while(i < l1 && j < r1) {
		if(L[i] <= R[j]) {
			A[k] = L[i];
			i++;
		}
		else {
			A[k] = R[j];
			j++;
		}
		k++;
	}
	//merge remaining elements
	while(i < l1) {
		A[k] = L[i];
		i++;
		k++;
	}
	while(j < r1) {
		A[k] = R[j];
		j++;
		k++;
	}
}
//recursivly divide array into subproblems to merge back into order in merge function
void mergeSort(int A[], int l, int r) {
	if(l < r) {

		int m = (l+r)/2;

		mergeSort(A,l,m);
		mergeSort(A,m+1,r);

		merge(A,l,m,r);
	}
}

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int A[], int low, int high) {
	int pivot = A[low]; //use low end value as pivot
	int i = low;
	
	//move all values smaller than the pivot to the low end of the array
	for(int j = low+1; j <= high; j++) { 
		if(A[j] < pivot) {
			i++;
			swap(&A[i], &A[j]);
		}
	}
	//move the pivot so that all the smaller elements are on the left of it
	swap(&A[i], &A[low]); 
	return (i);
}
//recursivley work on array
void quickSort(int A[], int low, int high) {
	if(low < high) {
		int i = partition(A, low,high);
		
		quickSort(A,low,i-1);
		quickSort(A,i+1,high);
	}
}

void bubbleSort(int A[], int size) {
	int i, j;
	for(i = 0; i < size-1; i++) { 
		for(j = 0; j < size-i-1; j++) {
			if(A[j] > A[j+1]) {
				swap(&A[j], &A[j+1]);
			}
		}
	}
}
//prints The first and last 5 elements of the array with the given time in seconds
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
int main() {
	int a1[512],a2[512],a3[512]; 
	int b1[1024],b2[1024],b3[1024];
	int c1[2048],c2[2048],c3[2048];
	int d1[4096],d2[4096],d3[4096];
	int x, rnum=0;
	double time = 0;
	clock_t s,e;

/*-------Test for array size 512(a[512])--------*/
	for(x = 0; x < 512; x++) {
		rnum = rand() % 1001;
		a1[x] = rnum;
		a2[x] = rnum;
		a3[x] = rnum;
	}
	printf("\n----------Test for array size 512----------\n");
	//printArray(a1,512,0);
	printf("\nMerge Sort call");
	s = clock();
	mergeSort(a1,0,511);
	e = clock();
	time = (double)(e-s)/CLOCKS_PER_SEC;
	printArray(a1,512,time);
	
	printf("\nQuick Sort call");
	s = clock();
	quickSort(a2,0,511);
	e = clock();
	time = (double)(e-s)/CLOCKS_PER_SEC;
	printArray(a2,512,time);

	printf("\nBubble Sort call");
	s = clock();
	bubbleSort(a3,512);
	e = clock();
	time = (double)(e-s)/CLOCKS_PER_SEC;
	printArray(a3,512,time);

/*-------Test for array size 1024(b[1024])-------*/
	for(x = 0; x < 1024; x++) {
		rnum = rand() % 1001;
		b1[x] = rnum;
		b2[x] = rnum;
		b3[x] = rnum;
	}
	printf("\n----------Test for array size 1024----------\n");
	//printArray(b1,1024,0);
	printf("\nMerge Sort call");
	s = clock();
	mergeSort(b1,0,1023);
	e = clock();
	time = (double)(e-s)/CLOCKS_PER_SEC;
	printArray(b1,1024,time);
	
	printf("\nQuick Sort call");
	s = clock();
	quickSort(b2,0,1023);
	e = clock();
	time = (double)(e-s)/CLOCKS_PER_SEC;
	printArray(b2,1024,time);

	printf("\nBubble Sort call");
	s = clock();
	bubbleSort(b3,1024);
	e = clock();
	time = (double)(e-s)/CLOCKS_PER_SEC;
	printArray(b3,1024,time);

/*--------Test for array size 2048(c[2048])------------*/
	for(x = 0; x < 2048; x++) {
		rnum = rand() % 1001;
		c1[x] = rnum; 
		c2[x] = rnum; 
		c3[x] = rnum; 
	}
	printf("\n-----------Test for array size 2048----------\n");
	//printArray(c1,2048,0);
	printf("\nMerge Sort call");
	s = clock();
	mergeSort(c1,0,2047);
	e = clock();
	time = (double)(e-s)/CLOCKS_PER_SEC;
	printArray(c1,2048,time);

	printf("\nQuick Sort call");	
	s = clock();
	quickSort(c2,0,2047);
	e = clock();
	time = (double)(e-s)/CLOCKS_PER_SEC;
	printArray(c2,2048,time);

	printf("\nBubble Sort call");
	s = clock();
	bubbleSort(c2,2048);
	e = clock();
	time = (double)(e-s)/CLOCKS_PER_SEC;
	printArray(c2,2048,time);

/*--------Test for array size 4096(d[4096])----------*/
	for(x = 0; x < 4096; x++) {
		rnum = rand() % 1001;
		d1[x] = rnum;
		d2[x] = rnum;
		d3[x] = rnum;
	}
	printf("\n-----------Test for array size 4096-----------\n");
	//printArray(d1,4096,0);
	printf("\nMerge Sort call");
	s = clock();
	mergeSort(d1,0,4095);
	e = clock();
	time = (double)(e-s)/CLOCKS_PER_SEC;
	printArray(d1,4096,time);
	
	printf("\nQuick Sort call");
	s = clock();
	quickSort(d2,0,4095);
	e = clock();
	time = (double)(e-s)/CLOCKS_PER_SEC;
	printArray(d2,4096,time);

	printf("\nBubble sort test");
	s = clock();
	bubbleSort(d3,4096);
	e = clock();
	time = (double)(e-s)/CLOCKS_PER_SEC;
	printArray(d3,4096,time);

	return 0;
}
