#include <gtk/gtk.h>


void
on_ButtonGestiondescapteurs_clicked    (GtkWidget *windowcap,
                                        gpointer         user_data);

void
on_ButtonGestiondesouvriers_clicked    (GtkWidget *windowcap,
                                        gpointer         user_data);

void
on_ButtonGestiondes__quipements_clicked
                                        (GtkWidget *windowcap,
                                        gpointer         user_data);

void
on_ButtonGestiondesclients_clicked     (GtkWidget *windowcap,
                                        gpointer         user_data);

void
on_ButtonGestiondestroupeaux_clicked   (GtkWidget *windowcap,
                                        gpointer         user_data);

void
on_ButtonGestionducalendrier_clicked   (GtkWidget *windowcap,
                                        gpointer         user_data);

void
on_ButtonQuit_clicked                  (GtkWidget *windowcap,
                                        gpointer         user_data);

void
on_ButtonAjouter_clicked               (GtkWidget *windowcap,
                                        gpointer         user_data);

void
on_ButtonSupprimer_clicked             (GtkWidget *windowcap,
                                        gpointer         user_data);

void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_ButtonModifier_clicked              (GtkWidget *windowcap,
                                        gpointer         user_data);

void
on_treeview2_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_ButtonRechercher_clicked            (GtkWidget *windowcap,
                                        gpointer         user_data);

void
on_TreeViewAffichageAlarmante_row_activated
                                        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_treeview3_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);
