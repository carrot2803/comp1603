#include <iostream>
using namespace std;

void reverse(char s[], int i){
    if(s[i] == '$') return;
    reverse(s, i+1);
    cout << s[i];
}

// void reverse(string s, int i){  additional option
//     if(s.at(i) == '$') return;
//     reverse(s, i+1);
//     cout << s[i];
// }

int main(){
    // string s = "abcd$";
    char s[] = "abcd$";
    reverse(s,0);
    return 0;
}