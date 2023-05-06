#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

Node *createNode(int n){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = n;
    newNode->next = NULL;
    return newNode;
}

Node *getLast(Node *top){
    if(top == NULL)
        return top;
    else if(top->next = NULL)
        return top;
    return getLast(top->next);
}

Node *insertAtTail(Node *top, int n){ 
    Node *newNode = createNode(n);
    Node *last = getLast(top);
    if(top == NULL)
        return newNode;
    last->next = newNode;
    last = newNode;
    return top;
}

void printList(Node *top){
    if(top == NULL) return;
    cout << top->data << " ";
    printList(top->next);
}

int main() {
    Node *top = NULL;
    top = insertAtTail(top, 1);
    top = insertAtTail(top, 2);
    top = insertAtTail(top, 3);
    top = insertAtTail(top, 4);

    printList(top);
    cout << endl;

    return 0;
}
