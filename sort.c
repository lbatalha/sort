#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXCHAR 65

int main(int argc, char *argv[])
{
	char line[MAXCHAR];
	char *lines = NULL;
	FILE *fp;

/*	char lines[2];
	char hello[] = "hello";*/

	int i = 1;
	int linecount=0;

	if(argc == 2)
		fp = fopen(argv[1], "r");
	else
		return(1);

	while(fgets(line, MAXCHAR, fp) != NULL)
	{
		
		linecount = linecount + 1;

		lines = realloc(lines, MAXCHAR * linecount);

		strcpy(lines + MAXCHAR * linecount, line);
				
	}


	for(i=0; i < linecount; i++)
	{
		strcpy(line, lines + MAXCHAR*i);
		printf("%s", line);
	}

	fclose(fp);
	free(lines);

	return 0;
}