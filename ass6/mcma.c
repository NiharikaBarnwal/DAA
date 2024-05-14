#include<stdio.h>
#include<limits.h>
#define length 7
int M[length-1][length-1];
int S[length-1][length-1];
void MATRIX_CHAIN_ORDER(int P[length])
{
        int n=length-1,j,q;
        for(int i=1;i<=n;i++)
        {
                M[i][i]=0;
        }
        for(int l=2;l<=n;l++)
        {
                for(int i=1;i<=n-l+1;i++)
                {
                        j=i+l-1;
                        M[i][j]=INT_MAX;
                        for(int k=i;k<=j-1;k++)
                        {
                                q=M[i][k]+M[k+1][j]+(P[i-1]*P[k]*P[j]);
                                if(q<M[i][j])
                                {
                                        M[i][j]=q;
                                        S[i][j]=k;
                                }
                        }
                }
        }
}
void PRINT_OPTIMAL_PAREN(int S[length-1][length-1],int i,int j)
{
        if(i==j)
        {
                printf("A%d",i);
        }
        else
        {
                printf("(");
                PRINT_OPTIMAL_PAREN(S,i,S[i][j]);
                PRINT_OPTIMAL_PAREN(S,S[i][j]+1,j);
                printf(")");
        }
}
void PRINT_MAT(int A[length-1][length-1])
{
	int i,j;
        for(i=1;i<length;i++)
        {
                for(j=1;j<length;j++)
                {
			if(i<=j)
                        	printf("%d\t",A[i][j]);
			else
				printf(" \t");
                }
                printf("\n");
        }
}
int main()
{
        int P[length];
        printf("Enter P:\n");
        for(int i=0;i<length;i++)
        {
                scanf("%d",&P[i]);
        }
        MATRIX_CHAIN_ORDER(P);
	printf("S is:\n");
        PRINT_MAT(S);
	printf("M is:\n");
        PRINT_MAT(M);
        printf("Optimal Paranthesization is:\n");
        PRINT_OPTIMAL_PAREN(S,1,length-1);
	printf("\n");
	return 0;
}

