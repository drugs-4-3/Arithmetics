#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

string s1 = "5";
string s2 = "2";

void add_to(string *s, int value, int position) {
	int index = (*s).length() - 1 - position;
	cout << "position = " << position << endl;
	cout << "index = " << index << endl;
	cout << "value = " << value << endl;
	if (index < 0) {
		*s = (char)(value + 48) + *s;
	}
	else {
		cout << "before adding: " << (*s)[index] << endl;
		(*s)[index] += value;
		cout << "after adding: " << (*s)[index] << endl;
		if ((*s)[index] > 57) { // above value of digit 9
			int number = (*s)[index] - 48;
			int surplus = number / 10;
			int rest = number % 10;
			cout << "rest = " << rest << endl;
			(*s)[index] = rest + 48;
			add_to(s, surplus, position + 1);
		}
	}
	
}


string add(string s1, string s2) {
	for (int i = 0; i < s1.length(); i++) {
		cout << "petla nr " << i << endl;
		int value = s1[s1.length() - 1 - i] - 48;
		add_to(&s2, value, i);
	}
	return s2;
}

string change(string *s) {
	*s = (char)56 + *s;
	return *s;
}

int main() {
	
	string s3 = add(s1, s2);
	cout << "s1 = " << s1 << endl;
	cout << "s2 = " << s2 << endl;
	cout <<"s1 + s2 = " << s3 << endl;

	return 0;
}

