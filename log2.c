#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{




int  nbchoix =0; // declaration de l'entier qui permettra d'avoir un choix
printf("veuillez faire un choix\n1-affichage par type:\n2-affichage par date\n3-sortir du  programme");//affichage du menu log

scanf("%d",&nbchoix); // recuperation de l'entree utilisateur et attribution de celle ci au nombre

FILE *fs; //declaration d'un pointeur de fichier
char buf [250]; // declaration du buffer

size_t sz; //definition de  sz
if (nbchoix ==1) //si le nombre entrée est 1 
{
execl("/home/merouane/Desktop/Exia-saver/maindet","maindet","-1",NULL);//l'exe maindet est lance 


}
else if ( nbchoix == 2) //si le nombre entree est 2
{
fs = fopen("log.txt", "r"); //le pointeur est utilisé pour ouvrir le fichier log en lecture

while(!feof(fs)) // tant qu'il ya des caracteres
{
sz = fread((void *) buf,100,1,fs); // sz lira et recuperera ce qui est inscrit sur le fichier log
printf("%s",buf); //les caracetre recupere seront affiche
}
fclose(fs); //fermeture du fichier log
}
else if (nbchoix == 3 ) // si le nombre 3 est entre
{
printf("sortie du programme\n"); // affichage du message sortie du programme
} //fin de programme
return 0;
}
