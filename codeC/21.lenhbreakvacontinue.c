// /*
// Kiểm tra một số nguyên mà nó được tạo thành từ các số chẵn hay không?
// Ví dụ: 8, 222, 246, …
// */
#include <stdio.h>
#include <stdbool.h>

// int main (){
//     int numb;
//     printf("Nhap number = ");
//     scanf("%d",&numb);

//     bool allEven = true;
//     int last;
//     while(numb > 0){
//         last = numb % 10;
//         if(last %2 == 1){
//             allEven = false;
//             break;
//         }
//         numb /= 10;
//     }
//     if(allEven){
//             printf("Toan chu so chan");
//         } else{
//             printf("Toan chu so le");
//         }
//         printf("\n");
// }
//------------------------------------lenh contiue-------------
/*
In ra các chữ số chẵn từ 1 đến 100.
*/

int main(){
    for(int i = 0;i<=100;i++){
        if(i%2 != 0){
            continue;
        }
        printf("%d ",i);
    }
}
