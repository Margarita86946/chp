#include "RLE.h"
#include <sstream>
#include <cctype>

using namespace std;

string RLE::compress(const string& input) {
    stringstream result;
    int count = 1;

    for (size_t i = 1; i <= input.size(); ++i) {
        if (i < input.size() && input[i] == input[i - 1]) {
            ++count;
        } else {
            result << input[i - 1];
            result << static_cast<char>(count);
            count = 1;
        }
    }

    return result.str();
}

string RLE::decompress(const string& input) {
    stringstream result;
    for (size_t i = 0; i < input.size(); i += 2) {
        char ch = input[i];
        int count = static_cast<int>(input[i + 1]);

        result << string(count, ch);
    }

    return result.str();
}