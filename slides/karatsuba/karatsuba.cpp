#include "karatsuba.h"
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

long long int karatsuba::multiply(long long int x, long long int y) {
    string Sx = to_string(x);
    string Sy = to_string(y);

    while (Sx.length() < Sy.length()) Sx = "0" + Sx;
    while (Sy.length() < Sx.length()) Sy = "0" + Sy;

    int len = Sx.length();

    if (len == 1)
        return x * y;

    int halfLen = len / 2;

    long long int a = stol(Sx.substr(0, halfLen));
    long long int b = stol(Sx.substr(halfLen));
    long long int c = stol(Sy.substr(0, halfLen));
    long long int d = stol(Sy.substr(halfLen));

    long long int ac = multiply(a, c);
    long long int bd = multiply(b, d);
    long long int ab_cd = multiply(a + b, c + d);

    long long int ad_bc = ab_cd - ac - bd;

    return ac * static_cast<long long int>(pow(10, 2 * (len - halfLen))) + ad_bc * static_cast<long long int>(pow(10, len - halfLen)) + bd;
}