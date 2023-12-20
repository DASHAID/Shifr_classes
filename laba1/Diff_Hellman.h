#pragma once
#include "Gen_key.h"
#include "Abonent_B.h"
#include <fstream>

class Diff_Hellman
{
private:
    Gen_key secret_key;
    long long public_key[2];
    long long key_secret = secret_key.get_key();//генерация первого секретного ключа
    //int key_secret_scnd = secret_key_scnd.get_key();//генерация второго секретного ключа
    long long open_key = 0, general_secret_key = 0;

public:

    Diff_Hellman() {
        public_key[0] = public_key[1] = 0;
    }

    
    Diff_Hellman(long long public_key, long long public_key_scnd) {
        this->public_key[0] = public_key; this->public_key[1] = public_key_scnd;
    }

    void set_key(int public_key, int public_key_scnd);//установить два публичных ключа
    void get_prime_nums(long long& key, long long& key_scnd);
    int get_key();
    
    //void check_pos(int x);
    int To_Shifr();
};

