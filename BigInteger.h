#include<iostream>
#include<string>
#include<string.h>
using namespace std;
class BigInteger{
private:
	string so_lon;
public:
	void setso(string so_lon);
	string getso() const;
	BigInteger();
	BigInteger(string a);
	
	BigInteger operator +(BigInteger)const;
	//BigInteger operator ++();
	//BigInteger operator ++(int);
	BigInteger operator -(BigInteger)const;
	//BigInteger operator --(int);
	//BigInteger operator --();
	BigInteger operator +=(BigInteger);
	BigInteger operator -=(BigInteger);
	BigInteger operator *(BigInteger)const;
	BigInteger operator *=(BigInteger);
	BigInteger operator /(BigInteger)const;
	BigInteger operator /=(BigInteger);
	/*qua tai toan tu ep kieu ve sang so thuc*/
	//operator int();
	bool operator ==(BigInteger);
	BigInteger operator =(BigInteger);
	bool operator >(BigInteger)const;
	bool operator >=(BigInteger)const;
	bool operator <=(BigInteger)const;
	bool operator <(BigInteger)const;
	bool operator !=(BigInteger)const;
	BigInteger operator %(BigInteger);
	BigInteger chia(BigInteger)const;
	BigInteger chia1(BigInteger)const;
	BigInteger operator ^(BigInteger)const;
	~BigInteger();
	
};