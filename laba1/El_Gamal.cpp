#include "El_Gamal.h"

using namespace std;

void El_Gamal::get_open_key() {
    ofstream fout;
    fout.open("my_file.txt");
    fout << prime_num << endl << sqrt2 << endl << open_key;
    fout.close();
}
void El_Gamal::get_close_key() {
    cout << "Close key(X):" << rand_num << endl;
}

void El_Gamal::To_Shifr(long long p, long long g, long long y, int number) {
    ofstream fout;
    my_number = number;
    k = rand() % (p - 1);
    if (max_del(k, p) != 1) k++;
    a = fast_pow(g, k,p);
        
    b = fast_pow(y, k, p) * my_number;
    cout << "Shifr: (A=" << a <<" ";
    cout << "B=" << b<<")" << endl;

    fout.open("my_file.txt");
    fout << a << endl << b;
    fout.close();
}
void El_Gamal::To_Deshifr() {
    Abonent_B Bob;
    Bob.To_Shifr_El_Gamal();
    ifstream fin;
    string str_mas[2];
    fin.open("my_file.txt");
    int i = 0;
    while (!fin.eof()) {
        str_mas[i] = "";
        getline(fin, str_mas[i]);
        mas[i] = stoi(str_mas[i]);
        i++;
    }
    fin.close();
    long long deshifr = fast_pow(mas[0], rand_num, prime_num);
        
    cout << "Deshifr:" << mas[1] / deshifr << endl;

}