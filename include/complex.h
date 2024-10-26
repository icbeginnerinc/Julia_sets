
#ifndef COMPLEX_H_
#define COMPLEX_H_

#include <iostream>
using namespace std;

class MyComplex
{
public:
	MyComplex();
	MyComplex(const float pReal, const float pImag);
	virtual ~MyComplex()=default;

	float norm()const;
	float real()const;
	float imag()const;

	MyComplex pow_n(const uint);
	void set_values(const float real,const float imag);

	MyComplex operator+(const MyComplex & term) const;
	MyComplex operator+(const float term) const;
	MyComplex operator-(const MyComplex & term) const;
	MyComplex operator-() const;
	MyComplex operator*(const MyComplex & term) const;
	MyComplex operator*(const float factor) const;
	MyComplex & operator=(const MyComplex & term);
	friend ostream& operator<<(ostream& os, const MyComplex & term);
	
	
	

private:
	float mReal;
	float mImag;
};

#endif /*COMPLEX_H_*/
