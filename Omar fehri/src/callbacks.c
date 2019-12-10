#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "reservation.h"
void
on_spinbutton101_changed               (GtkEditable     *editable,
                                        gpointer         user_data)
{
char ch[50];
int nbr,prix,n=0;
char date[50];
char des[50];
char Prix[50];
GtkWidget *Combobox102;
Combobox102=lookup_widget(editable,"combobox102");
strcpy(des,gtk_combo_box_get_active_text(GTK_COMBO_BOX(Combobox102)));
if(gtk_combo_box_get_active_text(GTK_COMBO_BOX(Combobox102))!=NULL)
{
GtkWidget *spin;
spin=lookup_widget(editable,"spinbutton101");
nbr=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (spin));

n=vol_prix(des);
n=n*nbr;
sprintf(ch,"%d",n);
GtkWidget	*input1	=	lookup_widget(editable,"entry102");
gtk_entry_set_text (GTK_ENTRY (input1),_(ch));
}
}

void
on_reserver_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
char des[50],date[50],Prix[50],Nbr1[50];
int nbr,prix,nbr1;
GtkWidget *Combobox101;
Combobox101=lookup_widget(button,"combobox101");
strcpy(des,gtk_combo_box_get_active_text(GTK_COMBO_BOX(Combobox101)));
GtkWidget *Combobox102;
Combobox102=lookup_widget(button,"combobox102");
strcpy(date,gtk_combo_box_get_active_text(GTK_COMBO_BOX(Combobox102)));

GtkWidget *spin;
spin=lookup_widget(button,"spinbutton101");
nbr=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (spin));

GtkWidget	*input1	=	lookup_widget(button,"entry102");
strcpy(Prix,gtk_entry_get_text(GTK_ENTRY(input1)));
prix=atoi(Prix);
GtkWidget	*input	=	lookup_widget(button,"entry101");
strcpy(Nbr1,gtk_entry_get_text(GTK_ENTRY(input)));
nbr1=atoi(Nbr1);
if(nbr<=nbr1)
save(des,date,nbr,prix);
else
	{
	GtkWidget *output=lookup_widget(button,"label106");
	strcat(Nbr1," places sont disponible pas plus");
	gtk_label_set_text(GTK_LABEL(output),Nbr1);
	}
}

void
on_combobox102_changed                 (GtkComboBox     *combobox,
                                        gpointer         user_data)
{
char ch[50];
int i,nbr,n=0;
char date[50];
char des[50];
GtkWidget *spin;
spin=lookup_widget(combobox,"spinbutton101");
nbr=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (spin));
GtkWidget *Combobox102;
Combobox102=lookup_widget(combobox,"combobox102");
strcpy(des,gtk_combo_box_get_active_text(GTK_COMBO_BOX(Combobox102)));
n=place_dispo_vol(des);
n-=place_res_vol(des);
sprintf(ch,"%d",n);
GtkWidget	*input	=	lookup_widget(combobox,"entry101");
gtk_entry_set_text (GTK_ENTRY (input),_(ch));
}


void
on_combobox101_changed                 (GtkComboBox     *combobox,
                                        gpointer         user_data)
{

int i,n;
char tab[50][50];
char des[50];
GtkWidget *Combobox101;
Combobox101=lookup_widget(combobox,"combobox101");
strcpy(des,gtk_combo_box_get_active_text(GTK_COMBO_BOX(Combobox101)));
GtkWidget *Combobox102;
Combobox102=lookup_widget(combobox,"combobox102");
n=vol_diponible(tab,des);
for(i=0;i<n;i++)
{
gtk_combo_box_append_text(GTK_COMBO_BOX(Combobox102),_(tab[i]));
}
}


void
on_spinbutton204_changed               (GtkEditable     *editable,
                                        gpointer         user_data)
{
char ch[50];
int nbr,prix,n=0;
char date[50];
char ref[50];
char Prix[50];
GtkWidget *Combobox202;
Combobox202=lookup_widget(editable,"combobox202");
strcpy(ref,gtk_combo_box_get_active_text(GTK_COMBO_BOX(Combobox202)));
if(gtk_combo_box_get_active_text(GTK_COMBO_BOX(Combobox202))!=NULL)
{
GtkWidget *spin;
spin=lookup_widget(editable,"spinbutton204");
nbr=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (spin));

n=voiture_prix(ref);
n=n*nbr;
sprintf(ch,"%d",n);
GtkWidget	*input1	=	lookup_widget(editable,"entry201");
gtk_entry_set_text (GTK_ENTRY (input1),_(ch));
}
}

void
on_combobox201_changed                 (GtkComboBox     *combobox,
                                        gpointer         user_data)
{
int i,n;
char tab[50][50];
char mark[50];
GtkWidget *Combobox201;
Combobox201=lookup_widget(combobox,"combobox201");
strcpy(mark,gtk_combo_box_get_active_text(GTK_COMBO_BOX(Combobox201)));
GtkWidget *Combobox202;
Combobox202=lookup_widget(combobox,"combobox202");
n=voiture_diponible(tab,mark);
for(i=0;i<n;i++)
{
gtk_combo_box_append_text(GTK_COMBO_BOX(Combobox202),_(tab[i]));
}
}

void
on_button201_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
char mark[50],ref[50],Prix[50],Nbr1[50];
int nbr,prix,nbr1;
date x,y;
GtkWidget *Combobox201;
Combobox201=lookup_widget(button,"combobox201");
strcpy(mark,gtk_combo_box_get_active_text(GTK_COMBO_BOX(Combobox201)));
GtkWidget *Combobox202;
Combobox202=lookup_widget(button,"combobox202");
strcpy(ref,gtk_combo_box_get_active_text(GTK_COMBO_BOX(Combobox202)));

GtkWidget *spin;
spin=lookup_widget(button,"spinbutton204");
nbr=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (spin));

GtkWidget *spin1;
spin1=lookup_widget(button,"spinbutton201");
x.jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (spin1));
GtkWidget *spin2;
spin2=lookup_widget(button,"spinbutton202");
x.mois=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (spin2));
GtkWidget *spin3;
spin3=lookup_widget(button,"spinbutton203");
x.annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (spin3));

GtkWidget	*input	=	lookup_widget(button,"entry201");
strcpy(Nbr1,gtk_entry_get_text(GTK_ENTRY(input)));
nbr1=atoi(Nbr1);
int i=0;
int ns=0;
char ch[50];
y=x;
for(i=0;i<nbr;i++)
	{
	sprintf(ch,"voiture non disponible le %d/%d/%d",x.jour,x.mois,x.annee);
	int n=0;
	int r=0;
	n= verif_d(x,ref);
	if(n==0)
		{
		r= verif_r(x,ref);
		if(r!=0)
			{
			GtkWidget *output=lookup_widget(button,"label209");
			gtk_label_set_text(GTK_LABEL(output),ch);
			ns++;
			}
		}
	else
		{
		GtkWidget *output=lookup_widget(button,"label209");
		gtk_label_set_text(GTK_LABEL(output),ch);
		ns++;
		}
	x=jr_s(x);
	}
if(ns==0)
for(i=0;i<nbr;i++)
	{
	save_voiture(ref,mark,nbr,nbr1,y);
	GtkWidget *output=lookup_widget(button,"label209");
	gtk_label_set_text(GTK_LABEL(output),"reservation terminer");	
	x=jr_s(x);
	}
}



