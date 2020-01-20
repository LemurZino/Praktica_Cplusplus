#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node* next;
};

void push(Node*& top, int value)
{
    Node* newNode = new Node{ value, nullptr };
    newNode->next = top;
    top = newNode;
}

int pop(Node*& top)
{
    int result = top->data;
    Node* tmp = top;
    top = top->next;
    delete tmp;

    return result;
}

void reverse(Node*& top)
{
    Node* new_head = 0;
    for (Node* pos = top;pos;)
    {
        Node* save_next = pos->next;
        pos->next = new_head;
        new_head = pos;
        pos = save_next;
    }
    top = new_head;
    while (top != nullptr) {
        cout << pop(top) << endl;
    }
}

int main()
{
    Node* top = nullptr;
    push(top, 444);
    push(top, 555);
    push(top, 666);

    while (top != nullptr) {
        cout << pop(top) << endl;
    }
    
    push(top, 444);
    push(top, 555);
    push(top, 666);

    reverse(top);

    return 0;
}