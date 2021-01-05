typedef struct
{
char id[20];
char nom[20];
char prenom[20];
char tel[13];
char mail[40];
}client;

void ajoutClient(client C); 
void modifClient (char *id,client tempo);
void SuppClient(char *id);
void afficherClient();
void chercherClient (char *id);
