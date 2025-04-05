#include <iostream>
#include <unordered_map>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

int preIndex = 0;

Node* buildTree(int inorder[], int preorder[], int inStart, int inEnd, unordered_map<int, int>& inMap) {
    if (inStart > inEnd)
        return nullptr;

    int rootVal = preorder[preIndex++];
    Node* root = new Node{rootVal, nullptr, nullptr};

    int inIndex = inMap[rootVal];
    root->left = buildTree(inorder, preorder, inStart, inIndex - 1, inMap);
    root->right = buildTree(inorder, preorder, inIndex + 1, inEnd, inMap);

    return root;
}

void printInorder(Node* root) {
    if (root) {
        printInorder(root->left);
        cout << root->data << " ";
        printInorder(root->right);
    }
}

int main() {
    int n;
    cout << "Enter number of nodes in the tree: ";
    cin >> n;

    int inorder[n], preorder[n];

    cout << "Enter " << n << " elements of Preorder traversal:\n";
    for (int i = 0; i < n; i++) cin >> preorder[i];

    cout << "Enter " << n << " elements of Inorder traversal:\n";
    for (int i = 0; i < n; i++) cin >> inorder[i];

    unordered_map<int, int> inMap;
    for (int i = 0; i < n; i++) inMap[inorder[i]] = i;

    Node* root = buildTree(inorder, preorder, 0, n - 1, inMap);

    cout << "Constructed tree's Inorder traversal: ";
    printInorder(root);
    cout << endl;

    return 0;
}
