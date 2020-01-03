/*
Nhập vào 2 số nguyên a, b
Nhập vào phép toán +, -, *, /
Thực hiện tính toán theo phép toán nhập vào với hai số a, b
mau:
// +
// 2 3
// => In ra 2 + 3
*/
#include <stdio.h>

int main(){
    int a , b = 0;
    char pheptoan;
    // printf("Nhap vao phep toan: ");
    scanf("%c",&pheptoan);
    // printf("Nhap a, b = ");
    scanf("%d %d", &a, &b);
    switch (pheptoan)
    {
    case '+':
        /* code */
        printf("%d", a+b);
        break;
    case '-':
        printf("%d", a-b);
        break;
    case '*':
        printf("%d",a*b);
        break;
    case '/':
        printf("%d",a/b);
        break;
    default:
        // printf("Ko ton tai phep toan %c",pheptoan);
        break;
    }
    printf("\n");
}