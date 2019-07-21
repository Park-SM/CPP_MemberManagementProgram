#include "MemberDAO.h"

MemberDAO::MemberDAO() {
	if (mysql_init(&this->conn) == NULL) {
		fprintf(stderr, ">> Connecting init error: %s\n", mysql_error(&this->conn));
	} else puts(">> Successfully initialized the connecting object.");

	std::cout << ">> Connecting to server's Database..";
	this->db = mysql_real_connect(&this->conn, DB_HOST, DB_USER, DB_PASS, DB_NAME, 3306, NULL, 0);
	if (this->db == NULL) {
		fprintf(stderr, "\n>> Connecting error: %s\n", mysql_error(&this->conn));
		this->IsConnecting = false;
	} else {
		puts("\n>> Successfully connected to the server's database.");
		this->IsConnecting = true;
	}

	puts("Please press any key to continue.."); _getch();
}

void MemberDAO::ConnectingCheck() const {
	if (this->IsConnecting) {
		printf(">> Print host information\t: %s\n", mysql_get_host_info(this->db));
		printf(">> Print server DB version\t: %s\n", mysql_get_server_info(this->db));
	} else puts(">> Error: Failed to check server database version for disconnecting.");
	
	puts("Please press any key to continue.."); _getch();
}