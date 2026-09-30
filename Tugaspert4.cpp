#include <iostream>
using namespace std;

struct Node 
{
    int data;
    Node* kiri;
    Node* kanan;
};

void tambah(Node*& root, int angka) 
{
    if (root == NULL) {
        root = new Node;
        root->data = angka;
        root->kiri = NULL;
        root->kanan = NULL;
    } else if (angka < root->data) {
        tambah(root->kiri, angka);
    } else if (angka > root->data) {
        tambah(root->kanan, angka);
    }
}

void preOrder(Node* root) 
{
    if (root != NULL) {
        cout << root->data << " ";
        preOrder(root->kiri);
        preOrder(root->kanan);
    }
}

void inOrder(Node* root) 
{
    if (root != NULL) {
        inOrder(root->kiri);
        cout << root->data << " ";
        inOrder(root->kanan);
    }
}

void postOrder(Node* root) 
{
    if (root != NULL) {
        postOrder(root->kiri);
        postOrder(root->kanan);
        cout << root->data << " ";
    }
}

int main () 
{
    Node* root = NULL;
    int angka;

    cout << "Masukkan angka (0=stop) : ";
    cin >> angka;

    while (angka != 0) {
        tambah(root, angka);
        cin >> angka;
    }

    cout << "Pre: ";
    preOrder(root);
    cout << endl;

    cout << "In: ";
    inOrder(root);
    cout << endl;

    cout << "Post: ";
    postOrder(root);
    cout << endl;
}