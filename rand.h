#include <stdio.h>
#include <string.h>



void rand()

{
 int rand_a_b(int a, int b) //intilalisation des valeurs randMIN & randMAX

{
    return rand()%(b-a) +a;
}

int i = 0;
int nombre_aleatoire = 0;
int m = 0;
srand(time(NULL)); // initialisation de rand

	for(m=0; m<1; m++)
    {
        rand_a_b(1,7);
		nombre_aleatoire = rand_a_b(1,7); // choix d'un nombre aleatoire entre A & B
		printf("%d\n",nombre_aleatoire);
		fflush(stdout);
    }
