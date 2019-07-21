#define _CRT_SECURE_NO_WARNINGS
#include "Member.h"

Member::Member() : origin_no(0), age(0) {
	memset(this->name, 0x00, NAME_L);
	memset(this->phone, 0x00, PHONE_L);
	memset(this->juso, 0x00, JUSO_L);
}

bool Member::initMember(short int uNo, char *uName, short int uAge, char *uPhone, char *uJuso) {
	if (strlen(uName) < NAME_L && strlen(uPhone) < PHONE_L && strlen(uJuso) < JUSO_L) {
		this->origin_no = uNo;
		strncpy(this->name, uName, strlen(uName));
		this->age = uAge;
		strncpy(this->phone, uPhone, strlen(uPhone));
		strncpy(this->juso, uJuso, strlen(uJuso));
		return true;
	} else return false;
}

void Member::setName(char *uName) {
	if (strlen(uName) < NAME_L) {
		strncpy(this->name, uName, strlen(uName));
	} else cout << ">> Error:: Failed to modify member name field" << endl;
}

void Member::setAge(short int uAge) {
	this->age = uAge;
}

void Member::setPhone(char *uPhone) {
	if (strlen(uPhone) < PHONE_L) {
		strncpy(this->phone, uPhone, strlen(uPhone));
	} else cout << ">> Error:: Failed to modify member phone field";
}

void Member::setJuso(char *uJuso) {
	if (strlen(uJuso) < JUSO_L) {
		strncpy(this->juso, uJuso, strlen(uJuso));
	} else cout << ">> Error:: Failed to modify member juso field" << endl;
}

void Member::setNextMember(Member *uNextMember) {
	this->NextMember = uNextMember;
}

void Member::PrintInfo() const {
	//cout << "Name: " << this->name << " || Age: " << this->age << " || Phone: " << this->phone << " || Juso: " << this->juso << endl;
	cout << " o.n: " << this->origin_no << " || Name: " << this->name << " || Age: " << this->age << " || Phone: " << this->phone << " || Juso: " << this->juso << endl;
}