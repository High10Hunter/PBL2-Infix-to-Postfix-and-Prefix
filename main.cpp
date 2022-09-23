#include <bits/stdc++.h>
#include "Expression.cpp"
#include "Infix.cpp"
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
        //
        //        cout << "Postfix: ";
        //        expr.infixToPostfix();
        //        expr.outputExpr();
        //        cout << endl;
        //        cout << "Value of expression: ";
        //        cout << expr.evaluatePostfix();
        //        cout << endl;

        // cout << "Prefix: ";
        // expr.infixToPrefix();
        // expr.outputExpr();
        // cout << endl;
        // cout << "Value of expression: ";
        // cout << expr.evaluatePrefix();
    }
    else
        cout << "Invalid input !" << endl;
}
