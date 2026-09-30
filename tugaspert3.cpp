#include <iostream>
#include <stack>
using namespace std;

int main() {
    string kata; 
    stack<char> s;

    cout << "masukkan kata: ";
    cin >> kata;

    for (char huruf : kata) {
        s.push(huruf);
    }

    cout << "kata abis dibalik: ";

    while (!s.empty()) {
        cout << s.top();
        s.pop();
    }

    cout << endl;

    return 0;
}