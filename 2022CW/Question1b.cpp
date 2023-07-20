#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

struct Account {
    int accNumber;
    double balance;
};

struct Node{
    Account *data;
    Node *next;
};

Node* createNode(int accNumber, double balance) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = (Account*)malloc(sizeof(Account));
    newNode->data->accNumber = accNumber;
    newNode->data->balance = balance;
    newNode->next = NULL;
    return newNode;
}

Node* insertList(Node* top, int accNumber, double balance) {
    if (top == NULL)  // Base case: if list is empty, newNode is the first element
        return createNode(accNumber, balance);
    else if (accNumber < top->data->accNumber) { // Recursive case: insert node at the beginning of the list
        Node* newNode = createNode(accNumber, balance);
        newNode->next = top;
        return newNode;
    }
    else { // Recursive case: insert node in the middle or at the end of the list
        top->next = insertList(top->next, accNumber, balance);
        return top;
    }
}

void printList(Node *top) {
    if (top == NULL) return; // Base case: the list is empty
    cout << "Account Number: " << top->data->accNumber << endl;
    cout << "Balance: " << top->data->balance << endl;
    printList(top->next); // Recursive call to print the rest of the list
}


void saveData(Node* top, char* branchData) {
    ofstream outFile("Accounts.dat", ios::out | ios::binary);
    int branchDataLength = strlen(branchData);
    outFile.write((char*)(&branchDataLength), sizeof(int));
    outFile.write(branchData, branchDataLength);
  
    while (top != nullptr) {
        outFile.write((char*)(top->data), sizeof(Account));
        top = top->next;
    }

    outFile.close();
}

int main() {
    Node* top = NULL;
    top = insertList(top, 200, 2000.00);
    top = insertList(top, 100, 1000.00);
    printList(top);    
    return 0;
}
