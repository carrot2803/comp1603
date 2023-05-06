#include <iostream>
#include <fstream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

struct Stack{
    Node *top;
};

void writeFile(){ // add a check if exams
    ofstream fout("data.dat", ios::out | ios::binary);
    for(int i = 200; i <= 400; i+= 10)
        fout.write((char*)&i, sizeof(int));
    fout.close();
}

void readFile(int arr[]){
    int i = 0;
    ifstream fin("data.dat", ios::in | ios::binary);
    while(fin.read((char*)&arr[i], sizeof(int)))
        i++;
    fin.close();
}

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
    writeFile();
    Stack *s = initStack();
    int arr[21] = {0};
    readFile(arr);

    for(int a : arr)
        push(s, a);
    
    while(!isEmpty(s)){
        if(!(peek(s) % 20))
            cout << pop(s) << " ";
        else
            pop(s);
    }

    return 0;
}