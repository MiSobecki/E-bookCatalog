#include "Functions.h"

//Create new array
void createStruct(Book *tab) {
	int number = lines();
		
	FILE* file1;
	FILE* file2;
	FILE* file3;
	FILE* file4;
	FILE* file5;
	FILE* file6;

	file1 = fopen("titles.txt", "r");
	file2 = fopen("authors.txt", "r");
	file3 = fopen("years.txt", "r");
	file4 = fopen("formats.txt", "r");
	file5 = fopen("filePaths.txt", "r");
	file6 = fopen("comments.txt", "r");

	int i = 0;
	char a[100];
	char b[100];
	char c[6];
	char d[6];
	char e[100];
	char f[100];

	int nb;

	while (i<=number) {
		fgets(a, 100, file1);
		nb = 0;
		while (a[nb] != '\0') {
			if (a[nb] == '\n')
				a[nb] = '\0';
			nb++;
		}
		strcpy(tab[i].title, a);
		fgets(b, 100, file2);
		nb = 0;
		while (b[nb] != '\0') {
			if (b[nb] == '\n')
				b[nb] = '\0';
			nb++;
		}
		strcpy(tab[i].author, b);
		fgets(c, 6, file3);
		nb = 0;
		while (c[nb] != '\0') {
			if (c[nb] == '\n')
				c[nb] = '\0';
			nb++;
		}
		strcpy(tab[i].year, c);
		fgets(d, 6, file4);
		nb = 0;
		while (d[nb] != '\0') {
			if (d[nb] == '\n')
				d[nb] = '\0';
			nb++;
		}
		strcpy(tab[i].format, d);
		fgets(e, 100, file5);
		nb = 0;
		while (e[nb] != '\0') {
			if (e[nb] == '\n')
				e[nb] = '\0';
			nb++;
		}
		strcpy(tab[i].filePath, e);
		fgets(f, 100, file6);
		nb = 0;
		while (f[nb] != '\0') {
			if (f[nb] == '\n')
				f[nb] = '\0';
			nb++;
		}
		strcpy(tab[i].comment, f);
		i++;
	}

	fclose(file1);
	fclose(file2);
	fclose(file3);
	fclose(file4);
	fclose(file5);
	fclose(file6);
}

//Add new line to the file
void addToFile(const char* name, const gchar* data) {
	FILE* file;
	file = fopen(name, "a");

	fputs(data, file);

	fclose(file);
}


//Create new List to show
void createList(Book *tab, GtkListStore* list, GtkTreeIter *iter) {

	int number = lines();

	int i = 0;
	while (i <= number) {
		gtk_list_store_append(list, &iter);
		gtk_list_store_set(list, &iter, 0, tab[i].title, 1, tab[i].author, 2, tab[i].year, 3 , tab[i].format, 4, tab[i].filePath, 5, tab[i].comment, -1);
		i++;
	}

}

//create new List only with searched Title
void createTitleList(Book* tab, GtkListStore* list, GtkTreeIter* iter, gchar* text) {

	int number = lines();
	int i = 0;

	char *text_copy = malloc(strlen(text) + 1);
	strcpy(text_copy, text);


	char* cos2 = text_copy;
	for (; *text_copy != '\0'; ++text_copy) *text_copy = tolower(*text_copy);
	
	while (i <= number) {
		char* tab_copy = malloc(strlen(tab[i].title) + 1);
		strcpy(tab_copy, tab[i].title);
		char* cos = tab_copy;
		for (; *tab_copy; ++tab_copy) *tab_copy = tolower(*tab_copy);
		if ((strstr(cos, cos2) != NULL)) {
			gtk_list_store_append(list, &iter);
			gtk_list_store_set(list, &iter, 0, tab[i].title, 1, tab[i].author, 2, tab[i].year, 3, tab[i].format, 4, tab[i].filePath, 5, tab[i].comment, -1);
		}
		i++;
		free(cos);
	}
}

//Create new List only with searched Author
void createAuthorList(Book* tab, GtkListStore* list, GtkTreeIter* iter, gchar* text) {

	int number = lines();

	int i = 0;

	char* text_copy = malloc(strlen(text) + 1);
	strcpy(text_copy, text);


	char* cos2 = text_copy;
	for (; *text_copy != '\0'; ++text_copy) *text_copy = tolower(*text_copy);

	while (i <= number) {
		char* tab_copy = malloc(strlen(tab[i].author) + 1);
		strcpy(tab_copy, tab[i].author);
		char* cos = tab_copy;
		for (; *tab_copy; ++tab_copy) *tab_copy = tolower(*tab_copy);
		if ((strstr(tab[i].author, text) != NULL)) {
			gtk_list_store_append(list, &iter);
			gtk_list_store_set(list, &iter, 0, tab[i].title, 1, tab[i].author, 2, tab[i].year, 3, tab[i].format, 4, tab[i].filePath, 5, tab[i].comment, -1);
		}
		i++;
	}
}

//Checks if file exists
int cfileexists(const char* filename) {
	/* try to open file to read */
	FILE* file;
	if (file = fopen(filename, "r")) {
		fclose(file);
		return 1;
	}
	return 0;
}

//Create new array and make List from it
void create(GtkWidget* treeview) {
	GtkListStore* list;
	GtkTreeIter ii;
	list = gtk_list_store_new(6, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
	gtk_list_store_clear(list);
	Book tab[1000];
	createStruct(tab);
	createList(tab, list, &ii);
	gtk_tree_view_set_model(GTK_TREE_VIEW(treeview), GTK_TREE_MODEL(list));
}

//Rewrite files without removed element, creates then new array and List from it
void removeLine(GtkWidget* treeview, gpointer data) {
	GtkTreeSelection* sel;
	GtkTreeModel* model;
	GtkTreeIter selected;

	Book tab[1000];
	createStruct(tab);

	int x = lines();

	FILE* file1;
	file1 = fopen("titles.txt", "w+");
	FILE* file2;
	file2 = fopen("authors.txt", "w+");
	FILE* file3;
	file3 = fopen("years.txt", "w+");
	FILE* file4;
	file4 = fopen("formats.txt", "w+");
	FILE* file5;
	file5 = fopen("filePaths.txt", "w+");
	FILE* file6;
	file6 = fopen("comments.txt", "w+");

	fclose(file1);
	fclose(file2);
	fclose(file3);
	fclose(file4);
	fclose(file5);
	fclose(file6);

	gchar* a;
	gchar* b;
	gchar* c;
	gchar* d;
	gchar* e;
	gchar* f;

	sel = gtk_tree_view_get_selection(GTK_TREE_VIEW(treeview));

	if (gtk_tree_selection_get_selected(sel, &model, &selected)) {
		gtk_tree_model_get(model, &selected, 0, &a, 1, &b, 2, &c, 3, &d, 4, &e, 5, &f, -1);
		int i = 0;
		while (i <= x) {
			if ((strcmp(tab[i].title, a) != 0) || (strcmp(tab[i].author, b) != 0) || (strcmp(tab[i].year, c) != 0) || (strcmp(tab[i].format, d) != 0) || (strcmp(tab[i].filePath, e) != 0) || (strcmp(tab[i].comment, f) != 0)) {
				addToFile("titles.txt", tab[i].title);
				addToFile("titles.txt", "\n");
				addToFile("authors.txt", tab[i].author);
				addToFile("authors.txt", "\n");
				addToFile("years.txt", tab[i].year);
				addToFile("years.txt", "\n");
				addToFile("formats.txt", tab[i].format);
				addToFile("formats.txt", "\n");
				addToFile("filePaths.txt", tab[i].filePath);
				addToFile("filePaths.txt", "\n");
				addToFile("comments.txt", tab[i].comment);
				addToFile("comments.txt", "\n");
			}
			i++;
		}
	}

	create(treeview);
}

//Error dialog about missing file in path location
void error_dialog(GtkWindow* okno)
{
	GtkWidget* dialog;
	dialog = gtk_message_dialog_new(GTK_WINDOW(okno), GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_ERROR, GTK_BUTTONS_OK, "Error ocurred: %s", "can't open the file!");
	gtk_window_set_title(GTK_WINDOW(dialog), "Error");
	gtk_dialog_run(GTK_DIALOG(dialog));
	gtk_widget_destroy(dialog);
}

