#include <iostream>
#include <cstdlib>
using namespace std;

struct Node{
    int data;
    Node *next;
};

struct Stack{
    Node *top;
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

int main(){
    Stack *s = initStack();
    int i = 0, sum = 0, arr[] = {1,2,3,4,5,6,7,8,9,10};

    for(int i = 0; i < 10; i++)
        push(s, arr[i]);
    
    while(!isEmpty(s)){
        if(i%2)
            sum += pop(s);
        else pop(s);
        i++;
    }

    cout << sum << endl;

    return 0;
}