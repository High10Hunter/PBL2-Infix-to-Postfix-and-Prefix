#include <bits/stdc++.h>
#include "Infix.h"
using namespace std;

void Infix::infixToPostfix()
{
    stack<char> stk;
    string result = "";

    for (int i = 0; i < (this->getExpr()).length(); i++)
    {
        if (isdigit((this->getExpr())[i]))
        {
            while (isdigit((this->getExpr())[i]))
            {
                result += (this->getExpr())[i];
                ++i;
            }
            result += ' ';
            --i;
        }
        else if ((this->getExpr())[i] == '(')
            stk.push('(');
        else if ((this->getExpr())[i] == ')')
        {
            while (stk.top() != '(')
            {
                result += stk.top();
                result += ' ';
                stk.pop();

                if (stk.empty())
                {
                    cout << "Invalid input !" << endl;
                    this->setValid(false);
                }
            }
            stk.pop();
        }
        else if (isOperator((this->getExpr())[i]))
        {
            while (!stk.empty() && priority((this->getExpr())[i]) <= priority(stk.top()))
            {
                if ((this->getExpr())[i] == '^' && stk.top() != '^')
                    break;
                else
                {
                    result += stk.top();
                    result += ' ';
                    stk.pop();
                }
            }
            stk.push((this->getExpr())[i]);
        }
        else
        {
            cout << "Invalid input !" << endl;
            this->setValid(false);
            return;
        }
    }

    while (!stk.empty())
    {
        result += stk.top();
        result += ' ';
        stk.pop();
    }

    this->setExpr(result);
}

void Infix::infixToPrefix()
{
    this->setExpr(reverseExpression(this->getExpr()));

    stack<char> stk;
    string result = "";

    for (int i = 0; i < (this->getExpr()).length(); i++)
    {
        if (isdigit((this->getExpr())[i]))
        {
            while (isdigit((this->getExpr())[i]))
            {
                result += (this->getExpr())[i];
                ++i;
            }
            result += ' ';
            --i;
        }
        else if ((this->getExpr())[i] == ')')
            stk.push((this->getExpr())[i]);
        else if ((this->getExpr())[i] == '(')
        {
            while (!stk.empty() && stk.top() != ')')
            {
                result += stk.top();
                result += ' ';
                stk.pop();

                if (stk.empty())
                {
                    cout << "Invalid input !" << endl;
                    this->setValid(false);
                }
            }
            stk.pop();
        }
        else if (Infix::isOperator((this->getExpr())[i]))
        {
            if ((this->getExpr())[i] == '^')
            {
                while (!stk.empty() && Infix::priority((this->getExpr())[i]) <= Infix::priority(stk.top()))
                {
                    result += stk.top();
                    result += ' ';
                    stk.pop();
                }
            }
            else
            {
                while (!stk.empty() && Infix::priority((this->getExpr())[i]) < Infix::priority(stk.top()))
                {
                    result += stk.top();
                    result += ' ';
                    stk.pop();
                }
            }
            stk.push((this->getExpr())[i]);
        }
        else
        {
            cout << "Invalid input !" << endl;
            this->setValid(false);
        }
    }

    while (!stk.empty())
    {
        result += stk.top();
        result += ' ';
        stk.pop();
    }

    result = reverseExpression(result);
    result.erase(0, 1);

    this->setExpr(result);
}

double Infix::evaluatePrefix()
{
    stack<double> stk;

    for (int i = (this->getExpr()).length() - 1; i >= 0; i--)
    {
        if ((this->getExpr())[i] == ' ')
            continue;
        if (isdigit((this->getExpr())[i]))
        {
            double number = 0;
            int j = i;
            while (i < (this->getExpr()).length() && isdigit((this->getExpr())[i]))
                --i;
            ++i;

            for (int k = i; k <= j; k++)
                number = number * 10 + double((this->getExpr())[k] - '0');

            stk.push(number);
        }
        else
        {
            double l = stk.top();
            stk.pop();
            double r = stk.top();
            stk.pop();
            Infix::calculateOp(stk, (this->getExpr())[i], l, r);
        }
    }

    return stk.top();
}

double Infix::evaluatePostfix()
{
    stack<double> stk;

    for (int i = 0; i < (this->getExpr()).length(); i++)
    {
        if ((this->getExpr())[i] == ' ')
            continue;
        if (isdigit((this->getExpr())[i]))
        {
            double number = 0;

            while (isdigit((this->getExpr())[i]))
            {
                number = number * 10 + double((this->getExpr())[i] - '0');
                ++i;
            }
            --i;

            stk.push(number);
        }
        else
        {
            double r = stk.top();
            stk.pop();
            double l = stk.top();
            stk.pop();
            Infix::calculateOp(stk, (this->getExpr())[i], l, r);
        }
    }

    return stk.top();
}