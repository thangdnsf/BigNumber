#pragma once
#ifndef BIG_MATH_H
#define BIG_MATH_H
#include "BigInteger.h"
#include "BigDouble.h"
BigDouble BigPow(BigDouble, BigDouble);// hàm tính a^b
BigDouble BigSqr(BigDouble);//hàm tính a^2
BigDouble BigSqrt(BigDouble);//hàm tính căn
BigDouble BigAbs(BigDouble);// hàm tính trị tuyệt đối
#endif
