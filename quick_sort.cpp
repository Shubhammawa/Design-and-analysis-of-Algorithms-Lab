#include<stdio.h>
// Partition function 
// Quick_sort function

int partition(float A[], int p, int q){
	float x = A[p];
	int i = p;
	float temp = 0;

	for(int j=p+1;j<=q;j++){
		if(A[j]<x){
			
			i++;
			
			temp = A[i];
			A[i] = A[j];
			A[j] = temp;
		}
	}
	
	temp = A[p];
	A[p] = A[i];
	A[i] = temp;
	
	return i;
}

int quicksort(float A[], int p, int q){
	if(p<q){
		
		int r = partition(A,p,q);
		quicksort(A,p,r-1);
		quicksort(A,r+1,q);
		}
}

int main(){
	int n;
	printf("Enter array size : ");
	scanf("%d",&n);
	float A[n];
	for(int i=0;i<n;i++){
		scanf("%f",&A[i]);
		}
	quicksort(A,0,n-1);
	printf("Sorted Array\n");
	for(int i=0;i<n;i++){
		printf("%f ",A[i]);
		}
}
