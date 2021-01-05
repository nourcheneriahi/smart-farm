#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "fonction.h"
#include "tree.h"

void
on_gestionouvrier_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{


}


void
on_ajouteri_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

GtkWidget  *entrycin, *entrynom, *entryprenom, *entrynumtel, *entrysalaire, *entrysexe, *CIN, *NOM, *PRENOM, *TEL ,*success , *fail , *p ,*p2 ,*p3; 

ouvrier o ;
p=lookup_widget(button,"treeviewi1");
p3=lookup_widget(button,"treeviewi2");
//entries
entrycin=lookup_widget(button,"entrycini");
entrynom=lookup_widget(button,"entrynomi");
entryprenom=lookup_widget(button,"entryprenomi");
entrynumtel=lookup_widget(button,"entryteli");
entrysalaire=lookup_widget(button,"spinbuttonsalaire");
entrysexe=lookup_widget(button,"comboboxsexe");


//labels

CIN=lookup_widget(button,"cini");
NOM=lookup_widget(button,"nomi");
PRENOM=lookup_widget(button,"prenomi");
TEL=lookup_widget(button,"teli");
fail=lookup_widget(button,"labelexiste");
success=lookup_widget(button,"label11");

//récuperation des données 

strcpy(o.cin, gtk_entry_get_text(GTK_ENTRY(entrycin)));
strcpy(o.nom, gtk_entry_get_text(GTK_ENTRY(entrynom)));
strcpy(o.prenom, gtk_entry_get_text(GTK_ENTRY(entryprenom)));
strcpy(o.tel, gtk_entry_get_text(GTK_ENTRY(entrynumtel)));
strcpy(o.sexe,gtk_combo_box_get_active_text(GTK_COMBO_BOX(entrysexe)));
o.salaire=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(entrysalaire));

//controle de saisie 
if(strcmp(o.cin,"")==0){
gtk_widget_show(CIN);
gtk_widget_set_visible(success,FALSE);

}
else
{
gtk_widget_set_visible(CIN,FALSE);
gtk_widget_set_visible(success,FALSE);

}
if(strcmp(o.nom,"")==0){
gtk_widget_show(NOM);
gtk_widget_set_visible(success,FALSE);

}
else
{
gtk_widget_set_visible(NOM,FALSE);
gtk_widget_set_visible(success,FALSE);

}

if(strcmp(o.prenom,"")==0){
gtk_widget_show(PRENOM);
gtk_widget_set_visible(success,FALSE);

}
else
{
gtk_widget_set_visible(PRENOM,FALSE);
gtk_widget_set_visible(success,FALSE);
}

if(strcmp(o.tel,"")==0){
gtk_widget_show(TEL);
gtk_widget_set_visible(success,FALSE);

}
else
{
gtk_widget_set_visible(TEL,FALSE);
gtk_widget_set_visible(success,FALSE);

}
if(gtk_widget_get_visible(CIN)==FALSE && gtk_widget_get_visible(NOM)==FALSE && gtk_widget_get_visible(PRENOM)==FALSE && gtk_widget_get_visible(TEL)==FALSE){
         if(exist(o.cin)==1){
	gtk_widget_set_visible(success,FALSE);
	gtk_widget_show(fail);
        Afficherouvrier (p,"users.txt");
        Afficherouvrier1(p3,"users.txt");
}
       

 else {

	
         ajouter(o);
         //bien ajouté 
	gtk_widget_set_visible(fail,FALSE);
	gtk_widget_show(success);
	//vider les champs après ajout
	gtk_entry_set_text(GTK_ENTRY(entrycin),"");
	gtk_entry_set_text(GTK_ENTRY(entrynom),"");
	gtk_entry_set_text(GTK_ENTRY(entryprenom),"");
        gtk_entry_set_text(GTK_ENTRY(entrynumtel),"");
	gtk_spin_button_set_value(GTK_SPIN_BUTTON(entrysalaire),500);
        //mise à jour du treeview 
       p2=lookup_widget(button,"treeviewi1");
	Afficherouvrier(p2,"users.txt");
        Afficherouvrier1(p3,"users.txt");}
}
	
	

	
	
}


void
on_modifieri_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_treeviewi_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{


}


void
on_supprimeri_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{



}






void
on_modifieri1_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
        GtkTreeSelection *selection;
        GtkTreeModel     *model;
        GtkTreeIter iter;
        gchar* cin;
GtkWidget *entrynom, *entryprenom, *entrytel, *entrysexe, *entrysalaire, *success,  *p , *p2;
ouvrier ov;

//les labels
success=lookup_widget(button,"succesi");

//entries

entrynom=lookup_widget(button,"entrynomi1");
entryprenom=lookup_widget(button,"entryprnomi1");
entrytel=lookup_widget(button,"entryteli1");
entrysalaire=lookup_widget(button,"spinbuttonsalaire2");
entrysexe=lookup_widget(button,"comboboxsexe2");



//Récuperation 
strcpy(ov.nom, gtk_entry_get_text(GTK_ENTRY(entrynom)));


strcpy(ov.prenom, gtk_entry_get_text(GTK_ENTRY(entryprenom)));
strcpy(ov.tel, gtk_entry_get_text(GTK_ENTRY(entrytel)));
ov.salaire=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(entrysalaire));
strcpy(ov.sexe,gtk_combo_box_get_active_text(GTK_COMBO_BOX(entrysexe)));

         p2=lookup_widget(button,"treeviewi2");
	p=lookup_widget(button,"treeviewi1");
        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(p));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))
        {  
		
                gtk_tree_model_get (model,&iter,0,&cin,-1);
                modifier(ov, cin );
		//mise à jour du treeview
		Afficherouvrier(p,"users.txt");
                Afficherouvrier1(p2,"users.txt");
		
		//bien modifié
		
		gtk_widget_show(success);
		//vider les champs après modification
		gtk_entry_set_text(GTK_ENTRY(entrynom),"");
		gtk_entry_set_text(GTK_ENTRY(entryprenom),"");
		gtk_entry_set_text(GTK_ENTRY(entrytel),"");
		gtk_spin_button_set_value(GTK_SPIN_BUTTON(entrysalaire),500);
		
		}
	
}


void
on_quitter_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_supprimeri1_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{

GtkTreeSelection *selection;
        GtkTreeModel     *model;
        GtkTreeIter iter;
        GtkWidget* p1  , *p2;
        gchar* cin;

        p1=lookup_widget(button,"treeviewi1");
        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(p1));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))
        {  gtk_tree_model_get (model,&iter,0,&cin,-1);
           gtk_list_store_remove(GTK_LIST_STORE(model),&iter);//supprimer la ligne du treeView

          supprimer(cin);
          p2=lookup_widget(button,"treeviewi2");
          Afficherouvrier1(p2,"users.txt");
        }

}


void
on_chercheri_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *p1;
GtkWidget *entry;
GtkWidget *labelnom;
GtkWidget *nbResultat;
GtkWidget *message;
char nom[30];
char chnb[30];
int b=0,nb;
entry=lookup_widget(button,"entrynomi2");
labelnom=lookup_widget(button,"labelnomii");
p1=lookup_widget(button,"treeviewi2");
strcpy(nom,gtk_entry_get_text(GTK_ENTRY(entry)));

if(strcmp(nom,"")==0){
  gtk_widget_show (labelnom);b=0;
}else{
b=1;
gtk_widget_hide (labelnom);}

if(b==0){return;}else{

nb=Chercherouvrier(p1,"users.txt",nom);
/* afficher le nombre de resultats obtenue par la recherche */
sprintf(chnb,"%d",nb);//conversion int==> chaine car la fonction gtk_label_set_text naccepte que chaine
nbResultat=lookup_widget(button,"nbi");
message=lookup_widget(button,"messageresi");
gtk_label_set_text(GTK_LABEL(nbResultat),chnb);

gtk_widget_show (nbResultat);
gtk_widget_show (message);

}
}
