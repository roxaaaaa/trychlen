#pragma once 
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Try {
protected:
	int a, b, c;
public:
	Try();
	Try(const Try& t);
	Try(int a, int b, int c);
	virtual void print() const;
	virtual float discr() const;
	virtual float find_roots();
	virtual void add(int n);
	virtual void minus(int n);
	virtual void multiply(int n);
	int get_a() const;
	void set_a(int new_a);
	void set_b(int new_b);
	void set_c(int new_c);
	int get_b() const;
	int get_c() const;
	friend istream& operator>>(istream& is, Try& t);
};

class Z : public Try {
private:
	int b, c;
public:
	Z();
	Z(const Z& t);
	Z(int b, int c);
	void print() const override;
	float discr() const override;
	float find_roots() override;
	void add(int n) override;
	void minus(int n) override;
	void multiply(int n) override;
	friend istream& operator>>(istream& is, Z& t) ;
};