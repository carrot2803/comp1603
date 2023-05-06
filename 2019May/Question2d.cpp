#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

Node* deleteNode(Node* top, int key) {
    if (top == NULL) 
        return top;
    if(top->data == key){
        Node *temp = top->next;
        free(top);
        return temp;
    }   
    top->next = deleteNode(top->next, key);
    return top;
}

void printList(Node *top){
    if(top == NULL)
        return;
    cout << top->data << " ";
    printList(top->next);
}

int main() {
    Node *top = new Node{0, new Node{5, new Node{2, new Node{3, new Node{4, new Node{5, NULL}}}}}};
    printList(top);
    cout << endl;
    deleteNode(top, 2);
    printList(top);
    

    return 0;
}

