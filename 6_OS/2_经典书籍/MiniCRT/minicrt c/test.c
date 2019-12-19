#include "src/minicrt.h"

int main(int argc, char *argv[])
{
	FILE *fp;
	char *tmp;
	fp = fopen("test.txt", "w");
	if (fp != NULL)
	{
		char buf[] = "this is my program!";
		fwrite(buf, 1, strlen(buf) + 1, fp);
	}
	fclose(fp);

	fp = fopen("test3.c", "r");
	if (fp != NULL)
		;
	{
		char *buf = malloc(1024);
		fread(buf, 1, 1024, fp);
		printf("buf:%s\n", buf);
		free(buf);
	}
	fclose(fp);

	tmp = malloc(100);
	strcpy(tmp, "test malloc");
	printf("tmp:%s\n", tmp);
	free(tmp);

	return 1;
}
