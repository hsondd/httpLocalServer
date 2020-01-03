#include <stdio.h>

int main(){
	int a;
	printf("Nhap a: ");
	scanf("%d", &a);
	if(a%2 == 0) printf("\na la so chan\n");
	else printf("\na la so le \n");
	return 0;
}
