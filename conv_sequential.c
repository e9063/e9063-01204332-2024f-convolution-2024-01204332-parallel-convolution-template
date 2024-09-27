#include "stdio.h"
#include "omp.h"
#include "time.h"
#include "stdlib.h"

void printarr_vert(int* arr, int len) {
  for (int i = 0; i < len; i++) {
    printf("%d\n", arr[i]);
  }
}

int main(void) {
  int NA, NF;
  scanf("%d %d", &NA, &NF);

  int NO = NA - NF + 1;
  int *A = malloc(sizeof(int) * NA);
  int *F = malloc(sizeof(int) * NF);

  for(int i = 0; i < NA; i++){
    scanf("%d", &A[i]);
  }

  for(int i = 0; i < NF; i++){
    scanf("%d", &F[NF - i - 1]);
  }

  int *O = calloc(NO, sizeof(int));

  for (int i = 0; i < NO; i++) {
    for (int m = i; m < NF + i; m++) {
      O[i] += A[m] * F[m - i];
    }
  }

  printarr_vert(O, NO);

  free(O);
  free(A);
  free(F);

  return 0;
}