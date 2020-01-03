#include <stdio.h>


int main(){
    int a, b = 0;
    int sum = 0;
    printf ("Nhap a, b: ");
    scanf("%d %d",&a,&b);
    for(int i = a; i<=b; i++){
        if(i%2 == 0) sum += i;
    }
    printf("Tong cac so chan trong khoang [a,b] la: %d", sum);
    return 0;
}