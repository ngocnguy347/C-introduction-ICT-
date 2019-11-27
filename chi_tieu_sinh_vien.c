/*

 *Sinh vien duoc phu huynh cap cho 1 so tien la 3 trieu moi thang de chi tieu.
 Trong chtrinh, ng dung chon che do chi tieu va nhap chi tieu moi thang trong nam de quan ly,
  -voi che do AN TOAN, so chi tieu khong the vuot dinh muc hang thang
  -voi che do LINH HOAT, so chi co the vuot dinh muc hang thang, nhung khong vuot so tien con du
 * Chuong trinh can co interface and menu:
  - Bang chi tieu ca nam
  - Thang chi tieu nhieu nhat, tiet kiem nhat
  - So tien con du lai moi thang, so tien con lai sau 1 nam

 */
#include <stdio.h>
#include <math.h>
#define MAX 3000000

int i, a, luachon, condition;
double s[MAX], thang[MAX], du[MAX], sodu = 0.0, sum = 0.0;
int min = 100000000, max = 0;

void menu();
void month();
void antoan();
void chedo();
void linhhoat();
void thongke();
void error();

// double tieu;
    // printf("Nhap so thang muon che do an toan : "); fflush(stdin); scanf("%d", &t); 
    // if ( t > 12 || t < 1){
    //     printf("          *******  ERROR  ********* \n");
    //     printf("WARNING: So lieu ban da nhap la %d khong hop le\n", t);
    //     printf("HINT: Ban chi co the nhap tu 1 den 12\n");
    //     break;
    // }

int main ( void )
{
    do{
        menu();
        switch ( luachon ){
            case 1: month();break;
            case 2: thongke();break;
            case 3: break;
            default : error(); break;
        }
    } while ( luachon != 3);
}

void menu()
{
    printf ("_______________________________________\n");
    printf ("|                MENU                  |\n");
    printf ("|--------------------------------------|\n");
    printf ("| 1 . Chon thang va che do chi tieu    |\n");
    printf ("| 2 . Thong ke chi tieu trong nam      |\n");
    printf ("| 3 . Thoat                            |\n");
    printf ("|______________________________________|\n");
    printf ("Lua chon cua ban : "); fflush(stdin); scanf("%d", &luachon);
}

void month(){
    int a;
    do{
        printf ("___________________________\n");
        printf ("|    SU LUA CHON           |\n");
        printf ("|--------------------------|\n");
        printf ("| 1 . Thang 1              |\n");
        printf ("| 2 . Thang 2              |\n");
        printf ("| 3 . Thang 3              |\n");
        printf ("| 4 . Thang 4              |\n");
        printf ("| 5 . Thang 5              |\n");
        printf ("| 6 . Thang 6              |\n");
        printf ("| 7 . Thang 6              |\n");
        printf ("| 8 . Thang 8              |\n");
        printf ("| 9 . Thang 9              |\n");
        printf ("| 10. Thang 10             |\n");
        printf ("| 11. Thang 11             |\n");
        printf ("| 12. Thang 12             |\n");
        printf ("| 13. Thoat option         |\n");
        printf ("|__________________________|\n");
        printf ("\nLua chon thang ban muon nhap chi tieu: "); fflush(stdin); scanf("%d", &condition);
        switch ( condition ){
            case 1 : chedo(); break;   
            case 2 : chedo(); break;
            case 3 : chedo(); break;
            case 4 : chedo(); break;
            case 5 : chedo(); break;
            case 6 : chedo(); break;
            case 7 : chedo(); break;
            case 8 : chedo(); break; 
            case 9 : chedo(); break;
            case 10: chedo(); break;
            case 11: chedo(); break;
            case 12: chedo(); break; 
            case 13: break;
            default :
                printf("          *******  ERROR  ********* \n");
                printf("WARNING: Lua chon cua ban la %d khong nam trong menu\n", a);
                printf("HINT: Ban chi co the chon may tu 1 den 40\n");
                break;
        }
    } while ( condition != 13);
}

void antoan()
{   
    double tieu; 
    printf("So tien chi tieu cho thang %d : ", condition); fflush(stdin); scanf ("%lf", &tieu);   
    if ( tieu <= MAX ){
        thang[condition-1] += tieu;
        sodu = fabs(1.0 * (MAX + sodu - tieu));
        du[condition-1] += sodu;
    }
    else {
        do {
            printf("Chi tieu qua gioi han cho phep ( 3000000 VND )\n");
            printf("Nhap lai chi tieu cho thang %d: ", condition); fflush(stdin); scanf ("%lf", &tieu);
        } while ( tieu > 3000000);
        thang[condition-1] += tieu;
        sodu = fabs(1.0 * (MAX + sodu - tieu));
        du[condition-1] += sodu;
    }
}

void linhhoat()
{     
    double tieu; 
    printf("So tien chi tieu cho thang %d : ", condition); fflush(stdin); scanf ("%lf", &tieu);
    if ( tieu <= MAX + sodu) {
        thang[condition-1] += tieu;
        sodu = fabs((1.0*(MAX + sodu - tieu)));
        du[condition-1] += sodu;
    }
    else {
        do {
            printf("Chi tieu qua gioi han cho phep ( %.1lf VND )\n", (double)MAX + sodu);
            printf("Nhap lai chi tieu cho thang %d : ", condition); fflush(stdin); scanf ("%lf", &tieu);
        } while ( tieu > (double) MAX + sodu);        
        thang[condition-1] += tieu;
        sodu = fabs((1.0*(MAX + sodu - tieu)));
        du[condition-1] += sodu;
    }
}

void chedo()
{
    printf("\nChe do chi tieu ban muon chon cho thang %d\n", condition);
    printf("1. AN TOAN\n");
    printf("2. LINH HOAT\n\n");
    printf("Che do ban lua chon : "); fflush(stdin); scanf("%d", &a);
    if ( a == 1) antoan();
    if ( a == 2) linhhoat();
    if ( a != 1 && a != 2 ){
        do {
            printf ("WARNING : BAN CHI CO THE CHON 1 TRONG 2 CHE DO\n");
            printf("Che do ban lua chon: "); fflush(stdin); scanf("%d", &a);
        } while ( a != 1 && a != 2 );
        if ( a == 1) antoan();
        if ( a == 2) linhhoat();
    }
    // switch ( a ){
    //     case 1: antoan(); break;
    //     case 2: linhhoat(); break;
    //     default :
    //         printf ("WARNING : BAN CHI CO THE CHON 1 TRONG 2 CHE DO\n");
    //         do {
    //            printf("lua chon cua ban : "); fflush(stdin); scanf("%d", &a);    
    //         } while ( a != 1 && a != 2);
    //         break;
    // }
}

void thongke()
{
    printf("__________________________________________________\n");
    printf("|        BANG THONG KE CHI TIEU TRONG NAM         |\n");
    printf("|-------------------------------------------------|\n");
    printf("| %-10s|  %-16s|  %-16s|\n", "Thang", "Chi tieu", "So du");
    printf("|-------------------------------------------------|\n");
    for ( i = 1 ; i < 13; i++){
        printf("| %-10d| %-17.1lf| %-17.1lf|\n", i, thang[i-1], du[i-1]);
        sum += thang[i-1];
        if (thang[i-1] > max ) max = thang[i-1];
    }
    for ( i = 1; i < 13; i++){
        if (thang[i-1] < min) min = thang[i-1];
    }
    printf("|_________________________________________________|\n");
    printf("Tong so tien da chi tieu trong 1 nam : %.1lf VND\n", sum);
    printf("So tien con lai sau 1 nam : %.1lf VND\n", du[11]);   
    printf("Thang chi tieu nhieu nhat : ");
    for ( i = 1; i < 13; i++){
        if (thang[i-1] == max) 
        printf("%-3d", i);
    }
    printf("voi %d VND\n", max);
    printf("Thang chi tieu it nhat : ");
    for ( i = 1; i < 13; i++){
        if (thang[i-1] == min) 
        printf("%-3d", i);
    }
    printf("voi %d VND\n", min);
}

void error()
{
    printf("          *******  ERROR  ********* \n");
    printf("WARNING: Lua chon cua ban la %d khong nam trong menu\n", luachon);
    printf("HINT: Ban chi co the chon option tu 1 den 3\n"); 
}

