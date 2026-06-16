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

    if (adaHurufKecil && !adaHurufBesar && !adaAngka && !adaSimbol) {
        karakter = 26; 
    } 
    else if ((adaHurufKecil || adaHurufBesar) && adaAngka && !adaSimbol) {
        karakter = 62; 
    } 
    else if ((adaHurufKecil || adaHurufBesar) && adaAngka && adaSimbol) {
        karakter = 94; 
    } 
    else {
        karakter = 0;
        if (adaHurufKecil) karakter += 26;
        if (adaHurufBesar) karakter += 26;
        if (adaAngka) karakter += 10;
        if (adaSimbol) karakter += 32;
    }
    long double kombinasi = pow(karakter, panjang);

    cout << endl;
    cout << "=== HASIL ANALISIS REKOMENDASI ===" << endl;
    cout << "Password kamu            : " << password << endl;
    cout << "Panjang password         : " << panjang << " karakter" << endl;
    cout << "Jumlah karakter tersedia : " << karakter << endl;
    cout << "Jumlah kemungkinan (N)   : " << setprecision(0) << kombinasi << endl;

    if (adaHurufKecil && !adaHurufBesar && !adaAngka && !adaSimbol) {
        cout << "Kategori keamanan        : Lemah" << endl;
    }
    else if ((adaHurufKecil || adaHurufBesar) && adaAngka && !adaSimbol) {
        cout << "Kategori keamanan        : Sedang" << endl;
    }
    else if ((adaHurufKecil || adaHurufBesar) && adaAngka && adaSimbol) {
        cout << "Kategori keamanan        : Kuat" << endl;
    }
    else {
        if (kombinasi <= 208827064576.0) 
            cout << "Kategori keamanan        : Lemah" << endl;
        else if (kombinasi <= 218340105584896.0) 
            cout << "Kategori keamanan        : Sedang" << endl;
        else 
            cout << "Kategori keamanan        : Kuat" << endl;
    }

    return 0;
}