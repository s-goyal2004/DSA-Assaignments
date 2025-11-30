#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

void printTree(Node* root, int space = 0) {
    if (root == NULL) return;

    space += 6;

    printTree(root->right, space);

    cout << endl;
    for (int i = 6; i < space; i++)
        cout << " ";
    cout << root->data;

    printTree(root->left, space);
}

void preorder(Node* root) {
    if (root == NULL) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main() {
    // Creating the standard binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout << "Binary Tree Structure:\n";
    printTree(root);

    cout << "\n\nPre-order Traversal  : ";
    preorder(root);

    cout << "\nIn-order Traversal   : ";
    inorder(root);

    cout << "\nPost-order Traversal : ";
    postorder(root);

    cout << endl;
    return 0;
}
