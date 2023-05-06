#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

int sum(Node *top){
    if(top == NULL) return 0;
    return top->data + sum(top->next);
}

int main(){
    Node *top = new Node{0, new Node{1, new Node{2, new Node{3, new Node{4, new Node{5, NULL}}}}}};
    cout << sum(top) << endl;
    return 0;
}