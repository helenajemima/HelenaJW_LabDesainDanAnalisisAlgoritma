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
 

int main()
{
    struct Node* root = new Node(15);
    root->left = new Node(30);
    root->right = new Node(27);
    root->left->left = new Node(25);
    root->left->right = new Node(29);

    cout << "Preorder traversal : ";
    printPreorder(root);

    cout << "\nPostorder traversal : ";
    printPostorder(root);

    cout << "\nInorder traversal : ";
    printInorder(root);
    
    return 0;
}




