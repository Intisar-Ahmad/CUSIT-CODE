#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    Node(int val) : key(val), left(NULL), right(NULL) {}
};

Node* insertNode(Node* root, int key) {
    if (!root) return new Node(key);
    if (key < root->key) root->left = insertNode(root->left, key);
    else root->right = insertNode(root->right, key);
    return root;
}

Node* findMin(Node* root) {
    while (root->left) root = root->left;
    return root;
}

Node* deleteNode(Node* root, int key) {
    if (!root) return NULL;

    if (key < root->key)
        root->left = deleteNode(root->left, key);

    else if (key > root->key)
        root->right = deleteNode(root->right, key);

    else {
        // Case 1: Leaf node
        if (!root->left && !root->right) {
            delete root;
            return NULL;
        }
        // Case 2: One child
        else if (!root->left) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (!root->right) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        // Case 3: Two children
        else {
            Node* temp = findMin(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }
    return root;
}

void inorder(Node* root) {
    if (root) {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

int main() {
    Node* root = NULL;
    int arr[] = {50, 30, 20, 40, 70, 60, 80};
    for (int x : arr) root = insertNode(root, x);

    cout << "Inorder before deletion: ";
    inorder(root);

    root = deleteNode(root, 50); // delete root (two children)

    cout << "\nInorder after deletion: ";
    inorder(root);
    return 0;
}
