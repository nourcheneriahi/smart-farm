#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "capteurs.h"
//fonction ajout
void ajouter_capteur(Capteur C)
{
FILE *f=NULL;
FILE *f1=NULL;
FILE *f2=NULL;
f=fopen("capteurs.txt","a");
if(f == NULL)
{
printf("Impossible d'ouvrir le fichier");
}
else
{
fprintf(f,"%s %s %s %s %d %d\n",C.identifiant,C.marque,C.position,C.type,C.valeur,C.etat);
	if ((C.valeur>=101) && (C.valeur<=201)){
	f1=fopen("alarmantes.txt","a");
	fprintf(f1,"%s %s %s %s %d %d\n",C.identifiant,C.marque,C.position,C.type,C.valeur,C.etat);
	fclose(f1);
	}
	if (C.etat==0){
	f2=fopen("defectueux.txt","a");
	fprintf(f2,"%s %s %s %s %d %d\n",C.identifiant,C.marque,C.position,C.type,C.valeur,C.etat);
	fclose(f2);
	}
fclose(f);
}
}
//fonction suprresion
void supprimer_capteur(char *id)
{
FILE*f=NULL;
FILE*f1=NULL;
Capteur C ;
f=fopen("capteurs.txt","r");
f1=fopen("ancienscap.txt","w+");
while(fscanf(f,"%s %s %s %s %d %d\n",C.identifiant,C.marque,C.position,C.type,&C.valeur,&C.etat)!=EOF)
{
if(strcmp(id,C.identifiant)!=0)
    fprintf(f1,"%s %s %s %s %d %d\n",C.identifiant,C.marque,C.position,C.type,C.valeur,C.etat);
}
fclose(f);
fclose(f1);
remove("capteurs.txt");
rename("ancienscap.txt","capteurs.txt");
}
//fonction chercher
void chercher_capteur(char * id){
remove("capteurs_recherche.txt");
FILE*f=fopen("capteurs.txt","r");
FILE*f1=fopen("capteurs_recherche.txt","a+");
Capteur C;
while(fscanf(f,"%s %s %s %s %d %d\n",C.identifiant,C.marque,C.position,C.type,&C.valeur,&C.etat)!=EOF)
{
if(strcmp(id,C.identifiant)==0){
fprintf(f1,"%s %s %s %s %d %d\n",C.identifiant,C.marque,C.position,C.type,C.valeur,C.etat);

}
}
fclose(f);
fclose(f1);
}

// fonction modifier
void modifier_capteur(Capteur tempo, char*id ){
FILE*f=fopen("capteurs.txt","r");
FILE*f1=fopen("ancienscap.txt","w+");
Capteur C;
while(fscanf(f,"%s %s %s %s %d %d\n",C.identifiant,C.marque,C.position,C.type,&C.valeur,&C.etat)!=EOF)
{
if(strcmp(C.identifiant,id)==0)
{
fprintf(f1,"%s %s %s %s %d %d\n",id,tempo.marque,tempo.position,tempo.type,tempo.valeur,tempo.etat);
}
else{
fprintf(f1,"%s %s %s %s %d %d\n",C.identifiant,C.marque,C.position,C.type,C.valeur,C.etat);
}
}
fclose(f);
fclose(f1);
remove("capteurs.txt");
rename("ancienscap.txt","capteurs.txt");
}
//fonction changer etat
void changer_etat_capteur(char *id ,int etat)
{
FILE *f=NULL;
FILE *f1=NULL;
Capteur C;
//printf + scanf de : marque , position, type, etat dans tempo

f=fopen("capteurs.txt","r");
f1=fopen("ancienscap.txt","w+");
while (fscanf(f,"%s %s %s %s %d %d\n",C.identifiant,C.marque,C.position,C.type,&C.valeur,&C.etat)!=EOF)
{
if(strcmp(id,C.identifiant)!=0)
{
fprintf(f1,"%s %s %s %s %d %d\n",C.identifiant,C.marque,C.position,C.type,C.valeur,C.etat);
}
else
{
fprintf(f1,"%s %s %s %s %d %d\n",id,C.marque,C.position,C.type,C.valeur,etat);
}

}
fclose(f);
fclose(f1);
remove("capteurs.txt");
rename("ancienscap.txt","capteurs.txt");
}

//fonction afficher
void afficher_capteurs()
{
FILE *f=NULL;
Capteur C;
int i=0;
f=fopen("capteurs.txt","r");
while (fscanf(f,"%s %s %s %s %d %d\n",C.identifiant,C.marque,C.position,C.type,&C.valeur,&C.etat)!=EOF)
        {
        printf("La fiche du capteur %d\n",i+1);
	printf("\n");
	printf("L'identfiant est %s\n",C.identifiant);
	printf("La marque est: %s\n",C.marque);
	printf("La position du capteur dans la ferme est: %s\n",C.position);
	printf("Le type du capteur est: %s\n",C.type);
	printf("La valeur du capteur est: %d\n",C.valeur);
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
while (fscanf(f,"%s %s %s %s %d %d\n",C.identifiant,C.marque,C.position,C.type,&C.valeur,&C.etat)!=EOF)
{
if(C.valeur>100)
{
fprintf(f1,"%s %s %s %s %d %d\n",C.identifiant,C.marque,C.position,C.type,C.valeur,C.etat);
}
}
}
fclose(f);
fclose(f1);
}
//fonction exist
int capteur_exist(char*id){
FILE*f=NULL;
Capteur C;
f=fopen("capteurs.txt","r");
while(fscanf(f,"%s %s %s %s %d %d\n",C.identifiant,C.marque,C.position,C.type,&C.valeur,&C.etat)!=EOF)
{
if(strcmp(C.identifiant,id)==0){
return 1;
}
fclose(f);
return 0;
}
}




