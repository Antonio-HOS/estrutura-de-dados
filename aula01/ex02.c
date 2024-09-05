#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void ordenar(int *Array, int tam);
double media(int *Array, int tam);
double deviopadrao(int *Array, int tam, double media);
void histograma(int *Array, int tam, int *NovoArray);

int main() {
  int *array;
  array = (int *)malloc(sizeof(int) * 10000);
  int *hist;
  hist = (int *)calloc(1000, sizeof(int));
  for (unsigned int j = 0; j < 10000; j++) {
    array[j] = rand() % 1000;
  }

  clock_t inicio, fim;
  double tempo_gasto;
  inicio = clock();

  ordenar(array, 10000 - 1);

  printf("\n\n maiores %i %i %i \n menores %i %i %i", array[0], array[1], array[2],
         array[9999], array[9998], array[9997]);

  double Vmedia = media(array, 10000);
  printf("\n\n media %.2f", Vmedia);

  printf("\n\n mediana %.2f", (double)(array[4999] + array[5000]) / 2);

  printf("\n\n desvio padrao %f", deviopadrao(array, 10000, Vmedia));

  histograma(array, 10000, hist);

  fim = clock();
  tempo_gasto = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

  printf("\n\n Tempo de execucao: %f segundos\n", tempo_gasto);

  for (int i = 0; i < 1000; i++) {
    printf("   %i-->%i   ", i, hist[i]);
  }

  return 0;
}

void ordenar(int *Array, int tam) {
  if (tam < 1) {
    return;
  }
  int aux = 0;

  for (int i = 0; i < tam; i++) {
    if (Array[i] < Array[i + 1]) {
      aux = Array[i];
      Array[i] = Array[i + 1];
      Array[i + 1] = aux;
    }
  }
  ordenar(Array, tam - 1);
}

double media(int *Array, int tam) {

  unsigned long int x = 0;
  for (unsigned int i = 0; i < tam; i++) {
    x += Array[i];
  }
  return (double)x / tam;
}

double deviopadrao(int *Array, int tam, double media) {
  double soma = 0;

  for (int i = 0; i < tam; i++) {

    soma = (Array[i] - media) * (Array[i] - media);
  }

  soma = soma / tam;

  return sqrt(soma);
}

void histograma(int *Array, int tam, int *NovoArray) {
  for (int i = 0; i < tam; i++) {
    NovoArray[Array[i]]++;
  }
}
