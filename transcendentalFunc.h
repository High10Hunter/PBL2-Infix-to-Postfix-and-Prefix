#ifndef TRANSCENDENTAL_H
#define TRANSCENDENTAL_H

#include <iostream>
#include <math.h>
using namespace std;

double Log(double r, double n) // log n with base r
{
    return log(n) / log(r);
}

double cot(double x)
{
    return 1 / tan(x);
}

#endif