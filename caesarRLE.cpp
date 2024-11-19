#include <iostream> 
#include <string> 
#include <cctype> 
 
using namespace std; 
 
int main() { 
    string input, encrypted, compressed, decompressed, decrypted; 
    int shift; 

    cout << "Enter text to encrypt: "; 
    getline(cin, input); 
 
    cout << "Enter shift value: "; 
    cin >> shift; 
 
    for (char ch : input) { 
        encrypted += static_cast<char>((static_cast<unsigned char>(ch) + shift) % 256);
    } 
 
    compressed = ""; 
    int count = 1; 
    for (size_t i = 1; i <= encrypted.length(); i++) { 
        if (i < encrypted.length() && encrypted[i] == encrypted[i - 1]) { 
            count++; 
        } else { 
            compressed += encrypted[i - 1]; 
                compressed += static_cast<char>(count); 
            count = 1; 
        } 
    } 
 
    cout << "Encrypted and compressed text: " << compressed << endl; 
 
    decompressed = ""; 
    for (size_t i = 0; i < compressed.length(); i += 2) {
        char ch = compressed[i];
        
        unsigned char repeat = static_cast<unsigned char>(compressed[i + 1]);
        
        decompressed += string(repeat, ch);
    }
    
    
    decrypted = ""; 
    
    for (char32_t ch : decompressed) { 
        decrypted += static_cast<char>((static_cast<unsigned char>(ch) - shift + 256) % 256);
    } 
    
    
    cout << "Decrypted text: " << decrypted << endl; 
 
 
    return 0; 
}