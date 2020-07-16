#include<iostream>
using namespace std;

#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED

class MATRIX
{
public:

	MATRIX() : a(0), b(0), c(0), d(0) {}
	MATRIX(int i, int j, int k, int l) : a(i), b(j), c(k), d(l) {}

	void print();
	void add(MATRIX m);
	void multiple(MATRIX m);
	void det();

private:
	/*
	m = [a, b
		 c, d]
	*/
	int a, b;
	int c, d;

};

//print the matrix
void MATRIX::print()
{
	cout<<'[';
    cout<<this->a<<" , ";
    cout<<this->b<<" , ";
    cout<<this->c<<" , ";
    cout<<this->d<<"]\n";
    return;
}

//this.add(m) -> this+=m and print this
void MATRIX::add(MATRIX m)
{
    this->a+=m.a;
    this->b+=m.b;
    this->c+=m.c;
    this->d+=m.d;
	this->print();
}

//this*=m and print this
void MATRIX::multiple(MATRIX m)
{
    /*
	aa+bc
    ab+bd
    ca+dc
    cb+dd
    */
    MATRIX tmp(
    this->a*m.a+this->b*m.c,
    this->a*m.b+this->b*m.d,
    this->c*m.a+this->d*m.c,
    this->c*m.b+this->d*m.d);
    *this=tmp;
	this->print();
}

void MATRIX::det()
{
	//ad-bc
	cout<<this->a*this->d-this->b*this->c<<'\n';
}

#endif // MATRIX_H_INCLUDED
