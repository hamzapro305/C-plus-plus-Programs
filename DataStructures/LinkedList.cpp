#include <iostream>

using namespace std;

class MyLinkedList
{
    struct Node
    {
        int value;
        struct Node *next = NULL;
    };

public:
    Node *Head = new Node();
    int length = 0;
    MyLinkedList(int value)
    {
        Head->value = value;
        length++;
    }
    void AddItemAt(int Key, int Value)
    {
        if(Key == -1){
            Node *NewItem = new Node();
            NewItem->value = Value;
            Node *TempItem = Head;
            Head = NewItem;
            NewItem->next = TempItem;
        }
        Node *Item = Head;
        int CurrentKey = 0;
        do
        {
            if(CurrentKey == Key){
                Node *NewItem = new Node();
                NewItem->value = Value;
                Node *TempItem = Item->next;
                Item->next = NewItem;
                NewItem->next = TempItem;
                length++;
            }
            CurrentKey++;
            Item = Item->next;
        }while (Item->next != NULL);
    }
    void SetValue(int Key, int Value)
    {
        Node *Item = Head;
        int CurrentKey = 0;
        while (Item->next != NULL)
        {
            if (CurrentKey == Key)
            {
                Item->value = Value;
                break;
            }
            Item = Item->next;
            CurrentKey++;
        }
    }
    void RemoveItemAt(int Key, int Value)
    {
        Node *Item = Head;
        int CurrentKey = 0;
        if (Head->next == NULL)
        {
            free(Head);
            length = 0;
            return;
        }
        while (Item->next != NULL)
        {
            Item = Item->next;
            if (CurrentKey == Key)
            {
                Node *Temp = Item->next;
                Item->next = Item->next->next;
                length--;
                free(Temp);
                break;
            }
            CurrentKey++;
        }
    }
    void push(int Value)
    {
        Node *Item = Head;
        while (Item->next != NULL)
        {
            Item = Item->next;
        }
        Item->next = new Node();
        Item->next->value = Value;
        length++;
    }
    void Print()
    {
        Node *Item = Head;
        cout << "[ ";
        while (Item != NULL)
        {
            cout << Item->value << " ";
            Item = Item->next;
        }
        cout << " ] Length: " << length << endl;
    }
};

int main()
{
    MyLinkedList arr = MyLinkedList(1);
    arr.push(3);
    arr.push(5);
    arr.Print();
    arr.AddItemAt(0, 2);
    arr.AddItemAt(2, 4);
    arr.Print();
}