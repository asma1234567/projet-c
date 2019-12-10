#include <stdio.h>
#include <string.h>
#include "men.h"
#include <gtk/gtk.h>

enum
{    
	PRENOM,
	NOM,
	ADRESSE,
	NUMCARTE,
	MM,
	AAAA,
	CVV,
        COLUMNS
};
void ajouter_men(men p)
{
   FILE *f;
   f=fopen("Paiement.txt","a+");
if (f!=NULL)
{
 fprintf(f,"%s %s %s %s %s %s %s\n",p.Prenom,p.Nom,p.Adresse,p.Numcarte,p.mm,p.aaaa,p.cvv);
fclose(f);
}
}
///*******************************************************************
void supprimerm(char Numcarte[])
{
men p;

FILE *l=fopen("/home/saifbenhassine/Projects/project10/src/Paiement.txt","r");
FILE *t=fopen("tamp2.txt","a+");
if (l!=NULL) 
	{ 
	while(fscanf(l,"%s %s %s %s %s %s %s\n",p.Prenom,p.Nom,p.Adresse,p.Numcarte,p.mm,p.aaaa,p.cvv)!=EOF)
		{
		if (strcmp(p.Numcarte,Numcarte)!=0)
			{
			fprintf(t,"%s %s %s %s %s %s %s\n",p.Prenom,p.Nom,p.Adresse,p.Numcarte,p.mm,p.aaaa,p.cvv);
			}
		}
	}
fclose(l);
fclose(t);
remove("/home/saifbenhassine/Projects/project10/src/Paiement.txt");
rename("tamp2.txt","Paiement.txt");
}
//******************************************
men XX(char Numcarte[])
{
//remove("tamp.txt");
men p ;
FILE* f=fopen ("Paiement.txt" , "r");
if (f!=NULL) 
	{ 
	while (fscanf(f,"%s %s %s %s %s %s %s\n",p.Prenom,p.Nom,p.Adresse,p.Numcarte,p.mm,p.aaaa,p.cvv)!=EOF)
		{ 
		if (strcmp(Numcarte,p.Numcarte)==0)
			{
			FILE *t=fopen("tamp.txt","a+");
			fprintf(t,"%s %s %s %s %s %s %s %s\n",p.Prenom,p.Nom,p.Adresse,p.Numcarte,p.mm,p.aaaa,p.cvv);
			fclose(t);		
			}
		}
	}
fclose(f);
return p;
}
//********************************************
men YY()
{
men p ;
FILE* f=fopen ("tamp.txt" , "r");
if (f!=NULL) 
	{ 
	while (fscanf(f,"%s %s %s %s %s %s %s\n",p.Prenom,p.Nom,p.Adresse,p.Numcarte,p.mm,p.aaaa,p.cvv)!=EOF)
		{ 
		fclose(f);
		return p;
		}
	}
}
//***********************************************
void ZZ(men p)
{
	char Prenom[50];
	char Nom[50];
	char Adresse[50];
	char Numcarte[50];
	char mm[50];
	char aaaa[50];
	char cvv[50];
	

FILE *l=fopen("Paiement.txt","r");
FILE *t=fopen("tamp1.txt","a+");
if (l!=NULL) 
	{ 
	while(fscanf(l,"%s %s %s %s %s %s %s\n",Prenom,Nom,Adresse,Numcarte,mm,aaaa,cvv)!=EOF)
		{
		if (strcmp(Numcarte,p.Numcarte)!=0)
		fprintf(t,"%s %s %s %s %s %s %s\n",Prenom,Nom,Adresse,Numcarte,mm,aaaa,cvv);
		else 
		fprintf(t,"%s %s %s %s %s %s %s\n",p.Prenom,p.Nom,p.Adresse,p.Numcarte,p.mm,p.aaaa,p.cvv);
		}
	}
fclose(l);
fclose(t);
remove("Paiement.txt");
rename("tamp1.txt","Paiement.txt");
}


/***********************//////////////////////

int combo13(char cins[][50])
{
int nS=0;
men p;
FILE* f=fopen ("Paiement.txt" , "r");
      
if (f!=NULL) 
	{ 
	while (fscanf(f,"%s %s %s %s %s %s %s\n",p.Prenom,p.Nom,p.Adresse,p.Numcarte,p.mm,p.aaaa,p.cvv)!=EOF)
		
			{
			strcpy (cins[nS],p.Numcarte);
			nS++;
			}
			
	}
fclose(f);
return nS;
}
//********************************************************************
void afficher_men(GtkWidget *liste)
{
    GtkCellRenderer *renderer;
    GtkTreeViewColumn *column;
   
    GtkTreeIter  iter;
   
   GtkListStore *store;
 
   char Prenom [30] ;
   char Nom [30] ;
   char Adresse [30] ;
   char Numcarte [30] ;
   char mm[30] ;
   char aaaa [30] ;
   char cvv [30] ;
   store=NULL ;
   FILE *f;
   store=gtk_tree_view_get_model(liste);
  if (store==NULL)
  {
     renderer = gtk_cell_renderer_text_new () ;
     column = gtk_tree_view_column_new_with_attributes("Prenom", renderer, "text", PRENOM,NULL);
     gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column) ;
//*************
renderer = gtk_cell_renderer_text_new () ;
     column = gtk_tree_view_column_new_with_attributes("Nom", renderer, "text", NOM,NULL);
     gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column) ;

 renderer = gtk_cell_renderer_text_new () ;
     column = gtk_tree_view_column_new_with_attributes("Adresse", renderer, "text", ADRESSE,NULL);
     gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column) ;

renderer = gtk_cell_renderer_text_new () ;
     column = gtk_tree_view_column_new_with_attributes("Numcarte", renderer, "text", NUMCARTE,NULL);
     gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column) ;

renderer = gtk_cell_renderer_text_new () ;
     column = gtk_tree_view_column_new_with_attributes("mm", renderer, "text", MM,NULL);
     gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column) ;

renderer = gtk_cell_renderer_text_new () ;
     column = gtk_tree_view_column_new_with_attributes("aaaa", renderer, "text", AAAA,NULL);
     gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column) ;

renderer = gtk_cell_renderer_text_new () ;
     column = gtk_tree_view_column_new_with_attributes("cvv", renderer, "text", CVV,NULL);
     gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column) ;

//**************
store = gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

f = fopen("Paiement.txt","r");
if(f==NULL){
return;
}
else
{
f = fopen("Paiement.txt","a+");
while(fscanf(f,"%s %s %s %s %s %s %s\n",Prenom,Nom,Adresse,Numcarte,mm,aaaa,cvv)!=EOF)
{
gtk_list_store_append (store,&iter);

gtk_list_store_set (store,&iter,PRENOM,Prenom,NOM,Nom,ADRESSE,Adresse,NUMCARTE,Numcarte,MM,mm,AAAA,aaaa,CVV,cvv, -1);
}
 fclose(f);
 gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
 g_object_unref (store);
}
}
}
