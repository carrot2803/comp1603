/*
a.  
a,b are static stock variables, 
ap,bp are dynamic pointer variables  that store memory addresses where values can be found.

b.
1. New share value is $ 13.67
2. Apple share value is $187.3
3. Google share value is $1162.49
4. Apple share value is $188.02
5. Apple Inc. share value is $1165


*/

/*

c.

struct Stock{
    string name;
    double perShare;
};

void setshareValue(Stock *p, double perShare){
    p->perShare = perShare;
}

void swap(Stock &a, Stock &b){
    Stock temp = a;
    a = b;
    b = temp;
}

swap(a , b); 

*/
