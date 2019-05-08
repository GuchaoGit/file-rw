#include <stdio.h>
#include <string.h>
#include "custom_math.h"
#include "utils.h"
#include "cJSON.h"
#define MAX(x,y) ((x)>(y) ? (x) : (y))

int main(int argc, char *argv[])
{

	FILE *fp = NULL;
	char buff[255];
	fp = fopen("./config.ini", "r");
#ifdef DEBUG
	printf("已开启 -DDEBUG\n");
	printf("File :%s\n", __FILE__);
	printf("Date :%s\n", __DATE__);
	printf("Time :%s\n", __TIME__);
	printf("Line :%d\n", __LINE__);
	printf("ANSI :%d\n\n", __STDC__);
#endif

#if 1
	int i = 0;
	while (fscanf(fp, "%s", buff) == 1) {
		i++;
		printf("%d: %s\n", i, buff);

	}
#endif
	fclose(fp);


	printf("Max between 20 and 10 is %d\n", MAX(10, 20));
	printf("Average of 5, 10, 15 = %f\n", average(3, 5, 10, 15));

	printf("********************************************\n");
	char *sys_line = "ls -lhi";
	char *result = NULL;
	get_command_result(sys_line, &result);

	printf("%s :\nresult length = %ld\n%s\n", sys_line, strlen(result),
	       result);

	free(result);

	printf("********************************************\n");
	printf("test cJSON\n");
	cJSON *root = NULL;
	cJSON *format = NULL;
	cJSON *brother = NULL;
	root = cJSON_CreateObject();
	cJSON_AddStringToObject(root, "name", "Jack (\"Bee\") Nimble");
	cJSON_AddItemToObject(root, "format", format =
			      cJSON_CreateObject());
	cJSON_AddItemToObject(root, "brother", brother =
			      cJSON_CreateArray());

	/* 普通对象中插入对象和值 */
	{
		cJSON_AddStringToObject(format, "type", "rect");
		cJSON_AddFalseToObject(format, "interlace");
		cJSON_AddNumberToObject(format, "width", 1920);
		cJSON_AddNumberToObject(format, "height", 1920.11);
		cJSON_AddBoolToObject(format, "flag", 1);
	}

	/* 数组中插入对象和值 */
	{
		cJSON_AddItemToArray(brother, cJSON_CreateString("Lea/s"));
		cJSON_AddItemToArray(brother, cJSON_CreateString("Boo"));
	}

	char *cj_str = cJSON_Print(root);
	printf("%s\n\n", cj_str);
	free(cj_str);
	char *cj_str_unformat = cJSON_PrintUnformatted(root);
	printf("%s\n\n", cj_str_unformat);
        free(cj_str_unformat);

	/* *
	 *      * cjson使用完成之后需要释放空间
	 *           */
	cJSON_Delete(root);

	printf("********************************************\n");

	char *mac=NULL;
	get_mac("ens33",&mac);
	printf("ens33 mac is:%s\n",mac);
	free(mac);
	printf("********************************************\n");

	return 0;
}
