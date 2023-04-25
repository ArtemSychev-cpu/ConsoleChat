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
		cout << "Здравствуйте! Выберите шаг: 1 - регистрация в чате, 2 - вход в аккаунт, 0 - выход" << endl;
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

			cout << "Введите имя" << endl;
			cin >> name;
			cout << "Введите логин" << endl;
			cin >> login;
			cout << "Введите пароль" << endl;
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

			cout << "Введите логин" << endl;
			cin >> login;
			cout << "Введите пароль" << endl;
			cin >> password;
			_currentUser = getUserByLogin(login);
			if (_currentUser == nullptr || (password != _currentUser->get_password()))
			{
				_currentUser = nullptr;
				cout << "Пользователь не зарегистрирован, любой символ - повторить ввод, 0  - выход" << endl;
				cin >> choise;
				if (choise =='0')
					startMenu();
			}
		} while (!_currentUser);

	}
	void Chat:: sendMessage()
	{
		string text, to;
			
			cout << "Отправить сообщение конкретному пользователю введите его имя" << endl;
			cout << "Чтобы отправить Всем, введите 'all' " << endl;
			cin >> to;
			cout << "Текст:  ";
			cin.ignore();
			getline(cin, text);

			if (!(to == "all" || getUserByLogin(to)))
			{
				cout << "Такого пользователя не существует : " << to << endl;
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
			cout << "Привет " << _currentUser->get_name() << endl;
			cout << "Меню:" << endl;
			cout << "1. Показать чат" << endl;
			cout << "2. Написать сообщение" << endl;
			cout << "3. Пользователи" << endl;
			cout << "0. Выход" << endl;

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

	cout << "История сообщений" << endl;

	for (auto& m : messages)
	{
		if (_currentUser->get_login() == m.get_from() || _currentUser->get_login() == m.get_to() || m.get_to() == "all")
		{
		from = (_currentUser->get_login() == m.get_from() ? "Меня" : getUserByLogin(m.get_from())->get_name());
		if (m.get_to() == "all")
		{
			to = " Всем ";
		}
		else
		{
		to = (_currentUser->get_login() == m.get_to()) ? "Мне" : getUserByLogin(m.get_to())->get_name();
		}
		cout << " Сообщение от " << from << "  Кому  " << to << endl;
		cout << "Текст  " << m.get_text() << endl;
		}
    }
    }
	void Chat::showAllUserName() const
	{
		cout << "Пользователь: " << endl;
		for (auto& user : users)
		{
			cout << user.get_name();
			if (_currentUser->get_login() == user.get_login())
				cout << " Я " << endl;
			cout << endl;
		}
	}














