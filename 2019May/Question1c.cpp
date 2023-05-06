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
    return (top == NULL) ? newNode : (newNode->next = top, top = newNode);
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
    Stack *s = initStack();
    Queue *q = initQueue();
    int *sum = (int*)malloc(sizeof(int));
    *sum = 0;

    enqueue(q,10);
    enqueue(q,20);
    enqueue(q,22);
    enqueue(q,102);
    enqueue(q,155);
    enqueue(q,362);

    while(!isEmptyQ(q))
        push(s, dequeue(q));

    while(!isEmpty(s)){
        int num = pop(s);   
        if(num % 10 == 2) 
            *sum += num;
    }

    cout << *sum << endl;

    free(s); free(sum);
    return 0;
}