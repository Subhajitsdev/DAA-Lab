#include<stdio.h>
int freq(int a[],int start,int end,int x){
    if(start==end){
        if(a[start]==x) return 1;
    }
    if(start>=end) return 0;

    int mid=(start+end)/2;
    return freq(a,start,mid,x)+freq(a,mid+1,end,x);
}
int main(){
     int n,i,x;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    int a[n];
    printf("\n***PLEASE ENTER SORTED ARRAY*** \n");
    printf("\nEnter the elements: \n");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
     printf("\nEntered array: \n");
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }
     printf("Enter the element to be searched for: \n");
     scanf("%d",&x);
     printf("Element %d occurs %d times",x,freq(a,0,n-1,x));
}