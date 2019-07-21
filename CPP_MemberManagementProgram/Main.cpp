#include "Display.h"
#include "MemberDAO.h"

int main() {

	Display *dp = new Display();
	while (dp->escape) dp->MainMenu();
	delete dp;

	return 0;
}