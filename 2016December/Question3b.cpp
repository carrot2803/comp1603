#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

bool containsSorted(Node *top, int key) { // recursive sequence of events basically
    return (top != NULL) ? ((top->data == key) ? true : ((top->data > key) ? false : containsSorted(top->next, key))) : false;
}

int main(){
    Node *top = new Node{1, new Node{2, new Node{3, new Node{4, NULL}}}};
    cout << boolalpha << containsSorted(top, 3) << endl; // should print (true)
    cout << boolalpha << containsSorted(top, 5) << endl; // should print (false)
    return 0;
}
