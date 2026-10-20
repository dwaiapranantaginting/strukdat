#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int target) {
    int kiri = 0;
    int kanan = n - 1;

    while (kiri <= kanan) {
        int tengah = kiri + (kanan - kiri) / 2;

        if (arr[tengah] == target) {
            return tengah;         
        } else if (arr[tengah] < target) {
            kiri = tengah + 1;     
        } else {
            kanan = tengah - 1;    
        }
    }

    return -1;                   
}

int main() {
    int n;
    cout << "Masukkan jumlah data nilai mahasiswa: ";
    cin >> n;

    if (n <= 0) {
        cout << "Jumlah data harus lebih dari 0." << endl;
        return 1;
    }

    int nilai[n];

    cout << "Masukkan " << n << " nilai (harus sudah terurut ascending):" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Nilai ke-" << i << ": ";
        cin >> nilai[i];
    }

    for (int i = 1; i < n; i++) {
        if (nilai[i] < nilai[i - 1]) {
            cout << "Data tidak terurut ascending! Binary Search tidak dapat digunakan." << endl;
            return 1;
        }
    }

    int cari;
    cout << "\nMasukkan nilai yang ingin dicari: ";
    cin >> cari;

    int hasil = binarySearch(nilai, n, cari);

    if (hasil != -1) {
        cout << "Data ditemukan pada indeks ke-" << hasil << endl;
    } else {
        cout << "Data tidak ditemukan." << endl;
    }

    return 0;
}