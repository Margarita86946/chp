#ifndef RLE_H
#define RLE_H

#include <string>

using namespace std;

class RLE {
public:
    string compress(const string& input);
    string decompress(const string& input);
};

#endif