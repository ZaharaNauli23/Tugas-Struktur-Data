#include <iostream>
using namespace std;

struct Node 
{
    char data;
    Node* left;
    Node* right;

    Node(char d) 
	{
        data = d;
        left = right = nullptr;
    }
};

// PreOrder: Root - Left - Right
void preOrder(Node* root) 
{
    if(root != nullptr) 
	{
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

// InOrder: Left - Root - Right
void inOrder(Node* root) 
{
    if(root != nullptr) 
	{
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}

// PostOrder: Left - Right - Root
void postOrder(Node* root) 
{
    if(root != nullptr) 
	{
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }
}

int main() 
{

    // Membentuk tree:
    //          R
    //       /     \
    //      A       E
    //    /   \
    //   S     T
    //  /
    // I

    Node* root = new Node('R');
    root->left = new Node('A');
    root->right = new Node('E');
    root->left->left = new Node('S');
    root->left->right = new Node('T');
    root->left->left->left = new Node('I');

    cout << "PreOrder  : ";
    preOrder(root);
    cout << endl;

    cout << "InOrder   : ";
    inOrder(root);
    cout << endl;

    cout << "PostOrder : ";
    postOrder(root);
    cout << endl;

    return 0;
}
