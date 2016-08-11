#include<stdio.h>
#define SIZE 9

void printarr(int[],int);
void swap(int*,int*);
int partition(int[],int,int,int);
void quickSort(int[],int,int);

int main(){
	int ar[]={2,5,3,4,1,7,6,8,9};
	quickSort(ar,0,SIZE-1);
	printarr(ar,SIZE);
	return 0;
}

int partition(int ar[],int p,int n,int pivot){
	int i=p;
	int j=n;

	while(i<=j){
		while(i<=n && ar[i]<pivot)
			i++;
		while(j>=p && ar[j]>pivot)
			j--;

		if(i<j){
			swap(&ar[i],&ar[j]);
			i++,j--;
		}
	}
	printarr(ar,n-p+2);
	return j;
}

void quickSort(int ar[],int p,int n){
	int pivot=ar[p];
	int j;

	if(p<n){
		j=partition(ar,p+1,n,pivot);
		swap(&ar[j],&ar[p]);
		quickSort(ar,p,j-1);
		quickSort(ar,j+1,n);
	}
}

void swap(int *a,int *b){
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

void printarr(int ar[],int size){
	printf("\n");
	for(int i=0;i<size;i++)
		printf("%d ",ar[i]);
	printf("\n");
}