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
	char *line = NULL;
	char *fgetsreturn = NULL;
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


	
	do{
		MAXCHAR = 0;
		/*printf("Start: %d\n", linelength);*/
		line = NULL;
		do{
			MAXCHAR += 4;
			line = realloc(line, MAXCHAR);
			
			fgetsreturn = fgets(line + lastlength, MAXCHAR, fp);
			
			linelength = strlen(line);
			lastlength = linelength-1;

		}while(line[lastlength] != '\n' && !feof(fp));

		linecount = linecount + 1;
		array = realloc(array, sizeof(char*) * linecount);
		array[linecount-1] = malloc(MAXCHAR);		
		strcpy(array[linecount-1], line);

	}while(fgetsreturn != NULL);

	qsort(array, linecount, sizeof(char*), charcmp);

	for(i=0; i < linecount; i++)
	{
		printf("%s", array[i]);
	}

	fclose(fp);
	free(array);
	

	return 0;
}