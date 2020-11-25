#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "capteurs.h"
//fonction ajout
void ajouter_capteur(Capteur C)
{
FILE *f=NULL;
f=fopen("capteurs.txt","a");
if(f == NULL)
{
printf("Impossible d'ouvrir le fichier");
}
else
{
fprintf(f,"%s %s %s %d %d %d \n",C.identifiant,C.marque,C.position,C.valeur,C.type,C.etat);
}
fclose(f);
}
//fonction suprresion
void supprimer_capteur(char *id)
{
FILE*f=NULL;
FILE*f1=NULL;
Capteur C ;
f=fopen("capteurs.txt","r");
f1=fopen("anciens.txt","w+");
while(fscanf(f,"%s %s %s %d %d %d \n",C.identifiant,C.marque,C.position,&C.valeur,&C.type,&C.etat)!=EOF)
{
if(strcmp(id,C.identifiant)!=0)
    fprintf(f1,"%s %s %s %d %d %d \n",C.identifiant,C.marque,C.position,C.valeur,C.type,C.etat);
}
fclose(f);
fclose(f1);
remove("capteurs.txt");
rename("anciens.txt","capteurs.txt");
}
//fonction chercher
void chercher_capteur(char *id)
{
FILE*f=NULL;
Capteur C;
f=fopen("capteurs.txt","r");
while(fscanf(f,"%s %s %s %d %d %d \n",C.identifiant,C.marque,C.position,&C.valeur,&C.type,&C.etat)!=EOF)
{
	if(strcmp(id,C.identifiant)!=0)
	{
	printf("L'identfiant est: %s \n",C.identifiant);
	printf("La marque est: %s\n",C.marque);
	printf("Sa position dans la ferme est: %s\n",C.position);
	printf("Sa valeur est: %d \n",C.valeur);
	printf("Son type est: %d \n",C.type);
	printf("Son état est: %d \n",C.etat);
	}
}
fclose(f);
printf("Le capteur n''existe pas ");
}    



// fonction modifier
void modifier_capteur(char *id,Capteur tempo)
{
FILE*f=NULL;
FILE*f1=NULL;
Capteur C;
//printf + scanf de : marque , position, type, etat dans tempo

f=fopen("capteurs.txt","r");
f1=fopen("anciens.txt","w+");
while (fscanf(f,"%s %s %s %d %d %d \n",C.identifiant,C.marque,C.position,&C.valeur,&C.type,&C.etat)!=EOF)
{
if(strcmp(id,C.identifiant)!=0)
{
fprintf(f1,"%s %s %s %d %d %d \n",id,tempo.marque,tempo.position,tempo.valeur,tempo.type,tempo.etat);
}
}
fclose(f);
fclose(f1);
remove("capteurs.txt");
rename("anciens.txt","capteurs.txt");
}
//fonction changer etat
void changer_etat_capteur(char *id ,int etat)
{
FILE *f=NULL;
FILE *f1=NULL;
Capteur C;
//printf + scanf de : marque , position, type, etat dans tempo

f=fopen("capteurs.txt","r");
f1=fopen("anciens.txt","w+");
while (fscanf(f,"%s %s %s %d %d %d \n",C.identifiant,C.marque,C.position,&C.valeur,&C.type,&C.etat)!=EOF)
{
if(strcmp(id,C.identifiant)!=0)
{
fprintf(f1,"%s %s %s %d %d %d \n",C.identifiant,C.marque,C.position,C.valeur,C.type,C.etat);
}
else
{
fprintf(f1,"%s %s %s %d %d %d \n",id,C.marque,C.position,C.valeur,C.type,etat);
}

}
fclose(f);
fclose(f1);
remove("capteurs.txt");
rename("anciens.txt","capteurs.txt");
}

//fonction afficher
void afficher_capteurs()
{
FILE *f=NULL;
Capteur C;
int i=0;
f=fopen("capteurs.txt","r");
while (fscanf(f,"%s %s %s %d %d %d",C.identifiant,C.marque,C.position,&C.valeur,&C.type,&C.etat)!=EOF)
        {
        printf("La fiche du capteur %d\n",i+1);
	printf("\n");
	printf("L'identfiant est %s\n",C.identifiant);
	printf("La marque est: %s\n",C.marque);
	printf("La position du capteur dans la ferme est: %s\n",C.position);
	printf("La valeur du capteur est: %d\n",C.valeur);
	printf("Le type du capteur est: %d\n",C.type);
	printf("L'état du capteur est %d\n",C.etat);
	printf("\n");
	i+=1;
        }

        fclose(f);
}

void capteurs_a_valeurs_alarmantes()
{
FILE *f=NULL;
FILE *f1=NULL;
Capteur C;
f=fopen("capteurs.txt","r");
f1=fopen("alarmantes","a+");
if(f == NULL)
{
printf("Impossible d'ouvrir le fichier");
}
else
{
while (fscanf(f,"%s %s %s %d %d %d \n",C.identifiant,C.marque,C.position,&C.valeur,&C.type,&C.etat)!=EOF)
{
if(C.valeur>100)
{
fprintf(f1,"%s %s %s %d %d %d \n",C.identifiant,C.marque,C.position,C.valeur,C.type,C.etat);
}
}
}
fclose(f);
fclose(f1);
}
