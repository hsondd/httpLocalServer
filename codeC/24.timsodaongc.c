/*
12345 -> 54321
1230 -> 321
1000 -> 1
*/
// #include <stdio.h>
// #include <stdbool.h>
//-----------------------------------------Cach1
// int main(){
//     int n, tmp = 0;
//     int res = 0;
//     scanf("%d", &n);
//     while(n>0){
//         tmp = n % 10;
//         res = res * 10 + tmp;
//         n = n/10;
//     }
//     printf("%d\n",res);
// }
//----------------------------------------------Cach2
// int main(){
//     int n, tmp;
//     scanf("%d",&n);
//     bool isFirst = 1;
//     while(n>0){
//         tmp =n% 10;
//         if(isFirst){
//             if(tmp!=0){
//                 printf("%d",tmp);
//                 isFirst = 0;
//             }
//         }
//         else
//         {
//             printf("%d",tmp);
//         }
//         n /= 10;
//     }
// }

--------------------------------------------------Cach3
#include <iostream>
#include <string>
