#include<stdio.h>
#include<stdlib.h>

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

void randomized_quicksort(float A[], int p, int q, int k){
	if(p<q){
		float temp2;
		int random = p + rand()%(q-p+1);
		temp2 = A[p];
		A[p] = A[random];
		A[random] = temp2;
		int r = partition(A,p,q);
		if(r==(k-1)){
			return;
			}
		randomized_quicksort(A,p,r-1,k);
		randomized_quicksort(A,r+1,q,k);
		}
}

int main(){
	int n;
	printf("Enter array size : ");
	scanf("%d",&n);
	float A[n];
	int k;
	float key;
	for(int i=0;i<n;i++){
		scanf("%f",&A[i]);
		}
	printf("Enter the value of k: ");
	scanf("%d",&k);
	randomized_quicksort(A,0,n-1,k);
	printf("kth smallest element is: %f",A[k-1]);
	printf("\n");
	
}
