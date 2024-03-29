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
  GtkWidget *Pay_1;
  GtkWidget *home_pay_his_1;
  GtkWidget *Historique_1;
  GtkWidget *Auth_1;
  GtkWidget *criation_1;

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
  //Pay_1 = create_Pay_1 ();
  //gtk_widget_show (Pay_1);
  //home_pay_his_1 = create_home_pay_his_1 ();
  //gtk_widget_show (home_pay_his_1);
  //Historique_1 = create_Historique_1 ();
  //gtk_widget_show (Historique_1);
  Auth_1 = create_Auth_1 ();
  gtk_widget_show (Auth_1);
  //cr__ation_1 = create_cr__ation_1 ();
  //gtk_widget_show (cr__ation_1);

  gtk_main ();
  return 0;
}

