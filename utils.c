#include "utils.h"

int get_command_result(const char *sys_line,char **result)
{
	char buf_ps[512];
	char *rst;
	FILE *ptr;
	int line = 0;
	int curlen = 0;
	if((ptr = popen(sys_line,"r"))!=NULL)
	{
		while(fgets(buf_ps,512,ptr)!=NULL){
			if(!line){
				curlen = 512*sizeof(char);
				rst = malloc(curlen);
				if(rst == NULL){
					printf("Error - unable to allocate required memory\n");
					return -1;
				}else{
					strcpy(rst,buf_ps);
				}
			
			}
			else
			{
				if((strlen(rst)+strlen(buf_ps)) > curlen )
				{
					rst = realloc(rst,curlen + 512*sizeof(char));
					if(rst == NULL){
						 printf("Error - unable to allocate required memory\n");
						 return -1;
					}else{
						curlen =curlen + 512*sizeof(char);
					}
					printf("realloc memory ,current len is %d\n",curlen);

				}
				strcat(rst,buf_ps);
			}
#ifdef DEBUG
			printf("result is :%s`\n",buf_ps);
#endif
			line++;
		}	
		*result = rst;
		pclose(ptr);
		ptr =NULL;
	}
	else
	{
		printf("popen %s error\n",sys_line);
		return -1;
	}

	return 0;
}
