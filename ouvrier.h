typedef struct {
char nom [20] ;
char prenom [20] ; 
int cin ; 
int telephone ;
char identifiant ; 
} ouvrier ; 

int lire_fichier (char filename[],ouvrier o []);
void ajoutouvrier(ouvrier o[]  );
void supprimeouvrier (ouvrier o[], char identifiant []);
void afficheouvrier (ouvrier o[] ); 
void taut_asenteisme (ouvrier o [] );
void modifierouvrier (ouvrier o [] ,char identifiant []);
void meilleur_ouvrier (ouvrier o[] );
