#include <stdio.h>
void bin_search(int rows,int cols, int a[rows][cols],int key){
    int start=0; int end=rows*cols-1; 
    int flag=0;
    while(start<=end){
        int mid=(start+end)/2;
        int n=mid/cols;
        int m=mid%cols;
        if(a[n][m]==key){
            printf("\nKey value %d is found at row: %d and col: %d\n",key,n,m);
            break; flag=1;
        }
        else if(a[n][m]<key) start=mid+1;
        else {end=mid-1;}
    } if(flag==0){ printf("\nKey %d is not found\n",key);}
}
int main(){
    int rows=3; int cols=3;
    int i,j;
    int a[rows][cols];
    printf("Enter elements: \n");
    for(i=0;i<rows;i++){
        for(j=0;j<cols;j++){
        scanf("%d",&a[i][j]);
        }
    }
    printf("The matrix is: \n");
    for(i=0;i<rows;i++){
        for(j=0;j<cols;j++){
        printf("%d ",a[i][j]);
        } printf("\n");
    }
    int key;
    printf("\nEnter key value: ");
    scanf("%d",&key);
    bin_search(rows,cols,a,key);
}