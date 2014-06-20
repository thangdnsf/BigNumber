#include "BigInteger.h"


BigInteger::BigInteger()
{
	this->big_integer = "";
}

BigInteger::BigInteger(string big_integer){
	this->big_integer = big_integer;
}

//phep cong
BigInteger BigInteger::operator + (BigInteger)const{

}

BigInteger BigInteger::operator += (BigInteger){

}

BigInteger BigInteger::operator++(int){

}

BigInteger BigInteger::operator++(){

}

//phep tru
BigInteger BigInteger::operator - (BigInteger)const{

}

BigInteger BigInteger::operator -= (BigInteger){

}

BigInteger BigInteger::operator--(int){

}

BigInteger BigInteger::operator--(){

}

//phep nhan
BigInteger BigInteger::operator *(BigInteger)const{

}

BigInteger BigInteger::operator *= (BigInteger){

}

//phep chia
BigInteger BigInteger::operator / (BigInteger)const{

}

BigInteger BigInteger::operator /= (BigInteger){

}

//phep mod
BigInteger BigInteger::operator % (BigInteger)const{

}

BigInteger BigInteger::operator %= (BigInteger){

}


//Ep kieu
BigInteger::operator BigDouble(){

}
//Toan tu so sanh
BigInteger BigInteger::operator >(BigInteger)const{


}

BigInteger BigInteger::operator >=(BigInteger)const{


}

BigInteger BigInteger::operator <(BigInteger)const{


}

BigInteger BigInteger::operator <=(BigInteger)const{


}

BigInteger BigInteger::operator ==(BigInteger)const{


}

BigInteger BigInteger::operator =(BigInteger){

}

BigInteger BigInteger::operator !=(BigInteger)const{


}


/*CAC HANH DONG */
void BigInteger::setBigInteger(string){// nhap

}

string BigInteger::getBigInteger()const{//xuat

}

BigInteger::~BigInteger()
{
}
