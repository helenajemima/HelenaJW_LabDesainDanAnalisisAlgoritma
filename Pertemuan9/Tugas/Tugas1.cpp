#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node *left, *right;
    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

void printPreorder(struct Node* node)
{
    if (node == NULL)
        return;
    cout << node->data << " ";
    printPreorder(node->left);
    printPreorder(node->right);
}

void printPostorder(struct Node* node)
{
    if (node == NULL)
        return;
    printPostorder(node->left);
    printPostorder(node->right);
    cout << node->data << " ";
}

void printInorder(struct Node* node)
{
    if (node == NULL)
        return;
    printInorder(node->left);
    cout << node->data << " ";
    printInorder(node->right);
}

void options(struct Node* root) {
    cout << "\nWhich traversal method do you want to use?\n";
    cout << "1. Preorder\n";
    cout << "2. Inorder\n";
    cout << "3. Postorder\n";
    cout << "4. All three\n";
    cout << "Enter your choice: ";
    int choice;
    cin >> choice;

    switch (choice) {
        case 1:
            cout << "Preorder traversal: ";
            printPreorder(root);
            break;
        case 2:
            cout << "Inorder traversal: ";
            printInorder(root);
            break;
        case 3:
            cout << "Postorder traversal: ";
            printPostorder(root);
            break;
        case 4:
            cout << "Preorder traversal: ";
            printPreorder(root);
            cout << "\nInorder traversal: ";
            printInorder(root);
            cout << "\nPostorder traversal: ";
            printPostorder(root);
            break;
        default:
            cout << "Your choice is invalid";
            break;
    }
}

int main()
{
    struct Node* root = new Node(12);
    root->left = new Node(16);
    root->right = new Node(20);
    root->left->left = new Node(24);
    root->left->right = new Node(32);

    cout << "Numbers: 12, 16, 20, 24, 32\n";

    options(root);
    
    return 0;
}

