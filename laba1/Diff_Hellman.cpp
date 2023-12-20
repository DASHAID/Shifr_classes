#include "Diff_Hellman.h"
#include "fast_pow.h"
#include "max_del.h"
#include "Abonent_B.h"
#include <iostream>
#include <fstream>
using namespace std;

void Diff_Hellman::set_key(int public_key, int public_key_scnd) {
    if (max_del(public_key, public_key_scnd) != 1) {
        cout << "Enter other key, it's not prime!";

    }
    else {
        this->public_key[0] = public_key;
        this->public_key[1] = public_key_scnd;
    }
    
}
// вернуть Бобу пару простых чисел
void Diff_Hellman::get_prime_nums(long long& key, long long& key_scnd) {
    
    
    key = public_key[0];
    key_scnd = public_key[1];



}

int Diff_Hellman::To_Shifr() {
    Abonent_B Bob;
    ofstream fout;
    Bob.To_Shifr_Diff_Hellman();
    general_secret_key = fast_pow(Bob.get_key(), key_secret, public_key[1]);//скрытый общий ключ
    return general_secret_key;
 
}

int Diff_Hellman::get_key() {//первый передаваемый открытый ключ ->B
    return fast_pow(public_key[0], key_secret, public_key[1]);
}
