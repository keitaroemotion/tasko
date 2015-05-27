#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define JST (+9)

const time_t get_current_time(){
  time_t current_time;
  current_time = time(NULL);
  return current_time;
}

const char * disp_current_time(){
  char* c_time_string;
  time_t current_time = get_current_time();
  c_time_string = ctime(&current_time);
  return c_time_string;
}

const int get_days_in_month(int year, int month){
  int numberOfDays;
  bool isLeapYear;
  if (month == 4 || month == 6 || month == 9 || month == 11){
    numberOfDays = 30;
  } else if (month == 2){
    isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    if (isLeapYear)
      numberOfDays = 29;
    else
      numberOfDays = 28;
  } else {
    numberOfDays = 31;
  }
  return numberOfDays;
}


struct tm * get_curr_time(){
  time_t rawtime;
  struct tm * ptm;
  time( &rawtime );
  ptm = gmtime ( &rawtime );
  return ptm;
}

void test(){
  /* days in month */
  int dim = get_days_in_month(2015,5);
  struct tm * ptm = get_curr_time();
  printf("days in month: %d\n",dim);
  printf("year:%d\n", (ptm->tm_year+1900));
  printf("month:%d\n", (ptm->tm_mon+1));
  printf("day:%d\n", (ptm->tm_mday));
  printf("hour:%2d\n", (ptm->tm_hour+JST));
  printf("minutes:%02d\n", (ptm->tm_min));
}

void disp_calendar(){
  printf("Su Mo Tu We Th Fr Sa\n");
  struct tm * ptm = get_curr_time();
  int dim = get_days_in_month(ptm->tm_mon+1,ptm->tm_mday);
  int dow = 0;
  for(int i=0; i<dim ; i++){
    if (i < 9){
      printf(" ");
    }
    printf("%d ", i+1);
    dow += 1;
    if (dow == 7){
      puts("");
      dow = 0;
    }
  }
  puts("");
}

int main(int argc, char *argv[]){
    if(argc != 2){
      printf("%s\n", "argument length is not enough provided.");
      abort();
    }

    char* order = argv[1];
    if(strcmp(order, "now") == 0){
      printf("%s\n", disp_current_time());
    }else if(strcmp(order, "ca") == 0){
      disp_calendar();
    }else if(strcmp(order, "test") == 0){
      test();
    }else{
      printf("%s\n", "order does not exist.");
    }
    return 0;
}

