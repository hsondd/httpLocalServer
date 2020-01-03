#include <stdio.h>

int g_number = 5;

void sum(int a, int b){
    int sum = a + b;
    printf("\nSum = %d", sum);
}

int main(){
    int f = 5;
    int s = 5;
    sum(f,s);
}