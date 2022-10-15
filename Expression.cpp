#include <bits/stdc++.h>
#include "Expression.h"
#include <windows.h>
#include <tchar.h>
#include <conio.h>
#include "drawGUI.cpp"
#include "mylib.cpp"

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
        else if (str[i] == 'L')
        {
            string smallFunc = "";
            while (str[i] != ')')
            {
                smallFunc += str[i];
                ++i;
            }
            smallFunc += str[i];
            res = smallFunc + res;
        }
        else if (str[i] == 'a')
        {
            string smallFunc = "";
            while (str[i] != ')')
            {
                smallFunc += str[i];
                ++i;
            }
            smallFunc += str[i];
            res = smallFunc + res;
        }
        else if (str[i] == 's')
        {
            string smallFunc = "";
            while (str[i] != ')')
            {
                smallFunc += str[i];
                ++i;
            }
            smallFunc += str[i];
            res = smallFunc + res;
        }
        else if (str[i] == 'c')
        {
            string smallFunc = "";
            while (str[i] != ')')
            {
                smallFunc += str[i];
                ++i;
            }
            smallFunc += str[i];
            res = smallFunc + res;
        }
        else if (str[i] == 't')
        {
            string smallFunc = "";
            while (str[i] != ')')
            {
                smallFunc += str[i];
                ++i;
            }
            smallFunc += str[i];
            res = smallFunc + res;
        }
        else if (str[i] == 'e')
        {
            string smallFunc = "";
            while (str[i] != ')')
            {
                smallFunc += str[i];
                ++i;
            }
            smallFunc += str[i];
            res = smallFunc + res;
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
    // getline(cin, this->expr);
    // this->setExpr(removeBlankSpace(this->getExpr()));

    // ShowCur(true);
    string result = "";
    int nSpace = 0;
    int count = 0;

    while (true)
    {
        while (_kbhit())
        {
            int kb_hit = _getch();
            string validateChar = "Logsincostancotexpsqrtarc()+-/*^,.";
            if ((validateChar.find(kb_hit) != string::npos) || (kb_hit == SPACE) || (kb_hit >= 48 && kb_hit <= 57) && count < 105 && count >= 0)
            {
                if (nSpace == 1 && kb_hit == SPACE)
                {
                    count++;
                    cout << (char)kb_hit;
                    result += (char)kb_hit;
                    nSpace = 0;
                }
                else if (kb_hit != SPACE)
                {
                    count++;
                    cout << (char)kb_hit;
                    result += (char)kb_hit;
                    nSpace = 1;
                }
            }
            else if (kb_hit == ENTER)
            {
                this->setExpr(removeBlankSpace(result));
                return;
            }
            else if (kb_hit == BACKSPACE && count > 0)
            {
                cout << "\b"
                     << " "
                     << "\b";
                count--;
                result.erase(result.length() - 1, 1);
            }
            else if (kb_hit == ESC)
            {
                result = "";
                this->setExpr(removeBlankSpace(result));
                return;
            }
        }
    }
}

void Expression::inputExprFile()
{
    fstream file;
    string word, filename;

    cout << "Enter your file name: ";
    cin >> filename;

    string temp = "";

    file.open(filename.c_str());

    while (file >> word)
    {
        temp += word;
    }

    string result = "";
    string validateChar = "Logsincostancotexpsqrtarc()+-/*^,.";
    for (int i = 0; i < temp.length(); i++)
    {
        if ((validateChar.find(temp[i]) != string::npos) || ((int)temp[i] >= 48 && (int)temp[i] <= 57))
        {
            result += temp[i];
        }
        else
        {
            cout << "Invalid input !";
            result = "";
            this->setExpr(result);
            return;
        }
    }

    file.close();
    this->setExpr(result);
}

void Expression::outputExpr()
{
    cout << expr;
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

void Expression::calculateOp(stack<long double> &stk, char op, long double l, long double r)
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
