#include "Display.h"
#include "MemberDAO.h"

int main() {

	MemberDAO *dao = new MemberDAO();
	dao->ConnectingCheck();

	Display *dp = new Display();
	while (dp->escape) dp->MainMenu();
	delete dp;

	return 0;
}