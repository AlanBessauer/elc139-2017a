#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <chrono>
#include <omp.h>
#include "Random.h"
#include "Forest.h"

void
checkCommandLine(int argc, char** argv, int& size, int& trials, int& probs)
{
   if (argc > 1) {
      size = atoi(argv[1]);
   }   
   if (argc > 2) {
      trials = atoi(argv[2]);
   }
   if (argc > 3) {
      probs = atoi(argv[3]);
   }   
}

int 
main(int argc, char* argv[]) 
{
   // parâmetros dos experimentos
   int forest_size = 30;
   int n_trials = 5000;
   int n_probs = 101;

   double* percent_burned; // percentuais queimados (saída)
   double* prob_spread;    // probabilidades (entrada)
   double prob_min = 0.0;
   double prob_max = 1.0;
   double prob_step;
   int base_seed = 100;
   int ip, it;

   checkCommandLine(argc, argv, forest_size, n_trials, n_probs);
    
auto start = std::chrono::high_resolution_clock::now();


   try {

      Forest* forest = new Forest(forest_size);
      Random rand;

      prob_spread = new double[n_probs];
      percent_burned = new double[n_probs];

      prob_step = (prob_max - prob_min)/(double)(n_probs-1);

      printf("Probabilidade, Percentual Queimado\n");


      // para cada probabilidade, calcula o percentual de árvores queimadas
	#pragma omp parallel shared(percent_burned, prob_spread) private(ip, it)
		{
      for (ip = 0; ip < n_probs; ip++){

         prob_spread[ip] = prob_min + (double) ip * prob_step;
         percent_burned[ip] = 0.0;
         rand.setSeed(base_seed+ip); // nova seqüência de números aleatórios

         // executa vários experimentos

         for (it = 0; it < n_trials; it++){
            // queima floresta até o fogo apagar
            forest->burnUntilOut(forest->centralTree(), prob_spread[ip], rand);
            percent_burned[ip] += forest->getPercentBurned();
         }
         // calcula média dos percentuais de árvores queimadas
	#pragma omp barrier
	
         percent_burned[ip] /= n_trials;

         // mostra resultado para esta probabilidade
         printf("%lf, %lf\n", prob_spread[ip], percent_burned[ip]);
			}
		}
	//fim da area paralela
      delete[] prob_spread;
      delete[] percent_burned;
   }
   catch (std::bad_alloc)
   {
      std::cerr << "Erro: alocacao de memoria" << std::endl;
      return 1;
   }

auto elapsed = std::chrono::high_resolution_clock::now() - start;
long long microseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();
  //fim da contagem
printf("%.llu microsegundos \n", microseconds);

   return 0;
}
