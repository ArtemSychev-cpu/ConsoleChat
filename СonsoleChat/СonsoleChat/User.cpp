#include "User.h"

void User:: UserReg()
{
	cout << "������� ���� ���:" << endl;
	cin >> _name;
	cout << "���������� �����:" << endl;
	cin >> _login;
	cout << "���������� ������:" << endl;
	cin >> _password;
}
void User:: UserLog() {
	cout << "������� �����:" << endl;
	cin >> _login;
	cout << "������� ������:" << endl;
	cin >> _password;


}