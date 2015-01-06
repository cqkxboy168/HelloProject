/*
* @desc:设置信号处理函数
* @param: 
* @return:null
* @other:use like,addsig( SIGURG, sig_urg_hldr );
*/

void addsig( int sig,void (*sig_handler)(int ) )
{
	struct sigaction sa;
	memset( &sa,'\0',sizeof(sa));
	sa.sa_handler = sig_handler;
	sa.sa_flags |=SA_RESTART;
	sigfillset( &sa.sa_mask);
	assert ( sigaction (sig,&sa,NULL) !=  -1 );
}
/*
* @desc:处理带外数据，SIG_URG
* @param:SIG
* @return:null
*/
void sig_urg_hldr(int sig)
{
	char buffer[1024];
	memset(buffer,'\0',1024);
	int ret=recv(connfd,buffer,1024-1,MSG_OOB);
}
/*
* @desc:SIGCHILD-子进程已经被停止或终止
* @param:
* @return:null
* @other:如果使用了 WNOHANG参数调用waitpid，如果没有任何已终止的进程，它也会立即返回，不会像wait那样永远等下去;
* 正常返回,子进程ID； 如果设置了选项WNOHANG，发现没有已退出的子进程可收集，则返回0； 出错，则返回-1
*/
void sig_chld_hldr()
{
	 while (waitpid((pid_t)-1,0,WNOHANG) >0 ) //pid=-1 等待任何子进程,
}

