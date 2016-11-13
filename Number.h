#pragma once
#include <string>

using namespace std;

class Number
{
public:
	string sign;
	string s_integer_part;
	string s_decimal_part;
	Number();
	Number(string s_whole_number);
	Number(string s_integer_part, string s_decimal_part);
	~Number();
	string to_string();
	void add(Number arg);
	void subtract(Number arg);
	void modify(Number arg);
	int compare(Number arg);
	int compare(Number n1, Number n2);
	void swap(Number *n1, Number *n2);
	

private:
	int compare_strings(string s1, string s2);
	string remove_leading_zeros(string str);
	string remove_trailing_zeros(string str);
	void add_to(string *s, int value, int position, int *times_extended);
	void subtract_from(string *s, int position, int value);
};

