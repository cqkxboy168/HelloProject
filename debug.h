#ifndef __DEBUG_H__
#define __DEBUG_H__

#include "comdef.h"
/*log level*/
#define LEVEL_DEBUG  0
#define LEVEL_INFO 1
#define LEVEL_NOTICE 2
#define LEVEL_WARNING 3
#define LEVEL_LOG_RAW (1<<10) /*without timestamp*/

#define DBG(args...) \
 print_log(LEVEL_DEBUG,##args) /*define中有##相当于传参*/

/**
 *
 *
 *
 */
void print_log(int level,const char *fmt,...);

#endif