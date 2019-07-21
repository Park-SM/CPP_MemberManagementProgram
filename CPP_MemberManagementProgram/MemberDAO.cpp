#include "MemberDAO.h"

MemberDAO::MemberDAO(const char *db_host, const char *db_user, const char *db_pass, const char *db_name, int db_port) {
	if ((this->db = mysql_init(NULL)) == NULL) {
		fprintf(stderr, ">> Connecting init error: %s\n", mysql_error(this->db));
		_getch();
	}

	if (mysql_real_connect(this->db, db_host, db_user, db_pass, db_name, db_port, NULL, 0) == NULL) {
		fprintf(stderr, "\n>> Connecting error: %s\n", mysql_error(this->db));
		this->IsConnecting = false;
		_getch();
	} else this->IsConnecting = true;
}

void MemberDAO::ConnectingCheck() const {
	if (this->IsConnecting) {
		printf(">> Print host information\t: %s\n", mysql_get_host_info(this->db));
		printf(">> Print server DB version\t: %s\n", mysql_get_server_info(this->db));
	} else puts(">> Error: Failed to check server database version for disconnecting.");
	
	puts("Please press any key to continue.."); _getch();
}

MemberDAO::~MemberDAO() {
	mysql_close(this->db);
}