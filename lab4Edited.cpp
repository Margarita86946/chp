#include <iostream>
#include <cmath>
#include <vector>
#include <string>
using namespace std;
void MatrixRows(vector<vector<char>>& matrix, const string& str, int size) {
    int idx = 0;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (idx < str.length()) {
                matrix[i][j] = str[idx++];
            } else {
                matrix[i][j] = ' ';
            }
        }
    }
}
string readMatrix(const vector<vector<char>>& matrix, int size) {
    string encoded_string = "";
    for (int j = 0; j < size; ++j) {
        for (int i = 0; i < size; ++i) {
            encoded_string += matrix[i][j];
        }
    }
    return encoded_string;
}
string encodeString(const string& str, int matrix_size) {
    int size = ceil(sqrt(matrix_size));
    vector<vector<char>> matrix(size, vector<char>(size, ' '));
    MatrixRows(matrix, str, size);
    return readMatrix(matrix, size);
}
void MatrixColumns(vector<vector<char>>& matrix, const string& str, int size) {
    int idx = 0;
    for (int j = 0; j < size; ++j) {
        for (int i = 0; i < size; ++i) {
            if (idx < str.length()) {
                matrix[i][j] = str[idx++];
            } else {
                matrix[i][j] = ' ';
            }
        }
    }
}
string readMatrixRows(const vector<vector<char>>& matrix, int size) {
    string decoded_string = "";
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            decoded_string += matrix[i][j];
        }
    }
    return decoded_string;
}
string decodeString(const string& str, int matrix_size) {
    int size = ceil(sqrt(matrix_size));
    vector<vector<char>> matrix(size, vector<char>(size, ' '));
    MatrixColumns(matrix, str, size);
    return readMatrixRows(matrix, size);
}
int main() {
    string user_string;
    cout << "Enter the string to encode: ";
    getline(cin, user_string);
    
    int matrix_size;
    cout << "Enter the matrix size (n*n): ";
    cin >> matrix_size;
    string encoded = encodeString(user_string, matrix_size);
    cout << "Encoded string: " << encoded << endl;
    string decoded = decodeString(encoded, matrix_size);
    cout << "Decoded string: " << decoded << endl;
    return 0;
}
