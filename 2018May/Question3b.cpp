#include <iostream>
#include <cstring>
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

bool isOperator(const char ch){
    return ch == '+' || ch == '-' || ch == '*';
}

bool isDigit(const char ch){
    return ch >= '0' && ch <= '9';
}

int sum(char ch[]){ // Assume is number or operator
    Stack *s = initStack();
    Stack *op = initStack();
    int i = 0;

    while(ch[i] != '$'){ 
        if(isDigit(ch[i])){
            push(s, ch[i] - '0');
        }
        else if(isOperator(ch[i])){
            int a = pop(s), b = pop(s);
            if(ch[i] == '+')
                push(s, a + b);
            else if(ch[i] == '-')
                push(s, (b - a));
            else if(ch[i] == '*')
                push(s, a * b);
        }
        i++;
    }
    return pop(s);
}

int main(){
    char expr_arr[] = "52+63-*$";
    cout << sum(expr_arr) << endl;

    return 0;
}
