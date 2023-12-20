#pragma once
#include "Diff_Hellman.h"
#include "Gen_key.h"
#include <fstream>

#include "fast_pow.h"
#include <string>
#include "El_Gamal.h"
#include "RSA.h"
#include <iostream>

using namespace std;

class Abonent_B
{  private:
	Gen_key secret_key;
	ifstream fin;
	ofstream fout;
	string word;
	long long public_key = 0, public_key2 = 0, key_secret=secret_key.check_prime(), pub_shifr = 0,
		general_key=0, num=0;
	string mas[3];
	long long int_mas[3];


public:
	int get_key();
	void To_Shifr_Diff_Hellman();
	void To_Shifr_RSA();
	void To_Shifr_Shamir();
	long get_x(long long x, int flag);
	int general_k();
	int get_n();
	void To_Shifr_El_Gamal();
};

