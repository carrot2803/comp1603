#include <iostream>
using namespace std;

struct Node{
    char data;
    Node *next;
};

char toLower(const char ch){
    return (ch >= 'A' & ch <= 'Z') ? ch + 32: ch;
}

Node *createNode(char n){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = n;
    newNode->next = NULL;
    return newNode;
}

Node *deleteNode(Node *top, char key){
    if(top == NULL)
        return top;
    else if(top->data == key){
        Node *temp = top->next;
        free(top);
        return temp;
    }
    top->next = deleteNode(top->next, key);
    return top;
}

bool containsKey(Node *top, char key){
    while(top != NULL){
        if(top->data == key)
            return true;
        top = top->next;
    }
    return false;
}

bool anagrams(Node *top1, Node *top2){
    while(top1 != NULL){
        if(!containsKey(top2, toLower(top1->data)))
            return false;
        top2 = deleteNode(top2, toLower(top1->data));
        top1 = top1->next;
    }
    if(top2 != NULL) return false;
    return true;
}

int main() {
    Node *list1 = new Node{'r', new Node{'e', new Node{'s', new Node{'i', new Node{'s', new Node{'t', NULL}}}}}};
    Node *list2 = new Node{'s', new Node{'i', new Node{'s', new Node{'t', new Node{'e', new Node{'r', NULL}}}}}};

    if (anagrams(list1, list2)) cout << "The strings are anagrams." << endl;
    else  cout << "The strings are not anagrams." << endl;
    
    return 0;
}