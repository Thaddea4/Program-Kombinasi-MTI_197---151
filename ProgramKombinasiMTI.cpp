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
    
    for (int i = 0; i < panjang; i++) {
        char c = password[i];
        if (c >= 'a' && c <= 'z') {
            adaHurufKecil = true;
        } else if (c >= 'A' && c <= 'Z') {
            adaHurufBesar = true;
        } else if (c >= '0' && c <= '9') {
            adaAngka = true;
        } else {
            adaSimbol = true; 
        }
    }
}