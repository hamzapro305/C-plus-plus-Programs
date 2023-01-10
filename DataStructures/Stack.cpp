#include <iostream>

using namespace std;

class Stack{
    struct Node
    {
        int value;
        struct Node *next = NULL;
    };
    private:
    Node *Head = NULL;
    public:
    int length = 0;
    Stack(){}
    Stack(int value)
    {
        Head = new Node();
        Head->value = value;
        length++;
    }
    void push(int Value)
    {
        Node *Item = Head;
        if(Head == NULL){
            Head = new Node();
            Head->value = Value;
            return;
        }
        while (Item->next != NULL) Item = Item->next;
        Item->next = new Node();
        Item->next->value = Value;
        length++;
    }
    int get(){
        if(Head == NULL) return -1;
        if(Head->next == NULL){
            int x = Head->value;
            free(Head);
            Head = NULL;
            length--;
            return x;
        }
        Node *Item = Head;
        while (Item->next->next != NULL) Item = Item->next;
        Node *ItemToDelete = Item->next;
        Item->next = NULL;
        int x = ItemToDelete->value;
        free(ItemToDelete);
        length--;
        return x;
    }
    void Print()
    {
        if(Head == NULL){
            cout << "[ ]" << endl;
            return;
        }
        Node *Item = Head;
        cout << "[ ";
        while (Item->next != NULL)
        {
            cout << Item->value << " ";
            Item = Item->next;
        }
        cout << " ] Length: " << length << endl;
    }
};

int main(){
    Stack arr = Stack(23);
    arr.push(1);
    arr.push(2);
    arr.push(3);
    arr.Print();
    cout << "Item: " << arr.get() << endl;
    arr.Print();
    cout << "Item: " << arr.get() << endl;
    arr.Print();
    cout << "Item: " << arr.get() << endl;
    arr.Print();
    cout << "Item: " << arr.get() << endl;
    arr.Print();
    return 0;
}