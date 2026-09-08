#include <iostream>
using namespace std;

int main (){

    int angka[3][3][4];
    int nilai = 2;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 4; k++) {
                angka[i][j][k] = nilai;
                nilai += 2;
            }
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 4; k++) {
                cout << angka[i][j][k] << "\t";
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}
