#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "men.h"
#include <gtk/gtkclist.h>
#include <gdk/gdkkeysyms.h>
///////*****Authentification****/////
void
on_togglebuttonconnexion_clicked (GtkWidget *button, gpointer user_data)
{

GtkWidget *window1;
GtkWidget *window;
GtkWidget *intputlogin;
GtkWidget *intputpass;
GtkWidget *error;

char l[20];
char p[20];
char log[20];
char pass[20];
int x=0;
FILE*f;
window1=lookup_widget(button,"Auth_1");
intputlogin=lookup_widget(button, "entrylogin");
intputpass=lookup_widget(button, "entrypass");
strcpy(l,gtk_entry_get_text(GTK_ENTRY(intputlogin)));
strcpy(p,gtk_entry_get_text(GTK_ENTRY(intputpass)));

f=fopen("/home/saifbenhassine/Projects/project10/src/users.txt","r"); 

if(f!=NULL){
while (fscanf(f,"%s %s \n",log,pass)!=EOF && x==0)
	{
	if (strcmp(l,log)==0 && strcmp(p,pass)==0)
		{
		gtk_widget_hide(window1);
		window=create_Pay_1();
		gtk_widget_show (window);
		x=1;

		}
	}
}

if(x==0)
	{
	error=lookup_widget(button, "label200");	
	gtk_label_set_text(GTK_LABEL(error),"vous n'etes pas inscrit");
	}
fclose(f);

}
//////************inscription*********/////////

void
on_button_Valider_ins_clicked (GtkWidget *objet_graphique, gpointer user_data)
{
	GtkWidget *window2;
	GtkWidget *window;
	window2=lookup_widget(objet_graphique,"criation_1");
	

	char civilite[20];
	char Prenom [20];
	char Nom [20];
	char Email[20];
	char Tel [20];
	char Adresse [100];
	char Code_postal [20];
	char Ville [20];
	char Login [20];
	char mot_de_passe [20];
	char c_mot_de_passe [20];

	GtkWidget *Combobox1=lookup_widget(objet_graphique,"civilite");
	GtkWidget *input_Prenom =lookup_widget(objet_graphique, "entryPrenom");
	GtkWidget *input_Nom =lookup_widget(objet_graphique, "entryNom");
	GtkWidget *input_Email =lookup_widget(objet_graphique, "entryEmail");
	GtkWidget *input_Tel =lookup_widget(objet_graphique, "entryTel");
	GtkWidget *input_Adresse =lookup_widget(objet_graphique, "entryAdresse");
	GtkWidget *input_Code_postal =lookup_widget(objet_graphique, "entrycode_postal");
	GtkWidget *input_Ville =lookup_widget(objet_graphique, "entryville");
	GtkWidget *input_Login =lookup_widget(objet_graphique, "entrylog");
	GtkWidget *input_mot_de_passe =lookup_widget(objet_graphique, "entrymp");
	GtkWidget *input_c_mot_de_passe =lookup_widget(objet_graphique, "entrycmp");


strcpy(civilite,gtk_combo_box_get_active_text(GTK_COMBO_BOX(Combobox1)));
strcpy(Prenom,gtk_entry_get_text(GTK_ENTRY(input_Prenom)));
strcpy(Nom,gtk_entry_get_text(GTK_ENTRY(input_Nom)));
strcpy(Email,gtk_entry_get_text(GTK_ENTRY(input_Email)));
strcpy(Tel,gtk_entry_get_text(GTK_ENTRY(input_Tel)));
strcpy(Adresse,gtk_entry_get_text(GTK_ENTRY(input_Adresse)));
strcpy(Code_postal,gtk_entry_get_text(GTK_ENTRY(input_Code_postal)));
strcpy(Ville,gtk_entry_get_text(GTK_ENTRY(input_Ville)));
strcpy(Login,gtk_entry_get_text(GTK_ENTRY(input_Login)));
strcpy(mot_de_passe,gtk_entry_get_text(GTK_ENTRY(input_mot_de_passe)));
strcpy(c_mot_de_passe,gtk_entry_get_text(GTK_ENTRY(input_c_mot_de_passe)));
//ajouter(Login,Nom);
FILE*f;
f=fopen("comptes.txt","a+");
if (f!=NULL) {

fprintf(f,"%s %s %s %s %s %s %s %s %s %s %s\n",civilite,Prenom,Nom,Email,Tel,Adresse,Code_postal,Ville,Login,mot_de_passe,c_mot_de_passe);
fclose(f);
}
gtk_widget_destroy(window2);
	window=create_Auth_1();
	gtk_widget_show (window);


}

///////////////////***********Button_inscrit******/////


void
on_togglebuttoninscrit_clicked         (GtkWidget       *button,
                                        gpointer         user_data)
{
		GtkWidget *window1;
		GtkWidget *window;

		window1=lookup_widget(button,"Auth_1");
		gtk_widget_destroy(window1);
		window=create_criation_1();
		gtk_widget_show (window);
}

///////////////**************Button_annuler_inscrit****/////
void
on_button_annuler_ins_clicked (GtkWidget *button, gpointer user_data)
{


		GtkWidget *criation_1, *Auth_1;
		criation_1=lookup_widget(button,"criation_1");
		gtk_widget_destroy(criation_1);
		Auth_1=create_Auth_1();
		gtk_widget_show (Auth_1);
}

///////////////**************Button_Paiement****/////
void
on_togglebutton_Payer_clicked (GtkWidget *objet, gpointer user_data)
{
men p;

GtkWidget *Auth_1 =lookup_widget(objet,"Auth_1");
GtkWidget *input1=lookup_widget(objet,"Prenom");
GtkWidget *input2=lookup_widget(objet,"Nom");
GtkWidget *input3=lookup_widget(objet,"Adresse");
GtkWidget *input4=lookup_widget(objet,"Numcarte");
GtkWidget *input5=lookup_widget(objet,"MM");
GtkWidget *input6=lookup_widget(objet,"AAAA");
GtkWidget *input7=lookup_widget(objet,"CVV");

GtkWidget *image22=lookup_widget(objet,"image22");
gtk_image_set_from_file(GTK_IMAGE(image22),"/home/saifbenhassine/Projects/project10/pixmaps/999.png");

strcpy(p.Prenom,gtk_entry_get_text(GTK_ENTRY (input1)));
strcpy(p.Nom,gtk_entry_get_text(GTK_ENTRY (input2)));
strcpy(p.Adresse,gtk_entry_get_text(GTK_ENTRY (input3)));
strcpy(p.Numcarte,gtk_entry_get_text(GTK_ENTRY (input4)));
strcpy(p.mm,gtk_entry_get_text(GTK_ENTRY (input5)));
strcpy(p.aaaa,gtk_entry_get_text(GTK_ENTRY (input6)));
strcpy(p.cvv,gtk_entry_get_text(GTK_ENTRY (input7)));
ajouter_men(p);
}

/////////////************Historique************////////////
void
on_togglebutton_histo_clicked (GtkWidget *objet, gpointer user_data)
{
GtkWidget *Auth_1;
GtkWidget *Historique_1;
GtkWidget *treeview1;

Auth_1=lookup_widget(objet,"Auth_1");
gtk_widget_destroy(Auth_1);

Historique_1=lookup_widget(objet,"Historique_1");
Historique_1=create_Historique_1();
gtk_widget_show(Historique_1);

treeview1=lookup_widget(Historique_1,"treeview1");
afficher_men(treeview1);
}

/////////***********Quitter_Historique_B******////////
void
on_Quitter_histo_clicked   (GtkWidget *objet, gpointer user_data)
{
GtkWidget *Pay_1, *Historique_1;
Historique_1=lookup_widget(objet,"Historique_1");
gtk_widget_destroy(Historique_1);

gtk_widget_show(Pay_1);
}

/////////////***********Quitter_pay_B*********/////////
void
on_Quitter_Pay_clicked   (GtkWidget *objet, gpointer user_data)
{
GtkWidget *Pay_1, *Auth_1;
Pay_1=lookup_widget(objet,"Pay_1");
gtk_widget_destroy(Pay_1);
Auth_1=create_Auth_1();
gtk_widget_show(Auth_1);
}

void
on_ButtonRech_clicked (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
int n,i;
char Numcarte[50][50];
GtkWidget *Combobox13;
Combobox13=lookup_widget(objet_graphique,"combobox13");
n=combo13(Numcarte); 

for(i=0;i<n;i++)
{
gtk_combo_box_append_text(GTK_COMBO_BOX(Combobox13),_(Numcarte[i]));
}
}



void
on_buttonmodif_clicked                 (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
char Numcarte[50];
GtkWidget *Combobox13;
Combobox13 = lookup_widget(objet_graphique,"combobox13");
if(gtk_combo_box_get_active_text(GTK_COMBO_BOX(Combobox13))!= NULL)
	{
	strcpy(Numcarte,gtk_combo_box_get_active_text(GTK_COMBO_BOX(Combobox13)));
	XX(Numcarte);

	GtkWidget *Pay_2 ;
	Pay_2 =create_Pay_2 ();
	gtk_widget_show(Pay_2);

}
}

void
on_buttonsuppay_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
char Numcarte[50];
GtkWidget *Combobox13;
Combobox13 = lookup_widget(objet_graphique,"combobox13");
if(gtk_combo_box_get_active_text(GTK_COMBO_BOX(Combobox13))!= NULL)
	{
	strcpy(Numcarte , gtk_combo_box_get_active_text(GTK_COMBO_BOX(Combobox13)));
	supprimerm(Numcarte);
	//GtkWidget *validation;
	//validation = create_validation ();
	//gtk_widget_show (validation);
	}
}


void
on_refresh_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{

GtkWidget *Historique_1;
Historique_1=lookup_widget(button,"Historique_1");
gtk_widget_hide(Historique_1);
Historique_1 = create_Historique_1 ();
gtk_widget_show (Historique_1);
GtkWidget *treeview1;
treeview1=lookup_widget(Historique_1,"treeview1");
afficher_men(treeview1);

}



void
on_Pay_2_show                          (GtkWidget       *widget,
                                        gpointer         user_data)
{
men p ;
p=YY();
GtkWidget	*input_nom	=	lookup_widget(widget,"entry1");
GtkWidget	*input_prenom	=	lookup_widget(widget,"entry2");
GtkWidget	*input_cin	=	lookup_widget(widget,"entry3");
GtkWidget	*input_gsm	=	lookup_widget(widget,"entry4");
GtkWidget	*input_adresse	=	lookup_widget(widget,"entry5");
GtkWidget	*input_date	=	lookup_widget(widget,"entry6");
GtkWidget	*input_mdp	=	lookup_widget(widget,"entry7");

gtk_entry_set_text (GTK_ENTRY (input_nom), _(p.Prenom));
gtk_entry_set_text (GTK_ENTRY (input_prenom), _(p.Nom));
gtk_entry_set_text (GTK_ENTRY (input_cin), _(p.Adresse));
gtk_entry_set_text (GTK_ENTRY (input_gsm), _(p.Numcarte));
gtk_entry_set_text (GTK_ENTRY (input_adresse), _(p.mm));
gtk_entry_set_text (GTK_ENTRY (input_date), _(p.aaaa));
gtk_entry_set_text (GTK_ENTRY (input_mdp), _(p.cvv));

}


void
on_save_clicked                      (GtkButton       *button,
                                        gpointer         user_data)
{
men p;
int x;
p=YY();
GtkWidget	*input_nom	=	lookup_widget(button,"entry1");
GtkWidget	*input_prenom	=	lookup_widget(button,"entry2");
GtkWidget	*input_cin	=	lookup_widget(button,"entry3");
GtkWidget	*input_gsm	=	lookup_widget(button,"entry4");
GtkWidget	*input_adresse	=	lookup_widget(button,"entry5");
GtkWidget	*input_date	=	lookup_widget(button,"entry6");
GtkWidget	*input_mdp	=	lookup_widget(button,"entry7");


strcpy(p.Prenom,gtk_entry_get_text(GTK_ENTRY(input_nom)));
strcpy(p.Nom,gtk_entry_get_text(GTK_ENTRY(input_prenom)));
strcpy(p.Adresse,gtk_entry_get_text(GTK_ENTRY(input_cin)));
strcpy(p.Numcarte,gtk_entry_get_text(GTK_ENTRY(input_gsm)));
strcpy(p.mm,gtk_entry_get_text(GTK_ENTRY(input_adresse)));
strcpy(p.aaaa,gtk_entry_get_text(GTK_ENTRY(input_date)));
strcpy(p.cvv,gtk_entry_get_text(GTK_ENTRY(input_mdp)));
	ZZ(p);
	remove("tamp.txt");
}

