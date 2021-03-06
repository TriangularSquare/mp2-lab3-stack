#include "TCalc.h"
#include <iostream>
#include <string>
#include <cmath>
#include <sstream>



inline int TCalc::prior(char op)
{
    switch (op) {
    case '(': return 0;
    case '+': return 1;
    case '-': return 1;
    case '*': return 2;
    case '/': return 2;
    case '^': return 3;
    }
}

TCalc::TCalc(std::string _expr)
{
    expr = _expr;
}

TCalc::TCalc(const TCalc& tc)
{
    expr = tc.expr;
    pstfix = tc.pstfix;
    st_char = tc.st_char;
    st_d = tc.st_d;
}

bool TCalc::CorrectBrackets() {
    for (int i = 0; i < expr.length(); i++) {
        if (expr[i] == '(') {
            st_char.Push(expr[i]);
        }
        else if (expr[i] == ')') {
            if (st_char.IsEmpty()) {
                return false;
            }
            else {
                st_char.Pop();
            }
        }
    }
    return st_char.IsEmpty();
}

void TCalc::ToPostfix()
{
    string infix = "(" + expr + ")";
    pstfix = "";
    st_char.Clear();
    for (int i = 0; i < infix.size(); i++) {
        if (isdigit(infix[i])) {
            size_t idx;
            double tmp = stod(&infix[i], &idx);
            ostringstream ss;
            ss << tmp;

            pstfix += ss.str();
            pstfix += " ";
            i += idx - 1;
        }
        else if (infix[i] == '(') {
            st_char.Push(infix[i]);
        }
        else if (infix[i] == ')') {
            while (st_char.Top() != '(') {
                pstfix += st_char.Pop();
                pstfix += " ";
            }
            st_char.Pop();
        }
        else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/' || infix[i] == '^') {
            while (prior(infix[i]) <= prior(st_char.Top())) {
                pstfix += st_char.Pop();
                pstfix += " ";
            }
            st_char.Push(infix[i]);
        }
    }

    if (!pstfix.empty()) {
        pstfix.pop_back();
    }
}



string TCalc::GetPostfix()
{
    return pstfix;
}

double TCalc::Calc() {
    if (pstfix.empty()) throw "ERROR";
    for (int i = 0; i < pstfix.length(); i++)
    {
        if (pstfix[i] >= '0' && pstfix[i] <= '9') {

            size_t idx;
            double tmp = stod(&pstfix[i], &idx);
            st_d.Push(tmp);

            i += idx - 1;
        }
        else if (pstfix[i] == '+' || pstfix[i] == '-' ||
            pstfix[i] == '*' || pstfix[i] == '/' || pstfix[i] == '^') {
            double second;
            double first;

            if (!(st_d.IsEmpty())) {
                second = st_d.Pop();
            }
            else throw "ERROR";

            if (!(st_d.IsEmpty())) {
                first = st_d.Pop();
            }
            else throw "ERROR";


            switch (pstfix[i]) {
            case '+':
                st_d.Push(first + second);
                break;
            case '-':
                st_d.Push(first - second);
                break;
            case '*':
                st_d.Push(first * second);
                break;
            case '/':
                st_d.Push(first / second);
                break;
            case '^':
                st_d.Push(pow(first, second));
                break;
            }
        }
    }

    if (!(st_d.IsEmpty())) {
        double result = st_d.Pop();
        if (!(st_d.IsEmpty())) {
            throw "ERROR";
        }
        return result;
    }
    else {
        throw "ERROR";
    }
}

double TCalc::NewCalc()
{
    string infix = "(" + expr + ")";

    st_char.Clear();
    st_d.Clear();

    for (int i = 0; i < infix.length(); i++)
    {
        if (infix[i] == '(')
        {
            st_char.Push(infix[i]);
        }
        else if (isdigit(infix[i]))
        {
            size_t idx;
            double tmp = stod(&infix[i], &idx);
            st_d.Push(tmp);
            i += idx - 1;
        }
        else if ((infix[i] == '+') || (infix[i] == '-') || (infix[i] == '*') || (infix[i] == '/') || (infix[i] == '^'))
        {
            while (prior(infix[i]) <= prior(st_char.Top()))
            {
                if (st_d.IsEmpty())
                    throw "ERROR";
                double second = st_d.Pop();

                if (st_d.IsEmpty())
                    throw "ERROR";
                double first = st_d.Pop();

                char op = st_char.Pop();

                switch (op)
                {
                case '+':
                    st_d.Push(first + second);
                    break;
                case '-':
                    st_d.Push(first - second);
                    break;
                case '*':
                    st_d.Push(first * second);
                    break;
                case '/':
                    st_d.Push(first / second);
                    break;
                case '^':
                    st_d.Push(pow(first, second));
                    break;
                }
            }
            st_char.Push(infix[i]);
        }
        else if (infix[i] == ')')
        {
            while (st_char.Top() != '(')
            {
                if (st_d.IsEmpty()) throw "ERROR";
                double second = st_d.Pop();

                if (st_d.IsEmpty()) throw "ERROR";
                double first = st_d.Pop();

                char op = st_char.Pop();

                switch (op)
                {
                case '+':
                    st_d.Push(first + second);
                    break;
                case '-':
                    st_d.Push(first - second);
                    break;
                case '*':
                    st_d.Push(first * second);
                    break;
                case '/':
                    st_d.Push(first / second);
                    break;
                case '^':
                    st_d.Push(pow(first, second));
                    break;
                }
            }
            st_char.Pop();
        }
    }

    if (st_d.IsEmpty()) throw "ERROR";
    double result = st_d.Pop();

    if (!(st_d.IsEmpty())) throw "ERROR";

    return result;
}
