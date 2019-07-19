#define _CRT_SECURE_NO_WARNINGS
#include "MemberHandler.h"

void MemberHandler::PrintList() const {
	if (this->HeadMember != NULL) {
		Member *CurrentMember = this->HeadMember;
		for (int index = 1; CurrentMember != NULL; index++) {
			cout << ">> "<< index << " || ";
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
	if (NewMember->initMember(tempMember->name, tempMember->age, tempMember->phone, tempMember->juso)) {
		this->AppendMember(NewMember);
		return true;
	} else return false;
}

bool MemberHandler::ModifyMember(short int targetIndex, Member *tempMember) const {
	if (this->HeadMember != NULL) {
		Member *CurrentMember = this->HeadMember;
		for (int i = 1; i < targetIndex && CurrentMember != NULL; i++)
			CurrentMember = CurrentMember->NextMember;
		if (CurrentMember != NULL) {
			memset(CurrentMember->name, 0x00, NAME_L);
			memset(CurrentMember->phone, 0x00, PHONE_L);
			memset(CurrentMember->juso, 0x00, JUSO_L);
			CurrentMember->initMember(tempMember->name, tempMember->age, tempMember->phone, tempMember->juso);
			return true;

		}
	}
	return false;
}

bool MemberHandler::DeleteMember(short int targetIndex) {
	if (this->HeadMember != NULL) {
		Member *tempMember = this->HeadMember;
		if (targetIndex == 1) {
			this->HeadMember = this->HeadMember->NextMember;
			delete tempMember;
			this->NumOfMember--;
			return true;
		} else {
			Member *CurrentMember = this->HeadMember;
			for (int i = 1; i < targetIndex - 1 && CurrentMember != NULL; i++)
				CurrentMember = CurrentMember->NextMember;
			if (CurrentMember != NULL) {
				tempMember = CurrentMember->NextMember;
				CurrentMember->NextMember = CurrentMember->NextMember->NextMember;
				delete tempMember;
				this->NumOfMember--;
				return true;
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
		DeleteNode(this->HeadMember);
		this->HeadMember = NULL;
		this->NumOfMember = 0;
		return true;
	}
	return false;
}

MemberHandler::~MemberHandler() {
	this->AllDeleteList();
}