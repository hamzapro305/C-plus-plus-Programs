#include <iostream>

using namespace std;

class Node
{
public:
    int value;
    Node *left, *right;
    Node(int val){
        value = val;
        left = NULL;
        right = NULL;
    }
};

void PreOrder(Node *root)
{
    if (root == NULL)
        return;
    cout << root->value << " ";
    PreOrder(root->left);
    PreOrder(root->right);
}
void PostOrder(Node *root)
{
    if (root == NULL)
        return;
    PostOrder(root->left);
    PostOrder(root->right);
    cout << root->value << " ";
}

void DestroyTree(Node* Root){
    if (Root == NULL)
        return;
    DestroyTree(Root->left);
    DestroyTree(Root->right);
    delete Root;
}
void InOrder(Node *root)
{
    if (root == NULL)
        return;
    InOrder(root->left);
    cout << root->value << " ";
    InOrder(root->right);
}
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    InOrder(root);
    cout << endl;

    DestroyTree(root);
}