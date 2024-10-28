#ifndef CIPHER_H
#define CIPHER_H

#include <string>

using namespace std;

class Cipher {
public:
    string makeKey();

    string encrypt(const string& str, const string& key);

    string decrypt(const string& str, const string& key);

    bool checking(const string& str1, const string& str2);
};

#endif