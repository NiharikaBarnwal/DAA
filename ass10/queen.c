#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>
int x[10];
bool PLACE(int k, int i){
	for(int j=0;j<k;j++){
		if((x[j]==i) || ( abs(x[j]-i) == abs(j-k)))
			return false;
	}
	return true;
}
void N_QUEEN(int k, int n){
	for(int i=0;i<n;i++){
		if(PLACE(k,i)==true){
			x[k]=i;
			if(k==n-1){
				for(int j=0;j<n;j++)
					printf("%d ",x[j]+1);
				printf("\n");
			}
			else
				N_QUEEN(k+1,n);
		}
	}
}
int main(){
	int n;
	printf("Enter the no. of queens: ");
	scanf("%d",&n);
	printf("The possible solutions are:\n");
	N_QUEEN(0,n);
	return 0;
}
