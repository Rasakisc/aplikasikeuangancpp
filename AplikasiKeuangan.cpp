#include <iostream>
#include <string>
#include <fstream>


using namespace std;


void tambahtransaksi() {

    int n;
    cout << "1. Pemasukan" << endl;
    cout << "2. Pengeluaran" << endl;
    cout << "Pilih : ";
    cin >> n;
    if(n == 1) {
        int uang;
        cout << "Masukkan Jumlah Uang : ";
        cin >> uang;
        ofstream buka;
        buka.open("keuangan.txt");
        buka << uang << endl;
        buka.close();

    } else if(n == 2) {
        cout << "dua";
    }

}

void keluar() {

    cout << "Terima kasih sudah menggunakan aplikasi kami ^-^)" << endl; 
}

void pilihan() {
 
    int n;
    cout << "Aplikasi Catatan Keuangan" << endl;
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
        pilihan();
    }
}


int main() {
    pilihan();

    return 0;
}