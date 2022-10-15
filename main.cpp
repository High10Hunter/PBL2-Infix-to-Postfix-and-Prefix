#include <bits/stdc++.h>
#include "Expression.cpp"
#include "Infix.cpp"
#include "transcendentalFunc.h"
#define M_PI 3.14159265358979323846
#define endl "\n"

using namespace std;

int main()
{
    Infix expr;
    // cout << "Input a infix expression: ";
    expr.inputExprFile();
    // cout << endl;
    expr.outputExpr();
    cout << endl;

    cout << "Postfix: ";
    cout << expr.infixToPostfix();
    cout << endl;
    cout << "Value of expression: ";
    cout << expr.evaluatePostfix();
    cout << endl;

    cout << "Prefix: ";
    cout << expr.infixToPrefix();
    cout << endl;
    cout << "Value of expression: ";
    cout << expr.evaluatePrefix();
    cout << endl;

    // VeHinhBangNhap(2, 3, 115, "    INPUT INFIX EXPRESSION:");
    // gotoxy(7, 5);
    // Infix expr;
    // expr.inputExpr();
    // cout << endl;
    // cout << endl;
    // cout << endl;
    // cout << "Postfix: ";
    // cout << expr.infixToPostfix();
    // cout << endl;
    // cout << "Value of expression: ";
    // cout << expr.evaluatePostfix();
    // cout << endl;

    // cout << "Prefix: ";
    // cout << expr.infixToPrefix();
    // cout << endl;
    // cout << "Value of expression: ";
    // cout << expr.evaluatePrefix();
    // cout << endl;
}
