#pragma once

#include <iostream>
#include <string>
#include <stack>
#include "Tstack.h"

using namespace::std;


class TCalculator {
private:
	double answer;
	string infix;
	string postfix;
	TStack<double> stackDigits;
	TStack<char> stackOperators;
	int Priority(char elem);

public:
	TCalculator();
	TCalculator(const string& exp);
	~TCalculator() {}

	string GetExp() {
		return infix;
	}

	string GetPostfix() {
		return postfix;
	}
	string GetInfix() {
		return infix;
	}
	double GetAnswer() {
		return answer;
	}
	void SetExp(const string& exp);
	void ToPostfix();
	double CalcPostfix();
	double Calc();

	friend istream& operator>>(istream& istr, TCalculator& c);
	friend ostream& operator<<(ostream& ostr, const TCalculator& c);
};
