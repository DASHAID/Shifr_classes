#include "find_primer_sqrt.h"
#include <iostream>

int find(int key, int num) {//����� ��������
    int prime_num = num - 1;
    for (int i = 2; i < prime_num; i++) {//����� ��������, � ������� ����� ���������
        if (prime_num % i == 0) {
            int pow_m = pow(key, i) - 1;
            int a = 0, b = 0;

            if (pow_m > prime_num + 1) {//����������� �����
                b = prime_num + 1;
                a = pow_m;
            }
            else {
                a = prime_num + 1;
                b = pow_m;
            }
            if (a % b == 0)//���� ������� ��� ������� - �� ������
            {
                key++;
                i = 1;
            }
        }
    }

    return key;
}
