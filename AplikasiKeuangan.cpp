#include <iostream>
#include <string>
#include <fstream>


using namespace std;
const string buka = "keuangan.txt";

struct catatanuang {
    int uang;
    string dekripsi;
};

void pilihan();
void keluar();
void tambahtransaksi();
void riwayattransaksi();


int main() {

    // summon pertama ^-^)
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

        catatanuang catatanuang;
        cout << "Masukkan Jumlah Uang : ";
        cin >> catatanuang.uang;
        cin.ignore();
        cout << "Dekripsi Transaksi : ";
        getline(cin, catatanuang.dekripsi);
        cout << "Transaksi sudah tersimpan ^-^";
        cout << "\n\n\n";
        ofstream file(buka,ios::app);
        file << "Pemasukan : " << catatanuang.uang << endl;
        file << "Dekripsi transaksi : " << catatanuang.dekripsi << endl;
        file.close();
        pilihan();

    } else if(n == 2) {
        catatanuang catatanuang;
        cout << "Masukkan Jumlah Uang : ";
        cin >> catatanuang.uang;
        cout << "Dekripsi Transaksi : ";
        cin >> catatanuang.dekripsi;
        cout << "Transaksi sudah tersimpan ^-^";
        cout << "\n\n\n";
        ofstream file(buka,ios::app);
        file << "Pengeluaran : " << catatanuang.uang << endl;
        file << "Dekripsi transaksi : " << catatanuang.dekripsi << endl;
        file.close();
        pilihan();
    }

}

void riwayattransaksi() {
    ifstream file(buka);
    string baris;
    while(getline(file, baris)) {

        
        cout << baris << endl;

    }
    file.close();
    cout << "\n";
    pilihan();
}

void keluar() {

    cout << "Terima kasih sudah menggunakan aplikasi kami ^-^)" << endl; 
}

void saldoterakhir() {
    string baris;
    ifstream file(buka);

    if(getline(file, baris) && baris.rfind("Pengeluaran : ",0) == 0) {

        string pengeluaran;
        pengeluaran = baris.substr(14);

        cout << pengeluaran << endl;


    }

}

void pilihan() {
 
    int n;
    bool pilihannya = false;
    cout << "Aplikasi Pelacakan Keuangan" << endl;
    cout << "1. Tambah transaksi" << endl;
    cout << "2. Lihat riwayat transaksi" << endl;
    cout << "3. Hitung saldo terakhir" << endl;
    cout << "4. Keluar" << endl;
    cout << "Pilih menu : ";
    if(cin >> n) {
        pilihannya = true;
    } else {
        pilihannya = false;
    }

    if(pilihannya == false) {
        cout << "Harus menu yang ada bukan huruf" << endl;
    }


    switch(n) {
        case 1: 
        tambahtransaksi();
        break;
        case 2:
        riwayattransaksi();
        case 3:
        saldoterakhir();
        break;
        break;
        case 4:
        keluar();
        break;
        default:
        cout << "Pilih menu yang ada" << endl;
        cout << "\n";
        pilihan();
        break;
        
    }
}