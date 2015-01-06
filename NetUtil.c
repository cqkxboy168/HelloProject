/*
* @desc:�жϴ�С��
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
* @desc:���÷�����
* @param:�ļ�������
* @return:0�ɹ�
*/
int setNonblocking(int fd,int option)
{
	int old_value = fcntl(fd,F_GETFL);//��ȡ�ļ���������״̬��־
	int new_value = (option==1)?(old_value | O_NONBLOCK):0;
	int rc=fcntl(fd,F_SETFL,new_value);
	if(rc<0)
		return -1;
	return 0;
}

/*
* @desc:����TCP_NODELAY������nagle�㷨
* @param:nodealyΪ1������nagle,nodelayΪ0������nagle;
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
* @desc:�����ػ�����
* @param:null
* @return:null
* @other:����->������->�Ự��������һ��bash��ִ��ps.less�������ͬһ���Ự��
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
  if( rc>0) //�������˳�
  	exit(0);
  /*�ػ��������ն˽������رձ�׼���룬���*/
  close( 0 );
  close( 1 );
  close( 2 );	
  umask( 0 );//��������
  rc=setsid();//�ؽ��Ự
  if(rc<0)
  {
  	printf("can not creat new session\n");
  	exit(-1);
  }
  rc=chdir("/");//�л���Ŀ¼
  if(rc<0)
  {
  	printf("change dir failed\n");
  	exit(-1);
  }
}

/*
* @desc�������û�ID��UID����ʵ���û�ID(EUID)
* @param:null
* @return:null
* @other:EUID��Ŀ�ķ�����Դ���ʣ�chown root:root test_uid,chmod +s test_uid.����su����
*/
void test_euid()
{
	uid_t uid=getuid(); //
	uid_t euid=geteuid();//������chmod+s��־��EUIDΪroot��������root�û�����
}

