#include<stdio.h>

#define SIZE 8

void swap(int*,int*);
void printarr(int[],int);
void Heapify(int[],int,int);
void buildHeap(int[],int);
void heapSort(int[],int,int);

int main(){
	int ar[]={5,6,8,7,2,0,1,3};
	heapSort(ar,0,SIZE-1);
	printarr(ar,SIZE);
}

void Heapify(int ar[],int root,int n){
 	int left=2*root+1;
	int right=2*root+2;
	int largest=root;

	if(ar[left]>ar[root] && left<=n){
		largest=left;
	}
	if(ar[right]>ar[largest] && right<=n){
		largest=right;
	}

	if(largest!=root){
		swap(&ar[root],&ar[largest]);
		Heapify(ar,largest,n);
	}
}

void buildHeap(int ar[],int n){
	for(int i=n/2;i>=0;i--){
		Heapify(ar,i,n);
	}
}

void heapSort(int ar[],int root,int n){
	buildHeap(ar,n);
	int i;

	for(i=n;i>0;i--){
		swap(&ar[root],&ar[i]);
		Heapify(ar,root,i-1);
	}
}

void swap(int *a,int *b){
	int temp=*b;
	*b=*a;
	*a=temp;
}

void printarr(int ar[],int size){
	printf("\n");
	for(int i=0;i<size;i++)
		printf("%d ",ar[i]);
	printf("\n");
}