#pragma once
#include <iostream> 
#include <vector> 
#include <string> 
#include <cstdlib> 
#include <ctime> 
using namespace std;
class Rsa {
	struct PublicKey {
		unsigned long long e;
		unsigned long long n;
	};
	struct PrivateKey {
		unsigned long long d;
		unsigned long long p;
		unsigned long long q;
	};
	string Message;
	unsigned long long n, e , d;
	PublicKey MyPublicKey;
	PrivateKey MyPrivateKey;
public:
	Rsa() { ; }
	~Rsa() { ; }
	unsigned long long CalcEuler(unsigned long long p, unsigned long long q) {
		return (p - 1) * (q - 1);
	}
	unsigned long long encrypt(PublicKey& puk, unsigned long long msg) {
		return EncryptOrDecryptFormula(msg, puk.e, puk.n);
	}
	unsigned long long decrypt(PrivateKey& prk, PublicKey& puk, unsigned long long c) {
		return EncryptOrDecryptFormula(c, prk.d, puk.n);
	}
	void SetMyPrivateKeyP(string p) {
		this->MyPrivateKey.p = std::stoll(p);
	}
	void SetMyPrivateKeyQ(string q) {
		this->MyPrivateKey.q = std::stoll(q);
	}
	PublicKey GetPublicKey() {
		return MyPublicKey;
	}
	PrivateKey GetPrivateKey() {
		return MyPrivateKey;
	}
	bool EuclidesAlgorithm(unsigned long long d, unsigned long long fi) {
		unsigned long long r1, r2, r3 = 1;
		if (d < fi) {
			r1 = d;
			r2 = fi;
		}
		else {
			r1 = fi;
			r2 = d;
		}
		while (r3 != 0) {
			r3 = r2 % r1;
			r2 = r1;
			r1 = r3;
		}
		return r2 == 1;
	}
	unsigned long long Calc_e_Value(unsigned long long d, unsigned long long fi) {
		unsigned long long e;
		for (unsigned long long i = 2; i < fi; i++) {
			unsigned long long temp = (i * d) % fi;
			if (temp == 1) {
				e = i;
				break;
			}
		}
		return e;
	}
	unsigned long long EncryptOrDecryptFormula(unsigned long long code, unsigned long long e_or_d_value, unsigned long long n) {
		unsigned long long ret = 1;
		unsigned long long tmp = code;
		while (e_or_d_value != 0) {
			if (e_or_d_value % 2 != 0)
				ret = ret * tmp % n;
			tmp = tmp * tmp % n;
			e_or_d_value /= 2;
		}
		return ret;
	}
	void CreateKey(long long d) {
		n = GetP() * GetQ();
		unsigned long long fi = CalcEuler(GetP(), GetQ());
		while (!EuclidesAlgorithm(d, fi))
			++d;
		e = Calc_e_Value(d, fi);
		MyPublicKey.n = n;
		MyPublicKey.e = e;
		MyPrivateKey.d = d;
		
	}
	vector<unsigned long long> EncryptationMetodRSA() {
		vector<unsigned long long> vcode;
		unsigned long long code;
		cout << "\nCipher text: " << endl << endl;
		string EncryptedMessage;
		for (unsigned long long character : this->Message) {
			//EncryptedMessage += encrypt(MyPublicKey, (unsigned long long)character) + ' ';
			code = encrypt(MyPublicKey, (unsigned long long)character);
			vcode.push_back(code);
		}
		return vcode;
	}



	string DecryptationMethod(vector<unsigned long long> codes) {
		unsigned long long code;
		cout << "\nCipher text: " << endl << endl;
		string DencryptedMessage;
		for (unsigned long long code : codes) {
			//EncryptedMessage += encrypt(MyPublicKey, (unsigned long long)character) + ' ';
			char c = decrypt(MyPrivateKey, MyPublicKey, code);

			DencryptedMessage += c;
		}
		return DencryptedMessage;
	}

	unsigned long long GetP() {
		return MyPrivateKey.p;
	}
	unsigned long long GetQ() {
		return MyPrivateKey.q;
	}
	unsigned long long GetE(){
		return e;
	}
	unsigned long long GetD(){
		return d;
	}
	unsigned long long GetN(){
		return n;
	}
	string GetMessage(){
		return this->Message;
	}
	void SetMessage(string input){
		this->Message = input;
	}
};

