#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "reclamation.h"
#include <string.h>

void
on_button_retour_rec_clicked   (GtkWidget      *objet,      gpointer    user_data)
{
GtkWidget *Client_reclamation ;
Client_reclamation=lookup_widget(objet,"Client_reclamation");
gtk_widget_hide(Client_reclamation);

}





void
on_button_quitter_rec_clicked  (GtkWidget       *objet,          gpointer         user_data)
{
GtkWidget *Client_reclamation ;
Client_reclamation=lookup_widget(objet,"Client_reclamation");
gtk_widget_destroy(Client_reclamation);

}



void
on_tab_enter                           (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *Client_reclamation;
GtkWidget *liste_reclamation;
GtkWidget *treeview1;

//Client_reclamation = lookup_widget(objet,"Client_reclamation");


liste_reclamation=lookup_widget(objet,"liste_reclamation");
gtk_widget_destroy(liste_reclamation);
liste_reclamation = create_liste_reclamation();
gtk_widget_show(liste_reclamation);

treeview1 = lookup_widget(liste_reclamation,"treeview1");
afficher_personne(treeview1);
}


void
on_button_envoyer_rec_clicked          (GtkWidget       *objet,
                                        gpointer         user_data)
{
int i,n ;
Personne p;
GtkWidget *input1;
GtkWidget *input2;
GtkWidget *input3;
GtkWidget *input4;
GtkWidget *input5;
GtkWidget *Client_reclamation;

Client_reclamation=lookup_widget(objet,"Client_reclamation");

input1=lookup_widget(objet,"Nom");
input2=lookup_widget(objet,"Prenom");
input3=lookup_widget(objet,"identifiant");
input4=lookup_widget(objet,"texte");



strcpy(p.Nom,gtk_entry_get_text(GTK_ENTRY (input1)));
strcpy(p.Prenom,gtk_entry_get_text(GTK_ENTRY (input2)));
strcpy(p.identifiant,gtk_entry_get_text(GTK_ENTRY (input3)));
strcpy(p.texte,gtk_entry_get_text(GTK_ENTRY (input4)));
n=strlen(p.texte) ;
for (i=0;i<n;i++)
if (p.texte[i]==' ')
p.texte[i]='_';
ajouter_personne(p);
}


void
on_button_retour_rec_admin_clicked     (GtkWidget      *objet,
                                        gpointer         user_data)
{
 GtkWidget *liste_reclamation ;
GtkWidget *administrateur_voit_la_reclamation_dun_client;
administrateur_voit_la_reclamation_dun_client=lookup_widget(objet,"administrateur_voit_la_reclamation_dun_client");
gtk_widget_destroy(administrateur_voit_la_reclamation_dun_client);
liste_reclamation =create_liste_reclamation();
gtk_widget_show(liste_reclamation);

 }


void
on_button_supp_rec_admin_clicked       (GtkWidget       *objet,
                                        gpointer         user_data)
{
char id[50];
GtkWidget *input;
input = lookup_widget(objet,"entry_id");
GtkWidget *input5	=  lookup_widget(objet,"entry1");
if(gtk_entry_get_text(GTK_ENTRY (input))!= NULL)
{
strcpy(id , gtk_entry_get_text(GTK_ENTRY (input)));
supprimerm(id);
gtk_entry_set_text(GTK_ENTRY(input5)," ");
}
}



void
on_ok_clicked                          (GtkWidget       *objet,
                                        gpointer         user_data)
{
int i,n;
//strcpy(p.Nom,gtk_entry_get_text(GTK_ENTRY (input5)));
char Nom[20];
char Prenom[20];

char  identifiant[10];
char id[10];
char texte [1000];
GtkWidget       *input  =  lookup_widget(objet,"entry_id");
GtkWidget	*input5	=  lookup_widget(objet,"entry1");
strcpy(id,gtk_entry_get_text(GTK_ENTRY(input)));
int a=0;
a=recherche(id);
modif(a,Nom,Prenom,identifiant,texte);
n=strlen(texte) ;
for (i=0;i<n;i++)
if (texte[i]=='_')
texte[i]=' ';
gtk_entry_set_text(GTK_ENTRY(input5),texte);

}





void
on_consulter_clicked                   (GtkWidget      *objet,
                                        gpointer         user_data)
{
GtkWidget *administrateur_voit_la_reclamation_dun_client;
GtkWidget *liste_reclamation;
liste_reclamation=lookup_widget(objet,"liste_reclamation");
gtk_widget_destroy(liste_reclamation);
administrateur_voit_la_reclamation_dun_client = create_administrateur_voit_la_reclamation_dun_client();
gtk_widget_show(administrateur_voit_la_reclamation_dun_client);
}

