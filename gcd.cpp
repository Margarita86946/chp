#include <iostream>
using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int remainder = a % b;
        a = b;
        b = remainder;
    }
    return a;
}

int lcp(int a, int b) {
    return a*b/gcd(a, b);
}

int main() {
    int num1, num2;
    
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;
    
    cout << "GCD and LCP " << num1 << " and " << num2 << " is " << gcd(num1, num2) << " " << lcp(num1, num2) << endl;
    
    return 0;
}
