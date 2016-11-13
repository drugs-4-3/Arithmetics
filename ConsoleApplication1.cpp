#include "stdafx.h"
#include <iostream>
#include <string>
#include "Number.h"
#include <gtest/gtest.h>


using namespace std;

string s1 = "5";
string s2 = "2";

void add_to(string *s, int value, int position) {
	int index = (*s).length() - 1 - position;

	if (index < 0) {
		*s = (char)(value + 48) + *s;
	}
	else {
		(*s)[index] += value;
		if ((*s)[index] > 57) { // above value of digit 9
			int number = (*s)[index] - 48;
			int surplus = number / 10;
			int rest = number % 10;
			(*s)[index] = rest + 48;
			add_to(s, surplus, position + 1);
		}
	}
}

string add(string s1, string s2) {
	for (int i = 0; i < s1.length(); i++) { // i is position in decimal system (e.g. i=2 -> 10^(i=2)*value)
		int value = s1[s1.length() - 1 - i] - 48; 
		add_to(&s2, value, i);
	}
	return s2;
}

int compare_numbers(string s1, string s2) {
	if (s1.length() != s2.length())
		return s1.length() > s2.length() ? 1 : -1;
	else
		return s1.compare(s2);
}

string remove_leading_zeros(string str) {
	string result;
	int index = str.find_first_not_of('0');
	if (index > str.length())
		result = "0";
	else
		result = str.substr(index, str.length() - index);
	return result;
}

void subtract_from(string *s, int position, int value) { 
	int index = (*s).length() - 1 - position; // translating decimal position into index of a string
	if (value <= (*s)[index] - 48) {
		(*s)[index] -= value;
	}
	else {
		subtract_from(s, position + 1, 1); // borrowing 1 from position above
		(*s)[index] = (*s)[index] + 10 - value;
	}
}

string subtract(string s1, string s2) {
	/*
	s1 - odjemna
	s2 - odjemnik
	*/
	bool swapped = false;
	if (compare_numbers(s1, s2) < 0) {
		string tmp = s1;
		s1 = s2;
		s2 = tmp;
		swapped = true;
	}
	for (int position = 0; position < s2.length(); position++) {
		int index = s2.length() - 1 - position;
		int value = s2[index] - 48;
		subtract_from(&s1, position, value);
	}
	s1 = remove_leading_zeros(s1);
	if (swapped)
		s1 = "-" + s1; // numbers swapped - that means the result is negative
	return s1;
}



int main()
{
	Number n1("102.532");
	Number n2("1000.000001");

	n1.subtract(n2);

	cout << n1.to_string() << endl;
}

