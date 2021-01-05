typedef struct
{
char identifiant [20] ;
char marque [20];
int type; //0: pour température , 1: pour 1'humidité
char position [ 20];
int etat; //1: en marche -1:en panne
}Capteur;


void lire_capteur (Capteur *p_Capteur);
int ajouter_capteur (Capteur C[l, int n); I/ n: la taille
int chercher_capteur (Capteur C[], intn, char id[]); // retourne 1'indice du capteur avec 1'id
void modifier_capteur (Capteur C[], int n, int position);
int supprimer_capteur(Capteur C[], int n, int position);// change la taille
void afficher_capteurs (Capteur C[], int n)
void changer_etat_capteur (Capteur C[], int n, int pos, int etat);



