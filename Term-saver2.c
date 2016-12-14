#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include "center.h"
#include "clear.h"

struct tm instant;
int separerheure(struct tm instant);
int i;
int x,n,j,k,l,v,c=0;
int h0=0;
int h1=0;
int m0=0;
int m1=0;
int s0=0;
int s1=0;
int valaffiche=0;
char tab [1][1]={1};

int separerheure(struct tm instant)  //Separer chaque decimale de du temps en hh:mm:ss

{
h0 = (instant.tm_hour)/10 ;
h1 = (instant.tm_hour)-(h0*10);
m0 = (instant.tm_min)/10;
m1 = (instant.tm_min)-(m0*10);
s0 = (instant.tm_sec)/10;
s1 = (instant.tm_sec)-(s0*10);
}

int main(int argc, char* argv[])
{

term_clear();               //Vider la console au demarrage

 const char* para = getenv("EXIASAVER2_SLEEP");    //Appeller la variable d'environnement

 time_t secondes;



    time(&secondes);                  //Appeller horloge systeme
    instant=*localtime(&secondes);

separerheure(instant);             //Prendre la valeur de chaque decimale du temps

for (i; i < 8; i++)               //Parcourir chaque decimale individuellement et prendre sa valeur entre 0 et 9 + :
  {

  if (i == 0)
    { valaffiche = h0;}
    else if (i == 1)
    { valaffiche =h1;}
    else if (i == 2)
    { valaffiche =29;}            //Code ascii pour separer des groupes GS
    else if ( i == 3)
    { valaffiche =m0;}
    else if ( i == 4)
    { valaffiche =m1;}
    else if (i == 5)
    { valaffiche =29;}            //Code ascii pour separer des groupes GS
    else if ( i == 6)
    { valaffiche =s0;}
    else if ( i == 7)
    { valaffiche =s1;}


FILE* fp = NULL;                  //Pointeur de fichier

char caractere;

switch(valaffiche)               //Caser chaque chiffre du temps avec un fichier pbm correspondant
{
    case 0:
    fp = fopen("/home/merouane/Desktop/Exia-saver/Term-saver2/zero.pbm","r");
    break;

    case 1:
    fp = fopen("/home/merouane/Desktop/Exia-saver/Term-saver2/un.pbm","r");
    break;

    case 2:
    fp = fopen("/home/merouane/Desktop/Exia-saver/Term-saver2/deux.pbm","r");
    break;

    case 3:
    fp = fopen("/home/merouane/Desktop/Exia-saver/Term-saver2/trois.pbm","r");
    break;

    case 4:
    fp = fopen("/home/merouane/Desktop/Exia-saver/Term-saver2/quatre.pbm","r");
    break;

    case 5:
    fp = fopen("/home/merouane/Desktop/Exia-saver/Term-saver2/cinq.pbm","r");
    break;

    case 6:
    fp = fopen("/home/merouane/Desktop/Exia-saver/Term-saver2/six.pbm","r");
    break;

    case 7:
    fp = fopen("/home/merouane/Desktop/Exia-saver/Term-saver2/sept.pbm","r");
    break;

    case 8:
    fp = fopen("/home/merouane/Desktop/Exia-saver/Term-saver2/huit.pbm","r");
    break;

    case 9:
    fp = fopen("/home/merouane/Desktop/Exia-saver/Term-saver2/neuf.pbm","r");
    break;

    case 29:
    fp = fopen("/home/merouane/Desktop/Exia-saver/Term-saver2/points.pbm","r");
    break;

 // default :                          //En cas de case vide, imprimer un espace vide

}

if (fp != NULL){                     //Parcours de chaque fichier pbm

  fseek(fp, 18, SEEK_SET);           //Siter emplacement de depart avec offset

do{
    for (k = 0; k < 5; k++){        //Recupere tous les 1 et 0 de chaque pbm et les stocker dans un tableau
    v = 0;

    for (l = 0; l < 3; l++){         //Trois critaires a verifier
    caractere = fgetc(fp);           //Ouvrir fichier
    if ( caractere == '0')           //Remplacer les 0 par des espaces
    {
    caractere = ' ';
     tab[c][v] = caractere;          //Stocker dans tableau v
      v++;
    }
   else if ( caractere == ' ')        //Laisser les espaces tel quel
    {
      caractere = NULL;
      tab[c][v] = caractere;        //Stocker dans tableau v
      v++;
    }
    else if ( caractere == '1')       //Remplacer les 1 par des X et stocker dans tableau
    {
      caractere = 'X';
      tab[c][v] = caractere;
    v++;

    }
    printf("%c",caractere);              //Afficher le fichier pbm et X espace
  }
}
  }while(caractere != EOF);              //Condition pour executer le processus
}
}
 i = 0;

   //printf("%d:%d:%d\n",instant.tm_hour,instant.tm_min,instant.tm_sec);
   //fflush(stdout);
    printf_center("Cet ecran sera actualise dans quelques secondes");    //Message d'actualisation
    fflush(stdout);

    for (x=0; x< atoi(para); x++)            //Appelle de la variable d'environnement
    {
        printf(".");                        //Afficher un point a chaque seconde selon la variable d'environnement
        fflush(stdout);
        sleep(1);
    }

//    getchar();

    term_clear();                             //Vider la console avant d'actualiser le terminale

}




