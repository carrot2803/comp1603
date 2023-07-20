#include <iostream>
using namespace std;

int sumSequence(int arr[], int i, int n){
    if(i == n) return 0;
    return arr[i] + sumSequence(arr, i+1, n);
}

int main() {
    int seq1[] = {1, 5, 9, 13, 17, 21, 25, 29, 33, 37, 41, 45, 49, 53, 57, 61, 65, 69, 73, 77, 81, 85, 89, 93, 97, 101};
    int seq2[251] = {0};

    for (int i = 0; i < 251; i++) 
        seq2[i] = 4 * i + 1;
    
    cout << "Sum of sequence 1: " << sumSequence(seq1, 0, 26) << endl;
    cout << "Sum of sequence 2: " << sumSequence(seq2, 0, 251) << endl;

    return 0;
}
