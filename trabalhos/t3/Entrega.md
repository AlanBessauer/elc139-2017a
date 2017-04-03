Programação Paralela - Alan Bessauer Lencina 
```
Pthreads
```
1.
O particionamento é dado no inicio da execução, dependendo de quantos threads são passados para ser usado, cria um numero
de threads worker igual a esse numero com o codigo :
```
for (i = 0; i < nthreads; i++) {
      pthread_create(&threads[i], &attr, dotprod_worker, (void *) i);
   }
```
A comunicação das threads é dada pelo codigo :
```
pthread_mutex_lock (&mutexsum);
dotdata.c += mysum;
pthread_mutex_unlock (&mutexsum);
``` 
No qual só é somado o mysum quando todas as threads terminaram seus respectivos trabalhos.

A aglomeração acontece nessa mesma adição de cima, o resultado das threads é adicionado à dotdata.c da variavel global dotdata.

O mapeamento para equilibrar o trabalho das threads é feito pela atribuição de um mesmo trabalho com os mesmos valores e tamanhos para
todas as threads:
``` 
   for (k = 0; k < dotdata.repeat; k++) {
      mysum = 0.0;
      for (i = start; i < end ; i++)  {
         mysum += (a[i] * b[i]);
      }
   }
``` 
2.
A aceleração que encontrei usando o tamanho e repetições pedido anteriormente foi 36778622 usec com 1 thread
para 22291222usec com 2 threads, no qual resulta numa aceleração de 1.645 vezes mais rapido com 2 threads.

3 & 4.

O resultado da aceleração em cada nivel diferente de repetições ficou mais ou menos na mesma media de resultados,
Dificil de dizer com absoluta certeza o numero exato, mesmo com poucos processos alem do programa em si havia constante
variação nos resultados, mas fiz uma tabela com oque consegui.


| Repetições                                           | Threads  | Tamanho  | Tempo  | Aceleração |
| --------------------------------------------------------- | --------------------- | --------------- |-----|----|
|  1000|1                     |10000000                      |36778622~37283020usec |1|
|  1000               |2   |10000000 |21741667~22291222usec |1,68202x|
|  500             |  1                  | 10000000             |18399602~18556421usec |1|
|  500           |   2                |   10000000           |11079117~11555640usec |1,6373x|
|  250              |  1                     |  10000000               |9146717~9363491usec |1|
|  250               |  2                    |  10000000              |5572279~5614939usec |1,6975x|
|  100                       |  1                     | 10000000         |3699223~3948350usec |1|
|  100                                        | 2                      | 10000000              |2160490~2226309usec |1,742334x|

E a aceleração em media foi 1.70x/70%.

5.
A diferença entre os 2 programas era que em um é verificado se todos os threads estavam finalizados para encontrar o resultado,
enquanto no outro simplesmente adicionam assim que finalizam as operações.
O programa ainda funciona, mas pode ocorrer que aconteça um problema na hora de adicionar o resultado ja que nao há nenhuma verificação
e se as 2 threads adicionarem ao resultado no mesmo instante, pode ocorrer um problema.
É dificil de acontecer nesse caso, mas poderia ser mais problemático em algum outro processo multithread.

```
openMP
```

No desempenho openMP, encontrei basicamente os mesmos resultados que havia encontrado usando pthreads com o mesmo numero de threads,
maior diferença encontrada foi que havia uma maior variação que usando o programa com pthreads.
Talvez seja algum problema com o modo que usei, entao vou deixar o programa com openMP na pasta.

