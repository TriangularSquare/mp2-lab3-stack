#include <iostream>
#include <string>
#include "TStackL.h"
#include "TCalcL.h"

void main() {
	string expr;
	getline(cin, expr);
	TCalcL calculator(expr);
	cout << calculator.CorrectBrackets() << '\n';
	calculator.ToPostfix();
	cout << calculator.GetPostfix() << '\n';
	cout << calculator.Calc() << '\n';
	cout << calculator.NewCalc();
}