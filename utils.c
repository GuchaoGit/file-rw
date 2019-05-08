#include "utils.h"

int get_command_result(const char *sys_line, char **result)
{
	char buf_ps[512];
	char *rst;
	FILE *ptr;
	int line = 0;
	int curlen = 0;
	if ((ptr = popen(sys_line, "r")) != NULL) {
		while (fgets(buf_ps, 512, ptr) != NULL) {
			if (!line) {
				curlen = 512 * sizeof(char);
				rst = malloc(curlen);
				if (rst == NULL) {
					printf
					    ("Error - unable to allocate required memory\n");
					return -1;
				} else {
					strcpy(rst, buf_ps);
				}

			} else {
				if ((strlen(rst) + strlen(buf_ps)) >
				    curlen) {
					rst =
					    realloc(rst,
						    curlen +
						    512 * sizeof(char));
					if (rst == NULL) {
						printf
						    ("Error - unable to allocate required memory\n");
						return -1;
					} else {
						curlen =
						    curlen +
						    512 * sizeof(char);
					}
					printf
					    ("realloc memory ,current len is %d\n",
					     curlen);

				}
				strcat(rst, buf_ps);
			}
#ifdef DEBUG
			printf("result is :%s`\n", buf_ps);
#endif
			line++;
		}
		*result = rst;
		pclose(ptr);
		ptr = NULL;
	} else {
		printf("popen %s error\n", sys_line);
		return -1;
	}

	return 0;
}

int get_mac(const char *dev_name, char **mac)
{

	int sd = 0;
	char macstr[MAC_SIZE];

	struct ifreq ifr;


	memset(&ifr, 0, sizeof(struct ifreq));
	sd = socket(AF_INET, SOCK_STREAM, 0);
	if (sd < 0) {
#ifdef DEBUG
		printf("get %s mac address socket creat error\n",
		       dev_name);
#endif
		return -1;
	}

	strncpy(ifr.ifr_name, dev_name, sizeof(ifr.ifr_name) - 1);

	if (ioctl(sd, SIOCGIFHWADDR, &ifr) < 0) {
#ifdef DEBUG
		printf("get %s mac address error\n", dev_name);
#endif
		close(sd);
		return -1;
	}

	snprintf(macstr, MAC_SIZE, "%02x:%02x:%02x:%02x:%02x:%02x",
		 (unsigned char) ifr.ifr_hwaddr.sa_data[0],
		 (unsigned char) ifr.ifr_hwaddr.sa_data[1],
		 (unsigned char) ifr.ifr_hwaddr.sa_data[2],
		 (unsigned char) ifr.ifr_hwaddr.sa_data[3],
		 (unsigned char) ifr.ifr_hwaddr.sa_data[4],
		 (unsigned char) ifr.ifr_hwaddr.sa_data[5]);


	close(sd);
#ifdef DEBUG
	printf("dev_name: %s, mac: %s \n", dev_name, macstr);
#endif
	*mac = strdup(macstr);
	if(*mac == NULL){
#ifdef DEBUG
		printf("strdup error\n");
#endif
			return -1;
	}
	return 0;
}
