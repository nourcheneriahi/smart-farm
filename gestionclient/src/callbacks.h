#include <gtk/gtk.h>


void
on_button2_ajouter_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_button4_supp_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_button3_modi_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_checkbutton1_validmodif_toggled     (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton2_validsupp_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_treeview2_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_button5_chercher_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_button6_quit_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_gclients_clicked                    (GtkButton       *button,
                                        gpointer         user_data);
