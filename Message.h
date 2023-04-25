#pragma once
#include<string>
#include"User.h"
using namespace std;

class Message
{
	const string _from;
	const string _to;
	const string _text;

public:
	Message(const string& from, const string& to, const string& text):
		_to(to), _from(from),_text(text){}
	string get_to() const {return _to;}
	string get_from() const {return _from;}
	string get_text() const {return _text;}


};

