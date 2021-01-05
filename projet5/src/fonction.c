#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonction.h"
 


void ajouter(ouvrier o)
{
FILE *f=NULL;

f=fopen("users.txt","a+");

if (f!=NULL)
{
fprintf(f,"%s %s %s %s %s %d\n",o.cin,o.nom,o.prenom,o.tel,o.sexe,o.salaire);
fclose(f);
}


else 
{printf("\n Erreur : Non trouvé");}

}





//fonction supprimer 
void supprimer(char*cin){
FILE*f=NULL;
FILE*f1=NULL;
ouvrier o ;
f=fopen("users.txt","r");
f1=fopen("ancien.txt","w+");

while(fscanf(f,"%s %s %s %s %s %d\n",o.cin ,o.nom ,o.prenom ,o.tel ,o.sexe ,&o.salaire)!=EOF){
if(strcmp(cin,o.cin)!=0) 
fprintf(f1,"%s %s %s %s %s %d\n",o.cin ,o.nom ,o.prenom ,o.tel ,o.sexe ,o.salaire);
}
fclose(f);
fclose(f1);
remove("users.txt");
rename("ancien.txt","users.txt");
}




//fonction modifier

void modifier(ouvrier ov, char*cin ){
FILE*f=fopen("users.txt","r");
FILE*f1=fopen("ancienscap.txt","w+");
ouvrier o;
while(fscanf(f,"%s %s %s %s %s %d\n",o.cin ,o.nom ,o.prenom ,o.tel ,o.sexe ,&o.salaire)!=EOF)
{
if(strcmp(o.cin,cin)==0)
{
fprintf(f1,"%s %s %s %s %s %d\n",cin,ov.nom,ov.prenom,ov.tel,ov.sexe,ov.salaire);
}
else{
fprintf(f1,"%s %s %s %s %s %d\n",o.cin ,o.nom ,o.prenom ,o.tel ,o.sexe ,o.salaire);
}
}
fclose(f);
fclose(f1);
remove("users.txt");
rename("ancienscap.txt","users.txt");
}


int exist(char*cin){
FILE*f=NULL;
ouvrier o;
f=fopen("users.txt","r");
while(fscanf(f,"%s %s %s %s %s %d\n",o.cin,o.nom,o.prenom,o.tel,o.sexe,&o.salaire)!=EOF)
{
	if(strcmp(o.cin,cin)==0)
	return 1;
}
fclose(f);
return 0;
}



