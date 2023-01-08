#include <stdio.h>
#include <string.h>

int main() {
  char curr_time[10];
  char curr_date[12];
  int std_c;

  strcpy(curr_time, __TIME__);
  strcpy(curr_date, __DATE__);
  printf("%s %s\n", curr_time, curr_date);
  printf("This is line %d\n", __LINE__);    
  std_c = __STDC__;
  printf("STDC is %d", std_c);  
  
  return 0;
}