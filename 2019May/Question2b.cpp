#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

int recLast(Node *top){
    if(top == NULL)
        return -999;
    else if(top->next == NULL)
        return top->data;
    return recLast(top->next);
}

int main() {
    Node *top = new Node{0, new Node{5, new Node{2, new Node{3, new Node{4, new Node{5, NULL}}}}}};
    int lastValue = recLast(top);
    cout << "The last value in the linked list is: " << lastValue << endl;
    return 0;
}
