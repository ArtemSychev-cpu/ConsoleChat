#include"User.h"
#include"Chat.h"
#include"Message.h"
#include<vector>
#include<exception>
using namespace std;



int main()
{
	setlocale(LC_ALL, "");
	Chat chat;
	chat.startMenu();
	chat.userMenu();
	
			

	return 0;
}
			

	
