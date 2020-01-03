#include <stdio.h>

int reverse(int n){
    int reNum = n%10;
    n /= 10;
    int last;
    while(n>0){
        last = n%10;
        n/=10;
        reNum = reNum *10 + last;
    }
    return reNum;
}

int main(){
    int n =0;
    printf("NHap so:");
    scanf("%d",&n);
    printf("So dao nguoc cua %d la %d\n",n,reverse(n));
}