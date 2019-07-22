#define _CRT_SECURE_NO_WARNINGS
#include "MemberHandler.h"

void DeleteNode(Member *target);

MemberHandler::MemberHandler() : HeadMember(NULL), NumOfMember(0) {
	this->LoadDB();
}

void MemberHandler::LoadDB() {
	if (this->HeadMember != NULL) {
		DeleteNode(this->HeadMember);
		this->HeadMember = NULL;
		this->NumOfMember = 0;
	}

	Member *NewMember = NULL;
	MemberDAO *MemDAO = new MemberDAO(DB_HOST, DB_USER, DB_PASS, DB_NAME, DB_PORT);
	if (!mysql_query(MemDAO->db, "select * from membermanagement order by no")) {
		MemDAO->result = mysql_store_result(MemDAO->db);
		if (MemDAO->result) {
			int count = mysql_num_rows(MemDAO->result);
			for (int i = 0; i < count; i++) {
				NewMember = new Member();
				MemDAO->row = mysql_fetch_row(MemDAO->result);
				NewMember->initMember(atoi(MemDAO->row[0]), MemDAO->row[1], atoi(MemDAO->row[2]), MemDAO->row[3], MemDAO->row[4]);
				AppendMember(NewMember);
			}
		}
		mysql_free_result(MemDAO->result);
	} else {
		fprintf(stderr, ">> Query error: Select query error:: %s\n", mysql_error(MemDAO->db));
		_getch();
	}
}

void MemberHandler::PrintList() const {
	if (this->HeadMember != NULL) {
		Member *CurrentMember = this->HeadMember;
		for (int index = 1; CurrentMember != NULL; index++) {
			cout << ">> No."<< index << " || ";
			CurrentMember->PrintInfo();
			CurrentMember = CurrentMember->NextMember;
		}
	} else cout << ">> No data.." << endl;
}

void MemberHandler::AppendMember(Member *NewMember) {
	if (this->HeadMember == NULL) {
		this->HeadMember = NewMember;
	} else {
		Member *tempMember = this->HeadMember;
		while (tempMember->NextMember != NULL)
			tempMember = tempMember->NextMember;
		tempMember->NextMember = NewMember;
	}
	this->NumOfMember++;
}

bool MemberHandler::CreateMember(Member *tempMember) {
	Member *NewMember = new Member();
	MemberDAO *MemDAO = new MemberDAO(DB_HOST, DB_USER, DB_PASS, DB_NAME, DB_PORT);
	if (NewMember->initMember(0, tempMember->name, tempMember->age, tempMember->phone, tempMember->juso)) {
		char query[256] = { 0, };
		sprintf(query, "insert into membermanagement (name, age, phone, juso) values ('%s', %d, '%s', '%s')", tempMember->name, tempMember->age, tempMember->phone, tempMember->juso);
		if (!mysql_query(MemDAO->db, query)) {	// If successful.
			this->AppendMember(NewMember);
			return true;
		}
		fprintf(stderr, ">> Query error: Select query error:: %s\n", mysql_error(MemDAO->db));
		_getch();
	}

	return false;
}

bool MemberHandler::ModifyMember(short int targetIndex, Member *tempMember) {
	if (this->HeadMember != NULL) {
		Member *CurrentMember = this->HeadMember;
		MemberDAO *MemDAO = new MemberDAO(DB_HOST, DB_USER, DB_PASS, DB_NAME, DB_PORT);
		char query[256] = { 0, };
		for (int i = 1; i < targetIndex && CurrentMember != NULL; i++)
			CurrentMember = CurrentMember->NextMember;
		if (CurrentMember != NULL) {
			sprintf(query, "update membermanagement set name = '%s', age = %d, phone = '%s', juso = '%s' where no = %d", tempMember->name, tempMember->age, tempMember->phone, tempMember->juso, CurrentMember->origin_no);
			if (!mysql_query(MemDAO->db, query)) {
				memset(CurrentMember->name, 0x00, NAME_L);
				memset(CurrentMember->phone, 0x00, PHONE_L);
				memset(CurrentMember->juso, 0x00, JUSO_L);
				CurrentMember->initMember(CurrentMember->origin_no, tempMember->name, tempMember->age, tempMember->phone, tempMember->juso);
				return true;
			}
			fprintf(stderr, ">> Query error: Select query error:: %s\n", mysql_error(MemDAO->db));
			_getch();
		}
	}
	return false;
}

bool MemberHandler::DeleteMember(short int targetIndex) {
	if (this->HeadMember != NULL) {
		Member *tempMember = this->HeadMember;
		MemberDAO *MemDAO = new MemberDAO(DB_HOST, DB_USER, DB_PASS, DB_NAME, DB_PORT);
		char query[256] = { 0, };

		if (targetIndex == 1) {
			sprintf(query, "delete from membermanagement where no = %d", this->HeadMember->origin_no);
			if (!mysql_query(MemDAO->db, query)) {
				this->HeadMember = this->HeadMember->NextMember;
				delete tempMember;
				this->NumOfMember--;
				return true;
			}
			fprintf(stderr, ">> Query error: Select query error:: %s\n", mysql_error(MemDAO->db));
			_getch();
		} else {
			Member *CurrentMember = this->HeadMember;
			for (int i = 1; i < targetIndex - 1 && CurrentMember != NULL; i++)
				CurrentMember = CurrentMember->NextMember;
			if (CurrentMember != NULL) {
				sprintf(query, "delete from membermanagement where no = %d", CurrentMember->NextMember->origin_no);
				if (!mysql_query(MemDAO->db, query)) {
					tempMember = CurrentMember->NextMember;
					CurrentMember->NextMember = CurrentMember->NextMember->NextMember;
					delete tempMember;
					this->NumOfMember--;
					return true;
				}
				fprintf(stderr, ">> Query error: Select query error:: %s\n", mysql_error(MemDAO->db));
				_getch();
			}
		}
	}
	return false;
}

void DeleteNode(Member *target) {
	if (target->NextMember != NULL) DeleteNode(target->NextMember);
	delete target;
}

bool MemberHandler::AllDeleteList() {
	if (this->HeadMember != NULL) {
		MemberDAO *MemDAO = new MemberDAO(DB_HOST, DB_USER, DB_PASS, DB_NAME, DB_PORT);
		if (!mysql_query(MemDAO->db, "delete from membermanagement")) {
			DeleteNode(this->HeadMember);
			this->HeadMember = NULL;
			this->NumOfMember = 0;
			return true;
		}
		fprintf(stderr, ">> Query error: Select query error:: %s\n", mysql_error(MemDAO->db));
		_getch();
	}
	return false;
}

MemberHandler::~MemberHandler() {
	if (this->HeadMember != NULL) DeleteNode(this->HeadMember);
}