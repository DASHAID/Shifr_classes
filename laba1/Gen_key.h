#pragma once
class Gen_key
{
private: 
    int prime_num=0;

public:
    Gen_key();
    long check_prime() ;
    long gen_e(long long a);
    long get_key();
};


