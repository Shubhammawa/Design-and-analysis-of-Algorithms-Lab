#include<stdio.h>

typedef struct {
	int row;
	int col;
	float data;
	}sparse;

int main(){
	sparse matrix_a[5] = {
	{1,2,4},{2,3,1},{4,1,2}};
	sparse matrix_b[5] = {
	{2,2,2},{3,1,1},{1,3,4}};
	
	sparse prod[5];
	
	int i,j,k=0,l=0;
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			if(matrix_a[i].col == matrix_b[j].row){
				l=0;
				while(l<k){
					if(prod[l].row == matrix_a[i].row && prod[l].col == matrix_b[j].col){
						prod[l].data += matrix_a[i].data*matrix_b[j].data;
						break;
						}
					l++;
				}
				if(l==k){
				prod[k].row = matrix_a[i].row;
				prod[k].col = matrix_b[j].col;
				prod[k].data = matrix_a[i].data*matrix_b[j].data;
				k++;
				}
			}
		}
	}
	int r;
	for(r=0;r<l;r++){
		printf("Row = %d ",prod[r].row);
		printf("Col = %d ",prod[r].col);
		printf("Value = %f ",prod[r].data);
		printf("\n");
	}
}
