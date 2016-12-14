#include <stdio.h>
#include <string.h>
int main()
{
char txt[5000];
int nbc,j,i,k;
int dyn=0;
int sta=0;
int tera=0;
char caractuel;
//printf("entrez du texte\n");
FILE *fichier= NULL;
fichier = fopen("log.txt","r");
do
{
    caractuel= fgetc(fichier);
printf("%c",caractuel);
}
while (caractuel != EOF);

gets(caractuel);
nbc = strlen(caractuel);
j=0;


for (i=0;i <nbc;i++)
if (caractuel[i] == 'd')
{
    i ++;
      if (caractuel[i] == 'y')
      {
          i++;
           if (caractuel[i] == 'n')
           {

            dyn ++;

                      }
                  }
            }


else if (caractuel[i] == 's'){

    i ++;
     if (caractuel[i] == 't')
     {
        i ++;
          if (caractuel[i] == 'a'){
            sta++;
               }
            }
         }
else if (caractuel[i] == 'i'){
    i++;
     if(caractuel[i] == 'n')
    {
        i++;
          if(caractuel[i] == 't'){
           tera++;
           }
         }
        }

printf("le type dynamique a ete lance %d fois\nle type interactif %d fois\nle type statique %d fois\n",dyn,tera,sta);



return 0;
    }
