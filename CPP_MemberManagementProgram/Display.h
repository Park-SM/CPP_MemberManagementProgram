#ifndef __DISPLAY_H_
#define __DISPLAY_H_

#define MAXBUF 128
#include "CommonInclude.h"
#include "MemberHandler.h"
using namespace std;

class Display{
public:
	short int escape;

private:
	MemberHandler *memberHandler;
	Member *tempMember;
	char inputBuf[MAXBUF];

public:
	Display();
	void MainMenu();
	void PrintMenu() const;
	void AddMenu();
	void ModifyMenu() const;
	void DeleteMenu();
	void DeleteAllMenu();
	~Display();
};

#endif