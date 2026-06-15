#include<stdio.h>
int main(){
    int n,bin[32],i=0;
    printf("Enter integer: ");
    scanf("%d",&n);
    while (n>0){
      bin[i]=n%2;
      n=n/2;
      i++;
    }
    for(int j=i-1;j>=0;j--){
        printf("%d",bin[j]);
    }
    }
