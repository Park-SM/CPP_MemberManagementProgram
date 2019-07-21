#ifndef __MEMBER_H_
#define __MEMBER_H_

#include "CommonInclude.h"
#define NAME_L 16
#define PHONE_L 12
#define JUSO_L 128
using namespace std;

class Member {
public:
	short int origin_no;
	char name[NAME_L];
	short int age;
	char phone[PHONE_L];
	char juso[JUSO_L];
	Member *NextMember;

public:
	Member();
	bool initMember(short int uNo, char *uName, short int uAge, char *uPhone, char *uJuso);
	void setName(char *uName);
	void setAge(short int uAge);
	void setPhone(char *uPhone);
	void setJuso(char *uJuso);
	void setNextMember(Member *uNextMeber);
	void PrintInfo() const;
	~Member() {};
};

#endif