#include "ColumnarCipher.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

ColumnarCipher::ColumnarCipher(int n) : n(n) {}

vector<vector<char>> ColumnarCipher::generateKey(const string& text) {
    int rows = (text.size() + n - 1) / n;
    vector<vector<char>> matrix(rows, vector<char>(n, ' '));

    int k = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < n; j++) {
            if (k < text.length()) {
                matrix[i][j] = text[k++];
            }
        }
    }
    return matrix;
}

vector<vector<char>> ColumnarCipher::generateDecryptKey(const string& text) {
    int rows = (text.size() + n - 1) / n;
    vector<vector<char>> matrix(rows, vector<char>(n, ' '));

    int k = 0;
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < rows; i++) {
            if (k < text.length()) {
                matrix[i][j] = text[k++];
            }
        }
    }
    return matrix;
}

string ColumnarCipher::encrypt(const string& text) {
    string encrypted = "";
    auto matrix = generateKey(text);

    cout << "Encrypt key:" << endl;
    for (const auto& row : matrix) {
        for (char ch : row) {
            cout << ch << " ";
        }
        cout << endl;
    }

    for (int j = 0; j < n; j++) {
        for (int i = 0; i < matrix.size(); i++) {
            encrypted += matrix[i][j];
        }
    }

    return encrypted;
    
}

string ColumnarCipher::decrypt(const string& text) {
    string decrypted = "";
    auto matrix = generateDecryptKey(text);

    cout << "Decrypt key:" << endl;
    for (const auto& row : matrix) {
        for (char ch : row) {
            cout << ch << " ";
        }
        cout << endl;
    }

    for (const auto& row : matrix) {
        for (char ch : row) {
            decrypted += ch;
        }
    }

    return decrypted;
}