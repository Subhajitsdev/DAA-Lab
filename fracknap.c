#include <stdio.h>
#include <stdlib.h>
int main(){
    int i,j,temp; 
    int n=5; int W=10; 
    int p[5]={300,500,250,100,50};
    int w[5]={5,3,4,2,1};
    float pw[5]; float P=0; double x[5];

    for(i=0;i<n;i++){
        pw[i]=p[i]/w[i];
    }
    for(i=0;i<n;i++){
        for(j=0;j<n-i-1;j++){
            if(pw[j]<pw[j+1]){
                temp=pw[j]; pw[j]=pw[j+1]; pw[j+1]=temp;
                temp=p[j];  p[j]=p[j+1];  p[j+1]=temp;
                temp=w[j];  w[j]=w[j+1];  w[j+1]=temp;
            }
        }
    }
    printf("\nSorted as per P/W\n");
    printf("\nITEM WEIGHT PROFIT  P/W\n");
    for(i=0;i<n;i++){
        printf(" %d     %d     %d   %0.3f\n",i,w[i],p[i],pw[i]);
    }
    for(i=0;i<n;i++){
        if(W!=0 && W>w[i]){
            W-=w[i];
            x[i]=1;
            P+=p[i];
        } else {break;}
    }
    P+=pw[i]*W;
    x[i]=W/(w[i]*1.0);
    W=0;
    printf("Total Profit: %0.3f\n",P);
    for(i=0;i<n;i++){
        printf("%0.3f\t",x[i]);    
    }
}