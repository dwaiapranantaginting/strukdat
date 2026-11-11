#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Ukuran Hash Table sesuai ketentuan (10)
const int TABLE_SIZE = 10;

class HashTable {
private:
    struct HashNode {
        string nim;
        string nama;
        bool isOccupied;
        bool isDeleted;

        HashNode() : nim(""), nama(""), isOccupied(false), isDeleted(false) {}
    };

    vector<HashNode> table;

    // Hash Function pertama: h1(k) = k % TABLE_SIZE
    int hash1(long long key) {
        return key % TABLE_SIZE;
    }

    // Hash Function kedua untuk Double Hashing: h2(k) = R - (k % R)
    // Di mana R adalah bilangan prima yang lebih kecil dari TABLE_SIZE (misal: 7)
    int hash2(long long key) {
        int prime = 7;
        return prime - (key % prime);
    }

public:
    HashTable() {
        table.resize(TABLE_SIZE);
    }

    // Operasi INSERT
    void insert(string nim, string nama) {
        long long key = stoll(nim);
        int h1 = hash1(key);
        int h2 = hash2(key);

        for (int i = 0; i < TABLE_SIZE; i++) {
            int index = (h1 + i * h2) % TABLE_SIZE;

            // Jika slot kosong atau pernah dihapus, masukkan data baru
            if (!table[index].isOccupied || table[index].isDeleted) {
                table[index].nim = nim;
                table[index].nama = nama;
                table[index].isOccupied = true;
                table[index].isDeleted = false;
                cout << "Berhasil memasukkan: NIM " << nim << " (" << nama << ") di indeks " << index << "\n";
                return;
            }
            
            // Jika NIM sudah ada, update namanya
            if (table[index].isOccupied && table[index].nim == nim) {
                table[index].nama = nama;
                cout << "NIM " << nim << " sudah ada. Nama diperbarui di indeks " << index << "\n";
                return;
            }
        }
        cout << "Hash Table penuh! Gagal memasukkan NIM " << nim << "\n";
    }

    // Operasi SEARCH
    int search(string nim) {
        long long key = stoll(nim);
        int h1 = hash1(key);
        int h2 = hash2(key);

        for (int i = 0; i < TABLE_SIZE; i++) {
            int index = (h1 + i * h2) % TABLE_SIZE;

            // Jika slot benar-benar kosong (bukan bekas delete), data tidak ada
            if (!table[index].isOccupied && !table[index].isDeleted) {
                return -1;
            }

            if (table[index].isOccupied && table[index].nim == nim) {
                return index;
            }
        }
        return -1;
    }

    // Operasi REMOVE
    void remove(string nim) {
        int index = search(nim);
        if (index != -1) {
            table[index].nim = "";
            table[index].nama = "";
            table[index].isOccupied = false;
            table[index].isDeleted = true; // Menandai bahwa slot ini pernah dihapus (untuk menjaga rantai probing)
            cout << "Data dengan NIM " << nim << " berhasil dihapus dari indeks " << index << "\n";
        } else {
            cout << "Data dengan NIM " << nim << " tidak ditemukan.\n";
        }
    }

    // Menampilkan isi Hash Table
    void display() {
        cout << "\n--- ISI HASH TABLE ---\n";
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << "Indeks " << i << ": ";
            if (table[i].isOccupied) {
                cout << "[NIM: " << table[i].nim << ", Nama: " << table[i].nama << "]\n";
            } else {
                cout << "[Kosong]\n";
            }
        }
        cout << "----------------------\n";
    }
};

int main() {
    HashTable ht;

    // Contoh Pengujian Operasi Insert, Search, dan Remove
    cout << "=== MELAKUKAN OPERASI INSERT ===\n";
    ht.insert("220101", "Andi");
    ht.insert("220111", "Budi"); // Berpotensi collision dengan 220101 jika h1 sama
    ht.insert("220102", "Citra");
    ht.insert("220105", "Dewi");

    // Tampilkan isi setelah insert
    ht.display();

    cout << "\n=== MELAKUKAN OPERASI SEARCH ===\n";
    string cariNIM = "220111";
    int hasilCari = ht.search(cariNIM);
    if (hasilCari != -1) {
        cout << "Ditemukan NIM " << cariNIM << " pada indeks " << hasilCari << "\n";
    } else {
        cout << "NIM " << cariNIM << " tidak ditemukan.\n";
    }

    cout << "\n=== MELAKUKAN OPERASI REMOVE ===\n";
    ht.remove("220101");

    // Tampilkan isi akhir setelah seluruh operasi selesai
    ht.display();

    return 0;
}