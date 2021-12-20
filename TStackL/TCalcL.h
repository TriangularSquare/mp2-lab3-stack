#pragma once
#include <iostream>
#include <string>
#include <cmath>
#include <sstream>
#include "TStackL.h"

using namespace std;

class TCalcL {
private:
    string expr;
    string pstfix;
    TStackL<char> st_char;
    TStackL<double> st_d;

    int prior(char op);
public:
    TCalcL(std::string _expr = "2 + 2");
    TCalcL(const TCalcL& tc);

    bool CorrectBrackets();
    void ToPostfix();
    string GetPostfix();
    double Calc();
    double NewCalc();
};
