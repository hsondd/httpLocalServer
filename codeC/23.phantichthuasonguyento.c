// Phan tích thua so nguyen to
#include <stdio.h>

int main(){
    int n;
    printf("NHap n = ");
    scanf("%d",&n);

    for (int i = 2;i<=n;i++){
        int dem = 0;
        while(n%i == 0){
            dem ++;
            n/=i;
        }
        if (dem){
            if(dem>1) printf("%d^%d",i, dem);
            else printf("%d",i);
            if(n>i){
                printf(" * ");
            }
        }
    }
    printf("\n");
}