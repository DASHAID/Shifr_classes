#pragma once
#include "Gen_key.h"
#include "euclid.h"
#include <string>
#include "Abonent_B.h"
#include <vector>
#include <fstream>
#include "fast_pow.h"
#include <string>

#include <iostream>
using namespace std;

class RSA
{
private:
    string my_word;
    vector <long long> this_shifr;
    ofstream fout;
    ifstream fin;
    string mas[50];
    Gen_key rand_key, rand_key2;//два простых ключа в зависимости от которых вычисляется все остальное
    long long key = rand_key.check_prime();
    long long key_scnd = rand_key2.check_prime();
    long long n = key;
    long long n2 = key_scnd;
    int size = 0;
    long long Fi = (key - 1) * (key_scnd - 1);
    long long e = rand_key.gen_e(Fi);
    long long d = euclid(e, Fi);
public:
    
    void get_close_key();
	void To_Shifr(string word, long long e, long long n);
	void To_Deshifr();
	void get_key();
    
		

};

