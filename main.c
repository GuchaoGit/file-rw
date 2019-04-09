#include <stdio.h>
#include <string.h>
#include "custom_math.h"
#define MAX(x,y) ((x)>(y) ? (x) : (y))

int main(int argc, char *argv[])
{

	FILE *fp = NULL;
	char buff[255];
	fp = fopen("./config.ini", "r");
#ifdef DEBUG
	printf("已开启 -DDEBUG\n");
	printf("File :%s\n", __FILE__ );
	printf("Date :%s\n", __DATE__ );
	printf("Time :%s\n", __TIME__ );
	printf("Line :%d\n", __LINE__ );
	printf("ANSI :%d\n\n", __STDC__ );
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
	int i = 0;
	while (fscanf(fp, "%s", buff) == 1) {
		i++;
		printf("%d: %s\n",i, buff);

	}
#endif
	fclose(fp);


	printf("Max between 20 and 10 is %d\n", MAX(10, 20));
	printf("Average of 5, 10, 15 = %f\n", average(3, 5,10,15));
	return 0;
}
