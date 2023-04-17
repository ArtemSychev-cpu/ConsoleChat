#pragma once
#include<iostream>
using namespace std;
#include<string>

class User 
{
public:
	User(string name, string login, string password) : _name(name), _login(login), _password(password) {
	}
	void UserReg();
	void UserLog();
		
	
private:
	string _name;
	string _login;
	string _password;

};

