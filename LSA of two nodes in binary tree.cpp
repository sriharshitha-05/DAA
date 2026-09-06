#include <iostream>
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

Node* LCA(Node* root, int a, int b) {

    if(root == NULL)
        return NULL;

    if(root->data == a || root->data == b)
        return root;

    Node* left = LCA(root->left, a, b);
    Node* right = LCA(root->right, a, b);

    if(left != NULL && right != NULL)
        return root;

    if(left != NULL)
        return left;

    return right;
}

int main() {
    Node* root = newNode(1);

    root->left = newNode(2);
    root->right = newNode(3);

    root->left->left = newNode(4);
    root->left->right = newNode(5);

    int a, b;
    cin >> a >> b;

    Node* ans = LCA(root, a, b);

    if(ans)
        cout << "LCA = " << ans->data;
    else
        cout << "Not found";

    return 0;
}
