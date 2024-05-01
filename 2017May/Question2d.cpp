#include <iostream>
using namespace std;

void reverse() {
    char c;
    cin >> c;
    if (c == '$') 
        return;
    reverse();
    cout << c;
}

int main() {
    cout << "Enter string terminated by $" << endl;
    reverse();
    return 0;
}