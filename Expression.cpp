#include <bits/stdc++.h>
#include <regex>
#include "Expression.h"
using namespace std;

string Expression::removeBlankSpace(string str)
{
    stringstream ss(str);
    string token;
    string res = "";

    while (ss >> token)
        res += token;

    return res;
}

string Expression::reverseExpression(string str)
{
    string res = "";
    for (int i = 0; i < str.length(); i++)
    {
        if (isdigit(str[i]))
        {
            string digit = "";
            while (isdigit(str[i]))
            {
                digit += str[i];
                ++i;
            }
            --i;
            res = digit + res;
        }
        else
            res = str[i] + res;
    }
    return res;
}

void Expression::setExpr(string new_expr)
{
    this->expr = new_expr;
}

string Expression::getExpr()
{
    return this->expr;
}

void Expression::inputExpr()
{
    getline(cin, this->expr);
    // regex rgx("^(\\d|\\()([0-9\\s\\+\\-\\*\\/\\^()])*(\\d|\\))$");
    //  if (!regex_match(this->expr, rgx))
    //  {
    //      this->valid = false;
    //      return;
    //  }
    this->setExpr(removeBlankSpace(this->getExpr()));
}

void Expression::outputExpr()
{
    if (valid)
        cout << expr;
}

bool Expression::isValid()
{
    return this->valid;
}

void Expression::setValid(bool check)
{
    this->valid = check;
}

int Expression::priority(char c)
{
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

bool Expression::isOperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
        return true;
    return false;
}

void Expression::calculateOp(stack<double> &stk, char op, double l, double r)
{
    switch (op)
    {
    case '+':
        stk.push(l + r);
        break;
    case '-':
        stk.push(l - r);
        break;
    case '*':
        stk.push(l * r);
        break;
    case '/':
        stk.push(l / r);
        break;
    case '^':
        stk.push(pow(l, r));
        break;
    }
}
