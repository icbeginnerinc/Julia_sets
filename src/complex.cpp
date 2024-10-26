#include "complex.h"
#include <cmath>
#include <iostream>
using namespace std;

MyComplex::MyComplex():mReal(0),mImag(0){}

MyComplex::MyComplex(const float pReal,const float pImag){
	this->mReal=pReal;
	this->mImag=pImag;
} 
float MyComplex::real()const
{
	return this->mReal;
}

float MyComplex::imag ()const
{
	return this->mImag;
}
MyComplex MyComplex::operator+(const MyComplex & term) const{
	MyComplex temp;
	temp.mReal=this->mReal+ term.mReal;
	temp.mImag=this->mImag+term.mImag;
	return temp;
}
MyComplex MyComplex::operator+(const float term) const{
	MyComplex temp;
	temp.mReal=this->mReal+ term;
	temp.mImag=this->mImag;
	return temp;
}
MyComplex MyComplex::operator-() const{
	MyComplex temp;
	temp.mImag=-this->mImag;
	temp.mReal=-this->mReal;
	return temp;
}
MyComplex MyComplex::operator-(const MyComplex & term) const{
	MyComplex temp;
	temp.mReal=this->mReal- term.mReal;
	temp.mImag=this->mImag-term.mImag;
	return temp;
}

//z1 · z2 = (x1x2 - y1y2) + i(x1y2 + x2y1)
MyComplex MyComplex::operator*(const MyComplex & term) const{
	MyComplex temp;
	temp.mReal=this->mReal*term.mReal-this->mImag* term.mImag;
	temp.mImag=this->mReal*term.mImag+term.mReal*this->mImag;
	return temp;
}
MyComplex MyComplex::operator*(const float factor) const{
	MyComplex temp;
	temp.mReal=this->mReal*factor;
	temp.mImag=this->mImag*factor;
	return temp;
}
float MyComplex::norm()const 
{
	float temp=0;
	temp=sqrt(pow(this->mReal,2)+pow(this->mImag,2)); //pow(x,2)=x^2, sqrt=sqare root
	return temp;
}

MyComplex & MyComplex::operator= (const MyComplex & term){
	this->mImag=term.mImag;
	this->mReal=term.mReal;
	return *this;
}
std::ostream& operator<<(std::ostream& os, const MyComplex &term){
	string temp;
	os <<"("<<term.real()<<","<<term.imag()<<")";
	return os;
}

MyComplex MyComplex::pow_n(const uint n){
	MyComplex temp,temp2;
	temp2=*this;
	temp=*this;
	for(int i=1;i<n;i++){
		temp2=temp2*temp;
	}
	return temp2;
}

void MyComplex::set_values(const float real,const float imag){
	this->mReal=real;
	this->mImag=imag;
}

