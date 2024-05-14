#include<stdio.h>
#include<stdlib.h>
char B[20][20];
void LCS_LENGTH(char X[], char Y[], int m, int n){
	int C[m+1][n+1];
	for(int i=0;i<=m;i++)
		C[i][0]=0;
	for(int j=0;j<=n;j++)
		C[0][j]=0;
	for(int i=1;i<=m;i++){
		for(int  j=1;j<=n;j++){
			if(X[i]==Y[j]){
				C[i][j]=C[i-1][j-1]+1;
				B[i][j]='d';
			}
			else if(C[i-1][j]>=C[i][j-1]){
				C[i][j]=C[i-1][j];
				B[i][j]='u';
			}
			else{
				C[i][j]=C[i][j-1];
				B[i][j]='l';
			}
		}
	}
}
void PRINT_LCS(int i,int j, char X[]){
	if(i==0 || j==0)
		return;
	else{
		if(B[i][j]=='d'){
			PRINT_LCS(i-1,j-1,X);
			printf("%c ",X[i]);
		}
		else if(B[i][j]=='l')
			PRINT_LCS(i,j-1,X);
		else
			PRINT_LCS(i-1,j,X);
	}
}
int main(){
	int m,n;
	printf("Enter the length of 1st sequence:");
	scanf("%d",&m);
	char X[m];
	printf("Enter the 1st sequence:");
	for(int i=1;i<=m;i++)
		scanf(" %c",&X[i]);
	 printf("Enter the length of 2nd sequence:");
        scanf("%d",&n);
        char Y[n];
        printf("Enter the 2nd sequence:");
        for(int i=1;i<=n;i++)
                scanf(" %c",&Y[i]);
	LCS_LENGTH(X,Y,m,n);
	printf("The LCS is: ");
	PRINT_LCS(m,n,X);
	printf("\n");
}
