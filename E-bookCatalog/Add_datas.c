#include "Add_datas.h"

//Add info from entry, all "add_data's"
void add_data1(GtkWidget* entry, gpointer data) {
	const gchar* text = gtk_entry_get_text(GTK_ENTRY(entry));

	addToFile("titles.txt", text);
	addToFile("titles.txt", "\n");
	gtk_entry_set_text(GTK_ENTRY(entry), "");
}

void add_data2(GtkWidget* entry, gpointer data) {
	const gchar* text = gtk_entry_get_text(GTK_ENTRY(entry));

	addToFile("authors.txt", text);
	addToFile("authors.txt", "\n");
	gtk_entry_set_text(GTK_ENTRY(entry), "");
}

void add_data3(GtkWidget* entry, gpointer data) {
	const gchar* text = gtk_entry_get_text(GTK_ENTRY(entry));

	addToFile("years.txt", text);
	addToFile("years.txt", "\n");
	gtk_entry_set_text(GTK_ENTRY(entry), "");
}

void add_data4(GtkWidget* entry, gpointer data) {
	const gchar* text = gtk_entry_get_text(GTK_ENTRY(entry));

	addToFile("formats.txt", text);
	addToFile("formats.txt", "\n");
	gtk_entry_set_text(GTK_ENTRY(entry), "");
}

void add_data5(GtkWidget* entry, gpointer data) {
	const gchar* text = gtk_entry_get_text(GTK_ENTRY(entry));

	addToFile("filePaths.txt", text);
	addToFile("filePaths.txt", "\n");
	gtk_entry_set_text(GTK_ENTRY(entry), "");
}

void add_data6(GtkWidget* entry, gpointer data) {
	const gchar* text = gtk_entry_get_text(GTK_ENTRY(entry));

	addToFile("comments.txt", text);
	addToFile("comments.txt", "\n");
	gtk_entry_set_text(GTK_ENTRY(entry), "");
}