/*
 @Write a program that uses a structure to store the following weathter data for a particular month.
 */

#include<stdio.h>
#define M 2


typedef struct {
  float total_rf;  //rf: rainfall
  float high_tem;  //tem: temperature
  float low_tem;
  float average_tem;
}weather;

weather month[M];

int input_data(int i){
  printf("\nEnter data for month %d:\n", i+1);
  printf("The rainfall(mm):  ");
  scanf("%f", &month[i].total_rf);
  do{
    printf("The high temperature(C): ");
    scanf("%f", &month[i].high_tem);
    if(month[i].high_tem<-40 || month[i].high_tem>50){
      printf("Only accept temperatures within the range -40 and 50 degrees Celcius!!!\n");
	}
  }while(month[i].high_tem<-40 || month[i].high_tem>50);

  do{
    printf("The low temperature(C): ");
    scanf("%f", &month[i].low_tem);
    if(month[i].low_tem<-40 || month[i].low_tem>50){
      printf("Only accept temperatures within the range -40 and 50 degrees Celcius!!!\n");
	}
  }while(month[i].low_tem<-40 || month[i].low_tem>50);
  
  month[i].average_tem = (month[i].high_tem + month[i].low_tem)/2.0;
  printf(" => The average temperature of this month is: %f(C)\n", month[i].average_tem);
}

int main(){
  int i;
  float max_tem=-40;
  float min_tem=50;
  int max_month;
  int min_month;
  
  float t_rf=0;
  
  for(i=0; i<M; i++){
    input_data(i);
  }

  for(i=0; i<M; i++){
    t_rf+=month[i].total_rf;
    if(month[i].high_tem>max_tem){
      max_month=i+1;
      max_tem=month[i].high_tem;
    }
    if(month[i].low_tem<min_tem){
      min_month=i+1;
      min_tem=month[i].low_tem;
    }
  }
  
  printf("\nTotal rainfull of the year: %f(mm)\n\n", t_rf);
  printf("The highest temperature in this year is: %f(C) in month %d\n\n", max_tem, max_month);
  printf("The lowest temperature in this year is: %f(C) in month %d\n\n", min_tem, min_month);
  
  return 0;
}
