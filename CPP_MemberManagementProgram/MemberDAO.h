#ifndef __MEMBERDAO_H_
#define __MEMBERDAO_H_

#pragma comment (lib, "libmysql.lib")

#define DB_HOST "localhost"
#define DB_USER 
#define DB_PASS 
#define DB_NAME 
#define DB_PORT 
// The field names in the schema are "no"(PRIMARY_KEY => AUTO_INCREMENT), "name", "age", "phone", "juso".

#include "CommonInclude.h"
#include <mysql.h>

class MemberDAO {	
public:
	MYSQL *db;
	MYSQL_RES *result;
	MYSQL_ROW row;
	bool IsConnecting;
	int query_status;
public:
	MemberDAO(const char *db_host, const char *db_user, const char *db_pass, const char *db_name, int db_port);
	void ConnectingCheck() const;
	~MemberDAO();
};

#endif