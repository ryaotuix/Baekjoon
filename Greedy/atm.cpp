#include <stdio.h>
#include <iostream>

using namespace std;

int main(){
    int a=0, i=0, A[1020]={0, }, sum=0;
    scanf("%d", &a);
    for(i=0;i<a;i++) scanf("%d", A+i);
    

    i=0;
    while(i!=a-1){
        if(A[i]>A[i+1]){
            sum=A[i];
            A[i]=A[i+1];
            A[i+1]=sum;
            i--;
        }
        else i++;
        if(i<0)i=0;
    }
    sum=0;
    for(i=0;i<a;i++) sum=sum+A[i]*(a-i);
    printf("%d", sum);
}