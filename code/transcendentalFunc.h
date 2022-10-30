#ifndef TRANSCENDENTAL_H
#define TRANSCENDENTAL_H
#define M_PI 3.14159265358979323846

#include <iostream>
#include <math.h>
using namespace std;

long double Log(long double r, long double n) // log n with base r
{
    return log(n) / log(r);
}

long double convertToRadian(long double degree)
{
    return degree * M_PI / 180;
}

long double cot(long double x)
{
    return 1 / tan(x);
}

long double acot(long double x)
{
    return (M_PI / 2) - atan(x);
}

#endif