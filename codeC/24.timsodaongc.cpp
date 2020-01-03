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

//--------------------------------------------------Cach3
#include <iostream>
#include <string>

using namespace std;

int main(){
    string s;
    cin >> s;
    int l = s.length();
    if(s[0] == '0'){
        cout << "\nSo ban nhap ko hop le";
        return 0;
    }
    for(int i = 0; i<1;i++){
        if(s[i] > '9' || s[i] < '0'){
            cout << "\nSo ban nhap ko hop le";
            return 0;
        }
    }
    while (s[l-1]=='0') --l;
    for(int i = l-1; i>=0;--i){
        cout << s[i];
    }
    return 0;
}