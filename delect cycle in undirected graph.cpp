#include <iostream>
using namespace std;

int graph[10][10];
int visited[10];
int n;

bool DFS(int v, int parent) {
    visited[v] = 1;

    for(int i = 0; i < n; i++) {

        if(graph[v][i] == 1) {

            if(visited[i] == 0) {
                if(DFS(i, v))
                    return true;
            }

            else if(i != parent) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    cin >> n;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> graph[i][j];

    for(int i = 0; i < n; i++)
        visited[i] = 0;

    for(int i = 0; i < n; i++) {
        if(visited[i] == 0) {
            if(DFS(i, -1)) {
                cout << "Cycle exists";
                return 0;
            }
        }
    }

    cout << "No cycle";

    return 0;
}
