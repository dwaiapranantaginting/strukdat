#include <iostream>
using namespace std;

#define MAX_DATA 100

struct Node {
    int data;
    Node* next;
};

Node* head = nullptr;

void tambahBelakang(int v) {
    Node* baru = new Node();
    baru->data = v;
    baru->next = nullptr;

    if (head == nullptr) {
        head = baru;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = baru;
}

void tampilkan() {
    if (head == nullptr) {
        cout << "  Linked list kosong" << endl;
        return;
    }

    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int hitungNode() {
    int jumlah = 0;
    Node* temp = head;
    while (temp != nullptr) {
        jumlah++;
        temp = temp->next;
    }
    return jumlah;
}

void hapusSetelah(Node*& head, int nilaiCari) {
    if (head == nullptr) {
        cout << "  Linked list kosong, tidak ada yang bisa dihapus" << endl;
        return;
    }

    Node* temp = head;
    while (temp != nullptr && temp->data != nilaiCari) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "  Nilai " << nilaiCari << " tidak ditemukan dalam linked list" << endl;
        return;
    }

    if (temp->next == nullptr) {
        cout << "  Nilai " << nilaiCari
             << " ditemukan, tetapi tidak memiliki node setelahnya" << endl;
        return;
    }

    Node* hapus = temp->next;
    temp->next = hapus->next;
    cout << "  Node dengan nilai " << hapus->data
         << " (tepat setelah " << nilaiCari << ") berhasil dihapus" << endl;
    delete hapus;
}

void balikList(Node*& head) {
    if (head == nullptr) {
        cout << "  Linked list kosong, tidak ada yang bisa dibalik" << endl;
        return;
    }

    Node* prev = nullptr;
    Node* curr = head;
    Node* next = nullptr;

    while (curr != nullptr) {
        next = curr->next;  
        curr->next = prev;  
        prev = curr;        
        curr = next;        
    }

    head = prev;            
    cout << "  Urutan linked list berhasil dibalik" << endl;
}

void hapusSemua() {
    Node* temp = head;
    while (temp != nullptr) {
        Node* hapus = temp;
        temp = temp->next;
        delete hapus;
    }
    head = nullptr;
}

int main() {
    system("cls");

    int data[MAX_DATA];
    int n;

    cout << "Banyak data yang ingin dimasukkan : ";
    cin >> n;

    if (n <= 0) {
        cout << "Jumlah data tidak valid" << endl;
        return 0;
    }
    if (n > MAX_DATA) {
        n = MAX_DATA;
    }

    for (int i = 0; i < n; i++) {
        cout << "Data ke-" << i + 1 << " : ";
        cin >> data[i];
    }

    for (int i = 0; i < n; i++) {
        tambahBelakang(data[i]);
    }

    cout << "\nData awal : ";
    tampilkan();

    int pilihan;
    do {
        cout << "\n menu" << endl;
        cout << "1. Tampilkan seluruh data" << endl;
        cout << "2. Hapus node setelah nilai tertentu" << endl;
        cout << "3. Balik urutan linked list" << endl;
        cout << "4. Tampilkan jumlah node" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilihan : ";
        cin >> pilihan;

        if (pilihan == 1) {
            cout << "\nIsi linked list : ";
            tampilkan();

        } else if (pilihan == 2) {
            int nilaiCari;
            cout << "Hapus node tepat setelah nilai : ";
            cin >> nilaiCari;
            hapusSetelah(head, nilaiCari);
            cout << "Isi linked list sekarang : ";
            tampilkan();

        } else if (pilihan == 3) {
            balikList(head);
            cout << "Isi linked list sekarang : ";
            tampilkan();

        } else if (pilihan == 4) {
            cout << "Jumlah node : " << hitungNode() << endl;

        } else if (pilihan != 0) {
            cout << "Pilihan tidak tersedia." << endl;
        }

    } while (pilihan != 0);

    hapusSemua();
    return 0;
}
