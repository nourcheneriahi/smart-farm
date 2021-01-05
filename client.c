#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "capteurs.h"


//fonction ajout

void ajoutClient(client C)
{
FILE *f=NULL;
f=fopen("clients.txt","a");
fprintf(f,"%s %s %s %s %s \n", C.id, C.nom, C.prenom, C.tel, C.mail);
fclose(f);
}

//fonction suprresion

void SuppClient(char *idSupp)
{
FILE*f=NULL;
FILE*f1=NULL;
client C ;
f=fopen("clients.txt","r");
f1=fopen("nouveau.txt","w");
while(fscanf(f,"%s %s %s %s %s \n", C.id, C.nom, C.prenom, C.tel, C.mail)!=EOF)
{
if(strcmp(idSupp,C.id)!=0)
    fprintf(f1,"%s %s %s %s %s \n", C.id, C.nom, C.prenom, C.tel, C.mail);
}
fclose(f);
fclose(f1);
remove("clients.txt");
rename("nouveau.txt","clients.txt");
}

//fonction chercher            A ETUDIER


client chercherClient(char * idChercher)
{
FILE*f=fopen("clients.txt","r");
client C;
while(fscanf(f,"%s %s %s %s %s\n", C.id, C.nom, C.prenom, C.tel, C.mail)!=EOF)
{
if(strcmp(idChercher,C.id)==0){
return C;
}
}
fclose(f);
printf("Le client est introuvable");
}




// fonction modifier
void modifClient(char *idModif, client tempo)
{
FILE*f=NULL;
FILE*f1=NULL;
client C;

//printf + scanf de : marque , position, type, etat dans tempo

f=fopen("clients.txt","r");
f1=fopen("nouveau.txt","w+");
while (fscanf(f,"%s %s %s %s %s \n", C.id, C.nom, C.prenom, C.tel, C.mail)!=EOF)
{
if(strcmp(idModif,C.id)!=0)
{
fprintf(f1,"%s %s %s %s %s \n", C.id, C.nom, C.prenom, C.tel, C.mail);
}

else
{
fprintf(f1,"%s %s %s %s %s \n", idModif, tempo.nom, tempo.prenom, tempo.tel, tempo.mail);
}

}
fclose(f);
fclose(f1);
remove("clients.txt");
rename("nouveau.txt","clients.txt");
}

//fonction afficher
void afficherClient()
{
FILE *f=NULL;
client C;
f=fopen("clients.txt","r");

if(f!=NULL)
{
    while (fscanf(f,"%s %s %s %s %s", C.id, C.nom, C.prenom, C.tel, C.mail)!=EOF)
        {
            printf("identifiant: %s ; nom: %s ; prenom: %s ; tel: %s ; mail: %s \n", C.id, C.nom, C.prenom, C.tel, C.mail);
        }

        fclose(f);
}
else
    {
        printf("Une erreur est survenue");
    }

}
