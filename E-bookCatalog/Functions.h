#ifndef FUNCTIONS

#include "Number_of_lines.h"

#define FUNCTIONS

//Stuct with informations about the book
struct books {
    char title[100];
    char author[100];
    char year[6];
    char format[6];
    char filePath[100];
    char comment[100];
};

typedef struct books Book;

void createList(Book*, GtkListStore*, GtkTreeIter*);
void addToFile(const char*, const gchar*);
void createStruct(Book*);
void createTitleList(Book*, GtkListStore*, GtkTreeIter*, gchar*);
void createAuthorList(Book*, GtkListStore*, GtkTreeIter*, gchar*);
void create(GtkWidget*);
int cfileexists(const char*);
void removeLine(GtkWidget*, gpointer);
void error_dialog(GtkWindow*);

#endif
