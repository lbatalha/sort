#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>



int charcmp(const void *a, const void  *b)
{
	return strcmp( * (char * const *) a, * (char * const *) b);
}

int main(int argc, char *argv[])
{
	char *line;

	char **array = NULL;

	FILE *fp;
	
	int i = 1;
	int linecount = 0;
	int MAXCHAR = 0;
	int linelength = 0;
	int lastlength = 0;

	if(argc < 2)
		fp = stdin;
	else
		fp = fopen(argv[1], "r");


	while(fgetsreturn != NULL)
	{
		MAXCHAR = 0;
	
		while(line[linelength-1] != '\n' && !feof(fp))
		{
			MAXCHAR += BUFSIZ;
			line = realloc(line, MAXCHAR);

			fgets(line + (linelength-1), MAXCHAR, fp);

			linelength = strlen(line);
		}

		linecount = linecount + 1;
		array = realloc(array, sizeof(char*) * linecount);
		array[linecount-1] = malloc(MAXCHAR);		
		strcpy(array[linecount-1], line);
	}

	qsort(array, linecount, sizeof(char*), charcmp);

	for(i=0; i < linecount; i++)
	{
		printf("%s", array[i]);
	}

	fclose(fp);
	free(array);
	

	return 0;
}