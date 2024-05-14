#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void merge(int A[],int p, int q, int r){
	int i,j,k;
	int n1=q-p+1;
	int n2=r-q;
	int L[n1],R[n2];
	for(i=0;i<n1;i++){
		L[i]=A[p+i];
	}
	for(j=0;j<n2;j++){
		R[j]=A[q+1+j];
	}
	i=0;
	j=0;
	k=p;
	while(i<n1 && j<n2){
		if(L[i]<=R[j]){
			A[k]=L[i];
			i++;
		}
		else{
			A[k]=R[j];
			j++;
		}
		k++;
	}
	while(i<n1){
		A[k]=L[i];
		i++;
		k++;
	}
	while(j<n2){
		A[k]=R[j];
                j++;
                k++;
	}
}
void merge_sort(int A[],int p,int r){
	if(p<r){
	int q=(r+p-1)/2;
	merge_sort(A,p,q);
	merge_sort(A,q+1,r);
	merge(A,p,q,r);
	}
}
int main(){
	int i,A[1000000],n;
	n=1000;
	for(i=0;i<1000000;i++){
		A[i]=rand()%(n+1);
	}
	clock_t start,end;
	double cpu_time;
	start = clock();
	merge_sort(A,0,1000000-1);
	end = clock();
	cpu_time = (double)(end - start);
	printf("Sorted array:\n");
        for(i=0;i<1000000;i++){
                printf("%d\n",A[i]);
        }
	printf("Time taken : %lf seconds\n",cpu_time/CLOCKS_PER_SEC);
}
