#include<stdio.h>

void swap(float *x,float *y){
	float temp = *x;
	*x = *y;
	*y = temp;
	}

void heapify(float A[], int n, int i){

	int max = i;
	int l = 2*i+1;
	int r = 2*i+2;
	
	if(l<n && A[l] > A[max]){
		max = l;
		}
	if(r<n && A[r] > A[max]){
		max = r;
		}
	if(max != i){
		swap(&A[i], &A[max]);
		heapify(A,n,max);
		}
			
}

void Heapsort(float A[], float n ){
	
	int i;
	
	for(i = n/2 -1; i>=0;i--){
		heapify(A,n,i);
	}
	
	for(i=n-1;i>=0;i--){
		swap(&A[0],&A[i]);
		heapify(A,i,0);
	}	
}

typedef struct{
	char name[50];
	char roll_no[10];
	float cgpa;
	}student;

int main(){

	int n;
	printf("Enter the array size: ");
	scanf("%d",&n);
	float A[n];
	printf("\nEnter the elements\n");
	for(int i=0;i<n;i++)
		scanf("%f",&A[i]);
		
	printf("Entered array: \n");
	for(int i=0;i<n;i++)
		printf("%f ",A[i]);
	Heapsort(A,n);
	printf("\nSorted array:\n");
	for(int i=0;i<n;i++)
		printf("%f ",A[i]);
		
	
	/*student record[5];
	
	record[0] = {"A","16IM10033",8.52};
	record[1] = {"B","16IM10034",9.78};
	record[2] = {"C","16IM10035",9.94};
	record[3] = {"D","16IM10036",8.98};
	record[4] = {"E","16IM10037",9.09};
	*/
	}

		
		

