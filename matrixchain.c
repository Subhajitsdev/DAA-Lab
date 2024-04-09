#include <stdio.h>
#include <limits.h>
#define MAX 10
int MatrixChainCost(int B[],int i, int j){
	int k;
	int min=INT_MAX;
	if(i==j) return 0;
	int cost;
	for(k=i;k<j;k++){
		cost=MatrixChainCost(B, i, k)+ MatrixChainCost(B, k + 1, j)+ B[i - 1] * B[k] * B[j];
                   
		if(cost<min) min=cost;
	}
	return min;
}
int main(){
	int n;
	int arr[MAX];
	printf("Enter the number of elements: ");
	scanf("%d",&n);
	printf("Enter the elements: ");
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	printf("Minimum cost for multiplication is : %d\n", MatrixChainCost(arr, 1, n - 1));
     getchar();
	return 0;
}