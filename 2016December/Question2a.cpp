/*
Due to the difficulty of this question I recommend you do the question then run to see the solution
14 
16 
18 
18 
18 
20 
22 
*/



#include <iostream>
using namespace std;

void fun(int m, int n){
    if(n <= 0) cout << endl;
    else{
        fun(m - 2, n - 2);
        cout << m << " ";
        fun(m + 2, n - 2);
    }
}

int main(){
    fun(18,5);
    return 0;
}