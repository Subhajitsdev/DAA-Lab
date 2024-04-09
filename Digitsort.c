#include <stdio.h>
int GetMax(int nums[],int n){
    int max=nums[0]; int i;
    for (i=1;i<n;i++){
        if(nums[i]>max)  max=nums[i];
    } 
    return max;
}
//Count Sort
void CountSort(int nums[],int n, int exp){
    int arr[n]; //to store sorted array
    int i, count[10]={0}; //count of values
    for (i=0;i<n;i++) 
        count[(nums[i]/exp)%10]++;//count no. of values
    for (i=1;i<10;i++) 
        count[i]+=count[i-1]; //counting index
    for (i=n-1;i>=0;i--){
        arr[count[(nums[i]/exp)%10]-1]=nums[i];
        count[(nums[i]/exp)%10]--; 
        }//sorting
    for(i=0;i<n;i++)
        nums[i]=arr[i];
}
//Radix Sort
void RadixSort(int nums[],int n){
    int m=GetMax(nums,n);
    for(int exp=1;m/exp>0;exp *=10)
        CountSort(nums,n,exp);
}
void display(int nums[],int n){
    for(int i=0;i<n;i++){
        printf("%d\t",nums[i]);
    }
}
int main(){
     int N=0;int nums[N];
    printf("Enter the number of elements: ");
    scanf("%d",&N);
    printf("Enter elements: ");
    for(int i=0;i<N;i++){
        scanf("%d",&nums[i]);
    }
    RadixSort(nums,N);
    printf("Sorted array: ");
    display(nums,N);
    return 0;
}