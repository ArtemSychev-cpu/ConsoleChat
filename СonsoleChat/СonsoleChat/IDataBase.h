#pragma once
#include<string>

class IDataBase //абстрактная база данных, содержащая данные пользователей и сообщения
{
	IDataBase() = default;
	
private:
	std::string data;
	
};

