#include<stdio.h>
#include<math.h>
#include<time.h>
void merge(int A[],int l, int u, int m){
	
	int i,j,k;
	int n1 = m-l+1;
	int n2 = u - m ;
	
	int L[n1], R[n2];
	
	for(i=0;i<n1;i++)
		L[i] = A[l+i];
	for(j =0;j<n2;j++)
		R[j] = A[m+1+j];
	
	i = 0;
	j = 0;
	k = l;
	
	while(i<n1 && j<n2){
	if(L[i] <=R[j]){
	A[k] = L[i];
	i++;
	}
	else{
	A[k] =R[j];
	j++;
	}
	k++;
}
	while(i<n1){
		A[k] = L[i];
		i++;
		k++;
	}
	
	while(j<n2){
		A[k] = R[j];
		j++;
		k++;
	}
	}
void mergesort(int A[], int l, int u){
	if(l<u){
	int m = 0;
	m = l + (u-l)/2;
	mergesort(A,l,m);
	mergesort(A,m+1,u);
	merge(A,l,u,m);
	}
}

int main(){
int A[] = {7,3,9,4,1,5,8};
int arr_size = sizeof(A)/sizeof(A[0]);
printf("Array size = %d\n",arr_size);
printf("Given array is \n");
for(int i =0;i<arr_size;i++){
	printf("%d ",A[i]);
	}
printf("\n");	
clock_t t;
t = clock();
mergesort(A,0,arr_size-1);
t = clock()-t;
double d = ((double)t)/CLOCKS_PER_SEC;
printf("%f\n",d);
printf("Sorted array is \n");
for(int i =0;i<arr_size;i++){
	printf("%d ",A[i]);
	}
}
