#include <stdio.h>
#include <string.h>
#include "reclamation.h"
#include <gtk/gtk.h>


enum
{    
          NOM,
          PRENOM,
          IDENTIFIANT,
          TEXTE,
          COLUMNS
};
int MAX=250;
void ajouter_personne(Personne p)
{
   FILE *f;
   f=fopen("reclamation.txt","a+");
if (f!=NULL)
{
 fprintf(f,"%s %s %s %s \n",p.Nom,p.Prenom,p.identifiant,p.texte);
fclose(f);
}
}
//********************************************************************
void afficher_personne(GtkWidget *liste)
{
    GtkCellRenderer *renderer;
    GtkTreeViewColumn *column;
   
    GtkTreeIter  iter;
   
   GtkListStore *store;
 
   char Nom [30] ;
   char Prenom [30] ;
   char identifiant [30] ;
   char texte [100] ;
   store=NULL ;
   FILE *f;
   store=gtk_tree_view_get_model(liste);
  if (store==NULL)
  {
     renderer = gtk_cell_renderer_text_new () ;
     column = gtk_tree_view_column_new_with_attributes("Nom", renderer, "text", NOM,NULL);
     gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column) ;
//*************
renderer = gtk_cell_renderer_text_new () ;
     column = gtk_tree_view_column_new_with_attributes("Prenom", renderer, "text", PRENOM,NULL);
     gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column) ;

 renderer = gtk_cell_renderer_text_new () ;
     column = gtk_tree_view_column_new_with_attributes("identifiant", renderer, "text", IDENTIFIANT,NULL);
     gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column) ;

renderer = gtk_cell_renderer_text_new () ;
     column = gtk_tree_view_column_new_with_attributes("texte", renderer, "text", TEXTE,NULL);
     gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column) ;



//**************
store = gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

//f = fopen("reclamation.txt","r");
f = fopen("reclamation.txt","a+");
while(fscanf(f,"%s %s %s %s\n",Nom,Prenom,identifiant,texte)!=EOF)
{
gtk_list_store_append (store,&iter);

gtk_list_store_set (store,&iter,NOM,Nom,PRENOM,Prenom,IDENTIFIANT,identifiant,TEXTE,texte, -1);
}
 fclose(f);
 gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
 g_object_unref (store);
}
}

//**********************************************************
void sup_reclamation(int lno)
{
int ctr = 0;
      char ch;
      FILE *fptr1, *fptr2;
        char fname[MAX];
    char str[MAX], temp[] =
"temp.txt";
       fptr1 = fopen("reclamation.txt","r");
       fptr2 = fopen("temp.txt","w");
       lno++;
      while (!feof(fptr1))
 { 
       strcpy(str,"\0");
       fgets(str,MAX, fptr1);
       if (!feof(fptr1))
   { 
           ctr++;
          if (ctr != (lno-1))
      {
          fprintf(fptr2, "%s", str);
         }
       } 
      }
      fclose(fptr1);
      fclose(fptr2);
      remove("reclamation.txt");
     rename("temp.txt","reclamation.txt");
}


int recherche(char Nom_cin[])
{
char Nom[20];
char Prenom[20];
char  identifiant[10];
char texte [1000];
int ligne=0;
FILE*f;
f=fopen("reclamation.txt","r"); 
if(f!=NULL) 
	{
		while(fscanf(f,"%s %s %s %s \n",Nom,Prenom,identifiant,texte)!=EOF)
		{ligne++;
			if(strcmp(Nom_cin,identifiant)==0)
			{fclose(f);
			return(ligne);}
			
		}
		fclose(f);
		return(-1);
	}
	return(-1);
}


//*************************

void modif(int a,char Nom[20],char Prenom[20],char identifiant[10],char texte[1000])
{


    FILE *f;
    f=fopen("reclamation.txt", "r");
    int line=0;
    while(fscanf(f,"%s %s %s %s \n",Nom,Prenom,identifiant,texte)!= EOF) {
        line++;
        if(line == a) break;
}
fclose(f);
}
//********************************************************************
void supprimerm(char cin[])
{
        char  NOM[50] ;
        char  PRENOM[50] ;
        char  IDENTIFIANT[50] ;
        char  TEXTE[50] ;
        

FILE *l=fopen("reclamation.txt","r");
FILE *t=fopen("tamp2.txt","a+");
if (l!=NULL)
{
while(fscanf(l,"%s %s %s %s \n",NOM,PRENOM,IDENTIFIANT,TEXTE)!=EOF)
{
if (strcmp(IDENTIFIANT,cin)!=0)
{

fprintf(t,"%s %s %s %s \n",NOM,PRENOM,IDENTIFIANT,TEXTE);
}
}
}
fclose(l);
fclose(t);
remove("reclamation.txt");
rename("tamp2.txt","reclamation.txt");
}























