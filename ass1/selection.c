#include<stdio.h>
void ssort(int a[],int m,int n){
	int min,i,temp,j;
	a[min]=a[m];
	for(j=0;j<n;j++){
	for(i=m+1;i<n;i++){
		if(a[i]<min)
			min=i;
	}
	temp=a[m];
	a[m]=a[min];
	a[min]=temp;
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
        ssort(a,0,n);
        printf("The sorted array is:");
        for(i=0;i<n;i++){
                printf("%d ",a[i]);
        }
}
