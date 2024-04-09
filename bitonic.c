#include<stdio.h>
#define MAX 10
int main(){
    int n;
    printf("Enter the number of elements: \n");
    scanf("%d",&n);
    int arr[MAX],i,j;
    printf("Enter the elements: \n");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("The Bitonic sequence is : \n");
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    for(j=1;j<n-1;j++){
        if(((arr[j-1]<arr[j]) && (arr[j]>arr[j+1]))|| ((arr[j-1]>arr[j]) && (arr[j]<arr[j+1]))){
            int bitpoint=arr[j];
            printf("\nThe Bitonic point is: %d\n",bitpoint);
        }
    }
    return 0;
}  