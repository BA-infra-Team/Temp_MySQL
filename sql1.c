#include <stdio.h>
#include </usr/include/mysql/mysql.h>
#include <errno.h>

int main(void)
{
	MYSQL mysql;
	mysql_init(&mysql);
	
	if (!mysql_real_connect(&mysql, NULL, "사용자이름", "암호", NULL, 3306, (char *)NULL,0))
		printf("%s\n",mysql_error(&mysql));
		exit(1);
	printf("성공적으로 연결되었습니다.\n");
	mysql_close(&mysql);
}
