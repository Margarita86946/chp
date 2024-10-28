#include "Cipher.h"
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

string Cipher::makeKey() {
    string alph = "abcdefghijklmnopqrstuvwxyz";
    string key = alph;

    srand(static_cast<unsigned>(time(0)));

    for (int i = key.length() - 1; i >= 0; i--) {
        int j = rand() % (i + 1);
        char temp = key[i];
        key[i] = key[j];
        key[j] = temp;
    }

    return key;
}

string Cipher::encrypt(const string& str, const string& key) {
    string encryptedStr = str;

    for (int i = 0; i < encryptedStr.length(); i++) {

        if (encryptedStr[i] >= 'a' && encryptedStr[i] <= 'z') {
            int keyInd = (int)(encryptedStr[i] - 'a');
            encryptedStr[i] = key[keyInd];
        }
    }

    return encryptedStr;
}

string Cipher::decrypt(const string& str, const string& key) {
    string decryptedStr = "";
    string alph = "abcdefghijklmnopqrstuvwxyz";

    for (int i = 0; i < str.length(); i++) {
        if (str[i] == ' ') {
            decryptedStr += ' ';
        } else {

            for (int j = 0; j < key.length(); j++) {
                if (str[i] == key[j]) {
                    decryptedStr += alph[j];
                    break;
                }
            }
        }
    }

    return decryptedStr;
}

bool Cipher::checking(const string& str1, const string& str2) {
    return str1 == str2;
}