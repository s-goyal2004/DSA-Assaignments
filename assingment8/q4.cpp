#include <iostream>
#include <climits>
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

// Function to check BST property using min/max range
bool isBSTUtil(Node* root, int minVal, int maxVal) {
    if (root == NULL)
        return true;

    if (root->data <= minVal || root->data >= maxVal)
        return false;

    return isBSTUtil(root->left, minVal, root->data) &&
           isBSTUtil(root->right, root->data, maxVal);
}

bool isBST(Node* root) {
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

// Inorder print for verifying tree contents
void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {

    /*
       Creating a general binary tree
                8
               / \
              3   10
             / \    \
            12  6    14

       This is **NOT** a BST (12 is in the left subtree of 8)
    */

    Node* root = new Node(8);
    root->left = new Node(3);
    root->right = new Node(10);
    root->left->left = new Node(12);   // breaks BST rule
    root->left->right = new Node(6);
    root->right->right = new Node(14);

    cout << "Inorder Traversal of the Tree: ";
    inorder(root);
    cout << endl;

    if (isBST(root))
        cout << "The tree IS a BST.\n";
    else
        cout << "The tree is NOT a BST.\n";

    return 0;
}
