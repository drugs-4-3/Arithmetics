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
	void subtract(Number arg);
	

private:
	string remove_leading_zeros(string str);
	string remove_trailing_zeros(string str);
	void add_to(string *s, int value, int position, int *times_extended);
	int compare_numbers(string s1, string s2);
};

