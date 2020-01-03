/*
Nhập vào điểm 3 môn toán, văn, anh của 1 học sinh, viết chương trình đưa ra xếp loại của học sinh đó theo điểm trung bình như sau:
– [0, 4.0): Yếu
– [4.0, 6.5): Trung bình
– [6.5, 8.0): Khá
– [8.0, 10]: Giỏi
*/
#include <stdio.h>

int main(){
    float a, b, c;
    printf("Nhap diem toan: ");
    scanf("%f",&a);
    printf("Nhap diem van: ");
    scanf("%f",&b);
    printf("Nhap diem anh: ");
    scanf("%f",&c);
    float tb = (a+b+c)/3;
    printf("\nDiem tb: %f\n",tb);
    printf("=> Ket qua danh gia: ");
    if(0<=tb<4.0) printf("Hoc sinh yeu");
    else if (4<=tb<6.5) printf ("Hoc sinh tb");
    else if (6.5<=tb<8.0) printf ("Hoc sinh kha");
    else
    {
        printf ("Hoc sinh gioi");
    }
    
    return 0;
}