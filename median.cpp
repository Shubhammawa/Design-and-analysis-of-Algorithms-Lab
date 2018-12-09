#include<stdio.h>
#include<stdlib.h>

//int randomPartition(int A[], int l, int r);
void swap(int *A, int *B){
	int temp = *A;
	*A = *B;
	*B = temp;
}

int partition(int A[], int l, int r){
	
	int x = A[r], i = l;
	
	for(int j = l; j <= r-1; j++){
		
		if(A[j] <= x){
			swap(&A[i], &A[j]);
			i++;
		}
	}
	swap(&A[i], &A[r]);
	return i;
}

int randomPartition(int A[], int l, int r){
	int n = r-l+1;
	int p = rand()%n;
	swap(&A[l+p], &A[r]);
	return partition(A,l,r);
}
int kth_Smallest(int A[], int l, int r, int k){
	if(k>0 && k <= r-l+1){
		
		int pos = randomPartition(A,l,r);
		
		if(pos-l == k-1)
			return A[pos];
		if(pos-l > k-1)
			return kth_Smallest(A,l,pos-1,k);
		return kth_Smallest(A,pos+1,r,k-pos+l-1);
		}
		
	return 0;
	}

int main(){
	int n,k;
	printf("Enter the array size: ");
	scanf("%d",&n);
	int A[n];
	printf("\nEnter the elements\n");
	for(int i=0;i<n;i++)
		scanf("%d",&A[i]);
	printf("Entered array: \n");
	for(int i=0;i<n;i++)
		printf("%d ",A[i]);
	printf("\nEnter the value of k: ");
	scanf("%d",&k);
		
	printf("\nkth order statistic is : %d",kth_Smallest(A,0,n-1,k));
	printf("\n");
}
