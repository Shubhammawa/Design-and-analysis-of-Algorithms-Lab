#include<stdio.h>
#include<math.h>
#include<string.h>

struct student {
 char name[50];
 char roll[50];
 float cgpa;
 };
 
void swapping(float *x, float *y)
{
	float temp=*x;
	*x=*y;
	*y=temp;
	}
	
void heapify(float arr[], int n, int i)
{
	int large=i;
	int l=2*i+1;
	int r=2*i+2;
	
	if (l<n && arr[l]>arr[large])
	{
		large = l;
		}
	if (r<n && arr[r]>arr[large])
	{
		large=r;
		}
	if (large!=i)
	{
		swapping(&arr[i],&arr[large]);
		
		heapify(arr,n,large);
		}
	}
void heapsort(float arr[], int n)
{
	int i=0;
	for(i=n/2-1;i>=0;i--)
	{
			heapify(arr,n,i);
		}
	for (i=n-1;i>=0;i--)
	{
		swapping(&arr[0],&arr[i]);
		
		heapify(arr,i,0);
		}
	}

int main()
{
	struct student s[5];
	strcpy(s[0].name, "A");
	strcpy(s[0].roll, "16IM10029");
	s[0].cgpa=8.24;
	strcpy(s[1].name, "B");
	strcpy(s[1].roll, "16IM10006");
	s[1].cgpa=8.12;
	strcpy(s[2].name, "C");
	strcpy(s[2].roll, "16IM10035");
	s[2].cgpa=8.8;
	strcpy(s[3].name, "D");
	strcpy(s[3].roll, "16IM10032");
	s[3].cgpa=8.52;
	strcpy(s[4].name, "E");
	strcpy(s[4].roll, "16IM10001");
	s[4].cgpa=8.5;
	
	float arr[5];
	int i;
	for(i=0;i<5;i++)
	{
		arr[i]=s[i].cgpa;
		}
		
	int n=sizeof(arr)/sizeof(arr[0]);
	
	heapsort(arr,n);
	float max=arr[n-1];
	
	for(i=0;i<n;i++)
	{
		if(max==s[i].cgpa)
		{
			printf("%s,%s,%f\n",s[i].name,s[i].roll,s[i].cgpa);
			}
		}
	}
