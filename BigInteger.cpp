#include "BigInteger.h"
/*file nay thieu nhie*/




void BigInteger::setso(string so_lon){
	for (int i = 0; i < so_lon.length() - 1; i++){
		if (so_lon[i] == '0'){
			so_lon.erase(0, 1);
		}
		else break;
	}
	this->so_lon = so_lon;
}

}
BigInteger::BigInteger(){
	so_lon = "0";
}
BigInteger::BigInteger(string so_lon){
	for (int i = 0; i < so_lon.length() - 1; i++){
		if (so_lon[i] == '0'){
			so_lon.erase(0, 1);
		}
		else break;
	}
	this->so_lon = so_lon;
}
BigInteger BigInteger::operator + (BigInteger a)const{

	BigInteger so_lon1 = so_lon, so_lon2 = a;
	int d;
	bool nho = false;
	if (so_lon.length() < a.getso().length()){
		string temp = so_lon1.so_lon;
		so_lon1.so_lon = so_lon2.so_lon;
		so_lon2.so_lon = temp;
	}
	for (int i = so_lon1.so_lon.length() - 1, j = so_lon2.so_lon.length() - 1; i >= 0 || j >= 0; i--, j--){
		if (j >= 0)d = (int)so_lon1.so_lon[i] + (int)so_lon2.getso()[j] - 2 * 48 + nho;
		else d = (int)so_lon1.so_lon[i] - 48 + nho;
		if (d >= 10){
			nho = true;
			d = d % 10;
		}
		else nho = false;
		so_lon1.so_lon[i] = (char)(d + 48);
		if (nho == false && j < 0)break;
	}
	if (nho == true)so_lon1.so_lon = "1" + so_lon1.so_lon;
	return so_lon1;
}
//++ chua lam
/*BigInteger BigInteger::operator++(){
return 0;
}
//++ chua lam
BigInteger BigInteger::operator++(int){
return 0;
}*/
BigInteger BigInteger::operator - (BigInteger a)const{
	BigInteger so_lon1 = so_lon, so_lon2 = a;
	int d;
	int k = 0;
	bool nho = false;
	if ((so_lon.length() < a.getso().length()) || (so_lon.length() == a.getso().length() && so_lon[0] < a.getso()[0])){
		string temp = so_lon1.so_lon;
		so_lon1.so_lon = so_lon2.so_lon;
		so_lon2.so_lon = temp;
		k = 1;
	}
	for (int i = so_lon1.so_lon.length() - 1, j = so_lon2.so_lon.length() - 1; i >= 0 || j >= 0; i--, j--){
		/*if (so_lon2.so_lon[j] == '-'||so_lon1.so_lon[i]=='-'){
		nho = true;
		}*/
		if (j >= 0 && i >= 0)d = ((int)so_lon1.so_lon[i] - 48) - ((int)so_lon2.so_lon[j] - 48) - nho;
		if (j < 0) d = (int)so_lon1.so_lon[i] - 48 - nho;
		if (i < 0) d = (int)so_lon2.so_lon[j] - 48 - nho;
		if (d < 0){
			nho = true;
			d = 10 + d;;
		}
		else nho = false;
		so_lon1.so_lon[i] = (char)(d + 48);
		if (nho == false && (i < 0 || j < 0))break;
	}
	for (int i = 0; i < so_lon1.so_lon.length() - 1; i++){
		if (so_lon1.so_lon[i] == '0'){
			so_lon1.so_lon.erase(0, 1);
		}
		else break;
	}
	if (k == 1)so_lon1.so_lon = "-" + so_lon1.so_lon;
	return so_lon1;
}
//++ chua lam
/*BigInteger BigInteger::operator--(){
return 0;
}
//++ chua lam
BigInteger BigInteger::operator--(int){
return 0;
}*/
BigInteger BigInteger::operator += (BigInteger a){
	BigInteger so_lon1 = so_lon;
	so_lon1 = so_lon1 + a;
	so_lon = so_lon1.so_lon;
	return so_lon;
}
BigInteger BigInteger::operator -= (BigInteger a){
	BigInteger so_lon1 = so_lon;
	so_lon1 = so_lon1 - a;
	so_lon = so_lon1.so_lon;
	return so_lon;
}
BigInteger BigInteger::operator *(BigInteger a)const{
	BigInteger so_lon1 = so_lon, so_lon2 = a;
	/*hoan vi hai so lay so lon (so_lon) nhan so be(a)*/
	if ((so_lon.length() < a.getso().length()) || (so_lon.length() == a.getso().length() && so_lon[0] < a.getso()[0])){
		string temp = so_lon1.so_lon;
		so_lon1.so_lon = so_lon2.so_lon;
		so_lon2.so_lon = temp;
	}
	/*lap theo so nhan*/
	BigInteger kq;
	for (int i = so_lon2.so_lon.length() - 1; i >= 0; i--){
		string c; int d, nho = 0;
		/*thuc hien phep nhan tu phai qua trai*/
		for (int j = so_lon1.so_lon.length() - 1; j >= 0; j--){
			d = (so_lon1.so_lon[j] - 48)*(so_lon2.so_lon[i] - 48) + nho;
			if (d >= 10){
				nho = d / 10;
				d = d % 10;
			}
			else nho = 0;
			c = (char)(d + 48) + c;
		}
		if (nho > 0){
			c = char(nho + 48) + c;
			nho = 0;
		}
		if (i == so_lon2.so_lon.length() - 1)kq.setso(c);
		else {
			for (int k = 0; k < (so_lon2.so_lon.length() - 1 - i); k++)
				c = c + '0';
			BigInteger tam(c);
			kq += c;
		}
	}
	for (int i = 0; i < kq.so_lon.length() - 1; i++){
		if (kq.so_lon[i] == '0'){
			kq.so_lon.erase(0, 1);
		}
		else break;
	}
	return kq;
}
BigInteger BigInteger::operator *=(BigInteger a){
	BigInteger b, so_lon1 = so_lon, so_lon2 = a;
	b = so_lon1*so_lon2;
	so_lon = b.so_lon;
	return so_lon;
}
BigInteger BigInteger::operator / (BigInteger a)const{
	BigInteger so_lon1 = so_lon, so_lon2 = a;
	/*hoan vi hai so lay so lon (so_lon) chia so be(a)
	if ((so_lon1.so_lon.length() < so_lon2.so_lon.length()) || (so_lon.length() == a.getso().length() && so_lon[0] < a.getso()[0])){
	string temp = so_lon1.so_lon;
	so_lon1.so_lon = so_lon2.so_lon;
	so_lon2.so_lon = temp;
	}*/
	
	BigInteger kq;
	BigInteger h = so_lon1.so_lon;
	if (so_lon1 < so_lon2){
		kq.so_lon = "0";
	}
	else{
		string c;
		c = so_lon1.so_lon[0];
		for (int i = h.so_lon.length() - 2; i >= 0; i--)c = c + '0';
		BigInteger k(c);
		while (1){
			while (1){
				BigInteger d = k*so_lon2;
				bool kt = false;
				if (d.so_lon.length() > h.so_lon.length())kt = true;
				if ((d.so_lon.length() == h.so_lon.length())){
					for (int y = 0; y < h.so_lon.length(); y++){
						if (d.so_lon[y] > h.so_lon[y]){
							kt = true;
							break;
						}
					}
				}
				if (kt == false){
					h = h - d;
					kq = kq + k;
					break;
				}
				if (k.so_lon[0] == '1'){
					k.so_lon[0] = '9';
					k.so_lon.erase(k.so_lon.length() - 1, k.so_lon.length());
				}
				else{
					k.so_lon[0] = (int)k.so_lon[0] - (int)'1' + 48;
					//cout << k.so_lon << endl;
				}
			}
			bool dk_dung = false;
			if (h.so_lon.length() < so_lon2.so_lon.length()) break;
			if (h.so_lon.length() == so_lon2.so_lon.length()){
				for (int u = 0; u < h.so_lon.length(); u++){
					if (h.so_lon[u] < so_lon2.so_lon[u]){
						dk_dung = true;
						break;
					}
				}
			}
			if (dk_dung == true)break;
		}
	}
	//cout << h.so_lon << endl;
	if (h.so_lon.length() && h.so_lon[0] != 48){
		kq.so_lon = kq.so_lon + '.';
		BigInteger coso("10"), u;
		int j = 1;
		/*for (int i = 0; i < so_lon2.so_lon.length(); i++){
			coso.so_lon = coso.so_lon + "0";
		}*/
		while (h.so_lon != "0"){
			u = (h*coso) % so_lon2;
			h = (h*coso).chia1(so_lon2);
			for (int i = 0; i < u.so_lon.length()-1; i++){
				if (u.so_lon[i] == '0'){
					u.so_lon.erase(0, 1);
				}
				else break;
			}
			kq.so_lon = kq.so_lon + h.so_lon;
			h = u;
			//cout << h.so_lon << " ";
			j++;
			if (j >= 9)break;
		}
	}

	//cout << h.so_lon << endl;
	//h la so du; su dung cai nay lam phay dong
	for (int i = 0; i < kq.so_lon.length() - 1; i++){
		if (kq.so_lon[i] == '0'){
			kq.so_lon.erase(0, 1);
		}
		else break;
	}
	return kq;
}
BigInteger BigInteger::operator /=(BigInteger a){
	BigInteger b, so_lon1 = so_lon, so_lon2 = a;
	b = so_lon1 / so_lon2;
	so_lon = b.so_lon;
	return so_lon;
}
BigInteger BigInteger::operator =(BigInteger a){
	so_lon = a.so_lon;
	return so_lon;
}
bool BigInteger::operator >(BigInteger a)const{
	if (so_lon.length() == a.so_lon.length()){
		for (int i = 0; i < so_lon.length(); i++){
			if (so_lon[i]>a.so_lon[i]){
				return true;
				break;
			}
			if (so_lon[i]<a.so_lon[i]){
				return false;
				break;
			}
		}
	}
	if (so_lon.length() > a.getso().length()){
		return true;
	}
	return  false;
}
bool BigInteger::operator >= (BigInteger a)const{
	if (so_lon.length() == a.so_lon.length()){
		for (int i = 0; i < so_lon.length(); i++){
			if (so_lon[i]>a.so_lon[i]){
				return true;
				break;
			}
			if (so_lon[i]<a.so_lon[i]){
				return false;
				break;
			}
			if (i == a.so_lon.length() - 1){
				if (so_lon[i] == a.so_lon[i])return true;
			}
		}
	}
	if (so_lon.length() > a.getso().length()){
		return true;
	}
	return  false;
}
bool BigInteger::operator <= (BigInteger a)const{
	if (so_lon.length() == a.so_lon.length()){
		for (int i = 0; i < so_lon.length(); i++){
			if (so_lon[i]<a.so_lon[i]){
				return true;
				break;
			}
			if (so_lon[i]>a.so_lon[i]){
				return false;
				break;
			}

			if (i == a.so_lon.length() - 1){
				if (so_lon[i] == a.so_lon[i])return true;
			}
		}
	}
	if (so_lon.length() <= a.getso().length()){
		return true;
	}
	return  false;
}
bool BigInteger::operator <(BigInteger a)const{
	if (so_lon.length() == a.so_lon.length()){
		for (int i = 0; i < so_lon.length(); i++){
			if (so_lon[i]<a.so_lon[i]){
				return true;
				break;
			}
			if (so_lon[i]>a.so_lon[i]){
				return false;
				break;
			}
		}
	}
	if (so_lon.length() < a.getso().length()){
		return true;
	}
	return  false;
}
bool BigInteger::operator == (BigInteger a){
	if (so_lon.length() == a.so_lon.length()){
		for (int i = 0; i < so_lon.length(); i++){
			if (so_lon[i]<a.so_lon[i]){
				return false;
				break;
			}
			if (so_lon[i]>a.so_lon[i]){
				return false;
				break;
			}
			if (so_lon[i] == a.so_lon[i]){
				return false;
				break;
			}
		}
	}
	return  false;
}
bool BigInteger::operator != (BigInteger a)const{
	BigInteger solon1 = so_lon, solon2 = a;
	if (solon1 == solon2)return false;
	return true;
}
BigInteger BigInteger::operator % (BigInteger a){
	BigInteger b, so_lon1 = so_lon, so_lon2 = a;
	/*hoan vi hai so lay so lon (so_lon) chia so be(a)*/
	/*if ((so_lon1.so_lon.length() < so_lon2.so_lon.length()) || (so_lon1.so_lon.length() == so_lon2.so_lon.length() && so_lon1.so_lon[0] < so_lon2.so_lon[0])){
		string temp = so_lon1.so_lon;
		so_lon1.so_lon = so_lon2.so_lon;
		so_lon2.so_lon = temp;
	}*/
	b = so_lon1.chia1(so_lon2);
	BigInteger kq = so_lon1 - b*so_lon2;

	return kq;
}

//BigInteger BigInteger::chia(BigInteger a)const{
//	BigInteger so_lon1 = so_lon, so_lon2 = a;
//	/*hoan vi hai so lay so lon (so_lon) chia so be(a)*/
//	if ((so_lon1.so_lon.length() < so_lon2.so_lon.length()) || (so_lon.length() == a.getso().length() && so_lon[0] < a.getso()[0])){
//		string temp = so_lon1.so_lon;
//		so_lon1.so_lon = so_lon2.so_lon;
//		so_lon2.so_lon = temp;
//	}
//	BigInteger kq;
//	BigInteger h = so_lon1.so_lon;
//	string c;
//	c = so_lon1.so_lon[0];
//	for (int i = h.so_lon.length() - 2; i >= 0; i--)c = c + '0';
//	BigInteger k(c);
//	while (1){
//		while (1){
//			BigInteger d = k*so_lon2;
//			bool kt = false;
//			if (d.so_lon.length() > h.so_lon.length())kt = true;
//			if ((d.so_lon.length() == h.so_lon.length())){
//				for (int y = 0; y < h.so_lon.length(); y++){
//					if (d.so_lon[y] > h.so_lon[y]){
//						kt = true;
//						break;
//					}
//				}
//			}
//			if (kt == false){
//				h = h - d;
//				kq = kq + k;
//				break;
//			}
//			if (k.so_lon[0] == '1'){
//				k.so_lon[0] = '9';
//				k.so_lon.erase(k.so_lon.length() - 1, k.so_lon.length());
//			}
//			else{
//				k.so_lon[0] = (int)k.so_lon[0] - (int)'1' + 48;
//				//cout << k.so_lon << endl;
//			}
//		}
//		bool dk_dung = false;
//		if (h.so_lon.length() < so_lon2.so_lon.length()) break;
//		if (h.so_lon.length() == so_lon2.so_lon.length()){
//			for (int u = 0; u < h.so_lon.length(); u++){
//				if (h.so_lon[u] < so_lon2.so_lon[u]){
//					dk_dung = true;
//					break;
//				}
//			}
//		}
//		if (dk_dung == true)break;
//	}
//	return kq;
//}

BigInteger BigInteger::chia1(BigInteger a)const{
	BigInteger so_lon1 = so_lon, so_lon2 = a;
	/*hoan vi hai so lay so lon (so_lon) chia so be(a)*/
	/*if ((so_lon1.so_lon.length() < so_lon2.so_lon.length()) || (so_lon.length() == a.getso().length() && so_lon[0] < a.getso()[0])){
		string temp = so_lon1.so_lon;
		so_lon1.so_lon = so_lon2.so_lon;
		so_lon2.so_lon = temp;
	}*/
	BigInteger kq;
	BigInteger h = so_lon1.so_lon;
	string c;
	c = so_lon1.so_lon[0];
	for (int i = h.so_lon.length() - 2; i >= 0; i--)c = c + '0';
	BigInteger k(c);
	while (1){
		while (1){
			BigInteger d = k*so_lon2;
			bool kt = false;
			if (d.so_lon.length() > h.so_lon.length())kt = true;
			if ((d.so_lon.length() == h.so_lon.length())){
				for (int y = 0; y < h.so_lon.length(); y++){
					if (d.so_lon[y] > h.so_lon[y]){
						kt = true;
						break;
					}
				}
			}
			if (kt == false){
				h = h - d;
				kq = kq + k;
				break;
			}
			if (k.so_lon[0] == '1'){
				k.so_lon[0] = '9';
				k.so_lon.erase(k.so_lon.length() - 1, k.so_lon.length());
			}
			else{
				k.so_lon[0] = (int)k.so_lon[0] - (int)'1' + 48;
				//cout << k.so_lon << endl;
			}
		}
		bool dk_dung = false;
		if (h.so_lon.length() < so_lon2.so_lon.length()) break;
		if (h.so_lon.length() == so_lon2.so_lon.length()){
			for (int u = 0; u < h.so_lon.length(); u++){
				if (h.so_lon[u] < so_lon2.so_lon[u]){
					dk_dung = true;
					break;
				}
			}
		}
		if (dk_dung == true)break;
	}
	return kq;
}

BigInteger BigInteger::operator ^ (BigInteger a)const{
	BigInteger nho, coso("1"), kq("1");
	for (nho; nho < a; nho = nho + coso){
		kq = kq*so_lon;
	}
	return kq;
}
BigInteger::~BigInteger(){

}
