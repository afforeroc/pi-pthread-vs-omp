#include "stdio.h"
#include "stdlib.h"
#include "pthread.h"

#define N 16 // numero de hilos
#define t 4000000000 // iteraciones

pthread_t hilo[N];
double parcialPi[N];

double calcPi(long long k) {
  long long max = t*(k+1)/N;
  long long min = t*k/N;
  double x = 0.0;
  int sig = -1;
  long long i;
  for(i=min+1; i<max; i=i+2){
    sig *= -1;
    x += sig*4.0/i;
  }
  return x;
}

void *threadPi(void *i){
  int k;
  k = *((int*)i);
  parcialPi[k] = calcPi(k);
  return NULL;
}

void valoresParcialesPi(){
  int i;
  for(i=0; i<N; i++){
    printf("parcialPi[%d] = %.20f\n", i, parcialPi[i]);
  }
}

double valorPi(){
  int i; 
  double pi = 0.0;
  for (i=0; i<N; i++){
    pi += parcialPi[i];
  }
  return pi;
}

void main(){
  printf("Calculo de Pi con Pthread\n"); // Titulo

  // Variables de tiempo
  time_t start, end, duration;
  start = time(0); // Inicia cronometro

  // Creación de los hilos
  int r, i;
  for(i = 0; i < N; i++) {
    r = pthread_create(&hilo[i], NULL, threadPi, &i);
    if(r < 0) {

      perror("error pthread_create\n");
      exit(-1);
    }
  }

  // Join de los hilos
  void *retval;
  for(i = 0; i < N; i++) {
    r = pthread_join(hilo[i], &retval);
    if(r < 0) {
      perror("error pthread_join\n");
      exit(-1);
    }
  }

  // Calculo final de tiempo de ejecucion
  end = time(0);
  duration = end - start;
  
  // Salida de datos
  printf("hilos = %d, tiempo = %ld seg\n", N, duration);
  valoresParcialesPi();
  printf("Pi = %.20f\n", valorPi());
}