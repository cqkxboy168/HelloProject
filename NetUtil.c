/*
* @desc:判断大小端
* @param:null
* @return: 1,big endian
*/
int byteorder()
{
	union
	{
		short value;
		char union_bytes[sizeof(short)];
	}test;
	test.value=0x0102;
	if(test.union_bytes[0]==1 && test.union_bytes[1]==2)
	{
		return 1;
	}
	else
	  return 0;
}

/*
* @desc:设置非阻塞
* @param:文件描述符
* @return:0成功
*/
int setNonblocking(int fd,int option)
{
	int old_value = fcntl(fd,F_GETFL);//获取文件描述符的状态标志
	int new_value = (option==1)?(old_value | O_NONBLOCK):0;
	int rc=fcntl(fd,F_SETFL,new_value);
	if(rc<0)
		return -1;
	return 0;
}

/*
* @desc:设置TCP_NODELAY，禁用nagle算法
* @param:nodealy为1，禁用nagle,nodelay为0，启用nagle;
* @return:
*/
int setNodelay(int fd,int option)
{
	int val=(option==1)?1:0;
	int rc;
	rc=setsockopt(fd,IPPROTO_TCP,TCP_NODELAY,(char*)&val;sizeof(val));
	if(rc<0)
		return -1;
	return 0;
}

/*
* @desc:设置守护进程
* @param:null
* @return:null
* @other:进程->进程组->会话（比如在一个bash上执行ps.less等命令都是同一个会话）
*/

void do_daemonise()
{
	int rc;
	rc=fork();
	if(rc<0)
	{
		printf("fork failed\n");
		exit(-1);
  }
  if( rc>0) //父进程退出
  	exit(0);
  /*守护进程无终端交互，关闭标准输入，输出*/
  close( 0 );
  close( 1 );
  close( 2 );	
  umask( 0 );//重设掩码
  rc=setsid();//重建会话
  if(rc<0)
  {
  	printf("can not creat new session\n");
  	exit(-1);
  }
  rc=chdir("/");//切换根目录
  if(rc<0)
  {
  	printf("change dir failed\n");
  	exit(-1);
  }
}

/*
* @desc：测试用户ID（UID），实际用户ID(EUID)
* @param:null
* @return:null
* @other:EUID的目的方便资源访问，chown root:root test_uid,chmod +s test_uid.比如su命令
*/
void test_euid()
{
	uid_t uid=getuid(); //
	uid_t euid=geteuid();//设置了chmod+s标志，EUID为root，程序以root用户运行
}

