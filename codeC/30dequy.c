//BT1. Tính tổng các số từ 1 đến n
#include <stdio.h>

// int sum (int n){
//     if(n==0) return 0;
//     return n + sum(n-1);
// }

// int main(){
//     int n = 0;
//     scanf("%d",&n);
//     printf("Tong tu 1 den %d la: %d",n,sum(n));
//     return 0;
// }
// ------------------------------------------------------------------------------------------------
// BT2. Xây dựng vòng lặp bằng đệ quy
static int count = 0;
void loop(){
    count++;
    if(count <= 5){
        printf("loop %d ",count);
        loop();
    }
}

int main(){
    loop();
    return 0;
}