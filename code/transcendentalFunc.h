#ifndef TRANSCENDENTAL_H
#define TRANSCENDENTAL_H
#define M_PI 3.14159265358979323846

#include <iostream>
#include <math.h>
using namespace std;

long double convertToRadian(long double degree)
{
    return degree * M_PI / 180;
}

long double Log(long double r, long double n) 
{
    return log(n) / log(r);
}

long double cot(long double x)
{
    return 1 / tan(x);
}

long double acot(long double x)
{
    return (M_PI / 2) - atan(x);
}

bool validateLog(
    string expr,
    string &temp,
    vector<string> transFunc_token,
    int begin_parenthesis,
    int &i)
{
    while (expr[i] != ')')
    {
        // check transcendental function
        if (expr[i] == '(')
        {
            begin_parenthesis = i;
            if (count(transFunc_token.begin(), transFunc_token.end(), temp) == 0)
            {
                return false;
            }
        }

        temp += expr[i];
        ++i;
        // check if iterator exceed the length of the string
        if (i >= expr.length())
        {
            return false;
        }
    }

    // check valid value in parenthesis
    int begin = begin_parenthesis + 1;
    int end = i - 1;
    int count_dot = 0, count_comma = 0;
    for (int j = begin; j <= end; j++)
    {
        if (isdigit(expr[j]) || expr[j] == '.' || expr[j] == ',')
        {
            if (expr[j] == '.')
                count_dot++;
            if (expr[j] == ',')
                count_comma++;
            if (count_dot > 2 || count_comma > 1)
            {
                return false;
            }
            continue;
        }
        else
        {
            return false;
        }
    }
    // check trailing comma and dot
    if (expr[i - 1] == ',' || expr[i - 1] == '.' || expr[i - 1] == '(')
    {
        return false;
    }
    // check leading comma and dot
    if (expr[begin] == '.' || expr[begin] == ',')
    {
        return false;
    }

    return true;
}

bool validateTransFunc(
    string expr,
    string &temp,
    vector<string> transFunc_token,
    int begin_parenthesis,
    int &i)
{
    while (expr[i] != ')')
    {
        // check transcendental function
        if (expr[i] == '(')
        {
            begin_parenthesis = i;
            if (count(transFunc_token.begin(), transFunc_token.end(), temp) == 0)
            {
                return false;
            }
        }

        temp += expr[i];
        ++i;
        // check if iterator exceed the length of the string
        if (i >= expr.length())
        {
            return false;
        }
    }

    // check valid value in parenthesis
    int begin = begin_parenthesis + 1;
    int end = i - 1;
    int count_dot = 0;
    for (int j = begin; j <= end; j++)
    {
        if (expr[begin] == '-' && j == begin)
        {
            continue;
        }
        if (isdigit(expr[j]) || expr[j] == '.')
        {
            if (expr[j] == '.')
                count_dot++;
            if (count_dot > 1)
            {
                return false;
            }
            continue;
        }
        else
        {
            return false;
        }
    }

    if (expr[i - 1] == ',' || expr[i - 1] == '.' || expr[i - 1] == '(')
    {
        return false;
    }

    // check leading comma and dot
    if (expr[begin] == '.' || expr[begin] == ',')
    {
        return false;
    }

    return true;
}

#endif