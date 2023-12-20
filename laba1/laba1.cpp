#include <iostream>
#include "RSA.h"
#include "Abonent_B.h"
#include "Diff_Hellman.h"
#include "El_Gamal.h"
#include "Shamir.h"
#include <fstream>

using namespace std;

int main()
{
  
    int agree = 0;
    int num = 0;
    ofstream fout;
    ifstream fin;
    char buff[50];

    Diff_Hellman diff_hellman;
    RSA rsa;
    Abonent_B Bob;
    Diff_Hellman my;
    El_Gamal el_gam;
    Shamir shamir;
    


    cout << "What methot you want to use?" << endl;
    cout << "1. RSA" << endl; cout << "2. Diff_Hellman" << endl; cout << "3. El_Gamal" << endl;
    cout << "4. Shamir" << endl;
    cin >> agree;

    switch (agree)
    { 
    case 1:
        fout.open("file.txt", ofstream::out | ofstream::trunc);
        fout.close();
        rsa.get_key();
        cout << endl;
        rsa.To_Deshifr();
        break;

    case 2:

        cout << endl;
        diff_hellman.set_key(997, 991);
        //очистка
        fout.open("file.txt", ofstream::out | ofstream::trunc);
        fout.close();
        //передача открытого ключа
        fout.open("file.txt", ofstream::app);
        fout.write((char*)&diff_hellman, sizeof(Diff_Hellman));
        fout.close();
       
        cout<<"General key: "<<diff_hellman.To_Shifr()<<endl;
        cout << "_________________________" << endl;
        cout << "General key(Abonent B): ";
        fin.open("file.txt");
        fin >> buff;
        cout<<buff;

        

        break;

    case 3:

        fout.open("my_file.txt", ofstream::out | ofstream::trunc);
        fout.close();
        //передача открытого ключа
        el_gam.get_open_key();
        el_gam.To_Deshifr();
        break;
        
    case 4:
        cout << "Enter number: " << endl;
        cin >> num;
        cout << "_________________________" << endl;

        fout.open("my_file.txt", ofstream::out | ofstream::trunc);
        fout.close();

        shamir.To_Shifr(num);
        break;

    default:
        cout << "Bad input!";
        break;

    }

    cin.get();
}
