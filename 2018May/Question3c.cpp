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

bool containsKey(Node *top, int key){
    if(top == NULL)   return false;
    else if(top->data == key) return true;
    return containsKey(top->next, key);
}

Node *getLast(Node *top){
    if(top == NULL)
        return top;
    else if(top->next == NULL)
        return top;
    return getLast(top->next);
}

Node *insertAtTail(Node *top, int n){
    Node *newNode = createNode(n), *last = getLast(top);
    if(top == NULL){
        top = newNode;
        return top;
    }
    last->next = newNode;
    last = newNode;
    return top;
}

Node *intersect(Node *list1, Node *list2){
    Node *list3 = NULL;
    while(list1 != NULL){
        if(containsKey(list2, list1->data))
           list3 = insertAtTail(list3, list1->data);
        list1 = list1->next;
    }
    return list3;
}

void printList(Node *top){
    if(top == NULL) return;
    cout << top->data << " ";
    printList(top->next);
}

int main(){
    Node *top = new Node{0, new Node{1, new Node{2, new Node{3, new Node{4, new Node{5, NULL}}}}}};
    Node *top2 = new Node{10, new Node{1, new Node{8, new Node{90, new Node{31, new Node{5, NULL}}}}}};
    
    Node *list3 = intersect(top, top2);
    printList(list3);
    
    return 0;
}