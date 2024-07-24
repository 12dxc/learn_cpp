#ifndef _PUB_H
#define _PUB_H
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <strings.h>
#include <ctype.h>
char *get_mime_type(char *name);
int get_line(int sock, char *buf, int size);
int hexit(char c);//16쏵齡瘻10쏵齡
void strencode(char* to, size_t tosize, const char* from);//긍쯤
void strdecode(char *to, char *from);//썩쯤
#endif

