#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"

#include "client.h"
#include "tree.h"
void
on_button2_ajouter_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget  *entrycin, *entrynom, *entryprenom, *entrynumtel, *entryjour, *entrymois, *entryannee, *entrysexe, *CIN, *NOM, *PRENOM, *TEL ,*success , *fail , *p ,*p2 ,*p3; 

client c ;
p=lookup_widget(button,"treeview1");
p3=lookup_widget(button,"treeview2");
//entries
entrycin=lookup_widget(button,"entry3");
entrynom=lookup_widget(button,"entry1");
entryprenom=lookup_widget(button,"entry2");
entrynumtel=lookup_widget(button,"entry4");
entrysexe=lookup_widget(button,"combobox1");
entryjour=lookup_widget(button,"spinbutton1");
entrymois=lookup_widget(button,"spinbutton2");
entryannee=lookup_widget(button,"spinbutton3");


//labels

CIN=lookup_widget(button,"label17");
NOM=lookup_widget(button,"label15");
PRENOM=lookup_widget(button,"label16");
TEL=lookup_widget(button,"label18");
fail=lookup_widget(button,"label12");
success=lookup_widget(button,"label13");

//récuperation des données 

strcpy(c.cin, gtk_entry_get_text(GTK_ENTRY(entrycin)));
strcpy(c.nom, gtk_entry_get_text(GTK_ENTRY(entrynom)));
strcpy(c.prenom, gtk_entry_get_text(GTK_ENTRY(entryprenom)));
strcpy(c.tel, gtk_entry_get_text(GTK_ENTRY(entrynumtel)));
strcpy(c.sexe,gtk_combo_box_get_active_text(GTK_COMBO_BOX(entrysexe)));
c.date.j=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(entryjour));
c.date.m=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(entrymois));
c.date.a=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(entryannee));

//controle de saisie 
if(strcmp(c.cin,"")==0){
gtk_widget_show(CIN);
gtk_widget_set_visible(success,FALSE);

}
else
{
gtk_widget_set_visible(CIN,FALSE);
gtk_widget_set_visible(success,FALSE);

}
if(strcmp(c.nom,"")==0){
gtk_widget_show(NOM);
gtk_widget_set_visible(success,FALSE);

}
else
{
gtk_widget_set_visible(NOM,FALSE);
gtk_widget_set_visible(success,FALSE);

}

if(strcmp(c.prenom,"")==0){
gtk_widget_show(PRENOM);
gtk_widget_set_visible(success,FALSE);

}
else
{
gtk_widget_set_visible(PRENOM,FALSE);
gtk_widget_set_visible(success,FALSE);
}

if(strcmp(c.tel,"")==0){
gtk_widget_show(TEL);
gtk_widget_set_visible(success,FALSE);

}
else
{
gtk_widget_set_visible(TEL,FALSE);
gtk_widget_set_visible(success,FALSE);

}
if(gtk_widget_get_visible(CIN)==FALSE && gtk_widget_get_visible(NOM)==FALSE && gtk_widget_get_visible(PRENOM)==FALSE && gtk_widget_get_visible(TEL)==FALSE){
         if(exist(c.cin)==1){
	gtk_widget_set_visible(success,FALSE);
	gtk_widget_show(fail);
        Afficherclient (p,"client.txt");
        Afficherclient1(p3,"client.txt");
}
       

 else {

	
         ajouter(c);
         //bien ajouté 
	gtk_widget_set_visible(fail,FALSE);
	gtk_widget_show(success);
	//vider les champs après ajout
	gtk_entry_set_text(GTK_ENTRY(entrycin),"");
	gtk_entry_set_text(GTK_ENTRY(entrynom),"");
	gtk_entry_set_text(GTK_ENTRY(entryprenom),"");
        gtk_entry_set_text(GTK_ENTRY(entrynumtel),"");
	gtk_spin_button_set_value(GTK_SPIN_BUTTON(entryjour),1);
	gtk_spin_button_set_value(GTK_SPIN_BUTTON(entrymois),1);
	gtk_spin_button_set_value(GTK_SPIN_BUTTON(entryannee),1950);
        //mise à jour du treeview 
       p2=lookup_widget(button,"treeview1");
	Afficherclient(p2,"client.txt");
        Afficherclient1(p3,"client.txt");
}
}
	
	

	
	
}




void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_button4_supp_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{

GtkTreeSelection *selection;
        GtkTreeModel     *model;
        GtkTreeIter iter;
        GtkWidget* p1  , *p2;
        gchar* cin;

        p1=lookup_widget(button,"treeview1");
        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(p1));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))
        {  gtk_tree_model_get (model,&iter,0,&cin,-1);
           gtk_list_store_remove(GTK_LIST_STORE(model),&iter);//supprimer la ligne du treeView

          supprimer(cin);
          p2=lookup_widget(button,"treeview2");
          Afficherclient1(p2,"client.txt");
        }

}


void
on_button3_modi_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
{
        GtkTreeSelection *selection;
        GtkTreeModel     *model;
        GtkTreeIter iter;
        gchar* cin;
GtkWidget *entrynom, *entryprenom, *entrytel, *entrysexe, *entryjour,*entrymois,*entryannee, *success,  *p , *p2;
client cl;

//les labels
success=lookup_widget(button,"label26");

//entries

entrynom=lookup_widget(button,"entry5");
entryprenom=lookup_widget(button,"entry6");
entrytel=lookup_widget(button,"entry7");
entrysexe=lookup_widget(button,"combobox2");
entryjour=lookup_widget(button,"spinbutton6");
entrymois=lookup_widget(button,"spinbutton5");
entryannee=lookup_widget(button,"spinbutton4");



//Récuperation 
strcpy(cl.nom, gtk_entry_get_text(GTK_ENTRY(entrynom)));


strcpy(cl.prenom, gtk_entry_get_text(GTK_ENTRY(entryprenom)));
strcpy(cl.tel, gtk_entry_get_text(GTK_ENTRY(entrytel)));
strcpy(cl.sexe,gtk_combo_box_get_active_text(GTK_COMBO_BOX(entrysexe)));
cl.date.j=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(entryjour));
cl.date.m=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(entrymois));
cl.date.a=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(entryannee));

         p2=lookup_widget(button,"treeview2");
	p=lookup_widget(button,"treeview1");
        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(p));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))
        {  
		
                gtk_tree_model_get (model,&iter,0,&cin,-1);
                modifier(cl, cin );
		//mise à jour du treeview
		Afficherclient(p,"client.txt");
                Afficherclient1(p2,"client.txt");
		
		//bien modifié
		
		gtk_widget_show(success);
		//vider les champs après modification
		gtk_entry_set_text(GTK_ENTRY(entrynom),"");
		gtk_entry_set_text(GTK_ENTRY(entryprenom),"");
		gtk_entry_set_text(GTK_ENTRY(entrytel),"");
	gtk_spin_button_set_value(GTK_SPIN_BUTTON(entryjour),1);
	gtk_spin_button_set_value(GTK_SPIN_BUTTON(entrymois),1);
	gtk_spin_button_set_value(GTK_SPIN_BUTTON(entryannee),1950);
		
		}
	
}

}


void
on_checkbutton1_validmodif_toggled     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_checkbutton2_validsupp_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_treeview2_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_button5_chercher_clicked            (GtkButton       *button,
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
entry=lookup_widget(button,"entry8");
labelnom=lookup_widget(button,"labelnomii");
p1=lookup_widget(button,"treeview2");
strcpy(nom,gtk_entry_get_text(GTK_ENTRY(entry)));

if(strcmp(nom,"")==0){
  gtk_widget_show (labelnom);b=0;
}else{
b=1;
gtk_widget_hide (labelnom);}

if(b==0){return;}else{

nb=Chercherclient(p1,"client.txt",nom);
/* afficher le nombre de resultats obtenue par la recherche */
sprintf(chnb,"%d",nb);//conversion int==> chaine car la fonction gtk_label_set_text naccepte que chaine
nbResultat=lookup_widget(button,"label34");
message=lookup_widget(button,"label32");
gtk_label_set_text(GTK_LABEL(nbResultat),chnb);

gtk_widget_show (nbResultat);
gtk_widget_show (message);

}
}

void
on_button6_quit_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_gclients_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *p , *p3 , *gclient ,*tdb ;
tdb=lookup_widget(button,"window1");
gclient=create_window1();
p=lookup_widget(gclient,"treeview1");
p3=lookup_widget(gclient,"treeview2");
Afficherclient (p,"client.txt");
 Afficherclient1(p3,"client.txt");
gtk_widget_destroy(tdb);
gtk_widget_show(gclient);
}

