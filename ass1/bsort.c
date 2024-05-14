#include<stdio.h>
void bsort(int a[],int n){
	int i,j,temp;
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(a[i]>a[j]){
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
}
int main(){
	int i,a[20],n;
        printf("Enter the array size:");
        scanf("%d",&n);
        printf("Enter the array:");
        for(i=0;i<n;i++){
                scanf("%d",&a[i]);
        }
	bsort(a,n);
	printf("The sorted array is:");
	for(i=0;i<n;i++){
                printf("%d ",a[i]);
        }
}
