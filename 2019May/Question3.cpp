#include <iostream>
using namespace std;

struct Node{
    char data;
    Node *next;
};

char toLower(const char ch){
    return (ch >= 'A' && ch <= 'Z') ? ch + 32 : ch; 
}

Node* deleteNode(Node* top, char key) {
    if (top == NULL) 
        return top;
    if(top->data == key){
        Node *temp = top->next;
        free(top);
        return temp;
    }   
    top->next = deleteNode(top->next, key);
    return top;
}

bool containsKey(Node *top, char key){
    if(top == NULL)
        return false;
    else if(toLower(top->data) == key)
        return true;
    return containsKey(top->next, key);
}

bool anagram(Node *str1, Node *str2){
    while(str1 != NULL){
        if(!containsKey(str2, toLower(str1->data)))
            return false;
        str2 = deleteNode(str2, str1->data); 
        str1 = str1->next;
    }
    return true;
}

int main() {
    Node *list1 = new Node{'r', new Node{'e', new Node{'s', new Node{'i', new Node{'s', new Node{'t', NULL}}}}}};
    Node *list2 = new Node{'s', new Node{'i', new Node{'s', new Node{'t', new Node{'e', new Node{'r', NULL}}}}}};

    if (anagram(list1, list2)) cout << "The strings are anagrams." << endl;
    else  cout << "The strings are not anagrams." << endl;
    
    return 0;
}
