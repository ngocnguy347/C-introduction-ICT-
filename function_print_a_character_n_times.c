/*
write a function "void printachars(int ch, int n) to display a character for n times."
a) Use this function to print "* right triangle" which has adges of 5,5
b) Draw a square 9x9 of which the center is a blank character. YOu should use the statement continue and the nested loop here.
c) Write a function to get a character. Character must be in alphabetical table or be digit. When user enter wrong character,
program ask them to re-enter until the valid data is inputed or the number of wrong input depass 3.
- function returns the character get from users, in case of error, it returns character #.
...
 */

#include <stdio.h>

void printnchars(char ch, int n){
  for(int i=1; i<=n; i++){
    putchar(ch);
    printf(" ");
  }
}

void print_square(char ch, int n){
  int i;
  ch='*';
  for(i=1; i<=n; i++){
    if(i==1 || i==n){
      printnchars(ch, n);
      printf("\n");
    }
    else {
      printf("*"); printnchars(' ', n-1); printf("*");
    printf("\n");
    }
  }
}

 

int main()
{
  char ch;
  int n;
  printf("Nhap 1 ki tu:");
  ch=getchar();
  while(getchar()!='\n');
  printf("Ban muon hien thi ki tu nay bao nhieu lan? ");
  scanf("%d", &n);
  printnchars(ch, n);

  int e;
  printf("\n\nPrint * right triangle:\n ");
   printf("Input length of edge: ");
   scanf("%d",&e);
   ch='*';
   for(int i=1; i<=e; i++){
   printnchars(ch,i);
   printf("\n");
   }

   printf("\nPrint square 9x9:\n");
   print_square(ch, 9);


   
   printf("\n\n");
    int count=0;
    char c;
    
  do{
    
    printf("Input character: ");
    while(getchar() != '\n');
    c=getchar();
    
    if(count>3) return printf("#\n");
    if((c<='A' || c>='Z') && (c<='a' || c>='z') && (c<='0' || c>='9')){
      count++;
      printf("Error!!! Input again!!!\n");
    }
  }while((c<='A' || c>='Z') && (c<='a' || c>='z') && (c<='0' || c>='9'));
  putchar(c);
  printf("\n");
}

