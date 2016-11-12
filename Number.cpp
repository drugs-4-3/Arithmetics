#include "stdafx.h"
#include "Number.h"
#include <iostream>
#include <cmath>


Number::Number(){
	// default constructor
}

Number::Number(string s_integer_part, string s_decimal_part)
{
	// set private variables to values of parameters
	this->s_integer_part = s_integer_part;
	this->s_decimal_part = s_decimal_part;
}


Number::Number(string s_whole_number){
	int division_index = s_whole_number.length(); // we assume that there's no division character - integer number with dot at the end
	int dot_index = s_whole_number.find('.');
	int coma_index = s_whole_number.find(',');
	if (dot_index != -1 || coma_index != -1) {
		division_index = dot_index > coma_index ? dot_index : coma_index;
		s_integer_part = s_whole_number.substr(0, division_index);
		s_decimal_part = s_whole_number.substr(division_index + 1, s_whole_number.length());
	}
	else {
		s_integer_part = s_whole_number;
		s_decimal_part = "0";
	}
}

Number::~Number()
{
}

string Number::to_string() 
{
	// return minimalistic string representation of a number
	return (s_integer_part + "." + s_decimal_part);
}

int Number::compare_numbers(string s1, string s2) {
	if (s1.length() != s2.length())
		return s1.length() > s2.length() ? 1 : -1;
	else
		return s1.compare(s2);
}

string Number::remove_leading_zeros(string str) {
	string result;
	int index = str.find_first_not_of('0');
	if (index > str.length())
		result = "0";
	else
		result = str.substr(index, str.length() - index);
	return result;
}

string Number::remove_trailing_zeros(string str) {
	string result;
	int index = str.find_last_not_of('0');
	if (index > str.length())
		result = "0";
	else
		result = str.substr(0, index + 1);
	return result;
	// these two might be shorter, but wanted to keep code readability.
}

void Number::add(Number arg) {
	string s1 = s_integer_part + s_decimal_part;
	string s2 = arg.s_integer_part + arg.s_decimal_part;
	if (arg.s_decimal_part.length() != s_decimal_part.length()) {
		int deficit = arg.s_decimal_part.length() - s_decimal_part.length();
		if (deficit > 0)
			s1 += string(deficit, '0');
		else
			s2 += string(-deficit, '0');
	}
	int dot_index = s_integer_part.length();
	int times_extended = 0;
	for (int i = 0; i < s2.length(); i++) {
		int value = s2[s2.length() - 1 - i] - 48;
		add_to(&s1, value, i, &times_extended);
	}
	dot_index += times_extended;
	s_integer_part = s1.substr(0, dot_index);
	s_decimal_part = s1.substr(dot_index, s2.length());
	s_decimal_part = remove_trailing_zeros(s_decimal_part);
}

void Number::add_to(string *s, int value, int position, int *times_extended) {
	int index = (*s).length() - 1 - position;
	if (index < 0) {
		*s = (char)(value + 48) + *s;
		*times_extended += 1;
	}
	else {
		(*s)[index] += value;
		if ((*s)[index] > 57) { // above value of digit 9
			int number = (*s)[index] - 48;
			int surplus = number / 10;
			int rest = number % 10;
			(*s)[index] = rest + 48;
			add_to(s, surplus, position + 1, times_extended);
		}
	}
}

void Number::subtract(Number arg) {
	
}


