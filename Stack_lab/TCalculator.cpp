#include "TCalculator.h"
#include <iostream>
#include <cmath>

TCalculator::TCalculator() : stackOperators(0), stackDigits(0)
{
	infix = "";
	postfix = "";
	answer = 0;
}

TCalculator::TCalculator(const string& exp) : stackOperators(exp.length()*3), stackDigits(exp.length()*3)
{
	infix = exp;
	postfix = "";
	answer = 0;
}

int TCalculator::Priority(char elem) {
	switch (elem) {
	case'(':
	case')':return 1;
	case'+':
	case'-':return 2;
	case'*':
	case's':
	case'c':
	case'/':return 3;
	default: throw "error";
	}
}

void TCalculator::ToPostfix() {
	postfix = "";
	string src = "(" + infix + ")";
	char elem = '!';
	unsigned int i = 0;
	while (i < src.size()) {
		//postfix += " ";
		if (src[i] >= '0' && src[i] <= '9') {
			postfix += src[i];
		}
		if (src[i] == ',' || src[i] == '+' || src[i] == '-' || src[i] == '*' || src[i] == '/') {
			postfix += " ";
			elem = stackOperators.Pop();
			while (Priority(elem) >= Priority(src[i])) {
				postfix += elem;
				postfix += " ";
				elem = stackOperators.Pop();
			}
			stackOperators.Push(elem);
			stackOperators.Push(src[i]);
		}
		if (src[i] == 's' || src[i] == 'c') 
			stackOperators.Push(src[i]);
		if (src[i] == '(') {
			stackOperators.Push(src[i]);
		}
		if (src[i] == ')') {
			elem = stackOperators.Pop();
			while (elem != '(') {
				postfix += elem;
				elem = stackOperators.Pop();
			}
		}
		i++;
	}
}

void TCalculator::SetExp(const string& exp) {
	infix = exp;
}

double TCalculator::Calc() {
	try {
		ToPostfix();
		return CalcPostfix();
	}
	catch (const char* error) {
		cout << "Error: " << error << endl;
		return 0.0;
	}
}

double TCalculator::CalcPostfix() {
	for (size_t i = 0; i < postfix.size(); i++)
	{
		if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/' || postfix[i] == 's' || postfix[i] == 'c') { 
			double d1, d2;
			
			
			switch (postfix[i]) {
			case '+':
				d1 = stackDigits.Pop();
				d2 = stackDigits.Pop();
				
				stackDigits.Push(d1 + d2);
				break;
			case '-':
				d2 = stackDigits.Pop();
				d1 = stackDigits.Pop();
				stackDigits.Push(d1 - d2);
				break;
			case '*':
				d1 = stackDigits.Pop();
				d2 = stackDigits.Pop();
				stackDigits.Push(d1 * d2);
				break;
			case '/':
				d1 = stackDigits.Pop();
				d2 = stackDigits.Pop();
				//double tmp = -1;
				
				stackDigits.Push(d2/d1);
				break;
			case 's':
				d1 = stackDigits.Pop();
				stackDigits.Push(sin(d1)); 
				break;
			case 'c':
				d1 = stackDigits.Pop();
				stackDigits.Push(cos(d1));
				break;
			default: throw - 1;
			}
		}
		if (postfix[i] <= '9' && postfix[i] >= '0') {
			size_t c;
			double t = std::stod(&postfix[i], &c);
			stackDigits.Push(t);
			i = i + (c - 1);
		}
	}
	answer = stackDigits.GetTop();
	
}

istream& operator>>(istream& istr, TCalculator& calc)
{
	cout << "Enter your expression:";
	string exp;
	istr >> exp;
	calc.infix = exp;
	return istr;
}

ostream& operator<<(ostream& ostr, const TCalculator& c)
{
	if (c.postfix.size() == 0) throw "error";
	ostr << "Infix expr -- " << c.infix << endl;
	ostr << "Postfix expr  -- " << c.postfix << endl;
	ostr << "Answer is -- " << c.answer << endl;
	return ostr;
}
