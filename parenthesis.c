#include <stdio.h>
#include <limits.h>
// Function to print optimal parenthesization
void printParenthesis(int i, int j, int n, int* bracket, char* name)
{
    if (i == j){
        printf("%c", (*name)++);
        return;
    }
    printf("(");

    printParenthesis(i, *((bracket + i * n) + j), n, bracket, name);
    printParenthesis(*((bracket + i * n) + j) + 1, j, n, bracket, name);

    printf(")");
}

void matrixChainOrder(int p[], int n){
    int m[n][n];//cost store
    int bracket[n][n];//break points store 
    int i,L,j,k;      
    for (i = 0; i < n; i++)
     for(j=0;j<n;j++)
        m[i][j] = 0;

    for (L = 2; L < n; L++){ //l gives current length of chain during iteration
        for (i = 1; i < n - L + 1; i++){//i represents ith matrix itself
             j = i + L - 1;
            m[i][j] = INT_MAX;
            for (k = i; k < j ; k++) {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]){
                    m[i][j] = q;
                    bracket[i][j] = k;
                }
            }
        }
    }
    char name = 'A';
    printf("table\n");
    for(i=0;i<n;i++)
     {for(j=0;j<n;j++)
       printf("%d\t",m[i][j]);
      printf("\n");
	 }
    printf("Optimal Parenthesization is : ");
    printParenthesis(1, n - 1, n, (int*)bracket, &name);
    printf("\nOptimal Cost is : %d", m[1][n - 1]);
}

int main(){
    int arr[]={2,3,4,5,3};//n length of dimeensions means n-1 matrices with overlapping or common dimensions
    int n = sizeof(arr) / sizeof(arr[0]);
    matrixChainOrder(arr, n);
    return 0;
}