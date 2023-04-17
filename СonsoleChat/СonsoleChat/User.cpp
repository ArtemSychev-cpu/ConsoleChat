#include "User.h"

void User:: UserReg()
{
	cout << "Введите ваше имя:" << endl;
	cin >> _name;
	cout << "Придумайте логин:" << endl;
	cin >> _login;
	cout << "Придумайте пароль:" << endl;
	cin >> _password;
}
void User:: UserLog() {
	cout << "Введите логин:" << endl;
	cin >> _login;
	cout << "Введите пароль:" << endl;
	cin >> _password;


}