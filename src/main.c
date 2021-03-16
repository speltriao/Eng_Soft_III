#include <gtk/gtk.h>


enum {
    nome,
    telefone,
    servico,
    profissional, /* Not used by the view, maybe used elsewhere */
    datahora,
    N_COLUMNS
};

    GtkBuilder      *builder; 
    GtkWidget       *view;
    GtkWidget       *window;
    GtkWidget       *add_window;
    GtkListStore     *model;
    GtkTreeViewColumn   *column;
    GtkEntry	*in_nome;
    GtkEntry	*in_telefone;
    GtkEntry	*in_servico;
    GtkEntry	*in_datahora;
    GtkEntry	*in_profissional;


int main(int argc, char *argv[]){
    gtk_init(&argc, &argv);
    model = gtk_list_store_new(N_COLUMNS,
                               G_TYPE_STRING,   /* nome */
                               G_TYPE_STRING,     /* telefone */
                               G_TYPE_STRING,     /* servico */
                               G_TYPE_STRING,   /* profissional */
                               G_TYPE_STRING    /*datahora*/
                              );

    view = gtk_tree_view_new_with_model(GTK_TREE_MODEL(model));
    g_object_unref(model);

    column = gtk_tree_view_column_new_with_attributes("Nome",
                                                      gtk_cell_renderer_text_new(),
                                                      "text", nome,
                                                      NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(view), column);

    column = gtk_tree_view_column_new_with_attributes("Telefone",
                                                      gtk_cell_renderer_spin_new(),
                                                      "text", telefone,
                                                      NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(view), column);

    column = gtk_tree_view_column_new_with_attributes("Serviço",
                                                      gtk_cell_renderer_text_new(),
                                                      "text", servico,
                                                      NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(view), column);
    
        column = gtk_tree_view_column_new_with_attributes("Profissional",
                                                      gtk_cell_renderer_text_new(),
                                                      "text", profissional,
                                                      NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(view), column);

        column = gtk_tree_view_column_new_with_attributes("Data e hora",
                                                      gtk_cell_renderer_text_new(),
                                                      "text", datahora,
                                                      NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(view), column);


    builder = gtk_builder_new();
    gtk_builder_add_from_file (builder, "/home/speltriao/Documents/Programas/cabeleireiro.glade", NULL);
    in_nome = GTK_WIDGET(gtk_builder_get_object(builder, "in_nome"));
    in_telefone = GTK_WIDGET(gtk_builder_get_object(builder, "in_telefone"));
    in_servico = GTK_WIDGET(gtk_builder_get_object(builder, "in_servico"));
    in_datahora = GTK_WIDGET(gtk_builder_get_object(builder, "in_datahora"));
    in_profissional= GTK_WIDGET(gtk_builder_get_object(builder, "in_profissional"));

    window = GTK_WIDGET(gtk_builder_get_object(builder, "main_window"));
    add_window = GTK_WIDGET(gtk_builder_get_object(builder, "add_window"));

    gtk_builder_connect_signals(builder, NULL);
    gtk_container_add(GTK_CONTAINER(window), view);
    gtk_widget_show_all(window);
    g_object_unref(builder);
    gtk_main();
    return 0;
}

void on_btn_new_clicked(){
    gtk_widget_show(add_window);
}


void on_main_window_destroy(){
    gtk_main_quit();
}

void on_add_window_delete(){
    gtk_widget_hide_on_delete(add_window);
}



void on_btn_cancelar_clicked(){
    gtk_widget_hide(add_window);
}
void clear_in(){
    gtk_entry_reset_im_context(in_nome);
    gtk_widget_hide(add_window);
    gtk_entry_set_text(in_nome,"");
    gtk_entry_set_text(in_telefone,"");
    gtk_entry_set_text(in_servico,"");
    gtk_entry_set_text(in_profissional,"");
    gtk_entry_set_text(in_datahora,"");
}

void on_btn_ok_clicked(){
    char snome[64],stelefone[64],sservico[64],sprofissional[64],sdatahora[64];
	sprintf(snome, "%s", gtk_entry_get_text(in_nome));
    sprintf(stelefone, gtk_entry_get_text(in_telefone));
    sprintf(sservico, "%s", gtk_entry_get_text(in_servico));
    sprintf(sprofissional, "%s", gtk_entry_get_text(in_profissional));
    sprintf(sdatahora, "%s", gtk_entry_get_text(in_datahora));

    gtk_list_store_insert_with_values(model, NULL, -1,
                                      nome, snome,
                                      telefone, stelefone,
                                      servico, sservico,
                                      profissional, sprofissional,
                                      datahora, sdatahora,
                                      -1);
    clear_in();
}
