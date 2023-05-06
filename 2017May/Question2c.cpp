#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

void recAddn(Node *top, int n){
    if(top == NULL) return;
    top->data += n;
    recAddn(top->next, n);
}

void printList(Node *top){
    if(top == NULL) return;
    cout << top->data << " ";
    printList(top->next);
}

int main(){
    Node *top = new Node{0, new Node{5, new Node{2, new Node{3, new Node{4, new Node{5, NULL}}}}}};

    recAddn(top, 5);
    printList(top);

    return 0;
}