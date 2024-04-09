#include <stdio.h>
#include <time.h>

void swap (int *a, int *b){
    int temp= *a; *a=*b; *b=temp;
}
int partition(int *a, int l, int h){
    int i=l-1;
    int j;
    for(j=l;j<h;j++){
        if(a[j]<=a[h]){
            i++; swap(&a[i], &a[j]);
        }
    }
    i++; swap(&a[i],&a[h]);
    return i;
}

int quick_select(int *a, int l, int h, int k){
    if(l==h) return a[l];
    int pivot_index=partition(a,l,h);
    if(k==pivot_index) return a[k];
    else if(k>pivot_index) 
        return quick_select(a,pivot_index+1,h,k);
    else 
        return quick_select(a,l,pivot_index-1,k);
}

int main(){
    int a[]={5,4,9,9,1,4,7,6,1,1,2};
    int n=sizeof(a)/sizeof(a[0]);
    int second_largest=quick_select(a,0,n-1,n-2);
    int second_smallest=quick_select(a,0,n-1,1);
    int i;
    for(i=0;i<n;i++){
        printf("%d\t",a[i]);
    }
    for(i=1;i<n;i++){
        if(a[i]!=a[i-1]){
            printf("\n Second Smallest is: %d",a[i]); break;
        }
    }
    for(i=n-2;i>=0;i--){
        if(a[i]!=a[i+1]){
            printf("\n Second Largest is: %d",a[i]); break;
        }
    }
}