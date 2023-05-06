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

int occurrence(Node *top, int key){
    if(top == NULL) return 0;
    else if(top->data == key) return 1 + occurrence(top->next, key);
    return 0 + occurrence(top->next, key); // I added 0 for demonstration purposes
}

Node *removeDuplicates(Node *top) {
    if (top == NULL)   return NULL;

    if (occurrence(top, top->data) > 1) {
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

int main() {
    Node *top = new Node{1, new Node{2, new Node{2, new Node{2, new Node{4, new Node{1, NULL}}}}}};
    
    cout << "Original List: ";
    printList(top);
    top = removeDuplicates(top);
    cout << "\nList without duplicates: ";
    printList(top);
    
    return 0;
}   