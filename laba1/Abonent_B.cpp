#include "Abonent_B.h"



using namespace std;

int Abonent_B::get_key() {//отправили наше сообщение
	return pub_shifr;
};

void Abonent_B::To_Shifr_Diff_Hellman() {

	Diff_Hellman key_me;
	fin.open("file.txt");
	fin.read((char*)&key_me, sizeof(Diff_Hellman));
	fin.close();
	int secret_key = rand() % 200;
	key_me.get_prime_nums(public_key, public_key2);//получили 2 простых числа
	pub_shifr = fast_pow(public_key, secret_key, public_key2);//сгенерировали наше сообщание
	general_key = fast_pow(key_me.get_key(), secret_key, public_key2);//сохдали общий секретный ключ
	fout.open("file.txt");
	fout << general_key;
	fout.close();
};

int Abonent_B::general_k() {
	return general_key;
};

void Abonent_B::To_Shifr_RSA() {
	//получение открытого ключа
	ifstream fin;
	int i = 0;
	fin.open("file.txt");
	while (!fin.eof()) {
		mas[i] = "";
		getline(fin, mas[i]);
		i++;
	}
	fin.close();

	public_key = stoi(mas[0]);
	public_key2 = stoi(mas[1]);
	//шифровка
	RSA rsa;

	cout << "Enter word or number: " << endl;
	cin >> word;
	cout << "_________________________" << endl;
	rsa.To_Shifr(word, public_key, public_key2);
};

void Abonent_B::To_Shifr_Shamir() {

	//int cB = key_secret;
	fin.open("my_file.txt");
	fin >> word;
	fin.close();
	public_key = stoi(word);

	general_key = euclid(key_secret, public_key - 1);


};

long Abonent_B::get_x(long long x, int flag) {
	long long x1 = x;
	if (flag == 0) x1 = fast_pow(x, key_secret, public_key);
	else if (flag == 1) {
		x1 = fast_pow(x, general_key, public_key);
		cout << "______________" << endl;
		cout << "Shifr: " << x1 << endl;
		exit(0);
	}
	cout << "X from B: " << x1 << endl;
	return x1;

}

void Abonent_B::To_Shifr_El_Gamal() {
	El_Gamal el_gam;

	cout << "Enter number: " << endl;
	cin >> num;
	cout << "_________________________" << endl;

	//считаем открытые ключи
	int i = 0;
	fin.open("my_file.txt");
	while (!fin.eof()) {
		mas[i] = "";
		getline(fin, mas[i]);
		int_mas[i]=stoi(mas[i]);
		i++;
	}
	fin.close();

	el_gam.To_Shifr(int_mas[0], int_mas[1], int_mas[2], num);

}

