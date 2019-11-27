/*
Chi phi:
- Phi noi tru: 150.000 vnd/ngay
- Tien thuoc: gia tri nguyen duong, lon
- Tien phau thuat: (neu co) khac 0
Benh nhan co 3 loai the bao hiem sau:
+ Gold(G): chi can thanh toan 30% chi phi
+ Silver(S): chi can thanh toan 50% chi phi
+ Citizen(C): 70% chi phi
Thiet ke ham hospitalFree 
 */

#include<stdio.h>
#define G 0.3
#define S 0.5
#define C 0.7


float hospitalFree(int day, int thuoc, int pt, int tbh){
  float ck, total;
  if(tbh=1){
    ck=G;
    total=G*(day*150000+thuoc+pt);
  }
  else if(tbh=2){
    ck=S;
    total=S*(day*150000+thuoc+pt);
  }
  else if(tbh=3){
    ck=C;
    C*(day*150000+thuoc+pt);
  }
  
  printf(" ===========HOA___DON=============\n");
  printf("|Phi noi tru: %20d|\n", day*150000);
  printf("|Tien thuoc: %21d|\n", thuoc);
  printf("|Tien phau thuat: %16d|\n", pt);
  printf("|Ban chi can thanh toan %0.0f%schi phi|\n", ck*100, "%");
  printf("|---------------------------------|\n");
  printf("|Tong cong: %22.2lf|\n", total);
  printf("|_________________________________|\n");
  
}

int main(){
  int day, thuoc, pt;
  printf("Thoi gian noi tru cua benh nhan la bao nhieu ngay? ");
  scanf("%d", &day);
  
  do{
    printf("Tien thuoc cua benh nhan la bao nhieu? ");
    scanf("%d", &thuoc);
    if(thuoc<=0) printf("Yeu cau nhap lai tien thuoc co gia tri >0!!!\n");
  }while(thuoc<=0);
  
  do{
    printf("Tien phau thuat:");
    scanf("%d", &pt);
    if(pt<0) printf("Yeu cau nhap lai voi gia tri >=0!!!\n");
  }while(pt<0);

  int tbh;
  do{
    printf("Loai the bao hiem cua benh nhan la gi? Gold(1)-Silver(2)-Citizen(3)\n");
    scanf("%d", &tbh);
  }while(tbh!=1 && tbh!=2 && tbh!=3);
  
  hospitalFree(day, thuoc, pt, tbh);
  
  return 0;
}


//done
