#include <iostream>
using namespace std;

struct Node { // i (just declare a linked list in ur main)
    int data;
    Node *next;
};

struct Queue{ // ii
    Node *front;
    Node *rear;
};

Node *createNode(int n){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = n;
    newNode->next = NULL;
    return newNode;
}

Node *insertAtHead(Node *top, int n){
    Node *newNode = createNode(n);
    return (top == NULL) ? newNode : (newNode->next = top, top = newNode);
}

Node *deleteAtHead(Node *top){
    if(top == NULL) return NULL;
    Node *temp = top->next;
    free(top);
    return temp;
}

Queue *initQueue(){
    Queue *q = (Queue*)malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

bool isEmpty(Queue *q){
    return q->front == NULL;
}

int peek(Queue *q){
    if(isEmpty(q)){
        cout << "Queue is empty\n";
        return -999;
    }
    return q->front->data;
}

int dequeue(Queue *q){
    if(isEmpty(q)){
        cout << "Queue is empty\n";
        return -999;
    }
    int n = q->front->data;
    q->front = deleteAtHead(q->front);
    return n;
}

void enqueue(Queue* q, char s) {
    Node* newNode = createNode(s);
    isEmpty(q) ? q->front = newNode : q->rear->next = newNode;
    q->rear = newNode;
}

int main(){
    Queue *q = initQueue();
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);

    while (!isEmpty(q))
        cout << dequeue(q) << " ";

    return 0;
}
