#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>

typedef struct 
 {
   double *a;
   double *b;
   double c; 
   int wsize;
   int repeat; 
 } dotdata_t;

// Variaveis globais, acessiveis por todas threads
dotdata_t dotdata;

/*
 * Funcao executada por uma thread
 */
void *dotprod_worker()
{
   #pragma omp parallel 
{
   int i, k;
   double *a = dotdata.a;
   double *b = dotdata.b;     
   int wsize = dotdata.wsize;
   int start = 0;
   int end = wsize;
   double mysum1;
   double mysum2;
 	
	for (k = 0; k < dotdata.repeat; k++){
	mysum1 = 0.0;
   	mysum2 = 0.0;
	#pragma parallel selection
	{
		for (i = start; i < (wsize/2) ; i++)  {
         		mysum1 += (a[i] * b[i]);
		}
	}
	#pragma parallel selection
	{
		for (i = (wsize/2); i < end ; i++)  {
         		mysum2 += (a[i] * b[i]);
		}
	}
}
dotdata.c += mysum1;
dotdata.c += mysum2;
}
}



/*
 * Tempo (wallclock) em microssegundos
 */ 
long wtime()
{
   struct timeval t;
   gettimeofday(&t, NULL);
   return t.tv_sec*1000000 + t.tv_usec;
}

/*
 * Preenche vetor
 */ 
void fill(double *a, int size, double value)
{  
   int i;
   for (i = 0; i < size; i++) {
      a[i] = value;
   }
}

/*
 * Funcao principal
 */ 
int main(int argc, char **argv)
{
   int nthreads, wsize, repeat;
   long start_time, end_time;

   if ((argc != 3)) {
      printf("Uso: %s  <worksize> <repetitions>\n", argv[0]);
      exit(EXIT_FAILURE);
   }

   nthreads = 2; 
   wsize = atoi(argv[1]);  // worksize = tamanho do vetor de cada thread
   repeat = atoi(argv[2]); // numero de repeticoes dos calculos (para aumentar carga)

   // Cria vetores
   dotdata.a = (double *) malloc(wsize*nthreads*sizeof(double));
   fill(dotdata.a, wsize*nthreads, 0.01);
   dotdata.b = (double *) malloc(wsize*nthreads*sizeof(double));
   fill(dotdata.b, wsize*nthreads, 1.0);
   dotdata.c = 0.0;
   dotdata.wsize = wsize;
   dotdata.repeat = repeat;

   // Calcula c = a . b em nthreads, medindo o tempo
   start_time = wtime();
   dotprod_worker();
   end_time = wtime();

   // Mostra resultado e estatisticas da execucao
   printf("%f\n", dotdata.c);
   printf("%d thread(s), %ld usec\n", nthreads, (long) (end_time - start_time));
   fflush(stdout);

   free(dotdata.a);
   free(dotdata.b);

   return EXIT_SUCCESS;
}
