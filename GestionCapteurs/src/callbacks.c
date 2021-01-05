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
#include "tree.h"
#include "capteurs.h"


void
on_ButtonGestiondescapteurs_clicked    (GtkWidget *windowcap,
                                        gpointer         user_data)
{
GtkWidget *p, *p1, *p2, *p3;
GtkWidget *windowdash, *windowcapteur;

windowcapteur= create_WindowGestiondescapteurs();


p=lookup_widget(windowcapteur,"treeview1");
p1=lookup_widget(windowcapteur,"TreeViewAffichageAlarmante");
p2=lookup_widget(windowcapteur,"treeview2");
p3=lookup_widget(windowcapteur,"treeview3");

Capteurtree(p,"capteurs.txt");
Alarmantetree(p1,"alarmantes.txt");
ChercherCapteur(p2,"capteurs.txt");
Defectueuxtree(p3,"defectueux.txt");


windowdash=lookup_widget(windowcap,"WindowDashboard");

gtk_widget_destroy(windowdash);
gtk_widget_show(windowcapteur);


}


void
on_ButtonGestiondesouvriers_clicked    (GtkWidget *windowcap,
                                        gpointer         user_data)
{

}


void
on_ButtonGestiondes__quipements_clicked
                                        (GtkWidget *windowcap,
                                        gpointer         user_data)
{

}


void
on_ButtonGestiondesclients_clicked     (GtkWidget *windowcap,
                                        gpointer         user_data)
{

}


void
on_ButtonGestiondestroupeaux_clicked   (GtkWidget *windowcap,
                                        gpointer         user_data)
{

}


void
on_ButtonGestionducalendrier_clicked   (GtkWidget *windowcap,
                                        gpointer         user_data)
{

}


void
on_ButtonQuit_clicked                  (GtkWidget *windowcap,
                                        gpointer         user_data)
{
GtkWidget *p, *p1, *p2, *p3;
GtkWidget *windowdash, *windowcapteur;
windowcapteur=lookup_widget(windowcap,"WindowGestiondescapteurs");
windowdash= create_WindowDashboard();
p=lookup_widget(windowcapteur,"treeview1");
Capteurtree(p,"capteurs.txt");
p1=lookup_widget(windowcapteur,"TreeViewAffichageAlarmante");
Alarmantetree(p1,"alarmantes.txt");
p2=lookup_widget(windowcapteur,"treeview2");
ChercherCapteur(p2,"capteurs.txt");
p3=lookup_widget(windowcapteur,"treeview3");
Defectueuxtree(p3,"defectueux.txt");
gtk_widget_destroy(windowcapteur);
gtk_widget_show(windowdash);
}


void
on_ButtonAjouter_clicked               (GtkWidget *windowcap,
                                        gpointer         user_data)
{
GtkWidget *id, *mar, *pos, *entryid, *entrymar, *entrypos, *entryty, *entryetat, *entryval, *fail, *success, *verif, *p, *p1, *p2, *p3;
Capteur C;

//les labels
id=lookup_widget(windowcap,"labelid");
mar=lookup_widget(windowcap,"labelma");
pos=lookup_widget(windowcap,"labelpos");
success=lookup_widget(windowcap,"labelsucess");
fail=lookup_widget(windowcap,"labelfail");
verif=lookup_widget(windowcap,"labelverif");

//entries
entryid=lookup_widget(windowcap,"EntryIdentifiant");
entrymar=lookup_widget(windowcap,"EntryMarque");
entrypos=lookup_widget(windowcap,"EntryPosition");
entryetat=lookup_widget(windowcap,"spinbuttonetat");
entryval=lookup_widget(windowcap,"spinbuttonvaleur");
entryty=lookup_widget(windowcap,"ComboBoxEntryType");

//Récuperation de l'identifiant & controle de saisie
strcpy(C.identifiant, gtk_entry_get_text(GTK_ENTRY(entryid)));
if(strcmp(C.identifiant,"")==0){
gtk_widget_show(id);
gtk_widget_show(verif);
}
else
{
gtk_widget_set_visible(id,FALSE);
gtk_widget_set_visible(verif,FALSE);
}

//Récuperation de la marque & controle de saisie
strcpy(C.marque, gtk_entry_get_text(GTK_ENTRY(entrymar)));
if(strcmp(C.marque,"")==0){
gtk_widget_show(mar);
gtk_widget_show(verif);
}
else
{
gtk_widget_set_visible(mar,FALSE);
gtk_widget_set_visible(verif,FALSE);
}
//Récuperation de la position & controle de saisie
strcpy(C.position, gtk_entry_get_text(GTK_ENTRY(entrypos)));
if(strcmp(C.position,"")==0){
gtk_widget_show(pos);
gtk_widget_show(verif);
}
else
{
gtk_widget_set_visible(pos,FALSE);
gtk_widget_set_visible(verif,FALSE);
}
//Récuperation du type 
strcpy(C.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(entryty)));
//Récuperation de la valeur
C.valeur=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(entryval));

//Récuperation de l'état
C.etat=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(entryetat));



if(gtk_widget_get_visible(id)==FALSE && gtk_widget_get_visible(mar)==FALSE && gtk_widget_get_visible(pos)==FALSE && gtk_widget_get_visible(verif)==FALSE){
if(capteur_exist(C.identifiant)==1){
gtk_widget_set_visible(success,FALSE);
gtk_widget_show(fail);
}else{
ajouter_capteur(C);
//mise à jour du treeview
p=lookup_widget(windowcap,"treeview1");
Capteurtree(p,"capteurs.txt");
p1=lookup_widget(windowcap,"TreeViewAffichageAlarmante");
Alarmantetree(p1,"alarmantes.txt");
p2=lookup_widget(windowcap,"treeview2");
ChercherCapteur(p2,"capteurs.txt");
p3=lookup_widget(windowcap,"treeview3");
Defectueuxtree(p3,"defectueux.txt");
//bien ajouté 
gtk_widget_set_visible(fail,FALSE);
gtk_widget_show(success);
//vider les champs après ajout
gtk_entry_set_text(GTK_ENTRY(entryid),"");
gtk_entry_set_text(GTK_ENTRY(entrymar),"");
gtk_entry_set_text(GTK_ENTRY(entrypos),"");
gtk_spin_button_set_value(GTK_SPIN_BUTTON(entryetat),1);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(entryval),0);
}
}
}


void
on_ButtonSupprimer_clicked             (GtkWidget *windowcap,
                                        gpointer         user_data)
{
	GtkTreeSelection *selection;
        GtkTreeModel     *model;
        GtkTreeIter iter;
        GtkWidget* p,*p1, *p2, *p3;
        GtkWidget *suc, *echec;
        gchar* id;
        suc=lookup_widget(windowcap,"labelsucess1");
	echec=lookup_widget(windowcap,"labelfail1");
        p=lookup_widget(windowcap,"treeview1");
	gtk_widget_set_visible(suc,FALSE);
        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(p));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))
        {  
		gtk_widget_set_visible(echec,FALSE);
		gtk_tree_model_get (model,&iter,0,&id,-1);
		gtk_list_store_remove(GTK_LIST_STORE(model),&iter);//supprimer la ligne du treeView

		supprimer_capteur(id);// supprimer la ligne du fichier

           	gtk_widget_show(suc);
		p1=lookup_widget(windowcap,"TreeViewAffichageAlarmante");
		Alarmantetree(p1,"alarmantes.txt");
		p2=lookup_widget(windowcap,"treeview2");
		ChercherCapteur(p2,"capteurs.txt");
		p3=lookup_widget(windowcap,"treeview3");
		Defectueuxtree(p3,"defectueux.txt");}
	else
	{
		gtk_widget_show(echec);		
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
on_ButtonModifier_clicked              (GtkWidget *windowcap,
                                        gpointer         user_data)
{
        GtkTreeSelection *selection;
        GtkTreeModel     *model;
        GtkTreeIter iter;
        gchar* id;
GtkWidget *entryid, *entrymar, *entrypos, *ty, *entryetat, *entryval, *fail, *success, *select, *verif1, *p, *p1, *p2, *p3;
Capteur C;

//les labels
success=lookup_widget(windowcap,"labelsuccess2");
fail=lookup_widget(windowcap,"labelfail2");
select=lookup_widget(windowcap,"labelselection");
verif1=lookup_widget(windowcap,"labelverif1");
//entries
entryid=lookup_widget(windowcap,"EntryId1");
entrymar=lookup_widget(windowcap,"EntryMa1");
entrypos=lookup_widget(windowcap,"EntryPos1");
entryetat=lookup_widget(windowcap,"spinbuttoneta");
entryval=lookup_widget(windowcap,"spinbuttonval");
ty=lookup_widget(windowcap,"ComboBoxEntryt1");

//Récuperation de l'identifiant & controle de saisie
strcpy(C.identifiant, gtk_entry_get_text(GTK_ENTRY(entryid)));
if(strcmp(C.identifiant,"")==0){
gtk_widget_show(verif1);
}
else
{
gtk_widget_set_visible(verif1,FALSE);
}

//Récuperation de la marque & controle de saisie
strcpy(C.marque, gtk_entry_get_text(GTK_ENTRY(entrymar)));
if(strcmp(C.marque,"")==0){
gtk_widget_show(verif1);
}
else
{
gtk_widget_set_visible(verif1,FALSE);
}
//Récuperation de la position & controle de saisie
strcpy(C.position, gtk_entry_get_text(GTK_ENTRY(entrypos)));
if(strcmp(C.position,"")==0){
gtk_widget_show(verif1);
}
else
{
gtk_widget_set_visible(verif1,FALSE);
}
//Récuperation de la valeur
C.valeur=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(entryval));

//Récuperation de l'état
C.etat=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(entryetat));

//Récuperation du type
strcpy(C.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(ty)));

if(gtk_widget_get_visible(verif1)==FALSE){
	p=lookup_widget(windowcap,"treeview1");
        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(p));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))
        {  
		gtk_widget_set_visible(select,FALSE);
		gtk_tree_model_get (model,&iter,0,&id,-1);
		if(capteur_exist(C.identifiant)==1 && strcmp(C.identifiant,id)!=0){
		gtk_widget_set_visible(success,FALSE);
		gtk_widget_show(fail);
		}
		else
		{
		modifier_capteur(C,id);
		//mise à jour du treeview
		Capteurtree(p,"capteurs.txt");
		p1=lookup_widget(windowcap,"TreeViewAffichageAlarmante");
		Alarmantetree(p1,"alarmantes.txt");
		p2=lookup_widget(windowcap,"treeview2");
		ChercherCapteur(p2,"capteurs.txt");
		p3=lookup_widget(windowcap,"treeview3");
		Defectueuxtree(p3,"defectueux.txt");
		//bien modifié
		gtk_widget_set_visible(fail,FALSE);
		gtk_widget_show(success);
		//vider les champs après modification
		gtk_entry_set_text(GTK_ENTRY(entryid),"");
		gtk_entry_set_text(GTK_ENTRY(entrymar),"");
		gtk_entry_set_text(GTK_ENTRY(entrypos),"");
		gtk_spin_button_set_value(GTK_SPIN_BUTTON(entryetat),1);
		gtk_spin_button_set_value(GTK_SPIN_BUTTON(entryval),0);
		}
	}
	else{
	gtk_widget_show(select);
	}
}
}


void
on_treeview2_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
}


void
on_ButtonRechercher_clicked            (GtkWidget *windowcap,
                                        gpointer         user_data)
{

GtkWidget *p, *success, *fail, *id;
gchar *identifiant;
id=lookup_widget(windowcap,"EntryId2");
identifiant=gtk_entry_get_text(GTK_ENTRY(id));
p=lookup_widget(windowcap,"treeview2");
success=lookup_widget(windowcap,"labelsucess3");
fail=lookup_widget(windowcap,"labelfail3");
if(strcmp(identifiant,"")==0){
ChercherCapteur(p,"capteurs.txt");
gtk_widget_set_visible(success,FALSE);
gtk_widget_show(fail);
}
else{
chercher_capteur(identifiant);
ChercherCapteur(p,"capteurs_recherche.txt");
gtk_widget_set_visible(fail,FALSE);
gtk_widget_show(success);
}
}


void
on_TreeViewAffichageAlarmante_row_activated
                                        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
}


void
on_treeview3_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}

