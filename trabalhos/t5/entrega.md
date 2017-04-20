Programacao paralela 
Alan Bessauer Lencina

foi usado o Asus Vivobook S500CA com processadores Intel Core i7-3537U, frequencia de -2.0GHz, turbo -3.1GHz e 2 cores.
GCC usado e 6.2.0-5ubuntu12 6.2.0 

Nao consegui fazer o trabalho, tentei fazer parallel com sections e deu varios erros que me levam a acreditar que
ele nao funciona para for entrelacados que nem o desse programa.
tentando usar 
```
chunk = n_trials/2
#pragma omp parallel shared(percent_burned,prob_spread,,chunk) private(ip,it)
   {

   #pragma omp for schedule(dynamic,chunk) nowait
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
 ```
 deu o mesmo resultado que com uma thread.

 usando parallel so no segundo for deu um resultado em media 4 vezes mais rapido que o normal que
 imagino estar totalmente errado.
 
 O resultado mais prox do que poderia ser considerado foi oque vou mandar junto, que normalmente variava
 de uma aceleracao de 1.50x ate um pouco acima de 2.0x, mas imagino que ainda estava errado pois a 
 porcentagem queimada saia errada.
 

| Repetições                                           | Threads  |prob |size  | Tempo  | Aceleração |
| --------------------------------------------------------- | --------------------- | --------------- |-----|----|----|
|  1000|1                     |85    |20            |6682174-6932142microsegundos |1x|
|  1000               |2   |85 |20 |3420719-3667521microsegundos|1,91x|
|  500             |  1                  | 100             |20 |4201625-4309691microsegundos|1x|
|  500           |   2                |   100           |20 |2273375-2501490microsegundos|1,78x|
|  250              |  1                     |  100               |20 |2212414-2404714microsegundos|1x|
|  250               |  2                    |  100              |20 |1469489-1531712microsegundos|1.53x|







