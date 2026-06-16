#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    cout.setf(ios::fixed);

    string password;
    cout << "=== ANALISIS KEAMANAN PASSWORD ===" << endl;
    cout << "Masukkan password yang ingin diuji: ";
    getline(cin, password);
    
    int panjang = password.length();
    long long karakter = 0;
    
    bool adaHurufKecil = false;
    bool adaHurufBesar = false;
    bool adaAngka = false;
    bool adaSimbol = false;
}