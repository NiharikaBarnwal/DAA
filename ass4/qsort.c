#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
int partition(int a[], int p, int r){
	int x=a[r];
	int i=p-1;
	int j,temp;
	for(j=p;j<r;j++){
		if(a[j]<=x){
			i++;
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
	}
	temp=a[i+1];
	a[i+1]=a[r];
	a[r]=temp;
	return i+1;
}
void quick_sort(int a[], int p,int r){
	if(p<r){
		int q=partition(a,p,r);
		quick_sort(a,p,q-1);
		quick_sort(a,q+1,r);
	}
}
int main(){
	int x=pow(10,5);
        int i,A[x],n;
        n=1000;
        for(i=0;i<x;i++){
                A[i]=rand()%(n+1);
        }
        clock_t start,end;
        double cpu_time;
        start = clock();
        quick_sort(A,0,x-1);
        end = clock();
        cpu_time = (double)(end - start);
        printf("Sorted array:\n");
        for(i=0;i<x;i++){
                printf("%d\n",A[i]);
        }
        printf("Time taken for unsorted array : %lf seconds\n",cpu_time/CLOCKS_PER_SEC);
	start = clock();
        quick_sort(A,0,x-1);
        end = clock();
        cpu_time = (double)(end - start);
        printf("Time taken for sorted array : %lf seconds\n",cpu_time/CLOCKS_PER_SEC);
}
