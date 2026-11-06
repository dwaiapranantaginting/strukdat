#include <iostream>
#include <climits>
using namespace std;

const int V = 6;
const int INF = INT_MAX;

int graph[V][V] = {
    {0, 4, 2, 0, 0, 0},
    {4, 0, 1, 5, 3, 0},
    {2, 1, 0, 8, 0, 0},
    {0, 5, 8, 0, 2, 4},
    {0, 3, 0, 2, 0, 3},
    {0, 0, 0, 4, 3, 0}
};

void dijkstra(int start, int tujuan = -1) {
    int dist[V];
    bool visited[V] = {false};
    int parent[V];

    for (int i = 0; i < V; i++) {
        dist[i] = INF;
        parent[i] = -1;
    }

    dist[start] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = -1;
        int minDist = INF;

        for (int i = 0; i < V; i++) {
            if (!visited[i] && dist[i] < minDist) {
                minDist = dist[i];
                u = i;
            }
        }

        if (u == -1) break;

        visited[u] = true;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] > 0 && !visited[v]) {
                if (dist[u] + graph[u][v] < dist[v]) {
                    dist[v] = dist[u] + graph[u][v];
                    parent[v] = u;
                }
            }
        }
    }

    if (tujuan == -1) {
        cout << "\n=== RUTE TERPENDEK DARI A ===" << endl;

        for (int i = 0; i < V; i++) {
            cout << "A ke " << char(i + 'A') << " : ";

            if (dist[i] == INF) {
                cout << "Tidak ada rute" << endl;
            } else {
                cout << dist[i] << " km" << endl;
            }
        }
    } else {
        cout << "\n=== HASIL NAVIGASI ===" << endl;

        if (dist[tujuan] == INF) {
            cout << "Tidak ada rute yang tersedia." << endl;
            return;
        }

        int path[V];
        int panjang = 0;

        int current = tujuan;

        while (current != -1) {
            path[panjang++] = current;
            current = parent[current];
        }

        cout << "Rute tercepat: ";

        for (int i = panjang - 1; i >= 0; i--) {
            cout << char(path[i] + 'A');

            if (i > 0) cout << " -> ";
        }

        cout << "\nTotal jarak: " << dist[tujuan] << " km" << endl;
    }
}

int main() {
    cout << "=== SISTEM NAVIGASI KOTA ===" << endl;
    cout << "Lokasi: A, B, C, D, E, F" << endl;

    // Mencari jarak terpendek dari A ke semua lokasi
    dijkstra(0);

    // Input lokasi pengguna
    char asal, tujuan;

    cout << "\nMasukkan lokasi awal (A-F): ";
    cin >> asal;

    cout << "Masukkan lokasi tujuan (A-F): ";
    cin >> tujuan;

    int start = asal - 'A';
    int finish = tujuan - 'A';

    if (start < 0 || start >= V || finish < 0 || finish >= V) {
        cout << "Lokasi tidak valid!" << endl;
        return 0;
    }

    // Mencari rute tercepat berdasarkan input
    dijkstra(start, finish);

    return 0;
}