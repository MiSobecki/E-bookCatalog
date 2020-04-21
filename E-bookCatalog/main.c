#include "Functions.h"
#include "Add_window.h"

GtkWidget* treeview;
Book tab[1000];
GtkWidget* removee;
GtkWidget* open;
GtkWidget* window;

void opening(GtkWidget*, gpointer);
void selectionChange(GtkTreeSelection*, GtkListStore*);
void createTitle(GtkWidget*, gpointer);
void createAuthor(GtkWidget*, gpointer);


int main(int argc, char* argv[]) {

    GtkListStore* magazineList;
    GtkTreeIter iter;

    magazineList = gtk_list_store_new(6, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

    createStruct(tab);

    createList(tab, magazineList, &iter);

    GtkWidget* hbox;
    GtkWidget* container;
    GtkWidget* box;
    GtkWidget* hseparator;

    GtkWidget* add;
    GtkWidget* searchTitle;
    GtkWidget* searchAuthor;
    GtkWidget* reset;

    GtkWidget* scrolledWindow;
    GtkWidget* sumBox;

    GtkTreeViewColumn* column1;
    GtkTreeViewColumn* column2;
    GtkTreeViewColumn* column3;
    GtkTreeViewColumn* column4;
    GtkTreeViewColumn* column5;
    GtkTreeViewColumn* column6;
    GtkTreeViewColumn* cell1;
    GtkTreeViewColumn* cell2;
    GtkTreeViewColumn* cell3;
    GtkTreeViewColumn* cell4;
    GtkTreeViewColumn* cell5;
    GtkTreeViewColumn* cell6;

    GtkWidget* titleBox;
    GtkWidget* authorBox;
    GtkWidget* entry1;
    GtkWidget* entry2;

    GtkTreeSelection* sel;

    GdkPixbuf* image;
    GError* error = NULL;
    GtkWidget* obraz;

    GdkPixbuf* image2;
    GtkWidget* obraz2;

    GdkPixbuf* image3;
    GtkWidget* obraz3;

    GdkPixbuf* image4;
    GtkWidget* obraz4;

    gtk_init(&argc, &argv);

    g_object_set(gtk_settings_get_default(), "gtk-application-prefer-dark-theme", TRUE, NULL);


    reset = gtk_button_new();
    add = gtk_button_new();
    removee = gtk_button_new();
    open = gtk_button_new();

    image = gdk_pixbuf_new_from_file_at_scale("refresh2.png", 50, 50, 1, error);
    obraz = gtk_image_new_from_pixbuf(image);
    image2 = gdk_pixbuf_new_from_file_at_scale("add.png", 50, 50, 1, error);
    obraz2= gtk_image_new_from_pixbuf(image2);
    image3 = gdk_pixbuf_new_from_file_at_scale("remove.png", 50, 50, 1, error);
    obraz3 = gtk_image_new_from_pixbuf(image3);
    image4 = gdk_pixbuf_new_from_file_at_scale("open1.png", 70, 60, 1, error);
    obraz4 = gtk_image_new_from_pixbuf(image4);


    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_default_size(GTK_WINDOW(window), 1000, 600);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    gtk_container_set_border_width(GTK_CONTAINER(window), 6);

    gtk_window_set_title(GTK_WINDOW(window), "E-book Catalog");

    hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 1);

    container = gtk_fixed_new();

    gtk_fixed_put(GTK_FIXED(container), hbox, 0, 0);

    box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 1);
    gtk_box_pack_start(GTK_BOX(box), container, TRUE, FALSE, 0);

    scrolledWindow = gtk_scrolled_window_new(NULL, NULL);
    gtk_container_set_border_width(GTK_CONTAINER(scrolledWindow), 8);

    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scrolledWindow), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
    gtk_scrolled_window_set_min_content_height(GTK_SCROLLED_WINDOW(scrolledWindow), 500);

    hseparator = gtk_separator_new(GTK_ORIENTATION_HORIZONTAL);

    sumBox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    gtk_box_pack_start(GTK_BOX(sumBox), box, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(sumBox), hseparator, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(sumBox), scrolledWindow, FALSE, TRUE, 0);

    treeview = gtk_tree_view_new();

    gtk_container_add(GTK_CONTAINER(scrolledWindow), treeview);
    gtk_tree_view_set_model(GTK_TREE_VIEW(treeview), GTK_TREE_MODEL(magazineList));
    g_object_unref(G_OBJECT(magazineList));

    gtk_container_add(GTK_CONTAINER(window), sumBox);

    column1 = gtk_tree_view_column_new();
    column2 = gtk_tree_view_column_new();
    column3 = gtk_tree_view_column_new();
    column4 = gtk_tree_view_column_new();
    column5 = gtk_tree_view_column_new();
    column6 = gtk_tree_view_column_new();

    cell1 = gtk_cell_renderer_text_new();
    cell2 = gtk_cell_renderer_text_new();
    cell3 = gtk_cell_renderer_text_new();
    cell4 = gtk_cell_renderer_text_new();
    cell5 = gtk_cell_renderer_text_new();
    cell6 = gtk_cell_renderer_text_new();

    gtk_tree_view_column_set_title(column1, "Title");
    gtk_tree_view_column_set_title(column2, "Author");
    gtk_tree_view_column_set_title(column3, "Year");
    gtk_tree_view_column_set_title(column4, "Format");
    gtk_tree_view_column_set_title(column5, "File Path");
    gtk_tree_view_column_set_title(column6, "Comment");
    gtk_tree_view_column_pack_start(column1, cell1, TRUE);
    gtk_tree_view_column_pack_start(column2, cell2, TRUE);
    gtk_tree_view_column_pack_start(column3, cell3, TRUE);
    gtk_tree_view_column_pack_start(column4, cell4, TRUE);
    gtk_tree_view_column_pack_start(column5, cell5, TRUE);
    gtk_tree_view_column_pack_start(column6, cell6, TRUE);
    gtk_tree_view_column_add_attribute(column1, GTK_CELL_RENDERER(cell1), "text", 0);
    gtk_tree_view_column_add_attribute(column2, GTK_CELL_RENDERER(cell2), "text", 1);
    gtk_tree_view_column_add_attribute(column3, GTK_CELL_RENDERER(cell3), "text", 2);
    gtk_tree_view_column_add_attribute(column4, GTK_CELL_RENDERER(cell4), "text", 3);
    gtk_tree_view_column_add_attribute(column5, GTK_CELL_RENDERER(cell5), "text", 4);
    gtk_tree_view_column_add_attribute(column6, GTK_CELL_RENDERER(cell6), "text", 5);
    gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column1);
    gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column2);
    gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column3);
    gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column4);
    gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column5);
    gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column6);

    gtk_tree_view_column_set_expand(column1, TRUE);
    gtk_tree_view_column_set_expand(column2, TRUE);
    gtk_tree_view_column_set_expand(column5, TRUE);
    gtk_tree_view_column_set_expand(column6, TRUE);

    gtk_tree_view_column_set_sort_column_id(column1, 0);
    gtk_tree_view_column_set_sort_column_id(column2, 1);
    gtk_tree_view_column_set_sort_column_id(column3, 2);
    gtk_tree_view_column_set_sort_column_id(column4, 3);
    gtk_tree_view_column_set_sort_column_id(column5, 4);
    gtk_tree_view_column_set_sort_column_id(column6, 5);

    titleBox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    authorBox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    entry1 = gtk_entry_new();
    entry2 = gtk_entry_new();

    gtk_button_set_image(GTK_BUTTON(add), obraz2);
    gtk_widget_set_size_request(add, 180, 35);
    g_signal_connect(G_OBJECT(add), "clicked", G_CALLBACK(add_window), NULL);
    gtk_button_set_image(GTK_BUTTON(removee), obraz3);
    gtk_widget_set_size_request(removee, 180, 35);
    gtk_widget_set_sensitive(removee, FALSE);
    g_signal_connect_swapped(removee, "clicked", G_CALLBACK(removeLine), treeview);
    searchTitle = gtk_button_new_with_label("Search by title");
    gtk_widget_set_size_request(searchTitle, 180, 35);
    g_signal_connect_swapped(searchTitle, "clicked", G_CALLBACK(createTitle), entry1);
    searchAuthor = gtk_button_new_with_label("Search by author");
    gtk_widget_set_size_request(searchAuthor, 180, 35);
    g_signal_connect_swapped(searchAuthor, "clicked", G_CALLBACK(createAuthor), entry2);
    gtk_button_set_image(GTK_BUTTON(reset), obraz);
    gtk_widget_set_size_request(reset, 180, 35);
    g_signal_connect_swapped(reset, "clicked", G_CALLBACK(create), treeview);
    gtk_button_set_image(GTK_BUTTON(open), obraz4);
    gtk_widget_set_size_request(open, 180, 35);
    gtk_widget_set_sensitive(open, FALSE);
    g_signal_connect_swapped(open, "clicked", G_CALLBACK(opening), treeview);

    gtk_box_pack_start(GTK_BOX(titleBox), searchTitle, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(titleBox), entry1, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(authorBox), searchAuthor, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(authorBox), entry2, FALSE, FALSE, 0);

    gtk_box_pack_start(GTK_BOX(hbox), add, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(hbox), removee, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(hbox), titleBox, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(hbox), authorBox, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(hbox), reset, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(hbox), open, FALSE, FALSE, 0);

    gtk_tree_view_set_grid_lines(treeview, GTK_TREE_VIEW_GRID_LINES_VERTICAL);


    sel = gtk_tree_view_get_selection(GTK_TREE_VIEW(treeview));
    g_signal_connect(sel, "changed", G_CALLBACK(selectionChange), magazineList);

    g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);

    gtk_widget_show_all(window);

    gtk_main();

    return 0;
}

//Open book
void opening(GtkWidget* treeview, gpointer data) {
    GtkTreeSelection* sel;
    GtkTreeModel* model;
    GtkTreeIter selected;

    sel = gtk_tree_view_get_selection(GTK_TREE_VIEW(treeview));

    gchar* a;
    gchar* b;
    gchar* c;
    gchar* d;
    gchar* e;
    gchar* f;


    if (gtk_tree_selection_get_selected(sel, &model, &selected)) {
        gtk_tree_model_get(model, &selected, 0, &a, 1, &b, 2, &c, 3, &d, 4, &e, 5, &f, -1);
        if (cfileexists(e)) system(e);
        else error_dialog(window);
    }

}

//Activation of buttons
void selectionChange(GtkTreeSelection* sel, GtkListStore* list)
{
    GtkTreeIter selected;

    if (gtk_tree_selection_get_selected(sel, NULL, &selected))
    {
        gtk_widget_set_sensitive(removee, TRUE);
        gtk_widget_set_sensitive(open, TRUE);
    }
    else
    {
        gtk_widget_set_sensitive(removee, FALSE);
        gtk_widget_set_sensitive(open, FALSE);
    }
}


//Create new array and make List where searched Title is
void createTitle(GtkWidget* entry, gpointer data) {
    GtkListStore* list;
    GtkTreeIter ii;
    list = gtk_list_store_new(6, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
    gtk_list_store_clear(list);
    Book tab[1000];
    createStruct(tab);
    gchar* text = gtk_entry_get_text(GTK_ENTRY(entry));
    createTitleList(tab, list, &ii, text);
    gtk_tree_view_set_model(GTK_TREE_VIEW(treeview), GTK_TREE_MODEL(list));
}

//Create new array and make List where searched Author is
void createAuthor(GtkWidget* entry, gpointer data) {
    GtkListStore* list;
    GtkTreeIter ii;
    list = gtk_list_store_new(6, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
    gtk_list_store_clear(list);
    Book tab[1000];
    createStruct(tab);
    gchar* text = gtk_entry_get_text(GTK_ENTRY(entry));
    createAuthorList(tab, list, &ii, text);
    gtk_tree_view_set_model(GTK_TREE_VIEW(treeview), GTK_TREE_MODEL(list));
}

