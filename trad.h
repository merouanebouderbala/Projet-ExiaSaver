#include <stdio.h>
#include <stdlib.h>

tab ;
char caractere;
int v,c,k,l=0;
int affiheure()


{
FILE* fp = NULL;
if (fp != NULL){

  fseek(fp, 18, SEEK_SET);

do{
    for (k = 0; k < 30; k++){
    v = 0;

    for (l = 0; l < 3; l++){
    caractere = fgetc(fp);
    if ( caractere == '0')
    {

    caractere = ' ';
     tab[c][v] = caractere;
      v++;
    }
   else if ( caractere == ' ')
    {
      caractere = ' ';
      tab[c][v] = caractere;
      v++;
    }
    else if ( caractere == '1')
    {
      caractere = 'X';
      tab[c][v] = caractere;
    v++;
    }
    printf("%c", caractere);
  }

c++;
}
  }while(caractere != EOF);
}
}
