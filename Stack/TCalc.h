#pragma once
#include <iostream>
#include <string>
#include <cmath>
#include <sstream>
#include "TStack.h"

using namespace std;

class TCalc {
private:
    string expr;
    string pstfix;
    TStack<char> st_char;
    TStack<double> st_d;

    int prior(char op);
public:
    TCalc(std::string _expr = "2 + 2");
    TCalc(const TCalc& tc); 

    bool CorrectBrackets();
    void ToPostfix();
    string GetPostfix();
    double Calc();
    double NewCalc();
};
