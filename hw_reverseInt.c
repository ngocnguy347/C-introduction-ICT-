/*
Viet ham reverseInt nhan tham so la 1 so nguyen duong. Sau khi ra khoi ham tham so se bien thanh so dao nguoc cua tham so dau vao. VD
 - unsigned int a=4357;
 - reverseInt(&a);
 - printf("%4d", a); cho kq 7543
 */

#include<stdio.h>

int reverseInt(int n){
  int r=0;
   while (n != 0){
    r = r * 10;
    r = r + n%10;
    n = n/10;
  }
   return r;
}

int main(){
  int a;
  do{
  printf("Enter a unsigned number: ");
  scanf("%d", &a);
  if(a<=0) printf("Nhap lai mot so nguyen duong!\n");
  }while(a<=0);
  printf("\n->%-10d\n",reverseInt(a));
  return 0;
  
}
