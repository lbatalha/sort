#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXCHAR 65

int main(int argc, char *argv[])
{
	char line[MAXCHAR];
	char *lines = NULL;
	char *lines_origin;

/*	char lines[2];
	char hello[] = "hello";*/

	int i = 1;
	int linecount=0;


	FILE *fp = fopen(argv[1], "r");

	while(fgets(line, MAXCHAR, fp) != NULL)
	{
		
		lines = realloc(lines, MAXCHAR * linecount);

		strcpy(lines + MAXCHAR * linecount, line);
		
		linecount = linecount + 1;
		
	}


	for(i=0; i < linecount; i++)
	{
		strcpy(line, lines + MAXCHAR*i;);
		printf("%s\n", line);
	}

	fclose(fp);

	return 0;
}