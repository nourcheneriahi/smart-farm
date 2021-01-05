#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "client.h"
void ajouter(client c)
{
FILE *f=NULL;

f=fopen("client.txt","a+");

if (f!=NULL)
{
fprintf(f,"%s %s %s %s %s %d %d  %d\n",c.cin,c.nom,c.prenom,c.tel,c.sexe,c.date.j,c.date.m,c.date.a);
fclose(f);
}


else 
{printf("\n Erreur : Non trouvé");}

}
//*********************************//
void supprimer(char*cin) {
FILE*f=NULL;
FILE*f1=NULL;
client c ;
f=fopen("client.txt","r");
f1=fopen("ancien.txt","w+");

while(fscanf(f,"%s %s %s %s %s %d %d %d\n",c.cin,c.nom,c.prenom,c.tel,c.sexe,&c.date.j,&c.date.m,&c.date.a)!=EOF){
if(strcmp(cin,c.cin)!=0) 
fprintf(f1,"%s %s %s %s %s %d %d %d\n",c.cin,c.nom,c.prenom,c.tel,c.sexe,c.date.j,c.date.m,c.date.a);
}
fclose(f);
fclose(f1);
remove("client.txt");
rename("ancien.txt","client.txt");
}
//*********************************//
void modifier(client cl, char*cin ){

FILE*f=fopen("client.txt","r");
FILE*f1=fopen("ancienscap.txt","w+");
client c;
while(fscanf(f,"%s %s %s %s %s %d %d %d\n",c.cin,c.nom,c.prenom,c.tel,c.sexe,&c.date.j,&c.date.m,&c.date.a)!=EOF)
{
if(strcmp(c.cin,cin)==0)
{
fprintf(f1,"%s %s %s %s %s %d %d %d\n",cin,cl.nom,cl.prenom,cl.tel,c.sexe,cl.date.j,cl.date.m,cl.date.a);
}
else{
fprintf(f1,"%s %s %s %s %s %d %d %d\n",c.cin,c.nom,c.prenom,c.tel,c.sexe,c.date.j,c.date.m,c.date.a);
}
}
fclose(f);
fclose(f1);
remove("client.txt");
rename("ancienscap.txt","client.txt");
}

//******************************//
int exist(char*cin){
FILE*f=NULL;
client c;
f=fopen("client.txt","r");
while(fscanf(f,"%s %s %s %s %s %d %d %d\n",c.cin,c.nom,c.prenom,c.tel,c.sexe,&c.date.j,&c.date.m,&c.date.a)!=EOF)
{
	if(strcmp(c.cin,cin)==0)
	return 1;
}
fclose(f);
return 0;
}





