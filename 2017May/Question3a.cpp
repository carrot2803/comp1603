#include <iostream>
#include <cstdlib>
using namespace std;

int* sumProduct(int *m, int *n){
    int *sum1 = (int*)malloc(sizeof(int));
    int *product1 = (int*)malloc(sizeof(int));
    int* result = (int*)malloc(sizeof(int) * 2);
    *sum1 = 0, *product1 = 1;

    for(int *i = m; *i <= *n; (*i)++){
        *sum1 += *i;
        *product1 *= *i;
    }

    result[0] = *sum1;
    result[1] = *product1;
    
    free(sum1); free(product1);
    return result;
}

int main(){
    int m = 1;
    int n = 5;
    int* result = sumProduct(&m, &n);
    cout << "Sum: " << result[0] << endl;
    cout << "Product: " << result[1] << endl;
    free(result);
    return 0;
}