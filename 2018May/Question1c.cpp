#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

struct Stack{
    Node *top;
};

struct Queue{
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
    if(top == NULL){
        top = newNode;
        return top;
    }
    newNode->next = top;
    top = newNode;
    return top;
}

Node *deleteAtHead(Node *top){
    if(top == NULL)
        return NULL;
    Node *temp = top;
    top = top->next;
    free(temp);
    return top;
}

Stack *initStack(){
    Stack *s = (Stack*)malloc(sizeof(Stack));
    s->top = NULL;
    return s;
}

bool isEmpty(Stack *s){
    return s->top == NULL;
}

int peek(Stack *s){
    if(isEmpty(s)){
        cout << "The stack is empty\n";
        return -999;
    }
    return s->top->data;
}

int pop(Stack *s){
    if(isEmpty(s)){
        cout << "The stack is empty\n";
        return -999;
    }
    int n = s->top->data;
    s->top = deleteAtHead(s->top);
    return n;
}

void push(Stack *s, int n){
    s->top = insertAtHead(s->top, n);
}

Queue *initQueue(){
    Queue *q = (Queue*)malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

bool isEmptyQ(Queue *q){
    return q->front == NULL;
}

void enqueue(Queue *q, int n){
    Node *newNode = createNode(n);
    if(isEmptyQ(q))
        q->front = newNode;  
    else
        q->rear->next = newNode;
    q->rear = newNode;
}

int peekQ(Queue *q){
    if(isEmptyQ(q)){
        cout << "Queue is empty \n";
        return -999;
    }
    return q->front->data;
}

int dequeue(Queue *q){
    if(isEmptyQ(q)){
        cout << "Queue is empty \n";
        return -999;
    }
    int n = q->front->data;
    q->front = deleteAtHead(q->front);
    return n;
}

int main(){
    int product = 1, arr[] = {1,2,3,4,5,6,8,9,10}; // use 10 over 200 for demonstation
    Stack *s = initStack();
    Queue *q = initQueue();

    for(int i = 0; i < 9; i++)
        enqueue(q, arr[i]);

    while(!isEmptyQ(q))
        push(s, dequeue(q));

    while(!isEmpty(s))
        product *= pop(s);
    
    cout << product << endl;

    return 0;
}