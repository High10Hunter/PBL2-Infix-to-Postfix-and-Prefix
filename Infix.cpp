#include <bits/stdc++.h>
#include "Infix.h"
#include "transcendentalFunc.h"
using namespace std;

string Infix::infixToPostfix()
{
    stack<char> stk;
    string result = "";

    string expr = this->getExpr();

    for (int i = 0; i < expr.length(); i++)
    {
        if (isdigit(expr[i]))
        {
            while (isdigit(expr[i]))
            {
                result += expr[i];
                ++i;
            }
            result += ' ';
            --i;
        }
        else if (expr[i] == 'L')
        {
            while (expr[i] != ')')
            {
                result += expr[i];
                ++i;
            }
            result += expr[i];
            result += ' ';
        }
        else if (expr[i] == 'S')
        {
            while (expr[i] != ')')
            {
                result += expr[i];
                ++i;
            }
            result += expr[i];
            result += ' ';
        }
        else if (expr[i] == 's')
        {
            while (expr[i] != ')')
            {
                result += expr[i];
                ++i;
            }
            result += expr[i];
            result += ' ';
        }
        else if (expr[i] == 'c')
        {
            while (expr[i] != ')')
            {
                result += expr[i];
                ++i;
            }
            result += expr[i];
            result += ' ';
        }
        else if (expr[i] == 't')
        {
            while (expr[i] != ')')
            {
                result += expr[i];
                ++i;
            }
            result += expr[i];
            result += ' ';
        }
        else if (expr[i] == 'e')
        {
            while (expr[i] != ')')
            {
                result += expr[i];
                ++i;
            }
            result += expr[i];
            result += ' ';
        }
        else if (expr[i] == '(')
            stk.push('(');
        else if (expr[i] == ')')
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
        else if (isOperator(expr[i]))
        {
            while (!stk.empty() && priority(expr[i]) <= priority(stk.top()))
            {
                if (expr[i] == '^' && stk.top() != '^')
                    break;
                else
                {
                    result += stk.top();
                    result += ' ';
                    stk.pop();
                }
            }
            stk.push(expr[i]);
        }
        else
        {
            cout << "Invalid input !" << endl;
            this->setValid(false);
            return "";
        }
    }

    while (!stk.empty())
    {
        result += stk.top();
        result += ' ';
        stk.pop();
    }

    // this->setExpr(result);
    return result;
}

string Infix::infixToPrefix()
{
    // this->setExpr(reverseExpression(this->getExpr()));
    string expr = reverseExpression(this->getExpr());

    stack<char> stk;
    string result = "";

    // string expr = this->getExpr();

    for (int i = 0; i < expr.length(); i++)
    {
        if (isdigit(expr[i]))
        {
            while (isdigit(expr[i]))
            {
                result += expr[i];
                ++i;
            }
            result += ' ';
            --i;
        }
        else if (expr[i] == 'L')
        {
            while (expr[i] != ')')
            {
                result += expr[i];
                ++i;
            }
            result += expr[i];
            result += ' ';
        }
        else if (expr[i] == 'S')
        {
            while (expr[i] != ')')
            {
                result += expr[i];
                ++i;
            }
            result += expr[i];
            result += ' ';
        }
        else if (expr[i] == 's')
        {
            while (expr[i] != ')')
            {
                result += expr[i];
                ++i;
            }
            result += expr[i];
            result += ' ';
        }
        else if (expr[i] == 'c')
        {
            while (expr[i] != ')')
            {
                result += expr[i];
                ++i;
            }
            result += expr[i];
            result += ' ';
        }
        else if (expr[i] == 't')
        {
            while (expr[i] != ')')
            {
                result += expr[i];
                ++i;
            }
            result += expr[i];
            result += ' ';
        }
        else if (expr[i] == 'e')
        {
            while (expr[i] != ')')
            {
                result += expr[i];
                ++i;
            }
            result += expr[i];
            result += ' ';
        }
        else if (expr[i] == ')')
            stk.push(expr[i]);
        else if (expr[i] == '(')
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
        else if (Infix::isOperator(expr[i]))
        {
            if (expr[i] == '^')
            {
                while (!stk.empty() && Infix::priority(expr[i]) <= Infix::priority(stk.top()))
                {
                    result += stk.top();
                    result += ' ';
                    stk.pop();
                }
            }
            else
            {
                while (!stk.empty() && Infix::priority(expr[i]) < Infix::priority(stk.top()))
                {
                    result += stk.top();
                    result += ' ';
                    stk.pop();
                }
            }
            stk.push(expr[i]);
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

    // this->setExpr(result);
    return result;
}

double Infix::evaluatePrefix()
{
    stack<double> stk;

    string expr = this->infixToPrefix();

    for (int i = expr.length() - 1; i >= 0; i--)
    {
        if (expr[i] == ' ')
            continue;
        if (isdigit(expr[i]))
        {
            double number = 0;
            int j = i;
            while (i < expr.length() && isdigit(expr[i]))
                --i;
            ++i;

            for (int k = i; k <= j; k++)
                number = number * 10 + double(expr[k] - '0');

            stk.push(number);
        }
        else if (expr[i] == ')')
        {
            string tempFunc = "";
            while (expr[i] != ' ' && i >= 0)
            {
                tempFunc = expr[i] + tempFunc;
                --i;
            }
            ++i;
            if (tempFunc[0] == 'L')
            {
                int k = 4;
                double r = 0;
                while (tempFunc[k] != ',')
                {
                    r = r * 10 + double(tempFunc[k] - '0');
                    ++k;
                }
                ++k;
                double n = 0;
                while (tempFunc[k] != ')')
                {
                    n = n * 10 + double(tempFunc[k] - '0');
                    ++k;
                }

                double number = Log(r, n);
                stk.push(number);
            }
            else if (tempFunc[0] == 's')
            {
                if (tempFunc[1] == 'i')
                {
                    int k = 4;
                    double n = 0;
                    while (tempFunc[k] != ')')
                    {
                        n = n * 10 + double(tempFunc[k] - '0');
                        ++k;
                    }

                    double number = sin(n);
                    stk.push(number);
                }
                else if (tempFunc[1] == 'q')
                {
                    int k = 5;
                    double n = 0;
                    while (tempFunc[k] != ')')
                    {
                        n = n * 10 + double(tempFunc[k] - '0');
                        ++k;
                    }

                    double number = sqrt(n);
                    stk.push(number);
                }
            }
            else if (tempFunc[0] == 'c')
            {
                if (tempFunc[2] == 's')
                {
                    int k = 4;
                    double n = 0;
                    while (tempFunc[k] != ')')
                    {
                        n = n * 10 + double(tempFunc[k] - '0');
                        ++k;
                    }

                    double number = cos(n);
                    stk.push(number);
                }
                else if (tempFunc[2] == 't')
                {
                    int k = 4;
                    double n = 0;
                    while (tempFunc[k] != ')')
                    {
                        n = n * 10 + double(tempFunc[k] - '0');
                        ++k;
                    }

                    double number = cot(n);
                    stk.push(number);
                }
            }
            else if (tempFunc[0] == 't')
            {
                int k = 4;
                double n = 0;
                while (tempFunc[k] != ')')
                {
                    n = n * 10 + double(tempFunc[k] - '0');
                    ++k;
                }

                double number = tan(n);
                stk.push(number);
            }
            else if (tempFunc[0] == 'e')
            {
                int k = 4;
                double n = 0;
                while (tempFunc[k] != ')')
                {
                    n = n * 10 + double(tempFunc[k] - '0');
                    ++k;
                }

                double number = exp(n);
                stk.push(number);
            }
        }
        else
        {
            double l = stk.top();
            stk.pop();
            double r = stk.top();
            stk.pop();
            Infix::calculateOp(stk, expr[i], l, r);
        }
    }

    return stk.top();
}

double Infix::evaluatePostfix()
{
    stack<double> stk;

    string expr = this->infixToPostfix();

    for (int i = 0; i < expr.length(); i++)
    {
        if (expr[i] == ' ')
            continue;
        if (isdigit(expr[i]))
        {
            double number = 0;

            while (isdigit(expr[i]))
            {
                number = number * 10 + double(expr[i] - '0');
                ++i;
            }
            --i;

            stk.push(number);
        }
        else if (isalpha(expr[i]))
        {
            string tempFunc = "";
            while (expr[i] != ')' && i < expr.length())
            {
                tempFunc += expr[i];
                ++i;
            }
            tempFunc += expr[i];

            if (tempFunc[0] == 'L')
            {
                int k = 4;
                double r = 0;
                while (tempFunc[k] != ',')
                {
                    r = r * 10 + double(tempFunc[k] - '0');
                    ++k;
                }
                ++k;
                double n = 0;
                while (tempFunc[k] != ')')
                {
                    n = n * 10 + double(tempFunc[k] - '0');
                    ++k;
                }

                double number = Log(r, n);
                stk.push(number);
            }
            else if (tempFunc[0] == 's')
            {
                if (tempFunc[1] == 'i')
                {
                    int k = 4;
                    double n = 0;
                    while (tempFunc[k] != ')')
                    {
                        n = n * 10 + double(tempFunc[k] - '0');
                        ++k;
                    }

                    double number = sin(n);
                    stk.push(number);
                }
                else if (tempFunc[1] == 'q')
                {
                    int k = 5;
                    double n = 0;
                    while (tempFunc[k] != ')')
                    {
                        n = n * 10 + double(tempFunc[k] - '0');
                        ++k;
                    }

                    double number = sqrt(n);
                    stk.push(number);
                }
            }
            else if (tempFunc[0] == 'c')
            {
                if (tempFunc[2] == 's')
                {
                    int k = 4;
                    double n = 0;
                    while (tempFunc[k] != ')')
                    {
                        n = n * 10 + double(tempFunc[k] - '0');
                        ++k;
                    }

                    double number = cos(n);
                    stk.push(number);
                }
                else if (tempFunc[2] == 't')
                {
                    int k = 4;
                    double n = 0;
                    while (tempFunc[k] != ')')
                    {
                        n = n * 10 + double(tempFunc[k] - '0');
                        ++k;
                    }

                    double number = cot(n);
                    stk.push(number);
                }
            }
            else if (tempFunc[0] == 't')
            {
                int k = 4;
                double n = 0;
                while (tempFunc[k] != ')')
                {
                    n = n * 10 + double(tempFunc[k] - '0');
                    ++k;
                }

                double number = tan(n);
                stk.push(number);
            }
            else if (tempFunc[0] == 'e')
            {
                int k = 4;
                double n = 0;
                while (tempFunc[k] != ')')
                {
                    n = n * 10 + double(tempFunc[k] - '0');
                    ++k;
                }

                double number = exp(n);
                stk.push(number);
            }
        }
        else
        {
            double r = stk.top();
            stk.pop();
            double l = stk.top();
            stk.pop();
            Infix::calculateOp(stk, expr[i], l, r);
        }
    }

    return stk.top();
}