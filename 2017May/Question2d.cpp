#include <iostream>

void reverse(char ch[], int i){
    if(ch[i] == '$') return;
    reverse(ch, i+1); 
    std::cout << ch[i];
}

int main(){
    char ch[] = "abcd$";
    reverse(ch, 0);
    return 0;
}