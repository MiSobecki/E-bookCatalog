#include "Number_of_lines.h"

//Count lines in the file
int lines() {
	FILE* file;
	file = fopen("titles.txt", "r");
	char znak;
	int number = -1;
	while ((znak = getc(file)) != EOF)
	{
		if (znak == '\n')
			++number;
	}
	fclose(file);
	return number;
}