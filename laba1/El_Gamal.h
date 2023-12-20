#pragma once
#include "Gen_key.h"
#include "fast_pow.h"
#include "find_primer_sqrt.h"
#include <iostream>
#include "max_del.h"
#include <fstream>
#include "Abonent_B.h"
#include <string>

/*1. определяем два простых числа
2. случайное число х < одного предыдущего простого числа
открытое число y=простое число^x mod p
3. к - случайное взаимнопростое число с простым числом -1
4. отправляемый шифротекст а= простое число^секретного ключа mod второе число
                            b=открытые ключ**число для шифровки mod простое число */
class El_Gamal
{
private:
    Gen_key key;
    int my_number = 0;
    long long a = 0, b = 0,k = 0;
    long long prime_num = key.check_prime();//простое число
    int sqrt = 2;
    long long sqrt2 = find(sqrt, prime_num);//первообразный корень
    int rand_num = rand() % 16;//скрытое число х
    long long open_key = fast_pow(sqrt2, rand_num, prime_num);
    int mas[2];
public:
    void get_open_key();
    void get_close_key();
    void To_Shifr(long long p, long long g, long long y, int number);
    void To_Deshifr();
};
