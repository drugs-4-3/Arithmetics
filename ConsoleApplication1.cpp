#include "stdafx.h"
#include <iostream>
#include <string>
#include "Number.h"

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
	for (int i = 0; i < s1.length(); i++) {
		int value = s1[s1.length() - 1 - i] - 48;
		add_to(&s2, value, i);
	}
	return s2;
}

string change(string *s) {
	*s = (char)56 + *s;
	return *s;
}

int main()
{
	Number n1("109", "9221");
	Number n2("9", "22");

	n1.add(n2);
	cout << n1.to_string() << endl;
}

