/*

 *Phong lab 813 chuong trinh Viet Nhat chua 40 may tinh de ban. Hang tuan cac may se duoc sd de thuc tap. Biet 1 lan duoc sd - dien nang tieu thu la 400Watt. Viet chtrinh quan li viec sd may voi cac menu sau:
 * Dung may: khi 1 nguoi vao phong may, chi dinh so hieu may muon sd. Neu may con trong => duoc cap may.
 * Roi may: may ve trang thai roi.
 * In ra trang thai cac may:
 * In ra dien nang tieu thu tich luy tren cac may cho den thoi diem hien tai
 * In ra tong dien nang tieu thu - va tien dien thanh toan (750d/KW)
 * In ra nhung may duoc dung nhieu nhat va it nhat

 */

#include <stdio.h>
#define MAX 40


int i, j, luachon, condition, temp;
int s[MAX] = {0}, dien[MAX] = {0}, count[MAX] = {0};
int tongdien = 0, count1 = 0;
double tiendien = 0.0;
int min = 1000000000;
int max = 0;

void menu();
void chonroimay();
void trangthai();
void diennang();
void thanhtoan();
void minmax();
void error();

int main ( void )
{    
    do {
        menu();
        switch ( luachon ){
            case 1 : chonroimay();break;
            case 2 : trangthai();break;
            case 3 : diennang();break;
            case 4 : thanhtoan();break;
            case 5 : minmax();break;
            case 6 : break;
            default : error();break;
        }
    } while ( luachon != 6);
}

void menu()
{
    printf ("__________________________________________________________\n");
    printf ("|                       MENU                              |\n");
    printf ("|---------------------------------------------------------|\n");
    printf ("| 1 . Chon/roi may                                        |\n");
    printf ("| 2 . In trang thai may                                   |\n");
    printf ("| 3 . In dien nang tieu thu tich luy den hien tai         |\n");
    printf ("| 4 . In tong dien nang tieu thu va tien dien thanh toan  |\n");
    printf ("| 5 . May dung nhieu nhat va it nhat                      |\n");
    printf ("| 6 . Thoat                                               |\n");
    printf ("|_________________________________________________________|\n");
    printf ("Lua chon cua ban : "); fflush(stdin); scanf("%d", &luachon);
}

void chonroimay()
{
    int a, b, temp;
    do {
        printf ("___________________________\n");
        printf ("|    SU LUA CHON           |\n");
        printf ("|--------------------------|\n");
        printf ("| 1. Nhap so may muon chon |\n");
        printf ("| 2. Nhap so may muon roi  |\n");
        printf ("| 3. Thoat option          |\n");
        printf ("|__________________________|\n");
        printf ("Lua chon cua ban: "); fflush(stdin); scanf("%d", &condition);
        switch ( condition ){
            case 1: 
                printf ("So may ban muon chon : "); fflush(stdin); scanf ("%d", &a);
                if ( a > 40 || a < 1 ) {
                    do {
                    printf("          *******  ERROR  ********* \n");
                    printf("WARNING: So may ban chon la %d khong nam trong danh sach may\n", a);
                    printf("HINT: Ban chi co the chon may tu 1 den 40\n");
                    printf ("So may ban muon chon : "); fflush(stdin); scanf ("%d", &a);
                    } while ( a > 40 || a < 1);
                }                
                if (s[a-1] == 0){
                    count1++;
                    s[a-1] = 1;
                    count[a-1]++;
                    dien[a-1] += 400;
                    tongdien += 400;
                }
                else {
                    do {
                    printf("May nay da co nguoi dung. vui long chon may khac\n");
                    printf ("So may ban muon chon : "); fflush(stdin); scanf ("%d", &a);
                    } while ( s[a-1] == 1);
                    count1++;
                    s[a-1] = 1;
                    count[a-1]++;
                    dien[a-1] += 400;
                    tongdien += 400;
                }
                if ( count[a-1] > max){
                     max = count[a-1];
                } 
                for ( i = 1; i < MAX; i++){
                    if (s[i] < min) min = s[i];
                }             
                break;
            case 2: 
                if ( count1 == 0 ) 
                    printf ("Phong nay chua co ai dung\n");
                if ( count1 > 0){
                    printf ("So may ban muon roi : "); fflush(stdin); scanf ("%d", &a);
                    if (s[a-1] == 1) {
                        s[a-1] = 0;
                        printf("HEN GAP LAI\n");
                    }
                    else {
                        do {
                            printf ("May nay khong co nguoi dung\n");
                            printf ("Vui long chon may khac! \n");
                        } while (0);
                    }
                }
                break;
            case 3: break;
            default :
                printf("          *******  ERROR  ********* \n");
                printf("WARNING: Lua chon cua ban la %d khong nam trong menu\n", condition);
                printf("HINT: Ban chi co the chon  1 hoac 2 hoac 3\n");
                break;
        }
    } while ( condition != 3);
}

void trangthai()
{
    int dem=0;
    printf ("      BANG THONG KE TRANG THAI MAY HIEN TAI\n\n");
    for ( i = 0; i < MAX; i++){
        dem++;
        if (s[i]) 
            printf("%-3d : %-7s", i+1, "ON");
        else 
        printf("%-3d : %-7s", i+1, "OFF");
        if ( dem == 4 ) { 
          printf("\n"); 
          dem = 0;
        }
    }
}

void diennang()
{
    int dem=0;
    printf ("      BANG THONG KE DIEN NANG TICH LUY HIEN TAI\n\n");
    for ( i = 1; i <= MAX; i++){
        dem++;
        printf("%-3d : %-10d", i, dien[i-1]);
        if ( dem == 4 ) { 
          printf("\n"); 
          dem = 0;
        }
    }
}

void thanhtoan()
{
    tiendien = 1.0 * tongdien * 750 / 1000;
    printf("Tong dien nang tieu thu : %d\n", tongdien );
    printf("Tien dien phai thanh toan : %.2lf\n", tiendien);

}

void minmax()
{
    int dem=0;
    printf ("      BANG THONG KE TAN SO SU DUNG HIEN TAI\n\n");
    for ( i = 1; i <= MAX; i++){
        dem++;
        printf("%-3d : %-10d", i, count[i-1]);
        if ( dem == 4 ) { 
          printf("\n"); 
          dem = 0;
        }
    }
    
    
    printf("Nhung may duoc dung nhieu nhat ");
    for ( i = 0; i < MAX; i++){
        if ( count[i] == max){
            printf("%-3d", i+1);
        }
    }
    printf(" voi %d lan\n", max);
    
    printf("Nhung may duoc dung it nhat ");
    for ( i = 0; i < MAX; i++){
        if ( count[i] == min){
            printf("%-3d", i+1);
        }
    }
    printf(" voi %d lan\n", min);
}

void error()
{
    printf("          *******  ERROR  ********* \n");
    printf("WARNING: Lua chon cua ban la %d khong nam trong menu\n", luachon);
    printf("HINT: Ban chi co the chon option tu 1 den 6\n");
}
