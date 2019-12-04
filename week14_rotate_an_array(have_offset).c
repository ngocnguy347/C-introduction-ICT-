/*
Write and test functions that rotate an array from right to left and from left to right. The parameters of them are a given array and the value of offset.
The offset must be smaller than the array's size.
 */

#include <stdio.h>
#define MAX 1000


int s[MAX], k[MAX], size;
int* ptr;
int i, offset;
int choice;

void menu();
void input();
void rightleft();
void leftright();

int main( void )
{
    do{
        menu();
        switch( choice){
            case 1: input();break;
            case 2: leftright();break;
            case 3: rightleft();break;
            case 4: break;
            default:
            printf("WARNING. You have to chooze 1, 2 or 3\n");
        }
    } while ( choice != 4);  
}

void menu()
{
    printf("\n______________________________________\n");
    printf("|               MENU                  |\n");
    printf("|-------------------------------------|\n");
    printf("| 1 . Input array                     |\n");
    printf("| 2 . From left to right              |\n");
    printf("| 3 . From right to left              |\n");
    printf("| 4 . Exit                            |\n");
    printf("|_____________________________________|\n");
    printf("Your choice : "); scanf("%d", &choice);
}

void input()
{
    printf("\nHow many elements of array you wanna create : ");
    scanf("%d", &size);
    printf("Array s :\n");
    for ( i = 0 ; i < size; i++){
        printf("s[%d] = ", i+1 );
        scanf("%d", &s[i]);
    }
    for ( i = 0; i < size; i++){
        k[i] = s[i];
    }
    printf("\nArray s[] = ");
    for ( i = 0; i < size; i++){
        printf("%8d", s[i]);
    }
}

void rightleft()
{   
    ptr = s;
    printf("Array s before rotate :\n");
    printf("s[%d] = ", size);
    for ( i = 0; i < size; i++){
        printf("%8d", s[i]);
    }
    printf("\n\nOffset = ");scanf("%d", &offset);
    if (offset < 1 || offset > size - 1){
        do{
            printf("Please try again\nOffset from 1 to %d\n", size - 1);
            printf("\n\nOffset = ");scanf("%d", &offset);
        } while (offset < 1 || offset > size - 1);
    }
    printf("\nArray s after rotate :\n");   
    printf("s[%d] = " , size);
    for ( i = 0; i < size - 1 ; i++){
        printf("%8d", *(ptr+offset));
        offset++;
        if ( offset > size - 1){
            ptr = k;
            offset = 0;
            printf("%8d", *(ptr+offset));
            offset++;
        }       
    }
    printf("\n");
}

void leftright()
{   
    ptr = s;
    printf("Array s before rotate :\n");
    printf("s[%d] = ", size);
    for ( i = 0; i < size; i++){
        printf("%8d", s[i]);
    }
    printf("\n\nOffset = ");scanf("%d", &offset);
    if (offset < 1 || offset > size - 1){
        do{
            printf("Please try again\nOffset from 1 to %d\n", size - 1);
            printf("\n\nOffset = ");scanf("%d", &offset);
        } while (offset < 1 || offset > size - 1);
    }
    printf("\nArray s after rotate :\n");   
    printf("s[%d] = " , size);
    for ( i = 0; i < size-1; i++){
        if ( offset > 0 ) printf("%8d", *(ptr+size-offset));  
        offset--;
        if ( offset <= 0){
            ptr = k;
            printf("%8d", *(ptr-offset));
        }
    }
    printf("\n");
}
