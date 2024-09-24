#include <iostream>
#include <string>

using namespace std;

int main() {
    string key = "QWERTYUIOPASDFGHJKLZXCVBNM"; 
    string plaintext, ciphertext = "";

    cout << "Enter the text to hash: ";
    getline(cin, plaintext); 

    for (int i=0; i<=plaintext.length(); i++) {
        if (isalpha(plaintext[i])) { 
            char upperCh = toupper(plaintext[i]); 
            int index = upperCh - 'A'; 
            ciphertext += key[index]; 
        } else {
            ciphertext += plaintext[i]; 
        }
    }

    cout << "Encrypted text: " << ciphertext << endl;

    
    string decryptedText = "";
    for (int i=0; i<=ciphertext.length(); i++) {
        if (isalpha(ciphertext[i])) {
            
            size_t index = key.find(toupper(ciphertext[i]));
            char originalCh = 'A' + index;
            decryptedText += originalCh;
        } else {
            decryptedText += ciphertext[i];
        }
    }

    cout << "Decrypted text: " << decryptedText << endl;

    return 0;
}
