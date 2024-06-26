#include "Try.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

Try::Try() : a(1), b(1), c(1) {}

Try::Try(const Try& t) : a(t.a), b(t.b), c(t.c) {}

Try::Try(int a, int b, int c) : a(a), b(b), c(c) {}

void Try::print() const
{
    cout << "trychlen: " << a << "x^2 + " << b << "x + " << c << endl;
}

float Try::discr() const
{
    return ((b * b) - 4 * a * c);
}

float Try::find_roots()
{
    vector<float> roots;
    if (discr() < 0) {
        cout << "there are no roots" << endl;
        return 0;
    }
    else if (discr() == 0) {
        cout << "roots are: " << (-b) / (2 * a) << endl;
        return (-b) / (2 * a);
    }
    else if (discr() > 0) {
        cout << "roots: ";
        roots.push_back(((-b) + sqrt(discr())) / (2 * a));
        roots.push_back(((-b) - sqrt(discr())) / (2 * a));
        for (const auto& i : roots) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 1;
}

void Try::add(int n)
{
    a += n;
    b += n;
    c += n;
}

void Try::minus(int n)
{
    a -= n;
    b -= n;
    c -= n;
}

void Try::multiply(int n)
{
    a *= n;
    b *= n;
    c *= n;
}

int Try::get_a() const
{
    return a;
}

void Try::set_a(int new_a)
{
    a = new_a;
}

void Try::set_b(int new_b)
{
    b = new_b;
}

void Try::set_c(int new_c)
{
    c = new_c;
}

int Try::get_b() const
{
    return b;
}

int Try::get_c() const
{
    return c;
}

istream& operator>>(istream& is, Try& t)
{
    is >> t.a >> t.b >> t.c;
    return is;
}

istream& operator>>(istream& is, Z& t)
{
    is >> t.b >> t.c;
    return is;
}

Z::Z() : Try() {}

Z::Z(const Z& t) : Try(t),b( t.b), c(t.c) {}

Z::Z(int b, int c) : Try(), b(b), c(c) {}

void Z::print() const
{
    cout << "zvedenyi trychlen: " << "x^2 + " << b << "x + " << c << endl;
}

float Z::discr() const
{
    return ((b * b) - 4 * c);
}

float Z::find_roots()
{
    vector<float> roots;
    if (discr() < 0) {
        cout << "there are no roots" << endl;
        return 0;
    }
    else if (discr() == 0) {
        cout << "roots are: " << (-b) / 2 << endl;
        return (-b) / 2;
    }
    else if (discr() > 0) {
        cout << "roots: ";
        roots.push_back(((-b) + sqrt(discr())) / 2);
        roots.push_back(((-b) - sqrt(discr())) / 2);
        for (const auto& i : roots) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 1;
}

void Z::add(int n)
{
    b += n;
    c += n;
}

void Z::minus(int n)
{
    b -= n;
    c -= n;
}

void Z::multiply(int n)
{
    b *= n;
    c *= n;
}