
#include <iostream>
#include <string>
#include "TCalculator.h"

using namespace::std;

int main() {
    setlocale(LC_ALL, "Russian");
    string inp;
    cout << "Введите математическое выражение\n";
    cin >> inp;

    TCalculator calc(inp);
    calc.ToPostfix();
    calc.CalcPostfix();
    cout << calc.GetPostfix() << " = " << calc.GetAnswer();
   


}
