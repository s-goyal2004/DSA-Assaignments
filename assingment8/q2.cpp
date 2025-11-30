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

Node* insertNode(Node* root, int val) {
    if (root == NULL) 
        return new Node(val);

    if (val < root->data)
        root->left = insertNode(root->left, val);
    else
        root->right = insertNode(root->right, val);

    return root;
}

// (a) Recursive Search
Node* searchRec(Node* root, int key) {
    if (root == NULL || root->data == key)
        return root;

    if (key < root->data)
        return searchRec(root->left, key);
    return searchRec(root->right, key);
}

// (a) Non-recursive Search
Node* searchIter(Node* root, int key) {
    while (root != NULL) {
        if (root->data == key)
            return root;
        else if (key < root->data)
            root = root->left;
        else
            root = root->right;
    }
    return NULL;
}

// (b) Maximum element in BST
Node* findMax(Node* root) {
    if (root == NULL) return NULL;

    while (root->right != NULL)
        root = root->right;

    return root;
}

// (c) Minimum element in BST
Node* findMin(Node* root) {
    if (root == NULL) return NULL;

    while (root->left != NULL)
        root = root->left;

    return root;
}

// (d) In-order Successor
Node* inorderSuccessor(Node* root, int key) {
    Node* curr = searchIter(root, key);
    if (curr == NULL) return NULL;

    // Case 1: Right subtree exists → successor = min(right)
    if (curr->right != NULL)
        return findMin(curr->right);

    // Case 2: No right subtree → find ancestor
    Node* successor = NULL;
    Node* ancestor = root;

    while (ancestor != curr) {
        if (curr->data < ancestor->data) {
            successor = ancestor;
            ancestor = ancestor->left;
        } else {
            ancestor = ancestor->right;
        }
    }
    return successor;
}

// (e) In-order Predecessor
Node* inorderPredecessor(Node* root, int key) {
    Node* curr = searchIter(root, key);
    if (curr == NULL) return NULL;

    // Case 1: Left subtree exists → predecessor = max(left)
    if (curr->left != NULL)
        return findMax(curr->left);

    // Case 2: No left subtree → find ancestor
    Node* predecessor = NULL;
    Node* ancestor = root;

    while (ancestor != curr) {
        if (curr->data > ancestor->data) {
            predecessor = ancestor;
            ancestor = ancestor->right;
        } else {
            ancestor = ancestor->left;
        }
    }
    return predecessor;
}

// In-order Print for reference
void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = NULL;

    // Constructing BST
    int arr[] = {20, 10, 30, 5, 15, 25, 40};
    for (int x : arr)
        root = insertNode(root, x);

    cout << "BST (In-order): ";
    inorder(root);
    cout << endl;

    int key = 15;

    // Search
    cout << "\nSearching for " << key << " (Recursive): ";
    cout << (searchRec(root, key) ? "Found" : "Not Found");

    cout << "\nSearching for " << key << " (Iterative): ";
    cout << (searchIter(root, key) ? "Found" : "Not Found");

    // Min & Max
    cout << "\n\nMinimum Element: " << findMin(root)->data;
    cout << "\nMaximum Element: " << findMax(root)->data;

    // Successor & Predecessor
    Node* succ = inorderSuccessor(root, key);
    Node* pred = inorderPredecessor(root, key);

    cout << "\n\nIn-order Successor of " << key << ": ";
    if (succ) cout << succ->data; else cout << "None";

    cout << "\nIn-order Predecessor of " << key << ": ";
    if (pred) cout << pred->data; else cout << "None";

    cout << endl;
    return 0;
}
