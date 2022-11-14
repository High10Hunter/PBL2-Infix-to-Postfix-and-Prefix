#include <bits/stdc++.h>
#include "Infix.h"
#include "transcendentalFunc.h"
using namespace std;

vector<string> transFunc_token{"Log", "sin", "cos", "tan", "cot", "exp", "sqrt", "arcsin", "arccos", "arctan", "arccot"};

string Infix::infixToPostfix()
{
    stack<char> stk;
    string result = "";
    bool allOperator = true;

    string expr = this->getExpr();

    for (int i = 0; i < expr.length(); i++)
    {
        if (isdigit(expr[i]))
        {
            allOperator = false;

            while (isdigit(expr[i]) || expr[i] == '.')
            {
                result += expr[i];
                ++i;
            }
            result += ' ';
            --i;
        }
        else if (expr[i] == 'L')
        {
            allOperator = false;
            int begin_parenthesis = i;
            string temp = "";

            if (!validateLog(expr, temp, transFunc_token, begin_parenthesis, i))
            {
                throw runtime_error("Invalid Expression");
            }
            else
            {
                temp += expr[i];
                result += temp;
                result += ' ';
            }
        }
        else if (expr[i] == 'a')
        {
            allOperator = false;
            int begin_parenthesis = i;
            string temp = "";

            if (!validateTransFunc(expr, temp, transFunc_token, begin_parenthesis, i))
            {
                throw runtime_error("Invalid Expression");
            }
            else
            {
                temp += expr[i];
                result += temp;
                result += ' ';
            }
        }
        else if (expr[i] == 's')
        {
            allOperator = false;
            int begin_parenthesis = i;
            string temp = "";

            if (!validateTransFunc(expr, temp, transFunc_token, begin_parenthesis, i))
            {
                throw runtime_error("Invalid expression");
            }
            else
            {
                temp += expr[i];
                result += temp;
                result += ' ';
            }
        }
        else if (expr[i] == 'c')
        {
            allOperator = false;
            int begin_parenthesis = i;
            string temp = "";

            if (!validateTransFunc(expr, temp, transFunc_token, begin_parenthesis, i))
            {
                throw runtime_error("Invalid expression");
            }
            else
            {
                temp += expr[i];
                result += temp;
                result += ' ';
            }
        }
        else if (expr[i] == 't')
        {
            allOperator = false;
            int begin_parenthesis = i;
            string temp = "";

            if (!validateTransFunc(expr, temp, transFunc_token, begin_parenthesis, i))
            {
                throw runtime_error("Invalid expression");
            }
            else
            {
                temp += expr[i];
                result += temp;
                result += ' ';
            }
        }
        else if (expr[i] == 'e')
        {
            allOperator = false;
            int begin_parenthesis = i;
            string temp = "";

            if (!validateTransFunc(expr, temp, transFunc_token, begin_parenthesis, i))
            {
                throw runtime_error("Invalid expression");
            }
            else
            {
                temp += expr[i];
                result += temp;
                result += ' ';
            }
        }
        else if (expr[i] == '(')
            stk.push('(');
        else if (expr[i] == ')')
        {
            if (stk.empty())
            {
                throw runtime_error("Invalid input !");
            }

            while (stk.top() != '(')
            {
                result += stk.top();
                result += ' ';
                stk.pop();

                if (stk.empty())
                {
                    throw runtime_error("Invalid input !");
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
            throw runtime_error("Invalid input !");
        }
    }

    if (allOperator)
    {
        throw runtime_error("Invalid input !");
    }

    while (!stk.empty())
    {
        if (stk.top() == '(')
        {
            throw runtime_error("Invalid input !");
        }

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
            while (isdigit(expr[i]) || expr[i] == '.')
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
        else if (expr[i] == 'a')
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
            // double number = 0;
            string number = "";
            int j = i;
            while (i < expr.length() && (isdigit(expr[i]) || expr[i] == '.'))
                --i;
            ++i;

            for (int k = i; k <= j; k++)
                // number = number * 10 + double(expr[k] - '0');
                number += expr[k];

            stk.push(stold(number));
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
                // double r = 0;
                string r = "";
                while (tempFunc[k] != ',')
                {
                    // r = r * 10 + double(tempFunc[k] - '0');
                    r += tempFunc[k];
                    ++k;
                }
                ++k;
                // double n = 0;
                string n = "";
                while (tempFunc[k] != ')')
                {
                    // n = n * 10 + double(tempFunc[k] - '0');
                    n += tempFunc[k];
                    ++k;
                }

                double number = Log(stold(r), stold(n));
                stk.push(number);
            }
            else if (tempFunc[0] == 's')
            {
                if (tempFunc[1] == 'i')
                {
                    int k = 4;
                    // double n = 0;
                    string n = "";
                    while (tempFunc[k] != ')')
                    {
                        // n = n * 10 + double(tempFunc[k] - '0');
                        n += tempFunc[k];
                        ++k;
                    }

                    double number = sin(convertToRadian(stold(n)));
                    stk.push(number);
                }
                else if (tempFunc[1] == 'q')
                {
                    int k = 5;
                    // double n = 0;
                    string n = "";
                    while (tempFunc[k] != ')')
                    {
                        // n = n * 10 + double(tempFunc[k] - '0');
                        n += tempFunc[k];
                        ++k;
                    }

                    double number = sqrt(stold(n));
                    stk.push(number);
                }
            }
            else if (tempFunc[0] == 'c')
            {
                if (tempFunc[2] == 's')
                {
                    int k = 4;
                    // double n = 0;
                    string n = "";
                    while (tempFunc[k] != ')')
                    {
                        // n = n * 10 + double(tempFunc[k] - '0');
                        n += tempFunc[k];
                        ++k;
                    }

                    double number = cos(convertToRadian(stold(n)));
                    stk.push(number);
                }
                else if (tempFunc[2] == 't')
                {
                    int k = 4;
                    // double n = 0;
                    string n = "";
                    while (tempFunc[k] != ')')
                    {
                        // n = n * 10 + double(tempFunc[k] - '0');
                        n += tempFunc[k];
                        ++k;
                    }

                    double number = cot(convertToRadian(stold(n)));
                    stk.push(number);
                }
            }
            else if (tempFunc[0] == 't')
            {
                int k = 4;
                // double n = 0;
                string n = "";
                while (tempFunc[k] != ')')
                {
                    // n = n * 10 + double(tempFunc[k] - '0');
                    n += tempFunc[k];
                    ++k;
                }

                double number = tan(convertToRadian(stold(n)));
                stk.push(number);
            }
            else if (tempFunc[0] == 'e')
            {
                int k = 4;
                // double n = 0;
                string n = "";
                while (tempFunc[k] != ')')
                {
                    // n = n * 10 + double(tempFunc[k] - '0');
                    n += tempFunc[k];
                    ++k;
                }

                double number = exp(stold(n));
                stk.push(number);
            }
            else if (tempFunc[0] == 'a') // arcsin(x), arccos, arctan, arccot
            {
                if (tempFunc[3] == 's')
                {
                    int k = 7;
                    string n = "";
                    while (tempFunc[k] != ')')
                    {
                        // n = n * 10 + double(tempFunc[k] - '0');
                        n += tempFunc[k];
                        ++k;
                    }

                    double number = asin(stold(n));
                    stk.push(number);
                }
                else if (tempFunc[3] == 't')
                {
                    int k = 7;
                    string n = "";
                    while (tempFunc[k] != ')')
                    {
                        // n = n * 10 + double(tempFunc[k] - '0');
                        n += tempFunc[k];
                        ++k;
                    }

                    double number = atan(stold(n));
                    stk.push(number);
                }
                else if (tempFunc[3] == 'c')
                {
                    if (tempFunc[5] == 's')
                    {
                        int k = 7;
                        string n = "";
                        while (tempFunc[k] != ')')
                        {
                            // n = n * 10 + double(tempFunc[k] - '0');
                            n += tempFunc[k];
                            ++k;
                        }

                        double number = acos(stold(n));
                        stk.push(number);
                    }
                    else if (tempFunc[5] == 't')
                    {
                        int k = 7;
                        string n;
                        while (tempFunc[k] != ')')
                        {
                            // n = n * 10 + double(tempFunc[k] - '0');
                            n += tempFunc[k];
                            ++k;
                        }

                        double number = acot(stold(n));
                        stk.push(number);
                    }
                }
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
            string number = "";

            while (isdigit(expr[i]) || expr[i] == '.')
            {
                // number = number * 10 + double(expr[i] - '0');
                number += expr[i];
                ++i;
            }
            --i;

            stk.push(stold(number));
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
                // double r = 0;
                string r = "";
                while (tempFunc[k] != ',')
                {
                    // r = r * 10 + double(tempFunc[k] - '0');
                    r += tempFunc[k];
                    ++k;
                }
                ++k;
                // double n = 0;
                string n = "";
                while (tempFunc[k] != ')')
                {
                    // n = n * 10 + double(tempFunc[k] - '0');
                    n += tempFunc[k];
                    ++k;
                }

                double number = Log(stold(r), stold(n));
                stk.push(number);
            }
            else if (tempFunc[0] == 's')
            {
                if (tempFunc[1] == 'i')
                {
                    int k = 4;
                    // double n = 0;
                    string n = "";
                    while (tempFunc[k] != ')')
                    {
                        // n = n * 10 + double(tempFunc[k] - '0');
                        n += tempFunc[k];
                        ++k;
                    }

                    double number = sin(convertToRadian(stold(n)));
                    stk.push(number);
                }
                else if (tempFunc[1] == 'q')
                {
                    int k = 5;
                    // double n = 0;
                    string n = "";
                    while (tempFunc[k] != ')')
                    {
                        // n = n * 10 + double(tempFunc[k] - '0');
                        n += tempFunc[k];
                        ++k;
                    }

                    double number = sqrt(stold(n));
                    stk.push(number);
                }
            }
            else if (tempFunc[0] == 'c')
            {
                if (tempFunc[2] == 's')
                {
                    int k = 4;
                    // double n = 0;
                    string n = "";
                    while (tempFunc[k] != ')')
                    {
                        // n = n * 10 + double(tempFunc[k] - '0');
                        n += tempFunc[k];
                        ++k;
                    }

                    double number = cos(convertToRadian(stold(n)));
                    stk.push(number);
                }
                else if (tempFunc[2] == 't')
                {
                    int k = 4;
                    // double n = 0;
                    string n = "";
                    while (tempFunc[k] != ')')
                    {
                        // n = n * 10 + double(tempFunc[k] - '0');
                        n += tempFunc[k];
                        ++k;
                    }

                    double number = cot(convertToRadian(stold(n)));
                    stk.push(number);
                }
            }
            else if (tempFunc[0] == 't')
            {
                int k = 4;
                // double n = 0;
                string n = "";
                while (tempFunc[k] != ')')
                {
                    // n = n * 10 + double(tempFunc[k] - '0');
                    n += tempFunc[k];
                    ++k;
                }

                double number = tan(convertToRadian(stold(n)));
                stk.push(number);
            }
            else if (tempFunc[0] == 'e')
            {
                int k = 4;
                // double n = 0;
                string n = "";
                while (tempFunc[k] != ')')
                {
                    // n = n * 10 + double(tempFunc[k] - '0');
                    n += tempFunc[k];
                    ++k;
                }

                double number = exp(stold(n));
                stk.push(number);
            }
            else if (tempFunc[0] == 'a') // arcsin(x), arccos, arctan, arccot
            {
                if (tempFunc[3] == 's')
                {
                    int k = 7;
                    string n = "";
                    while (tempFunc[k] != ')')
                    {
                        // n = n * 10 + double(tempFunc[k] - '0');
                        n += tempFunc[k];
                        ++k;
                    }

                    if (stold(n) > 1 || stold(n) < -1)
                    {
                        throw runtime_error("arcsin(x) is not defined for x > 1 or x < -1");
                    }

                    double number = asin(stold(n));
                    stk.push((number * 180) / M_PI);
                }
                else if (tempFunc[3] == 't')
                {
                    int k = 7;
                    string n = "";
                    while (tempFunc[k] != ')')
                    {
                        // n = n * 10 + double(tempFunc[k] - '0');
                        n += tempFunc[k];
                        ++k;
                    }

                    double number = atan(stold(n));
                    stk.push((number * 180) / M_PI);
                }
                else if (tempFunc[3] == 'c')
                {
                    if (tempFunc[5] == 's')
                    {
                        int k = 7;
                        string n = "";
                        while (tempFunc[k] != ')')
                        {
                            // n = n * 10 + double(tempFunc[k] - '0');
                            n += tempFunc[k];
                            ++k;
                        }

                        if (stold(n) > 1 || stold(n) < -1)
                        {
                            throw runtime_error("arccos(x) is not defined for x > 1 or x < -1");
                        }

                        double number = acos(stold(n));
                        stk.push((number * 180) / M_PI);
                    }
                    else if (tempFunc[5] == 't')
                    {
                        int k = 7;
                        string n;
                        while (tempFunc[k] != ')')
                        {
                            // n = n * 10 + double(tempFunc[k] - '0');
                            n += tempFunc[k];
                            ++k;
                        }

                        double number = acot(stold(n));
                        stk.push((number * 180) / M_PI);
                    }
                }
            }
        }
        else
        {
            bool check_right = false, check_left = false;
            double r, l;

            if (!stk.empty())
            {
                check_right = true;
                r = stk.top();
                stk.pop();
            }

            if (!stk.empty())
            {
                check_left = true;
                l = stk.top();
                stk.pop();
            }

            if (check_right && check_left)
                Infix::calculateOp(stk, expr[i], l, r);
            else
            {
                throw runtime_error("Cannot calculate expression");
            }
        }
    }

    return stk.top();
}