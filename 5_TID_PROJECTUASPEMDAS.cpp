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
    string coutnya[] = {"Masukkan Jumlah Uang : ","Dekripsi Transaksi : ","Transaksi sudah tersimpan ^-^"}; 
    cout << "1. Pemasukan" << endl;
    cout << "2. Pengeluaran" << endl;
    cout << "Pilih : ";
    cin >> n;


    if(n == 1) {

        // jika input 1 cuy
        catatanuang catatanuang;
        cout << coutnya[0];
        cin >> catatanuang.uang;
        cin.ignore();
        cout << coutnya[1];
        getline(cin, catatanuang.dekripsi);
        cout << coutnya[2];
        cout << "\n\n\n";
        ofstream file(buka,ios::app);
        file << "Pemasukan : " << catatanuang.uang << endl;
        file << coutnya[1] << catatanuang.dekripsi << endl;
        file.close();
        pilihan();

    } else if(n == 2) {

        // ketik 2 jika turunkan prabowo
        catatanuang catatanuang;
        cout << coutnya[0];
        cin >> catatanuang.uang;
        cout << coutnya[1];
        cin >> catatanuang.dekripsi;
        cout << coutnya[2];
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
    string pemasukan;
    string pengeluaran;
    long long totalpemasukan = 0;
    long long totalpengeluaran = 0;
    long long saldo = 0;

   while (getline(file, baris)) {
        if(baris.rfind("Pemasukan : ", 0) == 0) {
            pemasukan = baris.substr(12);
            totalpemasukan += stoll(pemasukan);
        }
        else if (baris.rfind("Pengeluaran : ", 0) == 0) {
            pengeluaran = baris.substr(14);
            totalpengeluaran += stoll(pengeluaran);
        }

    }
    
    saldo = totalpemasukan - totalpengeluaran;
    cout << "Saldo sekarang : "<< saldo << endl;
    cout << "\n" << endl;
    pilihan();
    

}




void pilihan() {
 
    int n;
    
    cout << "Aplikasi Pelacakan Keuangan" << endl;
    cout << "1. Tambah transaksi" << endl;
    cout << "2. Lihat riwayat transaksi" << endl;
    cout << "3. Hitung saldo terakhir" << endl;
    cout << "4. Keluar" << endl;
    cout << "Pilih menu : ";
    if(!(cin >> n)) {

        cout << "Harus pilih menu yang ada";
        cin.clear();
        cin.ignore();
        pilihan();
        return;
    }


    switch(n) {
        case 1: 
        tambahtransaksi();
        break;
        case 2:
        riwayattransaksi();
        break;
        case 3:
        saldoterakhir();
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