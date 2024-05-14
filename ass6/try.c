#include<stdio.h>
#include<limits.h>
#define length 7
int M[length][length];
int S[length][length];

void MATRIX_CHAIN_ORDER(int P[length]) {
    int n = length - 1, j, q;
    for (int i = 1; i <= n; i++) {
        M[i][i] = 1;
    }
    for (int l = 2; l <= n; l++) {
        for (int i = 1; i <= n - l + 1; i++) {
            j = i + l - 1;
            M[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; k++) {
                q = M[i][k] + M[k + 1][j] + (P[i - 1] * P[k] * P[j]);
                if (q < M[i][j]) {
                    M[i][j] = q;
                    S[i][j] = k;
                }
            }
        }
    }
}

void PRINT_OPTIMAL_PAREN(int i, int j) {
    if (i == j) {
        printf("A%d", i);
    } else {
        printf("(");
        PRINT_OPTIMAL_PAREN(i, S[i][j]);
        PRINT_OPTIMAL_PAREN(S[i][j] + 1, j);
        printf(")");
    }
}

void PRINT_MAT(int A[length][length], int size) {
    for (int i = 1; i <= size; i++) {
        for (int j = 1; j <= size; j++) {
            if (i <= j)
                printf("%d\t", A[i][j]);
            else
                printf("\t");
        }
        printf("\n");
    }
}

int main() {
    int P[length];
    printf("Enter P:\n");
    for (int i = 0; i < length; i++) {
        scanf("%d", &P[i]);
    }
    MATRIX_CHAIN_ORDER(P);
    printf("M is:\n");
    PRINT_MAT(M, length - 1);
    printf("S is:\n");
    PRINT_MAT(S, length - 1);
    printf("Optimal parenthesization is:\n");
    PRINT_OPTIMAL_PAREN(1, length - 1);
    printf("\n");
    return 0;
}

