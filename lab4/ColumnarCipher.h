#ifndef COLUMNARCIPHER_H
#define COLUMNARCIPHER_H

#include <vector>
#include <string>

using namespace std;

class ColumnarCipher {
public:
    ColumnarCipher(int n);

    string encrypt(const string& text);
    string decrypt(const string& text);

private:
    int n;

    vector<vector<char>> generateKey(const string& text);
    vector<vector<char>> generateDecryptKey(const string& text);
};

#endif