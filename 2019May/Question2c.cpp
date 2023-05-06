#include <iostream>
using namespace std;

void reverse(char s[], int i){
    if(s[i] == '$') return;
    reverse(s, i+1);
    cout << s[i];
}

int main(){
    char s[] = "abcd$";
    reverse(s,0);
    return 0;
}