#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXCHAR 65

int main(int argc, char *argv[])
{
	char line[MAXCHAR];
	char *lines = NULL;
/*	char lines[2];
	char hello[] = "hello";*/
	int i = 1;
	int linecount=0;

	FILE *fp = fopen(argv[1], "r");

	while(fgets(line, MAXCHAR, fp) != NULL)
	{
		linecount = linecount + 1;

		lines = realloc(lines, MAXCHAR);

		strcpy(lines, line);

		lines = lines + MAXCHAR;
		
	}


	for(i=0; i < linecount; i++)
	{
		lines = lines + MAXCHAR*i;
		strcpy(line, lines);
		printf("%s\n", line);
	}

	fclose(fp);

	return 0;
}