#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

const char * disp_current_time(){
  time_t current_time;
  char* c_time_string;
  current_time = time(NULL);
  c_time_string = ctime(&current_time);
  return c_time_string;
}

int main(int argc, char *argv[]){

    if(argc != 2){
      printf("%s\n", "argument length is not enough provided.");
      abort();
    }

    char* order = argv[1];
    if(strcmp(order, "now") == 0){
      printf("%s\n", disp_current_time());
    }else{
      printf("%s\n", "order does not exist.");
    }
    return 0;
}

