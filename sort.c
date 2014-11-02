#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXCHAR 65

int main(int argc, char *argv[])
{
	char line[MAXCHAR];
	char *lines = NULL;
	char **array = NULL;

	FILE *fp;
	
	int i = 1;
	int linecount = 0;
	


/*	char hello[] = "hello";
	char bye[] = "bye";
*/
	if(argc == 2)
		fp = fopen(argv[1], "r");
	else
		return(1);

	while(fgets(line, MAXCHAR, fp) != NULL)
	{
		
		linecount = linecount + 1;
		array[linecount-1] = malloc(MAXCHAR);		
		strcpy(array[linecount-1], line);

	}

	qsort(array, linecount, sizeof(char*), (__compar_fn_t)strcmp);
/*
	char **array;
	array = malloc(sizeof(char*) * 2);
	array[0] = hello;
	array[1] = bye;

	__compar_fn_t qsort_strcmp = (__compar_fn_t)strcmp;
	
	qsort(array, linecount, sizeof(char*), (__compar_fn_t)strcmp);

	printf("1: %s 2:%s\n", array[0], array[1]);
*/
	for(i=0; i < linecount; i++)
	{
		printf("%d: %p %s", i, array[i], array[i]);
	}

	fclose(fp);
	free(array);
	free(lines);

	return 0;
}