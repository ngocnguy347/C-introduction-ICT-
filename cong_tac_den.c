/*

 *Den trong phong hoc thuc hanh C nhu 1 ma tran 5*3
 *Den sang: 1
 *Den toi: 0
 *Cong suat tieu thu cua cac den:
  - VT hang le cot le: 10W
  - VT hang chan cot chan: 20W
  - con lai: 15W
 *Viet chtrinh menu:
  -1. ng dung bat tat den theo hang
  -2. ng dung bat tat den theo cot
  -3. ng dung bat tat den theo VT
  -4. Xem cong suat tieu thu cua den theo trang thai hien thoi
 
*/

#include <stdio.h>
#define MAX 100

int luachon, i, j, condition;
int s[MAX][MAX], dien[MAX][MAX];

void menu(); // function propotype
void row(); // function propotype
void column(); // function propotype
void vitri(); // function propotype
void congsuat(); // function propotype
void error();

int main ( void )
{
    do {
        menu();
        switch ( luachon ){
            case 1 : row();break;
            case 2 : column();break;
            case 3 : vitri();break;
            case 4 : congsuat();break;
            case 5 : break;
            default : error();break;
        }
    } while ( luachon != 5);
}

void menu()
{
    printf ("_______________________________________\n");
    printf ("|                MENU                  |\n");
    printf ("|--------------------------------------|\n");
    printf ("| 1 . Bat tat den theo hang            |\n");
    printf ("| 2 . Bat tat den theo cot             |\n");
    printf ("| 3 . Bat tat den theo vi tri          |\n");
    printf ("| 4 . Cong suat tieu thu cua dan den   |\n");
    printf ("| 5 . Thoat                            |\n");
    printf ("|______________________________________|\n");
    printf ("Lua chon cua ban : "); fflush(stdin); scanf("%d", &luachon);
}

void row()
{
    int a, b;
    do {
        printf("________________________\n");
        printf("|     BANG LUA CHON     |\n");
        printf("|-----------------------|\n");
        printf("| 1 . Bat den           |\n");
        printf("| 2 . Tat den           |\n");
        printf("| 3 . Thoat option      |\n");
        printf("|_______________________|\n");
        printf("Lua chon cua ban: "); fflush(stdin); scanf("%d", &condition);
        switch ( condition){
            case 1:
                printf("Hang ban muon bat den: "); fflush(stdin); scanf("%d", &a);
                if ( a > 5 || a < 1) {
                    do {
                        printf ("Ban chi co the chon hang tu 1 den 5\n");
                        printf("VUI LONG NHAP LAI\n");
                        printf("Hang ban muon bat den: "); fflush(stdin); scanf("%d", &a);
                    } while (a > 5 || a < 1);
                }
                for ( i = 0; i < 5; i++){
                    for( j = 0; j < 3; j++){
                        if ( i == a-1 ) s[i][j] = 1;
                    }
                }
                printf("\n");
                for ( i = 0; i < 5; i++){
                    for ( j = 0; j < 3; j++){
                        printf("%5d", s[i][j]);
                    }
                    printf("\n\n");
                }
                break;
            case 2:
                printf("Hang ban muon tat den: "); fflush(stdin); scanf("%d", &b);
                if ( b > 5 || b < 1) {
                    do {
                        printf ("Ban chi co the chon hang tu 1 den 5\n");
                        printf("VUI LONG NHAP LAI\n");
                        printf("Hang ban muon tat den: "); fflush(stdin); scanf("%d", &b);
                    } while (b > 5 || b < 1);
                }
                for ( i = 0; i < 5; i++){
                    for( j = 0; j < 3; j++){
                        ;
                    }
                }
                if ( s[0][j] == 0 || s[1][j] == 0 || s[2][j] == 0 || s[3][j] == 0 || s[4][j] == 0){
                    printf("Hang nay khong co bong nao bat\n");
                }
                for ( i = 0; i < 5; i++){
                    for( j = 0; j < 3; j++){
                        if ( i == b-1 ) s[i][j] = 0;
                    }
                }
                
                printf("\n");
                for ( i = 0; i < 5; i++){
                    for ( j = 0; j < 3; j++){
                        printf("%5d", s[i][j]);
                    }
                    printf("\n\n");
                }
                break;
            case 3: break;
            default :
                printf("          *******  ERROR  ********* \n");
                printf("WARNING: Lua chon cua ban la %d khong nam trong menu\n", condition);
                printf("HINT: Ban chi co the chon tu 1 den 3\n");
                break;
        }
    } while ( condition != 3);
}

void column()
{
    int a, b;
    do {
        printf("________________________\n");
        printf("|     BANG LUA CHON     |\n");
        printf("|-----------------------|\n");
        printf("| 1 . Bat den           |\n");
        printf("| 2 . Tat den           |\n");
        printf("| 3 . Thoat option      |\n");
        printf("|_______________________|\n");
        printf("Lua chon cua ban: "); fflush(stdin); scanf("%d", &condition);
        switch ( condition){
            case 1:
                printf("Cot ban muon bat den: "); fflush(stdin); scanf("%d", &a);
                if ( a > 3 || a < 1) {
                    do {
                        printf ("Ban chi co the chon cot tu 1 den 3\n");
                        printf("VUI LONG NHAP LAI\n");
                        printf("Cot ban muon bat den: "); fflush(stdin); scanf("%d", &a);
                    } while (a > 3 || a < 1);
                }
                for ( i = 0; i < 5; i++){
                    for( j = 0; j < 3; j++){
                        if ( j == a-1 ) s[i][j] = 1;
                    }
                }
                printf("\n");
                for ( i = 0; i < 5; i++){
                    for ( j = 0; j < 3; j++){
                        printf("%5d", s[i][j]);
                    }
                    printf("\n\n");
                }
                break;
            case 2:
                printf("Cot ban muon tat den: "); fflush(stdin); scanf("%d", &b);
                if ( b > 3 || b < 1) {
                    do {
                        printf ("Ban chi co the chon cot tu 1 den 3\n");
                        printf("VUI LONG NHAP LAI\n");
                        printf("Cot ban muon tat den: "); fflush(stdin); scanf("%d", &b);
                    } while (b > 3 || b < 1);
                }
                for ( i = 0; i < 5; i++){
                    for( j = 0; j < 3; j++){
                        ;
                    }
                }
                if ( s[i][0] == 0 || s[i][1] == 0 || s[i][2] == 0){
                        printf("Cot nay khong co bong nao bat\n");
                }
                for ( i = 0; i < 5; i++){
                    for( j = 0; j < 3; j++){
                        if ( j == b-1 ) s[i][j] = 0;
                    }
                }
                
                printf("\n");
                for ( i = 0; i < 5; i++){
                    for ( j = 0; j < 3; j++){
                        printf("%5d", s[i][j]);
                    }
                    printf("\n\n");
                }
                break;
            case 3: break;
            default :
                printf("          *******  ERROR  ********* \n");
                printf("WARNING: Lua chon cua ban la %d khong nam trong option\n", condition);
                printf("HINT: Ban chi co the chon tu 1 den 3\n");
                break;
        }
    } while ( condition != 3);
}

void vitri()
{
    int a, b, c, d;
    do {
        printf("________________________\n");
        printf("|     BANG LUA CHON     |\n");
        printf("|-----------------------|\n");
        printf("| 1 . Bat den           |\n");
        printf("| 2 . Tat den           |\n");
        printf("| 3 . Thoat option      |\n");
        printf("|_______________________|\n");
        printf("Lua chon cua ban: "); fflush(stdin); scanf("%d", &condition);
        switch ( condition){
            case 1:
                printf("Vi tri ban muon bat den ( row, column ): "); fflush(stdin); scanf("%d, %d", &a, &b);
                if ( (a > 5 || a < 1) && (b < 1 || b > 3) ) {
                    do {
                        printf ("Ban chi co the chon hang tu 1 den 5. chon cot tu 1 den 3\n");
                        printf("VUI LONG NHAP LAI\n");
                        printf("Vi tri ban muon bat den ( row, column ): "); fflush(stdin); scanf("%d, %d", &a, &b);
                    } while ((a > 5 || a < 1) && (b < 1 || b > 3) );
                }
                for ( i = 0; i < 5; i++){
                    for( j = 0; j < 3; j++){
                        if ((i == a-1) && (j == b-1)) s[i][j] = 1;
                    }
                }
                printf("\n");
                for ( i = 0; i < 5; i++){
                    for ( j = 0; j < 3; j++){
                        printf("%5d", s[i][j]);
                    }
                    printf("\n\n");
                }
                break;
            case 2:
                printf("Vi tri ban muon tat den ( row, column ): "); fflush(stdin); scanf("%d, %d", &c, &d);
                if ( c > 5 || c < 1 || d < 1 || d > 3 ) {
                    do {
                        printf ("Ban chi co the chon hang tu 1 den 5. chon cot tu 1 den 3\n");
                        printf("VUI LONG NHAP LAI\n");
                        printf("Vi tri ban muon tat den ( row, column ): "); fflush(stdin); scanf("%d, %d", &c, &d);
                    } while (c > 5 || c < 1 || d < 1 || d > 3 );
                }
                for ( i = 0; i < 5; i++){
                    for( j = 0; j < 3; j++){
                        if ((i == c-1) && (j == d-1)) s[i][j] = 0;
                    }
                }
                printf("\n");
                for ( i = 0; i < 5; i++){
                    for ( j = 0; j < 3; j++){
                        printf("%5d", s[i][j]);
                    }
                    printf("\n\n");
                }
                break;
            case 3: break;
            default :
                printf("          *******  ERROR  ********* \n");
                printf("WARNING: Lua chon cua ban la %d khong nam trong option\n", condition);
                printf("HINT: Ban chi co the chon tu 1 den 3\n");
                break;
        }
    } while ( condition != 3);
}

void congsuat()
{
    int temp, temp1, sum=0;
    for (i = 0; i < 5; i++){
        for ( j = 0; j < 3; j++){
            if (s[i][j] == 1) {
                if (((i+1)%2==1)&&((j+1)%2==1))
                    dien[i][j] = 10;
                if (((i+1)%2==0)&&((j+1)%2==0))
                    dien[i][j] = 20;
                if ((((i+1)%2==1)&&((j+1)%2==0)) || (((i+1)%2==0)&&((j+1)%2==1)))
                    dien[i][j] = 15;         
            }
        }
    }
    printf("\n");
    for ( i = 0; i < 5; i++){
        for ( j = 0; j < 3; j++){
            printf("%5d", dien[i][j]);
            sum += dien[i][j];
        }
        printf("\n\n");
    }
    printf ("Tong cong suat tieu thu cua dan den hien tai : %d\n", sum);
}

void error(){
    printf("          *******  ERROR  ********* \n");
    printf("WARNING: Lua chon cua ban la %d khong nam trong menu\n", luachon);
    printf("HINT: Ban chi co the chon option tu 1 den 5\n");
}
