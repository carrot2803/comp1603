#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

Node *deleteNode(Node *top, int key){
    if(top == NULL) return top;
    else if(top->data == key){
        Node *temp = top->next;
        free(top);
        return temp;
    }
    top->next = deleteNode(top->next, key);
    return top;
}

Node *removeDuplicates(Node *top) {
    if (top == NULL || top->next == NULL) return top;
    if (top->data == top->next->data) {
        top = deleteNode(top, top->data);
        return removeDuplicates(top);
    } 
    top->next = removeDuplicates(top->next);
    return top;
}

void printList(Node *top){
    if(top == NULL) return;
    cout << top->data << " ";
    printList(top->next);
}

int main(){
    Node *top = new Node{1, new Node{1, new Node{1, new Node{4, NULL}}}};
    cout << "Original List: ";
    printList(top);
    top = removeDuplicates(top);
    cout << "\nList without duplicates: ";
    printList(top);

    return 0;
}