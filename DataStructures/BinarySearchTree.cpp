#include <iostream>

namespace BST {
    
    struct Node {
        int data;
        Node *Left = NULL;
        Node *Right = NULL;
        Node(int data) { this->data = data; }
    };
    
    struct Node* addNode(struct Node *node, int data) {
        if (node == NULL) return new Node(data);
        if (data < node->data){
            node->Left = addNode(node->Left, data);
        }
        else{
            node->Right = addNode(node->Right, data);
        }
        return node;
    }
    struct Node* deleteNode(struct Node *root, int data){
        if (root == NULL) return NULL;
        if (data < root->data) {
            root->Left = deleteNode(root->Left, data);
        }
        else if (data > root->data) {
            root->Right = deleteNode(root->Right, data);
        }
        else {
            if (root->Left == NULL) {
              struct Node *temp = root->Right;
              delete root;
              return temp;
            } else if (root->Right == NULL) {
              struct Node *temp = root->Left;
              delete root;
              return temp;
            }
            

        }
        return root;
    }
    void InOrderTraverse(struct Node *root){
        if (root != NULL) {
            // Traverse left
            InOrderTraverse(root->Left);

            // Traverse root
            std::cout << root->data << " -> ";

            // Traverse right
            InOrderTraverse(root->Right);
          }
    }
    
    class Tree {
        struct Node* root = NULL;
        public:
        Tree(int data){
            root = addNode(root, data);
        }
        void AddNode(int data){
            root = addNode(root, data);
        }
        void Traverse(){
            InOrderTraverse(root);
        }
    };
};

int main()
{
    BST::Tree Tree1(5);
    Tree1.AddNode(2);
    Tree1.AddNode(10);
    Tree1.Traverse();
}