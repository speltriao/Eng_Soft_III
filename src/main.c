#include <gtk/gtk.h>


GtkWidget			*window;
GtkWidget			*adicionar_window;
GtkWidget			*fixed1;
GtkWidget			*view1;
GtkTreeStore		*treeStore;
GtkTreeView			*tv1;
GtkTreeViewColumn	*cx1;
GtkTreeViewColumn	*cx2;
GtkTreeViewColumn	*cx3;
GtkTreeViewColumn	*cx4;
GtkTreeViewColumn	*cx5;
GtkTreeViewColumn	*cx6;
GtkTreeSelection	*selection;
GtkCellRenderer		*cr1;
GtkCellRenderer		*cr2;
GtkCellRenderer		*cr3;
GtkCellRenderer		*cr4;
GtkCellRenderer		*cr5;
GtkCellRenderer		*cr6;
GtkBuilder			*builder; 
GtkWidget           *add_window;
GtkEntry	            *in_nome;
GtkEntry	            *in_telefone;
GtkEntry	            *in_servico;
GtkEntry	            *in_data;
GtkEntry	            *in_hora;
GtkEntry	            *in_profissional;
GtkTreeIter 			iter2;
void		on_destroy(); 

int main(int argc, char *argv[]) {

	gtk_init(&argc, &argv); // init Gtk

	builder = gtk_builder_new_from_file ("/home/speltriao/Documents/Programas/Code_C/C glade/Eng_Soft_III-main/glade/cabeleireiro.glade");
 
	window = GTK_WIDGET(gtk_builder_get_object(builder, "main_window"));

	g_signal_connect(window, "destroy", G_CALLBACK(on_destroy), NULL);

    gtk_builder_connect_signals(builder, NULL);

	fixed1		= GTK_WIDGET(gtk_builder_get_object(builder, "fixed1"));
	view1		= GTK_WIDGET(gtk_builder_get_object(builder, "view1"));
	treeStore	= GTK_TREE_STORE(gtk_builder_get_object(builder, "treeStore"));
	tv1		= GTK_TREE_VIEW(gtk_builder_get_object(builder, "tv1"));
	cx1		= GTK_TREE_VIEW_COLUMN(gtk_builder_get_object(builder, "cx1")); // col 1
	cx2		= GTK_TREE_VIEW_COLUMN(gtk_builder_get_object(builder, "cx2")); // col 2
	cx3		= GTK_TREE_VIEW_COLUMN(gtk_builder_get_object(builder, "cx3")); // col 2
	cx4		= GTK_TREE_VIEW_COLUMN(gtk_builder_get_object(builder, "cx4")); // col 2
	cx5		= GTK_TREE_VIEW_COLUMN(gtk_builder_get_object(builder, "cx5")); // col 2
	cx6		= GTK_TREE_VIEW_COLUMN(gtk_builder_get_object(builder, "cx6")); // col 2
	cr1		= GTK_CELL_RENDERER(gtk_builder_get_object(builder, "cr1")); // col 1 renderer
	cr2		= GTK_CELL_RENDERER(gtk_builder_get_object(builder, "cr2")); // col 2 renderer
	cr3		= GTK_CELL_RENDERER(gtk_builder_get_object(builder, "cr3")); // col 2 renderer
	cr4		= GTK_CELL_RENDERER(gtk_builder_get_object(builder, "cr4")); // col 2 renderer
	cr5		= GTK_CELL_RENDERER(gtk_builder_get_object(builder, "cr5")); // col 2 renderer
	cr6		= GTK_CELL_RENDERER(gtk_builder_get_object(builder, "cr6")); // col 2 renderer
	selection	= GTK_TREE_SELECTION(gtk_builder_get_object(builder, "selection")); // tree view selection
	adicionar_window = GTK_WIDGET(gtk_builder_get_object(builder, "adicionar_window"));
	in_nome = GTK_WIDGET(gtk_builder_get_object(builder, "in_nome"));
    in_telefone = GTK_WIDGET(gtk_builder_get_object(builder, "in_telefone"));
    in_servico = GTK_WIDGET(gtk_builder_get_object(builder, "in_servico"));
    in_data = GTK_WIDGET(gtk_builder_get_object(builder, "in_data"));
	in_hora= GTK_WIDGET(gtk_builder_get_object(builder, "in_hora"));
    in_profissional= GTK_WIDGET(gtk_builder_get_object(builder, "in_profissional"));

	gtk_tree_view_column_add_attribute(cx1, cr1, "text", 0); // attach the renderer to the column
	gtk_tree_view_column_add_attribute(cx2, cr2, "text", 1); // attach the renderer to the column
	gtk_tree_view_column_add_attribute(cx3, cr3, "text", 2);
	gtk_tree_view_column_add_attribute(cx4, cr4, "text", 3);
	gtk_tree_view_column_add_attribute(cx5, cr5, "text", 4);
	gtk_tree_view_column_add_attribute(cx6, cr6, "text", 5);



	selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(tv1));

	gtk_widget_show_all(window);
	gtk_main();
	return EXIT_SUCCESS;
	}

void on_selection_changed1(GtkTreeIter iter){
	//GtkTreeModel *model;

    g_print ("Row has been clicked. Removing row.\n");

	//

    //if (!gtk_tree_model_get_iter(model, &iter, path))
      //return; // path describes a non-existing row - should not happen //

    
}


void on_selection_changed(GtkWidget *c) { 
	gchar *value;
	
	GtkTreeModel *model;

	if (gtk_tree_selection_get_selected
		(GTK_TREE_SELECTION(c), &model, &iter2) == FALSE)
			return;

	gtk_tree_model_get(model, &iter2, 0, &value,  -1);
	printf("col 0 = %s; ", value);
	//
	gtk_tree_model_get(model, &iter2, 1, &value,  -1);
	printf("col 1  = %s\n", value);
}


void on_destroy() {
		gtk_main_quit();
		}

void on_btn_new_clicked(){
    gtk_widget_show(adicionar_window);
}
void on_btn_remover_clicked(){
	gtk_tree_store_remove(GTK_TREE_STORE(treeStore), &iter2);
}
void on_main_window_destroy(){
    gtk_main_quit();
}

void on_adicionar_window_delete(){
    gtk_widget_hide_on_delete(adicionar_window);
}

void on_btn_cancelar_clicked(){
    gtk_widget_hide(add_window);
}
void clear_in(){

}

void on_btn_ok_clicked(){
	char snome[64],stelefone[64],sservico[64],sprofissional[64],sdata[64],shora[64];
	sprintf(snome, "%s", gtk_entry_get_text(in_nome));
    sprintf(stelefone, gtk_entry_get_text(in_telefone));
    sprintf(sservico, "%s", gtk_entry_get_text(in_servico));
    sprintf(sprofissional, "%s", gtk_entry_get_text(in_profissional));
    sprintf(sdata, "%s", gtk_entry_get_text(in_data));
	sprintf(shora, "%s", gtk_entry_get_text(in_hora));
	GtkTreeIter iter;	
	gtk_tree_store_append (treeStore, &iter, NULL);
	gtk_tree_store_set(treeStore, &iter, 0, snome, -1); //Nome
	gtk_tree_store_set(treeStore, &iter, 1, stelefone, -1); //Telefone
	gtk_tree_store_set(treeStore, &iter, 2, sservico, -1); //Serviço
	gtk_tree_store_set(treeStore, &iter, 3, sprofissional, -1);//Profissional
	gtk_tree_store_set(treeStore, &iter, 4, sdata, -1);//Data
	gtk_tree_store_set(treeStore, &iter, 5, shora, -1);//Hora

}