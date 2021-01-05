#include<gtk/gtk.h>
#ifndef OUVRIERS_H_
#define OUVRIERS_H_
typedef struct 
{char cin [20] ;
char nom [20] ;
char prenom [20] ;
char tel [20] ;
char sexe [20] ; 
int salaire ;
}ouvrier;

void ajouter(ouvrier o) ;
int exist(char*cin) ;
void supprimer(char*cin) ;
void modifier(ouvrier ov, char*cin );
#endif
