/*
* Aim: To implement binary search algorithm in C
*
* Date: 28.Mai 2020
*/

#include<stdio.h>
#include<stdlib.h>

// binary search function
int bin_suche(int a[], int element, int upper, int lower){
	if(upper >= lower){		// this is to avoid infinite recursion and prevent Segmentation Faults
		int mid_pt = (upper + lower)/2;
		
		if(a[mid_pt] == element){	// return index on match found
			return mid_pt;
		}		
		
		if(a[mid_pt] < element){	// go the right side of the array to search the element
			return bin_suche(a, element, upper, mid_pt+1);
		}

		return bin_suche(a, element, mid_pt-1, lower);	// go to the eft side of the 
								// array to search for the element
	}
	else
		return -1;		// return -1 if no match found
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
	
	// TODO: Add a sort function to avoid dependence on input correctness
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
