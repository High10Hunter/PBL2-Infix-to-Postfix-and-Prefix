#include <bits/stdc++.h>
#include "Expression.cpp"
#include "Infix.cpp"
#include "transcendentalFunc.h"
using namespace std;

int main()
{
    Infix expr;
    cout << "Input a infix expression: ";
    expr.inputExpr();
    if (expr.isValid())
    {
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
    }
    else
        cout << "Invalid input !" << endl;
}
