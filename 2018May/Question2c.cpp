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

Node *insertInOrder(Node *top, int key){
    if(top == NULL || top->data >= key){
        Node *newNode = createNode(key);
        newNode->next = top;
        return newNode;
    }
    top->next = insertInOrder(top->next, key);
    return top;
}

int main(){
    Node* top = NULL;
    top = insertInOrder(top, 4);
    top = insertInOrder(top, 24);
    top = insertInOrder(top, 50);
    top = insertInOrder(top, 1);
    top = insertInOrder(top, -3);
    while (top != NULL) {
        cout << top->data << " ";
        top = top->next;
    }
    cout << endl;

    return 0;
}