#include <iostream>
#include <string>
#include "TStack.h"
#include "TCalc.h"

void main() {
	string expr;
	getline(cin, expr);
	TCalc calculator(expr);
	cout << calculator.CorrectBrackets() << '\n';
	calculator.ToPostfix();
	cout << calculator.GetPostfix() << '\n';
	cout << calculator.Calc() << '\n';
	cout << calculator.NewCalc();
}