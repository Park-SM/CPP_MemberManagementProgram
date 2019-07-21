#ifndef __MEMBERHANDLER_H_
#define __MEMBERHANDLER_H_

#include "CommonInclude.h"
#include "Member.h"
#include "MemberDAO.h"
using namespace std;

class MemberHandler {
private:
	Member *HeadMember;
	int NumOfMember;
public:
	MemberHandler();
	void LoadDB();
	void PrintList() const;
	bool CreateMember(Member *tempMember);
	bool ModifyMember(short int targetIndex, Member *tempMember);
	bool DeleteMember(short int targetIndex);
	bool AllDeleteList();
	int getNumOfMember() { return NumOfMember; };
	~MemberHandler();
private:
	void AppendMember(Member *NewMember);
};

#endif