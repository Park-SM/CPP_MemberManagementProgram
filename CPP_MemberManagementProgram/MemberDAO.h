#ifndef __MEMBERDAO_H_
#define __MEMBERDAO_H_

#pragma comment (lib, "libmysql.lib")

#define DB_HOST "125.129.249.230"
#define DB_USER
#define DB_PASS
#define DB_NAME

#include "CommonInclude.h"
#include <mysql.h>

class MemberDAO {	
private:
	MYSQL db;
	MYSQL_RES *result;
	MYSQL_ROW row;
	int query_status;
public:
	MemberDAO();
	int ConnectingCheck() const;
};

#endif