#include<stdio.h>
#include<math.h>
int r1,c1,r2,c2;
float multiply_matrix_1(float a[][c1], float b[][c2], int r1, int c1, int r2, int c2){
	int i,j,k;
	float c[r1][c2];
	/*if(c1 != r1){
	printf("Invalid dimensions\n");
	return 0;
	}   */
	
	for(i=0;i<r1;i++){
	    for(j=0;j<r2;j++){
	        for(k=0;k<c2;k++){
	            c[i][j] += a[i][k]*b[j][k];
	            }
	            printf("%f ",c[i][j]);
	        }
	        printf("\n");
	    }		
}

void main(){

int i,j;
printf("Enter matrix 1 dimensions\n");
scanf("%d",&r1);
scanf("%d",&c1);
printf("Enter matrix 2 dimensions\n");
scanf("%d",&r2);
scanf("%d",&c2);
if(c1 != r2){
    printf("Invalid dimensions\n");
    }
float a[r1][c1];
float b[r2][c2];
printf("Enter matrix 1\n");
for(i=0;i<r1;i++){
    for(j=0;j<c1;j++){
    	scanf("%f",&a[i][j]);
    	}}
printf("Enter matrix 2\n");
for(i=0;i<r2;i++){
    for(j=0;j<c2;j++){
    	scanf("%f",&b[i][j]);
    	}}
printf("Your entered matrices\n");    	
for(i=0;i<r1;i++){
    for(j=0;j<c1;j++){
    	printf("%f ",a[i][j]);
    	}
    	printf("\n");
    	}
printf("\n");
for(i=0;i<r2;i++){
    for(j=0;j<c2;j++){
    	printf("%f ",b[i][j]);
    	}
    	printf("\n");
    	}
printf("\n");
multiply_matrix_1(a,b,r1,c1,r2,c2);
}
