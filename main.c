#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[])
{

	FILE *fp = NULL;
	char buff[255];
	fp = fopen("./config.ini", "r");
#ifndef DDD
	printf("未找到 DDD\n");
#endif
#if 0
	int rst = -1;
	rst = fscanf(fp, "%s", buff);
	printf("read content is :%s\nsize is:%ld\nrst is:%d\n", buff,
	       strlen(buff), rst);

	rst = -1;
	rst = fscanf(fp, "%s", buff);
	printf("read content is :%s\nsize is:%ld\nrst is:%d\n", buff,
	       strlen(buff), rst);


	rst = -1;
	rst = fscanf(fp, "%s", buff);
	printf("read content is :%s\nsize is:%ld\nrst is:%d\n", buff,
	       strlen(buff), rst);


	rst = -1;
	rst = fscanf(fp, "%s", buff);
	printf("read content is :%s\nsize is:%ld\nrst is:%d\n", buff,
	       strlen(buff), rst);


	rst = -1;
	rst = fscanf(fp, "%s", buff);
	printf("read content is :%s\nsize is:%ld\nrst is:%d\n", buff,
	       strlen(buff), rst);


	rst = -1;
	rst = fscanf(fp, "%s", buff);
	printf("read content is :%s\nsize is:%ld\nrst is:%d\n", buff,
	       strlen(buff), rst);

#endif


#if 1
	while (fscanf(fp, "%s", buff) == 1) {
		printf("1: %s\n", buff);

	}
#endif
	fclose(fp);


	return 0;
}
