/*
 * Initial main.c file generated by Glade. Edit as required.
 * Glade will not overwrite this file.
 */

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "interface.h"
#include "support.h"

int
main (int argc, char *argv[])
{
  GtkWidget *client_fait_une_reclamation;
  GtkWidget *voir_la_reclamation_d_un_client;
  GtkWidget *lise_des_reclamation;
  GtkWidget *liste_reclamation;
  GtkWidget *administrateur_voit_la_reclamation_dun_client;
  GtkWidget *Client_reclamation;
  GtkWidget *treeview1;
#ifdef ENABLE_NLS
  bindtextdomain (GETTEXT_PACKAGE, PACKAGE_LOCALE_DIR);
  bind_textdomain_codeset (GETTEXT_PACKAGE, "UTF-8");
  textdomain (GETTEXT_PACKAGE);
#endif

  gtk_set_locale ();
  gtk_init (&argc, &argv);

  add_pixmap_directory (PACKAGE_DATA_DIR "/" PACKAGE "/pixmaps");

  /*
   * The following code was added by Glade to create one of each component
   * (except popup menus), just so that you see something after building
   * the project. Delete any components that you don't want shown initially.
   */
  Client_reclamation = create_Client_reclamation ();
  gtk_widget_show (Client_reclamation);
  liste_reclamation = create_liste_reclamation ();
  gtk_widget_show (liste_reclamation);
  treeview1=lookup_widget(liste_reclamation,"treeview1");
  //administrateur_voit_la_reclamation_dun_client = create_administrateur_voit_la_reclamation_dun_client ();
  //gtk_widget_show (administrateur_voit_la_reclamation_dun_client);
  gtk_main ();
  return 0;
}

