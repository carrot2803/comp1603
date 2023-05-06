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

Node *addRest(Node *newTop, Node *last, Node *curr){
    while(curr != NULL){
        Node *newNode = createNode(curr->data);
        last->next = newNode;
        last = newNode;
        curr = curr->next;
    }
    return newTop;
}

Node *mergeSorted(Node *list1, Node *list2){
    Node *newNode, *newTop=NULL, *curr1 = list1, *curr2 = list2, *last = NULL;
    while(curr1 != NULL && curr2 != NULL){
        if(curr1->data  < curr2->data){
            newNode = createNode(curr1->data);
            curr1 = curr1->next;
        }
        else{
            newNode = createNode(curr2->data);
            curr2 = curr2->next;
        }   
        (newTop == NULL) ? newTop = newNode : last->next = newNode;
        last = newNode;
    }
    return addRest(newTop, last, (curr1 ? curr1 : curr2));
}

void printList(Node *top){
    if(top == NULL) return;
    cout << top->data << " ";
    printList(top->next);
}

int main(){
    Node *list1 = new Node{1, new Node{3, new Node{5, NULL}}};
    Node *list2 = new Node{2, new Node{4, new Node{6, NULL}}};

    Node *mergedList = mergeSorted(list1, list2);
    printList(mergedList);
  
    return 0;
}
