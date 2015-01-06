/*
* @desc:�����źŴ�����
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
* @desc:����������ݣ�SIG_URG
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
* @desc:SIGCHILD-�ӽ����Ѿ���ֹͣ����ֹ
* @param:
* @return:null
* @other:���ʹ���� WNOHANG��������waitpid�����û���κ�����ֹ�Ľ��̣���Ҳ���������أ�������wait������Զ����ȥ;
* ��������,�ӽ���ID�� ���������ѡ��WNOHANG������û�����˳����ӽ��̿��ռ����򷵻�0�� �����򷵻�-1
*/
void sig_chld_hldr()
{
	 while (waitpid((pid_t)-1,0,WNOHANG) >0 ) //pid=-1 �ȴ��κ��ӽ���,
}

