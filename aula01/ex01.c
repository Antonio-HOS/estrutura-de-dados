#include <stdio.h>
#include <stdlib.h>

int main() {
  int *array;
  array = (int *)malloc(sizeof(int) * 10000);

  for (unsigned int j = 0; j < 10000; j++) {
    array[j] = rand()%1000;
  }

  int maior[3] = {0};

  int menor[3] = {0};

  menor[0] = menor[1] = menor[2] = array[0];
  maior[0] = maior[1] = maior[2] = array[0];

  for (unsigned int h = 0; h < 10000; h++) {

    if (array[h] >= maior[0]) {
      maior[0] = array[h];
    } else if (array[h] >= maior[1]) {
      maior[1] = array[h];
    } else if (array[h] >= maior[2]) {
      maior[2] = array[h];
    }

    if (array[h] <= menor[0]) {
      menor[0] = array[h];
    } else if (array[h] <= menor[1]) {
      menor[1] = array[h];
    } else if (array[h] <= menor[2]) {
      menor[2] = array[h];
    }
  }
  printf("maiores %i %i %i \n menores %i %i %i",maior[0],maior[1],maior[2],menor[0],menor[1],menor[2]);
    return 0;
  }
