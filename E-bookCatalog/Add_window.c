#include "Add_window.h"

//Dialog with information about a successful adding the book
void showDialog(GtkWidget* widget, gpointer window)
{
	GtkWidget* dialog;
	dialog = gtk_message_dialog_new(GTK_WINDOW(window), GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_INFO, GTK_BUTTONS_OK, "It was succesful to add the file %s", "");
	gtk_window_set_title(GTK_WINDOW(dialog), "New file in list");
	gtk_dialog_run(GTK_DIALOG(dialog));
	gtk_widget_destroy(dialog);
}

//Add new window after button "Add" clicked
void add_window(GtkWidget* pWidget, gpointer user_data) {

	GtkWidget* pWindow;
	GtkWidget* vbox1;
	GtkWidget* vbox2;
	GtkWidget* vbox3;
	GtkWidget* vbox4;
	GtkWidget* vbox5;
	GtkWidget* vbox6;

	GtkWidget* hbox;

	GtkWidget* entry1;
	GtkWidget* entry2;
	GtkWidget* entry3;
	GtkWidget* entry4;
	GtkWidget* entry5;
	GtkWidget* entry6;

	GtkWidget* text1;
	GtkWidget* text2;
	GtkWidget* text3;
	GtkWidget* text4;
	GtkWidget* text5;
	GtkWidget* text6;

	GtkWidget* button;
	GtkWidget* vboxx;

	pWindow = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(pWindow), "Add book");
	gtk_window_set_default_size(GTK_WINDOW(pWindow), 700, 50);
	gtk_window_set_position(GTK_WINDOW(pWindow), GTK_WIN_POS_CENTER);
	gtk_container_set_border_width(GTK_CONTAINER(pWindow), 6);

	button = gtk_button_new_with_label("Add");

	vbox1 = gtk_box_new(GTK_ORIENTATION_VERTICAL, 1);
	vbox2 = gtk_box_new(GTK_ORIENTATION_VERTICAL, 1);
	vbox3 = gtk_box_new(GTK_ORIENTATION_VERTICAL, 1);
	vbox4 = gtk_box_new(GTK_ORIENTATION_VERTICAL, 1);
	vbox5 = gtk_box_new(GTK_ORIENTATION_VERTICAL, 1);
	vbox6 = gtk_box_new(GTK_ORIENTATION_VERTICAL, 1);
	vboxx = gtk_box_new(GTK_ORIENTATION_VERTICAL, 1);

	gtk_box_pack_start(GTK_BOX(vboxx), button, FALSE, FALSE, 0);

	hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 10);

	text1 = gtk_label_new("Title");
	entry1 = gtk_entry_new();
	gtk_box_pack_start(GTK_BOX(vbox1), entry1, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(vbox1), text1, FALSE, FALSE, 0);

	text2 = gtk_label_new("Author");
	entry2 = gtk_entry_new();
	gtk_box_pack_start(GTK_BOX(vbox2), entry2, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(vbox2), text2, FALSE, FALSE, 0);

	text3 = gtk_label_new("Year");
	entry3 = gtk_entry_new();
	gtk_box_pack_start(GTK_BOX(vbox3), entry3, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(vbox3), text3, FALSE, FALSE, 0);
	gtk_entry_set_max_length(GTK_ENTRY(entry3), 4);

	text4 = gtk_label_new("Format");
	entry4 = gtk_entry_new();
	gtk_box_pack_start(GTK_BOX(vbox4), entry4, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(vbox4), text4, FALSE, FALSE, 0);
	gtk_entry_set_max_length(GTK_ENTRY(entry4), 4);

	text5 = gtk_label_new("File Path");
	entry5 = gtk_entry_new();
	gtk_box_pack_start(GTK_BOX(vbox5), entry5, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(vbox5), text5, FALSE, FALSE, 0);

	text6 = gtk_label_new("Comment");
	entry6 = gtk_entry_new();
	gtk_box_pack_start(GTK_BOX(vbox6), entry6, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(vbox6), text6, FALSE, FALSE, 0);

	g_signal_connect_swapped(button, "clicked", G_CALLBACK(add_data1), entry1);
	g_signal_connect_swapped(button, "clicked", G_CALLBACK(add_data2), entry2);
	g_signal_connect_swapped(button, "clicked", G_CALLBACK(add_data3), entry3);
	g_signal_connect_swapped(button, "clicked", G_CALLBACK(add_data4), entry4);
	g_signal_connect_swapped(button, "clicked", G_CALLBACK(add_data5), entry5);
	g_signal_connect_swapped(button, "clicked", G_CALLBACK(add_data6), entry6);
	g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(showDialog), (gpointer)pWindow);

	gtk_box_pack_start(GTK_BOX(hbox), vbox1, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(hbox), vbox2, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(hbox), vbox3, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(hbox), vbox4, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(hbox), vbox5, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(hbox), vbox6, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(hbox), vboxx, FALSE, FALSE, 0);

	gtk_container_add(GTK_CONTAINER(pWindow), hbox);

	gtk_widget_show_all(pWindow);

}