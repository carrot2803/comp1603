#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

int count5(Node *top){
    if(top == NULL)
        return 0;
    else if(top->data == 5)
        return 1 + count5(top->next);
    return 0 + count5(top->next);  // Added zero for indication purposes
}

int main(){
    Node *top = new Node{0, new Node{5, new Node{2, new Node{3, new Node{4, new Node{5, NULL}}}}}};

    cout << count5(top) << endl; //2

    return 0;
}