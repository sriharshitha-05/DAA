#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

#define N 4
#define INF INT_MAX

struct Node {
    vector<pair<int, int>> path;
    int reducedMatrix[N][N];
    int cost;
    int vertex;
    int level;
};

Node* newNode(int parentMatrix[N][N], vector<pair<int, int>> const &path, int level, int i, int j) {
    Node* node = new Node;
    node->path = path;
    if (level != 0) {
        node->path.push_back(make_pair(i, j));
    }
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            node->reducedMatrix[r][c] = parentMatrix[r][c];
        }
    }
    for (int k = 0; level != 0 && k < N; k++) {
        node->reducedMatrix[i][k] = INF;
        node->reducedMatrix[k][j] = INF;
    }
    node->reducedMatrix[j][0] = INF;
    node->level = level;
    node->vertex = j;
    return node;
}

int rowReduction(int reducedMatrix[N][N], int row[N]) {
    fill_n(row, N, INF);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (reducedMatrix[i][j] < row[i]) {
                row[i] = reducedMatrix[i][j];
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (reducedMatrix[i][j] != INF && row[i] != INF) {
                reducedMatrix[i][j] -= row[i];
            }
        }
    }
    int cost = 0;
    for (int i = 0; i < N; i++) {
        if (row[i] != INF) cost += row[i];
    }
    return cost;
}

int colReduction(int reducedMatrix[N][N], int col[N]) {
    fill_n(col, N, INF);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (reducedMatrix[i][j] < col[j]) {
                col[j] = reducedMatrix[i][j];
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (reducedMatrix[i][j] != INF && col[j] != INF) {
                reducedMatrix[i][j] -= col[j];
            }
        }
    }
    int cost = 0;
    for (int i = 0; i < N; i++) {
        if (col[i] != INF) cost += col[i];
    }
    return cost;
}

int calculateCost(int reducedMatrix[N][N]) {
    int cost = 0;
    int row[N];
    cost += rowReduction(reducedMatrix, row);
    int col[N];
    cost += colReduction(reducedMatrix, col);
    return cost;
}

struct comp {
    bool operator()(const Node* lhs, const Node* rhs) const {
        return lhs->cost > rhs->cost;
    }
};

int solve(int costMatrix[N][N]) {
    priority_queue<Node*, vector<Node*>, comp> pq;
    vector<pair<int, int>> v;
    Node* root = newNode(costMatrix, v, 0, 0, 0);
    root->cost = calculateCost(root->reducedMatrix);
    pq.push(root);

    while (!pq.empty()) {
        Node* minNode = pq.top();
        pq.pop();
        int i = minNode->vertex;

        if (minNode->level == N - 1) {
            minNode->path.push_back(make_pair(i, 0));
            int finalCost = minNode->cost;
            delete minNode;
            while (!pq.empty()) {
                delete pq.top();
                pq.pop();
            }
            return finalCost;
        }

        for (int j = 0; j < N; j++) {
            if (minNode->reducedMatrix[i][j] != INF) {
                Node* child = newNode(minNode->reducedMatrix, minNode->path, minNode->level + 1, i, j);
                child->cost = minNode->cost + minNode->reducedMatrix[i][j] + calculateCost(child->reducedMatrix);
                pq.push(child);
            }
        }
        delete minNode;
    }
    return INF;
}

int main() {
    int costMatrix[N][N] = {
        { INF, 10,  15,  20 },
        { 10,  INF, 35,  25 },
        { 15,  35,  INF, 30 },
        { 20,  25,  30,  INF }
    };
    cout << solve(costMatrix) << endl;
    return 0;
}
