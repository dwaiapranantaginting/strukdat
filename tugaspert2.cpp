#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = nullptr;

void tambahBelakang(int v) {
    Node* baru = new Node{v, nullptr};
    if (!head) { head = baru; return; }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = baru;
}

void tambahDepan(int v) {
    head = new Node{v, head};
}

void tambahTengah(int setelah, int v) {
    Node* temp = head;
    while (temp && temp->data != setelah) temp = temp->next;
    if (temp) temp->next = new Node{v, temp->next};
}

void hapusNode(int v) {
    if (!head) return;
    if (head->data == v) {
        Node* hapus = head;
        head = head->next;
        delete hapus;
        return;
    }
    Node* temp = head;
    while (temp->next && temp->next->data != v) temp = temp->next;
    if (temp->next) {
        Node* hapus = temp->next;
        temp->next = hapus->next;
        delete hapus;
    }
}

void tampilkan() {
    Node* temp = head;
    while (temp) {
        cout << temp->data;
        if (temp->next) cout << ", ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int nilai[] = {100, 92, 45, 87, 71, 99, 95, 60, 55, 88};
    for (int i = 0; i < 10; i++) tambahBelakang(nilai[i]);

    cout << "Awal: "; tampilkan();

    tambahDepan(70);
    cout << "Tambah 70 didepan: "; tampilkan();

    tambahBelakang(50);
    cout << "Tambah 50 dibelakang: "; tampilkan();

    tambahTengah(45, 0);
    cout << "Tambah 0 setelah 45: "; tampilkan();

    hapusNode(99);
    cout << "Hapus 99: "; tampilkan();

    hapusNode(60);
    cout << "Hapus 60: "; tampilkan();

    return 0;
}