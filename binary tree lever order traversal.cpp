#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

Node* newNode(int x) {
    Node* temp = new Node;
    temp->data = x;
    temp->left = temp->right = NULL;
    return temp;
}

void levelOrder(Node* root) {
    if(root == NULL)
        return;

    queue<Node*> q;
    q.push(root);

    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();

        cout << temp->data << " ";

        if(temp->left)
            q.push(temp->left);

        if(temp->right)
            q.push(temp->right);
    }
}

int main() {
    Node* root = newNode(1);

    root->left = newNode(2);
    root->right = newNode(3);

    root->left->left = newNode(4);
    root->left->right = newNode(5);

    levelOrder(root);

    return 0;
}
