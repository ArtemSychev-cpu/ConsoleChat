#pragma once
#include<string>
using namespace std;

class User
{
   const std::string _name;
   const std::string _login;
   const std::string _password;

public:
	User(const std::string& name,const std:: string& login,const std:: string& password):
	_name(name),_login(login),_password(password){}
	auto get_name() const {return _name;}
	void set_name(std::string& name) {name = name;}
	auto get_login() const{ return _login; }
	auto get_password()const {return _password;}
	void set_password(std::string& password) {password = _password;}
	
	
};

