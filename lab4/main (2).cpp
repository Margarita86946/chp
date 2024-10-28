#include "ColumnarCipher.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    string text;

    cout << "Enter text: ";
    getline(cin, text);

    cout << "Enter number: ";
    cin >> n;

    ColumnarCipher cipher(n);

    string encrypted = cipher.encrypt(text);
    cout << "Encrypted text: " << encrypted << endl;

    string decrypted = cipher.decrypt(encrypted);
    cout << "Decrypted text: " << decrypted << endl;

    return 0;
}
