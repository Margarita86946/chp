#include "RLE.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
    RLE rle;
    string input;
    
    cout << "Enter text to compress: ";
    getline(cin, input);
    
    string compressed = rle.compress(input);
    cout << "Compressed text: " << compressed << endl;
    
    string decompressed = rle.decompress(compressed);
    cout << "Decompressed text: " << decompressed << endl;
    
    if (input == decompressed) {
        cout << "Success: Original and decompressed texts match!" << endl;
    } else {
        cout << "Error: Original and decompressed texts do not match!" << endl;
    }
    
    return 0;
}