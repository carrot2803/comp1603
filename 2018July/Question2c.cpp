#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

struct Node{
    char data;
    Node *next;
};

struct Stack{
    Node *top;
};

Node *createNode(char n){
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
    Node *temp = top->next;
    free(top);
    return temp;
}

Stack *initStack(){
    Stack *s = (Stack*)malloc(sizeof(Stack));
    s->top = NULL;
    return s;
}

bool isEmpty(Stack *s){
    return s->top == NULL;
}

void push(Stack *s, char ch){
    s->top = insertAtHead(s->top, ch);
}

char peek(Stack *s){
    if(isEmpty(s)){
        cout << "Stack is empty\n";
        return '\0';
    }
    return s->top->data;
}

char pop(Stack *s){
    if(isEmpty(s)){
        cout << "Stack is empty\n";
        return '\0';
    }
    char n = s->top->data;
    s->top = deleteAtHead(s->top);
    return n;
}

int isBalanced(char ch[]){
    Stack *s1 = initStack(), *s2 = initStack();
    int lhs=0, rhs=0;
    for(int i = 0; i < strlen(ch); i++)
        if(ch[i] == '(')
            push(s1, ch[i]);
        else if(ch[i] == ')')
            push(s2, ch[i]);
    
    while(!isEmpty(s1))   pop(s1), lhs++;
    while(!isEmpty(s2))   pop(s2), rhs++;

    cout << "Number of parenthesis: "<< lhs+rhs << endl;

    if(lhs > rhs) return 1;
    else if(lhs < rhs) return -1;
    return 0;
}

int main() {
    char ch[] = "()";
    int balanced = isBalanced(ch);

    if(balanced == 0)
        cout << "Balanced\n";
    else if(balanced < 0)
        cout << "More right than left\n";
    else
        cout << "More left than right\n"; 

    
    return 0;
}
