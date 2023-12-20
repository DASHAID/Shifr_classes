#include "find_primer_sqrt.h"
#include <iostream>

int find(int key, int num) {//найти делители
    int prime_num = num - 1;
    for (int i = 2; i < prime_num; i++) {//найти делители, в которые будем возводить
        if (prime_num % i == 0) {
            int pow_m = pow(key, i) - 1;
            int a = 0, b = 0;

            if (pow_m > prime_num + 1) {//переставить числа
                b = prime_num + 1;
                a = pow_m;
            }
            else {
                a = prime_num + 1;
                b = pow_m;
            }
            if (a % b == 0)//если делится без остатка - не корень
            {
                key++;
                i = 1;
            }
        }
    }

    return key;
}
