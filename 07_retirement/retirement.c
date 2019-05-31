
#include <stdlib.h>
#include <stdio.h>

struct _retire_info {
  int months;
  double contribution;
  double rate_of_return;
};

typedef struct _retire_info retire_info;

void computation(int * startAge, double *  initial, retire_info status) {
  for (int i = 0; i < status.months; i++) {
    printf("Age %3d month %2d you have $%.2lf\n", *startAge/12, *startAge%12, *initial);
    *initial += *initial*status.rate_of_return;
    *initial += status.contribution;
    *startAge += 1;
  }
}

void retirement(int startAge, double initial, retire_info working,
      		retire_info retired) {
  computation(&startAge, &initial, working);
  computation(&startAge, &initial, retired);
}
  

int main (void) {
  retire_info working = { 489, 1000, 0.045/12 };
  retire_info retired = { 384, -4000, 0.01/12 };
  int startAge = 327;
  double initial = 21345;
  retirement(startAge, initial, working, retired);

  return EXIT_SUCCESS;
}
