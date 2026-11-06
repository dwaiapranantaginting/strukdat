#include <iostream>
#include <queue>
using namespace std;

int main() {
    const int V = 6;
    int graph[V][V] = {0};
    int jumlahEdge;

    cout << "=== PROGRAM BFS ===" << endl;
    cout << "Vertex: A, B, C, D, E, F" << endl;

    cout << "Masukkan jumlah edge: ";
    cin >> jumlahEdge;

    for (int i = 0; i < jumlahEdge; i++) {
        char asal, tujuan;

        cout << "Edge ke-" << i + 1 << " (contoh A B): ";
        cin >> asal >> tujuan;

        int u = asal - 'A';
        int v = tujuan - 'A';

        if (u >= 0 && u < V && v >= 0 && v < V) {
            graph[u][v] = 1;
            graph[v][u] = 1;
        } else {
            cout << "Vertex tidak valid!" << endl;
            i--;
        }
    }

    char mulai;
    cout << "\nMasukkan vertex awal BFS: ";
    cin >> mulai;

    int start = mulai - 'A';

    if (start < 0 || start >= V) {
        cout << "Vertex tidak valid!" << endl;
        return 0;
    }

    bool visited[V] = {false};
    queue<int> q;

    visited[start] = true;
    q.push(start);

    cout << "\nUrutan BFS: ";

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        cout << char(current + 'A') << " ";

        for (int i = 0; i < V; i++) {
            if (graph[current][i] == 1 && !visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }

    cout << endl;

    return 0;
}