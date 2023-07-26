#pragma once
#include<string>
using namespace std;

class User
{
   string _name;//если сделать _name и _password константами, то в сеттерах не удастся присвоить им значение
   const string _login;
   string _password;

public:
	User( const string& name,const string& login,const string& password):
	_name(name),_login(login),_password(password){}
	auto get_name() const {return _name;}
	auto set_name(const string& name) { _name = name; }
	auto get_login() const{ return _login; }
	auto get_password()const {return _password;}
	auto set_password( const string& password) { _password = password; }
	
	
};

