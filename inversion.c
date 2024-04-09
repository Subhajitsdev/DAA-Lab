#include<stdio.h>
int count=0;
int Merge(int *a,int start,int end){
    int startc=start;
    int mid=(start+end)/2;
    int l1=mid-start+1;
    int l2=end-mid;
    int a1[l1]; int a2[l2];
    int i,j,k,midc=mid+1;
    for(i=0;i<l1;i++){
        a1[i]=a[startc++];
    }
    for(i=0;i<l2;i++){
        a2[i]=a[midc++];
    }
    i=0;j=0;k=start;
    while(i<l1 && j<l2){
        if(a1[i]<a2[j]){
            a[k++]=a1[i++];
        }
        else if(a1[i]>a2[j]){
            int m;
            for(m=i;m<l1;m++){
                printf("(%d, %d)",a1[m],a2[j]);
                count++;
            } a[k++]=a2[j++];
        }
        else{
            a[k++]=a1[i++]; j++;
        }
    }
    while(i<l1){
        a[k++]=a1[i++];
    }
    while(j<l2){
        a[k++]=a2[j++];
    }
    return count;
}

void MergeSort(int *a, int start, int end){
    if(start<end){
        int mid=(start+end)/2;
        MergeSort(a,start,mid);
        MergeSort(a,mid+1,end);
        Merge(a,start,end);
    }
}

int main(){
    int n,i;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    int a[n];
    printf("\nEnter the elements: \n");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
     printf("\nEntered array: \n");
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\nInversion pairs: \n");
     MergeSort(a,0,n-1);
     printf("\nNumber of Inversion pairs: %d",count);
}