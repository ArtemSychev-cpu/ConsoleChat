#include "Chat.h"



shared_ptr<User> Chat:: getUserByLogin(const string& login) const
{
	for (auto& user : users)
	{
		if (login == user.get_login())
			return make_shared<User>(user);
	}
	return nullptr;
}
shared_ptr<User>Chat::getUserByName(const string& name) const
{
	for (auto& user : users)
	{
		if (name == user.get_name())
			return make_shared<User>(user);
	}
}
	void Chat::startMenu()
	{

		int choise = 0;
		cout << "������������! �������� ���: 1 - ����������� � ����, 2 - ���� � �������, 0 - �����" << endl;
		cin >> choise;
		if (choise == 1)
			registration();
		if (choise == 2)
			LogAccount();
	}
	void Chat::registration()
	{
		string name, login, password;
		do
		{

			cout << "������� ���" << endl;
			cin >> name;
			cout << "������� �����" << endl;
			cin >> login;
			cout << "������� ������" << endl;
			cin >> password;
			if (getUserByLogin(login) || login == "all")
			{
				throw ExceptLogin();
			}

			User user = User(login, password, name);
			users.push_back(user);
			_currentUser = std::make_shared<User>(user);
		} while (!_currentUser);
	}
	void Chat::LogAccount()
	{
		string login, password;
		char choise;
		do {

			cout << "������� �����" << endl;
			cin >> login;
			cout << "������� ������" << endl;
			cin >> password;
			_currentUser = getUserByLogin(login);
			if (_currentUser == nullptr || (password != _currentUser->get_password()))
			{
				_currentUser = nullptr;
				cout << "������������ �� ���������������, ����� ������ - ��������� ����, 0  - �����" << endl;
				cin >> choise;
				if (choise =='0')
					startMenu();
			}
		} while (!_currentUser);

	}
	void Chat:: sendMessage()
	{
		string text, to;
			
			cout << "��������� ��������� ����������� ������������ ������� ��� ���" << endl;
			cout << "����� ��������� ����, ������� 'all' " << endl;
			cin >> to;
			cout << "�����:  ";
			cin.ignore();
			getline(cin, text);

			if (!(to == "all" || getUserByLogin(to)))
			{
				cout << "������ ������������ �� ���������� : " << to << endl;
			}
		

		if (to == "all")
			messages.push_back(Message(_currentUser->get_login(), "all", text));
		else
			messages.push_back(Message(_currentUser->get_login(), getUserByName(to)->get_login(), text));
	}

	
	void Chat::userMenu()
	{
		int choise;
		

		while (_currentUser)
		{
			cout << "������ " << _currentUser->get_name() << endl;
			cout << "����:" << endl;
			cout << "1. �������� ���" << endl;
			cout << "2. �������� ���������" << endl;
			cout << "3. ������������" << endl;
			cout << "0. �����" << endl;

			cout << endl;

			cin >> choise;

			switch (choise)
			{
			case 1:
				showChat();
				break;
			case 2:
				sendMessage();
				break;
			case 3:
				showAllUserName();
				break;
			case 0:
				_currentUser = nullptr;
				startMenu();
			}
		}
	}

	void Chat::showChat()const
{
	string from;
	string to;

	cout << "������� ���������" << endl;

	for (auto& m : messages)
	{
		if (_currentUser->get_login() == m.get_from() || _currentUser->get_login() == m.get_to() || m.get_to() == "all")
		{
		from = (_currentUser->get_login() == m.get_from() ? "����" : getUserByLogin(m.get_from())->get_name());
		if (m.get_to() == "all")
		{
			to = " ���� ";
		}
		else
		{
		to = (_currentUser->get_login() == m.get_to()) ? "���" : getUserByLogin(m.get_to())->get_name();
		}
		cout << " ��������� �� " << from << "  ����  " << to << endl;
		cout << "�����  " << m.get_text() << endl;
		}
    }
    }
	void Chat::showAllUserName() const
	{
		cout << "������������: " << endl;
		for (auto& user : users)
		{
			cout << user.get_name();
			if (_currentUser->get_login() == user.get_login())
				cout << " � " << endl;
			cout << endl;
		}
	}














