#include<gtk/gtk.h>
typedef struct 
{int j;
int m;
int a;
}Date;
typedef struct 
{char cin [20] ;
char nom [20] ;
char prenom [20] ;
char tel [20] ;
char sexe [20] ; 
Date date;
}client;
void ajouter(client c) ;
int exist(char*cin) ;
void supprimer(char*cin) ;
void modifier(client cl, char*cin );
