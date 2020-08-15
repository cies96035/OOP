#include "Vector.h"
#include <cmath>

Vector::Vector()
{
	arr = new float[0];
	arrSize = 0;
	currentIndex = 0;//point to end()
}

//.resize()
Vector::Vector(int size)//useless
{ 
	arr = new float[size];
	arrSize = size;
	currentIndex = 0;
}

//copy constructor
Vector::Vector(const Vector& V)
{
	arrSize=V.arrSize;
	currentIndex=V.currentIndex;
	arr = new float[arrSize];
	for(int i=0;i<currentIndex;i++)
		arr[i]=V.arr[i];
}

//delete
Vector::~Vector()
{
	delete[] arr;
}

//push_back
void Vector::AddNumbertoArr(float number)
{
	//the arr size isnt enough
	//expand arr size
	if(currentIndex==arrSize)
	{
		Vector tmp(arrSize*2+1);
		tmp.currentIndex=currentIndex;
		//copy
		for(int i=0;i<currentIndex;i++)
			tmp.arr[i]=arr[i];
		//add number
		tmp.arr[currentIndex]=number;
		tmp.currentIndex++;
		*this=tmp;
	}
	else
	{
		arr[currentIndex]=number;
		currentIndex++;
	}
	
}

int Vector::getSize()//useless
{
	return currentIndex;
}

float Vector::length()
{
	long double sum=0;
	for(int i=0;i<currentIndex;i++)
		sum+=arr[i]*arr[i];
	return sqrt(sum);
}

Vector Vector::normalize()
{
	long double len=length();
	Vector tmp(arrSize);
	for(int i=0;i<currentIndex;i++)
		tmp.arr[i]=arr[i]/len;
	tmp.currentIndex=currentIndex;
	return tmp;
}

//doesnt check if the srrsize is same
Vector  Vector::operator+(const Vector &v)
{
	Vector tmp(arrSize);
	for(int i=0;i<currentIndex;i++)
		tmp.arr[i]=arr[i]+v.arr[i];
	tmp.currentIndex=currentIndex;
	return tmp; 
}

Vector  Vector::operator=(const Vector &v)
{
	arrSize=v.arrSize;
	currentIndex=v.currentIndex;

	delete[] arr;
	arr = new float[arrSize];

	for(int i=0;i<v.currentIndex;i++)
		arr[i]=v.arr[i];

	return *this;
}

Vector  Vector::operator-(const Vector &v)
{
	Vector tmp(arrSize);
	for(int i=0;i<currentIndex;i++)
		tmp.arr[i]=arr[i]-v.arr[i];
	tmp.currentIndex=currentIndex;
	return tmp; 
}

float  Vector::operator*(const Vector &v)
{
	double sum=0;
	for(int i=0;i<currentIndex;i++)
		sum+=arr[i]*v.arr[i];
	return sum;
}

ifstream & operator>>(ifstream & in, Vector &v)
{
	int amount;
	double number;
	in>>amount;
	while(amount--)
	{
		in>>number;
		v.AddNumbertoArr(number);
	}
	return in;
}

ostream & operator<<(ostream & out, const Vector & v)
{
	out<<'(';
	for(int i=0;i<v.currentIndex-1;i++)
		out<<v.arr[i]<<',';
	out<<v.arr[v.currentIndex-1]<<')';
	return out;
}
