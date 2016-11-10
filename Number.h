#pragma once
#include <string>

using namespace std;

class Number
{
public:
	string s_integer_part;
	string s_decimal_part;
	Number();
	Number(string s_whole_number);
	Number(string s_integer_part, string s_decimal_part);
	~Number();
	string to_string();
	void add(Number arg);
	string remove_trailing_zeros(string str);
	

private:
	void add_to(string *s, int value, int position, int *times_extended);
	string remove_leading_zeros(string str);
};

