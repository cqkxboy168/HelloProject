#include"comdef.h"
#include"debug.h"

int main(int argv,char*args[])
{
	 print_log(LEVEL_INFO, "infointpl - param is NULL");
	 print_log(LEVEL_NOTICE, "%s = %d","my fpid is",getppid());
	 DBG("%s = %d", "my pid is", getpid());
}