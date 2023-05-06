#include <iostream>

void reverse(int n){
    if(n > 0){
        std::cout << n % 10;
        reverse(n/10);
    }
}

int main(){
    reverse(5678);
    return 0;
}