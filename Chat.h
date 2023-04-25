#pragma once
#include<iostream>
#include<vector>
#include "User.h"
#include "Message.h"
#include<exception>
using namespace std;
class Chat
{   
	shared_ptr<User> _currentUser = nullptr;
	vector<User>users;
	vector<Message>messages;
public:
	
	struct ExceptLogin : public exception
	{
		const char* what() const noexcept override { return "������������ � ����� ������� ��� ����������"; }
	};
	vector<User>& getAllUser() { return users; }
	vector<Message>& getAllMessege() { return messages; }
	shared_ptr<User> getUserByLogin(const string& login) const;
	shared_ptr<User> getUserByName(const string& name) const;
	shared_ptr<User> getCurrentUser()const { return _currentUser; }
	void startMenu();
	void registration();
	void LogAccount();
	void sendMessage();
	void userMenu();
	void showChat()const;
	void showAllUserName() const;

	
  










};

