/*
* Aim: To implement binary search in C
*
* Date: 28.Mai 2020
*/

#include<stdio.h>
#include<stdlib.h>

int binsearch(int a[], int element, int upper, int lower){
	int mid_pt = lower + (upper - 1)/2;
	if(element < a[mid_pt]){
		return binsearch(a, element, mid_pt, lower);
	}
	else if(element > a[mid_pt]){
		return binsearch(a, element, upper, mid_pt);
	}
	else if(element == a[mid_pt]){
		printf("Element found!\n");
		return mid_pt;
	}
	else
		return -1;
}

int main(void){
	int i = 0;
	int n = 0;
	int element = 0;
	int ret = 0;
	int a[100];
	printf("---Binary Search----\n");
	printf("Enter the no of elements: ");
	scanf("%d",&n);
	printf("Enter the sorted array\n");
	for(i=0; i<n; i++){
		printf("Element no. %d: ",i);
		scanf("%d", &a[i]);
		printf("\n");
	}
	printf("Enter the element to be searched: ");
	scanf("%d",&element);
	ret = binsearch(a, element, 0, n-1);
	if(ret < 0){
		printf("Element could not be found in the array\n");
	}
	else{
		printf("Element found at position: %d\n",ret);
	}
	return 0;
}
