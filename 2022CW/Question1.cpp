#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

struct Account {
    int accNumber;
    double balance;
};

int main(){
    ifstream fin("Accounts.dat", ios::binary | ios::in);
    Account *a = (Account*)malloc(sizeof(Account) * 90); 
    double *sum = (double*)malloc(sizeof(double));
    int *count = (int*)malloc(sizeof(int));
    *sum = 0, *count = 0;

    char* branchInfo = (char*)malloc(sizeof(char) * 90);
    strcpy(branchInfo, "Branch information goes here");
    fin.read(branchInfo, sizeof(char) * 90);

    while(fin.read((char*)a, sizeof(Account))){
        *sum += a->balance;
        // cout << a->accNumber << endl;
        (*count)++;
        a++;
    }

    cout << "num accounts is " << *count << endl; 
    cout << "Balance is " << *sum << endl;

    return 0;
}
