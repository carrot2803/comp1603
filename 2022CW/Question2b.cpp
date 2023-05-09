#include <iostream>
using namespace std;

int biggestChange(int A[], int n, int biggestSoFar) {
    if (n <= 0) return biggestSoFar;
    else if (abs(A[n] - A[n - 1]) > biggestSoFar)
        biggestSoFar = abs(A[n] - A[n - 1]);
    return biggestChange(A, n - 1, biggestSoFar);
}

int main() {
    int A[] = {90, 91, 100, 120, 110, 101, 95};
    int size = sizeof(A) / sizeof(int);

    cout << "biggest change " << biggestChange(A, size - 1, 0);

    return 0;
}