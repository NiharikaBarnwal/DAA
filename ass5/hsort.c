#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
int length=pow(10,5);
int heapsize;
int PARENT(int i){
	return i/2;
}
int LEFT(int i){
	return 2*i;
}
int RIGHT(int i){
	return (2*i)+1;
}
void MAX_HEAPIFY(int A[], int i){
	int l=LEFT(i);
	int r=RIGHT(i);
	int largest;
	if(l<=heapsize && A[l]>A[i]){
		largest=l;
	}
	else{
		largest=i;
	}
	if(r<=heapsize && A[r]>A[largest]){
		largest=r;
	}
	if(largest!=i){
		int temp=A[i];
		A[i]=A[largest];
		A[largest]=temp;
		MAX_HEAPIFY(A,largest);
	}
}
void BUILD_MAX_HEAP(int A[]){
	int i;
	heapsize=length;
	for(i=length/2;i>=1;i--){
		MAX_HEAPIFY(A,i);
	}
}
void HEAP_SORT(int A[]){
	int i;
	BUILD_MAX_HEAP(A);
	for(i=length;i>=2;i--){
		int temp=A[1];
		A[1]=A[i];
		A[i]=temp;
		heapsize=heapsize-1;
		MAX_HEAPIFY(A,1);
	}
}
int main(){
        int i,A[length],n;
        n=1000;
        for(i=0;i<length;i++){
                A[i]=rand()%(n+1);
        }
        clock_t start,end;
        double cpu_time;
        start = clock();
        HEAP_SORT(A);
        end = clock();
        cpu_time = (double)(end - start);
        printf("Sorted array:\n");
        for(i=0;i<length;i++){
                printf("%d\n",A[i]);
        }
        printf("Time taken for unsorted array : %lf seconds\n",cpu_time/CLOCKS_PER_SEC);
        start = clock();
        HEAP_SORT(A);
        end = clock();
        cpu_time = (double)(end - start);
        printf("Time taken for sorted array : %lf seconds\n",cpu_time/CLOCKS_PER_SEC);
}

