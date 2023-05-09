#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

Node * deleteRange(Node * top, int m, int n) {
    if (top == NULL) return NULL;
    if (top->data >= m && top->data <= n) {
        Node* temp = top->next;
        free(top);
        return deleteRange(temp, m, n);
    }
    top->next = deleteRange(top->next, m, n);
    return top;
}

void printList(Node *top){
    for (Node *curr = top; curr != NULL; curr = curr->next) 
        cout << curr->data << " ";
    cout << endl;
}

void deleteList(Node *top){
    while (top != NULL) {
        Node *temp = top->next;
        free(top);
        top = temp;
    }
}

int main() {
    // Create a linked list 1 -> 2 -> 3 -> 4 -> 5
    Node *top = new Node{1, new Node{2, new Node{3, new Node{4, new Node{5, NULL}}}}};

    cout << "Original linked list: ";
    printList(top);

    top = deleteRange(top, 1, 4); // Delete elements within the range [2, 4]

    cout << "Linked list after deleting elements within range [2, 4]: ";
    printList(top);
    cout << endl;

    deleteList(top);    // Free memory used by linked list

    return 0;
}
