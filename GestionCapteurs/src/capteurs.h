#include<gtk/gtk.h>
#ifndef CAPTEURS_H_
#define CAPTEURS_H_
typedef struct
{
char identifiant[20];
char marque[20];
char position[20];
int valeur;
char type[20]; //température ,humidité
int etat; //1: en marche , -1:en panne
}Capteur;
void ajouter_capteur(Capteur C);
void supprimer_capteur(char *id);
void chercher_capteur(char * id);
void modifier_capteur(Capteur tempo,char * id);
void changer_etat_capteur(char *id ,int etat);
void afficher_capteurs();
void capteurs_a_valeurs_alarmantes();
int capteur_exist(char*id);
#endif

