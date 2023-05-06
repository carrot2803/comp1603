#include <iostream>
#include <cstdlib>
using namespace std;

struct Node{
    char data;
    Node *next;
};

int occurrences(Node *top, char ch){
    if(top == NULL) return 0;
    else if(top->data == ch) return 1 + occurrences(top->next, ch);
    return 0 + occurrences(top->next, ch); // usually i just return straight but i used 0 to show no incrementation
}

int main() {
    Node *list1 = new Node{'r', new Node{'e', new Node{'s', new Node{'i', new Node{'s', new Node{'t', NULL}}}}}};

    cout << "Number of occurrences of 's' in list1: " << occurrences(list1, 's') << endl;
    cout << "Number of occurrences of 'x' in list1: " << occurrences(list1, 'x') << endl;

    return 0;
}
