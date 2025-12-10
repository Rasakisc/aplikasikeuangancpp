#include <iostream>
#include <string>
#include <fstream>


using namespace std;
const string buka = "keuangan.txt";

struct structuang {
    int uangnya;
};

void pilihan();
void keluar();
void tambahtransaksi();


int main() {
    pilihan();

    return 0;
}

void tambahtransaksi() {

    

    int n;
    cout << "1. Pemasukan" << endl;
    cout << "2. Pengeluaran" << endl;
    cout << "Pilih : ";
    cin >> n;
    if(n == 1) {

        structuang uang;
        cout << "Masukkan Jumlah Uang : ";
        cin >> uang.uangnya;
        ofstream file(buka,ios::app);
        file << "Pemasukan : " << uang.uangnya << endl;
        file.close();
        pilihan();

    } else if(n == 2) {
        structuang uang;
        cout << "Masukkan Jumlah Uang : ";
        cin >> uang.uangnya;
        ofstream file(buka,ios::app);
        file << "Pengeluaran : " << uang.uangnya << endl;
        file.close();
        pilihan();
    }

}

void keluar() {

    cout << "Terima kasih sudah menggunakan aplikasi kami ^-^)" << endl; 
}

void pilihan() {
 
    int n;
    cout << "Aplikasi Pelacakan Keuangan" << endl;
    cout << "1. Tambah transaksi" << endl;
    cout << "2. Lihat riwayat transaksi" << endl;
    cout << "3. Hitung saldo terakhir" << endl;
    cout << "4. Keluar" << endl;
    cout << "Pilih menu : ";
    cin >> n;

    switch(n) {
        case 1: 
        tambahtransaksi();
        break;
        case 4:
        keluar();
        break;
        default:
        cout << "Pilih menu yang ada" << endl;
        pilihan();
    }
}