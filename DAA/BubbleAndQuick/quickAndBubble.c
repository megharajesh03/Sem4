#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define size 100000000
int a[size],b[size];
void printArray(int a[],int n){
	for(int i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
}

void swap(int a,int b){
	int temp;
	temp=a;
	a=b;
	b=temp;
}

int partition(int a[], int low, int high)
{

    int i, j, pivot,temp1,temp2;
    pivot=a[high];
    i=low-1;
    for(j=low;j<high;j++)
    {
        if(a[j]<=pivot)
        {
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[high]);
    return i+1;
    
}
void quickSort(int a[],int low,int high){
	int loc;
	if (low<high){
		loc=partition(a,low,high);
		quickSort(a,low,loc-1);
		quickSort(a,loc+1,high);
	}
}

void bubbleSort(int a[],int n){
	int i,j,temp;
	for(i=0;i<n-1;i++){
		for(j=0;j<n-i-1;j++){
			if(a[j]>a[j+1]){
				swap(a[j],a[j+1]);
			}
		}
	}
}

void main(){
	int i,j,temp,n;
	clock_t start1,start2,end1,end2;
	double timeElapsed1,timeElapsed2;
	printf("Comparison between QuickSort and BubbleSort\n");
	printf("Enter the no. of elements in the array:");
	scanf("%d",&n);
	//generate random array
	for(i=0;i<n;i++){
		a[i]=rand()%100;
		b[i]=a[i];
	}
	start1=clock();
	bubbleSort(a,n);
	end1=clock();
	timeElapsed1=(double)(end1-start1)/CLOCKS_PER_SEC;
	start2=clock();
	quickSort(b,0,n-1);
	end2=clock();
	timeElapsed2=(double)(end2-start2)/CLOCKS_PER_SEC;
	printf("Time for bubble sort: %f\n",timeElapsed1);
	printf("Time for quick sort: %f\n",timeElapsed2);
	
	FILE *fptr;
	fptr=fopen("/home/megharajesh/sort.txt","a+");
	fprintf(fptr,"%-15d\t%-15f\t%-15f\n",n,timeElapsed1,timeElapsed2);
	fclose(fptr);
}
