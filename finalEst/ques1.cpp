#include <iostream>
#include <vector>
using namespace std;

int extendedGCD(int a, int b, int &x, int &y) {
    
    if(b==0){
        x=1;
        y=0;
        return a;
    }

    int x1,y1;
    int gcd = extendedGCD(b, a%b, x1,y1);
   
    x = y1;
    y=x1-(a/b)*y1;
    return gcd;
}

int main() {
   
    int a = 30,b=20;
    int x,y;
    int gcd = extendedGCD(b, a%b, x,y);

    cout << "GCD = " << gcd << endl;
    cout << "x = " << x << ", y = " << y << endl;
    

    return 0;
}
