#include "Shamir.h"
#include <iostream>
#include "fast_pow.h"
#include <fstream>
#include "Abonent_B.h"
using namespace std;


void Shamir::To_Shifr(int number) {
	my_number = number;
	Abonent_B Bob;

	ofstream fout;
	fout.open("my_file.txt");
	fout << prime_num;
	fout.close();
	Bob.To_Shifr_Shamir();
	int flag = 0;
	long long x1 = fast_pow(my_number,cA,prime_num);
	cout << "X from A: " << x1 << endl;
	long long x3 = fast_pow(Bob.get_x(x1,flag), dA, prime_num);
	cout << "X from A: " << x3 << endl;
	flag++;
	Bob.get_x(x3, flag);
	

}
