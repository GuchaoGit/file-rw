#ifndef UTILLS_H
#define UTILLS_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <net/if.h>
#define MAC_SIZE    18
extern int get_command_result(const char *sys_line,char **result);
extern int get_mac(const char *dev_name,char **mac);
#endif
