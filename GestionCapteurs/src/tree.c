#include <stdlib.h>
#include <stdio.h>
#include<string.h>
#include <gtk/gtk.h>
#include "interface.h"
#include "tree.h"
#include "capteurs.h" 
GtkListStore *adstore;//creation du modele de type liste
GtkTreeViewColumn *adcolumn;//visualisation des colonnes
GtkCellRenderer *cellad; //afficheur de cellule(text,image..)
FILE *f=NULL;
int i,j,k,m;
void Capteurtree(GtkWidget* treeview1,char*l)
{

Capteur C;
	
        // Creation du modele 
        adstore = gtk_list_store_new(6,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
				     G_TYPE_STRING,
                                     G_TYPE_INT,
                                     G_TYPE_INT);
        //Insertion des élements 
        f=fopen(l,"r");
while(fscanf(f,"%s %s %s %s %d %d\n",C.identifiant,C.marque,C.position,C.type,&C.valeur,&C.etat)!=EOF)
        {GtkTreeIter pIter;

         //Creation de la nouvelle ligne
         gtk_list_store_append(adstore, &pIter);
         // Mise a jour des données
         gtk_list_store_set(adstore, &pIter,
                            0,C.identifiant,
                            1,C.marque,
                            2,C.position,
                            3,C.type,
                            4,C.valeur,
                            5,C.etat,
                            -1);}
        fclose(f);

	//Creation de la 1ère colonne 
if(i==0)
	{
	cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("identifiant",
                                                            cellad,
                                                            "text", 0,
                                                            NULL);


        //Ajouter la 1ère colonne à la vue
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);


	//Creation de la 2ème colonne 
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("marque",
                                                            cellad,
                                                            "text", 1,
                                                            NULL);
	//Ajouter la 2ème colonne à la vue 
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	//Creation de la 3ème colonne 
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("position",
                                                            cellad,
                                                            "text", 2,
                                                            NULL);
	//Ajouter la 3ème colonne à la vue 
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	//Creation de la 4ème colonne 
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("type",
                                                            cellad,
                                                            "text", 3,
                                                            NULL);
	//Ajouter la 4ème colonne à la vue 
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	//Creation de la 5ème colonne
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("valeur",
                                                            cellad,
                                                            "text", 4,
                                                            NULL);
	//Ajouter la 5ème colonne à la vue
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	//Creation de la 6ème colonne
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("etat",
                                                            cellad,
                                                            "text", 5,
                                                            NULL);
	//Ajouter la 6ème colonne à la vue 
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	i++;}


 	gtk_tree_view_set_model ( GTK_TREE_VIEW (treeview1),
                                  GTK_TREE_MODEL(adstore)  );

}

void Alarmantetree(GtkWidget* TreeViewAffichageAlarmante,char*l)
{

Capteur C;
	

        // Creation du modele 
        adstore = gtk_list_store_new(6,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
				     G_TYPE_STRING,
                                     G_TYPE_INT,
                                     G_TYPE_INT);
        //Insertion des élements 
        f=fopen(l,"r");
while(fscanf(f,"%s %s %s %s %d %d\n",C.identifiant,C.marque,C.position,C.type,&C.valeur,&C.etat)!=EOF)
        {GtkTreeIter pIter;

         //Creation de la nouvelle ligne
         gtk_list_store_append(adstore, &pIter);
         // Mise a jour des données
         gtk_list_store_set(adstore, &pIter,
                            0,C.identifiant,
                            1,C.marque,
                            2,C.position,
                            3,C.type,
                            4,C.valeur,
                            5,C.etat,
                            -1);}
        fclose(f);

	
if(k==0)
	{
	//Creation de la 1ère colonne
	cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("identifiant",
                                                            cellad,
                                                            "text", 0,
                                                            NULL);
        //Ajouter la 1ère colonne à la vue
	gtk_tree_view_append_column(GTK_TREE_VIEW(TreeViewAffichageAlarmante), adcolumn);
	//Creation de la 3ème colonne 
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("marque",
                                                            cellad,
                                                            "text", 1,
                                                            NULL);
	//Ajouter la 3ème colonne à la vue 
	gtk_tree_view_append_column(GTK_TREE_VIEW(TreeViewAffichageAlarmante), adcolumn);
	
	//Creation de la 2ème colonne 
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("position",
                                                            cellad,
                                                            "text", 2,
                                                            NULL);
	//Ajouter la 2ème colonne à la vue 
	gtk_tree_view_append_column(GTK_TREE_VIEW(TreeViewAffichageAlarmante), adcolumn);

	//Creation de la 4ème colonne 
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("type",
                                                            cellad,
                                                            "text", 3,
                                                            NULL);
	//Ajouter la 4ème colonne à la vue 
	gtk_tree_view_append_column(GTK_TREE_VIEW(TreeViewAffichageAlarmante), adcolumn);

	//Creation de la 5ème colonne
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("valeur",
                                                            cellad,
                                                            "text", 4,
                                                            NULL);
	//Ajouter la 5ème colonne à la vue
	gtk_tree_view_append_column(GTK_TREE_VIEW(TreeViewAffichageAlarmante), adcolumn);

	//Creation de la 6ème colonne
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("etat",
                                                            cellad,
                                                            "text", 5,
                                                            NULL);
	//Ajouter la 6ème colonne à la vue 
	gtk_tree_view_append_column(GTK_TREE_VIEW(TreeViewAffichageAlarmante), adcolumn);
	k++; }
 	gtk_tree_view_set_model ( GTK_TREE_VIEW (TreeViewAffichageAlarmante),
                                  GTK_TREE_MODEL(adstore)  );
	
}


void ChercherCapteur(GtkWidget* treeview2,char*l)
{
Capteur C;
	
        // Creation du modele 
        adstore = gtk_list_store_new(6,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
				     G_TYPE_STRING,
                                     G_TYPE_INT,
                                     G_TYPE_INT);
        //Insertion des élements 
        f=fopen(l,"r");
while(fscanf(f,"%s %s %s %s %d %d\n",C.identifiant,C.marque,C.position,C.type,&C.valeur,&C.etat)!=EOF)
        {GtkTreeIter pIter;

         //Creation de la nouvelle ligne
         gtk_list_store_append(adstore, &pIter);
         // Mise a jour des données
         gtk_list_store_set(adstore, &pIter,
                            0,C.identifiant,
                            1,C.marque,
                            2,C.position,
                            3,C.type,
                            4,C.valeur,
                            5,C.etat,
                            -1);}
        fclose(f);

	//Creation de la 1ère colonne 
if(j==0)
	{
	cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("identifiant",
                                                            cellad,
                                                            "text", 0,
                                                            NULL);


        //Ajouter la 1ère colonne à la vue
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview2), adcolumn);


	//Creation de la 2ème colonne 
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("marque",
                                                            cellad,
                                                            "text", 1,
                                                            NULL);
	//Ajouter la 2ème colonne à la vue 
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview2), adcolumn);

	//Creation de la 3ème colonne 
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("position",
                                                            cellad,
                                                            "text", 2,
                                                            NULL);
	//Ajouter la 3ème colonne à la vue 
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview2), adcolumn);

	//Creation de la 4ème colonne 
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("type",
                                                            cellad,
                                                            "text", 3,
                                                            NULL);
	//Ajouter la 4ème colonne à la vue 
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview2), adcolumn);

	//Creation de la 5ème colonne
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("valeur",
                                                            cellad,
                                                            "text", 4,
                                                            NULL);
	//Ajouter la 5ème colonne à la vue
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview2), adcolumn);

	//Creation de la 6ème colonne
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("etat",
                                                            cellad,
                                                            "text", 5,
                                                            NULL);
	//Ajouter la 6ème colonne à la vue 
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview2), adcolumn);

	j++;}


 	gtk_tree_view_set_model ( GTK_TREE_VIEW (treeview2),
                                  GTK_TREE_MODEL(adstore)); 
}

void Defectueuxtree(GtkWidget* treeview3,char*l)
{
Capteur C;
	
        // Creation du modele 
        adstore = gtk_list_store_new(6,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
				     G_TYPE_STRING,
                                     G_TYPE_INT,
                                     G_TYPE_INT);
        //Insertion des élements 
        f=fopen(l,"r");
while(fscanf(f,"%s %s %s %s %d %d\n",C.identifiant,C.marque,C.position,C.type,&C.valeur,&C.etat)!=EOF)
        {GtkTreeIter pIter;

         //Creation de la nouvelle ligne
         gtk_list_store_append(adstore, &pIter);
         // Mise a jour des données
         gtk_list_store_set(adstore, &pIter,
                            0,C.identifiant,
                            1,C.marque,
                            2,C.position,
                            3,C.type,
                            4,C.valeur,
                            5,C.etat,
                            -1);}
        fclose(f);

	//Creation de la 1ère colonne 
if(m==0)
	{
	cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("identifiant",
                                                            cellad,
                                                            "text", 0,
                                                            NULL);


        //Ajouter la 1ère colonne à la vue
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview3), adcolumn);


	//Creation de la 2ème colonne 
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("marque",
                                                            cellad,
                                                            "text", 1,
                                                            NULL);
	//Ajouter la 2ème colonne à la vue 
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview3), adcolumn);

	//Creation de la 3ème colonne 
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("position",
                                                            cellad,
                                                            "text", 2,
                                                            NULL);
	//Ajouter la 3ème colonne à la vue 
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview3), adcolumn);

	//Creation de la 4ème colonne 
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("type",
                                                            cellad,
                                                            "text", 3,
                                                            NULL);
	//Ajouter la 4ème colonne à la vue 
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview3), adcolumn);

	//Creation de la 5ème colonne
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("valeur",
                                                            cellad,
                                                            "text", 4,
                                                            NULL);
	//Ajouter la 5ème colonne à la vue
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview3), adcolumn);

	//Creation de la 6ème colonne
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("etat",
                                                            cellad,
                                                            "text", 5,
                                                            NULL);
	//Ajouter la 6ème colonne à la vue 
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview3), adcolumn);

	m++;}


 	gtk_tree_view_set_model ( GTK_TREE_VIEW (treeview3),
                                  GTK_TREE_MODEL(adstore)); 
}

