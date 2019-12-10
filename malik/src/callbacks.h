#include <gtk/gtk.h>


void
on_togglebuttonconnexion_clicked (GtkWidget *button, gpointer user_data);


void
on_annuler_inscrit_clicked (GtkWidget *button, gpointer user_data);

void
on_button_Valider_ins_clicked (GtkWidget *button, gpointer user_data);


void
on_togglebuttoninscrit_clicked (GtkWidget *objet_graphique, gpointer user_data);

void
on_button_annuler_ins_clicked (GtkWidget *button,  gpointer  user_data);

void
on_togglebutton_Payer_clicked  (GtkWidget *button, gpointer user_data);

void
on_togglebutton_histo_clicked  (GtkWidget *button, gpointer user_data);

void
on_Quitter_histo_clicked   (GtkWidget *button, gpointer user_data);

void
on_Quitter_Pay_clicked    (GtkWidget *button, gpointer user_data);

void
on_ButtonRech_clicked                  (GtkWidget       *button,
                                        gpointer         user_data);



void
on_buttonmodif_clicked                 (GtkWidget       *objet_graphique,
                                        gpointer         user_data);




void
on_buttonsuppay_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_refresh_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_Pay_2_show                          (GtkWidget       *widget,
                                        gpointer         user_data);

void
on_save_clicked                        (GtkButton       *button,
                                        gpointer         user_data);
