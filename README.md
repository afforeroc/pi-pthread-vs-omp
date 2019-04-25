# Calculo de Pi: Pthread vs OpenMP

## Pi con Pthread
* Compilar: `gcc pi-pthread.c -pthread -o pi-pthread`
* Ejecutar: `./pi-pthread`

## Pi con OpenMP
* Compilar: `gcc -fopenmp pi-omp.c -o pi-omp`
* Ejecutar: `./pi-omp`

## Caracteristicas del computador
<pre>
Procesador: Intel(R) Core(TM) i7-6500U CPU @ 2.50GHz
Memoria: 12 GB
Sistema operativo: Ubuntu 18.10
GCC version: gcc (Ubuntu 8.2.0-7ubuntu1) 8.2.0
</pre>

## Comparativa Pthread vs OpenMP
<pre>
Calculo de Pi con Pthread               Calculo de Pi con OpenMP
hilos = 16, tiempo = 3 seg              hilos = 16, tiempo = 3 seg
parcialPi[0] = 3.14159264558932393996   parcialPi[0] = 3.14159264558932393996
parcialPi[1] = 0.00000000400000000009   parcialPi[1] = 0.00000000400000000009
parcialPi[2] = 0.00000000133333333258   parcialPi[2] = 0.00000000133333333258
parcialPi[3] = 0.00000000066666666667   parcialPi[3] = 0.00000000066666666667
parcialPi[4] = 0.00000000000000000000   parcialPi[4] = 0.00000000039999999975
parcialPi[5] = 0.00000000000000000000   parcialPi[5] = 0.00000000026666666667
parcialPi[6] = 0.00000000000000000000   parcialPi[6] = 0.00000000019047619048
parcialPi[7] = 0.00000000000000000000   parcialPi[7] = 0.00000000014285714286
parcialPi[8] = 0.00000000000000000000   parcialPi[8] = 0.00000000011111111107
parcialPi[9] = 0.00000000000000000000   parcialPi[9] = 0.00000000008888888889
parcialPi[10] = 0.00000000000000000000  parcialPi[10] = 0.00000000007272727273
parcialPi[11] = 0.00000000000000000000  parcialPi[11] = 0.00000000006060606061
parcialPi[12] = 0.00000000000000000000  parcialPi[12] = 0.00000000005128205128
parcialPi[13] = 0.00000000000000000000  parcialPi[13] = 0.00000000004395604396
parcialPi[14] = 0.00000000000000000000  parcialPi[14] = 0.00000000003809523809
parcialPi[15] = 0.00000000000000000000  parcialPi[15] = 0.00000000003333333333
Pi = 3.14159265158932399231             Pi = 3.14159265308932411642
</pre>