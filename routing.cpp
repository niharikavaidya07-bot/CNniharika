
#include <iostream>
using namespace std;

int main() {
    int n = 7;
    int cost[7][7] = {
        {0, 2, 4, 0, 0, 0, 0},
        {2, 0, 1, 7, 0, 0, 0},
        {4, 1, 0, 3, 5, 0, 0},
        {0, 7, 3, 0, 2, 4, 0},
        {0, 0, 5, 2, 0, 1, 6},
        {0, 0, 0, 4, 1, 0, 2},
        {0, 0, 0, 0, 6, 2, 0}
    };

    int dist[7], visited[7] = {0}, parent[7];
    char s, d;
    int source, dest, minDist, next;

    cout << "Available routers: A B C D E F G\n";
    cout << "Enter source router: ";
    cin >> s;
    cout << "Enter destination router: ";
    cin >> d;

    source = s - 'A';
    dest = d - 'A';

    if (source < 0 || source >= n || dest < 0 || dest >= n) {
        cout << "Invalid router!\n";
        return 0;
    }

    for (int i = 0; i < n; i++) {
        dist[i] = 9999;
        parent[i] = -1;
    }

    dist[source] = 0;

    for (int i = 0; i < n; i++) {
        minDist = 9999;
        next = -1;

        for (int j = 0; j < n; j++)
            if (!visited[j] && dist[j] < minDist)
                minDist = dist[j], next = j;

        if (next == -1) break;
        visited[next] = 1;

        for (int j = 0; j < n; j++) {
            if (cost[next][j] > 0 && !visited[j] &&
                dist[next] + cost[next][j] < dist[j]) {
                dist[j] = dist[next] + cost[next][j];
                parent[j] = next;
            }
        }
    }

    cout << "\nShortest distances from router " << s << ":\n";
    for (int i = 0; i < n; i++) {
        cout << s << " to " << char('A' + i) << " = ";
        if (dist[i] == 9999) cout << "Unreachable\n";
        else cout << dist[i] << "\n";
    }

    if (dist[dest] == 9999) {
        cout << "\nNo path exists.\n";
    } else {
        int path[7], len = 0;
        for (int v = dest; v != -1; v = parent[v])
            path[len++] = v;

        cout << "\nShortest path: ";
        for (int i = len - 1; i >= 0; i--) {
            cout << char('A' + path[i]);
            if (i > 0) cout << " -> ";
        }

        cout << "\nMinimum routing cost: " << dist[dest] << "\n";
    }

    return 0;
}
