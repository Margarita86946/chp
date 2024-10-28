#include "Caesar.h"
#include <iostream>
#include <cstring>

using namespace std;

#define BUF_SIZE  1024

int main() {
    Caesar cipher;
    cipher.SetShift(4);

    const char* message = "Hello, World! 123";
    unsigned int size = strlen(message);
    unsigned char encrypted[BUF_SIZE] = {0};
    unsigned char decrypted[BUF_SIZE] = {0};
    unsigned int outsize = size;

    cipher.Encrypt((const unsigned char*)message, size, encrypted, outsize);
    cout << "Encrypted: ";
    cipher.PrintData(encrypted, outsize);

    cipher.Decrypt(encrypted, outsize, decrypted, outsize);
    cout << "Decrypted: ";
    cipher.PrintData(decrypted, outsize);

    return 0;
}