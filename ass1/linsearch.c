#include<stdio.h>
int linsearch(int a[],int i,int m,int x){
        if(i>m)
                return -1;
        if(a[i]==x)
                return i;
        else
                linsearch(a,i+1,m,x);
}
int main(){
	int i,a[5],n,x,m;
	printf("Enter the array size:");
        scanf("%d",&m);
	printf("Enter the array:");
	for(i=0;i<m;i++){
		scanf("%d",&a[i]);
	}
	printf("Enter the number to be searched:");
	scanf("%d",&n);
	x=linsearch(a,0,m,n);
	if(x==-1){
		printf("The no is not found");
	}
	else{
		printf("The no is at position %d",x);
	}
}
