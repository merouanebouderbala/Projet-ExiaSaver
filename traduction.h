#include <stdio.h>
#include <stdlib.h>

int affichage(fichier) {
  char caractere;

  if (fichier != NULL) {
    fseek (fichier, 14, SEEK_SET);
    do {
      caractere = fgetc(fichier);
      if (caractere == '0') {caractere = ' ';}

      else if (caractere == '1') {caractere = 'X';}
      printf("%c", caractere);
    } while (caractere != EOF);
  }
