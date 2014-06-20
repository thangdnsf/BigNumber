#pragma once
#ifndef BIG_INTEGER_H
#define BIG_INTEGER_H
#include <string>
#include<iostream>
#include "BigDouble.h"
using namespace std;
class BigInteger
{
protected:
	string big_integer;
public:
	BigInteger();
	BigInteger(string);

	//phep cong
	BigInteger operator +(BigInteger)const;
	BigInteger operator +=(BigInteger);
	BigInteger operator ++(int);
	BigInteger operator ++();
	//phep tru
	BigInteger operator -(BigInteger)const;
	BigInteger operator -=(BigInteger);
	BigInteger operator --(int);
	BigInteger operator --();
	//phep nhan
	BigInteger operator *(BigInteger)const;
	BigInteger operator *=(BigInteger);
	//phep chia
	BigInteger operator /(BigInteger)const;
	BigInteger operator /=(BigInteger);
	//phep mod
	BigInteger operator %(BigInteger)const;
	BigInteger operator %=(BigInteger);

	//Ep kieu
	operator BigDouble();

	//Toan tu so sanh
	BigInteger operator >(BigInteger)const;
	BigInteger operator >=(BigInteger)const;
	BigInteger operator <(BigInteger)const;
	BigInteger operator <=(BigInteger)const;
	BigInteger operator ==(BigInteger)const;
	BigInteger operator =(BigInteger)const;
	BigInteger operator !=(BigInteger)const;
	
/*CAC HANH DONG */
	void setBigInteger(string);// nhap
	string getBigInteger()const;//xuat

	~BigInteger();
};
#endif