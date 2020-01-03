#include <stdio.h>

int main(){
    int number;
    printf("Nhap number = ");
    scanf("%d", &number);
    int last = number;
    //Vong for
    // for(;last>9;last/=10);
    //vong while
    while(last >9){
        last /= 10;
    }
    printf("chu so dau tien cua %d la: %d", number, last);
    return 0;
}