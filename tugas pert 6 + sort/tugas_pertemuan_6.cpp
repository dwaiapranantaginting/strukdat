#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;

    cout << "jumlah kata: ";
    cin >> n;

    string kata[n];

    cout << "masukkan kata:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Kata ke-" << i + 1 << ": ";
        cin >> kata[i];
    }

    cout << "proses Insertion Sort:" << endl;

    for (int i = 1; i < n; i++) {
        string key = kata[i];
        int j = i - 1;

        cout << "langkah " << i << ":" << endl;

        while (j >= 0 && kata[j] > key) {
            kata[j + 1] = kata[j];

            cout << "geser " << kata[j] << " ke posisi kanan" << endl;

            j--;
        }

        kata[j + 1] = key;

        cout << "masukkan " << key << " ke posisi yang sesuai" << endl;

        cout << "hasil: ";
        for (int k = 0; k < n; k++) {
            cout << kata[k] << " ";
        }
        cout << endl;
    }

    cout << "hasil akhir (A-Z):" << endl;
    for (int i = 0; i < n; i++) {
        cout << kata[i] << " ";
    }

    cout << endl;

    return 0;
}