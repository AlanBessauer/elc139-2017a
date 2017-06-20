#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

int main(int argc, char* argv[]) {
  int myrank;                     
  int source; 
  int p;        
  int dest;
  int x, z, n, size, i, end, working, k;
  long inicio, fim;
  int v1[10001],v2[25001],v3[17501],v4[5001],v5[100001],v6[70001],v7[50001],v8[80001],v9[40001],v10[60001]; 
  int* v[10];               
  int indice, sender;
  int trabalho;
  working = 0;
  end = 1;
  trabalho = 0;
  long wtime()
{
	struct timeval t;
	gettimeofday(&t, NULL);
	return t.tv_sec*1000000 + t.tv_usec;
}
        inicio = wtime();
	for (n = 0; n < 100001;n++){
		v5[n] = 10;
		}
	for (n = 0; n < 80001;n++){
		v8[n] = 10;
		}
	for (n = 0; n < 10001;n++){
		v1[n] = 10;
		}
	for (n = 0; n < 25001;n++){
		v2[n] = 10;
		}
        for (n = 0; n < 17501;n++){
		v3[n] = 10;
		}
        for (n = 0; n < 60001;n++){
		v10[n] = 10;
		}
        for (n = 0; n < 50001;n++){
		v7[n] = 10;
		}
        for (n = 0; n < 40001;n++){
		v9[n] = 10;
		}
        for (n = 0; n < 5001;n++){
		v4[n] = 10;
		}
        for (n = 0; n < 70001;n++){
		v6[n] = 10;
		}
  v1[10001] = 500, v[0] = v1;
  v2[25001] = 500 , v[1] = v2;
  v3[17501] = 500, v[2] = v3;
  v4[5001] = 500, v[3] = v4;
  v5[100001] = 500, v[4] = v5;
  v6[70001] = 500, v[5] = v6;
  v7[50001] = 500, v[6] = v7;
  v8[80001] = 500, v[7] = v8;
  v9[40001] = 500, v[8] = v9;
  v10[60001] = 500, v[9] = v10;
  for(x = 0;x < 9;x++){
	for(z = 0;z <= 100001;z++){
	usleep(20);
	if(v[x][z]== 500){
		z = 100002;
		printf("terminou vetor %d \n", x);
		}
	}
}
fim = wtime();
printf("demorou %ld usec \n",(long)(fim - inicio));
}
