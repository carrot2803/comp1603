#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

int recSum(Node *top){
    if(top == NULL) return 0;
    return top->data + recSum(top->next);
}

int main(){
    Node *top = new Node{0, new Node{5, new Node{2, new Node{3, new Node{4, new Node{5, NULL}}}}}};

    cout << recSum(top) << endl; //2

    return 0;
}