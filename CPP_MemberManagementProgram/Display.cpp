#include "Display.h"

Display::Display() {
	this->escape = 1;
	this->memberHandler = new MemberHandler();
	this->tempMember = new Member();
}

void Display::MainMenu() {
	system("cls");
	cout << "=========================================================" << endl;
	cout << "Command list." << endl;
	cout << " - print\t=> Print the member list." << endl;
	cout << " - add\t\t=> Add new member." << endl;
	cout << " - modify\t=> Modify the member." << endl;
	cout << " - delete\t=> Delete the member." << endl;
	cout << " - deleteALL\t=> Destroy the member list." << endl;
	cout << " - exit\t\t=> Exit program." << endl;
	cout << "=========================================================" << endl;
	cout << ">> command:: ";
	memset(this->inputBuf, 0x00, MAXBUF);
	gets_s(inputBuf, MAXBUF);

	if (strncmp(this->inputBuf, "print", strlen("print")) == 0) this->PrintMenu();
	else if (strncmp(this->inputBuf, "add", strlen("add")) == 0) this->AddMenu();
	else if (strncmp(this->inputBuf, "modify", strlen("modify")) == 0) this->ModifyMenu();
	else if (strncmp(this->inputBuf, "deleteALL", strlen("deleteALL")) == 0) this->DeleteAllMenu();
	else if (strncmp(this->inputBuf, "delete", strlen("delete")) == 0) this->DeleteMenu();
	else if (strncmp(this->inputBuf, "exit", strlen("exit")) == 0) this->escape = 0;
}

void Display::PrintMenu() const {
	system("cls");
	cout << "=========================================================" << endl;
	cout << "::: PRINT MENU :::" << endl;
	this->memberHandler->PrintList();
	cout << "=========================================================" << endl;
	cout << ">> Please press any key to continue.." << endl;
	_getch();
}

void Display::AddMenu() {
	system("cls");
	cout << "=========================================================" << endl;
	cout << "::: ADD MENU :::" << endl;
	cout << "=========================================================" << endl;
	cout << "Member Name: ";
	gets_s(this->tempMember->name, NAME_L);
	cout << "Member Age: ";
	cin >> this->tempMember->age;
	while (getchar() != '\n'); // flush buf
	cout << "Member Phone: ";
	gets_s(this->tempMember->phone, PHONE_L);
	cout << "Member address: ";
	gets_s(this->tempMember->juso, JUSO_L);

	if (this->memberHandler->CreateMember(this->tempMember))
		cout << ">> Success!" << endl;
	else
		cout << ">> Error:: Failed to create member node. please input data in the correct data format" << endl;

	cout << "=========================================================" << endl;
	cout << ">> Please press any key to continue.." << endl;
	_getch();
}

void Display::ModifyMenu() const {
	short int selectIndex = 0;
	system("cls");
	cout << "=========================================================" << endl;
	cout << "::: MODIFY MENU :::" << endl;
	this->memberHandler->PrintList();
	cout << "=========================================================" << endl;
	cout << ">> Select member number: ";
	cin >> selectIndex;
	while (getchar() != '\n'); // flush buf

	if (selectIndex <= memberHandler->getNumOfMember()) {
		cout << "=============================" << endl;
		cout << "Member Name: ";
		gets_s(this->tempMember->name, NAME_L);
		cout << "Member Age: ";
		cin >> this->tempMember->age;
		while (getchar() != '\n'); // flush buf
		cout << "Member Phone: ";
		gets_s(this->tempMember->phone, PHONE_L);
		cout << "Member address: ";
		gets_s(this->tempMember->juso, JUSO_L);

		if (this->memberHandler->ModifyMember(selectIndex, tempMember))
			cout << ">> Success!" << endl;
		else
			cout << ">> Error:: Failed to found the member." << endl;
	} else cout << ">> Error:: Failed to found the member." << endl;

	cout << "=========================================================" << endl;
	cout << ">> Please press any key to continue.." << endl;
	_getch();
}

void Display::DeleteMenu() {
	short int selectIndex = 0;
	system("cls");
	cout << "=========================================================" << endl;
	cout << "::: DELETE MENU :::" << endl;
	this->memberHandler->PrintList();
	cout << "=========================================================" << endl;
	cout << ">> Select member number: ";
	cin >> selectIndex;
	while (getchar() != '\n'); // flush buf


	if (selectIndex <= memberHandler->getNumOfMember()) {
		if (this->memberHandler->DeleteMember(selectIndex))
			cout << ">> Success!" << endl;
		else
			cout << ">> Error:: Failed to found the member." << endl;
	} else cout << ">> Error:: Failed to found the member." << endl;

	cout << "=========================================================" << endl;;
	cout << ">> Please press any key to continue.." << endl;
	_getch();
}

void Display::DeleteAllMenu() {
	char answer = 0x00;
	system("cls");
	cout << "=========================================================" << endl;
	cout << "::: DELETE ALL MENU :::" << endl;
	cout << "=========================================================" << endl;
backQust:
	cout << ">> This menu is to delete all member information.\n>> Would you like to continue? [y/n]: ";
	cin >> answer;
	while (getchar() != '\n'); // flush buf
	if (answer == 'y' || answer == 'Y') {
		memberHandler->AllDeleteList();
		cout << "Success!" << endl;
	} else if (answer == 'n' || answer == 'N');
	else goto backQust;

	cout << "=========================================================" << endl;;
	cout << ">> Please press any key to continue.." << endl;
	_getch();
}

Display::~Display() {
	delete memberHandler;
	delete tempMember;
}