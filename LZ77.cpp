#include <iostream>
#include <string>

using namespace std;

int main() {
    string text;
    cout << "Enter text to compress: ";
    getline(cin, text);

    int offsets[100];
    int lengths[100];
    char nextChars[100];
    int count = 0;

    int n = text.length();
    for (int i = 0; i < n;) {
        int matchOffset = 0, matchLength = 0;

        for (int j = max(0, i - 10); j < i; ++j) {
            int k = 0;
            while (i + k < n && text[j + k] == text[i + k]) {
                k++;
            }
            if (k > matchLength) {
                matchOffset = i - j;
                matchLength = k;
            }
        }

        offsets[count] = matchOffset;
        lengths[count] = matchLength;
        nextChars[count] = (i + matchLength < n) ? text[i + matchLength] : '\0';
        count++;

        i += matchLength + 1;
    }

    cout << "Compressed Output:\n";
    for (int i = 0; i < count; i++) {
        cout << "(" << offsets[i] << ", " << lengths[i] << ", " << nextChars[i] << ")\n";
    }

    string decompressed = "";
    for (int i = 0; i < count; i++) {
        int start = decompressed.length() - offsets[i];
        for (int j = 0; j < lengths[i]; j++) {
            decompressed += decompressed[start + j];
        }

        if (nextChars[i] != '\0') {
            decompressed += nextChars[i];
        }
    }

    cout << "Decompressed Text:\n" << decompressed << endl;

    return 0;
}