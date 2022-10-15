#ifndef INFIX_H
#define INFIX_H

#include <bits/stdc++.h>
#include "Expression.h"
using namespace std;

class Infix : public Expression
{
public:
    string infixToPostfix();
    string infixToPrefix();
    long double evaluatePrefix();
    long double evaluatePostfix();
};

#endif