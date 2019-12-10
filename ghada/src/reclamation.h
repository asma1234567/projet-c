#include <gtk/gtk.h>

typedef struct
{

char Nom[200];
char Prenom[200];
char identifiant[200];
char texte[100];
}Personne;
void ajouter_personne(Personne p);
void afficher_personne(GtkWidget *liste);
int recherche(char Nom_cin[]);
void sup_reclamation(int lno);
void modif(int a,char Nom[20],char Prenom[20],char identifiant[10],char texte[100]);
