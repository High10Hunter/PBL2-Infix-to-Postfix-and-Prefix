#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <bits/stdc++.h>
using namespace std;

class Expression
{
protected:
    string expr;

public:
    string getExpr();
    void setExpr(string new_expr);
    void inputExpr();
    void inputExprFile();
    void outputExpr();
    static string removeBlankSpace(string str);
    static string reverseExpression(string infix);
    static int priority(char op);
    static bool isOperator(char c);
    static void calculateOp(stack<double> &stk, char op, double l, double r);
};

#endif