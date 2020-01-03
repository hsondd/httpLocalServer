#include <stdio.h>

int main(){
    int a, b, c;
    printf ("NHap a, b, c: ");
    scanf("%d %d %d", &a, &b,&c);
    if(a>b && a>c) printf("a lon nhat");
    else if(b>a && b>c ) printf("b lon nhat");
    else printf("c lon nhat");
    return 0;
}