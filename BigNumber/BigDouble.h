#pragma once
#ifndef BIG_DOUBLE_H
#define BIG_DOUBLE_H
#include <string>
#include<iostream>
#include "BigInteger.h"
using namespace std;
class BigDouble
{
protected:
	string big_double;
public:
	BigDouble();

	BigDouble(string);

	//phep cong
	BigDouble operator +(BigDouble)const;
	BigDouble operator +=(BigDouble);
	BigDouble operator ++(int);
	BigDouble operator ++();

	//phep tru
	BigDouble operator -(BigDouble)const;
	BigDouble operator -=(BigDouble);
	BigDouble operator --(int);
	BigDouble operator --();

	//phep nhan
	BigDouble operator *(BigDouble)const;
	BigDouble operator *=(BigDouble);

	//phep chia
	BigDouble operator /(BigDouble)const;
	BigDouble operator /=(BigDouble);

	//phep mod
	BigDouble operator %(BigDouble)const;
	BigDouble operator %=(BigDouble);

	//Ep kieu BigInteger
	operator BigInteger();

	//Toan tu so sanh
	BigDouble operator >(BigDouble)const;
	BigDouble operator >=(BigDouble)const;
	BigDouble operator <(BigDouble)const;
	BigDouble operator <=(BigDouble)const;
	BigDouble operator ==(BigDouble)const;
	BigDouble operator =(BigDouble);
	BigDouble operator !=(BigDouble)const;

/*CAC PHUONG THUC*/
	void setBigDouble(string);

	string getBigDouble()const;

	~BigDouble();
};

#endif