#include <iostream>
#include <string>

using namespace std;

    string runLengthEncode(const string &input) {
    string encoded = "";
    int n = input.length();

    for (int i = 0; i < n; i++) {
        int count = 1;
        while (i < n - 1 && input[i] == input[i + 1]) {
            count++;
            i++;
        }

        encoded += input[i];
        encoded += to_string(count);
    }

    return encoded;
}

int main() {
    string input;
    
    cout << "Enter a string: ";
    cin >> input;

    string encodedString = runLengthEncode(input);
    cout << "Encoded string: " << encodedString << endl;

    return 0;
}