Alan Bessauer Lencina
- Programacao Paralela

Testes feito em um notebook Dell Inspiron 15 5000 com core i5-7200U, frequencia de 2.50 GHz ate 2.70GHz 8GB de RAM.

em maquina virtual de ubuntu com gcc 6.3.0-12ubuntu2.

Links:

https://github.com/AlanBessauer/elc139-2017a/blob/master/trabalhos/t8/sequencial.c
https://github.com/AlanBessauer/elc139-2017a/blob/master/trabalhos/t8/dinamico.c

Fiz o MPI dinamico com varios grandes vetores, onde o trabalho e dividido pelo processo mestre entre os trabalhadores, em cada um dos
trabalhadores e percorrido esse vetor enquanto faz um pequeno sleep para "imitar" um trabalho a cada interacao ate alcancar o fim do vetor.
entao e mandado uma mensagem para o mestre avisando que o vetor foi percorrido, e depois que o mestre recebe essa mensagem, ele manda
um novo trabalho para o processo trabalhador que acabou de o contatar.

Os resultados do programa feito dinamicamente foram em media 4 vezes mais rapido que o sequencial, que me leva a imaginar que tenha algo de errado.


