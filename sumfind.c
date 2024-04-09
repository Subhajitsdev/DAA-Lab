#include <stdio.h>
#define MAX 10
int main(){
    int arr[MAX],n,sum,i,j;
    printf("Enter the number of elements: ");
    scanf("%d",&n);  
    printf("\nEnter the elements: \n");  
    for(i=0;i<n;i++){
      scanf("%d",&arr[i]);
    }
     printf("The sorted array is: ");
     for(i=0;i<n;i++){
      printf("%d\t",arr[i]);
    }
    printf("\nEnter the sum value: ");
    scanf("%d",&sum); 
    i=0; j=n-1;
    int flag =0;
    while(i<j){
        if(arr[i]+arr[j]==sum){
            printf("%d+%d=%d\n",arr[i],arr[j],sum);
            i++; j--; flag=1;
        }
        else if(arr[i]+arr[j]<sum) 
        i++;
        else 
        j--;
    }
    if(flag==0){
        printf("\nNot found\n");
    }
}