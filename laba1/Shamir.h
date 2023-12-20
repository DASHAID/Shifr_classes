#pragma once
#include "Gen_key.h"
#include "euclid.h"

class Shamir
{ 

private:

	Gen_key num, key, prime;
	long long prime_num = prime.check_prime();
	   long long cA = key.check_prime();
	   long long dA = euclid(cA, prime_num - 1);
	   int my_number = 0;

public:
	void To_Shifr(int number);

};


