#include<stdio.h>
int bsearch(int a[],int n,int x,int y){
        int m;
        if(x>y){
		return -1;
	}
        m=(x+y)/2;
        if(a[m]==n){
                return m;
        }
        else if(a[m]<n){
                
                return bsearch(a,n,m+1,y);
        }
        else{
                return bsearch(a,n,x,m-1);
        }
}
int main(){
        int i,a[20],n,x,m;
	printf("Enter the array size:");
	scanf("%d",&m);
        printf("Enter the array:");
        for(i=0;i<m;i++){
                scanf("%d",&a[i]);
        }
        printf("Enter the number to be searched:");
        scanf("%d",&n);
        x=bsearch(a,n,0,m);
        if(x==-1){
                printf("The no is not found\n");
        }
        else{
                printf("The no is at index %d\n",x);
        }
}
