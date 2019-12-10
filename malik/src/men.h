#include <gtk/gtk.h>

typedef struct
{

char Prenom[20];
char Nom[20];
char Adresse[30];
char Numcarte[30];
char mm[10];
char aaaa[10];
char cvv[10];
}men;
void ajouter_men(men p);
void afficher_men(GtkWidget *liste);
int combo13(char cins[][50]);


men XX(char cin1[]);
men YY();
void ZZ(men p);

void supprimerm(char cin[]);
