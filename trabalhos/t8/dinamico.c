#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include "mpi.h"

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
  end = 0;
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
  MPI_Status status;   
  MPI_Request request;
  MPI_Init(&argc, &argv);
  MPI_Comm_rank(MPI_COMM_WORLD, &myrank);
  MPI_Comm_size(MPI_COMM_WORLD, &p);
  	if(myrank == 0){
			char processor_name[MPI_MAX_PROCESSOR_NAME];
    			int name_len;
    			MPI_Get_processor_name(processor_name, &name_len);
    			for (i = 1; i < p; i++){
				n = (i-1);
				printf("trabalhador %d inicializou vetor %d.\n", i, n);
    				MPI_Send(&n, 1, MPI_INT, i, 0, MPI_COMM_WORLD);
				end++;
    				}
			i--;
			while(1){
			
			if (end == 10){
			i = 15;
			for (x = 1;x < p;x++){
				MPI_Send(&i, 1, MPI_INT, x, 0, MPI_COMM_WORLD);
				}
			break;
			}
			MPI_Recv(&sender, 1, MPI_INT, MPI_ANY_SOURCE, 1, MPI_COMM_WORLD, &status);
			if (sender != 0){
				i++;
				end++;
                                n = i-1;
				printf("iniciou vetor %d em processo %d.\n", n,sender);
				MPI_Send (&n, 1, MPI_INT, sender, 0, MPI_COMM_WORLD);
				}
			}
		}
	
	if (myrank != 0){	
		while(1){
		MPI_Recv(&indice, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);
		if (indice == 15){
			break;
			}
		z = indice;
		for(x = 0; x <= 100001; x++){
			usleep(20);
			if ( v[z][x] == 500){
				MPI_Send(&myrank, 1, MPI_INT, 0, 1, MPI_COMM_WORLD);
				printf("processo %d terminou vetor %d.\n", myrank, z);
				if(z == 9){
					fim = wtime();
  					printf("demorou %ld usec \n",(long)(fim - inicio));
				}
				x = 100002;		
				}
			}
		}
	}
  MPI_Finalize();
  return 0;
}
