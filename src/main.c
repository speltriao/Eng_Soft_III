#include <gtk/gtk.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>


//gcc -o gladewin main.c -Wall -rdynamic $(pkg-config --cflags --libs gtk+-3.0) -export-dynamic
GtkWidget				*window;
GtkWidget				*teste_window;
GtkWidget				*adicionar_window;
GtkWidget				*adicionar_window2;
GtkWidget				*adicionar_window3;
GtkWidget				*pesquisar_window;
GtkWidget				*sobre_window;
GtkWidget				*fixed1;
GtkWidget				*view1;
GtkWidget				*btn_masculino;
GtkWidget				*btn_feminino;
GtkWidget				*btn_feminino2;
GtkWidget				*btn_masculino2;
GtkWidget				*btn_clientes;
GtkWidget				*btn_funcionarios;
GtkWidget				*btn_agenda;
GtkTreeStore			*treeStore;
GtkTreeStore			*treeStore2;
GtkTreeStore			*treeStore3;
GtkTreeView				*tv1;
GtkTreeView				*tv2;
GtkTreeView				*tv3;
GtkTreeViewColumn		*cx1;
GtkTreeViewColumn		*cx2;
GtkTreeViewColumn		*cx3;
GtkTreeViewColumn		*cx4;
GtkTreeViewColumn		*cx5;
GtkTreeViewColumn		*cx6;
GtkTreeViewColumn		*cx7;
GtkTreeViewColumn		*cx8;
GtkTreeViewColumn		*cx9;
GtkTreeViewColumn		*cx10;
GtkTreeViewColumn		*cx11;
GtkTreeViewColumn		*cx12;
GtkTreeViewColumn		*cx13;
GtkTreeViewColumn		*cx14;
GtkTreeViewColumn		*cx15;
GtkTreeViewColumn		*cx16;
GtkTreeViewColumn		*cx17;
GtkTreeSelection		*selection;
GtkTreeSelection		*selection2;
GtkTreeSelection		*selection3;
GtkCellRenderer			*cr1;
GtkCellRenderer			*cr2;
GtkCellRenderer			*cr3;
GtkCellRenderer			*cr4;
GtkCellRenderer			*cr5;
GtkCellRenderer			*cr6;
GtkCellRenderer			*cr7;
GtkCellRenderer			*cr8;
GtkCellRenderer			*cr9;
GtkCellRenderer			*cr10;
GtkCellRenderer			*cr11;
GtkCellRenderer			*cr12;
GtkCellRenderer			*cr13;
GtkCellRenderer			*cr14;
GtkCellRenderer			*cr15;
GtkCellRenderer			*cr16;
GtkCellRenderer			*cr17;
GtkBuilder				*builder; 
GtkEntry	            *in_nome;
GtkEntry	            *in_telefone;
GtkEntry	            *in_cpf;
GtkEntry	            *in_endereco;
GtkEntry	            *in_telefone;
GtkEntry	            *in_nome2;
GtkEntry	            *in_telefone2;
GtkEntry	            *in_cpf2;
GtkEntry	            *in_endereco2;
GtkEntry	            *in_servicos;
GtkEntry	            *in_nome3;
GtkEntry	            *in_datahora3;
GtkEntry	            *in_profissional3;
GtkEntry	            *in_servico3;
GtkEntry	            *in_preco3;

GtkEntry	            *out_datahora;
GtkTreeIter 			iter2;


void on_destroy();
char data2[20]; 
int main(int argc, char *argv[]) {

	gtk_init(&argc, &argv);
	builder = gtk_builder_new_from_file ("../glade/cabeleireiro.glade");
	window = GTK_WIDGET(gtk_builder_get_object(builder, "main_window"));

	g_signal_connect(window, "destroy", G_CALLBACK(on_destroy), NULL);

    gtk_builder_connect_signals(builder, NULL);

	fixed1		= GTK_WIDGET(gtk_builder_get_object(builder, "fixed1"));
	view1		= GTK_WIDGET(gtk_builder_get_object(builder, "view1"));
	treeStore	= GTK_TREE_STORE(gtk_builder_get_object(builder, "treeStore"));
	treeStore2	= GTK_TREE_STORE(gtk_builder_get_object(builder, "treeStore2"));
	treeStore3	= GTK_TREE_STORE(gtk_builder_get_object(builder, "treeStore3"));
	tv1		= GTK_TREE_VIEW(gtk_builder_get_object(builder, "tv1"));
	tv2		= GTK_TREE_VIEW(gtk_builder_get_object(builder, "tv2"));
	tv3		= GTK_TREE_VIEW(gtk_builder_get_object(builder, "tv3"));
	cx1		= GTK_TREE_VIEW_COLUMN(gtk_builder_get_object(builder, "cx1")); // col 1
	cx2		= GTK_TREE_VIEW_COLUMN(gtk_builder_get_object(builder, "cx2")); // col 2
	cx3		= GTK_TREE_VIEW_COLUMN(gtk_builder_get_object(builder, "cx3")); // col 3
	cx4		= GTK_TREE_VIEW_COLUMN(gtk_builder_get_object(builder, "cx4")); // col 4
	cx5		= GTK_TREE_VIEW_COLUMN(gtk_builder_get_object(builder, "cx5")); // col 5
	cx6		= GTK_TREE_VIEW_COLUMN(gtk_builder_get_object(builder, "cx6")); // col 6
	cx7		= GTK_TREE_VIEW_COLUMN(gtk_builder_get_object(builder, "cx7")); // col 6
	cx8		= GTK_TREE_VIEW_COLUMN(gtk_builder_get_object(builder, "cx8")); // col 6
	cx9		= GTK_TREE_VIEW_COLUMN(gtk_builder_get_object(builder, "cx9")); // col 6
	cx10	= GTK_TREE_VIEW_COLUMN(gtk_builder_get_object(builder, "cx10")); // col 6
	cx11	= GTK_TREE_VIEW_COLUMN(gtk_builder_get_object(builder, "cx11")); // col 6
	cx12	= GTK_TREE_VIEW_COLUMN(gtk_builder_get_object(builder, "cx12"));
	cx13	= GTK_TREE_VIEW_COLUMN(gtk_builder_get_object(builder, "cx13"));
	cx14	= GTK_TREE_VIEW_COLUMN(gtk_builder_get_object(builder, "cx14"));
	cx15	= GTK_TREE_VIEW_COLUMN(gtk_builder_get_object(builder, "cx15"));
	cx16	= GTK_TREE_VIEW_COLUMN(gtk_builder_get_object(builder, "cx16"));
	cx17	= GTK_TREE_VIEW_COLUMN(gtk_builder_get_object(builder, "cx17"));

	cr1		= GTK_CELL_RENDERER(gtk_builder_get_object(builder, "cr1")); // col 1 renderer
	cr2		= GTK_CELL_RENDERER(gtk_builder_get_object(builder, "cr2")); 
	cr3		= GTK_CELL_RENDERER(gtk_builder_get_object(builder, "cr3")); 
	cr4		= GTK_CELL_RENDERER(gtk_builder_get_object(builder, "cr4")); 
	cr5		= GTK_CELL_RENDERER(gtk_builder_get_object(builder, "cr5")); 
	cr6		= GTK_CELL_RENDERER(gtk_builder_get_object(builder, "cr6")); 
	cr7		= GTK_CELL_RENDERER(gtk_builder_get_object(builder, "cr7")); 
	cr8		= GTK_CELL_RENDERER(gtk_builder_get_object(builder, "cr8")); 
	cr9		= GTK_CELL_RENDERER(gtk_builder_get_object(builder, "cr9")); 
	cr10	= GTK_CELL_RENDERER(gtk_builder_get_object(builder, "cr10")); 
	cr11	= GTK_CELL_RENDERER(gtk_builder_get_object(builder, "cr11")); 
	cr12	= GTK_CELL_RENDERER(gtk_builder_get_object(builder, "cr12")); 
	cr13	= GTK_CELL_RENDERER(gtk_builder_get_object(builder, "cr13")); 
	cr14	= GTK_CELL_RENDERER(gtk_builder_get_object(builder, "cr14")); 
	cr15	= GTK_CELL_RENDERER(gtk_builder_get_object(builder, "cr15")); 
	cr16	= GTK_CELL_RENDERER(gtk_builder_get_object(builder, "cr16")); 
	cr17	= GTK_CELL_RENDERER(gtk_builder_get_object(builder, "cr17")); 

	adicionar_window= GTK_WIDGET(gtk_builder_get_object(builder, "adicionar_window"));
	adicionar_window2= GTK_WIDGET(gtk_builder_get_object(builder, "adicionar_window2"));
	adicionar_window3= GTK_WIDGET(gtk_builder_get_object(builder, "adicionar_window3"));
	sobre_window= GTK_WIDGET(gtk_builder_get_object(builder, "sobre_window"));
	pesquisar_window= GTK_WIDGET(gtk_builder_get_object(builder, "pesquisar_window"));
	in_nome = GTK_WIDGET(gtk_builder_get_object(builder, "in_nome"));
    in_telefone = GTK_WIDGET(gtk_builder_get_object(builder, "in_telefone"));
    in_cpf = GTK_WIDGET(gtk_builder_get_object(builder, "in_cpf"));
    in_endereco = GTK_WIDGET(gtk_builder_get_object(builder, "in_endereco"));
	in_nome2 = GTK_WIDGET(gtk_builder_get_object(builder, "in_nome2"));
    in_telefone2 = GTK_WIDGET(gtk_builder_get_object(builder, "in_telefone2"));
    in_cpf2 = GTK_WIDGET(gtk_builder_get_object(builder, "in_cpf2"));
    in_endereco2 = GTK_WIDGET(gtk_builder_get_object(builder, "in_endereco2"));
	in_servicos= GTK_WIDGET(gtk_builder_get_object(builder, "in_servicos"));
	in_nome3 = GTK_WIDGET(gtk_builder_get_object(builder, "in_nome3"));
	in_datahora3= GTK_WIDGET(gtk_builder_get_object(builder, "in_datahora3"));
	in_profissional3= GTK_WIDGET(gtk_builder_get_object(builder, "in_profissional3"));
	in_servico3= GTK_WIDGET(gtk_builder_get_object(builder, "in_servico3"));
	in_preco3= GTK_WIDGET(gtk_builder_get_object(builder, "in_preco3"));

	
	out_datahora= GTK_WIDGET(gtk_builder_get_object(builder, "out_datahora"));
	btn_feminino= GTK_WIDGET(gtk_builder_get_object(builder, "btn_feminino"));
	btn_masculino= GTK_WIDGET(gtk_builder_get_object(builder, "btn_masculino"));
	btn_feminino2= GTK_WIDGET(gtk_builder_get_object(builder, "btn_feminino2"));
	btn_masculino2= GTK_WIDGET(gtk_builder_get_object(builder, "btn_masculino2"));
	btn_clientes= GTK_WIDGET(gtk_builder_get_object(builder, "btn_clientes"));
	btn_funcionarios= GTK_WIDGET(gtk_builder_get_object(builder, "btn_funcionarios"));
	btn_agenda= GTK_WIDGET(gtk_builder_get_object(builder, "btn_agenda"));

	
	g_signal_connect (sobre_window, "delete-event", G_CALLBACK (gtk_widget_hide_on_delete), NULL);
	g_signal_connect (pesquisar_window, "delete-event", G_CALLBACK (gtk_widget_hide_on_delete), NULL);
	g_signal_connect (adicionar_window2, "delete-event", G_CALLBACK (gtk_widget_hide_on_delete), NULL);
	g_signal_connect (adicionar_window3, "delete-event", G_CALLBACK (gtk_widget_hide_on_delete), NULL);

	selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(tv1));
	selection2 = gtk_tree_view_get_selection(GTK_TREE_VIEW(tv3));
	selection3 = gtk_tree_view_get_selection(GTK_TREE_VIEW(tv2));

	gtk_widget_show(window);
	gtk_main();
	return EXIT_SUCCESS;
	}


void on_selection_changed(GtkWidget *c) { 
	gchar *value;
	
	GtkTreeModel *model;

	if (gtk_tree_selection_get_selected
		(GTK_TREE_SELECTION(c), &model, &iter2) == FALSE)
			return;

	gtk_tree_model_get(model, &iter2, 0, &value,  -1);
	gtk_tree_model_get(model, &iter2, 1, &value,  -1);
}


void on_destroy() {
	gtk_main_quit();
}


void on_btn_new_clicked(){

	if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(btn_clientes))==TRUE){
		gtk_widget_show(adicionar_window);
    }
	else if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(btn_funcionarios))==TRUE){
		gtk_widget_show(adicionar_window2);
	}
	else if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(btn_agenda))==TRUE){
		gtk_widget_show(adicionar_window3);
	}
}
void on_btn_remover_clicked (){
	GtkTreeModel *model;
	GtkTreeSelection *select;

	if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(btn_clientes))==TRUE){
		select = gtk_tree_view_get_selection (GTK_TREE_VIEW (tv1));
		if (gtk_tree_selection_get_selected (selection, &model, &iter2)) {
			gtk_tree_store_remove (treeStore,&iter2);
		}
    }
	else if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(btn_funcionarios))==TRUE){
		select = gtk_tree_view_get_selection (GTK_TREE_VIEW (tv3));
		if (gtk_tree_selection_get_selected (selection2, &model, &iter2)) {
			gtk_tree_store_remove (treeStore2,&iter2);
		}
	}
	else if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(btn_agenda))==TRUE){
		select = gtk_tree_view_get_selection (GTK_TREE_VIEW (tv2));
		if (gtk_tree_selection_get_selected (selection3, &model, &iter2)) {
			gtk_tree_store_remove (treeStore3,&iter2);
		}
	}

}
void on_main_window_destroy(){
    gtk_main_quit();
}

void on_adicionar_window_delete(){
    gtk_widget_hide_on_delete(adicionar_window);
}
void on_adicionar_window2_delete(){
    gtk_widget_hide_on_delete(adicionar_window2);
}


void clear_in(){
	gtk_widget_hide (adicionar_window);
    gtk_entry_set_text(in_nome,"");
    gtk_entry_set_text(in_telefone,"");
	gtk_entry_set_text(in_cpf,"");
	gtk_entry_set_text(in_endereco,"");
}

void clear_in2(){
	gtk_widget_hide (adicionar_window2);
    gtk_entry_set_text(in_nome2,"");
    gtk_entry_set_text(in_telefone2,"");
	gtk_entry_set_text(in_cpf2,"");
	gtk_entry_set_text(in_endereco2,"");
	gtk_entry_set_text(in_servicos,"");
}

void clear_in3(){
	gtk_widget_hide (adicionar_window3);
    gtk_entry_set_text(in_nome3,"");
    gtk_entry_set_text(in_datahora3,"");
	gtk_entry_set_text(in_profissional3,"");
	gtk_entry_set_text(in_servico3,"");
	gtk_entry_set_text(in_preco3,"");
}

void on_btn_ok_clicked(){
	
	char snome[64],stelefone[64],scpf[64],sendereco[64],sgenero[10]="F";

	if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(btn_masculino))==TRUE){
		sprintf(sgenero, "%s", "M");
    }

	sprintf(snome, "%s", gtk_entry_get_text(in_nome));
    sprintf(stelefone, gtk_entry_get_text(in_telefone));
    sprintf(scpf, "%s", gtk_entry_get_text(in_cpf));
    sprintf(sendereco, "%s", gtk_entry_get_text(in_endereco));
	
	GtkTreeIter iter;	
	gtk_tree_store_append (treeStore, &iter, NULL);
	
	gtk_tree_view_column_add_attribute(cx1, cr1, "text", 0); // attach the renderer to the column
	gtk_tree_view_column_add_attribute(cx2, cr2, "text", 1); 
	gtk_tree_view_column_add_attribute(cx3, cr3, "text", 2);
	gtk_tree_view_column_add_attribute(cx4, cr4, "text", 3);
	gtk_tree_view_column_add_attribute(cx5, cr5, "text", 4);

	gtk_tree_store_set(treeStore, &iter, 0, snome, -1); //Nome
	gtk_tree_store_set(treeStore, &iter, 1, scpf, -1); //CPF
	gtk_tree_store_set(treeStore, &iter, 2, sendereco, -1);//Endereço
	gtk_tree_store_set(treeStore, &iter, 3, stelefone, -1); //Telefone
	gtk_tree_store_set(treeStore, &iter, 4, sgenero, -1);//sexo
	clear_in();
	
}


void on_btn_ok2_clicked(){
	char snome[64],stelefone[64],scpf[64],sendereco[64],sservicos[64],sgenero[10]="F";
	if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(btn_masculino2))==TRUE){
		sprintf(sgenero, "%s", "M");
    }
	sprintf(snome, "%s", gtk_entry_get_text(in_nome2));
    sprintf(stelefone, gtk_entry_get_text(in_telefone2));
    sprintf(scpf, "%s", gtk_entry_get_text(in_cpf2));
    sprintf(sendereco, "%s", gtk_entry_get_text(in_endereco2));
	sprintf(sservicos, "%s", gtk_entry_get_text(in_servicos));

	GtkTreeIter iter;	
	gtk_tree_store_append (treeStore2, &iter, NULL);
	gtk_tree_view_column_add_attribute(cx6, cr6, "text",  0); // attach the renderer to the column
	gtk_tree_view_column_add_attribute(cx8, cr8, "text",  1);
	gtk_tree_view_column_add_attribute(cx9, cr9, "text",  2);
	gtk_tree_view_column_add_attribute(cx10, cr10,"text", 3);
	gtk_tree_view_column_add_attribute(cx11, cr11, "text", 4);
	gtk_tree_view_column_add_attribute(cx12, cr12, "text", 5);
	gtk_tree_store_set(treeStore2, &iter, 0, snome, -1); //Nome
	gtk_tree_store_set(treeStore2, &iter, 1, scpf, -1); //CPF
	gtk_tree_store_set(treeStore2, &iter, 2, sendereco, -1);//Endereço
	gtk_tree_store_set(treeStore2, &iter, 3, stelefone, -1); //Telefone
	gtk_tree_store_set(treeStore2, &iter, 4, sservicos, -1);//genero 
	gtk_tree_store_set(treeStore2, &iter, 5, sgenero, -1);//servico
	clear_in2();
	
}

void on_btn_cancelar_clicked(){
    clear_in();
}
void on_btn_cancelar2_clicked(){
	clear_in2();
}

void on_btn_clientes_pressed(){
	gtk_widget_show(tv1);
	gtk_widget_hide(tv2);
	gtk_widget_hide(tv3);
	gtk_widget_hide(out_datahora);
}

char* get_time(){
	
	char dia[10], mes[15], ano[10], hora[10],min[10],data[51], dataf[60]="Hoje é: ",separador = '/', de[4]=" de ";
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	sprintf(dia, "%d", tm.tm_mday);
	strncat(dia, &de, 4);
	switch (tm.tm_mon + 1)
	{
	case 1:
		sprintf(mes, "%s", "Janeiro");
		break;
	case 2:
		sprintf(mes, "%s", "Fevereiro");
		break;
	case 3:
		sprintf(mes, "%s", "Março");
		break;		
	case 4:
		sprintf(mes, "%s", "Abril");
		break;	
	case 5:
		sprintf(mes, "%s", "Maio");
		break;	
	case 6:
		sprintf(mes, "%s", "Junho");
		break;	
	case 7:
		sprintf(mes, "%s", "Julho");
		break;
	case 8:
		sprintf(mes, "%s", "Agosto");
		break;
	case 9:
		sprintf(mes, "%s", "Setembro");
		break;
	case 10:
		sprintf(mes, "%s", "Outubro");
		break;
	case 11:
		sprintf(mes, "%s", "Novembro");
		break;
	case 12:
		sprintf(mes, "%s", "Dezembro");
		break;
	}
	strncat(mes, &de, 4);
	sprintf(ano, "%d", tm.tm_year+1900);
	strncat(ano, " ", 1);
	sprintf(hora, "%d", tm.tm_hour);
	strncat(hora, "h", 1);

	switch (tm.tm_min){
		case 1:
			sprintf(min, "%s", "01");
			break;
		case 2:
			sprintf(min, "%s", "02");
			break;
		case 3:
			sprintf(min, "%s", "03");
			break;
		case 4:
			sprintf(min, "%s", "04");
			break;
		case 5:
			sprintf(min, "%s", "05");
			break;
		case 6:
			sprintf(min, "%s", "06");
			break;
		case 7:
			sprintf(min, "%s", "07");
			break;
		case 8:
			sprintf(min, "%s", "08");
			break;
		case 9:
			sprintf(min, "%s", "09");
			break;
		default:
			sprintf(min, "%d", tm.tm_min);
			break;
	}
	snprintf(data, sizeof data, "%s%s%s%s%s%s", dia, mes, ano," ", hora,min);
	snprintf(data2, sizeof data2, "%s%s%s",hora,":",min);
	strncat(dataf,data,strlen(data));
	gtk_entry_set_text(out_datahora,data);
	return data2;
}

void on_btn_agenda_pressed(){
	gtk_widget_hide(tv1);
	gtk_widget_hide(tv3);
	gtk_widget_show(tv2);
	gtk_widget_show(out_datahora);
	get_time();
	gtk_tree_view_column_set_title(cx7,data2);
}

void on_btn_funcionarios_pressed(){
	gtk_widget_hide(tv1);
	gtk_widget_hide(tv2);
	gtk_widget_hide(out_datahora);
	gtk_widget_show(tv3);
}

void on_btn_pesquisar_clicked(){
	gtk_widget_show(pesquisar_window);
}

void on_btn_cancelar3_clicked(){
	gtk_widget_hide(pesquisar_window);
}

void on_about_item_activate(){
	gtk_widget_show(sobre_window);
}

void on_ok_btn_clicked(){
	gtk_widget_hide(sobre_window);
}

void on_teste_clicked(){
	gtk_widget_show(sobre_window);
}

void on_btn_cancelar1_clicked(){
	clear_in3();
	gtk_widget_hide(adicionar_window3);
}

void on_btn_ok1_clicked(){
	g_print("clicou");
	char snome[64],sdata[64],sprofissional[64],sservico[64],spreco[64];
	sprintf(snome, "%s", gtk_entry_get_text(in_nome3));
    sprintf(sdata, "%s",gtk_entry_get_text(in_datahora3));
    sprintf(sprofissional, "%s", gtk_entry_get_text(in_profissional3));
    sprintf(spreco, "%s", gtk_entry_get_text(in_preco3));
	sprintf(sservico, "%s", gtk_entry_get_text(in_servico3));

	GtkTreeIter iter;	
	gtk_tree_store_append (treeStore3, &iter, NULL);
	gtk_tree_view_column_add_attribute(cx13, cr13, "text",  1);
	gtk_tree_view_column_add_attribute(cx14, cr14, "text",  2);
	gtk_tree_view_column_add_attribute(cx15, cr15,"text", 3);
	gtk_tree_view_column_add_attribute(cx16, cr16, "text", 4);
	gtk_tree_view_column_add_attribute(cx17, cr17, "text", 5);
	
	gtk_tree_store_set(treeStore3, &iter, 1, snome, -1); //CPF
	gtk_tree_store_set(treeStore3, &iter, 2, sprofissional, -1); //Telefone
	gtk_tree_store_set(treeStore3, &iter, 3, sdata, -1);//Endereço
	gtk_tree_store_set(treeStore3, &iter, 4, spreco, -1);//genero 
	gtk_tree_store_set(treeStore3, &iter, 5, sservico, -1);//servico
	clear_in3();
}
