#include "BigDouble.h"


BigDouble::BigDouble()
{
	this->big_double = "";
}


BigDouble::BigDouble(string big_double){
	this->big_double = big_double;
}

//phep cong
BigDouble BigDouble::operator + (BigDouble)const{

}

BigDouble BigDouble::operator += (BigDouble){

}

BigDouble BigDouble::operator++(int){

}

BigDouble BigDouble::operator++(){

}

//phep tru
BigDouble BigDouble::operator - (BigDouble)const{

}

BigDouble BigDouble::operator -= (BigDouble){

}

BigDouble BigDouble::operator--(int){

}

BigDouble BigDouble::operator--(){

}


//phep nhan
BigDouble BigDouble::operator *(BigDouble)const{

}

BigDouble BigDouble::operator *= (BigDouble){

}


//phep chia
BigDouble BigDouble::operator / (BigDouble)const{

}

BigDouble BigDouble::operator /= (BigDouble){

}


//phep mod
BigDouble BigDouble::operator % (BigDouble)const{

}

BigDouble BigDouble::operator %= (BigDouble){

}


//Ep kieu BigInteger
BigDouble::operator BigInteger(){

}

//Toan Tu so sanh
BigDouble BigDouble::operator >(BigDouble)const{

}

BigDouble BigDouble::operator >=(BigDouble)const{


}

BigDouble BigDouble::operator <(BigDouble)const{


}

BigDouble BigDouble::operator <=(BigDouble)const{


}

BigDouble BigDouble::operator ==(BigDouble)const{


}

BigDouble BigDouble::operator =(BigDouble){


}

BigDouble BigDouble::operator !=(BigDouble)const{


}


/*CAC PHUONG THUC*/
void BigDouble::setBigDouble(string){

}

string BigDouble::getBigDouble()const{

}


BigDouble::~BigDouble()
{
}
