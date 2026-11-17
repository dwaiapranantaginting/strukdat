#include <iostream>
#include <string>
using namespace std;
int nilai[5][4];

string nama[5];
float rataRata[5];

string komponen[4] = {"Tugas", "Kuis", "UTS", "Praktikum"};

void inputData() {
    for (int i = 0; i < 5; i++) {
        cout << "Mahasiswa ke-" << i + 1 << endl;
        cout << "  Nama : ";
        cin >> nama[i];

        for (int j = 0; j < 4; j++) {
            cout << "  " << komponen[j] << " : ";
            cin >> nilai[i][j];
        }
    }
}

void hitungRataRata() {
    for (int i = 0; i < 5; i++) {
        int total = 0;
        for (int j = 0; j < 4; j++) {
            total = total + nilai[i][j];
        }
        rataRata[i] = (float) total / 4;
    }
}

void tampilkanData() {
    cout << "\nNama     Tugas   Kuis    UTS     Praktikum   Rata-rata" << endl;

    for (int i = 0; i < 5; i++) {
        cout << nama[i] << "    ";
        for (int j = 0; j < 4; j++) {
            cout << nilai[i][j] << "    ";
        }
        cout.precision(2);
        cout << fixed << rataRata[i] << endl;
    }
}

void cariTertinggiTerendah(int &idxTertinggi, int &idxTerendah) {
    idxTertinggi = 0;
    idxTerendah = 0;

    for (int i = 1; i < 5; i++) {
        if (rataRata[i] > rataRata[idxTertinggi]) {
            idxTertinggi = i;
        }
        if (rataRata[i] < rataRata[idxTerendah]) {
            idxTerendah = i;
        }
    }
}

int hitungLulus() {
    int jumlah = 0;

    cout << "\nMahasiswa dengan rata-rata minimal 75 : " << endl;
    for (int i = 0; i < 5; i++) {
        if (rataRata[i] >= 75) {
            jumlah++;
            cout << "  " << nama[i] << " (" << rataRata[i] << ")" << endl;
        }
    }
    if (jumlah == 0) {
        cout << "  tidak ada" << endl;
    }

    return jumlah;
}

int main() {
    system("cls");

    inputData();
    hitungRataRata();
    tampilkanData();

    int idxTertinggi, idxTerendah;
    cariTertinggiTerendah(idxTertinggi, idxTerendah);

    cout << "\nRata-rata tertinggi : " << nama[idxTertinggi]
         << " (" << rataRata[idxTertinggi] << ")" << endl;
    cout << "Rata-rata terendah  : " << nama[idxTerendah]
         << " (" << rataRata[idxTerendah] << ")" << endl;

    int jumlahLulus = hitungLulus();
    cout << "\nJumlah mahasiswa dengan rata-rata >= 75 : " << jumlahLulus << " dari " << 5 << endl;

    return 0;
}
