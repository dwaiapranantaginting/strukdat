#include <iostream>
using namespace std;

#define MAX_DATA  100

struct Node {
    int data;
    Node* kiri;
    Node* kanan;
};

void tambah(Node*& root, int angka) {
    if (root == NULL) {
        root = new Node;
        root->data = angka;
        root->kiri = NULL;
        root->kanan = NULL;
    } else if (angka < root->data) {
        tambah(root->kiri, angka);
    } else if (angka > root->data) {
        tambah(root->kanan, angka);
    } else {
        cout << "  Nilai " << angka << " sudah ada" << endl;
    }
}

void inOrderKeArray(Node* root, int data[], int &n) {
    if (root != NULL) {
        inOrderKeArray(root->kiri, data, n);

        data[n] = root->data;
        n++;

        inOrderKeArray(root->kanan, data, n);
    }
}

void tampilkanRentang(int data[], int n, int batasBawah, int batasAtas, int &jumlah) {
    jumlah = 0;

    for (int i = 0; i < n; i++) {
        if (data[i] >= batasBawah && data[i] <= batasAtas) {
            cout << data[i] << " ";
            jumlah++;
        }
    }
}

int binarySearch(int data[], int low, int high, int target) {
    if (low > high) {
        return -1;
    }

    int mid = low + (high - low) / 2;

    if (data[mid] == target) {
        return mid;
    } else if (target < data[mid]) {
        return binarySearch(data, low, mid - 1, target);
    } else {
        return binarySearch(data, mid + 1, high, target);
    }
}

void hapusSemua(Node*& root) {
    if (root != NULL) {
        hapusSemua(root->kiri);
        hapusSemua(root->kanan);
        delete root;
        root = NULL;
    }
}

int main() {
    system("cls");

    Node* root = NULL;
    int angka;

    cout << "Masukkan bilangan bulat (" << -1 << " = stop) : ";
    cin >> angka;

    while (angka != -1) {
        tambah(root, angka);
        cin >> angka;
    }

    if (root == NULL) {
        cout << "\nBST kosong, tidak ada data yang bisa diproses" << endl;
        return 0;
    }

    int data[MAX_DATA];
    int n = 0;
    inOrderKeArray(root, data, n);

    cout << "\nIsi BST terurut (in-order) : ";
    for (int i = 0; i < n; i++) {
        cout << data[i] << " ";
    }
    cout << endl;

    int batasBawah, batasAtas;
    cout << "\nMasukkan batas bawah : ";
    cin >> batasBawah;
    cout << "Masukkan batas atas  : ";
    cin >> batasAtas;
    
    if (batasBawah > batasAtas) {
        int temp = batasBawah;
        batasBawah = batasAtas;
        batasAtas = temp;
        cout << "  (Batas ditukar menjadi " << batasBawah
             << " sampai " << batasAtas << ")" << endl;
    }

    int jumlah;
    cout << "\nNilai dalam BST antara " << batasBawah << " dan "
         << batasAtas << " (terkecil ke terbesar) : ";
    tampilkanRentang(data, n, batasBawah, batasAtas, jumlah);

    if (jumlah == 0) {
        cout << "tidak ada nilai pada rentang tersebut";
    }
    cout << endl;
    cout << "Jumlah nilai pada rentang : " << jumlah << endl;

    int dicari;
    cout << "\nMasukkan satu nilai untuk diperiksa : ";
    cin >> dicari;

    int hasil = binarySearch(data, 0, n - 1, dicari);

    if (hasil != -1) {
        cout << "Nilai " << dicari << " TERDAPAT di dalam BST"
             << " (ditemukan pada indeks ke-" << hasil
             << " array in-order)." << endl;
    } else {
        cout << "Nilai " << dicari << " TIDAK terdapat di dalam BST." << endl;
    }

    hapusSemua(root);
    return 0;
}
