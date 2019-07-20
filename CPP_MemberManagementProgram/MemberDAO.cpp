#include "MemberDAO.h"
#include <Windows.h>

MemberDAO::MemberDAO() {
	if (mysql_init(&this->db) == NULL) {
		fprintf(stderr, ">> Connecting init error: %s\n", mysql_error(&this->db));
	} else puts(">> Successfully initialized the connecting object.");

	std::cout << ">> Connecting to server's Database..";
	if (mysql_real_connect(&this->db, DB_HOST, DB_USER, DB_PASS, DB_NAME, 3306, NULL, 0) == NULL) {
		fprintf(stderr, "\n>> Connecting error: %s\n", mysql_error(&this->db));
	} else puts("\n>> Successfully connected to the server's database.");

	puts("Please press any key to continue.."); _getch();
}

int MemberDAO::ConnectingCheck() const {

	//printf("Print mysql version: %s", mysql_get_server_info(&this->db));
	Sleep(1000);
	return 0;
}