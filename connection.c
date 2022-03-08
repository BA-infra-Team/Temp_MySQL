#include <stdio.h>
#include <stdlib.h>
#include <mysql/mysql.h>

static char *host = "localhost";
static char *user = "root";
static char *pass = "TBBZ3F";
static char *dbname = "logdata";

unsigned int port = 3306;
static char *unix_socket = NULL;
unsigned int flag = 0;

int main()
{
	MYSQL *conn; // connect 위한 mysql 구조체 선언
	conn = mysql_init(NULL);	// 초기에 널 값으로 지정
	if(!(mysql_real_connect(conn,host,user,pass,dbname,port,unix_socket,flag)));	// mysql 연결 함수 
		{		
			fprintf(stderr, "\nError:%s[%d]\n", mysql_error(conn), mysql_errno(conn));
			exit(1);
		}
	printf("Connection Successful\n");
	mysql_close(conn);	
return 0;
}
