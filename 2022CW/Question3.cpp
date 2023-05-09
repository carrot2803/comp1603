#include <iostream>
#include <fstream>
#define MAXSET 1000 
using namespace std;

struct SortedSet{
    int numElements;      // number of elements in the SortedSet
    int elements[MAXSET]; // the actual elements in the SortedSet
};

SortedSet * initSortedSet (){
    SortedSet *s = (SortedSet*)malloc(sizeof(SortedSet));
    s->numElements = 0;
    s->elements[s->numElements];
    return s;
}

bool isEmpty(SortedSet *ss) {
    return ss->numElements == 0;
}

bool isFull(SortedSet *ss) {
    return ss->numElements == MAXSET;
}

void push(SortedSet * ss, int n) {
    if (isFull(ss)) {
        cout << "Error: SortedSet overflow\n";
        return;
    }
    ss->elements[ss->numElements++] = n;
}

int peek(SortedSet * ss) { // Returns the element at the top of ss without removing it.
    if (isEmpty(ss)) {
        cout << "Error: SortedSet is empty\n";
        return -1; // or some other sentinel value to indicate an error
    }
    return ss->elements[ss->numElements - 1];
}

int pop(SortedSet * ss) { // Removes and returns the element at the top of ss.
    if (isEmpty(ss)) {
        cout << "Error: SortedSet is empty\n";
        return -1; // or some other sentinel value to indicate an error
    }
    int top = ss->elements[ss->numElements - 1];
    ss->numElements--;
    return top;
}

SortedSet * copySS (SortedSet * ss) {
    SortedSet *newSet = initSortedSet();
    for (int i = 0; i < ss->numElements; i++) {
        push(newSet, ss->elements[i]);
    }
    return newSet;
}

SortedSet * initSortedSetFromFile (const char* filename){
    SortedSet *s = initSortedSet();
    ifstream fin(filename);
    int n;
    while (s->numElements < MAXSET && fin >> n) 
        push(s, n);

    return s;
}

void insertSS (SortedSet * ss, int key) {
    if (isFull(ss)) {
        cout << "Error: SortedSet overflow\n";
        return;
    }
    push(ss, key);
}

bool containsSS(SortedSet *ss, int key) {
    SortedSet *copy = copySS(ss);
    while (copy->numElements > 0) {
        if (pop(copy) == key) {
            free(copy);
            return true;
        }
    }
    free(copy);
    return false;
}

void displaySS(SortedSet *ss) {
    SortedSet *copy = copySS(ss);
    while (copy->numElements > 0) 
        cout << pop(copy) << " ";
    cout << endl;
    free(copy);
}

SortedSet * intersectionSS (SortedSet * ss1, SortedSet * ss2){
    SortedSet *s1 = copySS(ss1), *s2 = copySS(ss2);
    SortedSet *interL = initSortedSet();
    while(!isEmpty(s1))
        if(containsSS(s2, peek(s1)) && !containsSS(interL, peek(s1)))
            push(interL, pop(s1));
        else pop(s1);
    
    free(s1);   free(s2);
    return interL;
}


SortedSet * unionSS (SortedSet * ss1, SortedSet * ss2){
    SortedSet *s1 = copySS(ss1), *s2 = copySS(ss2);
    SortedSet *unionL = initSortedSet();
    while(!isEmpty(s1))
        if(!containsSS(unionL, peek(s1)))
            push(unionL, pop(s1));
        else    pop(s1);
    
    while(!isEmpty(s2))
        if(!containsSS(unionL, peek(s2)))   push(unionL, pop(s2));
        else    pop(s2);

    free(s1); free(s2);
    return unionL;
}

int main() {
    // Create SortedSet ss1 from SortedSet1.txt
    SortedSet *ss1 = initSortedSetFromFile("SortedSet1.txt");

    // Create SortedSet ss2 from SortedSet2.txt
    SortedSet *ss2 = initSortedSetFromFile("SortedSet2.txt");

    // Display elements in ss1
    cout << "Elements in ss1: ";
    displaySS(ss1);

    // Display elements in ss2
    cout << "Elements in ss2: ";
    displaySS(ss2);

    // Create SortedSet ss3 containing elements in both ss1 and ss2
    SortedSet *ss3 = intersectionSS(ss1, ss2);

    // Create SortedSet ss4 containing elements in either ss1 or ss2
    SortedSet *ss4 = unionSS(ss1, ss2);

    // Display elements in ss3
    cout << "Elements in ss3: ";
    displaySS(ss3);

    // Display elements in ss4
    cout << "Elements in ss4: ";
    displaySS(ss4);

    free(ss1);  free(ss2);  free(ss3);  free(ss4);
    return 0;
}
