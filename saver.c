
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#include <ctype.h> // declaration des bibliotheques


int main(int argc, char* argv[])
{
 int c; // declaration de la variable qui permettra de lancer le paramettre
 char ret3;
 if ((c = getopt (argc, argv, "-stat")) != -1)//si l'exe est lance avec un parametre -stat
{
execl("/home/merouane/Desktop/Exia-saver/log","log", "-1",NULL); //execution de l'executable log
}

 system("clear"); //nettoyage de la console
 int i=0; //declaration de la variable i
 int nbal=0; // declaration du nombre aleatoire qui conditionnera l'execution d'un programme
FILE *fr; // pointeur fichiers


time_t t = time(NULL);
struct tm *tm = localtime(&t); //attribution de l'heure locale a une structure time
char stime[100]; // declaration d'une chaine de charachteres nommée stime
strftime(stime,sizeof(stime),"%c",tm);//strftime recupere le temps actuel depuis tm et le place dans la chaine de charactere stime



 srand(time(NULL)); // permet d'utiliser rand pour avoir un nombre generer aleatoirement

nbal= rand()%(4-1) + 1; //nombre aleatoire est tirée au hasard entre 1 et 3

if (nbal == 1) // si nombre aleatoire est egale a 1
{
fr = fopen("log.txt","a+"); //ouverture du fichier txt qui sert d'historique
fprintf(fr,"%s %s %s ",stime,"type","statique"); //ecriture sur le fichier txt de l'heure actuelle et de la mention "type statique"
fflush(stdout); // fonction permetant d'avoir un affichage fluide
fclose(fr); // fermeture du fichier txt
execl("/home/merouane/Desktop/Exia-saver/Term-saver1/Term-saver1","Term-saver1","-1",NULL); // lancement de l'executable pour le type statique
}
else if (nbal == 2) // si nombre aleatoire est egal a 2
{
fr = fopen("log.txt","a+"); //ouverture du fichier txt qui sert d'historique
fprintf(fr,"%s %s %s\n",stime,"type","dynamique"); // ecriture sur le fichier txt de l'heure actuelle et de la mention "type dynamique"
fclose(fr); //fermeture du fichier txt
execl("/home/merouane/Desktop/Exia-saver/Term-saver2/Term-saver2","Term-saver2","-1",NULL);//lancement de l'executable pour le type dynamique

}
else if (nbal == 3 ) // si le nombre aleatoire est a trois
{
fr = fopen("log.txt","a+"); // ouverture du fichier txt qui sert d'historique
fprintf(fr,"%s %s %s\n",stime,"type","interactif"); // ecriture sur le fichier txt de l'heure actuelle et de la mention "type interactif"
fclose(fr); // fermeture du fichier txt
ret3 =execl("/home/merouane/Desktop/Exia-saver/interactif","interactif","-1",NULL);

}

return 0;
 }//fin du programme
