#include <iostream>
#include <fstream>
using namespace std;

struct Account {
    int accNumber;
    double balance;
};

int main() {
    ofstream fout("Accounts.dat", ios::binary | ios::out);

    // Write branch information to the first 90 bytes of the file
    char branchInfo[90] = "Branch information goes here";
    fout.write(branchInfo, sizeof(branchInfo));

    // Write account information to the rest of the file
    Account accounts[5] = {{1001, 5000.0}, {1002, 7500.0}, {1003, 10000.0}, {1004, 2500.0}, {1005, 15000.0}};
    fout.write((char*)accounts, sizeof(accounts));

    fout.close();

    return 0;
}
