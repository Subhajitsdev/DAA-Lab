#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

typedef struct Jobs{
    char id;
    int dead;
    int profit;
}Jobs;
int compare(const void *a, const void *b){
    Jobs *temp1=(Jobs*)a;
    Jobs *temp2=(Jobs*)b;
    return (temp2->profit - temp1->profit);
}
int min(int num1, int num2){
    return (num1>num2) ? num2 : num1;
}
int main(){
    Jobs arr[]={
        {'A',3,1000},
        {'B',2,2000},
        {'C',1,600},
        {'D',3,1500},
    };
    int n=sizeof(arr)/sizeof(arr[0]);
    printf("Following is maximum profit sequence of Jobs: \n");
    qsort(arr,n,sizeof(Jobs),compare);
    int result[n];
    bool slot[n];
    for ( int i=0;i<n;i++) slot[i]=false;
    for(int i=0;i<n;i++){
        for(int j=min(n,arr[i].dead)-1; j>=0;j--){
            if(slot[j]==false){
                result[j]=i;
                slot[j]=true;
                break;
            }
        }
    }
    for(int i=0;i<n;i++){
        if(slot[i])
            printf("%c  ",arr[result[i]].id);
    }
}