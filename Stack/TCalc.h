#pragma once
#include <iostream>
#include <string>
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
    TCalc(string _expr = "2 + 2");
    TCalc(const TCalc& tc); 

    bool has_correct_brackets();
    void ToPostfix();
    double Calc();
    double NewCalc();
};
