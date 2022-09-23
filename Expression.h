#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <bits/stdc++.h>
using namespace std;

class Expression
{
private:
    string expr;
    bool valid = true;

public:
    string getExpr();
    void setExpr(string new_expr);
    bool isValid();
    void setValid(bool);
    void inputExpr();
    void outputExpr();
    static string removeBlankSpace(string str);
    static string reverseExpression(string infix);
    static int priority(char op);
    static bool isOperator(char c);
    static void calculateOp(stack<double> &stk, char op, double l, double r);
};

#endif