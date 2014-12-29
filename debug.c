#include "debug.h"
void print_log(int level,const char *fmt, ...)
{
	int log_level=0;
	int log_to_stdout=1;
	const char *c[]={"D","I","N","W"};
	
	int log_to_file=1;
	int rawmode=(level& LEVEL_LOG_RAW);
	level&=0xff;/*clear flag*/
	
	va_list ap;
	va_start(ap,fmt);
	char msg[100];
	vsnprintf(msg,sizeof(msg),fmt,ap);
	va_end(ap);
	//printf("%s\n",msg);
	
	FILE *fp=NULL;
	
	if(log_to_file)
	{
		char logpath[100]={ 0 };
		snprintf(logpath,sizeof(logpath),"%s","/tmp/hellopro.log");
		fp=fopen(logpath,"a");
		if(fp==NULL)
		{
		}
	}
	if(rawmode)
	{
		fprintf(fp,"%s",msg);
	}
	else
	{
		int offset;
		struct timeval tv;
		char tbuf[64]={ 0 };
		gettimeofday(&tv,NULL);
		offset=strftime(tbuf,sizeof(tbuf),"%Y-%m-%d %H:%M:%S,",localtime(&tv.tv_sec));//write s into buf.
		snprintf(tbuf+offset,sizeof(tbuf)-offset,"%03d",tv.tv_usec/1000);//write ms into buf
		if(level>log_level && log_to_file && fp!=NULL)
		{
			fprintf(fp,"%d|%s|%s|%s\n",getpid(),c[level],tbuf,msg);
		}
		if(log_to_stdout)
		{
	    fprintf(stdout,"%d|%s|%s|%s\n",getpid(),c[level],tbuf,msg);
		}
	}
	if(fp!=NULL) fflush(fp);
	if(log_to_file && fp!=NULL) fclose(fp);
}