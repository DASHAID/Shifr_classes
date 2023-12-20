#include "rsa.h"

using namespace std;


   
   void RSA::get_key() {
       cout<<"E: "<<e<<endl;
       cout << "N: " << n << endl;
       cout << "D: " << d << endl;

    }


   void RSA::To_Shifr(string word, long long e, long long n) {
       

        int pos = 0;
        int i = 0;
        my_word = word;
        //провиерка на русские буквы
        while (my_word[i] != '\0') {
            char a = my_word[i];
            pos = (int)(a);
            if (pos ==0) {
                cout << "Was find rus alphabet, enter other word!";
                exit(0);
            }
            this_shifr.push_back(fast_pow(pos, e, n));
            i++;
        }
        //передача шифра абоненту Б
        cout << "Shifr: ";
        fout.open("file.txt");
        for (auto j : this_shifr) { 
            cout << j<<" "; 
            fout << j<<endl; 
        }
        fout.close();

    }

    void RSA::To_Deshifr() {
        Abonent_B Bob;
       
        //передали открытый ключ
        fout.open("file.txt");
        fout << e << endl;
        fout << n;
        fout.close();
        Bob.To_Shifr_RSA();

        int i = 0;
        long long pos = 0;

        //получаем шифр
        fin.open("file.txt");
        try {
            while (!fin.eof()) {
                mas[i] = "";
                getline(fin, mas[i]);
                this_shifr.push_back(stoi(mas[i]));
                i++;
            }
            fin.close();
        }
        catch(const exception&ex) {
            fin.close();
        }

        cout << "\nDeshifr: ";
        i = 0;
        //расшифровываем строку
        while (i != this_shifr.size()) {
            pos = fast_pow(this_shifr[i], d, n);
            char b(pos);
            cout <<b << " ";
            i++;
        }
    }
    