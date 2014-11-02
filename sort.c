#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXCHAR 65

int main(int argc, char *argv[])
{
	char line[MAXCHAR];
	/*char *lines = NULL;*/
	char lines[2];
	char hello[] = "hello";
	int i;

	FILE *fp = fopen(argv[1], "r");

	while(fgets(line, MAXCHAR, fp) != NULL)
	{
		
		/*lines = realloc(lines, MAXCHAR);*/



		






	}





	return 0;
}