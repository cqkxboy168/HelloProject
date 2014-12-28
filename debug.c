#include<stdarg.h>
void print_log(int level,const char *fmt, ...)
{
	va_list ap;
	va_start(ap,fmt);
	char msg[100];
	vsnprintf(msg,sizeof(msg),fmt,ap);
	va_end(ap);
	printf("%s\n",msg);
}