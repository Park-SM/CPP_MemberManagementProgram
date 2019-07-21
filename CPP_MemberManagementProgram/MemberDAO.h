#ifndef __MEMBERDAO_H_
#define __MEMBERDAO_H_

#pragma comment (lib, "libmysql.lib")

#define DB_HOST "smparkworld.com"
#define DB_USER
#define DB_PASS
#define DB_NAME

#include "CommonInclude.h"
#include <mysql.h>

class MemberDAO {	
private:
	MYSQL *db, conn;
	MYSQL_RES *result;
	MYSQL_ROW row;
	bool IsConnecting;
	int query_status;
public:
	MemberDAO();
	void ConnectingCheck() const;
};

#endif